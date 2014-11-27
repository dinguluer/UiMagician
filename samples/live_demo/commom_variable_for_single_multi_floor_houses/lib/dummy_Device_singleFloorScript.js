/*
  Author = Dinesh Guleria
  VSCP Developer
  Date : 27-3-2014
*/

var WebSocket = require('C:\\Program Files\\nodejs\\node_modules\\ws');

var fs = require('fs');


// file is included here:
eval(fs.readFileSync('jquery.min.js')+'');
// file is included here:
eval(fs.readFileSync('wz_jsgraphics.js')+'');
// file is included here:
eval(fs.readFileSync('md5.js')+'');
// file is included here:
eval(fs.readFileSync('infoInit.js')+'');
// file is included here:
eval(fs.readFileSync('vscpwslib.min.dummy.js')+'');
// file is included here:
eval(fs.readFileSync('dummy_Device_vscpStateButton_mod.js')+'');
// file is included here:
eval(fs.readFileSync('dummy_Device_vscpSimpleText_mod.js')+'');
// file is included here:
eval(fs.readFileSync('dummy_Device_vscpslider.js')+'');
// file is included here:
eval(fs.readFileSync('dummy_Device_vscpVariableButton.js')+'');
// file is included here:
//eval(fs.readFileSync('dummy_Device_FloorCfg.js')+'');
// file is included here:
eval(fs.readFileSync('dummy_Device_SocketCfg.js')+'');

var tt = new create_dummy_device();


function pausecomp(ms) {
ms += new Date().getTime();
while (new Date() < ms){}
}

function create_dummy_device()
{


   // Initialise the info data structure
   //info_init();

   // Create the Socket
   create_device_socket(Single_Floor_Device_Array);
   //create socket for slider
  create_slider_socket(Single_Floor_Variable_Slider_Device_Array);
   //create socket for variable button
  create_Variable_Button_socket(Single_Floor_Variable_Switch_Device_Array);
   // Create the Socket for Measurement  devices
  create_measurement_device_socket(Single_Floor_Sensor_Device_Array);


   //call dummy function
   setInterval(function(){}, 10000);
}

function create_measurement_device_socket( Device_Array )
{
    var bOnce = true;

    //for (var i = 0; i < 1; i++)
    for (var i = 0; i < Device_Array.length; i++)
    {

        // *********** create dummy Device_Array  *************************** //
        var device_btn = new dummy_Device_vscpws_simpleTextEvent_mod( Device_Array[i].userName,
                                             Device_Array[i].password,
                                             Device_Array[i].url,           // url to VSCP websocket i/f
                                             Device_Array[i].vscpclass,       // Event class 10/60/65/15
                                             Device_Array[i].vscptype,        // Evet type
                                             Device_Array[i].codingIndex,     // Sensor coding index
                                             Device_Array[i].guid            // GUID we are interested in
                                                                      );

          device_btn.setExtraParameters(Device_Array[i].sensorIndex, Device_Array[i].sensorZone, Device_Array[i].sensorSubzone);

        //setTimeout(function(){}, 1000);
        pausecomp(20);
    }

}

function create_device_socket( Device_Array )
{
    var bOnce = true;

    //for (var i = 0; i < 1; i++)
    for (var i = 0; i < Device_Array.length; i++)
    {
        // *********** create dummy Device_Array  ***************************//

        var device_btn = new dummy_Device_vscpStateButton_mod( Device_Array[i].userName,
                                             Device_Array[i].password,
                                      Device_Array[i].url);


        //Reception parameters are opposite to button TX parameters
        device_btn.setOnReceiveEvent(Device_Array[i].onTxEventvscpclass,Device_Array[i].onTxEventvscptype);
        device_btn.setOnReceiveZone(Device_Array[i].onTxEventindex,Device_Array[i].onTxEventzone, Device_Array[i].onTxEventsubzone);
        device_btn.setOffReceiveEvent(Device_Array[i].offTxEventvscpclass,Device_Array[i].offTxEventvscptype);
        device_btn.setOffReceiveZone(Device_Array[i].offTxEventindex,Device_Array[i].offTxEventzone, Device_Array[i].offTxEventsubzone);

        //Transmission parameters are opposite to button RX parameters
        device_btn.setOnTransmittEvent(Device_Array[i].onRxEventvscpclass,Device_Array[i].onRxEventvscptype,Device_Array[i].onRxEventdata,Device_Array[i].onRxEventguid);
        device_btn.setOnTransmittZone(Device_Array[i].onRxEventindex,Device_Array[i].onRxEventzone, Device_Array[i].onRxEventsubzone);
        device_btn.setOffTransmittEvent(Device_Array[i].offRxEventvscpclass,Device_Array[i].offRxEventvscptype,Device_Array[i].offRxEventdata,Device_Array[i].offRxEventguid);
        device_btn.setOffTransmittZone(Device_Array[i].offRxEventindex,Device_Array[i].offRxEventzone, Device_Array[i].offRxEventsubzone);

        //setTimeout(function(){}, 1000);
        pausecomp(20);
    }

}

function create_slider_socket( Slider_Array )
{
    var bOnce = true;

    for (var i = 0; i < Slider_Array.length; i++)
    {

        // *********** create dummy Device_Array  ***************************//

        var device_btn = new dummy_Device_vscpws_slider( Slider_Array[i].userName,
                                             Slider_Array[i].password,
                                      Slider_Array[i].url);

        device_btn.setReceiveEvent(Slider_Array[i].TxEventvscpclass,Slider_Array[i].TxEventvscptype);
        device_btn.setReceiveZone(Slider_Array[i].TxEventindex,Slider_Array[i].TxEventzone, Slider_Array[i].TxEventsubzone);

        device_btn.setTransmittEvent(Slider_Array[i].RxEventvscpclass,Slider_Array[i].RxEventvscptype,Slider_Array[i].RxEventdata,Slider_Array[i].RxEventguid);
        device_btn.setTransmittZone(Slider_Array[i].RxEventindex,Slider_Array[i].RxEventzone, Slider_Array[i].RxEventsubzone);


        //setTimeout(function(){}, 1000);
        pausecomp(20);
    }



}

//create socket for variable button
function create_Variable_Button_socket( Variable_Button_Array )
{
    var bOnce = true;

    for (var i = 0; i < Variable_Button_Array.length; i++)
    {

        // *********** create dummy Device_Array  ***************************//

        var device_btn = new dummy_Device_vscpws_variableButton( Variable_Button_Array[i].userName,
                                             Variable_Button_Array[i].password,
                                      Variable_Button_Array[i].url);


        device_btn.setReceiveEvent(Variable_Button_Array[i].TxEventvscpclass,Variable_Button_Array[i].TxEventvscptype);
        device_btn.setReceiveZone(Variable_Button_Array[i].TxEventzone, Variable_Button_Array[i].TxEventsubzone);

        device_btn.setTransmittEvent(Variable_Button_Array[i].RxEventvscpclass,Variable_Button_Array[i].onRxEventvscptype,Variable_Button_Array[i].RxEventdata,Variable_Button_Array[i].RxEventguid);
        device_btn.setTransmittZone(Variable_Button_Array[i].RxEventzone, Variable_Button_Array[i].RxEventsubzone);


        //setTimeout(function(){}, 1000);
        pausecomp(20);
    }

}

function floor_area_visible_onload()
{

  $(floor_area_id).each(function(index, element) {
        if(element != floor_area_id[0] )
        {
          $("." + element).hide();

        }
        else
        {
          $("." + element).show();
          //$("." + element).css('background-color', 'blue');
        }
    });



}

function select_scroll_area_image()
{
  //Show area on the scrollable div
  // set img src
  $(div_class_scrollable_Image).each(function(index, element) {
        if(element != div_class_scrollable_Image[0] )
        {
          //alert("hellooooo");
          $("#" +element).attr('src', '../lib/widgets/room/room_unselected.png');

        }
        else
        {
          //alert("he");
          $("#" + element).attr('src', '../lib/widgets/room/room_selected.jpg');
        }

    });

  // Change the color of horizontal line
  $(div_class_scrollable_Hr).each(function(index, element) {
        if(element != div_class_scrollable_Hr[0] )
        {
          //alert("hellooooo");
          $("#" +element).css('background-color', '#DDDFED');

        }
        else
        {
          //alert("he");
          $("#" + element).css('background-color', '#00FF00');
        }

    });

}

function Central_widget_visible_onload()
{

  // hide group images
  hide_Central_widget_group_images();
  // hide group txt
  hide_Central_widget_group_txt();

  $(central_Area_widgets_id).each(function(index, element) {
        if(element != central_Area_widgets_id[0] )
        {
          $("." + element).hide();

        }
        else
        {
            $("." + element).show();
        }
    });

    //element = 'kkk';
    //$("." + element).show();

    //element = 'group_Txt_ID';
    //$("." + element).hide();
}

function show_area_single(parameter_image_array, parameter_image, parameter_Hr_array, parameter_Hr, parameter_central)
{

  //Show area on the scrollable div
  // set img src
  $(parameter_image_array).each(function(index, element) {
        if(element != parameter_image )
        {
          //alert("hellooooo");
          $("#" +element).attr('src', '../lib/widgets/room/room_unselected.png');

        }
        else
        {
          //alert("he");
          $("#" + element).attr('src', '../lib/widgets/room/room_selected.jpg');
        }

    });

  // Change the color of horizontal line
  $(parameter_Hr_array).each(function(index, element) {
        if(element != parameter_Hr )
        {
          //alert("hellooooo");
          //alert(parameter_Hr);
          $("#" +element).css('background-color', '#DDDFED');

        }
        else
        {
          //alert("he");
          $("#" + element).css('background-color', '#00FF00');
        }

    });

    // hide group images
    hide_Central_widget_group_images();
    // hide group txt
    hide_Central_widget_group_txt();
   // Show area on the central div
   show_Central_widget_single(parameter_central);


}


function show_info(parameter_image_array, parameter_Hr_array, parameter_Hr, parameter_central)
{

    // set img src
    $(parameter_image_array).each(function(index, element) {
            //alert("hellooooo");
            $("#" +element).attr('src', '../lib/widgets/room/room_unselected.png');

      });

    // Change the color of horizontal line
    $(parameter_Hr_array).each(function(index, element) {
          if(element != parameter_Hr )
          {
            //alert("hellooooo");
            //alert(parameter_Hr);
            $("#" +element).css('background-color', '#DDDFED');

          }
          else
          {
            //alert("he");
            $("#" + element).css('background-color', '#00FF00');
          }

      });

    // hide group images
    hide_Central_widget_group_images();
    // hide group txt
    hide_Central_widget_group_txt();

    // Show area on the central div
    show_Central_widget_single(parameter_central);


    // change info div content
    infoDisplay(parameter_central);  //------------->

    //hide unused info
    infoShow();
}

function show_area_group(parameter_image_array, parameter_image, parameter_Hr_array, parameter_Hr , group_image_class, group_txt_class)
{

    //alert("++");
  //Show area on the scrollable div
  // set img src
  $(parameter_image_array).each(function(index, element) {
        if(element != parameter_image )
        {
          //alert("hellooooo");
          $("#" +element).attr('src', '../lib/widgets/room/room_unselected.png');

        }
        else
        {
          //alert("he");
          $("#" + element).attr('src', '../lib/widgets/room/room_selected.jpg');
        }

    });

  // Change the color of horizontal line
  $(parameter_Hr_array).each(function(index, element) {
        if(element != parameter_Hr )
        {
          //alert("hellooooo");
          $("#" +element).css('background-color', '#DDDFED');

        }
        else
        {
          //alert("he");
          $("#" + element).css('background-color', '#00FF00');
        }

    });

    // hide central widget area
    hide_central_area();

    // show group image
    show_Central_widget_group_images(group_image_class);

    // show group txt
    show_Central_widget_group_txt(group_txt_class);

   // Show area on the central div
   //show_Central_widget_single(parameter_central);


}

// hide central widget area
function hide_central_area()
{
    // hide central widget area
    $(central_Area_widgets_id).each(function(index, element) {

            $("." + element).hide();
      });
}

// show group images
function show_Central_widget_group_images(parameter)
{


  // Show elements in central area
  $(central_Area_Group_Image_class).each(function(index, element) {
        if(element != parameter )
        {
          $("." + element).hide();

        }
        else
        {
          $("." + element).show();
        }

    });


}

// show group txt
function show_Central_widget_group_txt(parameter)
{


  // Show elements in central area
  $(central_Area_Group_txt_class).each(function(index, element) {
        if(element != parameter )
        {
          $("." + element).hide();

        }
        else
        {
          $("." + element).show();
        }

    });

}

// hide group images
function hide_Central_widget_group_images()
{


  // hide elements in group area
  $(central_Area_Group_Image_class).each(function(index, element) {
          $("." + element).hide();
    });


}

// hide group txt
function hide_Central_widget_group_txt()
{


  // hide elements in group area
  $(central_Area_Group_txt_class).each(function(index, element) {
          $("." + element).hide();
    });

}

function show_area(parameter, parameter_image_array, parameter_image, parameter_Hr_array, parameter_Hr, parameter_central, parameter_Menu_array, parmeter_menu_image)
{

  //Show area on the scrollable div
  // set img src
  $(parameter_image_array).each(function(index, element) {
        if(element != parameter_image )
        {
          //alert("hellooooo");
          $("#" +element).attr('src', '../lib/widgets/room/room_unselected.png');

        }
        else
        {
          //alert("he");
          $("#" + element).attr('src', '../lib/widgets/room/room_selected.jpg');
        }

    });

  // Change the color of horizontal line
  $(parameter_Hr_array).each(function(index, element) {
        if(element != parameter_Hr )
        {
          //alert("hellooooo");
          $("#" +element).css('background-color', '#DDDFED');

        }
        else
        {
          //alert("he");
          $("#" + element).css('background-color', '#00FF00');
        }

    });


  //Show area on the menu div
  $(floor_area_id).each(function(index, element) {
        if(element != parameter )
        {
          $("." + element).hide();

        }
        else
        {
          $("." + element).show();
        }

    });

   // Show area on the central div
   show_Central_widget(parameter_central, parameter_Menu_array, parmeter_menu_image);


}

function show_Central_widget_single(parameter)
{


  // Show elements in central area
  $(central_Area_widgets_id).each(function(index, element) {
        if(element != parameter )
        {
          $("." + element).hide();

        }
        else
        {
          $("." + element).show();
            //alert(parameter);
        }

    });


}

function show_Central_widget(parameter,parameter_image_array, parameter_image)
{

  // set img src
  $(parameter_image_array).each(function(index, element) {
        if(element != parameter_image )
        {
          //alert("hellooooo");
          $("#" +element).attr('src', '../lib/widgets/room/room_unselected.png');

        }
        else
        {
          //alert("he");
          $("#" + element).attr('src', '../lib/widgets/room/room_selected.jpg');
        }

    });


  // Show elements in central area
  $(central_Area_widgets_id).each(function(index, element) {
        if(element != parameter )
        {
          $("." + element).hide();

        }
        else
        {
          $("." + element).show();
        }

    });


}

function GetElementInsideContainer(containerID, childID) {
    var elm = {};
    var elms = document.getElementById(containerID).getElementsByTagName("*");
    for (var i = 0; i < elms.length; i++) {
        if (elms[i].id === childID) {
            elm = elms[i];
            break;
        }
    }
    return elm;
}
