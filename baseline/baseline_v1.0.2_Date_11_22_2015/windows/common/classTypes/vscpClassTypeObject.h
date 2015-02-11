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


#ifndef CLASSTYPE_H
#define CLASSTYPE_H

#include <QtGui>
#include <QStandardItemModel>
#include "../../source/uiMagicianConfiguration.h"
#include "vscp_class.h"
#include "vscp_type.h"

class vscpClassTypeObject : public QObject
{

public:
    vscpClassTypeObject();
    ~vscpClassTypeObject();

    /*------------------- vscpClassTypeObject file functions -------------------*/

    // get type for control
    void getControlTypeValue(QString &tempType);

    // get list index for Control
    int getControlTypeListIndex(QString &tempType);

    // get type for Information
    void getInformationTypeValue(QString &tempType);

    // get list index for Information
    int getInformationTypeListIndex(QString &tempType);

    // get type for Measurement
    void getMeasurementTypeValue(QString &tempType);

    // get list index for Information
    int getMeasurementTypeListIndex(QString &tempType);

protected:


private:

};

#endif
