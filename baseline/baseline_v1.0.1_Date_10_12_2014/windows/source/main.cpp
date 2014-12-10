/*---------------------------------------------------------------------------
** Project Name: UiMagician
** #Archive: D:\Qt\UiMagician\main.cpp #
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

/*---------------------------------------------------------------------------
** Includes
*/
#include <QtGui/QApplication>
#include "mainwindow.h"

/*----------------------------------------------------------------------------
** Function    : main
** Description : Main function of Geny starts here
** Precondition: None.
** Postcondition: Application Gui will start.
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Show the main window
    MainWindow w;

    // This function shows Show splash - on starting
    w.showSplashScreen(a, w);

    //Maximise the window
    w.showMaximized();   //w.show();
    
    return a.exec();
}
