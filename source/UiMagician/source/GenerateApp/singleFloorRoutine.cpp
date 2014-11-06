/*---------------------------------------------------------------------------
** Project Name: UiMagician
** #Archive:
** #Author: # Dinesh Guleria
** #Date: # 15-03-2013
** Copyright (C) 2012-2014 Dinesh Guleria, VSCP Developer
**----------------------------------------------------------------------------
** #Revision: 1 #
**----------------------------------------------------------------------------
** Target system: QT - 4.8.1
** Compiler:
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials           Name                     Project
** --------           ---------------------    -------------------------------
** DINESH.GULERIA     Dinesh Guleria           UiMagician
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log:
** 1. Creation of the file.
** 2. Review the implementation to bring it to 100%.
**--------------------------------------------------------------------------*/


#include <QtGui>
#include "generateapp.h"
#include "ui_generateapp.h"
#include "../common/timer/SleepTimerDelay.h"



// Create the single floor DIV scrollable
void GenerateApp::createSingleFloorDivScrollable(QDomElement &NodeElementSingleFloorDivScrollable)
{
    QDomElement NodeElementTemp;
    QDomElement NodeElementChildTemp;
    QString nodeNameTemp;
    QString nodeChildNameTemp;

    QString roomNameImageId;
    QString roomTxtId;
    QString roomHrId;

    QString OnClickText;

    QString scrollableImageArray;
    QString scrollableHrArray;

    QString floorName;

    T_packetFloorNodes floorNodes;

    QDomNodeList listRooms;

    QString nodeDataTextRoom;

    QDomNode tempNodeChild;
    QDomNodeList listChild;

    QString infoNodeName;

    QString groupDivId;
    QString groupImageId;
    QString groupHrId;
    QString groupClassName;
    QString groupTxtClassName;
    QString groupTxtId;
    QString groupImageTxt;


    nodeName = "div";
    NodeElementSingleFloorDivScrollable  = htmlDomDocument.createElement(nodeName);
    NodeElementSingleFloorDivScrollable.setAttribute("id","images");
    NodeElementSingleFloorDivScrollable.setAttribute("class","scrollable");

    scrollableImageArray     = "var div_class_scrollable_Image = [";
    scrollableHrArray        = "var div_class_scrollable_Hr = [";
    //Append new line
    scrollableImageArray += "\n";
    scrollableHrArray += "\n";

    //This loop will run 1 time as floorlist.size() is --> 1
    for (int i = 0; i < floorList.size(); ++i)
    {

        floorName = floorList.at(i);

        floorNodes = floorNodesList.at(0);
        //Load root nodes
        listRooms = floorNodes.floorRooms.childNodes();

        //get room name in list
        for (int t = 0; t < listRooms.size(); ++t)
        {

            //read the child node from list
            tempNodeChild = listRooms.at(t);

            // Create list of child nodes of - test case
            listChild = tempNodeChild.childNodes();
            //Read Room name from node
            tempNodeChild = listChild.at(ROOM_NAME_INDEX);
            if (!tempNodeChild.isNull())
            {
                nodeDataTextRoom = tempNodeChild.toElement().text();
            }
            else
            {
                nodeDataTextRoom = "";
            }

            //Edit room name
            nodeDataTextRoom.replace(" ", "");
            nodeDataTextRoom.remove(QRegExp("[^a-zA-Z\\d\\s]"));

            nodeNameTemp = "div";
            NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
            NodeElementTemp.setAttribute("id",nodeDataTextRoom);
            NodeElementTemp.setAttribute("class","input");

            //Create input node
            nodeChildNameTemp = "input";
            NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
            roomNameImageId = nodeDataTextRoom + "_Image";
            NodeElementChildTemp.setAttribute("id",roomNameImageId);
            NodeElementChildTemp.setAttribute("type","image");
            NodeElementChildTemp.setAttribute("class","image_scrollable");
            NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
            //NodeElementChildTemp.setAttribute("alt",floorNameId);
            OnClickText = "show_area_single(" "div_class_scrollable_Image,"
                                              "'" + roomNameImageId + "',"
                                              "div_class_scrollable_Hr,"
                                              "'" + nodeDataTextRoom + "_Hr" "'," +
                                              "'" + floorName + "_Floor"  "_Area_" + nodeDataTextRoom + "')"
                                              ;
            NodeElementChildTemp.setAttribute("onclick",OnClickText);
            //Append image div to floor div
            NodeElementTemp.appendChild(NodeElementChildTemp);

            //Create paragraph node
            nodeChildNameTemp = "p";
            NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
            roomTxtId = nodeDataTextRoom + "_txt";
            NodeElementChildTemp.setAttribute("id",roomTxtId);
            NodeElementChildTemp.setAttribute("class","imgtxt");
            stringTxtNode = nodeDataTextRoom;
            textNode = htmlDomDocument.createTextNode(stringTxtNode);
            //Append txt node
            NodeElementChildTemp.appendChild(textNode);
            //Append paragraph div to floor div
            NodeElementTemp.appendChild(NodeElementChildTemp);

            //Create hr node
            nodeChildNameTemp = "input";
            NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
            roomHrId = nodeDataTextRoom + "_Hr";
            NodeElementChildTemp.setAttribute("id",roomHrId);
            NodeElementChildTemp.setAttribute("class","hr_scrollable");
            //Append hr div to floor div
            NodeElementTemp.appendChild(NodeElementChildTemp);

            // Append floor div to div scrollable
            NodeElementSingleFloorDivScrollable.appendChild(NodeElementTemp);

            //add floor image ID
            scrollableImageArray += "\"" + roomNameImageId + "\""  ;
            // add HR line ID
            scrollableHrArray += "\"" + roomHrId + "\""  ;

            // check if it is last element to put in the array
            //if((t+1) < listRooms.size())
            //{
                scrollableImageArray += ",";
                scrollableHrArray += ",";
            //}

        }

    }

    //Get the Total number of groups
    getTotalGroups();

    //Create group config array
    SingleFloorGroupImageClass = "\n";
    SingleFloorGroupImageClass += "\n";
    SingleFloorGroupImageClass += "var central_Area_Group_Image_class = [";
    SingleFloorGroupImageClass += "\n" ;

    SingleFloorGroupTxtClass = "\n";
    SingleFloorGroupTxtClass += "\n";
    SingleFloorGroupTxtClass += "var central_Area_Group_txt_class = [";
    SingleFloorGroupTxtClass += "\n" ;

    //create Group nodes
    for (int i = 0; i < groupsTotal; ++i)
    {

        if(flagLightsGroup == 1)
        {
            groupDivId = "group_Light_Button";
            groupImageId = "group_Light_Image";
            groupHrId = "group_Light_Hr";
            groupClassName = "group_Lights";
            groupTxtClassName = "group_Light_Txt";
            groupTxtId = "group_Light_Txt_Id";
            groupImageTxt = "Lights";

            flagLightsGroup = 0;

        }
        else if(flagAccessoriesGroup == 1)
        {
            groupDivId = "group_Accessories_Button";
            groupImageId = "group_Accessories_Image";
            groupHrId = "group_Accessories_Hr";
            groupClassName = "group_Accessories";
            groupTxtClassName = "group_Accessories_Txt";
            groupTxtId = "group_Accessories_Txt_Id";
            groupImageTxt = "Accessories";

            flagAccessoriesGroup = 0;

        }
        else if(flagBlindDoorWindowGroup == 1)
        {
            groupDivId = "group_Blinds_Windows_Button";
            groupImageId = "group_Blinds_Windows_Image";
            groupHrId = "group_Blinds_Windows_Hr";
            groupClassName = "group_Blinds_Windows";
            groupTxtClassName = "group_Blinds_Windows_Txt";
            groupTxtId = "group_Blinds_Windows_Txt_Id";
            groupImageTxt = "Door Window";

            flagBlindDoorWindowGroup = 0;

        }
        else if(flagsensorGroup == 1)
        {
            groupDivId = "group_Sensors_Button";
            groupImageId = "group_Sensors_Image";
            groupHrId = "group_Sensors_Hr";
            groupClassName = "group_Sensors";
            groupTxtClassName = "group_Sensors_Txt";
            groupTxtId = "group_Sensors_Txt_Id";
            groupImageTxt = "Sensors";

            flagsensorGroup = 0;

        }
        else if(flagTemperatureControllerGroup == 1)
        {
            groupDivId = "group_Temperature_control_Button";
            groupImageId = "group_Temperature_control_Image";
            groupHrId = "group_Temperature_control_Hr";
            groupClassName = "group_Temperature_control";
            groupTxtClassName = "group_Temperature_control_Txt";
            groupTxtId = "group_Temperature_control_Txt_Id";
            groupImageTxt = "Temperature control";

            flagTemperatureControllerGroup = 0;

        }
        else
        {
            // Do nothing
        }

        SingleFloorGroupImageClass += "\"" + groupClassName + "\"" ;
        SingleFloorGroupTxtClass   += "\"" + groupTxtClassName + "\"" ;
        if((i+1) == groupsTotal)
        {
            //Do not append -- ","
            SingleFloorGroupImageClass += "\n" ;
            SingleFloorGroupImageClass += "];" ;

            //Do not append -- ","
            SingleFloorGroupTxtClass += "\n" ;
            SingleFloorGroupTxtClass += "];" ;
        }
        else
        {
            SingleFloorGroupImageClass += "," ;
            SingleFloorGroupTxtClass += "," ;

        }

        nodeNameTemp = "div";
        NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
        NodeElementTemp.setAttribute("id",groupDivId);
        NodeElementTemp.setAttribute("class","input");

        //Create input node
        nodeChildNameTemp = "input";
        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
        //roomNameImageId = nodeDataTextRoom + "_Image";
        NodeElementChildTemp.setAttribute("id",groupImageId);
        NodeElementChildTemp.setAttribute("type","image");
        NodeElementChildTemp.setAttribute("class","image_scrollable");
        NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
        //NodeElementChildTemp.setAttribute("alt",floorNameId);
        OnClickText = "show_area_group(" "div_class_scrollable_Image,"
                                          "'" + groupImageId + "',"
                                          "div_class_scrollable_Hr,"
                                          "'" + groupHrId + "'," +
                                          "'" + groupClassName + "'," +
                                          "'" + groupTxtClassName + "')"
                                          ;
        NodeElementChildTemp.setAttribute("onclick",OnClickText);
        //Append image div to floor div
        NodeElementTemp.appendChild(NodeElementChildTemp);

        //Create paragraph node
        nodeChildNameTemp = "p";
        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
        //roomTxtId = nodeDataTextRoom + "_txt";
        NodeElementChildTemp.setAttribute("id",groupTxtId);
        NodeElementChildTemp.setAttribute("class","imgtxt");
        stringTxtNode = groupImageTxt;
        textNode = htmlDomDocument.createTextNode(stringTxtNode);
        //Append txt node
        NodeElementChildTemp.appendChild(textNode);
        //Append paragraph div to floor div
        NodeElementTemp.appendChild(NodeElementChildTemp);

        //Create hr node
        nodeChildNameTemp = "input";
        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
        //roomHrId = nodeDataTextRoom + "_Hr";
        NodeElementChildTemp.setAttribute("id",groupHrId);
        NodeElementChildTemp.setAttribute("class","hr_scrollable");
        //Append hr div to floor div
        NodeElementTemp.appendChild(NodeElementChildTemp);

        // Append floor div to div scrollable
        NodeElementSingleFloorDivScrollable.appendChild(NodeElementTemp);

        //add floor image ID
        scrollableImageArray += "\"" + groupImageId + "\""  ;
        // add HR line ID
        scrollableHrArray += "\"" + groupHrId + "\""  ;

        // check if it is last element to put in the array
        if((i+1) < groupsTotal)
        {
            scrollableImageArray += ",";
            //scrollableHrArray += ",";
        }

        scrollableHrArray += ",";

    }

    //create info node
    infoNodeName = "Info";
    nodeNameTemp = "div";
    NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
    NodeElementTemp.setAttribute("id",infoNodeName);
    NodeElementTemp.setAttribute("class","input");

       //Create input node
       nodeChildNameTemp = "input";
       NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
       roomNameImageId = infoNodeName + "_Image";
       NodeElementChildTemp.setAttribute("id",roomNameImageId);
       NodeElementChildTemp.setAttribute("type","image");
       NodeElementChildTemp.setAttribute("class","image_scrollable");
       NodeElementChildTemp.setAttribute("src","../lib/widgets/info/info.jpg");
       //NodeElementChildTemp.setAttribute("alt",floorNameId);
       //OnClickText = "alert('Info clicked')";
       OnClickText = "show_info(" "div_class_scrollable_Image,"
                                             "div_class_scrollable_Hr,"
                                             "'"  "Info_Hr" "',"   "'"  "info_text"  "')"
                                             ;
           //show_info(div_class_scrollable_Image,div_class_scrollable_Hr,'Info_Hr','info_text')
       NodeElementChildTemp.setAttribute("onclick",OnClickText);
       //Append image div to floor div
       NodeElementTemp.appendChild(NodeElementChildTemp);

       //Create paragraph node
       nodeChildNameTemp = "p";
       NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
       roomTxtId = infoNodeName + "_txt";
       NodeElementChildTemp.setAttribute("id",roomTxtId);
       NodeElementChildTemp.setAttribute("class","imgtxt");
       stringTxtNode = "info";
                textNode = htmlDomDocument.createTextNode(stringTxtNode);
                //Append txt node
                NodeElementChildTemp.appendChild(textNode);
       //Append paragraph div to floor div
       NodeElementTemp.appendChild(NodeElementChildTemp);

       //Create hr node
       nodeChildNameTemp = "input";
       NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
       roomHrId = infoNodeName + "_Hr";
       NodeElementChildTemp.setAttribute("id",roomHrId);
       NodeElementChildTemp.setAttribute("class","hr_scrollable");
       //Append hr div to floor div
       NodeElementTemp.appendChild(NodeElementChildTemp);

    // Append info div to div scrollable
    NodeElementSingleFloorDivScrollable.appendChild(NodeElementTemp);

    //Add Info HR array
    scrollableHrArray += "\"" + roomHrId + "\""  ;

    //htmlRoot.appendChild(NodeElement);

    //Append new line
    scrollableImageArray += "\n";
    //Terminate the array
    scrollableImageArray += "];";
    //Append new line
    scrollableImageArray += "\n";
    //Append new line
    scrollableImageArray += "\n";

    //Append new line
    scrollableHrArray += "\n";
    //Terminate the array
    scrollableHrArray += "];";
    //Append new line
    scrollableHrArray += "\n";
    //Append new line
    scrollableHrArray += "\n";

    floorCfgFileString = scrollableImageArray + scrollableHrArray ;
}

