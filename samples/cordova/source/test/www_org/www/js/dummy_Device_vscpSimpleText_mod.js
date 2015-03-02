
///////////////////////////////////////////////////////////////////////////////
// vscpws_simpleTextEvent
//

function dummy_Device_vscpws_simpleTextEvent_mod( username,           // Username for websocket serever
                                    passwordhash,    // Password hash for websocket
                                    serverurl,       // url to VSCP websocket i/f
                                    vscpclass,       // Event class 10/60/65/15
                                    vscptype,        // Evet type
                                    codingIndex,     // Datacoding index
                                    guid             // GUID we are interested in
                                    )
{
    // First set default parameter
    this.username = username;
    this.passwordhash = passwordhash;
    this.vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : VSCP_CLASS1_MEASUREMENT;            // Meaurement
    this.vscptype = typeof vscptype !== 'undefined' ? vscptype : VSCP_TYPE_MEASUREMENT_TEMPERATURE;     // Temperature
    this.guid = typeof guid !== 'undefined' ? guid : "";
    this.codingIndex = typeof codingIndex !== 'undefined' ? codingIndex : 0;

    this.index = -1;
    this.zone = -1;
    this.subzone = -1;
    
    // Websocket for VSCP daemon communication
    this.socket_vscp = null;

    //dummy temperature
    this.dummyTemp = 0;
    
    //split GUID
    this.guid_split   = new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

    // Flag for connected or unconnected state.
    this.bConnected = false;

    // Open the socket
    this.socket_vscp = vscpws_openSocket(serverurl);
    
    if (null==this.socket_vscp ) {
        alert("Could not open websocket to VSCP server!");
    }
       
    this.messageProcess = 1;

    // Bind events	
    this.socket_vscp.onmessage = this.onVSCPMessage.bind(this);	
    this.socket_vscp.onopen = this.onVSCPOpen.bind(this);
    this.socket_vscp.onclose = this.onVSCPClose.bind(this);

}

//-----------------------------------------------------------------------------
// time4TempTransmitt
//-----------------------------------------------------------------------------
dummy_Device_vscpws_simpleTextEvent_mod.prototype.time4TempTransmitt = function(s,temp,guid_sensor)
{
    var cmd;
    var temp_1 = 0;
    var coding_value = 104;

    if (vscpws_debug) console.log("time4TempTransmitt");

    //cmd = "C;READVAR;" + m;



    if(temp < 20)
    {
        temp++;
    }
    else
    {
        temp = 0;
    }

    /*
    But if you only send integer temperaturs you could have sent

    011 01 000 = 0x68

    0,10,6,0,0,-,0x68,0,20

    instead or at you choice

    0,10,6,0,0,-,0x68,20
    0,10,6,0,0,-,0x68,0,20
    0,10,6,0,0,-,0x68,0,0,20
    0,10,6,0,0,-,0x68,0,0,0,20
    0,10,6,0,0,-,0x68,0,0,0,0,20
    0,10,6,0,0,-,0x68,0,0,0,0,0,20
    0,10,6,0,0,-,0x68,0,0,0,0,0,0,20
    */


    //cmd += "0x"+filter_type.toString(16) + ",";
    cmd += "0,10,6,0,0,";
    for (i=0;i<16;i++) {
        cmd += "0x"+(guid_sensor[i] & 255).toString(16);
        if (i<15) cmd += ":";   // No colon on last
    }
    cmd += ",";
    cmd +=coding_value.toString() + ",";
    cmd +=temp_1.toString() + ",";
    cmd +=temp.toString();

    // send the event
    s.send(cmd);

    if (vscpws_debug) console.log(cmd);
}

//-----------------------------------------------------------------------------
// setTxTemperature
//-----------------------------------------------------------------------------

dummy_Device_vscpws_simpleTextEvent_mod.prototype.setTxTemperature = function(interval)
{
    interval = typeof interval !== 'undefined' ? interval : 1000;

    if ( ("" != this.guid) ) {
       guid = this.guid.split(":");
       for ( i=0; i<16; i++ ) {
         this.guid_split[i] = guid[i];
       }
    }

    var cmd;
    var temp_1 = 0;
    var coding_value = 104;

    var t = this;
    //setInterval(function(){t.time4TempTransmitt(t.socket_vscp,t.dummyTemp,t.guid_split);}, interval);
    setInterval(function time4TempTransmitt_Local()
                    {

                    cmd="E;0,"; // Event + priority

                        if (vscpws_debug) console.log("time4TempTransmitt_Local");


                        if(t.dummyTemp < 20)
                        {
                            t.dummyTemp++;
                        }
                        else
                        {
                            t.dummyTemp = 0;
                        }


                        //cmd += "0x"+filter_type.toString(16) + ",";
                        cmd += "10,6,0,0,";
                        for (i=0;i<16;i++) {
                            //cmd += "0x"+(t.guid_split[i] & 255).toString(16);
                            cmd += t.guid_split[i];
                            if (i<15) cmd += ":";   // No colon on last
                        }
                        cmd += ",";
                        cmd +=coding_value.toString() + ",";
                        cmd +=temp_1.toString() + ",";
                        cmd +=t.dummyTemp.toString();

                        // send the event
                        t.socket_vscp.send(cmd);

                        if (vscpws_debug) console.log(cmd);
                        //alert("l");
                    }, interval);
};

//-----------------------------------------------------------------------------
// onVSCPOpen
//-----------------------------------------------------------------------------

dummy_Device_vscpws_simpleTextEvent_mod.prototype.setExtraParameters =
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

dummy_Device_vscpws_simpleTextEvent_mod.prototype.onVSCPOpen = function()
{
    if (vscpws_debug) console.log('Open VSCP websocket');

};

//-----------------------------------------------------------------------------
// onVSCPClose
//-----------------------------------------------------------------------------

dummy_Device_vscpws_simpleTextEvent_mod.prototype.onVSCPClose = function()
{
    if (vscpws_debug) console.log('Close VSCP websocket');
    this.bConnected = false;
};


//-----------------------------------------------------------------------------
// setFilter
//-----------------------------------------------------------------------------
dummy_Device_vscpws_simpleTextEvent_mod.prototype.setFilter = function()
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
dummy_Device_vscpws_simpleTextEvent_mod.prototype.onVSCPMessage = function(msg)
{	 
    if (vscpws_debug) console.log('onVSCPMessage -' + this.instanceName + 
                                    " " + msg.data);
	
    msgitems = msg.data.split(';');
				
    if(this.messageProcess == 1)
    {
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
                this.setFilter();

            }
            else if ( "OPEN" == msgitems[1] ) {
                // Open confirmation => We are connected
                this.bConnected = true;

                //Disable message received processing
                this.messageProcess = 0;

                //set timer event to send temperature
                this.setTxTemperature();
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
            respone = msgitems[0].split(";");
        }
        else if ("E" == msgitems[0]){   // Check for event

            // do nothing
        }

    }
}

//-----------------------------------------------------------------------------
// openConnection
//-----------------------------------------------------------------------------
// Open/close event traffic	
dummy_Device_vscpws_simpleTextEvent_mod.prototype.openConnection = function()
{
	this.socket_vscp.send("C;" + "open");
}
    
//-----------------------------------------------------------------------------
// closeConnection
//-----------------------------------------------------------------------------    
dummy_Device_vscpws_simpleTextEvent_mod.prototype.closeConnection = function()
{
	this.socket_vscp.send("C;" + "close");
}




