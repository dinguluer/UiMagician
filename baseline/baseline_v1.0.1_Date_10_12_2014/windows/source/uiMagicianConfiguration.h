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


#ifndef GENNYCONFIGURATION_H
#define GENNYCONFIGURATION_H

/*---------------------------------------------------------------------------
** Includes
*/

#include "../common/cal/sys_types.h"
#include "../common/classTypes/vscp_class.h"
#include "../common/classTypes/vscp_type.h"
#include "../common/classTypes/vscpClassTypeObject.h"
#include "../common/actionCodes/actioncodes.h"
#include "../common/priority/priority.h"
#include "../common/codingIndex/codingIndex.h"

/*---------------------------------------------------------------------------
** Defines and Macros
*/
// Text to be inserted in tableview Horizontal Header
//#define COLUMN_ZERO_TEXT    "Test Step"
//#define COLUMN_ONE_TEXT     "Function \n Tested"
//#define COLUMN_TWO_TEXT     "Test \n Description"
//#define COLUMN_THREE_TEXT   "Packet \n Tx"
//#define COLUMN_FOUR_TEXT    "Expected \n Rx Response"
//#define COLUMN_FIVE_TEXT    "Packet \n Rx"
//#define COLUMN_SIX_TEXT     "Pass/Fail"
//#define COLUMN_SEVEN_TEXT   "Comment"
#define COLUMN_ZERO_TEXT    "Device name"
#define COLUMN_ONE_TEXT     "Device \n Type"
#define COLUMN_TWO_TEXT     "Device \n Sub Type"
#define COLUMN_THREE_TEXT   "Device \n Image"
//#define COLUMN_FOUR_TEXT    "Device \n Info"
#define COLUMN_FOUR_TEXT    "Device \n Group"
#define COLUMN_FIVE_TEXT    "Device \n Packet"
//#define COLUMN_SIX_TEXT     "Pass/Fail"
//#define COLUMN_SEVEN_TEXT   "Comment"
// Text to be inserted in tableview Vertical Header
//#define ROW_TEXT   "Test-Step-"
//#define ROW_ZERO_TEXT   "Test-Step-1"
//#define ROW_ONE_TEXT    "Test-Step-2"
//#define ROW_TWO_TEXT    "Test-Step-3"
//#define ROW_THREE_TEXT  "Test-Step-4"
//#define ROW_FOUR_TEXT   "Test-Step-5"
//#define ROW_FIVE_TEXT   "Test-Step-6"
#define SELECT_RIGHT_DEVICE_TYPE    "Device type incorrect "

// Pop up message to show delete test step
#define DELETE_CONFIRM_MESSAGE    "Are you sure you want delete ROW = "
//
#define XML_REDO_CONFIRM_MESSAGE    "Are you sure to Redo XML ?"
//
#define XML_UNDO_CONFIRM_MESSAGE    "Are you sure to Undo XML ?"
// Model initial rows & columns
#define MODEL_INITIAL_ROWS    1
//#define MODEL_INITIAL_COLUMNS 8
#define MODEL_INITIAL_COLUMNS 6
// xml files related
#define CREATE_NEW_FILE       true
#define OPEN_EXISTING_FILE    false
// file open dialog message
#define NEW_FILE_CONFIRM_MESSAGE "Are you sure you want delete Current Xml file "
#define OPEN_FILE_CONFIRM_MESSAGE "Are you sure you want delete Current Xml file "
// Pop up message
#define CREATE_OPEN_HOUSE_CONFIGUATION_FILE "Create/Open House Configuration file"
#define NOTHING_TO_CLOSE "No file is opened - to close"
#define NO_TEST_CASE_EXIST        "No Test Case Exist"
#define SAVE_DELETE_NEW_EXISTING_NODE "Save delete existing node"
#define PRESENT_NODE_IS_NEW_NODE      "Present node is new node"
#define PROPERLY_FILL_THE_TEST_CASE "Properly fill the test case "
#define DELETE_POP_UP_MESSAGE       "Nothing is there to delete"
#define NO_TEST_STEP_EXIST_POP_UP_MESSAGE  "No test case exist"
#define CLOSE_EXISTING_FILE                "Close Existing File"
#define MESSAGE_SAVE_PRESSESD              "Close XML button - will  save file on exit"
#define NO_NODE_EXIST_MESSAGE              "create new test case"
#define TEST_CASE_VERIFY_MESSAGE           "Test Case Verify Already Open"
//#define TEST_VIEW_NOT_FILLED_CORRECTLY    -1
// Xml node labels
#define TEST_CASE_PREFIX         "TestCase "
#define ROOM_NODE_PREFIX    "Room"
#define ROOM_NAME           "RoomName"
#define FLOOR_NAME          "FloorName"
#define HOUSE_NAME          "HouseName"
//// Read textview macros
//#define TEST_CASE_DEFAULT           default
//#define TEST_CASE_TEST_STEP         0
//#define TEST_CASE_FUNCTION_TESTED   1
//#define TEST_CASE_TEST_DESCRIPTION  2
//#define TEST_CASE_PACKET_TX         3
//#define TEST_CASE_EXPECTED_RESPONSE 4
//#define TEST_CASE_PACKET_RX         5
//#define TEST_CASE_PASS_FAIL         6
//#define TEST_CASE_COMMENT           7

// Read textview macros
#define DEVICE_DESCRIPTION_DEFAULT           default
#define DEVICE_DESCRIPTION_DEVICE_NAME         0
#define DEVICE_DESCRIPTION_DEVICE_TYPE         1
#define DEVICE_DESCRIPTION_DEVICE_SUB_TYPE     2
#define DEVICE_DESCRIPTION_DEVICE_IMAGE        3
#define DEVICE_DESCRIPTION_DEVICE_INFO         4
#define DEVICE_DESCRIPTION_DEVICE_PACKET       5

#define DEVICE_INITIAL_ROW_NUMBER                     0
#define DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN       5

// VSCP packet type
#define UNDEFINED_PACKET_TYPE             0
#define SWITCH_PACKET_TYPE                1
#define SENSOR_PACKET_TYPE                2
#define SLIDER_PACKET_TYPE                3
#define VARIABLE_BUTTON_PACKET_TYPE       4

#define PACKET_INITIAL_STRING          "\n\n\n\n\n\n\n\n"
#define UNDEFINED_PACKET_STRING        "ENTER DEVICE TYPE & PACKET "
#define NOTHING_TO_UNDO                "Nothing to undo"
#define NOTHING_TO_REDO                "Nothing to redo"


//#define TEST_CASE_PASS_FAIL         6
//#define TEST_CASE_COMMENT           7
//#define TEST_STEP_TEXT         "TestStep"
//#define FUNCTION_TESTED_TEXT   "FunctionTested"
//#define TEST_DESCRIPTION_TEXT  "TestDescription"
////#define EXPECTED_RESPONSE_TEXT "ResponseText"
//#define PACKET_TX_TEXT         "PacketTx"
//#define PACKET_EXPECTED_RX_TEXT "PacketExpectedRx"
//#define PACKET_RX_TEXT         "PacketRx"
//#define PASS_FAIL_TEXT         "PassFail"
//#define COMMENT_TEXT           "Comment"
#define DEVICE_NAME_TEXT         "DeviceName"
#define DEVICE_TYPE_TEXT         "DeviceType"
#define DEVICE_SUB_TYPE_TEXT     "DeviceSubType"
//#define EXPECTED_RESPONSE_TEXT "ResponseText"
#define DEVICE_PACKET_TEXT       "DevicePacket"
#define PACKET_EXPECTED_RX_TEXT  "PacketExpectedRx"
#define DEVICE_IMAGE_TEXT        "DeviceImage"
#define DEVICE_INFO_TEXT         "DeviceInfo"
/*#define PASS_FAIL_TEXT         "PassFail"
#define COMMENT_TEXT           "Comment"*/
//Tree vieW
#define NO_NODE_TO_SAVE    0
#define FIRST_NODE_OF_TREE 0
#define NO_NODE_TO_DISPLAY -1
#define NO_TREE_TOP_ITEM_TO_DELETE -1
#define SELECTION_CHANGED_ONCE 1
#define SELECTION_CHANGED_TWICE 2
//#define TEST_CASE_NAME_NUMBER          0
#define ROOM_NAME_NUMBER               0
//#define TEST_CASE_DESCRIPTION_NUMBER   1
#define FLOOR_NAME_NUMBER           1
#define HOUSE_NAME_NUMBER           2
#define DEVICE_NODE_NUMBER          3
//CAN packet description
#define TEST_STEP_PACKET_TYPE          0
#define TEST_STEP_CAN_ID               1
#define TEST_STEP_CAN_DLC              2
#define TEST_STEP_CAN_BYTE0            3
#define TEST_STEP_CAN_BYTE1            4
#define TEST_STEP_CAN_BYTE2            5
#define TEST_STEP_CAN_BYTE3            6
#define TEST_STEP_CAN_BYTE4            7
#define TEST_STEP_CAN_BYTE5            8
#define TEST_STEP_CAN_BYTE6            9
#define TEST_STEP_CAN_BYTE7            9
//vscp packet description
#define VSCP_PACKET_SENSOR_WEBSOCKET_CONFIGURE          0
#define VSCP_PACKET_SENSOR_VARIABLE_CONFIGURE           1

#define VSCP_PACKET_SWITCH_WEBSOCKET_CONFIGURE          0
#define VSCP_PACKET_SWITCH_TX_ON_EVENT                  1
#define VSCP_PACKET_SWITCH_TX_OFF_EVENT                 2
#define VSCP_PACKET_SWITCH_RX_ON_EVENT                  3
#define VSCP_PACKET_SWITCH_RX_OFF_EVENT                 4
#define VSCP_PACKET_SWITCH_VARIABLE_CONFIGURE           5

#define VSCP_PACKET_SLIDER_WEBSOCKET_CONFIGURE          0
#define VSCP_PACKET_SLIDER_TX_EVENT                     1
#define VSCP_PACKET_SLIDER_RX_EVENT                     2
#define VSCP_PACKET_SLIDER_VARIABLE_CONFIGURE           3

#define VSCP_VARIABLE_SWITCH_WEBSOCKET_CONFIGURE          0
#define VSCP_VARIABLE_SWITCH_TX_EVENT                     1
#define VSCP_VARIABLE_SWITCH_RX_EVENT                     2
#define VSCP_VARIABLE_SWITCH_VARIABLE_CONFIGURE           3


// Xml operations
//#define ROOT_ELEMENT_DETAILS  "TestCases"
#define ROOT_ELEMENT_DETAILS  "Rooms_Zone"
#define FAIL_TO_OPEN_FILE      0
#define SUCCESS_TO_OPEN_FILE   1
#define TEST_CASE_HEADER       "TC"
#define ROOM_DEVICE_HEADER       "Device"
#define XML_ROOTNULL_MESSAGE   "xmlRoot NULL"
// Deligate operation
#define TX_PACKET_COLUMN_DELIGATE       (3u)
#define EXPECTED_PACKET_COLUMN_DELIGATE (4u)
#define RX_PACKET_COLUMN_DELIGATE       (5u)
#define RESULT_PACKET_COLUMN_DELIGATE   (6u)

#define DEVICE_NAME_COLUMN     (0u)
#define DEVICE_TYPE_COLUMN     (1u)
#define DEVICE_SUB_TYPE_COLUMN (2u)
#define DEVICE_IMAGE_COLUMN_DELIGATE    (3u)
#define DEVICE_INFO_COLUMN_DELIGATE     (4u)
#define DEVICE_PACKET_COLUMN_DELIGATE   (5u)

#define LEFT_TREE_WIDGET_WIDTH          (300U)

//Undo messages
#define NEW_DEVICE_CREATED_NOTHING_TO_UNDO "Device  - Nothing to Undo"
#define NEW_DEVICE_CREATED_NOTHING_TO_REDO "Device  - Nothing to Redo"

#define NEW_ROOM_CREATED_NOTHING_TO_UNDO "Room  - Nothing to Undo"
#define NEW_ROOM_CREATED_NOTHING_TO_REDO "Room  - Nothing to Redo"

// CAN packet
#define PACKET_TYPE  "PacketType"
#define CAN_PACKET   "1"
#define TCP_PACKET "2"
#define CAN_ID       "CanID"
#define DLC          "dlc"
#define BYTE_0       "byte_0"
#define BYTE_1       "byte_1"
#define BYTE_2       "byte_2"
#define BYTE_3       "byte_3"
#define BYTE_4       "byte_4"
#define BYTE_5       "byte_5"
#define BYTE_6       "byte_6"
#define BYTE_7       "byte_7"


#define DEVICE_SWITCH    "Switch"
#define DEVICE_SENSOR    "Sensor"

// Device sub type string
#define SWITCH_SUB_TYPE_ONE      "Switch - ON/OFF"
#define SWITCH_SUB_TYPE_TWO      "Switch - Variable Slider"
#define SWITCH_SUB_TYPE_THREE    "Switch - Variable Button"
#define SENSOR_SUB_TYPE_DEFAULT  "Sensor - Default"

// Device Info string
#define DEVICE_INFO_TYPE_ONE      "Light"
#define DEVICE_INFO_TYPE_TWO      "Accessories"
#define DEVICE_INFO_TYPE_THREE    "Blind Door Window"
#define DEVICE_INFO_TYPE_FOUR     "Sensor"
#define DEVICE_INFO_TYPE_FIVE     "Temperature Controller"


#define PACKET_SENSOR_TEXT     "SensorPacket"
#define PACKET_SWITCH_TEXT     "SwitchPacket"
#define PACKET_SLIDER_TEXT     "SliderPacket"
#define PACKET_VARIABLE_SWITCH_TEXT     "VariableSwitchPacket"

/**/
#define WEBSOCKET_CONFIGURE    "WebsocketConfigure"
#define VARIABLE_CONFIGURE     "VariableConfigure"
#define TX_ON_EVENT            "TxOnEvent"
#define TX_OFF_EVENT           "TxOffEvent"
#define RX_ON_EVENT            "RxOnEvent"
#define RX_OFF_EVENT           "RxOffEvent"

/*Slider*/
#define TX_EVENT           "TxEvent"
#define RX_EVENT           "RxEvent"


/* Sensor websocket */
#define SENSOR_ID              "id"
#define SENSOR_GRAPH_ID        "graphId"
#define SENSOR_GRAPH_UNIT_ID   "graphUnitId"
#define SENSOR_GRAPH_TYPE      "graphType"
#define SENSOR_ID              "id"
#define SENSOR_REMOTE_TXT_ID   "idRemoteTxt"
#define SENSOR_URL             "url"
#define SENSOR_CLASS           "class"
#define SENSOR_TYPE            "type"
#define SENSOR_CODING_INDEX    "codingIndex"
#define SENSOR_DECIMALS        "Decimals"
#define SENSOR_FORMAT_STRING   "FormatString"
#define SENSOR_GUID            "Guid"
#define SENSOR_CALLACK         "Callback"
#define SENSOR_USERNAME        "userName"
#define SENSOR_PASSWORD        "password"
#define SENSOR_DOMAIN          "domain"

#define SENSOR_ENABLE_MESUREMENT_CODING_INDEX        "bmeasurement"

/* variable websocket*/
#define VARIABLE_NAME               "Name"
#define VARIABLE_GROUPID            "GroupID"
#define VARIABLE_ALLOWED_FROM       "AllowedFrom"
#define VARIABLE_ALLOWED_TO         "AllowedTo"
#define VARIABLE_ALLOWED_TIME       "AllowedTime"
#define VARIABLE_ALLOWED_DAYS       "AllowedDays"
#define VARIABLE_ACTION             "Action"
#define VARIABLE_ACTION_PARAMETERS  "ActionParameters"
#define VARIABLE_CONTROL            "Control"
#define VARIABLE_CLASS              "Class"
#define VARIABLE_TYPE               "Type"
#define VARIABLE_GUID               "Guid"
#define VARIABLE_PRIORITY           "Priority"
#define VARIABLE_INDEX              "Index"
#define VARIABLE_ZONE               "Zone"
#define VARIABLE_SUBZONE            "Subzone"
#define VARIABLE_COMMENTS           "Comments"
#define VARIABLE_SWITCH_CLASS_ON    "ClassOn"
#define VARIABLE_SWITCH_TYPE_ON     "TypeOn"
#define VARIABLE_SWITCH_CLASS_OFF    "ClassOff"
#define VARIABLE_SWITCH_TYPE_OFF     "TypeOff"
#define VARIABLE_ACTION_PARAMETERS_SET  "ActionParametersSet"
#define VARIABLE_ACTION_PARAMETERS_RESET  "ActionParametersReset"

/* Switch websocket */
#define SWITCH_ID              "id"
#define SWITCH_URL             "url"
#define SWITCH_BLOCAL          "bLocal"
#define SWITCH_BNOSTATE        "bNoState"
#define SWITCH_USERNAME        "userName"
#define SWITCH_PASSWORD        "password"
#define SWITCH_DOMAIN          "domain"
/* Event websocket*/
#define EVENT_CLASS                "Class"
#define EVENT_TYPE                 "Type"
#define EVENT_GUID                 "Guid"
#define EVENT_INDEX                "Index"
#define EVENT_ZONE                 "Zone"
#define EVENT_SUBZONE              "Subzone"
#define EVENT_HEAD                 "Head"
#define EVENT_OBID                 "Obid"
#define EVENT_TIMESTAMP            "Timestamp"
#define EVENT_DATA                 "Data"

//Slider websocket
#define SLIDER_ID              "id"
#define SLIDER_LOCAL_TXT_ID    "idLocalTxt"
#define SLIDER_REMOTE_TXT_ID   "idRemoteTxt"
#define SLIDER_URL             "url"
#define SLIDER_MAX             "Max"
#define SLIDER_MIN             "Min"
#define SLIDER_USERNAME        "userName"
#define SLIDER_PASSWORD        "password"
#define SLIDER_DOMAIN          "domain"

//Slider websocket
//#define VARIABLE_SWITCH_ID                 "id"
#define VARIABLE_SWITCH_INC_ID             "IncId"
#define VARIABLE_SWITCH_DEC_ID             "DecId"
#define VARIABLE_SWITCH_LOCAL_TXT_ID       "idLocalTxt"
#define VARIABLE_SWITCH_REMOTE_TXT_ID      "idRemoteTxt"
#define VARIABLE_SWITCH_URL                "url"
#define VARIABLE_SWITCH_MAX                "Max"
#define VARIABLE_SWITCH_MIN                "Min"
#define VARIABLE_USERNAME                  "userName"
#define VARIABLE_PASSWORD                  "password"
#define VARIABLE_DOMAIN                    "domain"

#define DEFAULT_HOUSE_NAME         "One"


#define GRAPH_TYPE_LINE                 "line"
#define GRAPH_TYPE_BAR                  "bar"
#define GRAPH_TYPE_AREA                 "area"

/* Typedef */

/*
** Typedef for reading data from the test case edit view
*/
typedef struct {
    QString u8_deviceName;
    QString u8_deviceType;
    QString u8_deviceSubType;
    QString u8_devicePacket;
    QString u8_deviceImage;
    QString u8_deviceInfo;
    //QString u8_passFail;
    //QString u8_comment;
}T_testStepDetails;

/*
** Typedef for reading data from the test case edit view
*/
typedef struct {
    uint8_t stepnumber;
    QString u16_CanId;
    QString u8_dlc;
    QString u8_byte0;
    QString u8_byte1;
    QString u8_byte2;
    QString u8_byte3;
    QString u8_byte4;
    QString u8_byte5;
    QString u8_byte6;
    QString u8_byte7;
}T_testCaseStepCanPacket;

/*
** Typedef for allowed days
*/
typedef struct {
    QString mon;
    QString tue;
    QString wed;
    QString thur;
    QString fri;
    QString sat;
    QString sun;
}T_days;

/*
** Typedef for allowed days
*/
typedef struct {
    QString EnableRow;
    QString checkIndex;
    QString checkzone;
    QString endScan;
    QString checkSubzone;
}T_control;

/*
** Typedef for reading data from the variable ui
*/
typedef struct {
    QString name;
    QString groupId;
    QString allowedFrom;
    QString allowedTo;
    QString allowedTime;
    T_days allowedDays;
    QString action;
    QString actionParameters;
    T_control control;
    QString class_value;
    QString type_value;
    QString guid;
    QString priority;
    QString index;
    QString zone;
    QString subzone;
    QString comments;
}T_variableConfigure;

typedef struct {
    QString name;
    QString groupId;
    QString allowedFrom;
    QString allowedTo;
    QString allowedTime;
    T_days allowedDays;
    QString action;
    QString actionParametersSet;
    QString actionParametersReset;
    T_control control;
    QString class_value_on;
    QString type_value_on;
    QString class_value_off;
    QString type_value_off;
    QString guid;
    QString priority;
    QString index;
    QString zone;
    QString subzone;
    QString comments;
}T_variableConfigureSwitch;


/*
** Typedef for reading data from the event ui
*/
typedef struct {
    QString class_value;
    QString type_value;
    QString guid;
    QString index;
    QString zone;
    QString subzone;
    QString head;
    QString obid;
    QString timeStamp;
    QString data;
}T_event;


/*
** Typedef for reading data from the slider event ui
*/
typedef struct {
    QString class_value;
    QString type_value;
    QString guid;
    QString index;
    QString zone;
    QString subzone;
    QString head;
    QString obid;
    QString timeStamp;
    QString data;
}T_eventSlider;

/*
** Typedef for reading data from the websocketpacketsensor ui
*/
typedef struct {
    QString id;
    QString graphId;
    QString graphUnitId;
    QString graphType;
    QString idRemoteTxt;
    QString url;
    QString class_value;
    QString type_value;
    QString codingIndex;
    QString decimals;
    QString formatString;
    QString guid;
    QString callback;
    QString userName;
    QString passWord;
    QString domain;
    T_variableConfigure packetSensorVariable;
}T_widgetwebsocketPacketsensor;



/*
** Typedef for reading data from the WidgetWebsocketPacketSlider ui
*/
typedef struct {
    QString id;
    QString idLocalTxt;
    QString idRemoteTxt;
    QString url;
    QString minValue;
    QString maxValue;
    QString userName;
    QString passWord;
    QString domain;
    T_eventSlider txEvent;
    T_eventSlider rxEvent;
    T_variableConfigure packetSliderVariable;
}T_widgetWebsocketPacketSlider;


/*
** Typedef for reading data from the WidgetWebsocketPacketVariableSwitch;
 ui
*/
typedef struct {
    QString idIncImage;
    QString idDecImage;
    QString idLocalTxt;
    QString idRemoteTxt;
    QString url;
    QString minValue;
    QString maxValue;
    QString userName;
    QString passWord;
    QString domain;
    T_eventSlider txEvent;
    T_eventSlider rxEvent;
    T_variableConfigure packetVariableSwitchVariable;
}T_widgetWebsocketPacketVariableSwitch;

/*
** Typedef for reading data from the WidgetWebsocketPacketSwitch ui
*/
typedef struct {
    QString id;
    QString url;
    QString bLocal;
    QString bNoState;
    QString userName;
    QString passWord;
    QString domain;
    T_event txOnEvent;
    T_event txOffEvent;
    T_event rxOnEvent;
    T_event rxOffEvent;
    T_variableConfigureSwitch packetSwitchVariable;
}T_widgetWebsocketPacketSwitch;


/*
** Typedef for vscp device packet
*/
typedef struct {
    uint8_t stepnumber;
    uint8_t packetType;
    T_widgetWebsocketPacketSwitch vscpPacketSwitch;
    T_widgetwebsocketPacketsensor vscpPacketSensor;
    T_widgetWebsocketPacketSlider vscpPacketSlider;
    T_widgetWebsocketPacketVariableSwitch vscpPacketVariableSwitch;
}T_vscpDevicePacket;

/*
** Typedef for
*/
typedef struct {
    QString floorName;
    QList<uint16_t> floorIndexList;
}T_packetFloor;

/*
** Typedef for
*/
typedef struct {
    QString houseName;
    QList<T_packetFloor> houseFloorList;
}T_packetHouse;

typedef struct {
    QString houseName;
    QString floorName;
    QString roomName;
    QString deviceName;
}T_packetDeviceLocation;

#endif // GENNYCONFIGURATION_H
