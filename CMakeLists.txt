cmake_minimum_required(VERSION 3.24)
project(ace_signal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -ggdb -pthread -Wall -Wextra -Wpointer-arith -pipe -D_GNU_SOURCE")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-E -Wl,--enable-new-dtags")
include_directories(/home/sylar/Documents/ACE/app/include)
link_directories(/home/sylar/Documents/ACE/app/lib)

find_package(SQLite3 REQUIRED)



add_executable(ace_signal main.cpp ComFunc.h ComFunc.cpp Gb.h GbtMsgQueue.h ComDef.h Define.h ComStruct.h GbtDb.h GbtDb.cpp GbtExchg.h GbtExchg.cpp Dbinstance.h Dbinstance.cpp ManaKernel.h ManaKernel.cpp TscMsgQueue.h Log.h Log.cpp TscMsgQueue.cpp WirelessButtons.h WirelessButtons.cpp LampBoard.h LampBoard.cpp TimerManager.h TimerManager.cpp TscTimer.h TscTimer.cpp MainBoardLed.h MainBoardLed.cpp Detector.h Detector.cpp PowerBoard.h PowerBoard.cpp WatchDog.h WatchDog.cpp FlashMac.h FlashMac.cpp PscMode.h PscMode.cpp MacControl.h MacControl.cpp GaCountDown.h GaCountDown.cpp MainBackup.h MainBackup.cpp Can.h Can.cpp PreAnalysis.h PreAnalysis.cpp SerialCtrl.h SerialCtrl.cpp Rs485.h Rs485.cpp Gsm.h Gsm.cpp Gps.h Gps.cpp)


target_link_libraries(ace_signal ACE SQLite::SQLite3)
