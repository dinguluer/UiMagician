///////////////////////////////////////////////////////////////////////////////
// vscpws_stateButton_mod
//

function vscpws_stateButton_mod( username,           // Username for websocket serever
                                passwordhash,    // Password hash for websocket
                               url,             // url to VSCP websocket i/f
                               canvasName,    // Where it should be placed
                               bLocal,        // Local visual indication
                               btnType,       // Button type   
                               bNoState,      // True for nonstate button 
                               bDisabled,     // True to disable mouse clicks
                               customupsrc,   // Custom up image
                               customdownsrc, // Custom down image
                               variableName,        // Variable name to be monitored
                               interval             // Variable monitoring interval
                                   )
{
    //console.log("val " + Info_details.info_text[50].direction);
    //console.log("val_99 " +Info_details.info_text[99].direction);
    //return;

    // First set default parameter
    this.btnType = typeof btnType !== 'undefined' ? btnType : 0;
    this.bNoState = typeof bNoState !== 'undefined' ? bNoState : false;
    this.bLocal = typeof bLocal !== 'undefined' ? bLocal : false;
    this.bDisabled = typeof bDisabled !== 'undefined' ? bDisabled : false;
    this.customupsrc = 
        (typeof customupsrc !== 'undefined') ? customupsrc : "../lib/widgets/button/pressoff.png";
    this.customdownsrc = 
        (typeof customdownsrc !== 'undefined') ? customdownsrc : "../lib/widgets/button/presson.png";
    this.bOnce = false; // Monitor variable is checked on intervals

    // Websocket for VSCP daemon communication
    this.socket_vscp = null;
    
    // Flag for connected or unconnected state.
    this.bConnected = false;
    
    // Set the instance name for the control
    instanceName = "vscpws_" + canvasName;
    
    // move this to global scope
    eval(instanceName + " = this;");
        
    // remember instance name
    this.instanceName = instanceName;

    // Button intial state is off	
    this.bState = false;
    
    // Events to send to turn ON
    this.tansmitt_vscpclass_on = VSCP_CLASS1_CONTROL;     // Default class is CLASS1.CONTROL
    this.tansmitt_vscptype_on = VSCP_TYPE_CONTROL_TURNON; // Default type is TurnOn
    this.tansmitt_vscptype_on = new Array(0,0,0); // Index=0, zone=0, subzone=0
    this.tansmitt_guid_on = "-";        // Default GUID is GUID of interface.
    
    // Events to send to turn OFF 
    this.tansmitt_vscpclass_off = VSCP_CLASS1_CONTROL;      // Default class is CLASS1.CONTROL
    this.tansmitt_vscptype_off = VSCP_TYPE_CONTROL_TURNOFF; // Default type is TurnOff
    this.tansmitt_vscptype_on = new Array(0,0,0); // Index=0, zone=0, subzone=0
    this.tansmitt_guid_off = "-";       // Default GUID is GUID of interface.
    
    
    // Receive events to confirm Turn ON
    this.receive_vscpclass_on = VSCP_CLASS1_INFORMATION;   // Default class is CLASS1.INFORMATION
    this.receive_vscptype_on = VSCP_TYPE_INFORMATION_ON;   // Default type is On
    this.receive_data_on = new Array(-1,0,0); // zone=0, subzone=1
    this.receive_guid_on = "";          // Default GUID (empty is any).
    
    // Receive events to confirm turn OFF 
    this.receive_vscpclass_off = VSCP_CLASS1_INFORMATION;  // Default class is CLASS1.CONTROL
    this.receive_vscptype_off = VSCP_TYPE_INFORMATION_OFF; // Default type is Off
    this.receive_data_off = new Array(-1,0,0); // zone=0, subzone=1
    this.receive_guid_off = "";         // Default GUID (empty is any).

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

    this.canvas = document.getElementById(canvasName);

    // Preload up-image
    this.image_up = new Image();
    switch ( this.btnType ) { 
        
        case 1:
            this.image_up.src = "../lib/widgets/button/pressoffg.png";
            break;
            
        case 2:
            this.image_up.src = "../lib/widgets/button/pressoffo.png";
            break;
        
        case 3:
            this.image_up.src = "../lib/widgets/button/jbb1.png";
            break;
            
        case 4:
            this.image_up.src = "../lib/widgets/button/jbb2.png";
            break;
        
        case 5:
            this.image_up.src = "../lib/widgets/button/jbg.png";
            break;
            
        case 6:
            this.image_up.src = "../lib/widgets/button/jbo.png";
            break; 
        
        case 7:
            this.image_up.src = "../lib/widgets/button/jbr.png";
            break;
            
        case 8:
            this.image_up.src = "../lib/widgets/button/jbw.png";
            break;
        
        case 9:
            this.image_up.src = "../lib/widgets/button/jby.png";
            break;
            
        case 10:
            this.image_up.src = "../lib/widgets/button/jellyoff.png";
            break; 
        
        case 11:
            this.image_up.src = "../lib/widgets/button/dualpushgrey.png";
            break;
            
        case 12:
            this.image_up.src = "../lib/widgets/button/klunkmirror.png";
            break; 
        
        case 13:
            this.image_up.src = "../lib/widgets/button/klunk2mirror.png";
            break;
            
        case 14:
            this.image_up.src = "../lib/widgets/button/klunk4mirror.png";
            break; 
        
        case 15:
            this.image_up.src = "../lib/widgets/button/polywhiteH.png";
            break;
            
        case 16:
            this.image_up.src = "../lib/widgets/button/polywhiteV.png";
            break;    
            
        case 17:
            this.image_up.src = "../lib/widgets/button/pressoffS.png";
            break;
            
        case 18:
            this.image_up.src = "../lib/widgets/button/pressoffSb.png";
            break;
        
        case 19:
            this.image_up.src = "../lib/widgets/button/pressoffSg.png";
            break;
            
        case 20:
            this.image_up.src = "../lib/widgets/button/pressoffSy.png";
            break; 
        
        case 21:
            this.image_up.src = "../lib/widgets/button/pushin.png";
            break;
            
        case 22:
            this.image_up.src = "../lib/widgets/button/pushinw.png";
            break; 
        
        case 23:
            this.image_up.src = "../lib/widgets/button/rockerblackleft.png";
            break;
            
        case 24:
            this.image_up.src = "../lib/widgets/button/rockerblueleft.png";
            break; 
        
        case 25:
            this.image_up.src = "../lib/widgets/button/rockergreyleft.png";
            break;
            
        case 26:
            this.image_up.src = "../lib/widgets/button/rockerredleft.png";
            break;
        
        case 27:
            this.image_up.src = "../lib/widgets/button/rockersmooth.png";
            break;
            
        case 28:
            this.image_up.src = "../lib/widgets/button/rockersmoothBB.png";
            break;
        
        case 29:
            this.image_up.src = "../lib/widgets/button/rockersmoothBBL.png";
            break;
            
        case 30:
            this.image_up.src = "../lib/widgets/button/rockersmoothBC.png";
            break;
        
        case 31:
            this.image_up.src = "../lib/widgets/button/rockersmoothBG.png";
            break;
            
        case 32:
            this.image_up.src = "../lib/widgets/button/rockersmoothBGR.png";
            break;
        
        case 33:
            this.image_up.src = "../lib/widgets/button/rockersmoothBW.png";
            break;
            
        case 34:
            this.image_up.src = "../lib/widgets/button/rockersmoothBWR.png";
            break;  
        
        case 35:
            this.image_up.src = "../lib/widgets/button/rockerwhiteleft.png";
            break;
            
        case 36:
            this.image_up.src = "../lib/widgets/button/sidb.png";
            break;
        
        case 37:
            this.image_up.src = "../lib/widgets/button/sidb.png";
            break;
            
        case 38:
            this.image_up.src = "../lib/widgets/button/sidb.png";
            break; 
        
        case 39:
            this.image_up.src = "../lib/widgets/button/solinaOff.png";
            break;
            
        case 40:
            this.image_up.src = "../lib/widgets/button/led-orange-round-button-out.png";
            break;    
            
        case 41:
            this.image_up.src = "../lib/widgets/button/led_circle_grey.png";
            break; 
        
        case 42:
            this.image_up.src = "../lib/widgets/button/led_circle_grey.png";
            break;
            
        case 43:
            this.image_up.src = "../lib/widgets/button/led_circle_grey.png";
            break;
        
        case 44:
            this.image_up.src = "../lib/widgets/button/led_circle_grey.png";
            break;
            
        case 45:
            this.image_up.src = "../lib/widgets/button/led_circle_grey.png";
            break;
        
        case 46:
            this.image_up.src = "../lib/widgets/button/led_circle_grey.png";
            break;
            
        case 47:
            this.image_up.src = "../lib/widgets/button/led_circle_grey.png";
            break;
        
        case 48:
            this.image_up.src = "../lib/widgets/button/led_circle_grey.png";
            break;
            
        case 49:
            this.image_up.src = "../lib/widgets/button/led-red-off.png";
            break;
        
        case 50:
            this.image_up.src = "../lib/widgets/button/led_circle_green.png";
            break;
            
        case 51:
            this.image_up.src = "../lib/widgets/button/led-red-off.png";
            break;  
        
        case 52:
            this.image_up.src = "../lib/widgets/button/poweroff.png";
            break;
            
        case 53:
            this.image_up.src = "../lib/widgets/button/push-button-glossy-red.png";
            break;
        
        case 54:
            this.image_up.src = "../lib/widgets/button/push-button-glossy-red.png";
            break;
            
        case 55:
            this.image_up.src = "../lib/widgets/button/push-button-yellow-glossy.png";
            break;   
        
        case 56:
            this.image_up.src = "../lib/widgets/button/light_switch_off.png";
            break; 
            
        case 57:
            this.image_up.src = "../lib/widgets/button/sw1.png";
            break;  
        
        case 58:
            this.image_up.src = "../lib/widgets/button/sw5.png";
            break;
            
        case 59:
            this.image_up.src = "../lib/widgets/button/switch1.png";
            break;  
        
        case 60:
            this.image_up.src = "../lib/widgets/button/touchoy.png";
            break; 
        
        case 61:
            this.image_up.src = "../lib/widgets/button/touchow.png";
            break; 
            
        case 62:
            this.image_up.src = "../lib/widgets/button/touchoo.png";
            break; 
        
        case 63:
            this.image_up.src = "../lib/widgets/button/btn_led_rectangular_v_black.png";
            break;
            
        case 64:
            this.image_up.src = "../lib/widgets/button/btn-led_rounded_v_black.png";
            break; 
        
        case 65:
            this.image_up.src = "../lib/widgets/button/btn-led_rounded_v_grey.png";
            break;
            
        case 66:
            this.image_up.src = "../lib/widgets/button/btn_pressdown_off.png";
            break; 
        
        case 67:
            this.image_up.src = "../lib/widgets/button/btn_pressdown2_off.png";
            break;
            
        case 68:
            this.image_up.src = "../lib/widgets/button/red-rectangle-blank-button2-off.png";
            break;
            
        case 69:
            this.image_up.src = "../lib/widgets/button/run-push-button-off.png";
            break;
            
        case 70:
            this.image_up.src = "../lib/widgets/button/btn-silver-off.png";
            break;
            
        case 71:
            this.image_up.src = "../lib/widgets/button/start.png";
            break;    
            
        case 72:
            this.image_up.src = "../lib/widgets/button/switch-knob-off.png";
            break;  
            
        case 73:
            this.image_up.src = "../lib/widgets/button/SwtchOF1.png";
            break;
            
        case 74:
            this.image_up.src = "../lib/widgets/button/system-shut-down-off.png";
            break;  
            
        case 75:
            this.image_up.src = "../lib/widgets/button/brami_Square_Black_Crystal_Button.off.png";
            break; 
            
        case 76:
            this.image_up.src = "../lib/widgets/button/btncpgreen-off.png";
            break;
            
        case 77:
            this.image_up.src = "../lib/widgets/button/btncpmag-off.png";
            break; 
            
        case 78:
            this.image_up.src = "../lib/widgets/button/button-for-numbers-off.png";
            break;
            
        case 79:
            this.image_up.src = "../lib/widgets/button/button-green-off.png";
            break; 
            
        case 80:
            this.image_up.src = "../lib/widgets/button/button-off.png";
            break;  
            
        case 81:
            this.image_up.src = "../lib/widgets/button/button-power-off.png";
            break; 
            
        case 82:
            this.image_up.src = "../lib/widgets/button/btn-grey-rounded-off.png";
            break; 
            
        case 83:
            this.image_up.src = "../lib/widgets/button/btn-grey-off.png";
            break; 
            
        case 84:
            this.image_up.src = "../lib/widgets/button/interruptor-off.png";
            break;             
            
        case 85:
            this.image_up.src = "../lib/widgets/button/knife_switch_off.png";
            break; 
            
        case 86:
            this.image_up.src = "../lib/widgets/button/off-button.png";
            break;  
            
        case 87:
            this.image_up.src = "../lib/widgets/button/btn-modern-off.png";
            break; 
            
        case 88:
            this.image_up.src = "../lib/widgets/button/btn-oldstyle-off.png";
            break;  
            
        case 89:
            this.image_up.src = "../lib/widgets/button/orange-button-off.png";
            break;       
        
        case 90:
            this.image_up.src = "../lib/widgets/light/lightbulb1_off.png";
            break; 
        
        case 91:
            this.image_up.src = "../lib/widgets/light/light_green.gif";
            break;
            
        case 92:
            this.image_up.src = "../lib/widgets/lightbulb/semi-matte-light-bulb-unlit-th.png";
            break;
        
        case 93:
            this.image_up.src = "../lib/widgets/lightbulb/lightbulb-white-th.png";
            break;

        case 94:
            this.image_up.src = "../lib/widgets/lightbulb/light-bulb-icon.jpg";
            break;
            
        case -1:    // Custom
            this.image_up.src = this.customupsrc;
            break;    
            
        default:
            this.image_up.src = "../lib/widgets/button/pressoff.png";
            break;
    };

    // Preload down-image
    this.image_down = new Image();
    switch ( this.btnType ) {  
        case 1:
            this.image_down.src = "../lib/widgets/button/pressong.png";
            break;
            
        case 2:
            this.image_down.src = "../lib/widgets/button/pressono.png";
            break;
            
        case 3:
            this.image_down.src = "../lib/widgets/button/jbb1o.png";
            break;
            
        case 4:
            this.image_down.src = "../lib/widgets/button/jbb2o.png";
            break;
        
        case 5:
            this.image_down.src = "../lib/widgets/button/jbgo.png";
            break;
            
        case 6:
            this.image_down.src = "../lib/widgets/button/jboo.png";
            break; 
        
        case 7:
            this.image_down.src = "../lib/widgets/button/jbro.png";
            break;
            
        case 8:
            this.image_down.src = "../lib/widgets/button/jbwo.png";
            break;  
        
        case 9:
            this.image_down.src = "../lib/widgets/button/jbyo.png";
            break;
            
        case 10:
            this.image_down.src = "../lib/widgets/button/jellyon.png";
            break;  
        
        case 11:
            this.image_down.src = "../lib/widgets/button/dualpushgreymirror.png";
            break;
            
        case 12:
            this.image_down.src = "../lib/widgets/button/klunk.png";
            break; 
        
        case 13:
            this.image_down.src = "../lib/widgets/button/klunk2.png";
            break;
            
        case 14:
            this.image_down.src = "../lib/widgets/button/klunk4.png";
            break; 
        
        case 15:
            this.image_down.src = "../lib/widgets/button/polyblue.png";
            break;
            
        case 16:
            this.image_down.src = "../lib/widgets/button/polyredV.png";
            break;    
            
        case 17:
            this.image_down.src = "../lib/widgets/button/pressonS.png";
            break;
            
        case 18:
            this.image_down.src = "../lib/widgets/button/pressonSb.png";
            break;
        
        case 19:
            this.image_down.src = "../lib/widgets/button/pressonSg.png";
            break;
            
        case 20:
            this.image_down.src = "../lib/widgets/button/pressonSy.png";
            break; 
        
        case 21:
            this.image_down.src = "../lib/widgets/button/pushout.png";
            break;
            
        case 22:
            this.image_down.src = "../lib/widgets/button/pushoutw.png";
            break;  
        
        case 23:
            this.image_down.src = "../lib/widgets/button/rockerblack.png";
            break;
            
        case 24:
            this.image_down.src = "../lib/widgets/button/rockerblue.png";
            break; 
        
        case 25:
            this.image_down.src = "../lib/widgets/button/rockergrey.png";
            break;
            
        case 26:
            this.image_down.src = "../lib/widgets/button/rockerred.png";
            break; 
        
        case 27:
            this.image_down.src = "../lib/widgets/button/rockersmoothd.png";
            break;
            
        case 28:
            this.image_down.src = "../lib/widgets/button/rockersmoothBBd.png";
            break;
        
        case 29:
            this.image_down.src = "../lib/widgets/button/rockersmoothBBLd.png";
            break;
            
        case 30:
            this.image_down.src = "../lib/widgets/button/rockersmoothBCd.png";
            break;
        
        case 31:
            this.image_down.src = "../lib/widgets/button/rockersmoothBGd.png";
            break;
            
        case 32:
            this.image_down.src = "../lib/widgets/button/rockersmoothBGRd.png";
            break;
        
        case 33:
            this.image_down.src = "../lib/widgets/button/rockersmoothBWd.png";
            break;
            
        case 34:
            this.image_down.src = "../lib/widgets/button/rockersmoothBWRd.png";
            break; 
        
        case 35:
            this.image_down.src = "../lib/widgets/button/rockerwhite.png";
            break;
            
        case 36:
            this.image_down.src = "../lib/widgets/button/sidbon.png";
            break;
        
        case 37:
            this.image_down.src = "../lib/widgets/button/sidbongreen.png";
            break;
            
        case 38:
            this.image_down.src = "../lib/widgets/button/sidbonblue.png";
            break;  
        
        case 39:
            this.image_down.src = "../lib/widgets/button/solinaOn.png";
            break;
            
        case 40:
            this.image_down.src = "../lib/widgets/button/led-orange-round-button-in.png";
            break;
            
        case 41:
            this.image_down.src = "../lib/widgets/button/led_circle_red.png";
            break; 
        
        case 42:
            this.image_down.src = "../lib/widgets/button/led_circle_yellow_.png";
            break;
            
        case 43:
            this.image_down.src = "../lib/widgets/button/led-green.png";
            break;
        
        case 44:
            this.image_down.src = "../lib/widgets/button/led-green-button2.png";
            break;
            
        case 45:
            this.image_down.src = "../lib/widgets/button/led_circle_green.png";
            break;
        
        case 46:
            this.image_down.src = "../lib/widgets/button/led_circle_orange.png";
            break;
            
        case 47:
            this.image_down.src = "../lib/widgets/button/led_circle_purple.png";
            break;
        
        case 48:
            this.image_down.src = "../lib/widgets/button/led_circle_blue.png";
            break;
            
        case 49:
            this.image_down.src = "../lib/widgets/button/led-red-on.png";
            break;
        
        case 50:
            this.image_down.src = "../lib/widgets/button/led-green.png";
            break;
            
        case 51:
            this.image_down.src = "../lib/widgets/button/led_circle_green.png";
            break;
            
        case 52:
            this.image_down.src = "../lib/widgets/button/poweron.png";
            break; 
        
        case 53:
            this.image_down.src = "../lib/widgets/button/push-button-light-blue.png";
            break;
            
        case 54:
            this.image_down.src = "../lib/widgets/button/push-button-yellow-glossy.png";
            break;
        
        case 55:
            this.image_down.src = "../lib/widgets/button/push-button-light-blue.png";
            break;
            
        case 56:
            this.image_down.src = "../lib/widgets/button/light_switch_on.png";
            break;  
        
        case 57:
            this.image_down.src = "../lib/widgets/button/sw2.png";
            break; 
            
        case 58:
            this.image_down.src = "../lib/widgets/button/sw3.png";
            break; 
        
        case 59:
            this.image_down.src = "../lib/widgets/button/switch3.png";
            break; 
            
        case 60:
            this.image_down.src = "../lib/widgets/button/touchy.png";
            break;   
        
        case 61:
            this.image_down.src = "../lib/widgets/button/touchw.png";
            break;
            
        case 62:
            this.image_down.src = "../lib/widgets/button/toucho.png";
            break;
        
        case 63:
            this.image_down.src = "../lib/widgets/button/btn_led_rectangular_vh_black.png";
            break; 
            
        case 64:
            this.image_down.src = "../lib/widgets/button/btn-led_rounded_vh_black.png";
            break;  
        
        case 65:
            this.image_down.src = "../lib/widgets/button/btn-led_rounded_vh_grey.png";
            break; 
            
        case 66:
            this.image_down.src = "../lib/widgets/button/btn_pressdown_on.png";
            break; 
        
        case 67:
            this.image_down.src = "../lib/widgets/button/btn_pressdown2_on.png";
            break;
            
        case 68:
            this.image_down.src = "../lib/widgets/button/red-rectangle-blank-button-on.png";
            break;
            
        case 69:
            this.image_down.src = "../lib/widgets/button/run-push-button-on.png";
            break;
            
        case 70:
            this.image_down.src = "../lib/widgets/button/btn-silver-on.png";
            break;
            
        case 71:
            this.image_down.src = "../lib/widgets/button/stop.png";
            break;
            
        case 72:
            this.image_down.src = "../lib/widgets/button/switch-knob-on.png";
            break;
            
        case 73:
            this.image_down.src = "../lib/widgets/button/SwtchON1.png";
            break; 
               
        case 74:
            this.image_down.src = "../lib/widgets/button/system-shut-down-on.png";
            break; 
            
        case 75:
            this.image_down.src = "../lib/widgets/button/brami_Square_Black_Crystal_Button.on.png";
            break; 
            
        case 76:
            this.image_down.src = "../lib/widgets/button/btncpgreen-on.png";
            break;
            
        case 77:
            this.image_down.src = "../lib/widgets/button/btncpmag-on.png";
            break;  
            
        case 78:
            this.image_down.src = "../lib/widgets/button/button-for-numbers-on.png";
            break;
            
        case 79:
            this.image_down.src = "../lib/widgets/button/button-green-on.png";
            break; 
            
        case 80:
            this.image_down.src = "../lib/widgets/button/button-on.png";
            break; 
            
        case 81:
            this.image_down.src = "../lib/widgets/button/button-power-on.png";
            break; 
            
        case 82:
            this.image_down.src = "../lib/widgets/button/btn-grey-rounded-on.png";
            break; 
            
        case 83:
            this.image_down.src = "../lib/widgets/button/btn-grey-on.png";
            break;     
            
        case 84:
            this.image_down.src = "../lib/widgets/button/interruptor-on.png";
            break;
            
        case 85:
            this.image_down.src = "../lib/widgets/button/knife_switch_on.png";
            break;  
            
        case 86:
            this.image_down.src = "../lib/widgets/button/on-button.png";
            break; 
            
        case 87:
            this.image_down.src = "../lib/widgets/button/btn-modern-on.png";
            break;  
            
        case 88:
            this.image_down.src = "../lib/widgets/button/btn-oldstyle-on.png";
            break;
            
        case 89:
            this.image_down.src = "../lib/widgets/button/orange-button-on.png";
            break; 
        
        case 90:
            this.image_down.src = "../lib/widgets/light/lightbulb1_on.png";
            break;
            
        case 91:
            this.image_down.src = "../lib/widgets/light/light_red.gif";
            break; 
        
        case 92:
            this.image_down.src = "../lib/widgets/lightbulb/semi-matte-light-bulb-lit-th.png";
            break; 
            
        case 93:
            this.image_down.src = "../lib/widgets/lightbulb/lightbulb-th.png";
            break;     

        case 94:
            this.image_down.src = "../lib/widgets/lightbulb/glossy-light-bulb.jpg";
            break;

        case -1:    // Custom
            this.image_down.src = this.customdownsrc;
            break;    
        
        default:
            this.image_down.src = "../lib/widgets/button/presson.png";
            break;
    };
    
    
    // Open the socket
    this.socket_vscp = vscpws_openSocket(url);
    
    if (null==this.socket_vscp ) alert("Could not open websocket to VSCP server!");

    // Bind events	
    this.socket_vscp.onmessage = this.onVSCPMessage.bind(this);	
    this.socket_vscp.onopen = this.onVSCPOpen.bind(this);
    this.socket_vscp.onclose = this.onVSCPClose.bind(this);
    
    //this.canvas.onmouseover = this.onMouseOver.bind(this);
    //this.canvas.onmouseout = this.onMouseOut.bind(this);
    this.canvas.onmousedown = this.onMouseDown.bind(this);
    this.canvas.onmouseup = this.onMouseUp.bind(this);
    
    //this.image_up.onload = this.onImageLoad.bind(this);


    // set event send by gui value to false
    this.eventSend = 0;

    // Set default events
    this.setOnTransmittEvent();
    this.setOffTransmittEvent();

    //set device details
    this.setDeviceDetails();
   
    //retreive instance name
    this.getInstanceName = function() {
       return this.instanceName;
    }

    //default property
    this.toString = function() {
       return this.getInstanceName();
    }
    
};


//-----------------------------------------------------------------------------
// setDeviceDetails
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.setDeviceDetails = function(device,
                                                                room,
                                                                 floor)
{

   // floor = typeof floor !== 'undefined' ? floor : "";
    room = typeof room !== 'undefined' ? room : "";
    device = typeof device !== 'undefined' ? device : "";

    this.floorName = floor;
    this.roomName = room;
    this.deviceName = device;

    if(typeof floor !== 'undefined')
    {
      this.infoMessageOn = floor + " : " + room + " : " + device + " : ON" ;
      this.infoMessageOff = floor + " : " + room + " : " + device + " : OFF" ;
    }
    else  // i.e for single floor house
    {
      this.infoMessageOn = room + " : " + device + " : ON" ;
      this.infoMessageOff = room + " : " + device + " : OFF" ;

    }
};


//-----------------------------------------------------------------------------
// setOnTransmittEvent
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.setOnTransmittEvent = function(vscpclass,
                                                                vscptype,
                                                                data,        
                                                                guid ) 
{
    var dataArray = new Array(0,0,0); // index=0, zone=0, subzone=0
    
    // First set default parameter
    vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : 30;
    vscptype = typeof vscptype !== 'undefined' ? vscptype : 5;
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

vscpws_stateButton_mod.prototype.setOnTransmittZone = function(index,zone,subzone)
{
    this.tansmitt_data_on[0] = typeof index !== 'undefined' ? index : 0;
    this.tansmitt_data_on[1] = typeof zone !== 'undefined' ? zone : 0;
    this.tansmitt_data_on[2] = typeof subzone !== 'undefined' ? subzone : 0;
};

//-----------------------------------------------------------------------------
// setOffTransmittEvent
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.setOffTransmittEvent = function(vscpclass,
                                                                vscptype,
                                                                data,        
                                                                guid) 
{
    var dataArray = new Array(0,0,0); // index=0, zone=0, subzone=0
    
    // First set default parameter
    vscpclass = typeof vscpclass !== 'undefined' ? vscpclass : 30;
    vscptype = typeof vscptype !== 'undefined' ? vscptype : 6;
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

vscpws_stateButton_mod.prototype.setOffTransmittZone = function(index,zone,subzone)
{
    this.tansmitt_data_off[0] = typeof index !== 'undefined' ? index : 0;
    this.tansmitt_data_off[1] = typeof zone !== 'undefined' ? zone : 0;
    this.tansmitt_data_off[2] = typeof subzone !== 'undefined' ? subzone : 0;
};

//-----------------------------------------------------------------------------
// setOnReceiveEvent
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.setOnReceiveEvent = function(vscpclass,
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

vscpws_stateButton_mod.prototype.setOnReceiveZone = function(index,zone,subzone)
{
    this.receive_data_on[0] = typeof index !== 'undefined' ? index : 0;
    this.receive_data_on[1] = typeof zone !== 'undefined' ? zone : 0;
    this.receive_data_on[2] = typeof subzone !== 'undefined' ? subzone : 0;
};

//-----------------------------------------------------------------------------
// setOffReceiveEvent
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.setOffReceiveEvent = function(vscpclass,
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
    
    this.receive_vscpclass_off = vscpclass;
    this.receive_vscptype_off = vscptype;
    this.receive_guid_off = guid;
    
    // Set filter
    this.setFilter();
};

//-----------------------------------------------------------------------------
// setOffReceiveZone
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.setOffReceiveZone = function(index,zone,subzone)
{
    this.receive_data_off[0] = typeof index !== 'undefined' ? index : 0;
    this.receive_data_off[1] = typeof zone !== 'undefined' ? zone : 0;
    this.receive_data_off[2] = typeof subzone !== 'undefined' ? subzone : 0;
};


//-----------------------------------------------------------------------------
// setFilter
//-----------------------------------------------------------------------------
vscpws_stateButton_mod.prototype.setFilter = function()
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
// setMonitorVariable
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.setMonitorVariable = function(name,interval, bOnce)
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

vscpws_stateButton_mod.prototype.setMonitorVariableName = function(name)
{
    this.monitorVariableName = name;
};

//-----------------------------------------------------------------------------
// setValue
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.setValue = function(value, bUpdate)
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
                    cmd += this.tansmitt_data_on[i].toString() ;//+ ",";
                    if (i<this.tansmitt_data_on.length-1) cmd += ",";   // No comma for last
            }
            
            if (vscpws_debug) console.log(cmd);
            this.socket_vscp.send(cmd);
            
            if ("" != this.monitorVariableName) {
                //cmd = "C;WRITEVAR;" + this.monitorVariableName + ";true";
                //this.socket_vscp.send(cmd);
            }
        }
        
        if (this.bLocal) this.bState = true;
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
        
        if (this.bLocal) this.bState = false;
    }

};

//-----------------------------------------------------------------------------
// onImageLoad
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.onImageLoad = function(me)
{

};

//-----------------------------------------------------------------------------
// onMouseOver
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.onMouseOver = function()
{
   //if (vscpws_debug) console.log("Over");
};

//-----------------------------------------------------------------------------
// onMouseOut
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.onMouseOut = function()
{
   //if (vscpws_debug) console.log("Out");
};

//-----------------------------------------------------------------------------
// onMouseDown
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.onMouseDown = function()
{
    // If interaction clicks are disabled don't do anything.
    if (this.bDisabled) return;
    
    if (this.bConnected) {
        if (this.bNoState ) {

            this.setValue(true);
        }
    }
};

//-----------------------------------------------------------------------------
// onMouseUp
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.onMouseUp = function()
{
    // If interaction clicks are disabled don't do anything.
    if (this.bDisabled) return;
    
    if (this.bConnected && !this.bNoState ) {
        if ( this.bState ) {
            this.eventSend = 1;
            this.setValue(false);
        }
        else {
            this.eventSend = 1;
            this.setValue(true);
        }
    }
    else if (this.bConnected && this.bNoState ) {
        this.eventSend = 1;
        this.setValue(false);
    }
};

//-----------------------------------------------------------------------------
// onVSCPOpen
//-----------------------------------------------------------------------------

vscpws_stateButton_mod.prototype.onVSCPOpen = function()
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

vscpws_stateButton_mod.prototype.onVSCPClose = function()
{
    if (vscpws_debug) console.log('Close VSCP websocket');
    this.bConnected = false;
};


//-----------------------------------------------------------------------------
// onVSCPMessage
//-----------------------------------------------------------------------------
// handle VSCP socketcan incoming message/event.	
vscpws_stateButton_mod.prototype.onVSCPMessage = function(msg)
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
        else if ("READVAR" == msgitems[1] && (2 == msgitems[3])){
            if ( ("true" == msgitems[4].toLowerCase()) && 
                    (false == this.bState )) {
                // We have a match for ON
                this.bState = true;
                this.canvas.src = this.image_down.src;
            }
            else if ( ("false" == msgitems[4].toLowerCase()) && 
                    (true == this.bState )) {
                // We have a match for ON
                this.bState = false;
                this.canvas.src = this.image_up.src;
            }
            else{
                //do nothing
            }

           //alert("1")
           //alert(this.bOnce);
            if ( this.bOnce && ( typeof this.monitorInterval !== 'undefined' ) ) {
                clearInterval( this.variableTimer );
           //alert("2")
                this.bOnce = false;
            }

           //alert("3")
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
            // Check data if any
            if (this.receive_data_on.length ) {
                for (i=0;i<this.receive_data_on.length;i++) {
                    // Skip a don't care
                    if ( -1 == this.receive_data_on[i] ) continue;
                    if ( (vscpdata[i] == undefined) || 
                           (vscpdata[i] != this.receive_data_on[i]) ) return;
                }
            }

            // Check GUID
            if ( ("" != this.receive_guid_on) && 
                    this.receive_guid_on.toLowerCase() != vscpguid.toLowerCase()) return;
            
            // We have a match for ON
            this.bState = true;

            //this.canvas.src = "http://www.psdgraphics.com/file/glossy-light-bulb.jpg";
            this.canvas.src = this.image_down.src;

            // set global data structure
            setInfoData(this.eventSend,this.infoMessageOn);
            this.eventSend = 0;
            
            if (vscpws_debug) console.log("****** Turned ON ******");
        }
        
        // Check if this is a possible OFF-event
        if (vscpclass == this.receive_vscpclass_off && 
                vscptype == this.receive_vscptype_off ) {
            // Check data if any
            if (this.receive_data_off.length ) {
            //alert("length = " + this.receive_data_off.length);
                for (i=0;i<this.receive_data_off.length;i++) {
                    // Skip a don't care
                    if ( -1 == this.receive_data_off[i] ) continue;
                    if ( (vscpdata[i] == undefined) || 
                           (vscpdata[i] != this.receive_data_off[i]) ) return;

                }
            }
                 
            // Check GUID
            if (("" != this.receive_guid_off) && 
                    this.receive_guid_off.toLowerCase() != guid.toLowerCase()) return;
                      
            // We have a match for OFF
            this.bState = false;

            //this.canvas.src = "http://www.psdgraphics.com/file/light-bulb-icon.jpg";
            this.canvas.src = this.image_up.src;

            // set global data structure
            setInfoData(this.eventSend,this.infoMessageOff);
            this.eventSend = 0;

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
vscpws_stateButton_mod.prototype.openConnection = function()
{
	this.socket_vscp.send("C;" + "open");
};
    
//-----------------------------------------------------------------------------
// closeConnection
//-----------------------------------------------------------------------------    
vscpws_stateButton_mod.prototype.closeConnection = function()
{
	this.socket_vscp.send("C;" + "close");
};

//-----------------------------------------------------------------------------
// time4VariableRead
//-----------------------------------------------------------------------------    
vscpws_stateButton_mod.prototype.time4VariableRead = function(m,s)
{
    var cmd;
    if (vscpws_debug) console.log("time4VariableRead");
    cmd = "C;READVAR;" + m;
	s.send(cmd);
};
