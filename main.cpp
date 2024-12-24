
#include <ace/ACE.h>
#include <ace/Reactor.h>
#include <ace/Timer_Queue.h>
#include <ace/Time_Value.h>
#include <ace/Event_Handler.h>
#include <ace/Log_Msg.h>
#include <ace/Process_Mutex.h>
#include <ace/Thread.h>
#include "Gb.h"
#include "ComStruct.h"
#include "Dbinstance.h"
#include "ManaKernel.h"
#include "ComFunc.h"
using namespace std;
// 定时器处理类
class PeriodicTimerHandler : public ACE_Event_Handler {
public:
    PeriodicTimerHandler(ACE_Reactor* reactor) : reactor_(reactor) {}

    // 定时任务回调函数
    virtual int handle_timeout(const ACE_Time_Value& current_time, const void* arg) override {
        TscAceDebug((LM_DEBUG,"Debug message: %s, value: %d", "example", 42));
        ACE_DEBUG((LM_DEBUG, "Periodic task executed at: %T\n", &current_time));
        return 0; // 返回 0 表示继续运行定时器
    }

    // 启动周期定时器
    void start_timer(int interval_sec, int interval_usec = 0) {
        ACE_Time_Value initial_delay(0);             // 初始延时（0 表示立即执行）
        ACE_Time_Value interval(interval_sec, interval_usec); // 周期时间
        reactor_->schedule_timer(this, nullptr, initial_delay, interval);
    }

private:
    ACE_Reactor* reactor_;
};

int main() {
    ACE_Process_Mutex ationMutex("ation"); //process mutex
    int iRetAcquire = ationMutex.tryacquire();
    if ( 0 != iRetAcquire )
    {
        ACE_DEBUG((LM_DEBUG, "\n Error!!!Reason: TSC has already been runned.iRetAcquire = %d\n", iRetAcquire));
        ationMutex.release();
        return -1;
    }
    // 创建 Reactor 实例
    ACE_Reactor reactor;

    // 创建定时器处理对象
    PeriodicTimerHandler timer_handler(&reactor);

    // 启动周期定时器，每隔 2 秒执行一次
    timer_handler.start_timer(2);

    // 启动 Reactor 事件循环
    ACE_DEBUG((LM_DEBUG, "Starting Reactor event loop...\n"));
    reactor.run_reactor_event_loop();
    ationMutex.release();
    return 0;
}

/**************************************************************
Function:       RunGb
Description:    信号机系统核心入口函数，包含7个主要工作线程
Input:          无
Output:         无
Return:         无
***************************************************************/
void RunGb()
{
    ACE_thread_t tThreadId[10];
    ACE_hthread_t hThreadHandle[10];

    (CDbInstance::m_cGbtTscDb).InitDb(DB_NAME);
    CManaKernel::CreateInstance()->InitWorkPara();
    RecordTscStartTime();   //记录系统开启时间
    RecordTscSN();
}
