/*
$(document).ready(function(){

 var width=$('.div_layer').width();
 $('.div_layer').css('left',-width);
 var rig=$('.div_layer').position().left;

 $(".buttoncls").click(function() {
 var rig=$('.div_layer').position().left;
 if(rig == 0 )
 {
 $('.div_layer').animate({left:-width}, 300);
 $(".buttoncls").animate({left:'0px'}, 300);
 }
 else
 {
 $('.div_layer').animate({left:'0px'}, 300);
 $(".buttoncls").animate({left:width}, 300);
 }
 });


 });
*/

function house_onclick() {

    var rig=$('.div_layer').position().left;
    if(rig == 0 )
    {
      $('.div_layer').animate({left:-this.width}, 300);
      $(".scrollable").animate({left:'0px'}, 300);
      $(".scrollableMenu").animate({left:'0px'}, 300);
      //$(".scrollableCenter").animate({left:'250px'}, 300);
        $(".scrollableCenter").animate({left:'380px'}, 300);
      //$(".buttoncls_fotter").animate({left:'0px'}, 300);
    }
    else
    {
        //var center = this.width + 250;
        var center = this.width + 380;

      $('.div_layer').animate({left:'0px'}, 300);
        $(".scrollable").animate({left:this.width}, 300);
        $(".scrollableMenu").animate({left:this.width}, 300);
        $(".scrollableCenter").animate({left:center}, 300);
        //$(".buttoncls_fotter").animate({left:this.width}, 300);

    }

    var element = 'Houses_Hr';
    $("#" + element).css('background-color', '#DDDFED');
}

/*
function doc_onload() {

    this.width = $('.div_layer').width();
    $('.div_layer').css('left',-this.width);
    this.rig = $('.div_layer').position().left;


};*/

function selectId(id, indexArray,  houseName, houseClass) {
    //alert(id);

    //change the color
    $(house_image_id).each(function(index, element) {

          var div = document.getElementById(element);

          if(element == id )
          {
            div.style.backgroundColor = 'red';

          }
          else
          {
            div.style.backgroundColor = '#3e4046';
          }
      });


    //collaspe the menu
    $('.div_layer').animate({left:-this.width}, 300);
    //var center = 250;
    var center = 380;
    $(".scrollable").animate({left:'0px'}, 300);
    $(".scrollableMenu").animate({left:'0px'}, 300);
    $(".scrollableCenter").animate({left:center}, 300);
    //$(".buttoncls_fotter").animate({left:'0px'}, 300);

    //show house area
    $(house_group_class).each(function(index, element) {
          if(element != houseClass )
          {
            $("." + element).hide();

          }
          else
          {
            $("." + element).show();

          }

          central_Area_widgets_id = house_central_Area_widgets_id[indexArray];
          central_Area_Group_Image_class = house_central_Area_Group_Image_class[indexArray];
          div_class_scrollable_Image = house_div_class_scrollable_Image[indexArray];
          div_class_scrollable_Hr = house_div_class_scrollable_Hr[indexArray];
          floor_area_id = house_floor_area_id[indexArray];
          central_Area_widgets_id = house_central_Area_widgets_id[indexArray];
          //Always zero
          central_Area_Group_Floor_txt_class = house_central_Area_Group_Floor_txt_class[indexArray];
          scrollmenu_image_id = house_scrollmenu_image_id[indexArray];
          div_floor_room_Image = house_First_Floor_Area_Images[indexArray];

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

      });

    //change house name in Menu
    var elementHouseName = 'house_menu_txt';
    document.getElementById(elementHouseName).innerHTML = houseName;

    var element = 'house_menu_Hr';
    $("#" +element).css('background-color', '#00FF00');
};
