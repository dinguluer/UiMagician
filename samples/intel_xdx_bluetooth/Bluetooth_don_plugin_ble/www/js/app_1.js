var app = {
    initialize: function() {
        this.bindEvents();
    },
    bindEvents: function() {
        document.addEventListener('deviceready', this.onDeviceReady, false);
    },
    onDeviceReady: function() {
        alert('Device is ready !!');
        app.scan();
    },
    scan: function() {

        var foundHeartRateMonitor = false;

        function onScan(peripheral) {
            alert(JSON.stringify(peripheral));

        }

        function scanFailure(reason) {
            alert("BLE Scan Failed");
        }
              ble.startScan([], onScan, scanFailure);

    },

};

app.initialize();
