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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*---------------------------------------------------------------------------
** Defines and Macros
*/

/*---------------------------------------------------------------------------
** Includes
*/
#include <QtGui>
#include <QStandardItemModel>
#include <QMainWindow>
#include <QtXml>
#include <QFile>
#include "TestCaseTableView/textviewdeligate.h"
#include "TestCaseTableView/listwidgetdeligate.h"
#include "uiMagicianConfiguration.h"
#include "WidgetXmlVerify/xmlverifywidget.h"
#include "testScriptConfiguration.h"
#include "../common/xml/xmlLib.h"
#include "../common/timer/SleepTimerDelay.h"
#include "../common/excel/excel.h"
#include "MyStandardItemModel/mystandarditemmodel.h"
#include "WidgetImage/WidgetImageSelector/widgetimageselector.h"
#include "WidgetImage/WidgetImageSelectorSensor/widgetimageselectorsensor.h"
#include "WidgetImage/WidgetImageSelectorVariableSwitch/widgetimageselectorvariableswitch.h"
#include "WidgetWebsocketPacket/WidgetWebsocketPacketSwitch/widgetwebsocketpacketswitch.h"
#include "WidgetWebsocketPacket/WidgetWebsocketPacketSensor/widgetwebsocketpacketsensor.h"
#include "WidgetWebsocketPacket/WidgetWebsocketPacketSlider/widgetwebsocketpacketslider.h"
#include "WidgetWebsocketPacket/WidgetWebsocketPacketVariableSwitch/widgetWebsocketPacketVariableSwitch.h"
#include "WidgetHelp/helpaboutuimagician.h"
#include "WidgetHelp/helpcontent.h"
#include "GenerateApp/generateapp.h"


extern QString install_path;

/*---------------------------------------------------------------------------
** Name Space Decleration
*/
namespace Ui {
class MainWindow;
}

/*---------------------------------------------------------------------------
** This is the main window class
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // This function shows Show splash - on starting
    void showSplashScreen(QApplication &a, MainWindow &w);

    // This function is used to Create Test Cases & Test Steps view
    void createTestEditView();

    //Add root item to tree
    void AddRoot(QString name , QString description);

    //Add root item to tree
    void AddRootNoSelectionChange(QString name , QString roomName, QString floorname, QString houseName);

    // Add child to the parent
    void AddChild(QTreeWidgetItem *parent , QString name , QString description);

    // Remove top level item from the tree
    void RemoveTopLevelItem();

    // clear the tree view -- remove toplevel items
    void clearAllTopLevelItems();

    // This function will create layout for the left tree widget
    void createTreeWidgetView();

    // If xml file is already open
    void closeExistingFile(QString &xmlFileName, QFile &xmlFile, QDomDocument &xmlDomDocument);

    // save existing file
    void saveExistingFile();

    // open already existing file
    void openExistingFile(QString &xmlFileName, QFile &xmlFile, QDomDocument &xmlDomDocument, QDomDocument &xmlDomDocumentOrg, bool createFile);

    // if no xml file is open
    void openFile(QString &xmlFileName, QFile &xmlFile, QDomDocument &xmlDomDocument, QDomDocument &xmlDomDocumentOrg, bool createFile);

    // copy data from the textedit to the buffer
    void copyTextEditToTheTestCasesBuffer(QList<T_testStepDetails> &testCaseStepslist);

    // copy data from the buffer to the textedit
    void copyBufferRoomDevicesToTheTextEdit(QList<T_testStepDetails> &testCaseStepslist );

    //Copy xml node value to room name &  description
    void copyXmlNodeToRoomNameAndDescription();

    //Create default view of the table
    void createDefaultTableView();

    //Clear default view of the table
    void clearDefaultTableView();

    //change the name of the current node in the tree
    void ChangeNameOfcurrentNodeOfTree();

    //Initialise the variables
    void initialiseVariables();

    //Initialise the Undo & Redo Items
    void initialiseUndoRedoItems();

    //copy packet to the -- string
    void CanPacketCreateString(T_testCaseStepCanPacket &canPacket, QString &Canstring);

    //copy vscp packet to the -- string
    void VscpPacketCreateString(T_vscpDevicePacket &vscpPacket, QString &vscpPacketString);

    //copy vscp  Sensor packet to the -- string
    void SensorPacketCreateString(T_widgetwebsocketPacketsensor &vscpSensorPacket, QString &VscpSensorPacketstring);

    //copy vscp switch packet to the -- string
    void SwitchPacketCreateString(T_widgetWebsocketPacketSwitch &vscpSwitchPacket, QString &VscpSwitchPacketstring);

    //copy vscp slider packet to the -- string
    void SliderPacketCreateString(T_widgetWebsocketPacketSlider &vscpSliderPacket, QString &VscpSwitchPacketstring);

    //copy vscp variable button packet to the -- string
    void VariableButtonPacketCreateString(T_widgetWebsocketPacketVariableSwitch &vscpVariableSwitchPacket, QString &VscpSwitchPacketstring);

    // Initialise the CAN packet
    void CanPacketInitialise(T_testCaseStepCanPacket &canPacket);

    // Initialise the Device details packet
    void deviceDetailsInitialise(T_testStepDetails &testCaseStepsDetails_redo);

    // // Initialise the vscp packet
    void VscpPacketInitialise(T_vscpDevicePacket &vscpPacket);

    // Initialise the Sensor packet
    void SensorPacketInitialise(T_widgetwebsocketPacketsensor &packetSensor);

    // Initialise the switch packet
    void SwitchPacketInitialise(T_widgetWebsocketPacketSwitch &packetSwitch);

    // Initialise the slider packet
    void SliderPacketInitialise(T_widgetWebsocketPacketSlider &packetSlider);

    // Initialise the Variable Switch packet
    void SliderPacketVariableSwitchInitialise(T_widgetWebsocketPacketVariableSwitch &packetVariableSwitch);

    // Initialise the vscp Event packet
    void vscpEventInitialise(T_event &packetEvent);

    // Initialise the vscp Slider Event packet
    void vscpSliderEventInitialise(T_eventSlider &packetEvent);

    // Initialise the vscp variable initialise
    void vscpVariableInitialise(T_variableConfigure &vscpVariable);

    // Initialise the vscp switch variable initialise
    void vscpSwitchVariableInitialise(T_variableConfigureSwitch &vscpVariable);

    // Clear the TX & Rx list
    void clearTxRxList();

    //Create string of packet
    void CreateStringForTestStepPacket(QList<T_vscpDevicePacket> &testCaseStepCanPacketList, int row, QString &testStepPacket);

    /*------------------- xml file functions -------------------*/
    // open xml file
    // ---> m -- int xmlOpenFile(); //
    // close xml file
    // ---> m -- void xmlCloseFile(); //
    // open & truncate file
    // ---> m -- int xmlOpenFileTruncate();//
    //Load the XML file
    // ---> m -- void xmlLoadFile();//


    // xml node functions
    //Add the root item
    // ---> m -- void xmlAddRoot(); //
    //Get the root item
    // ---> m -- void xmlGetRoot(); //
    // Create the node
    // ---> m    void xmlCreateNode(QDomElement &NodeElement, QString Name); //
    // Create the text node
    // ---> m void xmlAddTextNode(QDomElement &NodeElement, QString textContent); //
    // Delete node from the root
    // ---> m void xmlRootDeleteNode(QDomNode &nodeToRemove);
    //Append node to the parent
    // ---> m void xmlAppendNode(QDomElement &xmlParent, QDomElement &xmlChild); //
    // Replace old node with new one
    // ---> m void xmlUpdateNode(QDomNode &newNode, QDomNode &oldNode);//
    // return number of direct root childs
    // ---> m    int xmlRootDirectChildNode();//
    // find number of elements attached to the node
    // ---> m  int xmlTotalChildNode(QDomNode NodeElement);//
    // Reading particular child node from the parent
    // ---> m void xmlGetNodeByNumber(QDomNode Parent, int nodeNumber, QDomNode &temp);//

    // Read node from xml root
    // ---> m void xmlReadFullTestCaseNodeValue(QList<T_testStepDetails> &testCaseStepslist, int nodeNumber);//
    //void xmlwriteFullNodeValue(T_testStepDetails &nodeDetails, int nodeNumber); --> use --> xmlUpdateNode
    void xmlCreateTestStepNode(T_testStepDetails &testStepMessageBuffer, QDomElement &testStepNode, uint8_t row, T_packetDeviceLocation &deviceLocation);//
    // xml adding values to the node
    void xmlAppendFullTestStepsToTestCase(QList<T_testStepDetails> testCaseStepslist, QDomElement &testCaseNode, T_packetDeviceLocation &deviceLocation);//
    // Set the value of the xml node
    // ---> m void xmlWriteNodeValue(QDomElement &NodeElement, QString NodeValueTxt); //
    // Read the value of the xml node
    // ---> m void xmlReadNodeValue(QDomNode &NodeToReadValue, QString NodeValueTxt); //
    //Append room name & description to the node
    void xmlAppendRoomNameAndDescription(QDomElement &testCaseNode); //
    //Update TextView & xml after delete Test Case Pressed
    void UpdateXmlAndTextViewAfterDelete();
    // Reading particular child node from the parent
    void xmlRootRemoveNodeByNumber(int nodeNumber);
    //Update TextView for currently selected node
    void UpdateTextViewForCurrentSelectedNode();
    //Load vaue of XML to the
    void loadXmltoTreeAndTextView();

    //load to xml test case ro excel
    void loadXmlTestCasetoexcel(MyExcel &excelTestReport);

    // Create Tx packet node
    void xmlCreateTxPacketNode(QDomElement &xmlNode, uint8_t row);
    // Create Rx packet node
    //void xmlCreateExpectedRxPacketNode(QDomElement &xmlTempNode, uint8_t row);
    // Create vscp packet node
    void xmlCreateVscpPacketNode(QDomElement &xmlNode, uint8_t row, T_packetDeviceLocation &deviceLocation);


    // Read node from xml root
    void xmlReadFullRoomNodeValue( QDomElement &xmlRoot, QString &roomNameText, QString &roomNameText_undo, QString &floorNameText , QString &floorNameText_undo , QString &houseNameText, QString &houseNameText_undo, QList<T_testStepDetails> &testCaseStepslist, QList<T_testStepDetails> &testCaseStepslist_undo, QList<T_testStepDetails> &testCaseStepslist_undoRoom,QList<T_vscpDevicePacket> &testCaseStepCanPacket_undo,QList<T_vscpDevicePacket> &testCaseStepCanPacket_undoRoom, QList<T_vscpDevicePacket> &testCaseStepCanPacket_rx, int nodeNumber);
    // update expected packet
    void UpdateListForCanPacket(QList<T_testCaseStepCanPacket> &testCaseStepCanPacket, QDomNode &firstChild,  uint8_t teststep);
    // update vscp expected packet --
    void UpdateListForvscpPacket(QList<T_vscpDevicePacket> &testCaseStepCanPacketList, QList<T_vscpDevicePacket> &testCaseStepCanPacket_undo, QList<T_vscpDevicePacket> &testCaseStepCanPacket_undoRoom, QDomNode &tempNode, uint8_t teststep);

    //Override virtual function - for Alt + F4 event handler
    void closeEvent(QCloseEvent *event);

    // close main window & save existing file
    void forceQuitMainWindow( bool closeVar);

    /*------------------- Project Data -------------------*/

    //Pointer to QStandardItemModel to be used inside - Test Case Tableview
    //QStandardItemModel *model;
    MyStandardItemModel *model;

    // Create an  view textdelegate to be shown inside the tableview
    textViewDeligate *mydeligate;

    // Create an list widget delegate to be shown inside the tableview
    listWidgetDeligate *deviceTypedeligate;
    QList<QString> deviceTypedeligateList;

    // Create an list widget delegate to be shown inside the tableview
    listWidgetDeligate *deviceSubTypedeligate;
    QList<QString> deviceSubTypedeligateList;

    // Create an list widget delegate to be shown inside the tableview
    listWidgetDeligate *deviceInfodeligate;
    QList<QString> deviceInfodeligateList;

    // variable to indicate current open file name
    QString xmlFileName;

    // xml file object
    QFile xmlFile;

    // xml dom document object
    QDomDocument xmlDomDocument;

    // xml dom document object
    QDomDocument xmlDomDocumentOrg;

    // xml dom document object
    QDomDocument xmlDomDocumentRedo;

    // stream used with the file
    QTextStream xmlStream;

    // root element of the xml
    QDomElement xmlRoot;

    //xmlLib library object
    xmlLib xmlLibObject;

    // indication that file is already open
    bool b_xmlFileAlreadyOpen;

    // Current test case number in XML
    int currentXmlRootNodeNumber;

    // Signal to indicate current node is saved once
    bool b_currentNodeSavedOnce;

    // Signal to indicate current node is new node
    bool b_nodeIsNewAndNotSaved;

    // Signal to indicate delete button is pressed
    bool b_deleteButtonIsPressed;

    // Signal to indicate xml contains test case
    bool b_testCaseExists;

    // Signal to indicate clear left tree
    bool b_clearTreeViewSignal;

    // Signal to indicate update tree with value read from xml - open file operation
    bool b_updateTreeViewSignal;

    // Signal to indicate file is empty
    bool b_fileDoesNotContainsNode;

    // Signal to indicate file is new
    bool b_newFileCreationSignal;

    //signal indicate verify dialog is open
    bool b_verifyDialogIsOpened;

    //signal indicate CAN Tcp Packet dialog is open
    bool b_packetDialogIsOpened;

    //signal indicate node is changing
    bool b_nodeIsChanging;

    // Room undo button is pressed
    bool b_roomUndoPressed;
    // Room redo button is pressed
    bool b_roomRedoPressed;
    // device undo button is pressed
    bool b_deviceUndoPressed;
    // device redo button is pressed
    bool b_deviceRedoPressed;
    // xml undo button is pressed
    bool b_xmlUndoPressed;
    // xml redo button is pressed
    bool b_xmlRedoPressed;

    // Signal to indicate selection change event - on left tree
    int numberOfTimeSelectionChangedWhenNewNode;

    // Global variable for reading room Name
    QString roomNameText;

    // Global variable for reading floor name
    QString floorNameText;

    // Global variable for reading house name
    QString houseNameText;

    // Save TX packet
    QList<T_testCaseStepCanPacket> testCaseStepCanPacket_tx;

    // Save RX packet
    QList<T_vscpDevicePacket> testCaseStepCanPacket_rx;

    uint8_t currentDeviceRow;
    // Save Undo packet
    QList<T_vscpDevicePacket> testCaseStepCanPacket_undo;
    // Save the packet for device details
    QList<T_testStepDetails> testCaseStepslist_undo;

    // Save Undo packet
    QList<T_vscpDevicePacket> testCaseStepCanPacket_undoRoom;
    // Save the packet for device details
    QList<T_testStepDetails> testCaseStepslist_undoRoom;
    // Global variable for reading room Name
    QString roomNameText_undo;
    // Global variable for reading floor name
    QString floorNameText_undo;
    // Global variable for reading house name
    QString houseNameText_undo;

    // Save Redo packet
    T_vscpDevicePacket testCaseStepCanPacket_redo;
    // Save the packet for device details
    T_testStepDetails testCaseStepsDetails_redo;
    // Global variable for reading room Name
    QString roomNameText_redo;
    // Global variable for reading floor name
    QString floorNameText_redo;
    // Global variable for reading house name
    QString houseNameText_redo;

private slots:
    void on_actionSave_triggered();

    void on_testStepNewPushButton_clicked();

    void on_testStepDeletePushButton_clicked();

    void on_leftTreeDockWidget_topLevelChanged(bool topLevel);

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_testCaseDeletePushButton_clicked();

    void on_testCaseNewPushButton_clicked();

    void on_testCaseSavePushButton_clicked();

    void on_treeWidgetLeft_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_actionClose_Project_triggered();

    void on_testReportVerifyPushButton_clicked();

    void on_appGeneratePushButton_clicked();

    void on_testCaseTableView_doubleClicked(const QModelIndex &index);

    void on_deviceUndoPushButton_clicked();

    void on_devicRedoPushButton_clicked();

    void on_testCaseTableView_clicked(const QModelIndex &index);

    void on_roomUndoPushButton_clicked();

    void on_roomRedoPushButton_clicked();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_Ui_Magician_triggered();

    void on_actionContent_Help_F1_triggered();

    void on_actionExit_Ctrl_Q_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
