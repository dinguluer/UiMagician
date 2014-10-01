// http://stackoverflow.com/questions/109086/stop-setinterval-call-in-javascript

///////////////////////////////////////////////////////////////////////////////
// vscpws_simpleTextEvent_mod
//

function vscpws_simpleTextEvent_mod( username,           // Username for websocket serever
                                    passwordhash,    // Password hash for websocket
                                    url,           // url to VSCP websocket i/f
                                    id,              // Where it should be placed
                                    vscpclass,       // Event class 10/60/65/15
                                    vscptype,        // Evet type
                                    codingIndex,     // Datacoding index
                                    decimals,        // Number of decimals
                                    formatstr,       // A value format string
                                    guid,            // GUID we are interested in
                                    fncallback,     // If set function to call when data arraives
                                    variableName,        // Variable name to be monitored
                                    interval             // Variable monitoring interval
                                       )
{
    // First set default parameter
    this.elementId = id;
    this.vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : VSCP_CLASS1_MEASUREMENT; // Meaurement
    this.vscptype = typeof vscptype !== 'undefined' ? vscptype : VSCP_TYPE_MEASUREMENT_TEMPERATURE;     // Temperature
    this.formatstr = typeof formatstr !== 'undefined' ? formatstr : "{0}";
    this.guid = typeof guid !== 'undefined' ? guid : "";
    this.codingIndex = typeof codingIndex !== 'undefined' ? codingIndex : 0;
    this.decimals = typeof decimals !== 'undefined' ? decimals : 2;
    this.fncallback = (fncallback && typeof(fncallback) === "function") ? fncallback : null;

    this.index = -1;
    this.zone = -1;
    this.subzone = -1;

    this.bOnce = false; // Monitor variable is checked on intervals

    // Websocket for VSCP daemon communication
    this.socket_vscp = null;

    // Flag for connected or unconnected state.
    this.bConnected = false;

    // Monitorvariabel - Should be a boolean variable
    variableName = typeof variableName !== 'undefined' ? variableName : ""; // Default is none
    this.monitorVariableName = variableName;
    interval = typeof interval !== 'undefined' ? interval : 1000; // Default is none
    this.monitorInterval = interval;        // Monitor interval is each second

    //this.numMessages = 0;
    //this.messageTestFlag = 0;

    this.user = username;
    this.password = "";
    this.domain = "";
    this.passwordhash = passwordhash;

    // Set the instance name for the control
    instanceName = "vscpws_" + this.elementId;

    // move this to global scope
    eval(instanceName + " = this;");

    // remember instance name
    this.instanceName = instanceName;

    // Open the socket
    this.socket_vscp = vscpws_openSocket(url);

    if (null==this.socket_vscp ) alert("Could not open websocket to VSCP server!");

    // Bind events
    this.socket_vscp.onmessage = this.onVSCPMessage.bind(this);
    this.socket_vscp.onopen = this.onVSCPOpen.bind(this);
    this.socket_vscp.onclose = this.onVSCPClose.bind(this);

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
// onVSCPOpen
//-----------------------------------------------------------------------------

vscpws_simpleTextEvent_mod.prototype.setExtraParameters =
                            function( index,     // Index if applicable
                                        zone,    // Zone if applicable
                                        subzone )// Subzone if applicable
{
    this.index = typeof index !== 'undefined' ? index : -1;
    this.zone = typeof zone !== 'undefined' ? zone : -1;
    this.subzone = typeof subzone !== 'undefined' ? subzone : -1;
}

//-----------------------------------------------------------------------------
// onVSCPOpen
//-----------------------------------------------------------------------------

vscpws_simpleTextEvent_mod.prototype.onVSCPOpen = function()
{
    //document.getElementById(this.elementId).style.backgroundColor = "#40ff40";
    if (this.elementId) document.getElementById(this.elementId).textContent = " undefined ";
    if (vscpws_debug) console.log('Open VSCP websocket');
    this.bConnected = true;

    // Open the connection to the VSCP daemon
    //this.socket_vscp.send("C;" + "open");
    //---this.socket_vscp.send("C;" + "NOOP");

    // Set filter
    this.setFilter();
};

//-----------------------------------------------------------------------------
// onVSCPClose
//-----------------------------------------------------------------------------

vscpws_simpleTextEvent_mod.prototype.onVSCPClose = function()
{
    //document.getElementById(this.elementId).style.backgroundColor = "#ff4040";
    if (this.elementId) document.getElementById(this.elementId).textContent = " websocket connection CLOSED ";
    if (vscpws_debug) console.log('Close VSCP websocket');
    this.bConnected = false;
};


//-----------------------------------------------------------------------------
// setFilter
//-----------------------------------------------------------------------------
vscpws_simpleTextEvent_mod.prototype.setFilter = function()
{
    var cmd;

    var filter_class = this.vscpclass;
    var filter_type = this.vscptype;
    var filter_guid = new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

    // Zero for a mask is don't care
    var mask_class = -1 != this.vscpclass ? 0xff : 0x00;
    var mask_type = -1 != this.vscptype ? 0xff : 0x00;
    var mask_guid = new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

    if ( ("" != this.guid) ) {
        guid = this.guid.split(":");
        for ( i=0; i<16; i++ ) {
            mask_guid[i] = 0xff;
            filter_guid[i] = guid[i];
        }
    }

    // Send setfilter command. Format is
    // “C;SETFILTER;filter-priority,filter-class,filter-type,
    //    filter-GUID;mask-priority,mask-class,mask-type,mask-GUID”
    cmd = "C;SETFILTER;0x00,";
    cmd += "0x"+filter_class.toString(16) + ",";
    cmd += "0x"+filter_type.toString(16) + ",";
    for (i=0;i<16;i++) {
        cmd += "0x"+(filter_guid[i] & 255).toString(16);
        if (i<15) cmd += ":";   // No colon on last
    }
    cmd += ";0x00,";
    cmd += "0x" + (mask_class & 255).toString(16) + ",";
    cmd += "0x" + (mask_type & 255).toString(16) + ",";
    for (i=0;i<16;i++) {
        cmd += "0x"+(mask_guid[i] & 255).toString(16);
        if (i<15) cmd += ":";   // No colon on last
    }

    if (vscpws_debug) console.log("Set filter = "+ cmd);

    // Set filter/mask on server
    if (this.bConnected) this.socket_vscp.send(cmd);
}


//-----------------------------------------------------------------------------
// onVSCPMessage
//-----------------------------------------------------------------------------
// handle VSCP socketcan incoming message/event.
vscpws_simpleTextEvent_mod.prototype.onVSCPMessage = function(msg)
{
    if (vscpws_debug) console.log('onVSCPMessage -' + this.instanceName + " " + msg.data);

    /*if(this.messageTestFlag == 0)
    {
        //Increase the message counter
        this.numMessages++;
    }*/

    msgitems = msg.data.split(';');

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
        else if ("READVAR" == msgitems[1])  //Process the response
        {
            //process variable read value

            if ( this.bOnce && ( typeof interval !== 'undefined' ) ) {
                clearInterval( this.variableTimer );
                this.bOnce = false;
            }
            // Stop the variable read
            //clearInterval(this.setInterval_Id);
        }
        else
        {
            //do nothing
        }
    }
    else if ("-" == msgitems[0]){   // Check for negative reply
        if (vscpws_debug) console.log("Negative reply " + msg.data);
        respone = msgitems[0].split(";");
    }
    else if ("E" == msgitems[0]){   // Check for event

        var offset = 0;

        //head;class;type;guid,data
        var vscpitems = msgitems[1].split(",");

        var vscphead = parseInt(vscpitems[0]);
        var vscpclass = parseInt(vscpitems[1]);
        var vscptype = parseInt(vscpitems[2]);
        var vscpobid = parseInt(vscpitems[3]);
        var vscptimestamp = parseInt(vscpitems[4]);
        var vscpguid = vscpitems[5];

        // Check if we have Level I events over Level II
        if ( vscpclass >= 512 && vscpclass < 1024 ) {
            offset = 16;    // Offset into data
            vscpclass -= 512;
        }

        var vscpdata = new Array();
        for (i=0;i<vscpitems.length-6-offset;i++){
            vscpdata[i] = parseInt(vscpitems[offset+6+i]);
            //if (vscpws_debug) console.log("index="+i.toString()+" data="+vscpdata[i]);
        }

        if (vscpws_debug) console.log("CLASS = " + vscpclass + " TYPE = " + vscptype + "\n " + msg.data);

        // Nothing to do if vscpclass or vscptype is undefined
        if ((vscpclass == undefined) || (vscptype == undefined) ) return;
        if (( -1 != this.vscpclass) && (vscpclass != this.vscpclass)) return;
        if (( -1 != this.vscptype) && (vscptype != this.vscptype)) return;

        // Classes with datacoding byte
        if ((VSCP_CLASS1_MEASUREMENT == this.vscpclass) ||
                (VSCP_CLASS1_DATA == this.vscpclass) ) {

            if (( -1 != this.codingIndex) &&
                    (vscpws_getDatacodingSensorIndex(vscpdata[0]) != this.codingIndex)) return;

            // This event is for us
            var value = vscpws_measurementClass10Decode( vscpdata );
            alert(value);

            var strvalue = new String();
            if ( null !== this.fncallback ) {

                strvalue =
                    this.fncallback.call( this,
                                            value,
                                            vscpws_getDatacodingUnit( vscpdata[0] ),
                                            vscpitems);
                // null is returned we expect the callback routine to
                // write the value for us.
                if (null == strvalue ) return;
            }
            else {
                strvalue = vscpws_toFixed(value,this.decimals);
            }

            document.getElementById(this.elementId).textContent =
                    this.formatstr.format(strvalue,
                        vscpws_units[vscptype][vscpws_getDatacodingUnit(vscpdata[0])],
                        vscpws_getDatacodingUnit(vscpdata[0]),
                        vscpws_getDatacodingSensorIndex(vscpdata[0]));

        }
        // Floating point
        else if (VSCP_CLASS1_MEASUREMENT64 == this.vscpclass) {

            var value = vscpws_measurementClass60DecodeNumber(vscpdata);

            if ( null !== this.fncallback ) {
                var strvalue =
                    this.fncallback.call( this,
                                            value,
                                            vscpws_getDatacodingUnit( vscpdata[0] ),
                                            vscpitems);
                // null is returned we expect the callback routine to
                // write the value for us.
                if (null == strvalue ) return;
                document.getElementById(this.elementId).textContent =
                        this.formatstr.format(strvalue,
                            vscpws_units[vscptype][0],-1,-1);
            }
            else {
                document.getElementById(this.elementId).textContent =
                        this.formatstr.format(value.toString(),
                            vscpws_units[vscptype][0],-1,-1);
            }
        }
        // Measurement with zone
        else if ((VSCP_CLASS1_MEASUREZONE == this.vscpclass) ||
                    (VSCP_CLASS1_SETVALUEZONE == this.vscpclass) ) {

            // Check event index
            if (( -1 != this.index) &&
                    (vscpdata[0] != this.index)) return;
            // Check zone
            if (( -1 != this.zone) &&
                    (vscpdata[1] != this.zone)) return;
            // Check subzone
            if (( -1 != this.subzone) &&
                    (vscpdata[2] != this.subzone)) return;
            // Check sensor index
            if (( -1 != this.codingIndex) &&
                    (vscpws_getDatacodingSensorIndex[vscpdata[3]] != this.codingIndex)) return;

            // This is for us

            // Mimic a standard data format
            var mimicdata = new Array();
            for (i=3;i<vscpdata.length;i++) {
                mimicdata[i-3] = vscpdata[i];
            }

            var value = vscpws_measurementClass10Decode( mimicdata );

            var strvalue = new String();
            if ( null !== this.fncallback ) {
                strvalue =
                    this.fncallback.call( this,
                                            value,
                                            vscpws_getDatacodingUnit( vscpdata[0] ),
                                            vscpitems);
                // null is returned we expect the callback routine to
                // write the value for us.
                if (null == strvalue ) return;
            }
            else {
                strvalue = value.toString();
            }

            document.getElementById(this.elementId).textContent =
                    this.formatstr.format(strvalue,
                        vscpws_units[vscptype][vscpws_getDatacodingUnit(vscpdata[0])],
                        vscpws_getDatacodingUnit(vscpdata[0]),
                        vscpws_getDatacodingSensorIndex(vscpdata[0]));

        }
        // Other event
        else {
            var strValue = "Unknown";
            if ( null !== this.fncallback ) {
                strvalue =
                    this.fncallback.call( this,
                                            value,
                                            vscpws_getDatacodingUnit( vscpdata[0] ),
                                            vscpitems);
                // null is returned we expect the callback routine to
                // write the value for us.
                if (null == strvalue ) return;

                document.getElementById(this.elementId).textContent =
                    this.formatstr.format(strvalue,"", "", 0);
            }
        }
    }

    /*if (this.numMessages > 10)
    {
        this.socket_vscp.send('exit');
    }*/

}

//-----------------------------------------------------------------------------
// openConnection
//-----------------------------------------------------------------------------
// Open/close event traffic
vscpws_simpleTextEvent_mod.prototype.openConnection = function()
{
    this.socket_vscp.send("C;" + "open");
}

//-----------------------------------------------------------------------------
// closeConnection
//-----------------------------------------------------------------------------
vscpws_simpleTextEvent_mod.prototype.closeConnection = function()
{
    this.socket_vscp.send("C;" + "close");
}


//-----------------------------------------------------------------------------
// setMonitorVariable
//-----------------------------------------------------------------------------

vscpws_simpleTextEvent_mod.prototype.setMonitorVariable = function(name,interval, bOnce)
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
};


//-----------------------------------------------------------------------------
// setMonitorVariableName
//-----------------------------------------------------------------------------

vscpws_simpleTextEvent_mod.prototype.setMonitorVariableName = function(name)
{
    this.monitorVariableName = name;
}


//-----------------------------------------------------------------------------
// time4VariableRead
//-----------------------------------------------------------------------------
vscpws_simpleTextEvent_mod.prototype.time4VariableRead = function(m,s)
{
    var cmd;
    if (vscpws_debug) console.log("time4VariableRead");
    cmd = "C;READVAR;" + m;
    s.send(cmd);
}
