
function vscp_make_websocket_auth_hash( user, password, sid ){
    return hex_md5( user + ":" + password + ":" + sid );
};

function vscpws_stateButton_mod()
{

    alert("creating Cwf");


    this.username = 'admin';
    this.password = "";
    this.domain = "";
    this.passwordhash = 'd50c3180375c27927c22e42a379c3f67';


    // Open the socket
    this.socket_vscp = vscpws_openSocket('ws://104.236.235.81:8080');

    // Bind events
    this.socket_vscp.onmessage = this.onVSCPMessage.bind(this);
    this.socket_vscp.onopen = this.onVSCPOpen.bind(this);
    this.socket_vscp.onclose = this.onVSCPClose.bind(this);

}

vscpws_stateButton_mod.prototype.onVSCPMessage = function(msg)
{
    alert("onVSCPMessage");
    //alert(msg);
    //        console.log('rx');

            msgitems = msg.data.split(';');

               if ("+" == msgitems[0]){        // check for positive reply

                   alert('+ rx');

                   respone = msgitems[0].split(";");

                   if ( "AUTH0" == msgitems[1] ) {
                       alert('AUTH0');
                       var msg_1 = "C;AUTH;" + this.username + ";" + vscp_make_websocket_auth_hash( this.username, this.passwordhash, msgitems[2] );
                       this.socket_vscp.send(msg_1);
                   }
                   else if ( "AUTH1" == msgitems[1] ) {

                       alert('AUTH1');
                       // We are authenticated and ready to go to work
                       this.socket_vscp.send("C;" + "OPEN");

                       // Draw the state
                       //this.draw();

                       // Set filter
                       this.setFilter();
                   }
                   else if ( "OPEN" == msgitems[1] ) {
                       // Open confirmation => We are connected
                       this.bConnected = true;
                       // Draw the state
                       //this.draw();
                   }
                   else if ( "CLOSE" == msgitems[1] ) {
                       // Close confirmation => We are NOT connected
                       this.bConnected = false;
                   }
                   else {
                   }
               }
               else if ("-" == msgitems[0]){   // Check for negative reply
                   //if (vscpws_debug) console.log("Negative reply " + msg.data);
                   alert("-ve");
               }
               else if ("E" == msgitems[0]){
                   alert('event');
               }
}


vscpws_stateButton_mod.prototype.onVSCPOpen = function()
{
    alert("onVSCPOpen");
}



vscpws_stateButton_mod.prototype.onVSCPClose = function()
{
    alert("onVSCPClose");
}


/////////////////////////////////////////////////////////////////////////////
// vscpws_openSocket
//

function vscpws_openSocket(url) {

    socket = null;

    socket = new WebSocket( url );

    return socket;
}



function initApp()
{

    alert("initApp");

    var btn = new vscpws_stateButton_mod();

}


//function doc_onload(page_type)
function doc_onload()
{

    alert("doc_load");

    //add device ready handler
    document.addEventListener("deviceready", initApp, false);

    //initApp();

}
