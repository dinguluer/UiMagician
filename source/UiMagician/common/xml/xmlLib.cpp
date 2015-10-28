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



#include "xmlLib.h"
#include <QMessageBox>


#define FLOOR_NAME_INDEX           1
#define HOUSE_NAME_INDEX           2

xmlLib::xmlLib()
{
    //Do nothing
}


xmlLib::~xmlLib()
{
    //Do nothing
}

//************** file ********************************

int xmlLib::xmlOpenFile( QString &xmlFileName, QFile &xmlFile, QTextStream &xmlStream)
{
    //set the name of the file
    xmlFile.setFileName(xmlFileName);

    // open read & write mode
    if (!xmlFile.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        return FAIL_TO_OPEN_FILE;
    }

    // Assign file to the stream
    xmlStream.setDevice(&xmlFile);

    return SUCCESS_TO_OPEN_FILE;
}

int xmlLib::xmlOpenFileTruncate( QString &xmlFileName, QFile &xmlFile, QTextStream &xmlStream)
{
    //set the name of the file
    xmlFile.setFileName(xmlFileName);

    // open read & write mode
    if (!xmlFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Text))
    {
        return FAIL_TO_OPEN_FILE;
    }

    // Assign file to the stream
    xmlStream.setDevice(&xmlFile);

    return SUCCESS_TO_OPEN_FILE;
}


//Load the XML file
void xmlLib::xmlLoadFile(QDomDocument &xmlDomDocument, QFile &xmlFile)
{
    xmlDomDocument.clear();
    xmlDomDocument.setContent(&xmlFile);
}

void xmlLib::xmlCreateSortDocument(QList<T_packetHouse> &housePacketList,QDomElement &xmlRootSorted,  QDomElement &xmlRoot )
{
    QDomNode domNodeChild;

    T_packetFloor floorPacketNode;
    T_packetHouse housePacketNode;

    QDomNodeList listchildNodes;
    listchildNodes = xmlRoot.childNodes();

    int tempInd = 0;

    /* **** prepare sorted XML node  **** */
    for (int indexHouse = 0; indexHouse < housePacketList.size(); ++indexHouse)
    {

        housePacketNode = housePacketList.at(indexHouse);

        //Itterate floor list for each house
        for (int indexfloor = 0; indexfloor < housePacketNode.houseFloorList.count(); ++indexfloor)
        {
            floorPacketNode =  housePacketNode.houseFloorList.at(indexfloor);

            //Ittergate indivisual nodes with same floor name
            for (int index = 0; index < floorPacketNode.floorIndexList.size(); ++index)
            {
                listchildNodes = xmlRoot.childNodes();

                tempInd= floorPacketNode.floorIndexList.at(index);
                //list.
                domNodeChild = listchildNodes.at(tempInd).cloneNode(true);
                //append to the sorted XML
                xmlRootSorted.appendChild(domNodeChild);
                //xmlRootSorted.appendChild(xmlRoot.childNodes().at(tempIndex));

            }
        }

    }

}

//Sort dom document
void xmlLib::xmlSortDocument(QList<T_packetHouse> &housePacketList,QDomNodeList &list )
{
    QString nodeDataTextHouse;
    QString nodeDataTextFloor;

    QDomNodeList listChild;
    //
    QDomNode tempNodeChild;
    bool found = false;

    QList<QString> listHouses;
    QList<QString> floorList;

    T_packetFloor floorPacketNode;
    T_packetHouse housePacketNode;


    // root have Test Case nodes
    if(list.count() != 0)
    {
        /* **** Get the name of houses **** */
        for(int i =0; i< list.count() ; i++)
        {
            //read the child node from list
            tempNodeChild = list.at(i);

            // Create list of child nodes of - test case
            listChild = tempNodeChild.childNodes();

            //Read floor name from node
            tempNodeChild = listChild.at(HOUSE_NAME_INDEX);
            if (!tempNodeChild.isNull())
            {
                nodeDataTextHouse = tempNodeChild.toElement().text();
            }
            else
            {
                nodeDataTextHouse = "";
            }

            // append house name to list
            if(listHouses.isEmpty())
            {
                listHouses.append(nodeDataTextHouse);
            }
            else
            {
                found = false;
                for (int j = 0; j < listHouses.size(); ++j)
                {
                    if (listHouses.at(j) == nodeDataTextHouse)
                    {
                        found = true;
                    }

                }

                if(found == false)
                {
                    listHouses.append(nodeDataTextHouse);
                }
            }

        }/* **** Get the name of houses **** */

        /* **** Get floor for every house **** */
        for(int i =0; i< listHouses.count() ; i++)
        {
            QString houseNamestr = listHouses.at(i);
            housePacketNode.houseName = houseNamestr;

            //Get the floor of houses
            for(int j =0; j< list.count() ; j++)
            {
                //read the child node from list
                tempNodeChild = list.at(j);

                // Create list of child nodes of - test case
                listChild = tempNodeChild.childNodes();

                //Read house name from node
                tempNodeChild = listChild.at(HOUSE_NAME_INDEX);
                if (!tempNodeChild.isNull())
                {
                    nodeDataTextHouse = tempNodeChild.toElement().text();
                }
                else
                {
                    nodeDataTextHouse = "";
                }

                // Check if the house name matches
                if(nodeDataTextHouse == houseNamestr)
                {
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

                    // Append floor name to the floor list
                    if(floorList.isEmpty())
                    {
                        floorList.append(nodeDataTextFloor);
                    }
                    else
                    {
                        found = false;
                        for (int k = 0; k < floorList.size(); ++k)
                        {
                            if (floorList.at(k) == nodeDataTextFloor)
                            {
                                found = true;
                            }

                        }

                        if(found == false)
                        {
                            floorList.append(nodeDataTextFloor);
                        }
                    }

                }
                else
                {
                    //Do nothing
                }
            }

            /* **** prepare list of floor for each house  **** */
            for (int i = 0; i < floorList.size(); ++i)
            {
                QString floorNamestr;
                floorPacketNode.floorName = floorList.at(i);
                floorNamestr = floorPacketNode.floorName;

                // Get the floor name node & prepare index list for every floor
                for(uint16_t j =0; j< list.count() ; j++)
                {
                    //read the child node from list
                    tempNodeChild = list.at(j);

                    // Create list of child nodes of - test case
                    listChild = tempNodeChild.childNodes();

                    //Read house name from node
                    tempNodeChild = listChild.at(FLOOR_NAME_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        nodeDataTextFloor = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        nodeDataTextFloor = "";
                    }

                    //Read house name from node
                    tempNodeChild = listChild.at(HOUSE_NAME_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        nodeDataTextHouse = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        nodeDataTextHouse = "";
                    }
                    // Check if the floor name matches
                    if((nodeDataTextFloor == floorNamestr) && (nodeDataTextHouse==houseNamestr) )
                    {
                        floorPacketNode.floorIndexList.append(j);
                    }

                    // append index to floor packet node
                    //floorPacketNode.floorIndexList.append();
                }

                //append the floorpacketnode
                housePacketNode.houseFloorList.append(floorPacketNode);

                floorPacketNode.floorName = "";
                floorPacketNode.floorIndexList.clear();
            }/* **** prepare list of floor for each house  **** */

            // Append the T_packetHouse to the housePacketList
            housePacketList.append(housePacketNode);

            //clear all temp list
            floorList.clear();
            housePacketNode.houseName = "";
            housePacketNode.houseFloorList.clear();
            floorPacketNode.floorName = "";
            floorPacketNode.floorIndexList.clear();
        }/* **** Get floor for every house **** */
    }
}

//close file
void xmlLib::xmlCloseFile(QTextStream &xmlStream, QDomDocument &xmlDomDocument, QFile &xmlFile)
{
    // xml dom document object
    QDomDocument xmlDomDocumentSorted;
    // xml root for sorted xml
    QDomElement xmlRootSorted;
    QList<T_packetHouse> housePacketList;
    //Node list
    QDomNodeList list;
    // Get the XML root from the DOM document
    QDomElement xmlRoot;

    //Clear the sorted document
    xmlDomDocumentSorted.clear();
    /* **** Prepare the sorted xml document **** */
    xmlAddRoot(xmlRootSorted,xmlDomDocumentSorted);

    // Get the root element
    xmlRoot = xmlDomDocument.documentElement();
    //Load root nodes
    list = xmlRoot.childNodes();

    //Sort the XML document
    xmlSortDocument(housePacketList, list);

    //create the XML document
    xmlCreateSortDocument(housePacketList, xmlRootSorted, xmlRoot);

    // Write xml to the file
    //(xmlStream) << xmlDomDocument.toString();
    (xmlStream) << xmlDomDocumentSorted.toString();

    // close the file
    xmlFile.flush();
    xmlFile.close();
}

//close file no flush
void xmlLib::xmlCloseFileNoFlush(QFile &xmlFile)
{
    // Write xml to the file
    //(xmlStream) << xmlDomDocument.toString();

    // close the file
    //xmlFile.flush();
    xmlFile.close();
}
//********************* Node creation *************************

//Add the root item
void xmlLib::xmlAddRoot(QDomElement &xmlRoot_org, QDomDocument &xmlDomDocument_org)
{
    // Make the root element
    xmlRoot_org = xmlDomDocument_org.createElement(ROOT_ELEMENT_DETAILS);

    // Add it to the document
    xmlDomDocument_org.appendChild(xmlRoot_org);
}

//Get the root item
void xmlLib::xmlGetRoot(QDomElement &xmlRoot, QDomDocument &xmlDomDocument)
{
    QMessageBox* msgBox_2;
    // Make the root element
    xmlRoot = xmlDomDocument.documentElement();

    if(xmlRoot.isNull()){
        msgBox_2 = new QMessageBox();
        msgBox_2->setWindowTitle("Confirmation");
        msgBox_2->setText(XML_ROOTNULL_MESSAGE);
        msgBox_2->exec();
   }
    // Add it to the document
    //xmlDomDocument.appendChild(xmlRoot);
}

// Create the node
void xmlLib::xmlCreateNode(QDomDocument &xmlDomDocument, QDomElement &NodeElement, QString Name)
{
    // Make the node element
    NodeElement = xmlDomDocument.createElement(Name);

}

// return number of direct root childs
int xmlLib::xmlRootDirectChildNode(QDomDocument &xmlDomDocument)
{
    // return number of direct root childs
       //xmlRoot --> xmlDomDocument.documentElement()
    return xmlDomDocument.documentElement().childNodes().count();
}

// find number of elements attached to the node
int xmlLib::xmlTotalChildNode(QDomNode &NodeElement)
{
    if(!NodeElement.firstChild().isNull())
    {
        return NodeElement.childNodes().count();
    }
    else
    {
        // Node is NULL
        return 0;
    }
}


// Reading particular child node from the parent
void xmlLib::xmlGetNodeByNumber(QDomNode Parent, int nodeNumber, QDomNode &temp)
{
    QDomNodeList list;
    if(!Parent.firstChild().isNull())
    {
        list = Parent.childNodes();
        temp = list.at(nodeNumber).toElement();
    }
    else
    {
        // Do nothing
    }
}
// Create the text node
void xmlLib::xmlAddTextNode(QDomDocument &xmlDomDocument, QDomElement &NodeElement, QString textContent)
{
    QDomText textNode;
    textNode = xmlDomDocument.createTextNode(textContent);
    NodeElement.appendChild(textNode);
}

//Append node to the parent
void xmlLib::xmlAppendNode(QDomElement &xmlParent, QDomElement &xmlChild)
{
    xmlParent.appendChild(xmlChild);
}
// Replace old node with new one
void xmlLib::xmlUpdateNode(QDomElement &xmlRoot, QDomNode &newNode,QDomNode &oldNode)
{
    // replace existing node with new node
    xmlRoot.replaceChild(newNode, oldNode);
}

// Remove child from xml Root -- i.e -- remove test case
void xmlLib::xmlRootDeleteNode(QDomElement &xmlRoot, QDomNode &nodeToRemove)
{
    if(!nodeToRemove.isNull())
    {
        // Remove node from the xml root
        xmlRoot.removeChild(nodeToRemove);
    }

}

// ******************** Node values *****************

// Set the value of the xml node
void xmlLib::xmlWriteNodeValue(QDomElement &NodeElement, QString NodeValueTxt)
{
    NodeElement.setNodeValue(NodeValueTxt);
}

// Read the value of the xml node
void xmlLib::xmlReadNodeValue(QDomNode &NodeToReadValue, QString NodeValueTxt)
{
    NodeValueTxt = NodeToReadValue.nodeValue();
}


// Reading particular child node from the parent
void xmlLib::xmlRootRemoveNodeByNumber(QDomElement &xmlRoot, int nodeNumber)
{
    QDomNodeList list;
    QDomNode temp;

    if(!xmlRoot.firstChild().isNull())
    {
        list = xmlRoot.childNodes();
        temp = list.at(nodeNumber);

        xmlRoot.removeChild(temp);
    }
    else
    {
        // Do nothing
    }
}


