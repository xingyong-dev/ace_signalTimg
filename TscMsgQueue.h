//
// Created by sylar on 24-12-24.
//

#ifndef ACE_SIGNAL_TSCMSGQUEUE_H
#define ACE_SIGNAL_TSCMSGQUEUE_H

#include "ace/Message_Queue.h"
#include "ace/Synch.h"

#include "ComStruct.h"
#include "Log.h"

/*
*信号机核心控制消息队列
*单个实例存在
*/
class CTscMsgQueue
{
public:
    static CTscMsgQueue* CreateInstance();
    void DealData();
    int SendMessage(SThreadMsg* pMsg,int iLen);
    void WriteEventLog(Byte uEvtType, Byte* pEvtValue);

/*
public:
	Byte m_ucLogMaxId;   //日志表的最大行数
	Byte m_ucLogMinId;   //日志表的日期最小的id
*/

private:
    CTscMsgQueue();
    ~CTscMsgQueue();

    CLogger m_logger;
    ACE_Message_Queue<ACE_MT_SYNCH>* m_pMsgQue;
};
#endif //ACE_SIGNAL_TSCMSGQUEUE_H
