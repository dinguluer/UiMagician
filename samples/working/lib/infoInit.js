
// hide group images
function hide_info_class()
{


  // hide elements in group area
  $(infoClass).each(function(index, element) {
          $("." + element).hide();
    });


}


function info_module()
{

    this.Info_details = {
        mutex: 0,
        start: 0,
        end: 0,
        length: 0,
        info_text : []
    };

    this.Info_len = 100;
    this.startInfoProcessing = 0;

    this.Info_details.start = 0;
    this.Info_details.end   = 0;
    this.Info_details.length = 0;

    for (var i = 0; i < this.Info_len ; i++) {
        this.Info_details.info_text.push({
            direction: "",
            time  : "",
            message  : ""
        });
    }

    /*Info_details.info_text.push({
        direction: "in",
        message  : ""
    });*/
}



info_module.prototype.setInfoData = function(eventSend, infoMessage)
{

//alert('enter --> ' + this.Info_details.length);

            //delay ms
            pausecomp(20);

    var d = new Date();

    var curr_date = d.getDate();
    var curr_month = d.getMonth();
    var curr_year = d.getFullYear();
    var curr_hour = d.getHours();
    var curr_minute = d.getMinutes();
    var curr_sec = d.getSeconds();
    var timeDetail = curr_date + "-" + curr_month + "-" + curr_year + "  " + curr_hour + ":" + curr_minute + ":" +  curr_sec ;
    //var timeDetail = curr_date + "-" + curr_month + "-" + curr_year + "  " + curr_hour + ":" + curr_minute  ;

    if(this.startInfoProcessing != 0)
    {
        if(this.Info_details.length < this.Info_len)
        {
            //Info_details.length++;
        }

        if(this.Info_details.length < this.Info_len)  //i.e < (100 -1 ) --> < 99
        {
            //Info_details.end++;
            this.Info_details.length++;
        }
        else
        {
            // process starting pointer
            if(this.Info_details.start == this.Info_len)
            {
                this.Info_details.start = 0;

            }
            else
            {
                this.Info_details.start++;
            }

            /*
            // process end pointer
            if(Info_details.end == this.Info_len)
            {
                Info_details.end = 0;

            }
            else
            {
                Info_details.end++;
            }*/

            //Info_details.end++;

        }

        // process end pointer
        if(this.Info_details.end == this.Info_len)
        {
            this.Info_details.end = 0;

        }

        if(eventSend == 1)
        {
           this.Info_details.info_text[this.Info_details.end].direction = "out";
        }
        else
        {
            this.Info_details.info_text[this.Info_details.end].direction = "in";
        }

        this.Info_details.info_text[this.Info_details.end].message   = infoMessage;
        this.Info_details.info_text[this.Info_details.end].time     = timeDetail;

        //increment the end point
        this.Info_details.end++;
    }
    else
    {
        this.Info_details.start = 0;
        this.Info_details.end   = 0;
        this.Info_details.length = 1;

        if(eventSend == 1)
        {
           this.Info_details.info_text[0].direction = "out";
        }
        else
        {
            this.Info_details.info_text[0].direction = "in";
        }

        this.Info_details.info_text[0].message   = infoMessage;
        this.Info_details.info_text[0].time     = timeDetail;

        this.Info_details.end++;

        this.startInfoProcessing = 1;
    }

//alert(Info_details.length);
//alert(Info_details.start);
//alert(Info_details.end);

//alert('exit --> ' + Info_details.length);

}

//function infoDisplay(parameter_info)
info_module.prototype.infoDisplay = function(parameter_info, home_name)
{
    var divIndex = 0;
    var divIndexString = divIndex.toString();
    var divId;
    var messageTxt;
    var messageTxtValue;
    var messageTime;

    // start updating only if single message is received
    if(this.startInfoProcessing == 1)
    {        

        //check if buffer is full
        if(this.Info_details.length == this.Info_len)
        {
            // update div value & class
            for (var j = this.Info_details.start; j < this.Info_len; j++)
            {
                divIndexString = divIndex.toString();

                //update message text class
                divId = "info_class_" + home_name + "_" +  divIndexString;

    //alert(divId);
                messageTxt = document.getElementById(divId);
                if(this.Info_details.info_text[j].direction == "out")
                {
                    messageTxt.className="info_text_" + home_name + " blue_box arrow_right";

                }
                else
                {
//alert(j);
                    messageTxt.className="info_text_" + home_name + " green_box arrow_left";
                }
                //update message text
                divId = "info_txt_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  this.Info_details.info_text[j].message ;

                //update message & time text class
                divId = "info_time_" + divIndexString;
                messageTxt = document.getElementById(divId);
                if(this.Info_details.info_text[j].direction == "out")
                {
    //alert(1);
                    messageTxt.className="info_text_" + home_name + " time_right_box_class";

                }
                else
                {
                    messageTxt.className="info_text_" + home_name + " time_left_box_class";
                }

                //update message text
                divId = "info_time_" + home_name + "_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  this.Info_details.info_text[j].time ;


                divIndex++;
            }



            //alert("+++" + Info_details.end);

         if(this.Info_details.end < this.Info_len)
         {
            // update div value & class
            for (var j = 0; j < this.Info_details.end; j++)
            {
                divIndexString = divIndex.toString();

                //update message text class
                divId = "info_class_" + divIndexString;

    //alert("-->" + divId);

                messageTxt = document.getElementById(divId);
                if(this.Info_details.info_text[j].direction == "out")
                {
                    messageTxt.className="info_text_" + home_name + " blue_box arrow_right";

                }
                else
                {
                    messageTxt.className="info_text_" + home_name + " green_box arrow_left";
                }
                //update message text
                divId = "info_txt_" + home_name + "_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  this.Info_details.info_text[j].message ;

                //update message & time text class
                divId = "info_time_" + home_name + "_"  + divIndexString;
                messageTxt = document.getElementById(divId);
                if(this.Info_details.info_text[j].direction == "out")
                {
                    messageTxt.className="info_text_" + home_name + " time_right_box_class";

                }
                else
                {
                    messageTxt.className="info_text_" + home_name + " time_left_box_class";
                }

                //update message text
                divId = "info_time_" + home_name + "_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  this.Info_details.info_text[j].time ;


                divIndex++;
            }

          }

        }
        else
        {
            // update div value & class
            for (var j = this.Info_details.start; j < this.Info_details.length; j++)
            {
                divIndexString = divIndex.toString();

                //update message text class
                divId = "info_class_" + home_name + "_"  + divIndexString;

    //alert(divId);
                messageTxt = document.getElementById(divId);
                if(this.Info_details.info_text[j].direction == "out")
                {
                    messageTxt.className="info_text_" + home_name + " blue_box arrow_right";

                }
                else
                {
                    messageTxt.className="info_text_" + home_name + " green_box arrow_left";
                }
                //update message text
                divId = "info_txt_" + home_name + "_"   + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  this.Info_details.info_text[j].message ;

                //update message & time text class
                divId = "info_time_" + home_name + "_"   + divIndexString;
                messageTxt = document.getElementById(divId);
                if(this.Info_details.info_text[j].direction == "out")
                {
    //alert(1);
                    messageTxt.className="info_text_" + home_name + " time_right_box_class";

                }
                else
                {
                    messageTxt.className="info_text_" + home_name + " time_left_box_class";
                }

                //update message text
                divId = "info_time_" + home_name + "_"   + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  this.Info_details.info_text[j].time ;


                divIndex++;
            }

        }

    }
    else // nothing to display
    {
        //parameter_info.hide();
        $("." + parameter_info).hide();
    }

}


info_module.prototype.infoShow = function(home_name)
{
    var divIndex = 0;
    var divIndexString = divIndex.toString();

//alert('1');
//alert(Info_details.length);

//send 0,20,3,0,0,-,0,0,

//alert("***" + Info_details.length);
    // update div value & class
    //for (var j = 0; j < 5; j++)
    for (var j = 0; j < this.Info_len; j++)
    {
        //divIndexString = "info_" + j.toString();
        divIndexString = "info_" + home_name + "_" + j.toString();


        //var id = "info_3";
        //id.show();

        //alert(divIndexString);


       
        if( j < this.Info_details.length )
        {
           $("." + divIndexString).show();
        }
        else
        {
           $("." + divIndexString).hide();
        }

    }

    //alert(this.Info_details.length)

}

