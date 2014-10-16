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


#include "mystandarditemmodel.h"
#include "../uiMagicianConfiguration.h"

MyStandardItemModel::MyStandardItemModel(int row, int column):QStandardItemModel(row, column)
{
}


Qt::ItemFlags MyStandardItemModel::flags(const QModelIndex& index) const
{
    //if ( (index.column() == TX_PACKET_COLUMN_DELIGATE) || (index.column() == RX_PACKET_COLUMN_DELIGATE)  || (index.column() == EXPECTED_PACKET_COLUMN_DELIGATE)  || (index.column() == RESULT_PACKET_COLUMN_DELIGATE))
    if (( index.column() == DEVICE_PACKET_COLUMN_DELIGATE) || ( index.column() == DEVICE_IMAGE_COLUMN_DELIGATE))
    {
            return (QStandardItemModel::flags(index) & ~Qt::ItemIsEditable);
    }
    else
    {
        return QStandardItemModel::flags(index);
    }

}
