/*
** Author : Dinesh Guleria
** Date : 17/10/2014
** Note : This library is designed taking into refrence Ake Hedman, vscpws.js lib
*/

///////////////////////////////////////////////////////////////////////////////
// vscpws_simpleTextEvent
//

function vscpws_simpleTextEvent_mod( username,           // Username for websocket serever
                                    passwordhash,    // Password hash for websocket
                                    serverurl,       // url to VSCP websocket i/f
                                    id,              // Where it should be placed
                                    vscpclass,       // Event class 10/60/65/15
                                    vscptype,        // Evet type
                                    codingIndex,     // Datacoding index
                                    decimals,        // Number of decimals
                                    formatstr,       // A value format string
                                    guid,            // GUID we are interested in
                                    fncallback,     // If set function to call    // when data arraives
                                    graphId,
                                    graphUnitId,
                                    graphType
                                     )
{
    var d_time = new Date();
    //alert(d_time.getTime());
    var data = [
                {
                    label: "sensor Value",
                    //values: [{ time: d.getTime(), y: 20 }, { time: d.getTime(), y: 2 }]
                    //values: [{ time: 1370044800, y: 0 }]
                    values: [{ time: d_time.getTime(), y: 0 }]
                },
        ];

    // First set default parameter
    this.username = username;
    this.passwordhash = passwordhash;
    this.elementId = id;
    this.vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : VSCP_CLASS1_MEASUREMENT;            // Meaurement
    this.vscptype = typeof vscptype !== 'undefined' ? vscptype : VSCP_TYPE_MEASUREMENT_TEMPERATURE;     // Temperature
    this.formatstr = typeof formatstr !== 'undefined' ? formatstr : "{0}";
    this.guid = typeof guid !== 'undefined' ? guid : "";
    this.codingIndex = typeof codingIndex !== 'undefined' ? codingIndex : 0;
    this.decimals = typeof decimals !== 'undefined' ? decimals : 2;
    this.fncallback = (fncallback && typeof(fncallback) === "function") ? fncallback : null;      

    this.var_graphId= graphId;
    this.var_graphUnitId = graphUnitId;
    this.var_graphType = graphType;
    this.graphVar = '';

    // ************* Create Epoch Graph  ************* //
    if(this.var_graphType == 'line')
    {
        this.graphVar = $("#" + this.var_graphId).epoch({
            type: 'time.line',
            tickFormats: { time: function(d) { return new Date(time*1000).toISOString() } },
            data: data,
            axes: ['left', 'right', 'bottom']
        });
    }
    else if(this.var_graphType == 'bar')
    {
        this.graphVar = $("#" + this.var_graphId).epoch({
            type: 'time.bar',
            tickFormats: { time: function(d) { return new Date(time*1000).toISOString() } },
            data: data,
            axes: ['left', 'right', 'bottom']
        });
    }
    else if(this.var_graphType == 'area')
    {
        this.graphVar = $("#" + this.var_graphId).epoch({
            type: 'time.area',
            tickFormats: { time: function(d) { return new Date(time*1000).toISOString() } },
            data: data,
            axes: ['left', 'right', 'bottom']
        });
    }
    else  // by default create line
    {
        this.graphVar = $("#" + this.var_graphId).epoch({
            type: 'time.line',
            tickFormats: { time: function(d) { return new Date(time*1000).toISOString() } },
            data: data,
            axes: ['left', 'right', 'bottom']
        });
    }

    this.index = -1;
    this.zone = -1;
    this.subzone = -1;
    
    //alert(this.guid);
    // Websocket for VSCP daemon communication
    this.socket_vscp = null;
    
    // Flag for connected or unconnected state.
    this.bConnected = false;
    
    // Set the instance name for the control
    instanceName = "vscpws_" + this.elementId;
    
    // move this to global scope
    eval(instanceName + " = this;");
        
    // remember instance name
    this.instanceName = instanceName;
        
    // Open the socket
    this.socket_vscp = vscpws_openSocket(serverurl);
    
    if (null==this.socket_vscp ) {
        alert("Could not open websocket to VSCP server!");
    }
       
    // Bind events	
    this.socket_vscp.onmessage = this.onVSCPMessage.bind(this);	
    this.socket_vscp.onopen = this.onVSCPOpen.bind(this);
    this.socket_vscp.onclose = this.onVSCPClose.bind(this);
       
    //retrieve instance name
    this.getInstanceName = function() {
       return this.instanceName;
    }

    //default property
    this.toString = function() {
       return this.getInstanceName();
    }     
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
// onVSCPOpen
//-----------------------------------------------------------------------------

vscpws_simpleTextEvent_mod.prototype.setExtraParameters = 
                            function( index,     // Index if applicable 
                                        zone,    // Zone if applicable 
                                        subzone )// Sub zone if applicable  
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
    if (this.elementId) document.getElementById(this.elementId).textContent = 
            " undefined ";
    if (vscpws_debug) console.log('Open VSCP websocket');
    //this.bConnected = true;
    
    // Open the connection to the VSCP daemon
    //this.socket_vscp.send("C;" + "open");
    
    // Set filter
    //this.setFilter();
};

//-----------------------------------------------------------------------------
// onVSCPClose
//-----------------------------------------------------------------------------

vscpws_simpleTextEvent_mod.prototype.onVSCPClose = function() 
{
    //document.getElementById(this.elementId).style.backgroundColor = "#ff4040";
    if (this.elementId) document.getElementById(this.elementId).textContent = 
            " websocket connection CLOSED ";
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
    //    filter-GUID;mask-priority,mask-class,mask-type,mask-GUID\E2\80?
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
// handle VSCP websocket incoming message/event.	
vscpws_simpleTextEvent_mod.prototype.onVSCPMessage = function(msg) 
{	 
    if (vscpws_debug) console.log('onVSCPMessage -' + this.instanceName + 
                                    " " + msg.data);
	
    msgitems = msg.data.split(';');


    if ("+" == msgitems[0]){        // check for positive reply
        
        if (vscpws_debug) console.log("Positive reply "+msg.data);
        
        respone = msgitems[0].split(";");
        
        if ( "AUTH0" == msgitems[1] ) {
            var msg = "C;AUTH;" + this.username + ";" + 
                    vscp_make_websocket_auth_hash( this.username, 
                                                    this.passwordhash, 
                                                    msgitems[2] );
			this.socket_vscp.send(msg);
        }
        else if ( "AUTH1" == msgitems[1] ) {
        
            // We are authenticated and ready to go to work         
            this.socket_vscp.send("C;" + "OPEN");
       
            // Set filter
            //this.setFilter();
        }
        else if ( "OPEN" == msgitems[1] ) {
            // Open confirmation => We are connected
            this.bConnected = true;
                //alert(msgitems.length);
            console.log("OPENED --- ++ ");
        }
        else if ( "CLOSE" == msgitems[1] ) {
            // Close confirmation => We are NOT connected
            this.bConnected = false;
        }

        else if ("READVAR" == msgitems[1])  //Process the response
        {
            //process variable read value

            //alert('Readvar');

            if ("READVAR" == msgitems[1] && (9 == msgitems[3])){
msgitems_comma = msgitems[4].split(',')

//alert(msgitems.length);
//alert(msgitems[4]);
                offset = 0;
                var vscpdataVar = new Array();
                for (i=0;i<msgitems_comma.length-offset;i++){
                    vscpdataVar[i] = parseInt(msgitems_comma[offset+i]);
//alert(parseInt(msgitems_comma[offset+i]));
                    //if (vscpws_debug) console.log("index="+i.toString()+" data="+vscpdata[i]);
                }

                // Classes with data coding byte
                if ((VSCP_CLASS1_MEASUREMENT == this.vscpclass) ||
                        (VSCP_CLASS1_DATA == this.vscpclass) ) {

                    if (( -1 != this.codingIndex) &&
                            (vscpws_getSensorIndexFromDataCoding(vscpdataVar[0]) !=
                                                    this.codingIndex)) return;

                    // This event is for us
                    var value = vscpws_measurementClass10Decode( vscpdataVar );

                    var strvalue = new String();
                    if ( null !== this.fncallback ) {
                       //todo
                    }
                    else {
                        strvalue = vscpws_toFixed(value,this.decimals);
                    }

                    document.getElementById(this.elementId).textContent =
                        this.formatstr.format(strvalue,
                        vscpws_units[this.vscptype][vscpws_getDatacodingUnit(vscpdataVar[0])],
                        vscpws_getDatacodingUnit(vscpdataVar[0]),
                        vscpws_getSensorIndexFromDataCoding(vscpdataVar[0]));


                    // ***** update graph ***** //
                    //Modify the graph unit
                    document.getElementById(this.var_graphUnitId).textContent = vscpws_units[this.vscptype][vscpws_getDatacodingUnit(vscpdataVar[0])];
                    // Push data on graph
                    var d = new Date();
                    var time_var = 100 ; // = d.getTime();
                    var data = [{ time: d.getTime(), y: value }];
                    this.graphVar.push( data );


                }
                // Floating point
                else if (VSCP_CLASS1_MEASUREMENT64 == this.vscpclass) {

                    var value = vscpws_measurementClass60DecodeNumber(vscpdataVar);

                    if ( null !== this.fncallback ) {
                        // todo
                    }
                    else {
                        document.getElementById(this.elementId).textContent =
                                this.formatstr.format(value.toString(),
                                    vscpws_units[this.vscptype][0],-1,-1);
                    }
                }
                // Measurement with zone
                else if ((VSCP_CLASS1_MEASUREZONE == this.vscpclass) ||
                            (VSCP_CLASS1_SETVALUEZONE == this.vscpclass) ) {

                    // Check event index
                    if (( -1 != this.index) &&
                            (vscpdataVar[0] != this.index)) return;
                    // Check zone
                    if (( -1 != this.zone) &&
                            (vscpdataVar[1] != this.zone)) return;
                    // Check subzone
                    if (( -1 != this.subzone) &&
                            (vscpdataVar[2] != this.subzone)) return;
                    // Check sensor index
                    if (( -1 != this.codingIndex) &&
                            (vscpws_getSensorIndexFromDataCoding[vscpdataVar[3]] !=
                                                        this.codingIndex)) return;

                    // This is for us

                    // Mimic a standard data format
                    var mimicdata = new Array();
                    for (i=3;i<vscpdataVar.length;i++) {
                        mimicdata[i-3] = vscpdataVar[i];
                    }

                    var value = vscpws_measurementClass10Decode( mimicdata );

                    var strvalue = new String();
                    if ( null !== this.fncallback ) {
                        // to do
                    }
                    else {
                        strvalue = value.toString();
                    }

                    document.getElementById(this.elementId).textContent =
                        this.formatstr.format(strvalue,
                        vscpws_units[this.vscptype][vscpws_getDatacodingUnit(vscpdataVar[0])],
                        vscpws_getDatacodingUnit(vscpdataVar[0]),
                        vscpws_getSensorIndexFromDataCoding(vscpdataVar[0]));



                    // ***** update graph ***** //
                    //Modify the graph unit
                    document.getElementById(this.var_graphUnitId).textContent = vscpws_units[this.vscptype][vscpws_getDatacodingUnit(vscpdataVar[0])];
                    // Push data on graph
                    var d = new Date();
                    var data = [{ time: d.getTime(), y: value }];
                    this.graphVar.push( data );

                }
                // Other event
                else {
                    // do nothing
                }

            if ( this.bOnce && ( typeof this.monitorVariableName !== 'undefined' ) ) {
                clearInterval( this.variableTimer );
                this.bOnce = false;
            }
            // Stop the variable read
            //clearInterval(this.setInterval_Id);

            }
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

        //alert("event");
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
            //if (vscpws_debug) console.log("index="+i.toString()+
            //                                " data="+vscpdata[i]);
        }

        if (vscpws_debug) console.log("CLASS = " + vscpclass +
                " TYPE = " + vscptype + "\n " + msg.data);

        // Nothing to do if vscpclass or vscptype is undefined
        if ((vscpclass == undefined) || (vscptype == undefined) ) return;
        if (( -1 != this.vscpclass) && (vscpclass != this.vscpclass)) return;
        if (( -1 != this.vscptype) && (vscptype != this.vscptype)) return;

         // Check GUID
        if ( ("" != this.guid) &&
                this.guid.toLowerCase() != vscpguid.toLowerCase()) return;

        // Classes with data coding byte
        if ((VSCP_CLASS1_MEASUREMENT == this.vscpclass) ||
                (VSCP_CLASS1_DATA == this.vscpclass) ) {

            if (( -1 != this.codingIndex) &&
                    (vscpws_getSensorIndexFromDataCoding(vscpdata[0]) !=
                                            this.codingIndex)) return;

            // This event is for us
            var value = vscpws_measurementClass10Decode( vscpdata );

            var strvalue = new String();
            if ( null !== this.fncallback ) {
               console.log("Function");
                strvalue =
                    this.fncallback.call( this,
                                    value,
                                    vscpws_getDatacodingUnit( vscpdata[0] ),
                                    vscpitems );
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
                vscpws_getSensorIndexFromDataCoding(vscpdata[0]));


            //alert("jjj");
            // ***** update graph ***** //
            //Modify the graph unit
            document.getElementById(this.var_graphUnitId).textContent = vscpws_units[vscptype][vscpws_getDatacodingUnit(vscpdata[0])];
            // Push data on graph
            var d = new Date();
            var data = [{ time: d.getTime(), y: parseInt(value) }];
            this.graphVar.push( data );
            //alert("kkk");

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
                    (vscpws_getSensorIndexFromDataCoding[vscpdata[3]] !=
                                                this.codingIndex)) return;

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
                vscpws_getSensorIndexFromDataCoding(vscpdata[0]));



            // ***** update graph ***** //
            //Modify the graph unit
            document.getElementById(this.var_graphUnitId).textContent = vscpws_units[vscptype][vscpws_getDatacodingUnit(vscpdata[0])];
            // Push data on graph
            var d = new Date();
            var data = [{ time: d.getTime(), y: value }];
            this.graphVar.push( data );

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




