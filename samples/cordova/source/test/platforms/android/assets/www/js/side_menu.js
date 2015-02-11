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
      $(".buttoncls").animate({left:'0px'}, 300);
    }
    else
    {
      $('.div_layer').animate({left:'0px'}, 300);
      $(".buttoncls").animate({left:this.width}, 300);
    }

}


function doc_onload() {

    this.width = $('.div_layer').width();
    $('.div_layer').css('left',-this.width);
    this.rig = $('.div_layer').position().left;


};

function selectId(id) {
    //alert(id);

    $('.div_layer').animate({left:-this.width}, 300);
    $(".buttoncls").animate({left:'0px'}, 300);

    //collaspe the menu
};
