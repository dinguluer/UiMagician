var Info_details = {
    mutex: 0,
    start: 0,
    end: 0,
    length: 0,
    info_text : []
};

var Info_len = 100;
var startInfoProcessing = 0;

function info_init()
{
    Info_details.start = 0;
    Info_details.end   = 0;
    Info_details.length = 0;

    for (var i = 0; i < Info_len ; i++) {
        Info_details.info_text.push({
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



function setInfoData(eventSend, infoMessage)
{

//alert('enter --> ' + Info_details.length);

    var d = new Date();

    var curr_date = d.getDate();
    var curr_month = d.getMonth();
    var curr_year = d.getFullYear();
    var curr_hour = d.getHours();
    var curr_minute = d.getMinutes();
    var curr_sec = d.getSeconds();
    var timeDetail = curr_date + "-" + curr_month + "-" + curr_year + "  " + curr_hour + ":" + curr_minute + ":" +  curr_sec ;
    //var timeDetail = curr_date + "-" + curr_month + "-" + curr_year + "  " + curr_hour + ":" + curr_minute  ;

    if(startInfoProcessing != 0)
    {
        if(Info_details.length < Info_len)
        {
            //Info_details.length++;
        }

        if(Info_details.length < Info_len)  //i.e < (100 -1 ) --> < 99
        {
            //Info_details.end++;
            Info_details.length++;
        }
        else
        {
            // process starting pointer
            if(Info_details.start == Info_len)
            {
                Info_details.start = 0;

            }
            else
            {
                Info_details.start++;
            }

            /*
            // process end pointer
            if(Info_details.end == Info_len)
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
        if(Info_details.end == Info_len)
        {
            Info_details.end = 0;

        }

        if(eventSend == 1)
        {
           Info_details.info_text[Info_details.end].direction = "out";
        }
        else
        {
            Info_details.info_text[Info_details.end].direction = "in";
        }

        Info_details.info_text[Info_details.end].message   = infoMessage;
        Info_details.info_text[Info_details.end].time     = timeDetail;

        //increment the end point
        Info_details.end++;
    }
    else
    {
        Info_details.start = 0;
        Info_details.end   = 0;
        Info_details.length = 1;

        if(eventSend == 1)
        {
           Info_details.info_text[0].direction = "out";
        }
        else
        {
            Info_details.info_text[0].direction = "in";
        }

        Info_details.info_text[0].message   = infoMessage;
        Info_details.info_text[0].time     = timeDetail;

        Info_details.end++;

        startInfoProcessing = 1;
    }

//alert(Info_details.length);
//alert(Info_details.start);
//alert(Info_details.end);

//alert('exit --> ' + Info_details.length);

}

function infoDisplay(parameter_info)
{
    var divIndex = 0;
    var divIndexString = divIndex.toString();
    var divId;
    var messageTxt;
    var messageTxtValue;
    var messageTime;

    // start updating only if single message is received
    if(startInfoProcessing == 1)
    {        

        //check if buffer is full
        if(Info_details.length == Info_len)
        {
            // update div value & class
            for (var j = Info_details.start; j < Info_len; j++)
            {
                divIndexString = divIndex.toString();

                //update message text class
                divId = "info_class_" + divIndexString;

    //alert(divId);
                messageTxt = document.getElementById(divId);
                if(Info_details.info_text[j].direction == "out")
                {
                    messageTxt.className="info_text blue_box arrow_right";

                }
                else
                {
//alert(j);
                    messageTxt.className="info_text green_box arrow_left";
                }
                //update message text
                divId = "info_txt_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  Info_details.info_text[j].message ;

                //update message & time text class
                divId = "info_time_" + divIndexString;
                messageTxt = document.getElementById(divId);
                if(Info_details.info_text[j].direction == "out")
                {
    //alert(1);
                    messageTxt.className="info_text time_right_box_class";

                }
                else
                {
                    messageTxt.className="info_text time_left_box_class";
                }

                //update message text
                divId = "info_time_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  Info_details.info_text[j].time ;


                divIndex++;
            }



            //alert("+++" + Info_details.end);

         if(Info_details.end < Info_len)
         {
            // update div value & class
            for (var j = 0; j < Info_details.end; j++)
            {
                divIndexString = divIndex.toString();

                //update message text class
                divId = "info_class_" + divIndexString;

    //alert("-->" + divId);

                messageTxt = document.getElementById(divId);
                if(Info_details.info_text[j].direction == "out")
                {
                    messageTxt.className="info_text blue_box arrow_right";

                }
                else
                {
                    messageTxt.className="info_text green_box arrow_left";
                }
                //update message text
                divId = "info_txt_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  Info_details.info_text[j].message ;

                //update message & time text class
                divId = "info_time_" + divIndexString;
                messageTxt = document.getElementById(divId);
                if(Info_details.info_text[j].direction == "out")
                {
                    messageTxt.className="info_text time_right_box_class";

                }
                else
                {
                    messageTxt.className="info_text time_left_box_class";
                }

                //update message text
                divId = "info_time_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  Info_details.info_text[j].time ;


                divIndex++;
            }

          }

        }
        else
        {
            // update div value & class
            for (var j = Info_details.start; j < Info_details.length; j++)
            {
                divIndexString = divIndex.toString();

                //update message text class
                divId = "info_class_" + divIndexString;

    //alert(divId);
                messageTxt = document.getElementById(divId);
                if(Info_details.info_text[j].direction == "out")
                {
                    messageTxt.className="info_text blue_box arrow_right";

                }
                else
                {
                    messageTxt.className="info_text green_box arrow_left";
                }
                //update message text
                divId = "info_txt_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  Info_details.info_text[j].message ;

                //update message & time text class
                divId = "info_time_" + divIndexString;
                messageTxt = document.getElementById(divId);
                if(Info_details.info_text[j].direction == "out")
                {
    //alert(1);
                    messageTxt.className="info_text time_right_box_class";

                }
                else
                {
                    messageTxt.className="info_text time_left_box_class";
                }

                //update message text
                divId = "info_time_" + divIndexString;
                messageTxt = document.getElementById(divId);
                messageTxt.innerHTML =  Info_details.info_text[j].time ;


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


function infoShow()
{
    var divIndex = 0;
    var divIndexString = divIndex.toString();

//alert('1');
//alert(Info_details.length);

//send 0,20,3,0,0,-,0,0,

//alert("***" + Info_details.length);
    // update div value & class
    //for (var j = 0; j < 5; j++)
    for (var j = 0; j < Info_len; j++)
    {
        divIndexString = "info_" + j.toString();


        //var id = "info_3";
        //id.show();

        //alert(divIndexString);


       
        if( j < Info_details.length )
        {
           $("." + divIndexString).show();
        }
        else
        {
           $("." + divIndexString).hide();
        }

    }

}

