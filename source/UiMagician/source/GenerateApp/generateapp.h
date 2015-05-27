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


#ifndef GENERATEAPP_H
#define GENERATEAPP_H

#include <QtGui>
#include <QtXml>

#include "../uiMagicianConfiguration.h"

#define SINGLE_FLOOR_HOUSE   "One"
#define MULTI_FLOOR_HOUSE    "Multi"

#define SINGLE_HOUSE   "One"
#define MULTI_HOUSE    "Multi"


#define VARIABLES_FILE_NAME  "/variables.xml"
#define VARIABLES_ROOT_NAME  "persistent"
#define DM_FILE_NAME         "/dm.xml"
#define DM_ROOT_NAME         "dm"

#define ROOM_NAME_INDEX            0
#define FLOOR_NAME_INDEX           1
#define HOUSE_NAME_INDEX           2
#define DEVICE_INDEX               3

#define DEVICE_NAME_INDEX          0
#define DEVICE_TYPE_INDEX          1
#define DEVICE_SUB_TYPE_INDEX      2
#define DEVICE_IMAGE_INDEX         3
#define DEVICE_INFO_INDEX          4
#define DEVICE_PACKET_INDEX        5

#define WEBSOCKET_INDEX            0
#define ON_TX_EVENT_INDEX          1
#define OFF_TX_EVENT_INDEX         2
#define ON_RX_EVENT_INDEX          3
#define OFF_RX_EVENT_INDEX         4

#define INFO_NODES_COUNT   100

/*
** Typedef for
*/
typedef struct {
    QString floorName;
    QDomElement  floorRooms;
}T_packetFloorNodes;

/*
** Typedef for house node list
*/
typedef struct {
    QString houseName;
    QList<T_packetFloorNodes> floorNodeList;
    uint16_t groupsTotal;
    uint16_t lightsGroupTotal;
    uint16_t accessoriesGroupTotal;
    uint16_t blindDoorWindowGroupTotal;
    uint16_t sensorGroupTotal;
    uint16_t temperatureControllerGroupTotal;
}T_packetHouseNodes;

namespace Ui {
class GenerateApp;
}

class GenerateApp : public QDialog
{
    Q_OBJECT
    
public:
    explicit GenerateApp(QString xmlFileName, QDomElement &xmlRoot, QWidget *parent = 0);
    ~GenerateApp();

    // Create the HTML App
    void createHtmlApp();

    // Create the output folder
    void createOpFolder();

    // Create the home output folder
    void createHomeOpFolder(QString homeName);


    // close the home output files
    void closeHomeOpFiles();

    // Create the General header for HTML
    void createHtmlHead();

    //verify the xml is single floor or multiple floor
    void verifyHouseFloor(QList<T_packetHouse> &housePacketList, QDomNodeList &list);

    //Create floor room list
    void createFloorRoomList(QList<T_packetHouse> &housePacketList, QDomElement &xmlRoot );

    // Create the Html Body
    void createHtmlBody();

    // create the floor configure javascript files
    void createFloorCfgFiles();

    // Create div to select house
    void createHouseSelectDiv(QDomElement &NodeElementDivHouseSelect);

    // Create the multi floor DIV scrollable
    void createMultiFloorDivScrollable(QDomElement &NodeElementMultiFloorDivScrollable);

    // Create the single floor DIV scrollable
    void createSingleFloorDivScrollable(QDomElement &NodeElementSingleFloorDivScrollable);

    // Create the multi floor DIV scrollableMenu
    void createMultiFloorDivScrollableMenu(QDomElement &NodeElementMultiFloorDivScrollableMenu);

    // Create the floor DIV scrollableCenter
    void createFloorDivScrollableCenter(QDomElement &NodeElementMultiFloorDivScrollableCenter);

    //Create div fotter
    void createDivFotter(QDomElement &NodeElementChildTemp);

    // close the HTML File
    void closeHtmlFile();

    // close java script configure files
    void closeCfgfiles();


    //reInitialise global variables
    void reInitializeGlobalVariables();

    //get sensor Image URL
    void getSensorDeviceImage(uint16_t deviceImageNumber , QString &sensorImageSrc);

    //get switch Image URL
    void getSwitchDeviceImage(uint16_t deviceImageNumber , QString &imageOn, QString &imageOff);

    //get slider Image URL
    void getSliderDeviceImage(uint16_t deviceImageNumber , QString &imageSlider);

    //get switch variable button Image URL
    void getSwitchVariableButtonDeviceImage(uint16_t deviceImageNumber ,QString &switchButtonUpImageSrc, QString &switchButtonDownImageSrc);

    //prepare the Packet format for each device socket
    void prepareSocketConf(QDomNode &tempNodeDevicePacket, QString DeviceId, QString DeviceLocalTxtId, QString VariableButtonOneId, QString VariableButtonTwoId, QString deviceImage, QString houseName);

    //Append value to variables & dm xml files
    void prepareVariablesDmXmlFile(QDomNode &tempNodeChild, QString PacketType);

    //get total groups
    void getTotalGroups(int index);

    // Recursively delete the contents of the directory first
    bool removeDir(const QString & dirName);

    // Public variables
    QString xmlFileNameRef;
    QString htmlFileDirectoryPath;
    QString htmlFilePath;
    QFile htmlFile;
    QTextStream htmlStream;

    // Javascript floorCfg File
    QString floorCfgFileString;
    QString floorCfgFilePath;
    QFile floorCfgFile;
    QTextStream floorCfgFileStream;
    // Javascript socket FloorsSocketCfg File
    QString FloorsSocketCfgFileString;
    QString FloorsSwitchSocketCfgFileString;
    QString FloorsVariableSwitchSocketCfgFileString;
    QString FloorsVariableSliderSocketCfgFileString;
    QString FloorsSensorSocketCfgFileString;
    QString FloorsSocketCfgFilePath;
    QString SingleFloorGroupImageClass;
    QString SingleFloorGroupTxtClass;
    QFile FloorsSocketCfgFile;
    QTextStream FloorsSocketCfgFileStream;
    //
    //array of array
    QString houseFloorsSwitchSocketCfgFileString;
    QString houseFloorsSensorSocketCfgFileString;
    QString houseFloorsVariableSliderSocketCfgFileString;
    QString houseFloorsVariableSwitchSocketCfgFileString;
    //
    uint16_t sensorCount;
    uint16_t switchCount;
    uint16_t variableSwitchCount;
    uint16_t variableSliderCount;
    uint16_t sensorTotal;
    uint16_t switchTotal;
    uint16_t variableSwitchTotal;
    uint16_t variableSliderTotal;

    // ----> comment this
    uint16_t groupsTotal;
    uint16_t lightsGroupTotal;
    uint16_t accessoriesGroupTotal;
    uint16_t blindDoorWindowGroupTotal;
    uint16_t sensorGroupTotal;
    uint16_t temperatureControllerGroupTotal;

    bool flagLightsGroup;
    bool flagAccessoriesGroup;
    bool flagBlindDoorWindowGroup;
    bool flagsensorGroup;
    bool flagTemperatureControllerGroup;

    uint16_t sensorFlag;
    uint16_t switchFlag;
    uint16_t variableSwitchFlag;
    uint16_t variableSliderFlag;

    uint8_t firstLoopFlag;

    QString sensorIndex;
    QString sensorZone;
    QString sensorSubzone;

    QString txEventClassSlider;
    QString txEventTypeSlider;

    QString txEventClassSensor;
    QString txEventTypeSensor;

    // html dom document object
    QDomDocument htmlDomDocument;
    QDomElement  htmlRoot;
    QDomElement NodeElement;
    QDomElement NodeElementChild;
    QDomElement NodeElementSubChild;

    QDomText textNode;
    QString stringTxtNode;
    QString nodeName;
    QString nodeChildName;
    QString stringAttributeTxt;
    QString stringTxtClass;

    // Refrence to root element of the xml
    QDomElement &xmlRootRef;

    //Node list
    QDomNodeList list;

    //house floors
    QString houseFloor;

    // Is it multi house XML
    QString xmlType;

    // coding index sensor
    QString codingIndexSensor;

    //list floor
    QList<QString> floorList;

    // list floor nodes
    QList<T_packetFloorNodes> floorNodesList;  // ---------------> comment this

    // list house nodes
    QList<T_packetHouseNodes> houseNodesList;

    // List of house
    QList<T_packetHouse> housePacketList;

    QString floorNameDevice;
    QString roomNameDevice;
    QString deviceNameDevice;

    QString rxClassTxt;
    QString rxTypeTxt;

    // variables.xml
    QString xmlVariablesFileName;
    QFile   xmlVariablesFile;
    QTextStream xmlVariablesStream;
    // root element of the xml
    QDomElement xmlVariablesRoot;
    // xml dom document object
    QDomDocument xmlVariablesDomDocument;
    //file path
    QString xmlVariablesFilePath;

    // home variables.xml
    QString xmlHomeVariablesFileName;
    QFile   xmlHomeVariablesFile;
    QTextStream xmlHomeVariablesStream;
    // root element of the xml
    QDomElement xmlHomeVariablesRoot;
    // xml dom document object
    QDomDocument xmlHomeVariablesDomDocument;
    //file path
    QString xmlHomeVariablesFilePath;

    // dm.xml
    QString xmlDmFileName;
    QFile   xmlDmFile;
    QTextStream xmlDmStream;
    // root element of the xml
    QDomElement xmlDmRoot;
    // xml dom document object
    QDomDocument xmlDmDomDocument;
    //file path
    QString xmlDmFilePath;


    // dm.xml
    QString xmlHomeDmFileName;
    QFile   xmlHomeDmFile;
    QTextStream xmlHomeDmStream;
    // root element of the xml
    QDomElement xmlHomeDmRoot;
    // xml dom document object
    QDomDocument xmlHomeDmDomDocument;
    //file path
    QString xmlHomeDmFilePath;

private slots:
    void on_okPushButton_clicked();

    void on_closePushButton_clicked();

    void on_htmlAppCheckBox_clicked();

private:
    Ui::GenerateApp *ui;
};

#endif // GENERATEAPP_H
