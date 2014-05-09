#define AD_ADS_NOSIZE
#include <ADLib/PlatformImpl/ADAds_NoAds.hpp>
#include <Testing/ADDeviceEmulator.h>

cocos2d::CCSize ADAds::Platform::getBannerSize(const BannerType& type)
{
    cocos2d::CCSize base (468, 60);
    if(type == "BANNER")
        base = cocos2d::CCSize(320, 50);

    static float density = ADDeviceEmulator::getInstance()->getScreenDencity();
    return cocos2d::CCSize(base.width*density, base.height*density);
}


#include <ADLib/PlatformImpl/ADBrowser_None.hpp>
#include <ADLib/PlatformImpl/ADStatistics_None.hpp>
#include <ADLib/PlatformImpl/ADNotification_None.hpp>
#include <ADLib/PlatformImpl/ADInfo_Default.hpp>
#include <ADLib/PlatformImpl/ADInApp_Emulator.hpp>
#include <ADLib/PlatformImpl/ADVirtualCurrency_None.hpp>

#include <ADLib/PlatformImpl/ADHttp_CURL.hpp>

#include <ADLib/Device/ADLanguage.h>
std::string ADLanguage::platformGetDeviceLanguage()
{
    return ADDeviceEmulator::getInstance()->getDeviceLanguage();
}

//#include "GameInfo.h"
//Version GameInfo::_version = Version::Free;
//#define FACEBOOK_INIT facebook_init
#include <ADLib/PlatformImpl/ADFacebook_Emulator.hpp>


