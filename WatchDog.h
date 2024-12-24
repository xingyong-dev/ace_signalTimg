//
// Created by sylar on 24-12-24.
//

#ifndef ACE_SIGNAL_WATCHDOG_H
#define ACE_SIGNAL_WATCHDOG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ComStruct.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/watchdog.h>

#define DEV_WATCHDOG  "/dev/watchdog"

class WatchDog
{
public:
    static WatchDog* CreateInstance();
    void OpenWatchdog();
    void CloseWatchdog();
    void FillWatchdog(char cData);
private:
    WatchDog();
    ~WatchDog();
    int timeout;
    int m_watchdogFd;
};

#endif //ACE_SIGNAL_WATCHDOG_H
