#include "main.h"
#include "../Classes/AppDelegate.h"
#include <Testing/ADDeviceEmulator.h>
#include <ADLib/Device/ADAds.h>
using namespace cocos2d;

int CALLBACK WinMain(
        _In_  HINSTANCE,
        _In_  HINSTANCE,
        _In_  LPSTR,
        _In_  int
        )
{
    //Create AppDelegate
    AppDelegate app;

    //Configure emulator
    ADDeviceEmulator* emulator = ADDeviceEmulator::getInstance();


    DeviceConfig custom(Device::Custom);
    custom.setDeviceName("Custom");
    custom.setScreenDencity(1.0);
    custom.setScreenWidth(1920);
    custom.setScreenHeight(1200);
    emulator->setCustomDevice(custom);


    emulator->setFitTheScreen(true);
    emulator->setDevice(Device::IPad2);
    emulator->setLanguage("en");
    emulator->setOrientation(Orientation::Portrait);


    return emulator->run();
}

