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


#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::xmlCreateTestStepNode(T_testStepDetails &testStepMessageBuffer, QDomElement &testStepNode, uint8_t row, T_packetDeviceLocation &deviceLocation)
{
    QDomElement xmlTempNode;
    QString string;

    // create a test step node
    //xmlCreateNode(testStepNode, "TS");
    xmlLibObject.xmlCreateNode(xmlDomDocument, testStepNode, ROOM_DEVICE_HEADER);

    for(int column =0; column < MODEL_INITIAL_COLUMNS; column++ )
    {
        string = QLatin1String("");

        //Copy from xml node to the buffer
        switch (column)
        {
        case DEVICE_DESCRIPTION_DEVICE_NAME:
            // copy value to the QString
            string = testStepMessageBuffer.u8_deviceName;
            //read device name
            deviceLocation.deviceName = string;
            //xmlCreateNode(xmlTempNode,TEST_STEP_TEXT);
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, DEVICE_NAME_TEXT);
            break;

        case DEVICE_DESCRIPTION_DEVICE_TYPE:
            // copy value to the QString
            string = testStepMessageBuffer.u8_deviceType;
            //xmlCreateNode(xmlTempNode,FUNCTION_TESTED_TEXT);
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, DEVICE_TYPE_TEXT);
          break;

        case DEVICE_DESCRIPTION_DEVICE_SUB_TYPE:
            // copy value to the QString
            string = testStepMessageBuffer.u8_deviceSubType;
            //xmlCreateNode(xmlTempNode,TEST_DESCRIPTION_TEXT);
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, DEVICE_SUB_TYPE_TEXT);
          break;

        case DEVICE_DESCRIPTION_DEVICE_IMAGE:
            // copy value to the QString
            //string = testStepMessageBuffer.u8_packetTx;
            string = testStepMessageBuffer.u8_deviceImage;;//"default";
            //xmlCreateNode(xmlTempNode,PACKET_TX_TEXT);
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, DEVICE_IMAGE_TEXT);
            // Xml create tx packet node
            //xmlCreateTxPacketNode(xmlTempNode, row);
          break;

        case DEVICE_DESCRIPTION_DEVICE_INFO:
            // copy value to the QString
            string = testStepMessageBuffer.u8_deviceInfo;
            //xmlCreateNode(xmlTempNode,PACKET_RX_TEXT);
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, DEVICE_INFO_TEXT);
          break;

        case DEVICE_DESCRIPTION_DEVICE_PACKET:
            // copy value to the QString
            string = testStepMessageBuffer.u8_devicePacket;
            //xmlCreateNode(xmlTempNode,EXPECTED_RESPONSE_TEXT);
            //xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, EXPECTED_RESPONSE_TEXT);
            //xmlCreateExpectedRxPacketNode(xmlTempNode, row);
            // Create vscp packet node
            xmlCreateVscpPacketNode(xmlTempNode, row ,deviceLocation);
          break;

        /*case TEST_CASE_PASS_FAIL:
            // copy value to the QString
            string = testStepMessageBuffer.u8_passFail;
            //xmlCreateNode(xmlTempNode,PASS_FAIL_TEXT);
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, PASS_FAIL_TEXT);
          break;

        case TEST_CASE_COMMENT:
            // copy value to the QString
            string = testStepMessageBuffer.u8_comment;
            //xmlCreateNode(xmlTempNode,COMMENT_TEXT);
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, COMMENT_TEXT);
          break;*/

        default:         // Do nothing
            break;
        }

        // Add text to the text node
        //if((column != DEVICE_DESCRIPTION_DEVICE_IMAGE) && (column != DEVICE_DESCRIPTION_DEVICE_PACKET))
        if(column != DEVICE_DESCRIPTION_DEVICE_PACKET)
        {
            xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        }
        // Add text node to the test step
        xmlLibObject.xmlAppendNode(testStepNode,xmlTempNode);
    }

}

void MainWindow::xmlAppendFullTestStepsToTestCase(QList<T_testStepDetails> testCaseStepslist, QDomElement &testCaseNode, T_packetDeviceLocation &deviceLocation)
{
    T_testStepDetails testStepMessageBuffer;
    QDomElement testStepNode;


    // Read from the T_testStepDetails list & update test step/case
    for(int row =0; row < testCaseStepslist.size() ; row++)
    {
        //Read from list
        testStepMessageBuffer = testCaseStepslist.at(row);
        //Create the test step node
        xmlCreateTestStepNode(testStepMessageBuffer, testStepNode, row, deviceLocation);

        //Append test step to the test case node
        //xmlAppendNode(testCaseNode,testStepNode);
        xmlLibObject.xmlAppendNode(testCaseNode,testStepNode);
    }

}

void MainWindow:: xmlAppendRoomNameAndDescription(QDomElement &roomDetailsNode)
{
    QString roomName;
    QString houseName;
    QString floorName;
    QDomElement roomNameNode;
    QDomElement houseNameNode;
    QDomElement floorNameNode;

    roomName = ui->roomLineEdit->text();
    //xmlCreateNode(testCaseNameNode, TEST_CASE_NAME);
    xmlLibObject.xmlCreateNode(xmlDomDocument, roomNameNode, ROOM_NAME);
    //xmlAddTextNode(testCaseNameNode, testCaseName );
    xmlLibObject.xmlAddTextNode(xmlDomDocument, roomNameNode, roomName );
    //Append test case name to the test case node
    //xmlAppendNode(testCaseNode,testCaseNameNode);
    xmlLibObject.xmlAppendNode(roomDetailsNode,roomNameNode);

    floorName = ui->floorLineEdit->text();
    //xmlCreateNode(testCaseDescriptionNode, TEST_CASE_DESCRIPTION);
    xmlLibObject.xmlCreateNode(xmlDomDocument, floorNameNode, FLOOR_NAME);
    //xmlAddTextNode(testCaseDescriptionNode, testCaseDescription);
    xmlLibObject.xmlAddTextNode(xmlDomDocument, floorNameNode, floorName);
    //Append test case description to the test case node
    //xmlAppendNode(testCaseNode,testCaseDescriptionNode);
    xmlLibObject.xmlAppendNode(roomDetailsNode,floorNameNode);

    houseName = ui->houseLineEdit->text();
    //xmlCreateNode(testCaseDescriptionNode, TEST_CASE_DESCRIPTION);
    xmlLibObject.xmlCreateNode(xmlDomDocument, houseNameNode, HOUSE_NAME);
    //xmlAddTextNode(testCaseDescriptionNode, testCaseDescription);
    xmlLibObject.xmlAddTextNode(xmlDomDocument, houseNameNode, houseName);
    //Append test case description to the test case node
    //xmlAppendNode(testCaseNode,testCaseDescriptionNode);
    xmlLibObject.xmlAppendNode(roomDetailsNode,houseNameNode);
}

//Update TextView & xml after delete Test Case Pressed
void MainWindow::UpdateXmlAndTextViewAfterDelete()
{
    // xml delete currentnodenumber from the xml
    //xmlRootRemoveNodeByNumber(currentXmlRootNodeNumber);
    xmlLibObject.xmlRootRemoveNodeByNumber(xmlRoot,currentXmlRootNodeNumber);
    //Update TextView for currently selected node
    UpdateTextViewForCurrentSelectedNode();

}

//Update TextView for currently selected node
void MainWindow::UpdateTextViewForCurrentSelectedNode()
{
    //int totalNumberOfXmlNodes;
    QList<T_testStepDetails> testCaseStepslist;

        // if it is the only node of the xml --> then do nothing
    if(!xmlRoot.firstChild().isNull())
    {
        //update current XmlNode
        currentXmlRootNodeNumber = ui->treeWidgetLeft->currentIndex().row();

        //Create default view of the table
        createDefaultTableView();

        // Clear the TX & Rx list
        clearTxRxList();

        // copy xml node content to the  -- testCaseStepslist
        //xmlReadFullTestCaseNodeValue(testCaseStepslist,currentXmlRootNodeNumber);
        xmlReadFullRoomNodeValue( xmlRoot, roomNameText, roomNameText_undo, floorNameText , floorNameText_undo , houseNameText, houseNameText_undo, testCaseStepslist,testCaseStepslist_undo, testCaseStepslist_undoRoom, testCaseStepCanPacket_undo, testCaseStepCanPacket_undoRoom, testCaseStepCanPacket_rx, currentXmlRootNodeNumber);

        //Copy xml node value to room name &  description
        copyXmlNodeToRoomNameAndDescription();
        //copy content of room devices nodes to the test case view
        copyBufferRoomDevicesToTheTextEdit(testCaseStepslist);
    }
    else
    {
        currentXmlRootNodeNumber = NO_NODE_TO_DISPLAY;
    }

}

//Load vaue of XML to the
void MainWindow::loadXmltoTreeAndTextView()
{
    QDomNodeList list;
    QDomNodeList listChild;
    QDomNode tempNodeChild;
    QString roomNameTextString;
    QString floorNameTextString;
    QString houseNameTextString;
    QList<QString> roomNameList;
    QList<QString> floorNameList;
    QList<QString> houseNameList;
    QDomNode firstNodeOfTheXml;
    QTreeWidgetItem *current;
    //QList<T_testStepDetails> loadFileTestCaseStepslist;

    //Make update tree view signal high
    b_updateTreeViewSignal = TRUE;

    //Load root nodes
    //list = xmlRoot.elementsByTagName("TC");
    list = xmlRoot.childNodes();

    // root have Test Case nodes
    if(list.count() != 0)
    {
        for(int i =0; i< list.count() ; i++)
        {
            tempNodeChild = list.at(i);
            if(i == 0)
            {
                firstNodeOfTheXml = tempNodeChild;
            }
            // Create list of child nodes of - test case
            listChild = tempNodeChild.childNodes();

            //Read test case name from node
            tempNodeChild = listChild.at(ROOM_NAME_NUMBER);
            if (!tempNodeChild.isNull())
            {
                roomNameTextString = tempNodeChild.toElement().text();
            }
            else{
                roomNameTextString = "";
            }
            //Append to list
            roomNameList << roomNameTextString;


            //Read floor name from node
            tempNodeChild = listChild.at(FLOOR_NAME_NUMBER);
            if (!tempNodeChild.isNull())
            {
                floorNameTextString = tempNodeChild.toElement().text();
            }
            else{
                floorNameTextString = "";
            }
            //Append to list
            floorNameList << floorNameTextString;


            //Read house name from node
            tempNodeChild = listChild.at(HOUSE_NAME_NUMBER);
            if (!tempNodeChild.isNull())
            {
                houseNameTextString = tempNodeChild.toElement().text();
            }
            else{
                houseNameTextString = "";
            }
            //Append to list
            houseNameList << houseNameTextString;

        }
    }

    // clear the tree
    ui->treeWidgetLeft->clear();
    //Add node to the tree
    for(int i=0;i<roomNameList.count();i++)
    {
        roomNameTextString = roomNameList.at(i);
        floorNameTextString = floorNameList.at(i);
        houseNameTextString = houseNameList.at(i);
        // Add the root item to tree
        AddRootNoSelectionChange(""   , roomNameTextString, floorNameTextString, houseNameTextString);
    }

    // Make selection to point at first node of the tree
    currentXmlRootNodeNumber = FIRST_NODE_OF_TREE;
    //take item from location currentXmlRootNodeNumber
    current = ui->treeWidgetLeft->topLevelItem(currentXmlRootNodeNumber);
    //change selection
    ui->treeWidgetLeft->setCurrentItem(current);

    //Update TextView for currently selected node
    UpdateTextViewForCurrentSelectedNode();

    //Test case exist
    b_testCaseExists = TRUE;

    //Make update tree view signal low
    b_updateTreeViewSignal = FALSE;
}



// Create Tx packet node
void MainWindow::xmlCreateTxPacketNode(QDomElement &xmlNode, uint8_t row)
{
    T_testCaseStepCanPacket testCaseStepCanMessage;
    QDomElement xmlTempNode;
    QDomElement xmlTempNode_1;
    QString string;
    bool b_packetisCanTx = false;

    /*QMessageBox *msgBox 	= new QMessageBox();
    msgBox->setText("hello");
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->exec();*/

    //itterate through the list
    for (uint16_t i = 0; i < testCaseStepCanPacket_tx.size(); ++i)
    {
         //Read from list without removing node
         testCaseStepCanMessage = testCaseStepCanPacket_tx.at(i);
         if(testCaseStepCanMessage.stepnumber == row)
         {
             b_packetisCanTx = true;
             break;
         }

     }

    if(b_packetisCanTx) //CAN step
    {
        /*QMessageBox *msgBox2 	= new QMessageBox();
        msgBox2->setText("hi");
        msgBox2->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox2->exec();*/

        //remove the node read previously
        //testCaseStepCanPacket_tx.removeAt(0);

        // create tx packet node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlNode, DEVICE_PACKET_TEXT);

        // create packet type node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, PACKET_TYPE);
        // Add text to the packet type node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, CAN_PACKET );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create CAN ID node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, CAN_ID);
        // read can ID
        string = testCaseStepCanMessage.u16_CanId;
        // Add text to the packet type node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create DLC node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode_1, DLC);
        // read DLC
        string = testCaseStepCanMessage.u8_dlc;
        // Add text to the DLC node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode_1, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode_1);

        // create Byte 0 node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, BYTE_0);
        // read byte 0
        string = testCaseStepCanMessage.u8_byte0;
        // Add text to the Byte 0 node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create Byte 1 node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, BYTE_1);
        // read byte 1
        string = testCaseStepCanMessage.u8_byte1;
        // Add text to the Byte 1 node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create Byte 2 node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, BYTE_2);
        // read byte 2
        string = testCaseStepCanMessage.u8_byte2;
        // Add text to the Byte 2 node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create Byte 3 node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, BYTE_3);
        // read byte 3
        string = testCaseStepCanMessage.u8_byte3;
        // Add text to the Byte 3 node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create Byte 4 node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, BYTE_4);
        // read byte 4
        string = testCaseStepCanMessage.u8_byte4;
        // Add text to the Byte 4 node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create Byte 5 node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, BYTE_5);
        // read byte 5
        string = testCaseStepCanMessage.u8_byte5;
        // Add text to the Byte 5 node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create Byte 6 node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, BYTE_6);
        // read byte 6
        string = testCaseStepCanMessage.u8_byte6;
        // Add text to the Byte 6 node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

        // create Byte 7 node
        xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, BYTE_7);
        // read byte 7
        string = testCaseStepCanMessage.u8_byte7;
        // Add text to the Byte 7 node
        xmlLibObject.xmlAddTextNode(xmlDomDocument,xmlTempNode, string );
        // Append the node
        xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);
    }
    else   // TCP step
    {
        //
    }

    /*QMessageBox *msgBox1 	= new QMessageBox();
    msgBox1->setText("bye");
    msgBox1->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox1->exec();*/

}

// Create Rx packet node
//void MainWindow::xmlCreateExpectedRxPacketNode(QDomElement &xmlNode, uint8_t row)
// Create vscp packet node
void MainWindow::xmlCreateVscpPacketNode(QDomElement &xmlNode, uint8_t row, T_packetDeviceLocation &deviceLocation)
{
    //T_testCaseStepCanPacket testCaseStepCanMessage;
    T_vscpDevicePacket testCaseStepCanMessage;
    QDomElement xmlTempNode;
    QDomElement xmlTempTxOnEventNode;
    QDomElement xmlTempTxOffEventNode;
    QDomElement xmlTempRxOnEventNode;
    QDomElement xmlTempRxOffEventNode;
    QDomElement xmlTempVariableNode;
    QString string;
    uint32_t controlVar = 0;
    bool b_packetExist = false;

    //itterate through the list
    for (uint16_t i = 0; i < testCaseStepCanPacket_rx.size(); ++i)
    {
         //Read from list without removing node
         testCaseStepCanMessage = testCaseStepCanPacket_rx.at(i);
         if(testCaseStepCanMessage.stepnumber == row)
         {
             b_packetExist = true;
             break;
         }

     }

    //Remove the spaces
    deviceLocation.houseName.replace(" ", "");
    deviceLocation.houseName.remove(QRegExp("[^a-zA-Z\\d\\s]"));
    deviceLocation.floorName.replace(" ", "");
    deviceLocation.floorName.remove(QRegExp("[^a-zA-Z\\d\\s]"));
    deviceLocation.roomName.replace(" ", "");
    deviceLocation.roomName.remove(QRegExp("[^a-zA-Z\\d\\s]"));
    deviceLocation.deviceName.replace(" ", "");
    deviceLocation.deviceName.remove(QRegExp("[^a-zA-Z\\d\\s]"));

    if(b_packetExist) //update node
    {
        if(testCaseStepCanMessage.packetType == SENSOR_PACKET_TYPE)
        {
            //remove the node read previously
            //testCaseStepCanPacket_rx.removeAt(0);

            // create sensor packet node
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlNode, PACKET_SENSOR_TEXT);

            /*** create websocket configure node ***/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, WEBSOCKET_CONFIGURE);

            //Update the sensor ID
            testCaseStepCanMessage.vscpPacketSensor.id = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Image" + "_ID";
            testCaseStepCanMessage.vscpPacketSensor.graphId = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_chart_div";
            testCaseStepCanMessage.vscpPacketSensor.graphUnitId = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_chart_unit_div";
            testCaseStepCanMessage.vscpPacketSensor.idRemoteTxt = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Remote_Txt" + "_ID";

            // create sensor id attribute
            string = testCaseStepCanMessage.vscpPacketSensor.id;
            xmlTempNode.setAttribute(SENSOR_ID,string);            
            // create sensor graph ID attribute
            string = testCaseStepCanMessage.vscpPacketSensor.graphId;
            xmlTempNode.setAttribute(SENSOR_GRAPH_ID,string);
            // create sensor graph Unit ID attribute
            string = testCaseStepCanMessage.vscpPacketSensor.graphUnitId;
            xmlTempNode.setAttribute(SENSOR_GRAPH_UNIT_ID,string);
            // create sensor graph Type attribute
            string = testCaseStepCanMessage.vscpPacketSensor.graphType;
            xmlTempNode.setAttribute(SENSOR_GRAPH_TYPE,string);
            // create sensor Remote txt id attribute
            string = testCaseStepCanMessage.vscpPacketSensor.idRemoteTxt;
            xmlTempNode.setAttribute(SENSOR_REMOTE_TXT_ID,string);
            // create sensor URL attribute
            string = testCaseStepCanMessage.vscpPacketSensor.url;
            xmlTempNode.setAttribute(SENSOR_URL,string);
            // create sensor class attribute
            string = testCaseStepCanMessage.vscpPacketSensor.class_value;
            xmlTempNode.setAttribute(SENSOR_CLASS,string);
            // create sensor type attribute
            string = testCaseStepCanMessage.vscpPacketSensor.type_value;
            xmlTempNode.setAttribute(SENSOR_TYPE,string);
            // create sensor coding index attribute
            string = testCaseStepCanMessage.vscpPacketSensor.codingIndex;
            xmlTempNode.setAttribute(SENSOR_CODING_INDEX,string);
            // create sensor decimals attribute
            string = testCaseStepCanMessage.vscpPacketSensor.decimals;
            xmlTempNode.setAttribute(SENSOR_DECIMALS,string);
            // create sensor formatString attribute
            string = testCaseStepCanMessage.vscpPacketSensor.formatString;
            xmlTempNode.setAttribute(SENSOR_FORMAT_STRING,string);
            // create sensor guid attribute
            string = testCaseStepCanMessage.vscpPacketSensor.guid;
            xmlTempNode.setAttribute(SENSOR_GUID,string);
            // create sensor callback attribute
            string = testCaseStepCanMessage.vscpPacketSensor.callback;
            xmlTempNode.setAttribute(SENSOR_CALLACK,string);
            // create username attribute
            string = testCaseStepCanMessage.vscpPacketSensor.userName;
            xmlTempNode.setAttribute(SENSOR_USERNAME,string);
            // create password attribute
            string = testCaseStepCanMessage.vscpPacketSensor.passWord;
            xmlTempNode.setAttribute(SENSOR_PASSWORD,string);
            // create Domain attribute
            string = testCaseStepCanMessage.vscpPacketSensor.domain;
            xmlTempNode.setAttribute(SENSOR_DOMAIN,string);

            /*** Append the websocket configure node ***/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);


            /************* create variable node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempVariableNode, VARIABLE_CONFIGURE);

            //update the variable name
            testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.name = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName + "_VAR";

            // create sensor variable name attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.name;
            xmlTempVariableNode.setAttribute(VARIABLE_NAME,string);
            // create sensor variable groupId attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.groupId;
            xmlTempVariableNode.setAttribute(VARIABLE_GROUPID,string);
            // create sensor variable allowedFrom attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedFrom;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_FROM,string);
            // create sensor variable allowedTo attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedTo;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_TO,string);
            // create sensor variable allowedTime attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedTime;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_TIME,string);
            // create sensor variable alloweddays attribute
            // read variable allowed days
            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedDays.mon == "true")
            {
                string = "m";
            }
            else
            {
                string = "-";
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedDays.tue == "true")
            {
                string += "t";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedDays.wed == "true")
            {
                string += "w";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedDays.thur == "true")
            {
                string += "t";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedDays.fri == "true")
            {
                string += "f";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedDays.sat == "true")
            {
                string += "s";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.allowedDays.sun == "true")
            {
                string += "s";
            }
            else
            {
                string += "-";
            }
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_DAYS,string);
            // create sensor variable action attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.action;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION,string);
            // create sensor variable actionParameters attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.actionParameters;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION_PARAMETERS,string);
            // create sensor variable control attribute
            // read variable control
            //controlVar
            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.control.EnableRow == "true")
            {
                controlVar |= (uint32_t)(1<<31);
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.control.endScan == "true")
            {
                controlVar |= (uint32_t)(1<<29);
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.control.checkIndex == "true")
            {
                controlVar |= (uint32_t)(1<<5);
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.control.checkzone == "true")
            {
                controlVar |= (uint32_t)(1<<4);
            }

            if(testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.control.checkSubzone == "true")
            {
                controlVar |= (uint32_t)(1<<3);
            }
            string = "0x" +  QString::number(controlVar,16);
            xmlTempVariableNode.setAttribute(VARIABLE_CONTROL,string);
            // create sensor variable class_value attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.class_value;
            xmlTempVariableNode.setAttribute(VARIABLE_CLASS,string);
            // create sensor variable type_value attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.type_value;
            xmlTempVariableNode.setAttribute(VARIABLE_TYPE,string);
            // create sensor variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.guid;
            xmlTempVariableNode.setAttribute(VARIABLE_GUID,string);
            // create sensor variable priority attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.priority;
            xmlTempVariableNode.setAttribute(VARIABLE_PRIORITY,string);
            // create sensor variable index attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.index;
            xmlTempVariableNode.setAttribute(VARIABLE_INDEX,string);
            // create sensor variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.zone;
            xmlTempVariableNode.setAttribute(VARIABLE_ZONE,string);
            // create sensor variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.subzone;
            xmlTempVariableNode.setAttribute(VARIABLE_SUBZONE,string);
            // create sensor variable comments attribute
            string = testCaseStepCanMessage.vscpPacketSensor.packetSensorVariable.comments;
            xmlTempVariableNode.setAttribute(VARIABLE_COMMENTS,string);

            /************ Append the Variable node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempVariableNode);

        }
        else if (testCaseStepCanMessage.packetType == SWITCH_PACKET_TYPE)
        {
            // create switch packet node
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlNode, PACKET_SWITCH_TEXT);

            /*** create websocket configure node ***/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, WEBSOCKET_CONFIGURE);

            //update the ID
            testCaseStepCanMessage.vscpPacketSwitch.id = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName  + "_Image" + "_ID";

            // create sensor id attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.id;
            xmlTempNode.setAttribute(SWITCH_ID,string);
            // create sensor URL attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.url;
            xmlTempNode.setAttribute(SWITCH_URL,string);
            // create sensor bLocal attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.bLocal;
            xmlTempNode.setAttribute(SWITCH_BLOCAL,string);
            // create sensor bNoState attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.bNoState;
            xmlTempNode.setAttribute(SWITCH_BNOSTATE,string);
            // create username attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.userName;
            xmlTempNode.setAttribute(SWITCH_USERNAME,string);
            // create password attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.passWord;
            xmlTempNode.setAttribute(SWITCH_PASSWORD,string);
            // create Domain attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.domain;
            xmlTempNode.setAttribute(SWITCH_DOMAIN,string);

            /*** Append the websocket configure node ***/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

            /************* create Tx ON Event node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempTxOnEventNode, TX_ON_EVENT);

            // create Tx ON Event variable class attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.class_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_CLASS,string);
            // create Tx ON Event variable type attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.type_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_TYPE,string);
            // create Tx ON Event variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.guid;
            xmlTempTxOnEventNode.setAttribute(EVENT_GUID,string);
            // create Tx ON Event variable index attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.index;
            xmlTempTxOnEventNode.setAttribute(EVENT_INDEX,string);
            // create Tx ON Event variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.zone;
            xmlTempTxOnEventNode.setAttribute(EVENT_ZONE,string);
            // create Tx ON Event variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.subzone;
            xmlTempTxOnEventNode.setAttribute(EVENT_SUBZONE,string);
            // create Tx ON Event variable head attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.head;
            xmlTempTxOnEventNode.setAttribute(EVENT_HEAD,string);
            // create Tx ON Event variable obid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.obid;
            xmlTempTxOnEventNode.setAttribute(EVENT_OBID,string);
            // create Tx ON Event variable timeStamp attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.timeStamp;
            xmlTempTxOnEventNode.setAttribute(EVENT_TIMESTAMP,string);
            // create Tx ON Event variable data attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOnEvent.data;
            xmlTempTxOnEventNode.setAttribute(EVENT_DATA,string);

            /************ Append the Tx ON Event node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempTxOnEventNode);

            /************* create Tx Off Event node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempTxOffEventNode, TX_ON_EVENT);

            // create Tx OFF Event variable class attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.class_value;
            xmlTempTxOffEventNode.setAttribute(EVENT_CLASS,string);
            // create Tx OFF Event variable type attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.type_value;
            xmlTempTxOffEventNode.setAttribute(EVENT_TYPE,string);
            // create Tx OFF Event variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.guid;
            xmlTempTxOffEventNode.setAttribute(EVENT_GUID,string);
            // create Tx OFF Event variable index attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.index;
            xmlTempTxOffEventNode.setAttribute(EVENT_INDEX,string);
            // create Tx OFF Event variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.zone;
            xmlTempTxOffEventNode.setAttribute(EVENT_ZONE,string);
            // create Tx OFF Event variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.subzone;
            xmlTempTxOffEventNode.setAttribute(EVENT_SUBZONE,string);
            // create Tx OFF Event variable head attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.head;
            xmlTempTxOffEventNode.setAttribute(EVENT_HEAD,string);
            // create Tx OFF Event variable obid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.obid;
            xmlTempTxOffEventNode.setAttribute(EVENT_OBID,string);
            // create Tx OFF Event variable timeStamp attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.timeStamp;
            xmlTempTxOffEventNode.setAttribute(EVENT_TIMESTAMP,string);
            // create Tx OFF Event variable data attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.txOffEvent.data;
            xmlTempTxOffEventNode.setAttribute(EVENT_DATA,string);

            /************ Append the Tx OFF Event node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempTxOffEventNode);

            /************* create Rx ON Event node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempRxOnEventNode, TX_ON_EVENT);

            // create Rx ON Event variable class attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.class_value;
            xmlTempRxOnEventNode.setAttribute(EVENT_CLASS,string);
            // create Rx ON Event variable type attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.type_value;
            xmlTempRxOnEventNode.setAttribute(EVENT_TYPE,string);
            // create Rx ON Event variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.guid;
            xmlTempRxOnEventNode.setAttribute(EVENT_GUID,string);
            // create Rx ON Event variable index attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.index;
            xmlTempRxOnEventNode.setAttribute(EVENT_INDEX,string);
            // create Rx ON Event variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.zone;
            xmlTempRxOnEventNode.setAttribute(EVENT_ZONE,string);
            // create Rx ON Event variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.subzone;
            xmlTempRxOnEventNode.setAttribute(EVENT_SUBZONE,string);
            // create Rx ON Event variable head attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.head;
            xmlTempRxOnEventNode.setAttribute(EVENT_HEAD,string);
            // create Rx ON Event variable obid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.obid;
            xmlTempRxOnEventNode.setAttribute(EVENT_OBID,string);
            // create Rx ON Event variable timeStamp attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.timeStamp;
            xmlTempRxOnEventNode.setAttribute(EVENT_TIMESTAMP,string);
            // create Rx ON Event variable data attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOnEvent.data;
            xmlTempRxOnEventNode.setAttribute(EVENT_DATA,string);

            /************ Append the Rx ON Event node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempRxOnEventNode);

            /************* create Rx Off Event node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempRxOffEventNode, TX_ON_EVENT);

            // create Rx OFF Event variable class attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.class_value;
            xmlTempRxOffEventNode.setAttribute(EVENT_CLASS,string);
            // create Rx OFF Event variable type attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.type_value;
            xmlTempRxOffEventNode.setAttribute(EVENT_TYPE,string);
            // create Rx OFF Event variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.guid;
            xmlTempRxOffEventNode.setAttribute(EVENT_GUID,string);
            // create Rx OFF Event variable index attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.index;
            xmlTempRxOffEventNode.setAttribute(EVENT_INDEX,string);
            // create Rx OFF Event variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.zone;
            xmlTempRxOffEventNode.setAttribute(EVENT_ZONE,string);
            // create Rx OFF Event variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.subzone;
            xmlTempRxOffEventNode.setAttribute(EVENT_SUBZONE,string);
            // create Rx OFF Event variable head attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.head;
            xmlTempRxOffEventNode.setAttribute(EVENT_HEAD,string);
            // create Rx OFF Event variable obid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.obid;
            xmlTempRxOffEventNode.setAttribute(EVENT_OBID,string);
            // create Rx OFF Event variable timeStamp attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.timeStamp;
            xmlTempRxOffEventNode.setAttribute(EVENT_TIMESTAMP,string);
            // create Rx OFF Event variable data attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.rxOffEvent.data;
            xmlTempRxOffEventNode.setAttribute(EVENT_DATA,string);

            /************ Append the Tx OFF Event node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempRxOffEventNode);

            /************* create variable node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempVariableNode, VARIABLE_CONFIGURE);

            // Update the variable name
            testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.name  = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName + "_VAR";

            // create sensor variable name attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.name;
            xmlTempVariableNode.setAttribute(VARIABLE_NAME,string);
            // create sensor variable groupId attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.groupId;
            xmlTempVariableNode.setAttribute(VARIABLE_GROUPID,string);
            // create sensor variable allowedFrom attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedFrom;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_FROM,string);
            // create sensor variable allowedTo attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedTo;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_TO,string);
            // create sensor variable allowedTime attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedTime;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_TIME,string);
            // create sensor variable alloweddays attribute
            // read variable allowed days
            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedDays.mon == "true")
            {
                string = "m";
            }
            else
            {
                string += "-";
            }
            //QMessageBox::information(this, "mon", testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedDays.mon );

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedDays.tue == "true")
            {
                string += "t";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedDays.wed == "true")
            {
                string += "w";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedDays.thur == "true")
            {
                string += "t";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedDays.fri == "true")
            {
                string += "f";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedDays.sat == "true")
            {
                string += "s";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.allowedDays.sun == "true")
            {
                string += "s";
            }
            else
            {
                string += "-";
            }
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_DAYS,string);
            // create sensor variable action attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.action;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION,string);
            // create sensor variable actionParameters Set attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.actionParametersSet;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION_PARAMETERS_SET,string);
            // create sensor variable actionParameters Reset attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.actionParametersReset;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION_PARAMETERS_RESET,string);
            // create sensor variable control attribute
            // read variable control
            //controlVar
            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.control.EnableRow == "true")
            {
                controlVar |= (uint32_t)(1<<31);
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.control.endScan == "true")
            {
                controlVar |= (uint32_t)(1<<29);
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.control.checkIndex == "true")
            {
                controlVar |= (uint32_t)(1<<5);
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.control.checkzone == "true")
            {
                controlVar |= (uint32_t)(1<<4);
            }

            if(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.control.checkSubzone == "true")
            {
                controlVar |= (uint32_t)(1<<3);
            }
            string = "0x" + QString::number(controlVar,16);
            xmlTempVariableNode.setAttribute(VARIABLE_CONTROL,string);
            // create sensor variable class_value_on attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.class_value_on;
            xmlTempVariableNode.setAttribute(VARIABLE_SWITCH_CLASS_ON,string);
            // create sensor variable type_value_on attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.type_value_on;
            xmlTempVariableNode.setAttribute(VARIABLE_SWITCH_TYPE_ON,string);
            // create sensor variable class_value_off attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.class_value_off;
            xmlTempVariableNode.setAttribute(VARIABLE_SWITCH_CLASS_OFF,string);
            // create sensor variable type_value_off attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.type_value_off;
            xmlTempVariableNode.setAttribute(VARIABLE_SWITCH_TYPE_OFF,string);
            // create sensor variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.guid;
            xmlTempVariableNode.setAttribute(VARIABLE_GUID,string);

            /*QMessageBox *msgBox_2 = new QMessageBox();
            msgBox_2->setWindowTitle("guid");
            msgBox_2->setText(testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.guid);
            msgBox_2->exec();*/

            // create sensor variable priority attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.priority;
            xmlTempVariableNode.setAttribute(VARIABLE_PRIORITY,string);
            // create sensor variable index attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.index;
            xmlTempVariableNode.setAttribute(VARIABLE_INDEX,string);
            // create sensor variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.zone;
            xmlTempVariableNode.setAttribute(VARIABLE_ZONE,string);
            // create sensor variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.subzone;
            xmlTempVariableNode.setAttribute(VARIABLE_SUBZONE,string);
            // create sensor variable comments attribute
            string = testCaseStepCanMessage.vscpPacketSwitch.packetSwitchVariable.comments;
            xmlTempVariableNode.setAttribute(VARIABLE_COMMENTS,string);

            /************ Append the Variable node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempVariableNode);
        }
        else if (testCaseStepCanMessage.packetType == SLIDER_PACKET_TYPE)
        {
            // create slider packet node
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlNode, PACKET_SLIDER_TEXT);

            /*** create websocket configure node ***/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, WEBSOCKET_CONFIGURE);

            //update the ID
            testCaseStepCanMessage.vscpPacketSlider.id = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Image" + "_ID";
            //Set the Local Txt ID
            testCaseStepCanMessage.vscpPacketSlider.idLocalTxt = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Local_Txt" + "_ID";
            //Set the Remote Txt ID
            testCaseStepCanMessage.vscpPacketSlider.idRemoteTxt = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Remote_Txt" + "_ID";

            // create slider id attribute
            string = testCaseStepCanMessage.vscpPacketSlider.id;
            xmlTempNode.setAttribute(SLIDER_ID,string);
            // create slider Local txt id attribute
            string = testCaseStepCanMessage.vscpPacketSlider.idLocalTxt;
            xmlTempNode.setAttribute(SLIDER_LOCAL_TXT_ID,string);
            // create slider Remote Txt id attribute
            string = testCaseStepCanMessage.vscpPacketSlider.idRemoteTxt;
            xmlTempNode.setAttribute(SLIDER_REMOTE_TXT_ID,string);
            // create slider URL attribute
            string = testCaseStepCanMessage.vscpPacketSlider.url;
            xmlTempNode.setAttribute(SLIDER_URL,string);
            // create slider Max value attribute
            string = testCaseStepCanMessage.vscpPacketSlider.maxValue;
            xmlTempNode.setAttribute(SLIDER_MAX,string);
            // create slider Min value attribute
            string = testCaseStepCanMessage.vscpPacketSlider.minValue;
            xmlTempNode.setAttribute(SLIDER_MIN,string);
            // create username attribute
            string = testCaseStepCanMessage.vscpPacketSlider.userName;
            xmlTempNode.setAttribute(SLIDER_USERNAME,string);
            // create password attribute
            string = testCaseStepCanMessage.vscpPacketSlider.passWord;
            xmlTempNode.setAttribute(SLIDER_PASSWORD,string);
            // create Domain attribute
            string = testCaseStepCanMessage.vscpPacketSlider.domain;
            xmlTempNode.setAttribute(SLIDER_DOMAIN,string);

            /*** Append the websocket configure node ***/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

            /************* create Tx Event node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempTxOnEventNode, TX_EVENT);

            // create Tx Event variable class attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.class_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_CLASS,string);
            // create Tx Event variable type attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.type_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_TYPE,string);
            // create Tx Event variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.guid;
            xmlTempTxOnEventNode.setAttribute(EVENT_GUID,string);
            // create Tx Event variable index attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.index;
            xmlTempTxOnEventNode.setAttribute(EVENT_INDEX,string);
            // create Tx Event variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.zone;
            xmlTempTxOnEventNode.setAttribute(EVENT_ZONE,string);
            // create Tx Event variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.subzone;
            xmlTempTxOnEventNode.setAttribute(EVENT_SUBZONE,string);
            // create Tx Event variable head attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.head;
            xmlTempTxOnEventNode.setAttribute(EVENT_HEAD,string);
            // create Tx Event variable obid attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.obid;
            xmlTempTxOnEventNode.setAttribute(EVENT_OBID,string);
            // create Tx Event variable timeStamp attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.timeStamp;
            xmlTempTxOnEventNode.setAttribute(EVENT_TIMESTAMP,string);
            // create Tx Event variable data attribute
            string = testCaseStepCanMessage.vscpPacketSlider.txEvent.data;
            xmlTempTxOnEventNode.setAttribute(EVENT_DATA,string);

            /************ Append the Tx Event node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempTxOnEventNode);


            /************* create Rx Event node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempTxOnEventNode, RX_EVENT);

            // create Rx Event variable class attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.class_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_CLASS,string);
            // create Rx Event variable type attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.type_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_TYPE,string);
            // create Rx Event variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.guid;
            xmlTempTxOnEventNode.setAttribute(EVENT_GUID,string);
            // create Rx Event variable index attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.index;
            xmlTempTxOnEventNode.setAttribute(EVENT_INDEX,string);
            // create Rx Event variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.zone;
            xmlTempTxOnEventNode.setAttribute(EVENT_ZONE,string);
            // create Rx Event variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.subzone;
            xmlTempTxOnEventNode.setAttribute(EVENT_SUBZONE,string);
            // create Rx Event variable head attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.head;
            xmlTempTxOnEventNode.setAttribute(EVENT_HEAD,string);
            // create Rx Event variable obid attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.obid;
            xmlTempTxOnEventNode.setAttribute(EVENT_OBID,string);
            // create Rx Event variable timeStamp attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.timeStamp;
            xmlTempTxOnEventNode.setAttribute(EVENT_TIMESTAMP,string);
            // create Rx Event variable data attribute
            string = testCaseStepCanMessage.vscpPacketSlider.rxEvent.data;
            xmlTempTxOnEventNode.setAttribute(EVENT_DATA,string);

            /************ Append the Rx Event node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempTxOnEventNode);


            /************* create variable node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempVariableNode, VARIABLE_CONFIGURE);

            //update the variable name
            testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.name = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName + "_VAR";

            // create sensor variable name attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.name;
            xmlTempVariableNode.setAttribute(VARIABLE_NAME,string);
            // create sensor variable groupId attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.groupId;
            xmlTempVariableNode.setAttribute(VARIABLE_GROUPID,string);
            // create sensor variable allowedFrom attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedFrom;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_FROM,string);
            // create sensor variable allowedTo attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedTo;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_TO,string);
            // create sensor variable allowedTime attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedTime;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_TIME,string);
            // create sensor variable alloweddays attribute
            // read variable allowed days
            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedDays.mon == "true")
            {
                string = "m";
            }
            else
            {
                string = "-";
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedDays.tue == "true")
            {
                string += "t";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedDays.wed == "true")
            {
                string += "w";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedDays.thur == "true")
            {
                string += "t";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedDays.fri == "true")
            {
                string += "f";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedDays.sat == "true")
            {
                string += "s";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.allowedDays.sun == "true")
            {
                string += "s";
            }
            else
            {
                string += "-";
            }
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_DAYS,string);
            // create sensor variable action attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.action;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION,string);
            // create sensor variable actionParameters attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.actionParameters;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION_PARAMETERS,string);
            // create sensor variable control attribute
            // read variable control
            //controlVar
            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.control.EnableRow == "true")
            {
                controlVar |= (uint32_t)(1<<31);
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.control.endScan == "true")
            {
                controlVar |= (uint32_t)(1<<29);
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.control.checkIndex == "true")
            {
                controlVar |= (uint32_t)(1<<5);
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.control.checkzone == "true")
            {
                controlVar |= (uint32_t)(1<<4);
            }

            if(testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.control.checkSubzone == "true")
            {
                controlVar |= (uint32_t)(1<<3);
            }
            string = "0x" +  QString::number(controlVar,16);
            xmlTempVariableNode.setAttribute(VARIABLE_CONTROL,string);
            // create sensor variable class_value attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.class_value;
            xmlTempVariableNode.setAttribute(VARIABLE_CLASS,string);
            // create sensor variable type_value attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.type_value;
            xmlTempVariableNode.setAttribute(VARIABLE_TYPE,string);
            // create sensor variable guid attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.guid;
            xmlTempVariableNode.setAttribute(VARIABLE_GUID,string);
            // create sensor variable priority attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.priority;
            xmlTempVariableNode.setAttribute(VARIABLE_PRIORITY,string);
            // create sensor variable index attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.index;
            xmlTempVariableNode.setAttribute(VARIABLE_INDEX,string);
            // create sensor variable zone attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.zone;
            xmlTempVariableNode.setAttribute(VARIABLE_ZONE,string);
            // create sensor variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.subzone;
            xmlTempVariableNode.setAttribute(VARIABLE_SUBZONE,string);
            // create sensor variable comments attribute
            string = testCaseStepCanMessage.vscpPacketSlider.packetSliderVariable.comments;
            xmlTempVariableNode.setAttribute(VARIABLE_COMMENTS,string);

            /************ Append the Variable node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempVariableNode);

        }
        else if (testCaseStepCanMessage.packetType == VARIABLE_BUTTON_PACKET_TYPE)
        {
            // create Variable Switch packet node
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlNode, PACKET_VARIABLE_SWITCH_TEXT);

            /*** create websocket configure node ***/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempNode, WEBSOCKET_CONFIGURE);

            //update the ID
            testCaseStepCanMessage.vscpPacketVariableSwitch.idIncImage = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Inc_Image" + "_ID";
            testCaseStepCanMessage.vscpPacketVariableSwitch.idDecImage = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Dec_Image" + "_ID";
            testCaseStepCanMessage.vscpPacketVariableSwitch.idLocalTxt = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Local_Txt" + "_ID";
            testCaseStepCanMessage.vscpPacketVariableSwitch.idRemoteTxt = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName   + "_Remote_Txt" + "_ID";

            // create Variable Switch Inc id attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.idIncImage;
            xmlTempNode.setAttribute(VARIABLE_SWITCH_INC_ID,string);
            // create Variable Switch Dec id attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.idDecImage;
            xmlTempNode.setAttribute(VARIABLE_SWITCH_DEC_ID,string);
            // create Variable Switch Local Txt id attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.idLocalTxt;
            xmlTempNode.setAttribute(VARIABLE_SWITCH_LOCAL_TXT_ID,string);
            // create Variable Switch Remote Txt id attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.idRemoteTxt;
            xmlTempNode.setAttribute(VARIABLE_SWITCH_REMOTE_TXT_ID,string);
            // create Variable Switch URL attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.url;
            xmlTempNode.setAttribute(VARIABLE_SWITCH_URL,string);
            // create Variable Switch Max value attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.maxValue;
            xmlTempNode.setAttribute(VARIABLE_SWITCH_MAX,string);
            // create Variable Switch Min value attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.minValue;
            xmlTempNode.setAttribute(VARIABLE_SWITCH_MIN,string);
            // create username attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.userName;
            xmlTempNode.setAttribute(VARIABLE_USERNAME,string);
            // create password attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.passWord;
            xmlTempNode.setAttribute(VARIABLE_PASSWORD,string);
            // create Domain attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.domain;
            xmlTempNode.setAttribute(VARIABLE_DOMAIN,string);

            /*** Append the websocket configure node ***/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempNode);

            /************* create Tx Event node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempTxOnEventNode, TX_EVENT);

            // create Tx Event variable class attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.class_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_CLASS,string);
            // create Tx Event variable type attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.type_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_TYPE,string);
            // create Tx Event variable guid attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.guid;
            xmlTempTxOnEventNode.setAttribute(EVENT_GUID,string);
            // create Tx Event variable zone attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.zone;
            xmlTempTxOnEventNode.setAttribute(EVENT_ZONE,string);
            // create Tx Event variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.subzone;
            xmlTempTxOnEventNode.setAttribute(EVENT_SUBZONE,string);
            // create Tx Event variable head attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.head;
            xmlTempTxOnEventNode.setAttribute(EVENT_HEAD,string);
            // create Tx Event variable obid attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.obid;
            xmlTempTxOnEventNode.setAttribute(EVENT_OBID,string);
            // create Tx Event variable timeStamp attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.timeStamp;
            xmlTempTxOnEventNode.setAttribute(EVENT_TIMESTAMP,string);
            // create Tx Event variable data attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.txEvent.data;
            xmlTempTxOnEventNode.setAttribute(EVENT_DATA,string);

            /************ Append the Tx Event node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempTxOnEventNode);


            /************* create Rx Event node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempTxOnEventNode, RX_EVENT);

            // create Rx Event variable class attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.class_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_CLASS,string);
            // create Rx Event variable type attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.type_value;
            xmlTempTxOnEventNode.setAttribute(EVENT_TYPE,string);
            // create Rx Event variable guid attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.guid;
            xmlTempTxOnEventNode.setAttribute(EVENT_GUID,string);
            // create Rx Event variable zone attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.zone;
            xmlTempTxOnEventNode.setAttribute(EVENT_ZONE,string);
            // create Rx Event variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.subzone;
            xmlTempTxOnEventNode.setAttribute(EVENT_SUBZONE,string);
            // create Rx Event variable head attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.head;
            xmlTempTxOnEventNode.setAttribute(EVENT_HEAD,string);
            // create Rx Event variable obid attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.obid;
            xmlTempTxOnEventNode.setAttribute(EVENT_OBID,string);
            // create Rx Event variable timeStamp attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.timeStamp;
            xmlTempTxOnEventNode.setAttribute(EVENT_TIMESTAMP,string);
            // create Rx Event variable data attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.rxEvent.data;
            xmlTempTxOnEventNode.setAttribute(EVENT_DATA,string);

            /************ Append the Rx Event node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempTxOnEventNode);


            /************* create variable node ***************/
            xmlLibObject.xmlCreateNode(xmlDomDocument, xmlTempVariableNode, VARIABLE_CONFIGURE);

            //update the variable name
            testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.name = deviceLocation.houseName + deviceLocation.floorName + deviceLocation.roomName + deviceLocation.deviceName + "_VAR";

            // create sensor variable name attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.name;
            xmlTempVariableNode.setAttribute(VARIABLE_NAME,string);
            // create sensor variable groupId attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.groupId;
            xmlTempVariableNode.setAttribute(VARIABLE_GROUPID,string);
            // create sensor variable allowedFrom attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedFrom;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_FROM,string);
            // create sensor variable allowedTo attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedTo;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_TO,string);
            // create sensor variable allowedTime attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedTime;
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_TIME,string);
            // create sensor variable alloweddays attribute
            // read variable allowed days
            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.mon == "true")
            {
                string = "m";
            }
            else
            {
                string = "-";
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.tue == "true")
            {
                string += "t";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.wed == "true")
            {
                string += "w";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.thur == "true")
            {
                string += "t";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.fri == "true")
            {
                string += "f";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.sat == "true")
            {
                string += "s";
            }
            else
            {
                string += "-";
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.sun == "true")
            {
                string += "s";
            }
            else
            {
                string += "-";
            }
            xmlTempVariableNode.setAttribute(VARIABLE_ALLOWED_DAYS,string);
            // create sensor variable action attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.action;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION,string);
            // create sensor variable actionParameters attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.actionParameters;
            xmlTempVariableNode.setAttribute(VARIABLE_ACTION_PARAMETERS,string);
            // create sensor variable control attribute
            // read variable control
            //controlVar
            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.EnableRow == "true")
            {
                controlVar |= (uint32_t)(1<<31);
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.endScan == "true")
            {
                controlVar |= (uint32_t)(1<<29);
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkIndex == "true")
            {
                controlVar |= (uint32_t)(1<<5);
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkzone == "true")
            {
                controlVar |= (uint32_t)(1<<4);
            }

            if(testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkSubzone == "true")
            {
                controlVar |= (uint32_t)(1<<3);
            }
            string = "0x" +  QString::number(controlVar,16);
            xmlTempVariableNode.setAttribute(VARIABLE_CONTROL,string);
            // create sensor variable class_value attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.class_value;
            xmlTempVariableNode.setAttribute(VARIABLE_CLASS,string);
            // create sensor variable type_value attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.type_value;
            xmlTempVariableNode.setAttribute(VARIABLE_TYPE,string);
            // create sensor variable guid attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.guid;
            xmlTempVariableNode.setAttribute(VARIABLE_GUID,string);
            // create sensor variable priority attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.priority;
            xmlTempVariableNode.setAttribute(VARIABLE_PRIORITY,string);
            // create sensor variable index attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.index;
            xmlTempVariableNode.setAttribute(VARIABLE_INDEX,string);
            // create sensor variable zone attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.zone;
            xmlTempVariableNode.setAttribute(VARIABLE_ZONE,string);
            // create sensor variable subzone attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.subzone;
            xmlTempVariableNode.setAttribute(VARIABLE_SUBZONE,string);
            // create sensor variable comments attribute
            string = testCaseStepCanMessage.vscpPacketVariableSwitch.packetVariableSwitchVariable.comments;
            xmlTempVariableNode.setAttribute(VARIABLE_COMMENTS,string);

            /************ Append the Variable node ************/
            xmlLibObject.xmlAppendNode(xmlNode,xmlTempVariableNode);

        }
        else{
            // Do nothing
        }

    }
    else
    {
        // Do nothing
    }

}



// Read node from xml root
void MainWindow::xmlReadFullRoomNodeValue( QDomElement &xmlRoot, QString &roomNameText, QString &roomNameText_undo, QString &floorNameText , QString &floorNameText_undo , QString &houseNameText, QString &houseNameText_undo, QList<T_testStepDetails> &testCaseStepslist, QList<T_testStepDetails> &testCaseStepslist_undo, QList<T_testStepDetails> &testCaseStepslist_undoRoom,QList<T_vscpDevicePacket> &testCaseStepCanPacket_undo, QList<T_vscpDevicePacket> &testCaseStepCanPacket_undoRoom, QList<T_vscpDevicePacket> &testCaseStepCanPacket_rx, int nodeNumber)
{
    QDomNode tempNode;
    QDomNode tempNodeChild;
    QDomNode firstChild;
    QDomNodeList list;
    T_testStepDetails testStepMessageBuffer;
    uint8_t teststep = 0;

    //xmlCreateNode(testStepNode, "TC");
    //xmlGetNodeByNumber(xmlRoot, nodeNumber, tempNode);
    xmlLibObject.xmlGetNodeByNumber(xmlRoot, nodeNumber, tempNode);

    if(!tempNode.firstChild().isNull())
    {
        list = tempNode.childNodes();

        //Read room name node
        tempNodeChild = list.at(ROOM_NAME_NUMBER);
        if (!tempNodeChild.isNull())
        {
            roomNameText = tempNodeChild.toElement().text();
        }
        else{
            roomNameText = "";
        }
        //Save the undo value
        roomNameText_undo = roomNameText;

        //Read floor name node
        tempNodeChild = list.at(FLOOR_NAME_NUMBER);
        if (!tempNodeChild.isNull())
        {
            floorNameText = tempNodeChild.toElement().text();
        }
        else{
            floorNameText = "";
        }
        //Save the undo value
        floorNameText_undo = floorNameText;

        //Read house name node
        tempNodeChild = list.at(HOUSE_NAME_NUMBER);
        if (!tempNodeChild.isNull())
        {
            houseNameText = tempNodeChild.toElement().text();
        }
        else{
            houseNameText = "";
        }
        //Save the undo value
        houseNameText_undo = houseNameText;

        // Iterate through all we found - get test case column value
        for(int testSteps= DEVICE_NODE_NUMBER; testSteps<list.count(); testSteps++)
        {
            //Read test step from list
            tempNodeChild = list.at(testSteps).toElement();

            if (!tempNodeChild.isNull())
            {
                //Read first child of the node
                firstChild = tempNodeChild.firstChild();

                if(!firstChild.isNull())
                {
                    //Read details of test step
                    for(int column =0; column < MODEL_INITIAL_COLUMNS; column++ )
                    {
                        //Copy from xml node to the buffer
                        switch (column)
                        {
                        case DEVICE_DESCRIPTION_DEVICE_NAME:
                            // copy value to the Qstring
                            testStepMessageBuffer.u8_deviceName = firstChild.toElement().text();
                            break;

                        case DEVICE_DESCRIPTION_DEVICE_TYPE:
                            // copy value to the Qstring
                            testStepMessageBuffer.u8_deviceType = firstChild.toElement().text();
                          break;

                        case DEVICE_DESCRIPTION_DEVICE_SUB_TYPE:
                            // copy value to the Qstring
                            testStepMessageBuffer.u8_deviceSubType = firstChild.toElement().text();
                          break;

                        case DEVICE_DESCRIPTION_DEVICE_IMAGE:
                            // copy value to the Qstring
                            testStepMessageBuffer.u8_deviceImage = firstChild.toElement().text();
                            //testStepMessageBuffer.u8_packetTx = "";
                            //update expected packet
                            //-->UpdateListForCanPacket(testCaseStepCanPacket_tx, firstChild, teststep);
                          break;

                        case DEVICE_DESCRIPTION_DEVICE_INFO:
                            // copy value to the Qstring
                            testStepMessageBuffer.u8_deviceInfo = firstChild.toElement().text();
                          break;

                        case DEVICE_DESCRIPTION_DEVICE_PACKET:
                            // copy value to the Qstring
                            //testStepMessageBuffer.u8_expectedResponse = firstChild.toElement().text();
                            testStepMessageBuffer.u8_devicePacket = "";
                            //update expected packet
                            //UpdateListForCanPacket(testCaseStepCanPacket_rx, firstChild, teststep);
                            UpdateListForvscpPacket(testCaseStepCanPacket_rx,testCaseStepCanPacket_undo,testCaseStepCanPacket_undoRoom, firstChild, teststep);
                          break;

                        /*case TEST_CASE_PASS_FAIL:
                            // copy value to the Qstring
                            testStepMessageBuffer.u8_passFail = firstChild.toElement().text();
                          break;

                        case TEST_CASE_COMMENT:
                            // copy value to the Qstring
                            testStepMessageBuffer.u8_comment = firstChild.toElement().text();
                          break;*/

                        default:         // Do nothing
                            break;
                        }

                        // Get the next child
                        firstChild = firstChild.nextSibling();
                    }

                    //Append to the list
                    testCaseStepslist.append(testStepMessageBuffer);
                    //Append to the undo list
                    testCaseStepslist_undo.append(testStepMessageBuffer);
                    //Append to the undo Room list
                    testCaseStepslist_undoRoom.append(testStepMessageBuffer);


                    //increment the step number
                    teststep++;
                }
            }
        }
    }
    else
    {
        // Do nothing
    }

}




// update vscp expected packet --
void MainWindow::UpdateListForvscpPacket(QList<T_vscpDevicePacket> &testCaseStepCanPacketList, QList<T_vscpDevicePacket> &testCaseStepCanPacket_undo, QList<T_vscpDevicePacket> &testCaseStepCanPacket_undoRoom, QDomNode &tempNode, uint8_t teststep)
{
    QDomNode tempNodeChild;
    QDomNodeList list;
    QString vscpPacketType;
    QString allowedDays;
    QChar *data;
    uint8_t iterator = 0;
    QString controlVarString;
    uint32_t controlVar = 0;
    bool ok;
    //T_testCaseStepCanPacket canPacket;
    T_vscpDevicePacket vscpPacket;

    //Create the list
    list = tempNode.childNodes();

    // Store the test step number
    //canPacket.stepnumber = teststep;
    vscpPacket.stepnumber = teststep;

    //Read VSCP packet type
    vscpPacketType = tempNode.toElement().tagName();
    //vscpPacketType = tempNode.toElement().text();

    if(vscpPacketType == PACKET_SENSOR_TEXT)
    {
        vscpPacket.packetType = SENSOR_PACKET_TYPE;

        //Read sensor websocket configuration
        tempNodeChild = list.at(VSCP_PACKET_SENSOR_WEBSOCKET_CONFIGURE);
        vscpPacket.vscpPacketSensor.id = tempNodeChild.toElement().attribute(SENSOR_ID);
        vscpPacket.vscpPacketSensor.graphId = tempNodeChild.toElement().attribute(SENSOR_GRAPH_ID);
        vscpPacket.vscpPacketSensor.graphUnitId = tempNodeChild.toElement().attribute(SENSOR_GRAPH_UNIT_ID);
        vscpPacket.vscpPacketSensor.graphType = tempNodeChild.toElement().attribute(SENSOR_GRAPH_TYPE);
        vscpPacket.vscpPacketSensor.idRemoteTxt = tempNodeChild.toElement().attribute(SENSOR_REMOTE_TXT_ID);
        vscpPacket.vscpPacketSensor.url = tempNodeChild.toElement().attribute(SENSOR_URL);
        vscpPacket.vscpPacketSensor.userName = tempNodeChild.toElement().attribute(SENSOR_USERNAME);
        vscpPacket.vscpPacketSensor.passWord = tempNodeChild.toElement().attribute(SENSOR_PASSWORD);
        vscpPacket.vscpPacketSensor.domain = tempNodeChild.toElement().attribute(SENSOR_DOMAIN);
        vscpPacket.vscpPacketSensor.class_value = tempNodeChild.toElement().attribute(SENSOR_CLASS);
        vscpPacket.vscpPacketSensor.type_value = tempNodeChild.toElement().attribute(SENSOR_TYPE);
        vscpPacket.vscpPacketSensor.codingIndex = tempNodeChild.toElement().attribute(SENSOR_CODING_INDEX);
        vscpPacket.vscpPacketSensor.decimals = tempNodeChild.toElement().attribute(SENSOR_DECIMALS);
        vscpPacket.vscpPacketSensor.formatString = tempNodeChild.toElement().attribute(SENSOR_FORMAT_STRING);
        vscpPacket.vscpPacketSensor.guid = tempNodeChild.toElement().attribute(SENSOR_GUID);
        vscpPacket.vscpPacketSensor.callback = tempNodeChild.toElement().attribute(SENSOR_CALLACK);

        //Read sensor variable
        tempNodeChild = list.at(VSCP_PACKET_SENSOR_VARIABLE_CONFIGURE);
        vscpPacket.vscpPacketSensor.packetSensorVariable.name = tempNodeChild.toElement().attribute(VARIABLE_NAME);
        vscpPacket.vscpPacketSensor.packetSensorVariable.groupId = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
        vscpPacket.vscpPacketSensor.packetSensorVariable.allowedFrom = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
        vscpPacket.vscpPacketSensor.packetSensorVariable.allowedTo = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
        vscpPacket.vscpPacketSensor.packetSensorVariable.allowedTime = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
        allowedDays = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
        data = allowedDays.data();
        while (!data->isNull())
        {

            //qDebug() << data->toAscii();
            if(iterator == 0)
            {
                if(data->toAscii() == 'm')
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.mon = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.mon = "false";
                }
            }
            else if(iterator == 1)
            {
                if(data->toAscii() == 't')
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.tue = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.tue = "false";
                }
            }
            else if(iterator == 2)
            {
                if(data->toAscii() == 'w')
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.wed = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.wed = "false";
                }
            }
            else if(iterator == 3)
            {
                if(data->toAscii() == 't')
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.thur = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.thur = "false";
                }
            }
            else if(iterator == 4)
            {
                if(data->toAscii() == 'f')
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.fri = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.fri = "false";
                }
            }
            else if(iterator == 5)
            {
                if(data->toAscii() == 's')
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.sat = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.sat = "false";
                }
            }
            else if(iterator == 6)
            {
                if(data->toAscii() == 's')
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.sun = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSensor.packetSensorVariable.allowedDays.sun = "false";
                }
            }


            ++data;
            ++iterator;
        }

        vscpPacket.vscpPacketSensor.packetSensorVariable.action = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
        vscpPacket.vscpPacketSensor.packetSensorVariable.actionParameters = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS);
        controlVarString =  tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
        controlVar = controlVarString.toUInt(&ok, 0);
        //controlVar = controlVarString.toAscii().toHex().toInt();

        if((uint32_t)controlVar & (uint32_t)(1<<31))
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.EnableRow = "true";
        }
        else
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.EnableRow = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<29))
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.endScan = "true";
        }
        else
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.endScan = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<5))
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.checkIndex = "true";
        }
        else
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.checkIndex = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<4))
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.checkzone = "true";
        }
        else
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.checkzone = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<3))
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.checkSubzone = "true";
        }
        else
        {
            vscpPacket.vscpPacketSensor.packetSensorVariable.control.checkSubzone = "false";
        }
        vscpPacket.vscpPacketSensor.packetSensorVariable.class_value = tempNodeChild.toElement().attribute(VARIABLE_CLASS);
        vscpPacket.vscpPacketSensor.packetSensorVariable.type_value = tempNodeChild.toElement().attribute(VARIABLE_TYPE);
        vscpPacket.vscpPacketSensor.packetSensorVariable.guid = tempNodeChild.toElement().attribute(VARIABLE_GUID);
        vscpPacket.vscpPacketSensor.packetSensorVariable.priority = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
        vscpPacket.vscpPacketSensor.packetSensorVariable.index = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
        vscpPacket.vscpPacketSensor.packetSensorVariable.zone = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
        vscpPacket.vscpPacketSensor.packetSensorVariable.subzone = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
        vscpPacket.vscpPacketSensor.packetSensorVariable.comments = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);

    }
    else if (vscpPacketType == PACKET_SWITCH_TEXT)
    {

        vscpPacket.packetType = SWITCH_PACKET_TYPE;

        //Read switch websocket configuration
        tempNodeChild = list.at(VSCP_PACKET_SWITCH_WEBSOCKET_CONFIGURE);
        vscpPacket.vscpPacketSwitch.id = tempNodeChild.toElement().attribute(SWITCH_ID);
        vscpPacket.vscpPacketSwitch.url = tempNodeChild.toElement().attribute(SWITCH_URL);
        vscpPacket.vscpPacketSwitch.bLocal = tempNodeChild.toElement().attribute(SWITCH_BLOCAL);
        vscpPacket.vscpPacketSwitch.bNoState = tempNodeChild.toElement().attribute(SWITCH_BNOSTATE);
        vscpPacket.vscpPacketSwitch.userName = tempNodeChild.toElement().attribute(SWITCH_USERNAME);
        vscpPacket.vscpPacketSwitch.passWord = tempNodeChild.toElement().attribute(SWITCH_PASSWORD);
        vscpPacket.vscpPacketSwitch.domain = tempNodeChild.toElement().attribute(SWITCH_DOMAIN);

        //Read switch tx on event
        tempNodeChild = list.at(VSCP_PACKET_SWITCH_TX_ON_EVENT);
        vscpPacket.vscpPacketSwitch.txOnEvent.class_value = tempNodeChild.toElement().attribute(EVENT_CLASS);
        vscpPacket.vscpPacketSwitch.txOnEvent.type_value  = tempNodeChild.toElement().attribute(EVENT_TYPE);
        vscpPacket.vscpPacketSwitch.txOnEvent.guid  = tempNodeChild.toElement().attribute(EVENT_GUID);
        vscpPacket.vscpPacketSwitch.txOnEvent.index  = tempNodeChild.toElement().attribute(EVENT_INDEX);
        vscpPacket.vscpPacketSwitch.txOnEvent.zone  = tempNodeChild.toElement().attribute(EVENT_ZONE);
        vscpPacket.vscpPacketSwitch.txOnEvent.subzone  = tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        vscpPacket.vscpPacketSwitch.txOnEvent.head  = tempNodeChild.toElement().attribute(EVENT_HEAD);
        vscpPacket.vscpPacketSwitch.txOnEvent.obid  = tempNodeChild.toElement().attribute(EVENT_OBID);
        vscpPacket.vscpPacketSwitch.txOnEvent.timeStamp  = tempNodeChild.toElement().attribute(EVENT_TIMESTAMP);
        vscpPacket.vscpPacketSwitch.txOnEvent.data  = tempNodeChild.toElement().attribute(EVENT_DATA);

        //Read switch tx off event
        tempNodeChild = list.at(VSCP_PACKET_SWITCH_TX_OFF_EVENT);
        vscpPacket.vscpPacketSwitch.txOffEvent.class_value = tempNodeChild.toElement().attribute(EVENT_CLASS);
        vscpPacket.vscpPacketSwitch.txOffEvent.type_value  = tempNodeChild.toElement().attribute(EVENT_TYPE);
        vscpPacket.vscpPacketSwitch.txOffEvent.guid  = tempNodeChild.toElement().attribute(EVENT_GUID);
        vscpPacket.vscpPacketSwitch.txOffEvent.index  = tempNodeChild.toElement().attribute(EVENT_INDEX);
        vscpPacket.vscpPacketSwitch.txOffEvent.zone  = tempNodeChild.toElement().attribute(EVENT_ZONE);
        vscpPacket.vscpPacketSwitch.txOffEvent.subzone  = tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        vscpPacket.vscpPacketSwitch.txOffEvent.head  = tempNodeChild.toElement().attribute(EVENT_HEAD);
        vscpPacket.vscpPacketSwitch.txOffEvent.obid  = tempNodeChild.toElement().attribute(EVENT_OBID);
        vscpPacket.vscpPacketSwitch.txOffEvent.timeStamp  = tempNodeChild.toElement().attribute(EVENT_TIMESTAMP);
        vscpPacket.vscpPacketSwitch.txOffEvent.data  = tempNodeChild.toElement().attribute(EVENT_DATA);

        //Read switch rx on event
        tempNodeChild = list.at(VSCP_PACKET_SWITCH_RX_ON_EVENT);
        vscpPacket.vscpPacketSwitch.rxOnEvent.class_value = tempNodeChild.toElement().attribute(EVENT_CLASS);
        vscpPacket.vscpPacketSwitch.rxOnEvent.type_value  = tempNodeChild.toElement().attribute(EVENT_TYPE);
        vscpPacket.vscpPacketSwitch.rxOnEvent.guid  = tempNodeChild.toElement().attribute(EVENT_GUID);
        vscpPacket.vscpPacketSwitch.rxOnEvent.index  = tempNodeChild.toElement().attribute(EVENT_INDEX);
        vscpPacket.vscpPacketSwitch.rxOnEvent.zone  = tempNodeChild.toElement().attribute(EVENT_ZONE);
        vscpPacket.vscpPacketSwitch.rxOnEvent.subzone  = tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        vscpPacket.vscpPacketSwitch.rxOnEvent.head  = tempNodeChild.toElement().attribute(EVENT_HEAD);
        vscpPacket.vscpPacketSwitch.rxOnEvent.obid  = tempNodeChild.toElement().attribute(EVENT_OBID);
        vscpPacket.vscpPacketSwitch.rxOnEvent.timeStamp  = tempNodeChild.toElement().attribute(EVENT_TIMESTAMP);
        vscpPacket.vscpPacketSwitch.rxOnEvent.data  = tempNodeChild.toElement().attribute(EVENT_DATA);

        //Read switch rx off event
        tempNodeChild = list.at(VSCP_PACKET_SWITCH_RX_OFF_EVENT);
        vscpPacket.vscpPacketSwitch.rxOffEvent.class_value = tempNodeChild.toElement().attribute(EVENT_CLASS);
        vscpPacket.vscpPacketSwitch.rxOffEvent.type_value  = tempNodeChild.toElement().attribute(EVENT_TYPE);
        vscpPacket.vscpPacketSwitch.rxOffEvent.guid  = tempNodeChild.toElement().attribute(EVENT_GUID);
        vscpPacket.vscpPacketSwitch.rxOffEvent.index  = tempNodeChild.toElement().attribute(EVENT_INDEX);
        vscpPacket.vscpPacketSwitch.rxOffEvent.zone  = tempNodeChild.toElement().attribute(EVENT_ZONE);
        vscpPacket.vscpPacketSwitch.rxOffEvent.subzone  = tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        vscpPacket.vscpPacketSwitch.rxOffEvent.head  = tempNodeChild.toElement().attribute(EVENT_HEAD);
        vscpPacket.vscpPacketSwitch.rxOffEvent.obid  = tempNodeChild.toElement().attribute(EVENT_OBID);
        vscpPacket.vscpPacketSwitch.rxOffEvent.timeStamp  = tempNodeChild.toElement().attribute(EVENT_TIMESTAMP);
        vscpPacket.vscpPacketSwitch.rxOffEvent.data  = tempNodeChild.toElement().attribute(EVENT_DATA);

        //Read switch variable
        tempNodeChild = list.at(VSCP_PACKET_SWITCH_VARIABLE_CONFIGURE);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.name = tempNodeChild.toElement().attribute(VARIABLE_NAME);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.groupId = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedFrom = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedTo = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedTime = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
        allowedDays = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
        data = allowedDays.data();
        while (!data->isNull())
        {

            //qDebug() << data->toAscii();
            if(iterator == 0)
            {
                if(data->toAscii() == 'm')
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.mon = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.mon = "false";
                }
            }
            else if(iterator == 1)
            {
                if(data->toAscii() == 't')
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.tue = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.tue = "false";
                }
            }
            else if(iterator == 2)
            {
                if(data->toAscii() == 'w')
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.wed = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.wed = "false";
                }
            }
            else if(iterator == 3)
            {
                if(data->toAscii() == 't')
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.thur = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.thur = "false";
                }
            }
            else if(iterator == 4)
            {
                if(data->toAscii() == 'f')
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.fri = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.fri = "false";
                }
            }
            else if(iterator == 5)
            {
                if(data->toAscii() == 's')
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.sat = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.sat = "false";
                }
            }
            else if(iterator == 6)
            {
                if(data->toAscii() == 's')
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.sun = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSwitch.packetSwitchVariable.allowedDays.sun = "false";
                }
            }


            ++data;
            ++iterator;
        }
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.action = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.actionParametersSet = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS_SET);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.actionParametersReset = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS_RESET);
        controlVarString =  tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
        controlVar = controlVarString.toUInt(&ok, 0);
        //controlVar = controlVarString.toAscii().toHex().toInt();


        if((uint32_t)controlVar & (uint32_t)(1<<31))
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.EnableRow = "true";

        }
        else
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.EnableRow = "false";

        }

        if((uint32_t)controlVar & (uint32_t)(1<<29))
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.endScan = "true";
        }
        else
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.endScan = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<5))
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.checkIndex = "true";
        }
        else
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.checkIndex = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<4))
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.checkzone = "true";
        }
        else
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.checkzone = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<3))
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.checkSubzone = "true";
        }
        else
        {
            vscpPacket.vscpPacketSwitch.packetSwitchVariable.control.checkSubzone = "false";
        }
        //vscpPacket.vscpPacketSwitch.packetSwitchVariable.control = tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.class_value_on = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_CLASS_ON);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.type_value_on = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_TYPE_ON);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.class_value_off = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_CLASS_OFF);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.type_value_off = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_TYPE_OFF);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.guid = tempNodeChild.toElement().attribute(VARIABLE_GUID);

        vscpPacket.vscpPacketSwitch.packetSwitchVariable.priority = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.index = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.zone = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.subzone = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
        vscpPacket.vscpPacketSwitch.packetSwitchVariable.comments = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);

    }
    else if (vscpPacketType == PACKET_SLIDER_TEXT)
    {

        vscpPacket.packetType = SLIDER_PACKET_TYPE;

        //Read switch websocket configuration
        tempNodeChild = list.at(VSCP_PACKET_SLIDER_WEBSOCKET_CONFIGURE);
        vscpPacket.vscpPacketSlider.id = tempNodeChild.toElement().attribute(SLIDER_ID);
        vscpPacket.vscpPacketSlider.idLocalTxt = tempNodeChild.toElement().attribute(SLIDER_LOCAL_TXT_ID);
        vscpPacket.vscpPacketSlider.idRemoteTxt = tempNodeChild.toElement().attribute(SLIDER_REMOTE_TXT_ID);
        vscpPacket.vscpPacketSlider.url = tempNodeChild.toElement().attribute(SLIDER_URL);
        vscpPacket.vscpPacketSlider.maxValue = tempNodeChild.toElement().attribute(SLIDER_MAX);
        vscpPacket.vscpPacketSlider.minValue = tempNodeChild.toElement().attribute(SLIDER_MIN);
        vscpPacket.vscpPacketSlider.userName = tempNodeChild.toElement().attribute(SLIDER_USERNAME);
        vscpPacket.vscpPacketSlider.passWord = tempNodeChild.toElement().attribute(SLIDER_PASSWORD);
        vscpPacket.vscpPacketSlider.domain = tempNodeChild.toElement().attribute(SLIDER_DOMAIN);

        //Read switch tx on event
        tempNodeChild = list.at(VSCP_PACKET_SLIDER_TX_EVENT);
        vscpPacket.vscpPacketSlider.txEvent.class_value = tempNodeChild.toElement().attribute(EVENT_CLASS);
        vscpPacket.vscpPacketSlider.txEvent.type_value  = tempNodeChild.toElement().attribute(EVENT_TYPE);
        vscpPacket.vscpPacketSlider.txEvent.guid  = tempNodeChild.toElement().attribute(EVENT_GUID);
        vscpPacket.vscpPacketSlider.txEvent.index  = tempNodeChild.toElement().attribute(EVENT_INDEX);
        vscpPacket.vscpPacketSlider.txEvent.zone  = tempNodeChild.toElement().attribute(EVENT_ZONE);
        vscpPacket.vscpPacketSlider.txEvent.subzone  = tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        vscpPacket.vscpPacketSlider.txEvent.head  = tempNodeChild.toElement().attribute(EVENT_HEAD);
        vscpPacket.vscpPacketSlider.txEvent.obid  = tempNodeChild.toElement().attribute(EVENT_OBID);
        vscpPacket.vscpPacketSlider.txEvent.timeStamp  = tempNodeChild.toElement().attribute(EVENT_TIMESTAMP);
        vscpPacket.vscpPacketSlider.txEvent.data  = tempNodeChild.toElement().attribute(EVENT_DATA);

        //Read switch tx on event
        tempNodeChild = list.at(VSCP_PACKET_SLIDER_RX_EVENT);
        vscpPacket.vscpPacketSlider.rxEvent.class_value = tempNodeChild.toElement().attribute(EVENT_CLASS);
        vscpPacket.vscpPacketSlider.rxEvent.type_value  = tempNodeChild.toElement().attribute(EVENT_TYPE);
        vscpPacket.vscpPacketSlider.rxEvent.guid  = tempNodeChild.toElement().attribute(EVENT_GUID);
        vscpPacket.vscpPacketSlider.rxEvent.index  = tempNodeChild.toElement().attribute(EVENT_INDEX);
        vscpPacket.vscpPacketSlider.rxEvent.zone  = tempNodeChild.toElement().attribute(EVENT_ZONE);
        vscpPacket.vscpPacketSlider.rxEvent.subzone  = tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        vscpPacket.vscpPacketSlider.rxEvent.head  = tempNodeChild.toElement().attribute(EVENT_HEAD);
        vscpPacket.vscpPacketSlider.rxEvent.obid  = tempNodeChild.toElement().attribute(EVENT_OBID);
        vscpPacket.vscpPacketSlider.rxEvent.timeStamp  = tempNodeChild.toElement().attribute(EVENT_TIMESTAMP);
        vscpPacket.vscpPacketSlider.rxEvent.data  = tempNodeChild.toElement().attribute(EVENT_DATA);


        //Read sensor variable
        tempNodeChild = list.at(VSCP_PACKET_SLIDER_VARIABLE_CONFIGURE);
        vscpPacket.vscpPacketSlider.packetSliderVariable.name = tempNodeChild.toElement().attribute(VARIABLE_NAME);
        vscpPacket.vscpPacketSlider.packetSliderVariable.groupId = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
        vscpPacket.vscpPacketSlider.packetSliderVariable.allowedFrom = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
        vscpPacket.vscpPacketSlider.packetSliderVariable.allowedTo = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
        vscpPacket.vscpPacketSlider.packetSliderVariable.allowedTime = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
        allowedDays = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
        data = allowedDays.data();
        while (!data->isNull())
        {

            //qDebug() << data->toAscii();
            if(iterator == 0)
            {
                if(data->toAscii() == 'm')
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.mon = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.mon = "false";
                }
            }
            else if(iterator == 1)
            {
                if(data->toAscii() == 't')
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.tue = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.tue = "false";
                }
            }
            else if(iterator == 2)
            {
                if(data->toAscii() == 'w')
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.wed = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.wed = "false";
                }
            }
            else if(iterator == 3)
            {
                if(data->toAscii() == 't')
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.thur = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.thur = "false";
                }
            }
            else if(iterator == 4)
            {
                if(data->toAscii() == 'f')
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.fri = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.fri = "false";
                }
            }
            else if(iterator == 5)
            {
                if(data->toAscii() == 's')
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.sat = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.sat = "false";
                }
            }
            else if(iterator == 6)
            {
                if(data->toAscii() == 's')
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.sun = "true";
                }
                else
                {
                    vscpPacket.vscpPacketSlider.packetSliderVariable.allowedDays.sun = "false";
                }
            }


            ++data;
            ++iterator;
        }

        vscpPacket.vscpPacketSlider.packetSliderVariable.action = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
        vscpPacket.vscpPacketSlider.packetSliderVariable.actionParameters = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS);
        controlVarString =  tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
        controlVar = controlVarString.toUInt(&ok, 0);
        //controlVar = controlVarString.toAscii().toHex().toInt();

        if((uint32_t)controlVar & (uint32_t)(1<<31))
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.EnableRow = "true";
        }
        else
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.EnableRow = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<29))
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.endScan = "true";
        }
        else
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.endScan = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<5))
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.checkIndex = "true";
        }
        else
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.checkIndex = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<4))
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.checkzone = "true";
        }
        else
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.checkzone = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<3))
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.checkSubzone = "true";
        }
        else
        {
            vscpPacket.vscpPacketSlider.packetSliderVariable.control.checkSubzone = "false";
        }
        vscpPacket.vscpPacketSlider.packetSliderVariable.class_value = tempNodeChild.toElement().attribute(VARIABLE_CLASS);
        vscpPacket.vscpPacketSlider.packetSliderVariable.type_value = tempNodeChild.toElement().attribute(VARIABLE_TYPE);
        vscpPacket.vscpPacketSlider.packetSliderVariable.guid = tempNodeChild.toElement().attribute(VARIABLE_GUID);
        vscpPacket.vscpPacketSlider.packetSliderVariable.priority = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
        vscpPacket.vscpPacketSlider.packetSliderVariable.index = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
        vscpPacket.vscpPacketSlider.packetSliderVariable.zone = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
        vscpPacket.vscpPacketSlider.packetSliderVariable.subzone = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
        vscpPacket.vscpPacketSlider.packetSliderVariable.comments = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);

    }
    else if (vscpPacketType == PACKET_VARIABLE_SWITCH_TEXT)
    {

        vscpPacket.packetType = VARIABLE_BUTTON_PACKET_TYPE;

        //Read switch websocket configuration
        tempNodeChild = list.at(VSCP_VARIABLE_SWITCH_WEBSOCKET_CONFIGURE);
        vscpPacket.vscpPacketVariableSwitch.idIncImage = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_INC_ID);
        vscpPacket.vscpPacketVariableSwitch.idDecImage = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_DEC_ID);
        vscpPacket.vscpPacketVariableSwitch.idLocalTxt = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_LOCAL_TXT_ID);
        vscpPacket.vscpPacketVariableSwitch.idRemoteTxt = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_REMOTE_TXT_ID);
        vscpPacket.vscpPacketVariableSwitch.url = tempNodeChild.toElement().attribute(SLIDER_URL);
        vscpPacket.vscpPacketVariableSwitch.maxValue = tempNodeChild.toElement().attribute(SLIDER_MAX);
        vscpPacket.vscpPacketVariableSwitch.minValue = tempNodeChild.toElement().attribute(SLIDER_MIN);
        vscpPacket.vscpPacketVariableSwitch.userName = tempNodeChild.toElement().attribute(SLIDER_USERNAME);
        vscpPacket.vscpPacketVariableSwitch.passWord = tempNodeChild.toElement().attribute(SLIDER_PASSWORD);
        vscpPacket.vscpPacketVariableSwitch.domain = tempNodeChild.toElement().attribute(SLIDER_DOMAIN);

        //Read switch tx on event
        tempNodeChild = list.at(VSCP_VARIABLE_SWITCH_TX_EVENT);
        vscpPacket.vscpPacketVariableSwitch.txEvent.class_value = tempNodeChild.toElement().attribute(EVENT_CLASS);
        vscpPacket.vscpPacketVariableSwitch.txEvent.type_value  = tempNodeChild.toElement().attribute(EVENT_TYPE);
        vscpPacket.vscpPacketVariableSwitch.txEvent.guid  = tempNodeChild.toElement().attribute(EVENT_GUID);
        vscpPacket.vscpPacketVariableSwitch.txEvent.zone  = tempNodeChild.toElement().attribute(EVENT_ZONE);
        vscpPacket.vscpPacketVariableSwitch.txEvent.subzone  = tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        vscpPacket.vscpPacketVariableSwitch.txEvent.head  = tempNodeChild.toElement().attribute(EVENT_HEAD);
        vscpPacket.vscpPacketVariableSwitch.txEvent.obid  = tempNodeChild.toElement().attribute(EVENT_OBID);
        vscpPacket.vscpPacketVariableSwitch.txEvent.timeStamp  = tempNodeChild.toElement().attribute(EVENT_TIMESTAMP);
        vscpPacket.vscpPacketVariableSwitch.txEvent.data  = tempNodeChild.toElement().attribute(EVENT_DATA);

        //Read switch tx on event
        tempNodeChild = list.at(VSCP_VARIABLE_SWITCH_RX_EVENT);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.class_value = tempNodeChild.toElement().attribute(EVENT_CLASS);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.type_value  = tempNodeChild.toElement().attribute(EVENT_TYPE);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.guid  = tempNodeChild.toElement().attribute(EVENT_GUID);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.zone  = tempNodeChild.toElement().attribute(EVENT_ZONE);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.subzone  = tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.head  = tempNodeChild.toElement().attribute(EVENT_HEAD);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.obid  = tempNodeChild.toElement().attribute(EVENT_OBID);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.timeStamp  = tempNodeChild.toElement().attribute(EVENT_TIMESTAMP);
        vscpPacket.vscpPacketVariableSwitch.rxEvent.data  = tempNodeChild.toElement().attribute(EVENT_DATA);


        //Read sensor variable
        tempNodeChild = list.at(VSCP_VARIABLE_SWITCH_VARIABLE_CONFIGURE);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.name = tempNodeChild.toElement().attribute(VARIABLE_NAME);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.groupId = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedFrom = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedTo = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedTime = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
        allowedDays = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
        data = allowedDays.data();
        while (!data->isNull())
        {

            //qDebug() << data->toAscii();
            if(iterator == 0)
            {
                if(data->toAscii() == 'm')
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.mon = "true";
                }
                else
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.mon = "false";
                }
            }
            else if(iterator == 1)
            {
                if(data->toAscii() == 't')
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.tue = "true";
                }
                else
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.tue = "false";
                }
            }
            else if(iterator == 2)
            {
                if(data->toAscii() == 'w')
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.wed = "true";
                }
                else
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.wed = "false";
                }
            }
            else if(iterator == 3)
            {
                if(data->toAscii() == 't')
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.thur = "true";
                }
                else
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.thur = "false";
                }
            }
            else if(iterator == 4)
            {
                if(data->toAscii() == 'f')
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.fri = "true";
                }
                else
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.fri = "false";
                }
            }
            else if(iterator == 5)
            {
                if(data->toAscii() == 's')
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.sat = "true";
                }
                else
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.sat = "false";
                }
            }
            else if(iterator == 6)
            {
                if(data->toAscii() == 's')
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.sun = "true";
                }
                else
                {
                    vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.allowedDays.sun = "false";
                }
            }


            ++data;
            ++iterator;
        }

        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.action = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.actionParameters = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS);
        controlVarString =  tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
        controlVar = controlVarString.toUInt(&ok, 0);
        //controlVar = controlVarString.toAscii().toHex().toInt();

        if((uint32_t)controlVar & (uint32_t)(1<<31))
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.EnableRow = "true";
        }
        else
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.EnableRow = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<29))
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.endScan = "true";
        }
        else
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.endScan = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<5))
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkIndex = "true";
        }
        else
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkIndex = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<4))
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkzone = "true";
        }
        else
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkzone = "false";
        }

        if((uint32_t)controlVar & (uint32_t)(1<<3))
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkSubzone = "true";
        }
        else
        {
            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.control.checkSubzone = "false";
        }
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.class_value = tempNodeChild.toElement().attribute(VARIABLE_CLASS);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.type_value = tempNodeChild.toElement().attribute(VARIABLE_TYPE);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.guid = tempNodeChild.toElement().attribute(VARIABLE_GUID);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.priority = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.index = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.zone = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.subzone = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
        vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.comments = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);

    }
    else
    {
        // undefined packet type
        vscpPacket.packetType = UNDEFINED_PACKET_TYPE;
    }

    //Append the vscp Packet
    testCaseStepCanPacketList.append(vscpPacket);
    //Append the vscp Packet to undo list
    testCaseStepCanPacket_undo.append(vscpPacket);
    //Append the vscp Packet to undo Room list
    testCaseStepCanPacket_undoRoom.append(vscpPacket);
}

// update expected packet --
void MainWindow::UpdateListForCanPacket(QList<T_testCaseStepCanPacket> &testCaseStepCanPacketList, QDomNode &tempNode, uint8_t teststep)
{
    QDomNode tempNodeChild;
    QDomNodeList list;
    QString packet;
    T_testCaseStepCanPacket canPacket;

    //Create the list
    list = tempNode.childNodes();

    // Store the test step number
    canPacket.stepnumber = teststep;

    //Read test step packet type
    tempNodeChild = list.at(TEST_STEP_PACKET_TYPE);
    packet = tempNodeChild.toElement().text();

    if(packet == CAN_PACKET)
    {
        //Read test step can id
        tempNodeChild = list.at(TEST_STEP_CAN_ID);
        canPacket.u16_CanId = tempNodeChild.toElement().text();

        //Read test step DLC
        tempNodeChild = list.at(TEST_STEP_CAN_DLC);
        canPacket.u8_dlc = tempNodeChild.toElement().text();

        //Read test step byte 0
        tempNodeChild = list.at(TEST_STEP_CAN_BYTE0);
        canPacket.u8_byte0 = tempNodeChild.toElement().text();

        //Read test step byte 1
        tempNodeChild = list.at(TEST_STEP_CAN_BYTE1);
        canPacket.u8_byte1 = tempNodeChild.toElement().text();

        //Read test step byte 2
        tempNodeChild = list.at(TEST_STEP_CAN_BYTE2);
        canPacket.u8_byte2 = tempNodeChild.toElement().text();

        //Read test step byte 3
        tempNodeChild = list.at(TEST_STEP_CAN_BYTE3);
        canPacket.u8_byte3 = tempNodeChild.toElement().text();

        //Read test step byte 4
        tempNodeChild = list.at(TEST_STEP_CAN_BYTE4);
        canPacket.u8_byte4 = tempNodeChild.toElement().text();

        //Read test step byte 5
        tempNodeChild = list.at(TEST_STEP_CAN_BYTE5);
        canPacket.u8_byte5 = tempNodeChild.toElement().text();

        //Read test step byte 6
        tempNodeChild = list.at(TEST_STEP_CAN_BYTE6);
        canPacket.u8_byte6 = tempNodeChild.toElement().text();

        //Read test step byte 7
        tempNodeChild = list.at(TEST_STEP_CAN_BYTE7);
        canPacket.u8_byte7 = tempNodeChild.toElement().text();

        //Append the CAN Packet
        testCaseStepCanPacketList.append(canPacket);

    }
    else
    {
        //TCP
    }

}
