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

//---

#ifndef PRIORITY_H
#define PRIORITY_H

#define VSCP_PRIORITY7          "PRIORITY7 (HIGH)"
#define VSCP_PRIORITY_HIGH      "PRIORITY_HIGH"
#define VSCP_PRIORITY6          "PRIORITY6"
#define VSCP_PRIORITY5          "PRIORITY5"
#define VSCP_PRIORITY4          "PRIORITY4 (MEDIUM)"
#define VSCP_PRIORITY_MEDIUM    "PRIORITY_MEDIUM"
#define VSCP_PRIORITY_NORMAL    "PRIORITY_NORMAL"
#define VSCP_PRIORITY3          "PRIORITY3"
#define VSCP_PRIORITY2          "PRIORITY2"
#define VSCP_PRIORITY1          "PRIORITY1"
#define VSCP_PRIORITY0          "PRIORITY0 (LOW)"
#define VSCP_PRIORITY_LOW       "PRIORITY_LOW"

#define VSCP_PRIORITY7_VALUE          0x00
#define VSCP_PRIORITY_HIGH_VALUE      0x00
#define VSCP_PRIORITY6_VALUE          0x01
#define VSCP_PRIORITY5_VALUE          0x02
#define VSCP_PRIORITY4_VALUE          0x03
#define VSCP_PRIORITY_MEDIUM_VALUE    0x03
#define VSCP_PRIORITY_NORMAL_VALUE    0x03
#define VSCP_PRIORITY3_VALUE          0x04
#define VSCP_PRIORITY2_VALUE          0x05
#define VSCP_PRIORITY1_VALUE          0x06
#define VSCP_PRIORITY0_VALUE          0x07
#define VSCP_PRIORITY_LOW_VALUE       0x07

#endif // PRIORITY_H
