///////////////////////////////////////////////////////////////////////////////
// dummy_Device_vscpStateButton_mod
//

function dummy_Device_vscpStateButton_mod( username,           // Username for websocket serever
                                passwordhash,    // Password hash for websocket
                               url             // url to VSCP websocket i/f
                                   )
{
    //console.log("val " + Info_details.info_text[50].direction);
    //console.log("val_99 " +Info_details.info_text[99].direction);
    //return;

    // Websocket for VSCP daemon communication
    this.socket_vscp = null;
    
    // Flag for connected or unconnected state.
    this.bConnected = false;

    this.bState = false;
    this.bOnReceived = 0;
    
    // Events to send to turn ON
    //this.tansmitt_vscpclass_on = VSCP_CLASS1_CONTROL;     // Default class is CLASS1.CONTROL
    //this.tansmitt_vscptype_on = VSCP_TYPE_CONTROL_TURNON; // Default type is TurnOn
    this.tansmitt_vscptype_on = new Array(0,0,0); // Index=0, zone=0, subzone=0
    this.tansmitt_guid_on = "-";        // Default GUID is GUID of interface.
    
    // Events to send to turn OFF 
    //this.tansmitt_vscpclass_off = VSCP_CLASS1_CONTROL;      // Default class is CLASS1.CONTROL
    //this.tansmitt_vscptype_off = VSCP_TYPE_CONTROL_TURNOFF; // Default type is TurnOff
    this.tansmitt_vscptype_on = new Array(0,0,0); // Index=0, zone=0, subzone=0
    this.tansmitt_guid_off = "-";       // Default GUID is GUID of interface.
    
    
    // Receive events to confirm Turn ON
    //this.receive_vscpclass_on = VSCP_CLASS1_INFORMATION;   // Default class is CLASS1.INFORMATION
    //this.receive_vscptype_on = VSCP_TYPE_INFORMATION_ON;   // Default type is On
    this.receive_data_on = new Array(-1,0,0); // zone=0, subzone=1
    this.receive_guid_on = "";          // Default GUID (empty is any).
    
    // Receive events to confirm turn OFF 
    //this.receive_vscpclass_off = VSCP_CLASS1_INFORMATION;  // Default class is CLASS1.CONTROL
    //this.receive_vscptype_off = VSCP_TYPE_INFORMATION_OFF; // Default type is Off
    this.receive_data_off = new Array(-1,0,0); // zone=0, subzone=1
    this.receive_guid_off = "";         // Default GUID (empty is any).

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


    // set event send by gui value to false
    this.eventSend = 0;

    // Set default events
    this.setOnTransmittEvent();
    this.setOffTransmittEvent();

    this.setOnReceiveEvent();
    this.setOffReceiveEvent();
    
};



//-----------------------------------------------------------------------------
// setOnTransmittEvent
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setOnTransmittEvent = function(vscpclass,
                                                                vscptype,
                                                                data,        
                                                                guid ) 
{
    var dataArray = new Array(0,0,0); // index=0, zone=0, subzone=0
    
    // First set default parameter
    vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : 20;
    vscptype = typeof vscptype !== 'undefined' ? vscptype : 3;
    data = typeof data !== 'undefined' ? data : dataArray;
    guid = typeof guid !== 'undefined' ? guid : "-";
    
    
    this.tansmitt_vscpclass_on = vscpclass;
    this.tansmitt_vscptype_on = vscptype;
    this.tansmitt_data_on = data;
    this.tansmitt_guid_on = guid;
};

//-----------------------------------------------------------------------------
// setOnTransmittZone
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setOnTransmittZone = function(index,zone,subzone)
{
    this.tansmitt_data_on[0] = typeof index !== 'undefined' ? index : 0;
    this.tansmitt_data_on[1] = typeof zone !== 'undefined' ? zone : 0;
    this.tansmitt_data_on[2] = typeof subzone !== 'undefined' ? subzone : 0;
};

//-----------------------------------------------------------------------------
// setOffTransmittEvent
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setOffTransmittEvent = function(vscpclass,
                                                                vscptype,
                                                                data,        
                                                                guid) 
{
    var dataArray = new Array(0,0,0); // index=0, zone=0, subzone=0
    
    // First set default parameter
    vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : 20;
    vscptype = typeof vscptype !== 'undefined' ? vscptype : 4;
    data = typeof data !== 'undefined' ? data : dataArray;
    guid = typeof guid !== 'undefined' ? guid : "-";
    
    this.tansmitt_vscpclass_off = vscpclass;
    this.tansmitt_vscptype_off = vscptype;
    this.tansmitt_data_off = data;
    this.tansmitt_guid_off = guid;
};

//-----------------------------------------------------------------------------
// setOffTransmittZone 
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setOffTransmittZone = function(index,zone,subzone)
{
    this.tansmitt_data_off[0] = typeof index !== 'undefined' ? index : 0;
    this.tansmitt_data_off[1] = typeof zone !== 'undefined' ? zone : 0;
    this.tansmitt_data_off[2] = typeof subzone !== 'undefined' ? subzone : 0;
};

//-----------------------------------------------------------------------------
// setOnReceiveEvent
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setOnReceiveEvent = function(vscpclass,
                                                                vscptype,
                                                                data,        
                                                                guid ) 
{
    var dataArray = new Array(-1,0,0); // index=don't care, zone=0, subzone=0
    //
    // First set default parameter
    vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : 30;
    vscptype = typeof vscptype !== 'undefined' ? vscptype : 5;
    data = typeof data !== 'undefined' ? data : dataArray;
    guid = typeof guid !== 'undefined' ? guid : "";  // GUID dont'care
    
    this.receive_vscpclass_on = vscpclass;
    this.receive_vscptype_on = vscptype;
    this.receive_guid_on = guid;
    
    // Set filter
    this.setFilter();
};

//-----------------------------------------------------------------------------
// setOnReceiveZone
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setOnReceiveZone = function(index,zone,subzone)
{
    this.receive_data_on[0] = typeof index !== 'undefined' ? index : 0;
    this.receive_data_on[1] = typeof zone !== 'undefined' ? zone : 0;
    this.receive_data_on[2] = typeof subzone !== 'undefined' ? subzone : 0;
};

//-----------------------------------------------------------------------------
// setOffReceiveEvent
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setOffReceiveEvent = function(vscpclass,
                                                                vscptype,
                                                                data,
                                                                guid ) 
{
    var dataArray = new Array(-1,0,0); // index=don't care, zone=0, subzone=0
    //
    // First set default parameter
    vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : 30;
    vscptype = typeof vscptype !== 'undefined' ? vscptype : 6;
    data = typeof data !== 'undefined' ? data : dataArray;
    guid = typeof guid !== 'undefined' ? guid : "";  // GUID dont'care
    
    this.receive_vscpclass_off = vscpclass;
    this.receive_vscptype_off = vscptype;
    this.receive_guid_off = guid;
    
    // Set filter
    this.setFilter();
};

//-----------------------------------------------------------------------------
// setOffReceiveZone
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setOffReceiveZone = function(index,zone,subzone)
{
    this.receive_data_off[0] = typeof index !== 'undefined' ? index : 0;
    this.receive_data_off[1] = typeof zone !== 'undefined' ? zone : 0;
    this.receive_data_off[2] = typeof subzone !== 'undefined' ? subzone : 0;
};


//-----------------------------------------------------------------------------
// setFilter
//-----------------------------------------------------------------------------
dummy_Device_vscpStateButton_mod.prototype.setFilter = function()
{
    var cmd;
    
    var filter_class = 0;
    var filter_type = 0;
    var filter_guid = new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    
    // Zero for a mask is don't care        
    var mask_class = 0;
    var mask_type = 0;
    var mask_guid = new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    
    // 0 0 = mask=1 filter=0
    // 0 1 = mask=0 filter=x
    // 1 0 = mask=0 filter=x
    // 1 1 = mask=1 filter=1
    
    // If any of the classes are don't care mask should also be don't care
    if ( (-1 == this.receive_vscpclass_off) || (-1 == this.receive_vscpclass_on) ) {
        mask_class = 0; // Don't care
    }
    else {
        mask_class = ~(this.receive_vscpclass_off ^ this.receive_vscpclass_on);
    }
    
    filter_class = (this.receive_vscpclass_off & this.receive_vscpclass_on);
    
    // If any of the types are don't care mask should also be don't care
    if ( (-1 == this.receive_vscptype_off) || (-1 == this.receive_vscptype_on) ) {
        mask_type = 0; // Don't care
    }
    else {
        mask_type = ~(this.receive_vscptype_off ^ this.receive_vscptype_on);
    }
    
    filter_type = (this.receive_vscptype_off & this.receive_vscptype_on);
    
    if ( ("" == this.receive_guid_off) || ("" == this.receive_guid_on) ) {
        mask_guid = new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);     // Don't care
        filter_guid = new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);   // Don't care
    }
    else {
        guid_on = this.receive_guid_on.split(":");
        guid_off = this.receive_guid_off.split(":");
        for ( i=0; i<16; i++ ) {
            mask_guid[i] = ~(this.receive_guid_off[i] ^ this.receive_guid_on[i]);
            filter_guid[i] = (this.receive_guid_off[i] & this.receive_guid_on[i]);
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
};


//-----------------------------------------------------------------------------
// setValue
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.setValue = function(value, bUpdate)
{
    var cmd="E;0,"; // Event + priority    

    // First set default parameter
    bUpdate = typeof bUpdate !== 'undefined' ? bUpdate : true;
    
    if (vscpws_debug) console.log('setValue -' + this.instanceName);

    if (value) {
        
        if (vscpws_debug) console.log("True");
        
        // Send Turn On Event
        if (this.bConnected && (-1 != this.tansmitt_vscpclass_on ) ) {

            cmd += this.tansmitt_vscpclass_on.toString() + ",";
            cmd += this.tansmitt_vscptype_on.toString() + ",";
            cmd += "0,0,"; // obid and timestamp
            if ("" == this.tansmitt_guid_on) {
                cmd += "-"; // Use daemon interface GUID
            }
            else {
                cmd += this.tansmitt_guid_on.toString();
            }
            cmd += ",";
            for (i=0;i<this.tansmitt_data_on.length;i++) {
                    cmd += this.tansmitt_data_on[i].toString() ; //+ ",";
                    if (i<this.tansmitt_data_on.length-1) cmd += ",";   // No comma for last
            }
            
            if (vscpws_debug) console.log(cmd);
            this.socket_vscp.send(cmd);
            
            if ("" != this.monitorVariableName) {
                //cmd = "C;WRITEVAR;" + this.monitorVariableName + ";true";
                //this.socket_vscp.send(cmd);
            }
        }
        
        //if (this.bLocal) this.bState = true;
    }
    else {
        
        if (vscpws_debug) console.log("False");
        
        // Send Turn Off Event
        if (this.bConnected && (-1 != this.tansmitt_vscpclass_off)) {
            cmd += this.tansmitt_vscpclass_off.toString() + ",";
            cmd += this.tansmitt_vscptype_off.toString() + ",";
            cmd += "0,0,"; // obid and timestamp
            if ("" == this.tansmitt_guid_off) {
                cmd += "-"; // Use daemon interface GUID
            }
            else {
                cmd += this.tansmitt_guid_off.toString();
            }
            cmd += ",";
            for (i=0;i<this.tansmitt_data_off.length;i++) {
                    cmd += this.tansmitt_data_off[i].toString() ; //+ ",";
                    if (i<this.tansmitt_data_off.length-1) cmd += ",";   // No comma for last
            }
            
            if (vscpws_debug) console.log(cmd);
            this.socket_vscp.send(cmd);
            
            if ("" != this.monitorVariableName) {
                //cmd = "C;WRITEVAR;" + this.monitorVariableName + ";false";
                //this.socket_vscp.send(cmd);
            }
        }
        
        //if (this.bLocal) this.bState = false;
    }

};

//-----------------------------------------------------------------------------
// onVSCPOpen
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.onVSCPOpen = function()
{
    if (vscpws_debug) console.log('Open VSCP websocket');
    // this.bConnected = true;
    //this.socket_vscp.send("C;" + "open");
    //----this.socket_vscp.send("C;" + "NOOP");
       
    // Set filter
    this.setFilter();
};

//-----------------------------------------------------------------------------
// onVSCPClose
//-----------------------------------------------------------------------------

dummy_Device_vscpStateButton_mod.prototype.onVSCPClose = function()
{
    if (vscpws_debug) console.log('Close VSCP websocket');
    this.bConnected = false;
};


//-----------------------------------------------------------------------------
// onVSCPMessage
//-----------------------------------------------------------------------------
// handle VSCP socketcan incoming message/event.	
dummy_Device_vscpStateButton_mod.prototype.onVSCPMessage = function(msg)
{

//alert("Rx");
    if (vscpws_debug) console.log('onVSCPMessage --->' + this.instanceName + " " + msg.data);
	
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
                    
        //if (vscpws_debug) console.log("CLASS = " + vscpclass + " TYPE = " + vscptype + "\n " + msg.data);
        if (vscpws_debug) console.log("CLASS = " + vscpclass + " Trigg on " + this.receive_vscpclass_on );
        if (vscpws_debug) console.log(" TYPE = " + vscptype + " Trigg on " + this.receive_vscptype_on );

        // Nothing to do if vscpclass or vscptype is undefined
        if ((vscpclass == undefined) || (vscptype == undefined) ) return;

        // Check if this is a possible ON-event
        if (vscpclass == this.receive_vscpclass_on && 
                vscptype == this.receive_vscptype_on ) {

            //alert("ok");
            // Check data if any
            if (this.receive_data_on.length ) {
                for (i=0;i<this.receive_data_on.length;i++) {
                    // Skip a don't care
                    if ( -1 == this.receive_data_on[i] ) continue;
                    if ( (vscpdata[i] == undefined) || 
                           (vscpdata[i] != this.receive_data_on[i]) ) return;
                }
            }

            //alert("ok - 1");

            // Check GUID
            if ( ("" != this.receive_guid_on) && 
                    this.receive_guid_on.toLowerCase() != vscpguid.toLowerCase()) return;
            
            // We have a match for ON
            this.bOnReceived = 1;

            //alert("guid - ON : " + this.receive_guid_on.toLowerCase());

            if (vscpws_debug) console.log("****** Turned ON ******");
        }
        
        // Check if this is a possible OFF-event
        if (vscpclass == this.receive_vscpclass_off && 
                vscptype == this.receive_vscptype_off ) {
            // Check data if any
            //alert("gg");
            if (this.receive_data_off.length ) {
            //alert("length = " + this.receive_data_off.length);
                for (i=0;i<this.receive_data_off.length;i++) {
                    // Skip a don't care
                    if ( -1 == this.receive_data_off[i] ) continue;
                    if ( (vscpdata[i] == undefined) || 
                           (vscpdata[i] != this.receive_data_off[i]) ) return;

                }
            }
                 
            //alert("gg _ 1");
            // Check GUID
            if (("" != this.receive_guid_off) && 
                    this.receive_guid_off.toLowerCase() != guid.toLowerCase()) return;

            //alert("guid - OFF : " + this.receive_guid_off.toLowerCase());

            // We have a match for OFF
            // We have a match for ON
            if(this.bOnReceived == 1)
            {
                if(this.bState == false)
                {
                    //send information on event
                    this.setValue(true);
                    this.bState = true;
                }
                else
                {
                    //send information off event
                    this.setValue(false);
                    this.bState = false;
                }

                this.bOnReceived = 0;
            }


            if (vscpws_debug) console.log("****** Turned OFF ******");
        }

    }

    /*if (this.numMessages > 10)
    {
        this.socket_vscp.send('exit');
    }*/

};



//-----------------------------------------------------------------------------
// openConnection
//-----------------------------------------------------------------------------
// Open/close event traffic	
dummy_Device_vscpStateButton_mod.prototype.openConnection = function()
{
	this.socket_vscp.send("C;" + "open");
};
    
//-----------------------------------------------------------------------------
// closeConnection
//-----------------------------------------------------------------------------    
dummy_Device_vscpStateButton_mod.prototype.closeConnection = function()
{
	this.socket_vscp.send("C;" + "close");
};

//-----------------------------------------------------------------------------
// time4VariableRead
//-----------------------------------------------------------------------------    
dummy_Device_vscpStateButton_mod.prototype.time4VariableRead = function(m,s)
{
    var cmd;
    if (vscpws_debug) console.log("time4VariableRead");
    cmd = "C;READVAR;" + m;
	s.send(cmd);
};
