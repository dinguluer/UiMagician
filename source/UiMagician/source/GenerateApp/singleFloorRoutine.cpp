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


/*
    Licence:
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version
    2 of the License, or (at your option) any later version.

    This file is part of the UiMagician Project (https://sites.google.com/site/uimagician/)

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this file see the file COPYING.  If not, write to
    the Free Software Foundation, 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.

    As a special exception, if other files instantiate templates or use macros
    or inline functions from this file, or you compile this file and link it
    with other works to produce a work based on this file, this file does not
    by itself cause the resulting work to be covered by the GNU General Public
    License. However the source code for this file must still be made available
    in accordance with section (3) of the GNU General Public License.

    This exception does not invalidate any other reasons why a work based on
    this file might be covered by the GNU General Public License.

    Alternative licenses for UiMagician may be arranged by contacting :--
    Tool Author : Dinesh Guleria
    din.gulu.er@gmail.com  https://sites.google.com/site/uimagician/
    Group : https://groups.google.com/forum/#!forum/uimagician
    Mailinglist : uimagician@googlegroups.com
*/



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

    QString houseScrollableImageArray;
    QString houseScrollableHrArray;

    QString floorName;

    QString houseName;

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

    QString homeGroupClass;

    QString HouseCentralAreaGroupImageClass;
    QString HouseCentralAreaGroupTxtClass;

    QString SingleFloorGroupImageClassName;
    QString SingleFloorGroupTxtClassName;

    bool sensorGraphGroup = 0;

    uint16_t houseIndex = 0;

    nodeName = "div";
    NodeElementSingleFloorDivScrollable  = htmlDomDocument.createElement(nodeName);
    NodeElementSingleFloorDivScrollable.setAttribute("id","images");
    NodeElementSingleFloorDivScrollable.setAttribute("class","scrollable");

/*
    scrollableImageArray     = "var div_class_scrollable_Image = [";
    scrollableHrArray        = "var div_class_scrollable_Hr = [";
    //Append new line
    scrollableImageArray += "\n";
    scrollableHrArray += "\n";
*/


    HouseCentralAreaGroupImageClass.clear();  // ----> error can be here
    HouseCentralAreaGroupTxtClass.clear();  // ----> error can be here

    // create multi house select Menu Button
    if(xmlType == MULTI_HOUSE)
    {
        nodeNameTemp = "div";
        NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
        NodeElementTemp.setAttribute("id","house_menu");
        NodeElementTemp.setAttribute("class","input");

        //Create input node
        nodeChildNameTemp = "input";
        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
        NodeElementChildTemp.setAttribute("id","house_menu_Image");
        NodeElementChildTemp.setAttribute("type","image");
        NodeElementChildTemp.setAttribute("class","image_scrollable");
        //NodeElementChildTemp.setAttribute("src","../lib/widgets/menu/show-menu-icon.png");
        if(appType == HTML_APP)
        {
            NodeElementChildTemp.setAttribute("src","../lib/widgets/menu/show-menu-icon.png");
        }
        else
        {
            NodeElementChildTemp.setAttribute("src","js/widgets/menu/show-menu-icon.png");
        }
        //NodeElementChildTemp.setAttribute("alt",floorNameId);
        OnClickText = "house_onclick()"
                ;
        NodeElementChildTemp.setAttribute("onclick",OnClickText);
        //Append image div to floor div
        NodeElementTemp.appendChild(NodeElementChildTemp);

        //Create paragraph node
        nodeChildNameTemp = "p";
        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
        NodeElementChildTemp.setAttribute("id","house_menu_txt");
        NodeElementChildTemp.setAttribute("class","imgtxt");
        stringTxtNode = "Houses";
        textNode = htmlDomDocument.createTextNode(stringTxtNode);
        //Append txt node
        NodeElementChildTemp.appendChild(textNode);
        //Append paragraph div to floor div
        NodeElementTemp.appendChild(NodeElementChildTemp);

        //Create hr node
        nodeChildNameTemp = "input";
        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
        //roomHrId = houseName + "_" + nodeDataTextRoom + "_Hr";
        NodeElementChildTemp.setAttribute("id","house_menu_Hr");
        NodeElementChildTemp.setAttribute("class","hr_scrollable");
        //Append hr div to floor div
        NodeElementTemp.appendChild(NodeElementChildTemp);

        // Append floor div to div scrollable
        NodeElementSingleFloorDivScrollable.appendChild(NodeElementTemp);

    }

    //clear the house scrollable error
    houseScrollableImageArray.clear();
    houseScrollableHrArray.clear();

    houseScrollableImageArray     = "var house_div_class_scrollable_Image = [";
    houseScrollableHrArray        = "var house_div_class_scrollable_Hr = [";
    //Append new line
    houseScrollableImageArray += "\n";
    houseScrollableHrArray += "\n";

    HouseCentralAreaGroupImageClass = "var house_central_Area_Group_Image_class = [";
    HouseCentralAreaGroupTxtClass = "var house_central_Area_Group_txt_class = [";
    //Append new line
    HouseCentralAreaGroupImageClass += "\n";
    HouseCentralAreaGroupTxtClass += "\n";


    // Create house zones icon
    for (int j = 0; j < houseNodesList.size(); ++j)
    {
        houseName = houseNodesList.at(j).houseName;

        //save home index
        houseIndex = j;

        scrollableImageArray.clear();
        scrollableHrArray.clear();
        scrollableImageArray     = "var " + houseName + "_div_class_scrollable_Image = [";
        scrollableHrArray        = "var " + houseName + "_div_class_scrollable_Hr = [";
        //Append new line
        scrollableImageArray += "\n";
        scrollableHrArray += "\n";

        // add HR line ID
        houseScrollableImageArray +=  houseName + "_div_class_scrollable_Image";
        houseScrollableHrArray +=  houseName + "_div_class_scrollable_Hr";

        // check if it is last element to put in the array
        if((j+1) < houseNodesList.size())
        {
            houseScrollableImageArray += ",";
            houseScrollableHrArray += ",";
        }


        //This loop will run 1 time as floorlist.size() is --> 1
        //for (int i = 0; i < floorList.size(); ++i)
        for (int i = 0; i < houseNodesList.at(j).floorNodeList.size(); ++i)
        {

            //--->>> todo
            //floorName = floorList.at(i);
            floorName = houseNodesList.at(j).floorNodeList.at(i).floorName;

            //floorNodes = floorNodesList.at(0);
            floorNodes = houseNodesList.at(j).floorNodeList.at(i);

            //Load root nodes
            listRooms = floorNodes.floorRooms.childNodes();


            //reInitialise global variables
            reInitializeGlobalVariables();
            //Reinitialise for new house
            sensorGraphGroup = 0;

            //--->>> todo
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
                homeGroupClass = houseName + "_group_class " "input";
                NodeElementTemp.setAttribute("class",homeGroupClass);

                //Create input node
                nodeChildNameTemp = "input";
                NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                roomNameImageId = houseName + "_" + nodeDataTextRoom + "_Image";
                NodeElementChildTemp.setAttribute("id",roomNameImageId);
                NodeElementChildTemp.setAttribute("type","image");
                NodeElementChildTemp.setAttribute("class","image_scrollable");
                //NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
                if(appType == HTML_APP)
                {
                    NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
                }
                else
                {
                    NodeElementChildTemp.setAttribute("src","js/widgets/room/room_unselected.png");
                }

                //NodeElementChildTemp.setAttribute("alt",floorNameId);
                OnClickText = "show_area_single(" "div_class_scrollable_Image,"
                        "'" + roomNameImageId + "',"
                        "div_class_scrollable_Hr,"
                        "'" + houseName + "_" + nodeDataTextRoom + "_Hr" "'," +
                        "'" + houseName + "_" + floorName + "_Floor"  "_Area_" + nodeDataTextRoom + "')"
                        ;
                NodeElementChildTemp.setAttribute("onclick",OnClickText);
                //Append image div to floor div
                NodeElementTemp.appendChild(NodeElementChildTemp);

                //Create paragraph node
                nodeChildNameTemp = "p";
                NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                roomTxtId = houseName + "_" + nodeDataTextRoom + "_txt";
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
                roomHrId = houseName + "_" + nodeDataTextRoom + "_Hr";
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


        //QMessageBox::information(this, "uiMagician", "two");

        //Get the Total number of groups
        //getTotalGroups(houseNodesList.at(j).floorNodeList);
        // Pss the index of the house list
        getTotalGroups(j);

        //QMessageBox::information(this, "uiMagician", "three___");
        //Create group config array
        SingleFloorGroupImageClass.clear(); // ----> error can be here
        SingleFloorGroupImageClass = "\n";
        SingleFloorGroupImageClass += "\n";
        SingleFloorGroupImageClass += "var " + houseName + "_" + "central_Area_Group_Image_class = [";
        SingleFloorGroupImageClassName = houseName + "_" + "central_Area_Group_Image_class";
        SingleFloorGroupImageClass += "\n" ;

        SingleFloorGroupTxtClass.clear();  // ----> error can be here
        SingleFloorGroupTxtClass = "\n";
        SingleFloorGroupTxtClass += "\n";
        SingleFloorGroupTxtClass += "var " + houseName + "_" + "central_Area_Group_txt_class = [";
        SingleFloorGroupTxtClassName = houseName + "_" + "central_Area_Group_txt_class";
        SingleFloorGroupTxtClass += "\n" ;

        //HouseCentralAreaGroupImageClass.clear();  // ----> error can be here
        //HouseCentralAreaGroupImageClass += "\n";
        //HouseCentralAreaGroupTxtClass.clear();  // ----> error can be here
        //HouseCentralAreaGroupTxtClass += "\n";

        if(flagsensorGroup == 1)
        {
            sensorGraphGroup = 1;
        }

        //create Group nodes
        for (int i = 0; i < houseNodesList.at(j).groupsTotal; ++i)
        {

            if(flagLightsGroup == 1)
            {
                groupDivId = "group_Light_Button_" + houseName;
                groupImageId = "group_Light_Image_" + houseName;
                groupHrId = "group_Light_Hr_" + houseName;
                groupClassName = "group_Lights_" + houseName;
                groupTxtClassName = "group_Light_Txt_" + houseName;
                groupTxtId = "group_Light_Txt_Id_" + houseName;
                groupImageTxt = "Lights";

                flagLightsGroup = 0;

            }
            else if(flagAccessoriesGroup == 1)
            {
                groupDivId = "group_Accessories_Button_" + houseName;
                groupImageId = "group_Accessories_Image_" + houseName;
                groupHrId = "group_Accessories_Hr_" + houseName;
                groupClassName = "group_Accessories_" + houseName;
                groupTxtClassName = "group_Accessories_Txt_" + houseName;
                groupTxtId = "group_Accessories_Txt_Id_" + houseName;
                groupImageTxt = "Accessories";

                flagAccessoriesGroup = 0;

            }
            else if(flagBlindDoorWindowGroup == 1)
            {
                groupDivId = "group_Blinds_Windows_Button_" + houseName;
                groupImageId = "group_Blinds_Windows_Image_" + houseName;
                groupHrId = "group_Blinds_Windows_Hr_" + houseName;
                groupClassName = "group_Blinds_Windows_" + houseName;
                groupTxtClassName = "group_Blinds_Windows_Txt_" + houseName;
                groupTxtId = "group_Blinds_Windows_Txt_Id_" + houseName;
                groupImageTxt = "Door Window";

                flagBlindDoorWindowGroup = 0;

            }
            else if(flagsensorGroup == 1)
            {
                groupDivId = "group_Sensors_Button_" + houseName;
                groupImageId = "group_Sensors_Image_" + houseName;
                groupHrId = "group_Sensors_Hr_" + houseName;
                groupClassName = "group_Sensors_" + houseName;
                groupTxtClassName = "group_Sensors_Txt_" + houseName;
                groupTxtId = "group_Sensors_Txt_Id_" + houseName;
                groupImageTxt = "Sensors";

                flagsensorGroup = 0;

            }
            else if(flagTemperatureControllerGroup == 1)
            {
                groupDivId = "group_Temperature_control_Button_" + houseName;
                groupImageId = "group_Temperature_control_Image_" + houseName;
                groupHrId = "group_Temperature_control_Hr_" + houseName;
                groupClassName = "group_Temperature_control_" + houseName;
                groupTxtClassName = "group_Temperature_control_Txt_" + houseName;
                groupTxtId = "group_Temperature_control_Txt_Id_" + houseName;
                groupImageTxt = "Temperature control";

                flagTemperatureControllerGroup = 0;

            }
            else
            {
                // Do nothing
            }

            SingleFloorGroupImageClass += "\"" + groupClassName + "\"" ;
            SingleFloorGroupTxtClass   += "\"" + groupTxtClassName + "\"" ;
            if((i+1) == houseNodesList.at(j).groupsTotal)
            {
                //Do not append -- ","
                SingleFloorGroupImageClass += "\n" ;
                SingleFloorGroupImageClass += "];" ;
                SingleFloorGroupImageClass += "\n" ;
                SingleFloorGroupImageClass += "\n" ;

                //Do not append -- ","
                SingleFloorGroupTxtClass += "\n" ;
                SingleFloorGroupTxtClass += "];" ;
                SingleFloorGroupTxtClass += "\n" ;
                SingleFloorGroupTxtClass += "\n" ;
            }
            else
            {
                SingleFloorGroupImageClass += "," ;
                SingleFloorGroupTxtClass += "," ;

            }

            nodeNameTemp = "div";
            NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
            NodeElementTemp.setAttribute("id",groupDivId);
            homeGroupClass = houseName + "_group_class " "input";
            NodeElementTemp.setAttribute("class",homeGroupClass);

            //Create input node
            nodeChildNameTemp = "input";
            NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
            //roomNameImageId = nodeDataTextRoom + "_Image";
            NodeElementChildTemp.setAttribute("id",groupImageId);
            NodeElementChildTemp.setAttribute("type","image");
            NodeElementChildTemp.setAttribute("class","image_scrollable");
            //NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
            if(appType == HTML_APP)
            {
                NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
            }
            else
            {
                NodeElementChildTemp.setAttribute("src","js/widgets/room/room_unselected.png");
            }
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
            if((i+1) < houseNodesList.at(j).groupsTotal)
            {
                scrollableImageArray += ",";
                //scrollableHrArray += ",";
            }
            else
            {
                // put comma if graph have to be added
                if(sensorGraphGroup == 1)
                {
                    scrollableImageArray += ",";
                }
            }

            scrollableHrArray += ",";

        }

        if(sensorGraphGroup == 1)
        {
            groupDivId = "group_sensors_Graph_" + houseName;
            groupImageId = "group_sensor_graph_Image_" + houseName;

            groupImageTxt = "Sensors Graph";
            groupHrId = "group_sensor_graph_Hr_" + houseName;

            groupClassName = "group_sensor_graph_" + houseName;
            groupTxtId = "group_sensors_Graph_txt_" + houseName;

            nodeNameTemp = "div";
            NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
            NodeElementTemp.setAttribute("id",groupDivId);
            homeGroupClass = houseName + "_group_class " "input";
            NodeElementTemp.setAttribute("class",homeGroupClass);

            //Create input node
            nodeChildNameTemp = "input";
            NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
            //roomNameImageId = nodeDataTextRoom + "_Image";
            NodeElementChildTemp.setAttribute("id",groupImageId);
            NodeElementChildTemp.setAttribute("type","image");
            NodeElementChildTemp.setAttribute("class","image_scrollable");
            //NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
            if(appType == HTML_APP)
            {
                NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
            }
            else
            {
                NodeElementChildTemp.setAttribute("src","js/widgets/room/room_unselected.png");
            }
            //NodeElementChildTemp.setAttribute("alt",floorNameId);
            OnClickText = "show_area_single(" "div_class_scrollable_Image,"
                    "'" + groupImageId + "',"
                    "div_class_scrollable_Hr,"
                    "'" + groupHrId + "'," +
                    "'" + groupClassName + "')"
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


            scrollableHrArray += ",";
        }

        //create info node
        infoNodeName = "Info_" + houseName;
        nodeNameTemp = "div";
        NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
        NodeElementTemp.setAttribute("id",infoNodeName);
        homeGroupClass = houseName + "_group_class " "input";
        NodeElementTemp.setAttribute("class",homeGroupClass);

        //Create input node
        nodeChildNameTemp = "input";
        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
        roomNameImageId = infoNodeName + "_Image";
        NodeElementChildTemp.setAttribute("id",roomNameImageId);
        NodeElementChildTemp.setAttribute("type","image");
        NodeElementChildTemp.setAttribute("class","image_scrollable");
        //NodeElementChildTemp.setAttribute("src","../lib/widgets/info/info.jpg");
        if(appType == HTML_APP)
        {
            NodeElementChildTemp.setAttribute("src","../lib/widgets/info/info.jpg");
        }
        else
        {
            NodeElementChildTemp.setAttribute("src","js/widgets/info/info.jpg");
        }
        //NodeElementChildTemp.setAttribute("alt",floorNameId);
        //OnClickText = "alert('Info clicked')";
        OnClickText = "show_info(" "div_class_scrollable_Image,"
                "div_class_scrollable_Hr,"
                "'"  "Info_" + houseName + "_Hr" + "',"   "'"  "info_text_" + houseName + "',"
                "'"  + houseName + "'," +  QString::number(houseIndex) + ")"
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

        // Append scrollable Image & HR array
        floorCfgFileString += scrollableImageArray + scrollableHrArray ;


        // --> could be an error
        // Append house group image & txt class
        floorCfgFileString += SingleFloorGroupImageClass;
        floorCfgFileString += SingleFloorGroupTxtClass;

        HouseCentralAreaGroupImageClass += SingleFloorGroupImageClassName;
        HouseCentralAreaGroupTxtClass += SingleFloorGroupTxtClassName;

        // check if it is last element to put in the array
        if((j+1) == houseNodesList.size())
        {
            //Do not append -- ","
            HouseCentralAreaGroupImageClass += "\n" ;
            HouseCentralAreaGroupImageClass += "];" ;
            HouseCentralAreaGroupImageClass += "\n" ;
            HouseCentralAreaGroupImageClass += "\n" ;

            //Do not append -- ","
            HouseCentralAreaGroupTxtClass += "\n" ;
            HouseCentralAreaGroupTxtClass += "];" ;
            HouseCentralAreaGroupTxtClass += "\n" ;
            HouseCentralAreaGroupTxtClass += "\n" ;
        }
        else
        {
            HouseCentralAreaGroupImageClass += ",";
            HouseCentralAreaGroupTxtClass += ",";
        }

    }


    //QMessageBox::information(this, "uiMagician", HouseCentralAreaGroupImageClass);
    floorCfgFileString += HouseCentralAreaGroupImageClass;
    floorCfgFileString += HouseCentralAreaGroupTxtClass;


    //Append new line
    houseScrollableImageArray += "\n";
    //Terminate the array
    houseScrollableImageArray += "];";
    //Append new line
    houseScrollableImageArray += "\n";
    //Append new line
    houseScrollableImageArray += "\n";

    //Append new line
    houseScrollableHrArray += "\n";
    //Terminate the array
    houseScrollableHrArray += "];";
    //Append new line
    houseScrollableHrArray += "\n";
    //Append new line
    houseScrollableHrArray += "\n";

    // append array of array
    floorCfgFileString += houseScrollableImageArray + houseScrollableHrArray ;

}
