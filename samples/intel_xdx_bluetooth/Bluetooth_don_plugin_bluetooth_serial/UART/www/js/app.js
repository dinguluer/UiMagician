/*
    SimpleSerial index.js
    Created 7 May 2013
    Modified 9 May 2013
    by Tom Igoe
*/

var bluetooth_devices= [];

function send_message()
{
    /*alert("send");

    return;*/
bluetoothSerial.write("hello, world",
                      function() {
                          app.display('send success');
                          alert('send success');

                      },
                      function() {
                          app.display('send fail');
                          alert('send fail');
                      });
}

function populate(menu)
{
    //alert("populate");

    bluetooth_devices = [];

    var select = document.getElementById("firstmenu");
    var length = select.options.length;
   // alert(length);
    //for (i = 0; i < length; i++) {
    for(i=select.options.length-1;i>=0;i--){
      select.remove(i);
    }

    //alert("item removed from list");

    // add new items
    for (var i = 0; i <  menu.length; i++) {
        //alert(myStringArray[i]);
       // alert(menu[i].name);
        //Do something

        var str="<option value='" + i + "'>" + menu[i].name + " : " +  menu[i].id + "</option>";
        $("#firstmenu").append(str);

        /*   var el = document.createElement("option");
            el.textContent = opt;
            el.value = opt;
            select.appendChild(el);*/

    }

    //alert("item updated in list");

    for (var i = 0; i <  menu.length; i++) {

        bluetooth_devices.push({
              "name" : menu[i].name,
              "id"  : menu[i].id
          });

        //alert(" *** " + bluetooth_devices[i].name + " *** " +bluetooth_devices[i].name)
    }

    //alert("pushed items");

}

function connectForDevices() {
    alert("Connecting ..!!!");
    //alert('test_1');

    var list = document.getElementById('firstmenu');

    alert('list item value = ' + list[list.selectedIndex].value);
    alert('list item text = ' + list[list.selectedIndex].text);

    global_mac = bluetooth_devices[list.selectedIndex].id;
}

function scanForDevices() {
    alert("Scanning ..!!!");
    //alert('test_1');


    /*
    var result = [{
                      "class": 276,
                      "id": "10:BF:48:CB:00:00",
                      "address": "10:BF:48:CB:00:00",
                      "name": "Nexus 7"
                  }, {
                      "class": 7936,
                      "id": "00:06:66:4D:00:00",
                      "address": "00:06:66:4D:00:00",
                      "name": "RN42"
                  }];

    populate(result);

    return;*/
    bluetoothSerial.discoverUnpaired(
                                     function(results) {
                                         app.display(JSON.stringify(results));
                                         populate(results);
                                     },
                                     function(error) {
                                         //app.display(JSON.stringify(error));
                                     }
                );

    //alert("Scanning ..!!!");
}

var app = {
    macAddress: "AA:BB:CC:DD:EE:FF",  // get your mac address from bluetoothSerial.list
    chars: "",

/*
    Application constructor
 */
    initialize: function() {
        this.bindEvents();
        console.log("Starting SimpleSerial app");
    },
/*
    bind any events that are required on startup to listeners:
*/
    bindEvents: function() {
        document.addEventListener('deviceready', this.onDeviceReady, false);
        connectButton.addEventListener('touchend', app.manageConnection, false);
        //connectButton.addEventListener('touchend', connectForDevices, false);
        discoverButton.addEventListener('touchend', scanForDevices, false);

        sendMsg.addEventListener('touchend', send_message, false);
    },

    populate_list: function(menu) {
                       alert("populate_list");

                       bluetooth_devices = [];

                       var select = document.getElementById("firstmenu");
                       var length = select.options.length;
                      // alert(length);
                       //for (i = 0; i < length; i++) {
                       for(i=select.options.length-1;i>=0;i--){
                         select.remove(i);
                       }

                       alert("item removed from list");

                       // add new items
                       for (var i = 0; i <  menu.length; i++) {
                           //alert(myStringArray[i]);
                          // alert(menu[i].name);
                           //Do something

                           var str="<option value='" + i + "'>" + menu[i].name + " : " +  menu[i].id + "</option>";
                           alert("1");
                           $("#firstmenu").append(str);
                           alert("2");

                           /*   var el = document.createElement("option");
                               el.textContent = opt;
                               el.value = opt;
                               select.appendChild(el);*/

                       }

                       alert("item updated in list");

                       for (var i = 0; i <  menu.length; i++) {

                           bluetooth_devices.push({
                                 "name" : menu[i].name,
                                 "id"  : menu[i].id
                             });

                           //alert(" *** " + bluetooth_devices[i].name + " *** " +bluetooth_devices[i].name)
                       }

                       alert("pushed items");

                   },

/*
    this runs when the device is ready for user interaction:
*/
    onDeviceReady: function() {

                       alert('Device is ready !!');

                       //clear data in buffer
                       bluetoothSerial.clear();

                      /* var result = [{
                                         "class": 276,
                                         "id": "10:BF:48:CB:00:00",
                                         "address": "10:BF:48:CB:00:00",
                                         "name": "Nexus 7"
                                     }, {
                                         "class": 7936,
                                         "id": "00:06:66:4D:00:00",
                                         "address": "00:06:66:4D:00:00",
                                         "name": "RN42"
                                     }];

                       alert("calling populate");
                       //app.populate_list(result);
                       populate(result);
                       alert("end populate");

                       return;*/

        // check to see if Bluetooth is turned on.
        // this function is called only
        //if isEnabled(), below, returns success:
        var listPorts = function() {
            // list the available BT ports:
            bluetoothSerial.list(
                function(results) {
                    //alert("calling populate_list");
                    //app.populate_list(results);
                    populate(results);
                    //alert("end populate_list");
                    app.display(JSON.stringify(results));
                },
                function(error) {
                    app.display(JSON.stringify(error));
                }
            );
        };

        // if isEnabled returns failure, this function is called:
        var notEnabled = function() {
            app.display("!! Bluetooth is not enabled. !!");
                  //alert('will open blue enabler');
            bluetoothSerial.enable(
                function() {
                    app.display("Bluetooth is enabled");

                    bluetoothSerial.list(
                        function(results) {
                                    //alert("calling populate_list");
                            //app.populate_list(results);
                                    populate(results);
                                    //alert("end populate_list");
                            app.display(JSON.stringify(results));
                        },
                        function(error) {
                            app.display(JSON.stringify(error));
                        }
                    );

                },
                function() {
                    app.display("The user did *not* enable Bluetooth");
                }
);
        };

         // check if Bluetooth is on:
        bluetoothSerial.isEnabled(
            listPorts,
            notEnabled
        );
    },
/*
    Connects if not connected, and disconnects if connected:
*/
    manageConnection: function() {

         connectForDevices();

                          alert("mac address = " + global_mac);

        // connect() will get called only if isConnected() (below)
        // returns failure. In other words, if not connected, then connect:
        var connect = function () {
            // if not connected, do this:
            // clear the screen and display an attempt to connect
            app.clear();
            app.display("Attempting to connect. " +
                "Make sure the serial port is open on the target device.");
            // attempt to connect:
            bluetoothSerial.connect(
                //app.macAddress,  // device to connect to
                global_mac,
                app.openPort,    // start listening if you succeed
                app.showError    // show the error if you fail
            );
        };

        // disconnect() will get called only if isConnected() (below)
        // returns success  In other words, if  connected, then disconnect:
        var disconnect = function () {
            app.display("attempting to disconnect");
            // if connected, do this:
            bluetoothSerial.disconnect(
                app.closePort,     // stop listening to the port
                app.showError      // show the error if you fail
            );
        };

        // here's the real action of the manageConnection function:
        bluetoothSerial.isConnected(disconnect, connect);
    },
/*
    subscribes to a Bluetooth serial listener for newline
    and changes the button:
*/
    openPort: function() {
        // if you get a good Bluetooth serial connection:
        //app.display("Connected to: " + app.macAddress);
                  app.display("Connected to: " + global_mac);
        // change the button's name:
        connectButton.innerHTML = "Disconnect";
        // set up a listener to listen for newlines
        // and display any new data that's come in since
        // the last newline:
        bluetoothSerial.subscribe('\n', function (data) {
            app.clear();
            app.display(data);
        });
    },

/*
    unsubscribes from any Bluetooth serial listener and changes the button:
*/
    closePort: function() {
        // if you get a good Bluetooth serial connection:
        //app.display("Disconnected from: " + app.macAddress);
                   app.display("Disconnected from: " + global_mac);
        // change the button's name:
        connectButton.innerHTML = "Connect";
        // unsubscribe from listening:
        bluetoothSerial.unsubscribe(
                function (data) {
                    app.display(data);
                },
                app.showError
        );
    },
/*
    appends @error to the message div:
*/
    showError: function(error) {
        app.display(error);
    },

/*
    appends @message to the message div:
*/
    display: function(message) {
        var display = document.getElementById("message"), // the message div
            lineBreak = document.createElement("br"),     // a line break
            label = document.createTextNode(message);     // create the label

        display.appendChild(lineBreak);          // add a line break
        display.appendChild(label);              // add the message node
    },
/*
    clears the message div:
*/
    clear: function() {
        var display = document.getElementById("message");
        display.innerHTML = "";
    }
};      // end of app
