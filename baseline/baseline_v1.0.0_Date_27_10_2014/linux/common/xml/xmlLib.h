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


#ifndef EXCEL_H
#define EXCEL_H

#include <QtGui>
#include <QStandardItemModel>
#include <QtXml>
#include "../../source/uiMagicianConfiguration.h"

class xmlLib : public QObject
{

public:
    xmlLib();
    ~xmlLib();

    /*------------------- xml file functions -------------------*/
    // open xml file
    int xmlOpenFile( QString &xmlFileName, QFile &xmlFile, QTextStream &xmlStream);
    // close xml file
    int xmlOpenFileTruncate( QString &xmlFileName, QFile &xmlFile, QTextStream &xmlStream);
    //Load the XML file
    void xmlLoadFile(QDomDocument &xmlDomDocument, QFile &xmlFile);
    //Sort dom document
    void xmlSortDocument(QList<T_packetHouse> &housePacketList,QDomNodeList &list );
    //
    void xmlCreateSortDocument(QList<T_packetHouse> &housePacketList,QDomElement &xmlRootSorted,  QDomElement &xmlRoot );
    //close file
    void xmlCloseFile(QTextStream &xmlStream, QDomDocument &xmlDomDocument, QFile &xmlFile);
    //close file no flush
    void xmlCloseFileNoFlush(QFile &xmlFile);

    // xml node functions
    //Add the root item
    void xmlAddRoot(QDomElement &xmlRoot_org, QDomDocument &xmlDomDocument_org);
    //Get the root item
    void xmlGetRoot(QDomElement &xmlRoot, QDomDocument &xmlDomDocument);
    // Create the node
    void xmlCreateNode(QDomDocument &xmlDomDocument, QDomElement &NodeElement, QString Name);
    // return number of direct root childs
    int xmlRootDirectChildNode(QDomDocument &xmlDomDocument);
    // find number of elements attached to the node
    int xmlTotalChildNode(QDomNode &NodeElement);
    // Reading particular child node from the parent
    void xmlGetNodeByNumber(QDomNode Parent, int nodeNumber, QDomNode &temp);
    // Create the text node
    void xmlAddTextNode(QDomDocument &xmlDomDocument, QDomElement &NodeElement, QString textContent);
    //Append node to the parent
    void xmlAppendNode(QDomElement &xmlParent, QDomElement &xmlChild);
    // Replace old node with new one
    void xmlUpdateNode(QDomElement &xmlRoot, QDomNode &newNode,QDomNode &oldNode);
    // Remove child from xml Root -- i.e -- remove test case
    void xmlRootDeleteNode(QDomElement &xmlRoot, QDomNode &nodeToRemove);
    // Set the value of the xml node
    void xmlWriteNodeValue(QDomElement &NodeElement, QString NodeValueTxt);
    // Read the value of the xml node
    void xmlReadNodeValue(QDomNode &NodeToReadValue, QString NodeValueTxt);
    // Reading particular child node from the parent
    void xmlRootRemoveNodeByNumber(QDomElement &xmlRoot, int nodeNumber);

protected:


private:

};

#endif
