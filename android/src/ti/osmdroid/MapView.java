package ti.osmdroid;

import java.util.List;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.titanium.TiC;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.kroll.common.Log;
import org.appcelerator.kroll.common.TiConfig;
import org.appcelerator.titanium.util.TiConvert;
import org.appcelerator.titanium.view.TiUIView;
import org.osmdroid.tileprovider.tilesource.ITileSource;
import org.osmdroid.tileprovider.tilesource.TileSourceFactory;
import org.osmdroid.views.MapController;
import org.osmdroid.util.GeoPoint;
import org.osmdroid.views.overlay.MyLocationOverlay;
import org.osmdroid.views.overlay.Overlay;

public class MapView extends TiUIView implements Handler.Callback {
	private static final String LCAT = "TiOsmdroidModule/MapView";
	private static final boolean DBG = TiConfig.LOGD;

	private static final int MSG_CHANGE_ZOOM = 306;

	private org.osmdroid.views.MapView osmMapView;
	private boolean scrollEnabled;
	private boolean regionFit;
	private boolean animate;
	private boolean userLocation;

	private KrollDict location;
	private MyLocationOverlay myLocation;

	private Handler handler;

	public MapView(TiViewProxy proxy) {
		super(proxy);
		this.handler = new Handler(Looper.getMainLooper(), this);
		osmMapView = new org.osmdroid.views.MapView(proxy.getActivity(), 50);
		setNativeView(osmMapView);
	}

	@Override
	public void processProperties(KrollDict d) {
		if (d.containsKeyAndNotNull(TiC.PROPERTY_MAP_TYPE)) {
			int mapType = TiConvert.toInt(d, TiC.PROPERTY_MAP_TYPE);
			Log.d(LCAT, "mapType=" + mapType);
			if (mapType >= 0 && mapType < tileSrc.length) {
				doSetMapType(mapType);
			}
		}
		if (d.containsKeyAndNotNull(TiC.PROPERTY_ZOOM_ENABLED)) {
			Boolean enableZoomCtl = TiConvert.toBoolean(d,TiC.PROPERTY_ZOOM_ENABLED);
			org.osmdroid.views.MapView mapView = getView();
			mapView.setBuiltInZoomControls(enableZoomCtl);
			Log.d(LCAT, "zoomEnabled=" + enableZoomCtl);
		}
		if (d.containsKeyAndNotNull(TiC.PROPERTY_SCROLL_ENABLED)) {
			// [TODO] always true?
			Boolean enableScroll = TiConvert.toBoolean(d,TiC.PROPERTY_SCROLL_ENABLED);
			// mapView.setScrollable(enableScroll);
			Log.d(LCAT, "scrollEnabled=" + enableScroll);
		}
		if (d.containsKeyAndNotNull(TiC.PROPERTY_REGION_FIT)) {
			regionFit = d.getBoolean(TiC.PROPERTY_REGION_FIT);
			Log.d(LCAT, "regionFit=" + regionFit);
		}
		if (d.containsKeyAndNotNull(TiC.PROPERTY_ANIMATE)) {
			animate = d.getBoolean(TiC.PROPERTY_ANIMATE);
			Log.d(LCAT, "animate=" + animate);
		}
		if (d.containsKeyAndNotNull(TiC.PROPERTY_REGION)) {
			doSetLocation(d.getKrollDict(TiC.PROPERTY_REGION));
		}
		if (d.containsKeyAndNotNull(TiC.PROPERTY_USER_LOCATION)) {
			doUserLocation(d.getBoolean(TiC.PROPERTY_USER_LOCATION));
		}
		if (d.containsKeyAndNotNull(TiC.PROPERTY_ANNOTATIONS)) {
			// proxy.setProperty(TiC.PROPERTY_ANNOTATIONS, d.get(TiC.PROPERTY_ANNOTATIONS));
			// Object [] annotations = (Object[]) d.get(TiC.PROPERTY_ANNOTATIONS);
			// for(int i = 0; i < annotations.length; i++) {
			// 	AnnotationProxy ap = (AnnotationProxy) annotations[i];
			// 	this.annotations.add(ap);
			// }
			// doSetAnnotations(this.annotations);
		}
		super.processProperties(d);
	}

	@Override
	public void propertyChanged(String key, Object oldValue, Object newValue, KrollProxy proxy) {
		if (key.equals(TiC.PROPERTY_MAP_TYPE)) {
			if (newValue == null) {
				doSetMapType(ti.osmdroid.TiosmdroidModule.MAPNIK);
			} else {
				doSetMapType(TiConvert.toInt(newValue));
			}
		} else {
			super.propertyChanged(key, oldValue, newValue, proxy);
		}
	}

	public boolean handleMessage(Message msg) {
		switch(msg.what) {
			case MSG_CHANGE_ZOOM :
				MapController mc = osmMapView.getController();
				if (mc != null) {
					mc.setZoom(osmMapView.getZoomLevel() + msg.arg1);
				}
				return true;
		}
		return false;
	}

	private ITileSource tileSrc[] = {
		//	TileSourceFactory.OSMARENDER,
	        TileSourceFactory.MAPNIK,
	        TileSourceFactory.CYCLEMAP,
	        TileSourceFactory.PUBLIC_TRANSPORT,
	        TileSourceFactory.BASE,
	        TileSourceFactory.TOPO,
	        TileSourceFactory.HILLS,
	        TileSourceFactory.CLOUDMADESTANDARDTILES,
	        TileSourceFactory.CLOUDMADESMALLTILES,
	        TileSourceFactory.MAPQUESTOSM
	};
	
	private org.osmdroid.views.MapView getView() {
		return osmMapView;
	}

	public void doSetMapType(int mapType) {
		org.osmdroid.views.MapView mapView = getView();
		mapView.setTileSource(tileSrc[mapType]);
	}

	public void doSetLocation(KrollDict d) {
		org.osmdroid.views.MapView mapView = getView();
		if (d.containsKeyAndNotNull(TiC.PROPERTY_LONGITUDE) && d.containsKeyAndNotNull(TiC.PROPERTY_LATITUDE)) {
				GeoPoint gp = new GeoPoint(d.getDouble(TiC.PROPERTY_LATITUDE), d.getDouble(TiC.PROPERTY_LONGITUDE));
			if (animate) {
				mapView.getController().animateTo(gp);
			} else {
				mapView.getController().setCenter(gp);
			}
		}
		if (regionFit && d.containsKeyAndNotNull(TiC.PROPERTY_LONGITUDE_DELTA) && d.containsKeyAndNotNull(TiC.PROPERTY_LATITUDE_DELTA)) {
			int latitudeDeltaE6 = scaleToGoogle(d.getDouble(TiC.PROPERTY_LATITUDE_DELTA));
			int longitudeDeltaE6 = scaleToGoogle(d.getDouble(TiC.PROPERTY_LONGITUDE_DELTA));
			Log.d(LCAT, "latitudeDeltaE6=" + latitudeDeltaE6 + ", longitudeDeltaE6=" + longitudeDeltaE6);
		} else {
			Log.w(LCAT, "span must have longitudeDelta and latitudeDelta");
		}
	}

	public void doUserLocation(boolean userLocation) {
		org.osmdroid.views.MapView mapView = getView();
		if (mapView != null) {
			if (userLocation) {
				if (myLocation == null) {
					//myLocation = new MyLocationOverlay(proxy.getContext(), mapView);
					return;
				}

				List<Overlay> overlays = mapView.getOverlays();
				synchronized(overlays) {
					if (!overlays.contains(myLocation)) {
						overlays.add(myLocation);
					}
				}

				myLocation.enableMyLocation();

			} else {
				if (myLocation != null) {
					List<Overlay> overlays = mapView.getOverlays();
					synchronized(overlays) {
						if (overlays.contains(myLocation)) {
							overlays.remove(myLocation);
						}
						myLocation.disableMyLocation();
					}
				}
			}
		}
	}
	
	public void changeZoomLevel(int delta) {
		handler.obtainMessage(MSG_CHANGE_ZOOM, delta, 0).sendToTarget();
	}


	private int scaleToGoogle(double value) {
		return (int)(value * 1000000);
	}
}
