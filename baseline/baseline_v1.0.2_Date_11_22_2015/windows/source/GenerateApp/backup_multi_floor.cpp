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

/*
//Create floor room list
void GenerateApp::createFloorRoomList()
{
    QString floorName;
    QDomNode tempNodeChild;
    QDomNode tempNodeChildClone;
    T_packetFloorNodes floorNodes;

    QDomNodeList listChild;
    QString nodeDataTextFloor;

    //Serch if floor name is in list
    for (int i = 0; i < floorList.size(); ++i)
    {
        floorName = floorList.at(i);
        // root have Test Case nodes
        if(list.count() != 0)
        {
            // Enter the floor name
            floorNodes.floorName = floorName;
            // clear the floornodes rooms DOM
            floorNodes.floorRooms.clear();
            // create the node
            floorNodes.floorRooms = htmlDomDocument.createElement("Rooms");

            for(int j =0; j< list.count() ; j++)
            {
                //read the child node from list
                tempNodeChild = list.at(j);

                // Create list of child nodes of - test case
                listChild = tempNodeChild.childNodes();

                //Read floor name from node
                tempNodeChild = listChild.at(FLOOR_NAME_INDEX);
                if (!tempNodeChild.isNull())
                {
                    nodeDataTextFloor = tempNodeChild.toElement().text();
                }
                else
                {
                    nodeDataTextFloor = "";
                }

                //Append the floor name list
                if(floorName == nodeDataTextFloor)
                {
                    tempNodeChildClone = list.at(j).cloneNode();
                    //qDebug() << "one";
                    floorNodes.floorRooms.appendChild(tempNodeChildClone);
                    //qDebug() << "two";
                }
            }

            floorNodesList.append(floorNodes);
        }
    }

}*/


//Create floor room list
void GenerateApp::createFloorRoomList(QList<T_packetHouse> &housePacketList, QDomElement &xmlRoot)
{
    QDomNode domNodeChild;

    T_packetFloor floorPacketNode;
    T_packetHouse housePacketNode;

    T_packetHouseNodes houseNodes;
    T_packetFloorNodes floorNode;

    QDomNodeList listchildNodes;
    listchildNodes = xmlRoot.childNodes();

    int tempInd = 0;

    /* **** prepare sorted XML node  **** */
    for (int indexHouse = 0; indexHouse < housePacketList.size(); ++indexHouse)
    {

        houseNodes.houseName = "";
        houseNodes.floorNodeList.clear();

        housePacketNode = housePacketList.at(indexHouse);

        // save house name
        houseNodes.houseName = housePacketNode.houseName;

        //Itterate floor list for each house
        for (int indexfloor = 0; indexfloor < housePacketNode.houseFloorList.count(); ++indexfloor)
        {
            floorPacketNode =  housePacketNode.houseFloorList.at(indexfloor);

            //save floor name
            floorNode.floorName = floorPacketNode.floorName;
            // clear the floornodes rooms DOM
            floorNode.floorRooms.clear();
            // create the node
            floorNode.floorRooms = htmlDomDocument.createElement("Rooms");

            //Ittergate indivisual nodes with same floor name
            for (int index = 0; index < floorPacketNode.floorIndexList.size(); ++index)
            {
                listchildNodes = xmlRoot.childNodes();

                tempInd= floorPacketNode.floorIndexList.at(index);
                //list.
                domNodeChild = listchildNodes.at(tempInd).cloneNode(true);

                //QMessageBox::information(this, "name", "1");
                //append to the sorted XML
                floorNode.floorRooms.appendChild(domNodeChild);
                //QMessageBox::information(this, "name", "2");
                //  xmlRootSorted.appendChild(domNodeChild);
                //xmlRootSorted.appendChild(xmlRoot.childNodes().at(tempIndex));

            }
            //append house floor
            houseNodes.floorNodeList.append(floorNode);
        }

        houseNodesList.append(houseNodes);

        //QMessageBox::information(this, "tt -> name", houseNodes.houseName);
        //QMessageBox::information(this, "tt -> name", floorPacketNode.floorName);
        //QMessageBox::information(this, "tt -> floor size", QString::number(houseNodes.floorNodeList.count()));
        //QMessageBox::information(this, "tt -> floor size", QString::number(houseNodes.floorNodeList.floorRooms.childNodes().count()));
    }

}


// Create the multi floor DIV scrollable
void GenerateApp::createMultiFloorDivScrollable(QDomElement &NodeElementMultiFloorDivScrollable)
{
    QDomElement NodeElementTemp;
    QDomElement NodeElementChildTemp;
    QString nodeNameTemp;
    QString nodeChildNameTemp;

    QString floorNameId;
    QString floorNameImageId;
    QString floorTxtId;
    QString floorHrId;

    QString OnClickText;
    QString floorArea;

    QString scrollableImageArray;
    QString scrollableHrArray;
    QString scrollableFloorAreaArray;

    QString floorName;

    T_packetFloorNodes floorNodes;

    QDomNodeList listRooms;

    QString nodeDataTextRoom;
    QDomNode tempNodeChild;
    QDomNodeList listChild;


    nodeName = "div";
    NodeElementMultiFloorDivScrollable  = htmlDomDocument.createElement(nodeName);
    NodeElementMultiFloorDivScrollable.setAttribute("id","images");
    NodeElementMultiFloorDivScrollable.setAttribute("class","scrollable");

    scrollableImageArray     = "var div_class_scrollable_Image = [";
    scrollableHrArray        = "var div_class_scrollable_Hr = [";
    scrollableFloorAreaArray = "var floor_area_id = [";
    //Append new line
    scrollableImageArray += "\n";
    scrollableHrArray += "\n";
    scrollableFloorAreaArray += "\n";

    for (int i = 0; i < floorList.size(); ++i)
    {

      floorName = floorList.at(i);

      //get room name in list
      for (int t = 0; t < floorNodesList.size(); ++t)
      {
          floorNodes = floorNodesList.at(t);

          if(floorNodes.floorName != floorName)
          {
              continue;
          }

          //Load root nodes
          listRooms = floorNodes.floorRooms.childNodes();

          //read the child node from list
          tempNodeChild = listRooms.at(0);

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

          break;
      }

      floorName.replace(" ", "");
      floorName.remove(QRegExp("[^a-zA-Z\\d\\s]"));

      floorNameId = floorName + "_Floor";
      // create floor node
      nodeNameTemp = "div";
      NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
      NodeElementTemp.setAttribute("id",floorNameId);
      NodeElementTemp.setAttribute("class","input");

         //Create input node
         nodeChildNameTemp = "input";
         NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
         floorNameImageId = floorNameId + "_Image";
         NodeElementChildTemp.setAttribute("id",floorNameImageId);
         NodeElementChildTemp.setAttribute("type","image");
         NodeElementChildTemp.setAttribute("class","image_scrollable");
         NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
         //NodeElementChildTemp.setAttribute("alt",floorNameId);
         floorArea = floorNameId  + "_Area";
         OnClickText = "show_area(" "'" + floorArea + "',"
                                    "div_class_scrollable_Image,"
                                    "'" + floorNameImageId + "',"
                                    "div_class_scrollable_Hr,"
                                    "'" + floorNameId + "_Hr" "'," +
                                    "'" + floorArea + "_" + nodeDataTextRoom + "',"
                                    "div_class_" + floorArea + "_Images" ","
                                    "'" + floorArea + "_" + nodeDataTextRoom  + "_Image" "')"
                                  ;
         NodeElementChildTemp.setAttribute("onclick",OnClickText);
         //Append image div to floor div
         NodeElementTemp.appendChild(NodeElementChildTemp);

         //Create paragraph node
         nodeChildNameTemp = "p";
         NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
         floorTxtId = floorNameId + "_txt";
         NodeElementChildTemp.setAttribute("id",floorTxtId);
         NodeElementChildTemp.setAttribute("class","imgtxt");
                  stringTxtNode = floorName;
                  textNode = htmlDomDocument.createTextNode(stringTxtNode);
                  //Append txt node
                  NodeElementChildTemp.appendChild(textNode);
         //Append paragraph div to floor div
         NodeElementTemp.appendChild(NodeElementChildTemp);

         //Create hr node
         nodeChildNameTemp = "input";
         NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
         floorHrId = floorNameId + "_Hr";
         NodeElementChildTemp.setAttribute("id",floorHrId);
         NodeElementChildTemp.setAttribute("class","hr_scrollable");
         //Append hr div to floor div
         NodeElementTemp.appendChild(NodeElementChildTemp);

      // Append floor div to div scrollable
      NodeElementMultiFloorDivScrollable.appendChild(NodeElementTemp);

      //add floor image ID
      scrollableImageArray += "\"" + floorNameImageId + "\""  ;
      // add HR line ID
      scrollableHrArray += "\"" + floorHrId + "\""  ;
      // add floor area ID
      scrollableFloorAreaArray += "\"" + floorArea + "\""  ;

      // check if it is last element to put in the array
      //if((i+1) < floorList.size())
      //{
          scrollableImageArray += ",";
          scrollableHrArray += ",";
          scrollableFloorAreaArray += ",";
      //}

    }

    //==============================================================


    //create all device node
    floorNameId = "All_Devices";
    nodeNameTemp = "div";
    NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
    NodeElementTemp.setAttribute("id",floorNameId);
    NodeElementTemp.setAttribute("class","input");

       //Create input node
       nodeChildNameTemp = "input";
       NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
       floorNameImageId = floorNameId + "_Image";
       NodeElementChildTemp.setAttribute("id",floorNameImageId);
       NodeElementChildTemp.setAttribute("type","image");
       NodeElementChildTemp.setAttribute("class","image_scrollable");
       NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
       //NodeElementChildTemp.setAttribute("alt",floorNameId);
       OnClickText = "show_group(" "'" + floorNameId + "_group" "'," +
                                   "'" + floorNameId + "_Image" "'," +
                                   "'" + floorNameId + "_Hr" "')"
                                ;
       NodeElementChildTemp.setAttribute("onclick",OnClickText);
       //Append image div to floor div
       NodeElementTemp.appendChild(NodeElementChildTemp);

       //Create paragraph node
       nodeChildNameTemp = "p";
       NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
       floorTxtId = floorNameId + "_txt";
       NodeElementChildTemp.setAttribute("id",floorTxtId);
       NodeElementChildTemp.setAttribute("class","imgtxt");
       stringTxtNode = "Groups";
                textNode = htmlDomDocument.createTextNode(stringTxtNode);
                //Append txt node
                NodeElementChildTemp.appendChild(textNode);
       //Append paragraph div to floor div
       NodeElementTemp.appendChild(NodeElementChildTemp);

       //Create hr node
       nodeChildNameTemp = "input";
       NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
       floorHrId = floorNameId + "_Hr";
       NodeElementChildTemp.setAttribute("id",floorHrId);
       NodeElementChildTemp.setAttribute("class","hr_scrollable");
       //Append hr div to floor div
       NodeElementTemp.appendChild(NodeElementChildTemp);

    // Append info div to div scrollable
    NodeElementMultiFloorDivScrollable.appendChild(NodeElementTemp);


      floorArea = floorNameId + "_group";
      //add floor image ID
      scrollableImageArray += "\"" + floorNameImageId + "\""  ;
      // add HR line ID
      scrollableHrArray += "\"" + floorHrId + "\""  ;
      // add floor area ID
      scrollableFloorAreaArray += "\"" + floorArea + "\""  ;


    //==============================================================

    //create info node
    floorNameId = "Info";
    nodeNameTemp = "div";
    NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
    NodeElementTemp.setAttribute("id",floorNameId);
    NodeElementTemp.setAttribute("class","input");

       //Create input node
       nodeChildNameTemp = "input";
       NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
       floorNameImageId = floorNameId + "_Image";
       NodeElementChildTemp.setAttribute("id",floorNameImageId);
       NodeElementChildTemp.setAttribute("type","image");
       NodeElementChildTemp.setAttribute("class","image_scrollable");
       NodeElementChildTemp.setAttribute("src","../lib/widgets/info/info.jpg");
       //NodeElementChildTemp.setAttribute("alt",floorNameId);
       //OnClickText = "alert('Info clicked')";
       OnClickText = "show_info(" "'"  "info_text"  "',"
                                         "div_class_scrollable_Image,"
                                         "div_class_scrollable_Hr,"
                                         "'"  "Info_Hr" "')"
                                         ;
       //show_info('info_text',div_class_scrollable_Image,div_class_scrollable_Hr,'Info_Hr')
       NodeElementChildTemp.setAttribute("onclick",OnClickText);
       //Append image div to floor div
       NodeElementTemp.appendChild(NodeElementChildTemp);

       //Create paragraph node
       nodeChildNameTemp = "p";
       NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
       floorTxtId = floorNameId + "_txt";
       NodeElementChildTemp.setAttribute("id",floorTxtId);
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
       floorHrId = floorNameId + "_Hr";
       NodeElementChildTemp.setAttribute("id",floorHrId);
       NodeElementChildTemp.setAttribute("class","hr_scrollable");
       //Append hr div to floor div
       NodeElementTemp.appendChild(NodeElementChildTemp);

    // Append info div to div scrollable
    NodeElementMultiFloorDivScrollable.appendChild(NodeElementTemp);

    scrollableHrArray += ",";
    scrollableHrArray += "\"" + floorHrId + "\""  ;

    //htmlRoot.appendChild(NodeElement);

    //add floor image ID
    //scrollableImageArray += "\"" + floorNameImageId + "\""  ;
    // add HR line ID
    //scrollableHrArray += "\"" + floorHrId + "\""  ;

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

    //Append new line
    scrollableFloorAreaArray += "\n";
    //Terminate the array
    scrollableFloorAreaArray += "];";
    //Append new line
    scrollableFloorAreaArray += "\n";
    //Append new line
    scrollableFloorAreaArray += "\n";
    // append scrollableImageArray & floorHrId
    floorCfgFileString = scrollableImageArray + scrollableHrArray + scrollableFloorAreaArray;
}


// Create the multi floor DIV scrollableMenu
void GenerateApp::createMultiFloorDivScrollableMenu(QDomElement &NodeElementMultiFloorDivScrollableMenu)
{
    QString scrollableMenuImageArray;
    QString scrollableMenuTxtArray;
    QString scrollableMenuHouseGroupsImageIdArray;
    QString centralAreaGroupImageClass;
    QString centralAreaGroupFloorTxtClass;

    QDomElement NodeElementTemp;
    QDomElement NodeElementChildTemp;
    QString nodeNameTemp;
    QString nodeChildNameTemp;
    QString floorNameArea;

    T_packetFloorNodes floorNodes;

    QString floorName;
    QString deviceInfo;
    QDomNodeList listRooms;
    QDomNodeList listDevices;
    QDomNodeList listDeviceDetails;

    QString nodeDataTextRoom;
    QDomNode tempNodeChild;
    QDomNodeList listChild;

    QString OnClickText;

    QString roomNameImageId;
    QString roomTxtId;

    uint16_t lightsFloorTotal;
    uint16_t accessoriesFloorTotal;
    uint16_t blindDoorWindowFloorTotal;
    uint16_t sensorFloorTotal;
    uint16_t temperatureControllerFloorTotal;

    bool flagLightsFloor;
    bool flagAccessoriesFloor;
    bool flagBlindDoorWindowFloor;
    bool flagsensorFloor;
    bool flagTemperatureControllerFloor;
    uint16_t groupsFloorTotal;

    bool flagSensorGraphFloor;

    QString groupDivId;
    QString groupImageId;
    QString groupTxtId;
    QString groupImageTxt;
    QString groupClass;

    nodeName = "div";
    NodeElementMultiFloorDivScrollableMenu  = htmlDomDocument.createElement(nodeName);
    NodeElementMultiFloorDivScrollableMenu.setAttribute("id","Menu");
    NodeElementMultiFloorDivScrollableMenu.setAttribute("class","scrollableMenu");

    //get floor name in list
    for (int i = 0; i < floorNodesList.size(); ++i)
    {

      floorNodes = floorNodesList.at(i);

      floorName = floorNodes.floorName;
      floorName.replace(" ", "");
      floorName.remove(QRegExp("[^a-zA-Z\\d\\s]"));

      floorNameArea = floorName + "_Floor_Area";

      //Load root nodes
      listRooms = floorNodes.floorRooms.childNodes();

      scrollableMenuImageArray.clear();
      scrollableMenuTxtArray.clear();

      scrollableMenuImageArray = "var div_class_" + floorNameArea + "_Images = [";
      scrollableMenuImageArray += "\n";

      scrollableMenuTxtArray = "var div_class_" + floorNameArea + "_Txt = [";
      scrollableMenuTxtArray += "\n";

      //get floor name in list
      for (int j = 0; j < listRooms.size(); ++j)
      {

        // create floor node
        nodeNameTemp = "div";
        NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
        NodeElementTemp.setAttribute("class",floorNameArea);

        //read the child node from list
        tempNodeChild = listRooms.at(j);

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

           //Create input node
           nodeChildNameTemp = "input";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           roomNameImageId = floorNameArea + "_"+ nodeDataTextRoom + "_Image";
           NodeElementChildTemp.setAttribute("id",roomNameImageId);
           NodeElementChildTemp.setAttribute("type","image");
           if(j == 0)
           {
               NodeElementChildTemp.setAttribute("class","image_menu_center_first");
               NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_selected.jpg");
           }
           else
           {
               NodeElementChildTemp.setAttribute("class","image_menu_center_second");
               NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
           }
           OnClickText = "show_Central_widget(" "'" + floorNameArea + "_" + nodeDataTextRoom + "',"
                                      "div_class_" + floorNameArea + "_Images" ","
                                      "'" + floorNameArea + "_" + nodeDataTextRoom  + "_Image" "')"
                                      ;
           NodeElementChildTemp.setAttribute("onclick",OnClickText);
           //NodeElementChildTemp.setAttribute("alt",roomNameImageId);
           //Append image div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

           //Create paragraph node
           nodeChildNameTemp = "p";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           roomTxtId = floorNameArea  + "_" + nodeDataTextRoom + "_txt";
           NodeElementChildTemp.setAttribute("id",roomTxtId);
           NodeElementChildTemp.setAttribute("class","imgtxt_scrollmenu");
                    stringTxtNode = nodeDataTextRoom;
                    textNode = htmlDomDocument.createTextNode(stringTxtNode);
                    //Append txt node
                    NodeElementChildTemp.appendChild(textNode);
           //Append paragraph div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

           //Create Hr node
           nodeChildNameTemp = "hr";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           //Append horizontal line div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

        // Append floor div to div scrollable
        NodeElementMultiFloorDivScrollableMenu.appendChild(NodeElementTemp);

        scrollableMenuImageArray += "\"" + roomNameImageId + "\"";
        scrollableMenuTxtArray += "\"" + roomTxtId + "\"";
        // check if it is last element to put in the array
        //if((j+1) < listRooms.size())
        //{
            scrollableMenuImageArray += ",";
            scrollableMenuTxtArray += ",";
        //}

      }

      lightsFloorTotal = 0;
      accessoriesFloorTotal = 0;
      blindDoorWindowFloorTotal = 0;
      sensorFloorTotal = 0;
      temperatureControllerFloorTotal = 0;

      flagLightsFloor = 0;
      flagAccessoriesFloor = 0;
      flagBlindDoorWindowFloor = 0;
      flagsensorFloor = 0;
      flagTemperatureControllerFloor = 0;
      groupsFloorTotal = 0;


      //get total device group for current floor
      for (int j = 0; j < listRooms.size(); ++j)
      {
          //read the child node from room list
          tempNodeChild = listRooms.at(j);

          // Create list of child nodes of - Every room
          listDevices = tempNodeChild.childNodes();

          for (int k = DEVICE_INDEX; k < listDevices.size(); ++k)
          {
              //read the Device child node from device list
              tempNodeChild = listDevices.at(k);
              // Create list nodes of - Every DEVICE
              listDeviceDetails = tempNodeChild.childNodes();

              //Get device Info node
              tempNodeChild = listDeviceDetails.at(DEVICE_INFO_INDEX);
              if (!tempNodeChild.isNull())
              {
                  deviceInfo = tempNodeChild.toElement().text();
              }
              else
              {
                  deviceInfo = "";
              }

              // If device type is light
              if(deviceInfo == DEVICE_INFO_TYPE_ONE)
              {
                  lightsFloorTotal++;
                  lightsGroupTotal++;
              }
              else if (deviceInfo == DEVICE_INFO_TYPE_TWO)
              {
                  accessoriesFloorTotal++;
                  accessoriesGroupTotal++;
              }
              else if (deviceInfo == DEVICE_INFO_TYPE_THREE)
              {
                  blindDoorWindowFloorTotal++;
                  blindDoorWindowGroupTotal++;
              }
              else if (deviceInfo == DEVICE_INFO_TYPE_FOUR)
              {
                  sensorFloorTotal++;
                  sensorGroupTotal++;
              }
              else if (deviceInfo == DEVICE_INFO_TYPE_FIVE)
              {
                  temperatureControllerFloorTotal++;
                  temperatureControllerGroupTotal++;
              }
              else
              {
                  //Do nothing
              }


          }
      }

      // Check which group to create
      if(lightsFloorTotal>0)
      {
          groupsFloorTotal++;
          flagLightsFloor = 1;
      }
      if(accessoriesFloorTotal>0)
      {
          groupsFloorTotal++;
          flagAccessoriesFloor = 1;
      }
      if(blindDoorWindowFloorTotal>0)
      {
          groupsFloorTotal++;
          flagBlindDoorWindowFloor = 1;
      }
      if(sensorFloorTotal>0)
      {
          groupsFloorTotal++;
          flagsensorFloor = 1;
          // make a graph
          flagSensorGraphFloor = 1;
      }
      if(temperatureControllerFloorTotal>0)
      {
          groupsFloorTotal++;
          flagTemperatureControllerFloor = 1;
      }

      //create Group nodes
      for (int i = 0; i < groupsFloorTotal; ++i)
      {

          if(flagLightsFloor == 1)
          {
              groupDivId = "group_Lights_Floor_" + floorName;
              groupImageId = floorNameArea + "_Lights_Group_Image";
              groupTxtId = floorNameArea + "_Lights_Group_txt";
              groupImageTxt = "Lights";

              flagLightsFloor = 0;

          }
          else if(flagAccessoriesFloor == 1)
          {
              groupDivId = "group_Accessories_Floor_" + floorName;
              groupImageId = floorNameArea + "_Accessories_Group_Image";
              groupTxtId = floorNameArea + "_Accessories_Group_txt";
              groupImageTxt = "Accessories";

              flagAccessoriesFloor = 0;

          }
          else if(flagBlindDoorWindowFloor == 1)
          {
              groupDivId = "group_Blinds_Windows_Floor_" + floorName;
              groupImageId = floorNameArea + "_Blinds_Windows_Group_Image";
              groupTxtId = floorNameArea + "_Blinds_Windows_Group_txt";
              groupImageTxt = "Door Window";

              flagBlindDoorWindowFloor = 0;

          }
          else if(flagsensorFloor == 1)
          {
              groupDivId = "group_Sensors_Floor_" + floorName;
              groupImageId = floorNameArea + "_Sensors_Group_Image";
              groupTxtId = floorNameArea + "_Sensors_Group_txt";
              groupImageTxt = "Sensors";

              flagsensorFloor = 0;

          }
          else if(flagTemperatureControllerFloor == 1)
          {
              groupDivId = "group_Temperature_control_Floor_" + floorName;
              groupImageId = floorNameArea + "_Temperature_control_Group_Image";
              groupTxtId = floorNameArea + "_Temperature_control_Group_txt";
              groupImageTxt = "Temperature control";

              flagTemperatureControllerFloor = 0;

          }
          else
          {
              // Do nothing
          }

          // create floor node
          nodeNameTemp = "div";
          NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
          NodeElementTemp.setAttribute("class",floorNameArea);

             //Create input node
             nodeChildNameTemp = "input";
             NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
             NodeElementChildTemp.setAttribute("id",groupImageId);
             NodeElementChildTemp.setAttribute("type","image");
             NodeElementChildTemp.setAttribute("class","image_menu_center_second");
             NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
             OnClickText = "show_Floor_Group(" "'" + groupDivId + "',"
                                        "div_class_" + floorNameArea + "_Images" ","
                                        "'" + groupImageId + "')"
                                        ;
             NodeElementChildTemp.setAttribute("onclick",OnClickText);
             //NodeElementChildTemp.setAttribute("alt",roomNameImageId);
             //Append image div to room div
             NodeElementTemp.appendChild(NodeElementChildTemp);

             //Create paragraph node
             nodeChildNameTemp = "p";
             NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
             roomTxtId = floorNameArea  + "_" + nodeDataTextRoom + "_txt";
             NodeElementChildTemp.setAttribute("id",groupTxtId);
             NodeElementChildTemp.setAttribute("class","imgtxt_scrollmenu");
                      stringTxtNode = groupImageTxt;
                      textNode = htmlDomDocument.createTextNode(stringTxtNode);
                      //Append txt node
                      NodeElementChildTemp.appendChild(textNode);
             //Append paragraph div to room div
             NodeElementTemp.appendChild(NodeElementChildTemp);

             //Create Hr node
             nodeChildNameTemp = "hr";
             NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
             //Append horizontal line div to room div
             NodeElementTemp.appendChild(NodeElementChildTemp);

          // Append floor div to div scrollable
          NodeElementMultiFloorDivScrollableMenu.appendChild(NodeElementTemp);

          scrollableMenuImageArray += "\"" + groupImageId + "\"" ;
          scrollableMenuTxtArray   += "\"" + groupTxtId + "\"" ;

          if(flagSensorGraphFloor == 0)
          {
              if((i+1) < groupsFloorTotal)
              {
                  scrollableMenuImageArray += "," ;
                  scrollableMenuTxtArray += "," ;

              }
          }
          else
          {
              scrollableMenuImageArray += "," ;
              scrollableMenuTxtArray += "," ;
          }

      }

      if(flagSensorGraphFloor == 1)
      {
          groupDivId = "group_Sensors_Graph_Floor_" + floorName;
          groupImageId = floorNameArea + "_Sensors_Group_Graph_Image";
          groupTxtId = floorNameArea + "_Sensors_Group_Graph_txt";
          groupImageTxt = "Sensors Graph";

          // create floor node
          nodeNameTemp = "div";
          NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
          NodeElementTemp.setAttribute("class",floorNameArea);

             //Create input node
             nodeChildNameTemp = "input";
             NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
             NodeElementChildTemp.setAttribute("id",groupImageId);
             NodeElementChildTemp.setAttribute("type","image");
             NodeElementChildTemp.setAttribute("class","image_menu_center_second");
             NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
             OnClickText = "show_Floor_Group(" "'" + groupDivId + "',"
                                        "div_class_" + floorNameArea + "_Images" ","
                                        "'" + groupImageId + "')"
                                        ;
             NodeElementChildTemp.setAttribute("onclick",OnClickText);
             //NodeElementChildTemp.setAttribute("alt",roomNameImageId);
             //Append image div to room div
             NodeElementTemp.appendChild(NodeElementChildTemp);

             //Create paragraph node
             nodeChildNameTemp = "p";
             NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
             roomTxtId = floorNameArea  + "_" + nodeDataTextRoom + "_txt";
             NodeElementChildTemp.setAttribute("id",groupTxtId);
             NodeElementChildTemp.setAttribute("class","imgtxt_scrollmenu");
             stringTxtNode = groupImageTxt;
                      textNode = htmlDomDocument.createTextNode(stringTxtNode);
                      //Append txt node
                      NodeElementChildTemp.appendChild(textNode);
             //Append paragraph div to room div
             NodeElementTemp.appendChild(NodeElementChildTemp);

             //Create Hr node
             nodeChildNameTemp = "hr";
             NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
             //Append horizontal line div to room div
             NodeElementTemp.appendChild(NodeElementChildTemp);

          // Append floor div to div scrollable
          NodeElementMultiFloorDivScrollableMenu.appendChild(NodeElementTemp);



          scrollableMenuImageArray += "\"" + groupImageId + "\"" ;
          scrollableMenuTxtArray   += "\"" + groupTxtId + "\"" ;

          //make it zero
          flagSensorGraphFloor = 0;
      }

      //Append new line
      scrollableMenuImageArray += "\n";
      //Terminate the array
      scrollableMenuImageArray += "];";
      //Append new line
      scrollableMenuImageArray += "\n";
      //Append new line
      scrollableMenuImageArray += "\n";

      //Append new line
      scrollableMenuTxtArray += "\n";
      //Terminate the array
      scrollableMenuTxtArray += "];";
      //Append new line
      scrollableMenuTxtArray += "\n";
      //Append new line
      scrollableMenuTxtArray += "\n";

      // append scrollableMenuImageArray & floorHrId
      floorCfgFileString += scrollableMenuImageArray + scrollableMenuTxtArray ;

    }

    // Check which group to create
    if(lightsGroupTotal>0)
    {
        groupsTotal++;
        flagLightsGroup = 1;
    }
    if(accessoriesGroupTotal>0)
    {
        groupsTotal++;
        flagAccessoriesGroup = 1;
    }
    if(blindDoorWindowGroupTotal>0)
    {
        groupsTotal++;
        flagBlindDoorWindowGroup = 1;
    }
    if(sensorGroupTotal>0)
    {
        groupsTotal++;
        flagsensorGroup = 1;
        // make a graph
        flagSensorGraphFloor = 1;
    }
    if(temperatureControllerGroupTotal>0)
    {
        groupsTotal++;
        flagTemperatureControllerGroup = 1;
    }

    scrollableMenuHouseGroupsImageIdArray.clear();
    centralAreaGroupImageClass.clear();
    centralAreaGroupFloorTxtClass.clear();

    scrollableMenuHouseGroupsImageIdArray = "var scrollmenu_image_id = [";
    scrollableMenuHouseGroupsImageIdArray += "\n";

    centralAreaGroupImageClass = "var central_Area_Group_Image_class = [";
    centralAreaGroupImageClass += "\n";

    if(groupsTotal > 0)
    {
        centralAreaGroupFloorTxtClass = "var central_Area_Group_Floor_txt_class = [";
        centralAreaGroupFloorTxtClass += "\n";

        //add group & floor text class
        centralAreaGroupFloorTxtClass += "\"group_Txt\",\"group_Floor_Txt\"";

        //Append new line
        centralAreaGroupFloorTxtClass += "\n";
        //Terminate the array
        centralAreaGroupFloorTxtClass += "];";
        //Append new line
        centralAreaGroupFloorTxtClass += "\n";
        //Append new line
        centralAreaGroupFloorTxtClass += "\n";


    }

    //create House Group nodes
    for (int i = 0; i < groupsTotal; ++i)
    {

        if(flagLightsGroup == 1)
        {
            groupClass = "group_Lights";
            groupImageId = "group_Lights_Image";
            groupTxtId = "group_Lights_Txt_Id";
            groupImageTxt = "Lights";

            flagLightsGroup = 0;

        }
        else if(flagAccessoriesGroup == 1)
        {
            groupClass = "group_Accessories";
            groupImageId = "group_Accessories_Image";
            groupTxtId = "group_Accessories_Txt_Id";
            groupImageTxt = "Accessories";

            flagAccessoriesGroup = 0;

        }
        else if(flagBlindDoorWindowGroup == 1)
        {
            groupClass = "group_Blinds_Windows";
            groupImageId = "group_Blinds_Windows_Image";
            groupTxtId = "group_Blinds_Windows_Txt_Id";
            groupImageTxt = "Door Window";

            flagBlindDoorWindowGroup = 0;

        }
        else if(flagsensorGroup == 1)
        {
            groupClass = "group_Sensors";
            groupImageId = "group_Sensors_Image";
            groupTxtId = "group_Sensors_Txt_Id";
            groupImageTxt = "Sensors";

            flagsensorGroup = 0;

        }
        else if(flagTemperatureControllerGroup == 1)
        {
            groupClass = "group_Temperature_control";
            groupImageId = "group_Temperature_control_Image";
            groupTxtId = "group_Temperature_control_Txt_Id";
            groupImageTxt = "Temperature control";

            flagTemperatureControllerGroup = 0;

        }
        else
        {
            // Do nothing
        }

        scrollableMenuHouseGroupsImageIdArray += "\"" + groupImageId + "\"" ;
        centralAreaGroupImageClass += "\"" + groupClass + "\"" ;

        if(flagSensorGraphFloor == 0)
        {
            if((i+1) < groupsTotal)
            {
                scrollableMenuHouseGroupsImageIdArray += ",";
                centralAreaGroupImageClass += ",";
            }
        }
        else
        {
            scrollableMenuHouseGroupsImageIdArray += ",";
            centralAreaGroupImageClass += ",";
        }

        // create floor node
        nodeNameTemp = "div";
        NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
        NodeElementTemp.setAttribute("class","All_Devices_group");

           //Create input node
           nodeChildNameTemp = "input";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           NodeElementChildTemp.setAttribute("id",groupImageId);
           NodeElementChildTemp.setAttribute("type","image");
           if(i == 0)
           {
               NodeElementChildTemp.setAttribute("class","image_menu_center_first");
           }
           else
           {
               NodeElementChildTemp.setAttribute("class","image_menu_center_second");
           }
           NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
           OnClickText = "show_area_group(" "'" + groupClass + "',"
                                            "'" + groupImageId + "')"
                                           ;
           NodeElementChildTemp.setAttribute("onclick",OnClickText);
           //NodeElementChildTemp.setAttribute("alt",roomNameImageId);
           //Append image div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

           //Create paragraph node
           nodeChildNameTemp = "p";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           roomTxtId = floorNameArea  + "_" + nodeDataTextRoom + "_txt";
           NodeElementChildTemp.setAttribute("id",groupTxtId);
           NodeElementChildTemp.setAttribute("class","imgtxt_scrollmenu");
                    stringTxtNode = groupImageTxt;
                    textNode = htmlDomDocument.createTextNode(stringTxtNode);
                    //Append txt node
                    NodeElementChildTemp.appendChild(textNode);
           //Append paragraph div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

           //Create Hr node
           nodeChildNameTemp = "hr";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           //Append horizontal line div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

        // Append floor div to div scrollable
        NodeElementMultiFloorDivScrollableMenu.appendChild(NodeElementTemp);
    }

    if(flagSensorGraphFloor == 1)
    {
        groupClass = "group_sensor_graph";
        groupImageId = "group_Sensors_Graph_Image";
        groupTxtId = "group_Sensors_Graph_Txt_Id";
        groupImageTxt = "Sensors Graph";


        // create floor node
        nodeNameTemp = "div";
        NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
        NodeElementTemp.setAttribute("class","All_Devices_group");

           //Create input node
           nodeChildNameTemp = "input";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           NodeElementChildTemp.setAttribute("id",groupImageId);
           NodeElementChildTemp.setAttribute("type","image");
           NodeElementChildTemp.setAttribute("class","image_menu_center_second");

           NodeElementChildTemp.setAttribute("src","../lib/widgets/room/room_unselected.png");
           OnClickText = "show_area_group(" "'" + groupClass + "',"
                                            "'" + groupImageId + "')"
                                           ;
           NodeElementChildTemp.setAttribute("onclick",OnClickText);
           //NodeElementChildTemp.setAttribute("alt",roomNameImageId);
           //Append image div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

           //Create paragraph node
           nodeChildNameTemp = "p";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           roomTxtId = floorNameArea  + "_" + nodeDataTextRoom + "_txt";
           NodeElementChildTemp.setAttribute("id",groupTxtId);
           NodeElementChildTemp.setAttribute("class","imgtxt_scrollmenu");
                    stringTxtNode = groupImageTxt;
                    textNode = htmlDomDocument.createTextNode(stringTxtNode);
                    //Append txt node
                    NodeElementChildTemp.appendChild(textNode);
           //Append paragraph div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

           //Create Hr node
           nodeChildNameTemp = "hr";
           NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
           //Append horizontal line div to room div
           NodeElementTemp.appendChild(NodeElementChildTemp);

        // Append floor div to div scrollable
        NodeElementMultiFloorDivScrollableMenu.appendChild(NodeElementTemp);

        //enter value in array
        scrollableMenuHouseGroupsImageIdArray += "\"" + groupImageId + "\"" ;
        centralAreaGroupImageClass += "\"" + groupClass + "\"" ;

        //reset flag
        flagSensorGraphFloor = 0;
    }


    //Append new line
    scrollableMenuHouseGroupsImageIdArray += "\n";
    //Terminate the array
    scrollableMenuHouseGroupsImageIdArray += "];";
    //Append new line
    scrollableMenuHouseGroupsImageIdArray += "\n";
    //Append new line
    scrollableMenuHouseGroupsImageIdArray += "\n";

    //Append new line
    centralAreaGroupImageClass += "\n";
    //Terminate the array
    centralAreaGroupImageClass += "];";
    //Append new line
    centralAreaGroupImageClass += "\n";
    //Append new line
    centralAreaGroupImageClass += "\n";

    // append scrollableMenuHouseGroupsImageIdArray & centralAreaGroupImageClass
    floorCfgFileString += scrollableMenuHouseGroupsImageIdArray + centralAreaGroupImageClass + centralAreaGroupFloorTxtClass ;

    //htmlRoot.appendChild(NodeElement);
}


