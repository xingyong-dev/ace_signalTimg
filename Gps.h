//
// Created by sylar on 24-12-24.
//

#ifndef ACE_SIGNAL_GPS_H
#define ACE_SIGNAL_GPS_H

#include "ComDef.h"
#include "ComStruct.h"

#define GPRMC "$GPRMC"
#define GPSFILE "GpsTime.info"

class CGps
{
public:
    static CGps* CreateInstance();
    void RunGpsData();
    time_t GetLastTi();
    int Extract();
    void InitGps();
    void ForceAdjust();
    bool CheckSum(char *cMsg);
    void SetTime(int iYear , int iMon , int iDay, int iHour, int iMin, int iSec);
    bool m_bGpsTime ;  //判断是否处于较时状态

private:
    CGps();
    ~CGps();
    int    m_iGpsFd;
    char   m_cBuf[128];
    time_t m_tLastTi;
    Ushort  ierrorcount ;
};
#endif //ACE_SIGNAL_GPS_H
