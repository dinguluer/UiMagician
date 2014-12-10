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

#ifndef INSERTSPLASHSCREEN_H
#define INSERTSPLASHSCREEN_H

/*---------------------------------------------------------------------------
** Includes
*/
#include <QThread>


/*---------------------------------------------------------------------------
** This is the SleepTimerDelay class
*/
class SleepTimerDelay : public QThread
{
public:
    SleepTimerDelay();

    ~SleepTimerDelay();

    // Function to sleep
    static void sleep(unsigned long secs) {
            QThread::sleep(secs);
    }

    // Function to sleep
    static void msleep(unsigned long msecs) {
            QThread::msleep(msecs);
    }

    // Function to sleep
    static void usleep(unsigned long usecs) {
            QThread::usleep(usecs);
    }
};

#endif // INSERTSPLASHSCREEN_H
