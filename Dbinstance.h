//
// Created by sylar on 24-12-20.
//

#ifndef ACE_SIGNAL_DBINSTANCE_H
#define ACE_SIGNAL_DBINSTANCE_H
#include "GbtMsgQueue.h"
#include "GbtDb.h"

/*
* 数据库操作类
*/
class CDbInstance
{
public:
    CDbInstance();
    ~CDbInstance();

    static GBT_DB::CGbtTscDb m_cGbtTscDb;
};

#endif //ACE_SIGNAL_DBINSTANCE_H
