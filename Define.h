//
// Created by sylar on 24-12-19.
//

#ifndef ACE_SIGNAL_DEFINE_H
#define ACE_SIGNAL_DEFINE_H
#if defined(__GNUC__)
#define LINUX
#else
#define WINDOWS
#endif

#ifndef Byte
typedef unsigned char Byte;
#endif
#ifndef Uint
typedef unsigned int Uint;
#endif
#ifndef Ulong
typedef unsigned long Ulong;
#endif

#ifndef Ushort
typedef unsigned short Ushort;
#endif
#ifndef Char
typedef char Char;
#endif

#ifndef Long
typedef long Long;
#endif
#ifndef Uint32
typedef unsigned int Uint32;
#endif

#define DB_NAME "./GbAitinTsc.db"


#define DEV_RTC "/dev/rtc0"
#define RTC_RD_TIME 0X80247009
#define TRC_SET_TIME 0X4024700a

#define GA_COUNT_DOWN


#endif //ACE_SIGNAL_DEFINE_H
