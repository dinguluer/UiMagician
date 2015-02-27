/*
  Author = Dinesh Guleria
  VSCP Developer
  Date : 27-3-2014
*/



var central_Area_widgets_id = '';
var central_Area_Group_Image_class = '';
var div_class_scrollable_Image = '';
var div_class_scrollable_Hr = '';
var floor_area_id = '';
var central_Area_widgets_id = '';
var central_Area_Group_Floor_txt_class = '';
var scrollmenu_image_id = '';
var div_floor_room_Image = '';



function doc_onload(houseType)
{


    //if there are multiple houses to be controlled by this html app
    if(houseType == 1)
    {

        /*
        var test = array_of_Arrays[0];
        //view names
        $(test).each(function(index, element) {
              alert(element);
          });*/
        //alert(test[0]);

        //show first house
        $(house_group_class).each(function(index, element) {

              if(index == 0 )
              {
                $("." + element).show();
              }
              else
              {
                $("." + element).hide();
              }
          });

        //change the color
        $(house_image_id).each(function(index, element) {

              var div = document.getElementById(element);

              if(element == house_image_id[0] )
              {
                div.style.backgroundColor = 'red';

              }
              else
              {
                div.style.backgroundColor = '#3e4046';
              }
          });

    }


    central_Area_widgets_id = house_central_Area_widgets_id[0];
    central_Area_Group_Image_class = house_central_Area_Group_Image_class[0];
    div_class_scrollable_Image = house_div_class_scrollable_Image[0];
    div_class_scrollable_Hr = house_div_class_scrollable_Hr[0];
    floor_area_id = house_floor_area_id[0];
    central_Area_widgets_id = house_central_Area_widgets_id[0];
    central_Area_Group_Floor_txt_class = house_central_Area_Group_Floor_txt_class[0];
    scrollmenu_image_id = house_scrollmenu_image_id[0];
    div_floor_room_Image = house_First_Floor_Area_Images[0];

    //hide central area
    hide_central_area();
   // select Scroll area images on load
   select_scroll_area_image();
   // Show floor area on load
   floor_area_visible_onload();
   // Show widget on load
   Central_widget_visible_onload();
   // hide group & floor text
   hide_group_floor_txt_class();
   //select floor Image
   select_floor_room_image();


    // hide info class
    hide_info_class();

    // Initialise the info data structure
    //info_init();
    for (var i = 0; i < infoVariableArray.length; i++)
    {
        infoVariableArray[i] = new info_module();
    }


    if(houseType == 1)
    {
        this.width = $('.div_layer').width();
        $('.div_layer').css('left',-this.width);
        this.rig = $('.div_layer').position().left;
    }

    //if there are multiple houses to be controlled by this html app
    if(houseType == 1)
    {
        //change house name in Menu
        var elementHouseName = 'house_menu_txt';
        document.getElementById(elementHouseName).innerHTML = house_name[0];

        var element = 'house_menu_Hr';
        $("#" +element).css('background-color', '#00FF00');

    }

    //alert(Info_details.info_text[50].direction);
    //alert(Info_details.info_text[99].direction);

    /*
   //  the Socket for I/O devices
   create_device_socket(Multi_Floor_Device_Array);
   // Create the Socket for Measurement  devices
   create_measurement_device_socket(Multi_Floor_Sensor_Device_Array);
   //create socket for slider
   create_slider_socket(Multi_Floor_Variable_Slider_Device_Array);
   //create socket for variable button
   create_Variable_Button_socket(Multi_Floor_Variable_Switch_Device_Array);
   */

    // Create the Socket for switch
     for (var i = 0; i < Multi_Floor_Device_Array.length; i++)
     {
         create_device_socket(Multi_Floor_Device_Array[i],infoVariableArray[i]);
     }
    //create socket for slider
     for (var i = 0; i < Multi_Floor_Variable_Slider_Device_Array.length; i++)
     {
         create_slider_socket(Multi_Floor_Variable_Slider_Device_Array[i],infoVariableArray[i]);
     }
    //create socket for variable button
     for (var i = 0; i < Multi_Floor_Variable_Switch_Device_Array.length; i++)
     {
         create_Variable_Button_socket(Multi_Floor_Variable_Switch_Device_Array[i],infoVariableArray[i]);
     }
    // Create the Socket for Measurement  devices
     for (var i = 0; i < Multi_Floor_Sensor_Device_Array.length; i++)
     {
         create_measurement_device_socket(Multi_Floor_Sensor_Device_Array[i]);
     }

}


function pausecomp(ms)
{
    ms += new Date().getTime();
    while (new Date() < ms){}
}


function create_measurement_device_socket( Device_Array )
{
    var bOnce = true;

    for (var i = 0; i < Device_Array.length; i++)
    {
        var btn = new vscpws_simpleTextEvent_mod( Device_Array[i].userName,
                                             Device_Array[i].password,
                                             Device_Array[i].url,           // url to VSCP websocket i/f
                                             Device_Array[i].id,              // Where it should be placed
                                             Device_Array[i].vscpclass,       // Event class 10/60/65/15
                                             Device_Array[i].vscptype,        // Evet type
                                             Device_Array[i].codingIndex,     // Datacoding index
                                             Device_Array[i].decimals,        // Number of decimals
                                             Device_Array[i].formatstr,       // A value format string
                                             Device_Array[i].guid,            // GUID we are interested in
                                             Device_Array[i].fncallback ,      // If set function to call                                                                                // when data arraives
                                             Device_Array[i].graphId,
                                             Device_Array[i].graphUnitId,
                                             Device_Array[i].graphType
                                                     );

                  btn.setExtraParameters(Device_Array[i].sensorIndex, Device_Array[i].sensorZone, Device_Array[i].sensorSubzone);

                  //delay ms
                  pausecomp(20);

                  btn.setMonitorVariable(Device_Array[i].VariableName,1000,bOnce);

    }

}


function create_device_socket( Device_Array, infoVariable )
{
    var bOnce = true;

    //for (var i = 0; i < 3; i++)
    for (var i = 0; i < Device_Array.length; i++)
    {
        var btn = new vscpws_stateButton_mod( Device_Array[i].userName,
                                             Device_Array[i].password,
                                      Device_Array[i].url,  // url
                                      Device_Array[i].canvasName,    // canvas for button
                                      Device_Array[i].bLocal,            // No local state change
                                      Device_Array[i].btnType,            // Button type
                                      Device_Array[i].bNoState,
                                      infoVariable);    // info variable name

        //set device details
        //btn.setDeviceDetails(Device_Array[i].deviceName,Device_Array[i].roomName,Device_Array[i].floorName);
        btn.setDeviceDetails(Device_Array[i].deviceName,Device_Array[i].roomName);

        btn.setOnTransmittEvent(Device_Array[i].onTxEventvscpclass,Device_Array[i].onTxEventvscptype,Device_Array[i].onTxEventdata,Device_Array[i].onTxEventguid);
        btn.setOnTransmittZone(Device_Array[i].onTxEventindex,Device_Array[i].onTxEventzone, Device_Array[i].onTxEventsubzone);
        btn.setOffTransmittEvent(Device_Array[i].offTxEventvscpclass,Device_Array[i].offTxEventvscptype,Device_Array[i].offTxEventdata,Device_Array[i].offTxEventguid);
        btn.setOffTransmittZone(Device_Array[i].offTxEventindex,Device_Array[i].offTxEventzone, Device_Array[i].offTxEventsubzone);

        btn.setOnReceiveEvent(Device_Array[i].onRxEventvscpclass,Device_Array[i].onRxEventvscptype,Device_Array[i].onRxEventdata,Device_Array[i].onRxEventguid);
        btn.setOnReceiveZone(Device_Array[i].onRxEventindex,Device_Array[i].onRxEventzone, Device_Array[i].onRxEventsubzone);
        btn.setOffReceiveEvent(Device_Array[i].offRxEventvscpclass,Device_Array[i].offRxEventvscptype,Device_Array[i].offRxEventdata,Device_Array[i].offRxEventguid);
        btn.setOffReceiveZone(Device_Array[i].offRxEventindex,Device_Array[i].offRxEventzone, Device_Array[i].offRxEventsubzone);

        //delay ms
        pausecomp(20);

        btn.setMonitorVariable(Device_Array[i].VariableName,1000,bOnce);

    }

}

function create_slider_socket( Slider_Array, infoVariable )
{
    var bOnce = true;

    for (var i = 0; i < Slider_Array.length; i++)
    {
        var btn = new vscpws_slider( Slider_Array[i].userName,
                                    Slider_Array[i].password,
                                Slider_Array[i].url,               // url
                                      Slider_Array[i].canvasName,            // canvas for slider
                                      Slider_Array[i].canvasLocalTxtName,    // Slider value
                                      Slider_Array[i].canvasRemoteTxtName,  // Remote device value
                                    infoVariable);     // info variable name

        //set device details
        //btn.setDeviceDetails(Slider_Array[i].deviceName,Slider_Array[i].roomName,Slider_Array[i].floorName);
        btn.setDeviceDetails(Slider_Array[i].deviceName,Slider_Array[i].roomName);

        btn.setTransmittEvent(Slider_Array[i].TxEventvscpclass,Slider_Array[i].TxEventvscptype,Slider_Array[i].TxEventdata,Slider_Array[i].TxEventguid);
        btn.setTransmittZone(Slider_Array[i].TxEventindex,Slider_Array[i].TxEventzone, Slider_Array[i].TxEventsubzone);

        btn.setReceiveEvent(Slider_Array[i].RxEventvscpclass,Slider_Array[i].RxEventvscptype,Slider_Array[i].RxEventdata,Slider_Array[i].RxEventguid);
        btn.setReceiveZone(Slider_Array[i].RxEventindex,Slider_Array[i].RxEventzone, Slider_Array[i].RxEventsubzone);

        //delay ms
        pausecomp(20);

        btn.setMonitorVariable(Slider_Array[i].VariableName,1000,bOnce);

    }



}

//create socket for variable button
function create_Variable_Button_socket( Variable_Button_Array, infoVariable )
{
    var bOnce = true;

    for (var i = 0; i < Variable_Button_Array.length; i++)
    {
        var btn = new vscpws_variableButton(  Variable_Button_Array[i].userName,
                                            Variable_Button_Array[i].password,
                                       Variable_Button_Array[i].url,               // url
                                      Variable_Button_Array[i].canvasIncName,            // Inc buton ID
                                      Variable_Button_Array[i].canvasDecName,            // Dec buton ID
                                      Variable_Button_Array[i].canvasLocalTxtName,       // local value ID
                                      Variable_Button_Array[i].canvasRemoteTxtName,     // Remote device value
                                      infoVariable);     // info variable name

        //set device details
        //btn.setDeviceDetails(Variable_Button_Array[i].deviceName,Variable_Button_Array[i].roomName,Variable_Button_Array[i].floorName);
        btn.setDeviceDetails(Variable_Button_Array[i].deviceName,Variable_Button_Array[i].roomName);

        btn.setTransmittEvent(Variable_Button_Array[i].TxEventvscpclass,Variable_Button_Array[i].TxEventvscptype,Variable_Button_Array[i].TxEventdata,Variable_Button_Array[i].TxEventguid);
        btn.setTransmittZone(Variable_Button_Array[i].TxEventzone, Variable_Button_Array[i].TxEventsubzone);

        btn.setReceiveEvent(Variable_Button_Array[i].RxEventvscpclass,Variable_Button_Array[i].onRxEventvscptype,Variable_Button_Array[i].RxEventdata,Variable_Button_Array[i].RxEventguid);
        btn.setReceiveZone(Variable_Button_Array[i].RxEventzone, Variable_Button_Array[i].RxEventsubzone);

        //delay ms
        pausecomp(20);

        btn.setMonitorVariable(Variable_Button_Array[i].VariableName,1000,bOnce);

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

//select floor Image
function select_floor_room_image()
{
    // set img src
    $(div_floor_room_Image).each(function(index, element) {
          if(element != div_floor_room_Image[0] )
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

}



// hide central widget area
function hide_central_area()
{
    // hide central widget area
    $(central_Area_widgets_id).each(function(index, element) {

            $("." + element).hide();
      });

    // hide central widget area
    $(central_Area_Group_Image_class).each(function(index, element) {

            $("." + element).hide();
      });

}

// hide scrollableMenu area
function hide_scrollableMenu_area()
{
    // hide scrollableMenu area
    $(floor_area_id).each(function(index, element) {

            $("." + element).hide();
      });
}

function show_group(All_Devices_group,All_Devices_Image,All_Devices_Hr)
{

    //hide central area
    hide_central_area();

    // set img src
    $(div_class_scrollable_Image).each(function(index, element) {
          if(element != All_Devices_Image )
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
          if(element != All_Devices_Hr )
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

    //hide central & scroll menu area
    hide_central_area();
    hide_scrollableMenu_area();
    // show device groups on scrollable menu
    $("." + All_Devices_group).show();
    // select first group in selectable menu
    $(scrollmenu_image_id).each(function(index, element) {
          if(element != scrollmenu_image_id[0] )
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
    //show central menu
    show_area_group_on_groups_clicked();
    //$("." + group_Txt).show();
    //$("." + group_Floor_Txt).show();

}

function show_area_group(group_device,group_image)
{
    // set img src
    //$(div_class_All_Devices_group_Images).each(function(index, element) {
    $(scrollmenu_image_id).each(function(index, element) {
          if(element != group_image )
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

    //hide central & scroll menu area
    hide_central_area();
    //show group devices
    $("." + group_device).show();
    // show group txt
    $("." + central_Area_Group_Floor_txt_class[0]).show();
    // show floor txt
    $("." + central_Area_Group_Floor_txt_class[1]).show();

}

//function show_area_group_on_groups_clicked(All_Devices_group,group_Txt,group_Floor_Txt)
function show_area_group_on_groups_clicked()
{
    //Show group images
    $("." + central_Area_Group_Image_class[0]).show();

    $("." + central_Area_Group_Floor_txt_class[0]).show();  // show floor names  -- i.e group_txt
    $("." + central_Area_Group_Floor_txt_class[1]).show();  // show room  names  -- i.e group_Floor_Txt
    //show room names
    /*$(central_Area_Floor_txt_class).each(function(index, element) {
            $("." + element).show();
      });*/
}

function show_Floor_Group(group_Floor_class, array_floor_images_id, floor_group_Image_id)
{
    // set img src
    $(array_floor_images_id).each(function(index, element) {
          if(element != floor_group_Image_id )
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

    //hide all central elements
    hide_central_area();
    //alert("hello");
    $("." + group_Floor_class).show();  // show floor names
    // hide group txt class
    $("." + central_Area_Group_Floor_txt_class[0]).hide();
    // show floor txt class
    $("." + central_Area_Group_Floor_txt_class[1]).show();
}

function hide_group_floor_txt_class()
{
    $("." + central_Area_Group_Floor_txt_class[0]).hide();
    $("." + central_Area_Group_Floor_txt_class[1]).hide();

}

function show_area(parameter, parameter_image_array, parameter_image, parameter_Hr_array, parameter_Hr, parameter_central, parameter_Menu_array, parmeter_menu_image)
{


  //hide central area
  hide_central_area();

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

   // hide group & floor text
   hide_group_floor_txt_class();

}

function show_info(parameter_image_array, parameter_Hr_array, parameter_Hr, parameter_central, parameter_home_name, parameter_home_index)
{

    //alert(parameter_Hr_array);
    //hide central area
    hide_central_area();

    //Show area on the scrollable div
    // set img src
    $(parameter_image_array).each(function(index, element) {
            $("#" +element).attr('src', '../lib/widgets/room/room_unselected.png');
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


  //Hide area on the menu div
  $(floor_area_id).each(function(index, element) {
          $("." + element).hide();
    });


    // Show elements in central area
    $(central_Area_widgets_id).each(function(index, element) {
          if(element != parameter_central )
          {
            $("." + element).hide();

          }
          else
          {
            $("." + element).show();
          }

      });

    //alert(parameter_central);
   // hide group & floor text
   hide_group_floor_txt_class();


    // change info div content
    infoVariableArray[parameter_home_index].infoDisplay(parameter_central, parameter_home_name);  //------------->

    //alert(1);
    //hide unused info
    infoVariableArray[parameter_home_index].infoShow(parameter_home_name);

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



    // hide group & floor text
    hide_group_floor_txt_class();


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
