//
// Created by sylar on 24-12-18.
//

#ifndef ACE_SIGNAL_COMFUNC_H
#define ACE_SIGNAL_COMFUNC_H
#include <ace/High_Res_Timer.h>

bool IsLeapYear(Uint ucYear);
bool IsRightDate(Uint ucYear,Byte ucMonth,Byte ucDay);
ACE_Time_Value getCurrTime();
ACE_Time_Value GetCurTime();
void CopyFile(char src[], char dest[]);
void AdjustFileSize(char* file,int iMaxFileLine);
void RecordTscStartTime();
void TestMem(char* funName,int iLine);
bool CompareTime(Byte ucHour1,Byte ucMin1,Byte ucHour2,Byte ucMin2);
int GetSysEnyDevId(char *SysEnyDevId);
int GetStrHwAddr(char * strHwAddr);
int GetEypChar(char *src ,char *dec);
int GetMainBroadCdKey(char *CdKey);
void TscBeep();
void RecordTscSN();
bool VaildSN();
#endif //ACE_SIGNAL_COMFUNC_H
