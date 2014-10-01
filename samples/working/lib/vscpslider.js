
///////////////////////////////////////////////////////////////////////////////
// vscpws_slider
//

function vscpws_slider( username,           // Username for websocket serever
                       passwordhash,    // Password hash for websocket
                       url,             // url to VSCP websocket i/f
                            sliderCanvasName,    // Slider ID
                            slideTxtname,        // Slider Input value ID
                            txtCanvasName,       // Remote device value ID
                            variableName,        // Variable name to be monitored
                            interval             // Variable monitoring interval
                               )
{
    // First set default parameter

    // Websocket for VSCP daemon communication
    this.socket_vscp = null;

    // Flag for connected or unconnected state.
    this.bConnected = false;

    // Set the instance name for the control
    instanceName = "vscpws_" + sliderCanvasName;

    // move this to global scope
    eval(instanceName + " = this;");

    // remember instance name
    this.instanceName = instanceName;

    // Events to send to turn ON
    this.tansmitt_vscpclass = VSCP_CLASS1_CONTROL;     // Default class is CLASS1.CONTROL
    this.tansmitt_vscptype = VSCP_TYPE_CONTROL_DIM_LAMPS; // Default type is TurnOn
    this.tansmitt_data = new Array(0,0,0); // Dimvalue=0, zone=0, subzone=0
    this.tansmitt_guid = "-";        // Default GUID is GUID of interface.


    // Receive events to confirm Turn ON
    this.receive_vscpclass = VSCP_CLASS1_INFORMATION;   // Default class is CLASS1.INFORMATION
    this.receive_vscptyp = VSCP_TYPE_INFORMATION_LEVEL_CHANGED;   // Default type is On
    this.receive_data = new Array(0,0,0); // Dimvalue = 0, zone=0, subzone=0
    this.receive_guid = "";          // Default GUID (empty is any).

    // Monitorvariabel - Should be a boolean variable
    variableName = typeof variableName !== 'undefined' ? variableName : ""; // Default is none
    this.monitorVariableName = variableName;
    interval = typeof interval !== 'undefined' ? interval : 1000; // Default is none
    this.monitorInterval = interval;        // Monitor interval is each second

    this.sliderCanvas = document.getElementById(sliderCanvasName);
    this.sliderTxtCanvas = document.getElementById(slideTxtname);
    this.txtCanvas = document.getElementById(txtCanvasName);

    this.sliderTxtCanvasId = slideTxtname;

    this.sliderRemoteValue = 0;

    this.bOnce = false; // Monitor variable is checked on intervals

    this.socket_vscp = null;

    //this.numMessages = 0;
    //this.messageTestFlag = 0;

    this.user = username;
    this.password = "";
    this.domain = "";
    this.passwordhash = passwordhash;

    // Open the socket
    this.socket_vscp = vscpws_openSocket(url);

    if (null==this.socket_vscp ) alert("Could not open websocket to VSCP server!");

    // Bind events
    this.socket_vscp.onmessage = this.onVSCPMessage.bind(this);
    this.socket_vscp.onopen = this.onVSCPOpen.bind(this);
    this.socket_vscp.onclose = this.onVSCPClose.bind(this);

    this.sliderCanvas.onchange = this.updateSlider.bind(this);

    // Set default events
    this.setTransmittEvent();

    //retreive instance name
    this.getInstanceName = function() {
       return this.instanceName;
    }

    //default property
    this.toString = function() {
       return this.getInstanceName();
    }

}

//-----------------------------------------------------------------------------
// setTransmittEvent
//-----------------------------------------------------------------------------

vscpws_slider.prototype.setTransmittEvent = function(vscpclass,
                                                                vscptype,
                                                                data,
                                                                guid )
{
    var dataArray;

    // First set default parameter
    vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : VSCP_CLASS1_CONTROL;
    vscptype = typeof vscptype !== 'undefined' ? vscptype : VSCP_TYPE_CONTROL_DIM_LAMPS;
    guid = typeof guid !== 'undefined' ? guid : "-";
    this.tansmitt_vscpclass = vscpclass;
    this.tansmitt_vscptype = vscptype;
    this.tansmitt_guid = guid;

    if (this.tansmitt_vscptype ==VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL)
    {
        dataArray = new Array(-1,0,0,0,0,0,0,0); // index = dont care, zone=0, subzone=0 , data , data, data, data, data
    }
    else   // VSCP_TYPE_CONTROL_DIM_LAMPS
    {
        dataArray = new Array(0,0,0); // Dimvalue = 0, zone=0, subzone=0
    }

    data = typeof data !== 'undefined' ? data : dataArray;
    this.tansmitt_data = data;

}

//-----------------------------------------------------------------------------
// setTransmittZone
//-----------------------------------------------------------------------------

vscpws_slider.prototype.setTransmittZone = function(index,zone,subzone)
{
    if((this.tansmitt_vscpclass == VSCP_CLASS1_CONTROL) && (this.tansmitt_vscptype == VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL))
    {
        this.tansmitt_data[0] = typeof index !== 'undefined' ? index : 0;
    }

    this.tansmitt_data[1] = typeof zone !== 'undefined' ? zone : 0;
    this.tansmitt_data[2] = typeof subzone !== 'undefined' ? subzone : 0;
}

//-----------------------------------------------------------------------------
// setReceiveEvent
//-----------------------------------------------------------------------------

vscpws_slider.prototype.setReceiveEvent = function(vscpclass,
                                                                vscptype,
                                                                data,
                                                                guid )
{

     var dataArray;

    //
    // First set default parameter
    vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : VSCP_CLASS1_INFORMATION;
    vscptype = typeof vscptype !== 'undefined' ? vscptype : VSCP_TYPE_INFORMATION_LEVEL_CHANGED;
    guid = typeof guid !== 'undefined' ? guid : "";  // GUID dont'care
    this.receive_vscpclass = vscpclass;
    this.receive_vscptype = vscptype;
    this.receive_guid = guid;

    if (this.receive_vscptype ==VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL)
    {
        dataArray = new Array(-1,0,0,0,0,0,0,0); // index = dont care, zone=0, subzone=0 , data , data, data, data, data
    }
    else   // VSCP_TYPE_CONTROL_DIM_LAMPS
    {
        dataArray = new Array(0,0,0); // Dimvalue = 0, zone=0, subzone=0
    }
    data = typeof data !== 'undefined' ? data : dataArray;
    this.receive_data = data;


    // Set filter
    //this.setFilter();
}

//-----------------------------------------------------------------------------
// setReceiveZone
//-----------------------------------------------------------------------------

vscpws_slider.prototype.setReceiveZone = function(index,zone,subzone)
{
    if((this.receive_vscpclass == VSCP_CLASS1_CONTROL) && (this.receive_vscptype == VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL))
    {
        this.receive_data[0] = typeof index !== 'undefined' ? index : 0;
    }
    this.receive_data[1] = typeof zone !== 'undefined' ? zone : 0;
    this.receive_data[2] = typeof subzone !== 'undefined' ? subzone : 0;
}


//-----------------------------------------------------------------------------
// updateSlider
//-----------------------------------------------------------------------------


vscpws_slider.prototype.updateSlider = function()
{
    //alert("hell0");
    this.sliderTxtCanvas.innerHTML = this.sliderCanvas.value;

    //send vscp event
    this.setValue(this.sliderCanvas.value);
}

//-----------------------------------------------------------------------------
// setMonitorVariable
//-----------------------------------------------------------------------------

vscpws_slider.prototype.setMonitorVariable = function(name,interval, bOnce)
{
    if ( ( "" == name ) && ( typeof interval !== 'undefined' ) ) {
        clearInterval( this.variableTimer );
    }
    else {
        // First set default parameter
        interval = typeof interval !== 'undefined' ? interval : 1000;
        this.bOnce = typeof bOnce !== 'undefined' ? bOnce : false;
        this.monitorVariableName = name;
        this.monitorInterval = interval;

        var t = this;
        this.variableTimer = setInterval(function(){t.time4VariableRead(t.monitorVariableName,t.socket_vscp);}, interval);
    }
}

//-----------------------------------------------------------------------------
// setMonitorVariableName
//-----------------------------------------------------------------------------

vscpws_slider.prototype.setMonitorVariableName = function(name)
{
    this.monitorVariableName = name;
}

//-----------------------------------------------------------------------------
// processTxData
//-----------------------------------------------------------------------------

vscpws_slider.prototype.processTxData = function(value)
{
  // value is the value received from slider  --> VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL
  // value can be --. +ve or _ve number
  // Split value into bytes & save into -- this.tansmitt_data[3],this.tansmitt_data[4],this.tansmitt_data[5]
  //                                       this.tansmitt_data[6], this.tansmitt_data[7]
}

//-----------------------------------------------------------------------------
// processRxData
//-----------------------------------------------------------------------------

vscpws_slider.prototype.processRxData = function(vscpdata)
{
  // vscpdata --> is data received for remote device ( +ve or _ve number) --> VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
  // depending upon vscpdata.length value -- set the --> this.sliderRemoteValue
  // vscpdata[3],vscpdata[4],vscpdata[5],vscpdata[6], vscpdata[7]

  this.sliderRemoteValue = 0;

}

//-----------------------------------------------------------------------------
// setValue
//-----------------------------------------------------------------------------

vscpws_slider.prototype.setValue = function(value)
{
    var cmd="E;0,"; // Event + priority

    //if (value) {

        if (vscpws_debug) console.log("True");

        // Send Turn On Event
        if (this.bConnected && (-1 != this.tansmitt_vscpclass ) ) {

            cmd += this.tansmitt_vscpclass.toString() + ",";
            cmd += this.tansmitt_vscptype.toString() + ",";
            cmd += "0,0,"; // obid and timestamp
            if ("" == this.tansmitt_guid) {
                cmd += "-"; // Use daemon interface GUID
            }
            else {
                cmd += this.tansmitt_guid.toString();
            }
            cmd += ",";
            if (this.tansmitt_vscptype ==VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL)
            {
                this.processTxData(value)
            }
            else  // VSCP_TYPE_CONTROL_DIM_LAMPS
            {
                this.tansmitt_data[0] = value;

            }

            for (i=0;i<this.tansmitt_data.length;i++) {
                    cmd += this.tansmitt_data[i].toString() + ",";
                    if (i<this.tansmitt_data.length-1) cmd += ",";   // No comma for last
            }

            if (vscpws_debug) console.log(cmd);
            this.socket_vscp.send(cmd);

        }
    //}

};



//-----------------------------------------------------------------------------
// onVSCPOpen
//-----------------------------------------------------------------------------

vscpws_slider.prototype.onVSCPOpen = function()
{
    if (vscpws_debug) console.log('Open VSCP websocket');
    this.bConnected = true;
    //this.socket_vscp.send("C;" + "open");
    //----this.socket_vscp.send("C;" + "NOOP");
};

//-----------------------------------------------------------------------------
// onVSCPClose
//-----------------------------------------------------------------------------

vscpws_slider.prototype.onVSCPClose = function()
{
    if (vscpws_debug) console.log('Close VSCP websocket');
    this.bConnected = false;
    this.socket_vscp.send("C;" + "close");

};


//-----------------------------------------------------------------------------
// onVSCPMessage
//-----------------------------------------------------------------------------
// handle VSCP socketcan incoming message/event.
vscpws_slider.prototype.onVSCPMessage = function(msg)
{
    if (vscpws_debug) console.log('onVSCPMessage -' + this.instanceName + " " + msg.data);

    msgitems = msg.data.split(';');

    /*if(this.messageTestFlag == 0)
    {
        //Increase the message counter
        this.numMessages++;
    }*/

    if ("+" == msgitems[0]){        // check for positive reply

        if (vscpws_debug) console.log("Positive reply "+msg.data);
        respone = msgitems[0].split(";");

        if ( "AUTH0" == msgitems[1] )
        {
            //Authentication 0 -  challange
            var msg = "C;AUTH;" + this.user + ";" + vscp_make_websocket_auth_hash( this.user, this.passwordhash, msgitems[2] );
            this.socket_vscp.send( msg );
        }
        else if ( "AUTH1" == msgitems[1] )
        {
            // successfully log in -- Authentication 1 - Logged in
            //this.numMessages = 0;
            //this.messageTestFlag = 1;

            // We are authenticated and ready to go to work
            this.socket_vscp.send("C;" + "OPEN");
        }
        else if ( "OPEN" == msgitems[1] ) {
            // Open confirmation => We are connected
            this.bConnected = true;

            //read the variable value
            //this.setMonitorVariable(this.monitorVariableName);
        }
        else if ( "CLOSE" == msgitems[1] ) {
            // Close confirmation => We are NOT connected
            this.bConnected = false;
        }
        else if ("READVAR" == msgitems[1])
        {
            if((this.receive_vscpclass == VSCP_CLASS1_INFORMATION) && (this.receive_vscptype == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED))
            {
                if ("READVAR" == msgitems[1] && (9 == msgitems[2])){
                    // todo --> set the Remote Data

                    // Stop the variable read
                    clearInterval(this.setInterval_Id);
                }
            }
            else  // VSCP_TYPE_INFORMATION_LEVEL_CHANGED
            {
                if ("READVAR" == msgitems[1] && (3 == msgitems[2])){
                    // todo --> set the Remote Data


                    if ( this.bOnce && ( typeof interval !== 'undefined' ) ) {
                        clearInterval( this.variableTimer );
                        this.bOnce = false;
                    }
                    // Stop the variable read
                    //clearInterval(this.setInterval_Id);
                }
            }
        }
        else
        {
            //do nothing
        }

    }
    else if ("-" == msgitems[0]){   // Check for negative reply
        if (vscpws_debug) console.log("Negative reply " + msg.data);
    }
    else if ("E" == msgitems[0]){   // Check for event
        var offset = 0; // used for Level I events over Level II

        //head;class;type;guid,data
        var vscpitems = msgitems[1].split(",");

        var vscphead = vscpitems[0];
        var vscpclass = vscpitems[1];
        var vscptype = vscpitems[2];
        var vscpobid = vscpitems[3];
        var vscptimestamp = vscpitems[4];
        var vscpguid = vscpitems[5];
        var vscpdata = new Array();
        for (i=0;i<vscpitems.length-6;i++){
            vscpdata[i] = vscpitems[6+i];
        }

        // Check if we have Level I events over Level II
        if ( vscpclass >= 512 && vscpclass < 1024 ) {
            offset = 16;    // Offset into data
            vscpclass -= 512;
        }

        if (vscpws_debug) console.log("CLASS = " + vscpclass + " Trigg on " + this.receive_vscpclass );
        if (vscpws_debug) console.log(" TYPE = " + vscptype + " Trigg on " + this.receive_vscptype );

        // Check GUID
        if ( ("" != this.receive_guid) &&
                this.receive_guid.toLowerCase() != guid.toLowerCase()) return;

        // Nothing to do if vscpclass or vscptype is undefined
        if ((vscpclass == undefined) || (vscptype == undefined) ) return;

        // Check if this is a possible Rx-event
        if (vscpclass == this.receive_vscpclass &&
                vscptype == this.receive_vscptype ) {
            // Check data if any
            if (this.receive_data.length ) {

                // Check zone & subzone & index
                if((this.receive_vscpclass == VSCP_CLASS1_INFORMATION) && (this.receive_vscptype == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED))
                {
                    //for (i=0;i<this.receive_data.length;i++) {
                    for (i=0;i<3;i++) {
                        // Skip a don't care
                        if (( -1 == this.receive_data[i] )||(this.receive_data[i] == undefined)) continue;
                        if ((vscpdata[i] != this.receive_data[i])||(vscpdata[i] == undefined))  return;
                    }
                }
                else  // VSCP_TYPE_INFORMATION_LEVEL_CHANGED
                {
                    for (i=1;i<3;i++) {
                        // Skip a don't care
                        if (( -1 == this.receive_data[i] )||(this.receive_data[i] == undefined)) continue;
                        if ((vscpdata[i] != this.receive_data[i])||(vscpdata[i] == undefined))  return;
                    }

                }
            }

            if((this.receive_vscpclass == VSCP_CLASS1_INFORMATION) && (this.receive_vscptype == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED))
            {
                processRxData(vscpdata);
            }
            else // VSCP_TYPE_INFORMATION_LEVEL_CHANGED
            {
                //this.sliderRemoteValue= vscpdata[0];
                this.sliderRemoteValue= parseInt(vscpdata[0], 16);
            }

            //set the remote text recived data
            this.txtCanvas.innerHTML = this.sliderRemoteValue;

            if (vscpws_debug) console.log("****** Data received Correctly ******");
        }

    }

    if (this.numMessages > 10)
    {
        this.socket_vscp.send('exit');
    }

}



//-----------------------------------------------------------------------------
// openConnection
//-----------------------------------------------------------------------------
// Open/close event traffic
vscpws_slider.prototype.openConnection = function()
{
    this.socket_vscp.send("C;" + "open");
}

//-----------------------------------------------------------------------------
// closeConnection
//-----------------------------------------------------------------------------
vscpws_slider.prototype.closeConnection = function()
{
    this.socket_vscp.send("C;" + "close");
}

//-----------------------------------------------------------------------------
// time4VariableRead
//-----------------------------------------------------------------------------
vscpws_slider.prototype.time4VariableRead = function(m,s)
{
    var cmd;
    if (vscpws_debug) console.log("time4VariableRead");
    cmd = "C;READVAR;" + m;
    s.send(cmd);
}
