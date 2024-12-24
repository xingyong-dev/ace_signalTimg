//
// Created by sylar on 24-12-24.
//

#ifndef ACE_SIGNAL_PREANALYSIS_H
#define ACE_SIGNAL_PREANALYSIS_H

#include "ComDef.h"
#include "ComStruct.h"

class CPreAnalysis
{
public:
    static CPreAnalysis* CreateInstance();
    bool b_SmoothTransition ; //是否平滑过渡 每次增加减少时间有限制还是直接按车长度计算时间
    bool b_HandPriority   ; //是否处于公交优先调控中
    Byte p_BusDelayTime   ; //默认车辆启动预留时间
    Byte p_PerBusCrossTime ; //单车通过路口平均时间
    Byte p_AccessDeviceType ; //接入设备类型 0-线圈 1-射频 2-雷达3-其他
    void QueryAccessDev(); //查询接入设备信息
    void HandPreAnalysis();
    void PreAnalysisExceptionHandle(); //异常情况处理，比如通信中断�
    void AcceptDevCarsInfo();
private:
    CPreAnalysis();
    ~CPreAnalysis();
    SPreAnalysisParaData sPreAnalysisParaData[MAX_PHASE] ;
};
#endif //ACE_SIGNAL_PREANALYSIS_H
