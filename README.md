OSMdroid
========


~~~
var window = Ti.UI.createWindow({
    backgroundColor : 'white'
});

window.open();

var osmdroidMap = require('ti.osmdroid');

if (Ti.Platform.name == "android") {
    window.add(osmdroidMap.createView({
        mapType : osmdroidMap.ROADS_OVERLAY_NL,
            region : {
                latitude : 53.390749,
                longitude : 10.081651,
                latitudeDelta : 0.01,
                longitudeDelta : 0.01
            },
            animate : true,
            regionFit : true,
            userLocation : true,
        }));
}
~~~