OSMdroid
========

![](https://raw.githubusercontent.com/AppWerft/Ti.OSMdroid/master/assets/osmdroid.png)
~~~
const MAPTYPES = [{
    name : 'CycleMap',
    index : 3
}, {
name : 'MAPNIK',
index : 6
}, {
name : 'MAPQUEST-AERIAL',
index : 7
}, {
name : 'MAPQUEST-OSM',
index : 9
}, {
name : 'PUBLIC_TRANSPORT',
index : 10
}];

var TiPermissions = require('ti.permissions'),
osmDroid = require('ti.osmdroid');

var $ = Ti.UI.createWindow({
    title : 'OSMdroid-Test',
    backgroundColor : 'gray'
});
$.addEventListener('open', function(_event) {
    var activity = _event.source.getActivity();
    if (activity) {
        activity.onCreateOptionsMenu = function(_menuevent) {
            _menuevent.menu.clear();
            var item = _menuevent.menu.add({
                title : 'Maptype',
                showAsAction : Ti.Android.SHOW_AS_ACTION_IF_ROOM,
            });

            item.addEventListener("click", function(_e) {
            var dialogView = Ti.UI.createOptionDialog({
                selectedIndex : 1,
                options : MAPTYPES.map(function(m) {return m.name;})
            });
            dialogView.show();
            dialogView.addEventListener('click', function(_e) {
                var mapType = dialogView.options[_e.index];
                $.children[0].setMapType(MAPTYPES[_e.index].index);
            });

        });
    };
    activity.invalidateOptionsMenu();
    }
});
$.open();

if (Ti.Platform.name == "android") {
var permissions = ['android.permission.ACCESS_COARSE_LOCATION', 'android.permission.WRITE_EXTERNAL_STORAGE'];
TiPermissions.requestPermissions(permissions, function(_e) {
if (_e.success) {

}
});
$.add(osmDroid.createView({
mapType : osmDroid.CYCLEMAP,
/*
Possible values:
CYCLEMAP,
MAPNIK,
MAPQUESTAERIAL,
MAPQUESTAERIAL_US,
MAPQUESTOSM,
PUBLIC_TRANSPORT,
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
$.children[0].zoom(13);
}
~~~