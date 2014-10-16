#-------------------------------------------------
#
# Project created by QtCreator 2013-06-17T11:14:54
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uiMagician
TEMPLATE = app
RC_FILE = myapp.rc

#LIBS += -lqaxserver \
#        -lqaxcontainer

#CONFIG += qaxserver
CONFIG += axcontainer

SOURCES += main.cpp\
        mainwindow.cpp \
    ../common/timer/SleepTimerDelay.cpp \
    TestCaseTableView/testCaseTableViewRoutine.cpp \
    LeftTreeEdit/leftTreeEditRoutine.cpp \
    mainWindowInitialisation.cpp \
    TestCaseTableView/textviewdeligate.cpp \
    XmlFileHandling/xmloperation.cpp \
    WidgetXmlVerify/xmlverifywidget.cpp \
    ../common/xml/xmlLib.cpp \
    MyStandardItemModel/mystandarditemmodel.cpp \
    WidgetXmlVerify/xmlverifymodel.cpp \
    WidgetImage/WidgetImageSelector/widgetimageselector.cpp \
    TestCaseTableView/listwidgetdeligate.cpp \
    TestCaseTableView/listWidgetDerived.cpp \
    WidgetWebsocketPacket/WidgetWebsocketPacketSensor/widgetwebsocketpacketsensor.cpp \
    WidgetWebsocketPacket/WidgetWebsocketPacketSwitch/widgetwebsocketpacketswitch.cpp \
    WidgetImage/WidgetImageSelectorSensor/widgetimageselectorsensor.cpp \
    WidgetHelp/helpaboutuimagician.cpp \
    WidgetHelp/helpcontent.cpp \
    GenerateApp/generateapp.cpp \
    GenerateApp/multiFloorRoutine.cpp \
    GenerateApp/singleFloorRoutine.cpp \
    ../common/classTypes/vscpClassTypeObject.cpp \
    WidgetWebsocketPacket/WidgetWebsocketPacketSlider/widgetwebsocketpacketslider.cpp \
    WidgetImage/WidgetImageSelectorVariableSwitch/widgetimageselectorvariableswitch.cpp \
    WidgetWebsocketPacket/WidgetWebsocketPacketVariableSwitch/widgetWebsocketPacketVariableSwitch.cpp

HEADERS  += mainwindow.h \
    ../common/timer/SleepTimerDelay.h \
    uiMagicianConfiguration.h \
    TestCaseTableView/textviewdeligate.h \
    WidgetXmlVerify/xmlverifywidget.h \
    ../common/xml/xmlLib.h \
    MyStandardItemModel/mystandarditemmodel.h \
    WidgetXmlVerify/xmlverifymmodel.h \
    WidgetImage/WidgetImageSelector/widgetimageselector.h \
    TestCaseTableView/listwidgetdeligate.h \
    TestCaseTableView/listWidgetDerived.h \
    WidgetWebsocketPacket/WidgetWebsocketPacketSensor/widgetwebsocketpacketsensor.h \
    WidgetWebsocketPacket/WidgetWebsocketPacketSwitch/widgetwebsocketpacketswitch.h \
    WidgetImage/WidgetImageSelectorSensor/widgetimageselectorsensor.h \
    WidgetHelp/helpaboutuimagician.h \
    WidgetHelp/helpcontent.h \
    GenerateApp/generateapp.h \
    ../common/classTypes/vscp_type.h \
    ../common/classTypes/vscp_class.h \
    ../common/classTypes/vscpClassTypeObject.h \
    WidgetWebsocketPacket/WidgetWebsocketPacketSlider/widgetwebsocketpacketslider.h \
    ../common/codingIndex/codingIndex.h \
    WidgetImage/WidgetImageSelectorVariableSwitch/widgetimageselectorvariableswitch.h \
    WidgetWebsocketPacket/WidgetWebsocketPacketVariableSwitch/widgetWebsocketPacketVariableSwitch.h \
    ../common/actionCodes/actioncodes.h \
    ../common/priority/priority.h \
    ../common/cal/sys_types.h \
    testScriptConfiguration.h

FORMS    += mainwindow.ui \
    WidgetXmlVerify/xmlverifywidget.ui \
    WidgetImage/WidgetImageSelector/widgetimageselector.ui \
    WidgetWebsocketPacket/WidgetWebsocketPacketSensor/widgetwebsocketpacketsensor.ui \
    WidgetWebsocketPacket/WidgetWebsocketPacketSwitch/widgetwebsocketpacketswitch.ui \
    WidgetImage/WidgetImageSelectorSensor/widgetimageselectorsensor.ui \
    WidgetHelp/helpaboutuimagician.ui \
    WidgetHelp/helpcontent.ui \
    GenerateApp/generateapp.ui \
    WidgetWebsocketPacket/WidgetWebsocketPacketSlider/widgetwebsocketpacketslider.ui \
    WidgetImage/WidgetImageSelectorVariableSwitch/widgetimageselectorvariableswitch.ui \
    WidgetWebsocketPacket/WidgetWebsocketPacketVariableSwitch/widgetwebsocketpacketvariableswitch.ui

RESOURCES += \
    AutosResourceFile.qrc
