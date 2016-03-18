OSMdroid
========

![](https://raw.githubusercontent.com/AppWerft/Ti.OSMdroid/master/assets/osmdroid.png)
~~~
var window = Ti.UI.createWindow({
backgroundColor : 'white',
title : 'OSMdroid-Test'
});

window.open();

var osmDroid = require('ti.osmdroid');

if (Ti.Platform.name == "android") {
require('ti.permissions').requestPermissions(['android.permission.WRITE_EXTERNAL_STORAGE', 'android.permission.ACCESS_COARSE_LOCATION'], function(_e) {
window.add(osmDroid.createView({
mapType : osmDroid.CYCLEMAP,
/*
Possible values:
BASE_OVERLAY_NL,
CYCLEMAP,
CLOUDMADESMALLTILES,
CLOUDMADESTANDARDTILES,
CYCLEMAP,
DEFAULT_TILE_SOURCE,
FIETS_OVERLAY_NL,
MAPNIK,
MAPQUESTAERIAL,
MAPQUESTAERIAL_US,
MAPQUESTOSM,
PUBLIC_TRANSPORT,
ROADS_OVERLAY_NL
*/
region : {
latitude : 53.53,
longitude : 10.0,
latitudeDelta : 0.01,
longitudeDelta : 0.01
},
animate : true,
regionFit : true,
userLocation : true,
zoomEnabled : false,
scrollEnabled : false

}));

window.children[0].zoom(13);

});

}
~~~