# Otto hands and LED Matrix

LED mouth Matrix use the [MAX7219](https://es.aliexpress.com/item/1pcs-MAX7219-dot-matrix-module-microcontroller-module-display-module-finished-goods/32725083862.html?spm=2114.search0104.3.97.cyRMWM&ws_ab_test=searchweb0_0%2Csearchweb201602_2_10152_10065_10151_10068_5460011_10307_10301_10303_10137_10060_10155_10154_10056_10055_10054_5470020_10059_100031_10099_10103_10102_10052_10053_10142_10107_10050_10051_5380020_10326_10084_10083_10080_10082_10081_10110_10111_10112_10113_10114_10179_10312_10313_10314_10078_10079_10073_5540020%2Csearchweb201603_2%2CppcSwitch_4&btsid=a23e196a-27ae-44de-9cd0-4252f0e1a4c3&algo_expid=f2ef828c-d2ef-43a0-abc1-84d06ab3babd-12&algo_pvid=f2ef828c-d2ef-43a0-abc1-84d06ab3babd)
+Touch sensor use this [2PCS TTP223 Capacitive Touch Switch Button Self-Lock Module for Arduino](http://www.ebay.com/itm/2PCS-TTP223-Capacitive-Touch-Switch-Button-Self-Lock-Module-for-Arduino/131662428748?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2057872.m2749.l2649)

Here are libraries and sketches for Otto DIY robot, with all files neccesary for LED Matrix and some features under developmnet

- Bluetooth
- rechargable lipo battery
- touch sensors
- RGB led nose
- LED matrix for mouths
- internal voltage measurment

v2 sketch is for version with 2 buttons for mode change (first button dance, second button walk+avoid, both together = react to noise)
v3 sketch has only 1 button or touch sensor and changes modes on touch (dance -> walk -> react to noise -> standby -> dance....)
Everything else is the same.
