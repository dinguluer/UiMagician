/*
  Author = Dinesh Guleria
  VSCP Developer
  Date : 27-3-2014
*/

function doc_onload(page_type)
{

   // select Scroll area images on load
   select_scroll_area_image();

   // Show floor area on load
   // page_type = 0  ; Single floor
   // page_type = 1  ; multiple floor
   if(page_type)
   {
      floor_area_visible_onload();
   }

   // Show widget on load
   Central_widget_visible_onload();
   // Create the Socket
   //---create_device_socket(Single_Floor_Device_Array);
   // Create the Socket for Measurement  devices
   //---create_measurement_device_socket(Single_Floor_Sensor_Device_Array);
   //create socket for slider
   //---create_slider_socket(Single_Floor_Variable_Slider_Device_Array);
   //create socket for variable button
   //---create_Variable_Button_socket(Single_Floor_Variable_Switch_Device_Array);
}

function create_measurement_device_socket( Device_Array )
{

    for (var i = 0; i < Device_Array.length; i++)
    {
        var btn = new vscpws_simpleTextEvent( Device_Array[i].url,           // url to VSCP websocket i/f
                                             Device_Array[i].id,              // Where it should be placed
                                             Device_Array[i].vscpclass,       // Event class 10/60/65/15
                                             Device_Array[i].vscptype,        // Evet type
                                             Device_Array[i].codingIndex,     // Datacoding index
                                             Device_Array[i].decimals,        // Number of decimals
                                             Device_Array[i].formatstr,       // A value format string
                                             Device_Array[i].guid,            // GUID we are interested in
                                             Device_Array[i].fncallback );     // If set function to call
                                                                               // when data arraives
          btn.setExtraParameters(Device_Array[i].sensorIndex, Device_Array[i].sensorZone, Device_Array[i].sensorSubzone);
    }

}

function create_device_socket( Device_Array )
{

    for (var i = 0; i < Device_Array.length; i++)
    {
        var btn = new vscpws_stateButton_mod( Device_Array[i].url,  // url
                                      Device_Array[i].canvasName,    // canvas for button
                                      Device_Array[i].bLocal,            // No local state change
                                      Device_Array[i].btnType,            // Button type
                                      Device_Array[i].bNoState);

        btn.setOnTransmittEvent(Device_Array[i].onTxEventvscpclass,Device_Array[i].onTxEventvscptype,Device_Array[i].onTxEventdata,Device_Array[i].onTxEventguid);
        btn.setOnTransmittZone(Device_Array[i].onTxEventindex,Device_Array[i].onTxEventzone, Device_Array[i].onTxEventsubzone);
        btn.setOffTransmittEvent(Device_Array[i].offTxEventvscpclass,Device_Array[i].offTxEventvscptype,Device_Array[i].offTxEventdata,Device_Array[i].offTxEventguid);
        btn.setOffTransmittZone(Device_Array[i].offTxEventindex,Device_Array[i].offTxEventzone, Device_Array[i].offTxEventsubzone);

        btn.setOnReceiveEvent(Device_Array[i].onRxEventvscpclass,Device_Array[i].onRxEventvscptype,Device_Array[i].onRxEventdata,Device_Array[i].onRxEventguid);
        btn.setOnReceiveZone(Device_Array[i].onRxEventindex,Device_Array[i].onRxEventzone, Device_Array[i].onRxEventsubzone);
        btn.setOffReceiveEvent(Device_Array[i].offRxEventvscpclass,Device_Array[i].offRxEventvscptype,Device_Array[i].offRxEventdata,Device_Array[i].offRxEventguid);
        btn.setOffReceiveZone(Device_Array[i].offRxEventindex,Device_Array[i].offRxEventzone, Device_Array[i].offRxEventsubzone);

//        btn.setMonitorVariable(Device_Array[i].VariableName);

    }

}

function create_slider_socket( Slider_Array )
{

    for (var i = 0; i < Slider_Array.length; i++)
    {
        var btn = new vscpws_slider( Slider_Array[i].url,               // url
                                      Slider_Array[i].canvasName,            // canvas for slider
                                      Slider_Array[i].canvasLocalTxtName,    // Slider value
                                      Slider_Array[i].canvasRemoteTxtName);  // Remote device value

        btn.setTransmittEvent(Slider_Array[i].TxEventvscpclass,Slider_Array[i].TxEventvscptype,Slider_Array[i].TxEventdata,Slider_Array[i].TxEventguid);
        btn.setTransmittZone(Slider_Array[i].TxEventindex,Slider_Array[i].TxEventzone, Slider_Array[i].TxEventsubzone);

        btn.setReceiveEvent(Slider_Array[i].RxEventvscpclass,Slider_Array[i].onRxEventvscptype,Slider_Array[i].RxEventdata,Slider_Array[i].RxEventguid);
        btn.setReceiveZone(Slider_Array[i].RxEventindex,Slider_Array[i].RxEventzone, Slider_Array[i].RxEventsubzone);

        //btn.setMonitorVariable(Slider_Array[i].VariableName);

    }



}

//create socket for variable button
function create_Variable_Button_socket( Variable_Button_Array )
{

    for (var i = 0; i < Variable_Button_Array.length; i++)
    {
        var btn = new vscpws_variableButton( Variable_Button_Array[i].url,               // url
                                      Variable_Button_Array[i].canvasIncName,            // Inc buton ID
                                      Variable_Button_Array[i].canvasDecName,            // Dec buton ID
                                      Variable_Button_Array[i].canvasLocalTxtName,       // local value ID
                                      Variable_Button_Array[i].canvasRemoteTxtName);     // Remote device value

        btn.setTransmittEvent(Variable_Button_Array[i].TxEventvscpclass,Variable_Button_Array[i].TxEventvscptype,Variable_Button_Array[i].TxEventdata,Variable_Button_Array[i].TxEventguid);
        btn.setTransmittZone(Variable_Button_Array[i].TxEventzone, Variable_Button_Array[i].TxEventsubzone);

        btn.setReceiveEvent(Variable_Button_Array[i].RxEventvscpclass,Variable_Button_Array[i].onRxEventvscptype,Variable_Button_Array[i].RxEventdata,Variable_Button_Array[i].RxEventguid);
        btn.setReceiveZone(Variable_Button_Array[i].RxEventzone, Variable_Button_Array[i].RxEventsubzone);

        //btn.setMonitorVariable(Variable_Button_Array[i].VariableName);

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
