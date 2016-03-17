
// open a single window
var window = Ti.UI.createWindow({
	backgroundColor:'white'
});
var label = Ti.UI.createLabel();
window.add(label);
window.open();

// TODO: write your module tests here
var tiosm = require('ti.iosmdroid');

if (Ti.Platform.name == "android") {
	var mapview = tiosm.createView({
    	mapType: tiosm.MAPQUESTOSM,
    	region: {latitude:37.390749, longitude:-122.081651,
            latitudeDelta:0.01, longitudeDelta:0.01},
    	animate:true,
    	regionFit:true,
    	userLocation:true,
	});

	mapview.setMapType(tiosm.MAPNIK);
	mapview.zoom(3);
	window.add(mapview);
}