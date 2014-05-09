#include "AppDelegate.h"
//#include "Scenes/Loading.h"
#include "AppMacros.h"
#include "SimpleAudioEngine.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Scenes/MainMenu.h"

#include <ADLib.h>
USING_NS_CC;


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

class InAppDelegate : public ADInApp::Delegate
{
public:
    void purchaseSuccessful(const ADInApp::ProductID & id)
    {
        cocos2d::CCLog("Purchase %s finished successful", id.c_str());

    }
    void purchaseFailed(const ADInApp::ProductID & id,
                        const ADInApp::ErrorType error)
    {
        typedef ADInApp::ErrorType Error;
        if(error == ADInApp::ErrorType::BillingUnavaliable)
        {
            ADNotification::showNotification(_("iap.error.billing_unavaliable"));
        }
        else if(error == ADInApp::ErrorType::DeveloperError ||
                error == ADInApp::ErrorType::Error)
        {
            ADNotification::showNotification(_("iap.error.purchase_error"));
        }

        CCLog("Purchase %s failed", id.c_str());
    }

    void restorePurchasesSuccessfully()
    {
        ADNotification::showNotification(_("iap.restore_purchases.success"));
    }

    void restorePurchasesFailed()
    {
        ADNotification::showNotification(_("iap.restore_purchases.failed"));
    }
};

class VirtualCurrencyDelegate : public ADVirtualCurrency::Delegate
{
    void onCurrencyAdded(const unsigned int number)
    {

    }
};


void initInAppPurchases()
{

}

/**
 * @brief Performs init and configuration of AdMob and home ads
 */
void initAds()
{

}

void initTapJoy()
{

}



bool AppDelegate::applicationDidFinishLaunching() {


    //Statistics in

    ADStatistics::startSession();
    ADInfo::getStore();

    //Language init
    std::string latin_font = "fonts/Fredoka One.ttf";
    std::string latin_bmfont = "fonts/Fredoka One.fnt";

    //std::string cyrilic_font = "fonts/Lasco-Bold.ttf";
    //std::string cyrilic_bmfont = "fonts/Lasco-Bold.fnt";

    ADLanguage::addSupportedLanguage("en", latin_font, latin_bmfont);
    //ADLanguage::addSupportedLanguage("uk", cyrilic_font, cyrilic_bmfont);
    //ADLanguage::addSupportedLanguage("pt", latin_font, latin_bmfont);
    //ADLanguage::addSupportedLanguage("ru", cyrilic_font, cyrilic_bmfont);
    //ADLanguage::addSupportedLanguage("hu", latin_font, latin_bmfont);
    //ADLanguage::addSupportedLanguage("de", latin_font, latin_bmfont);


    ADLanguage::setDefaultLanguage("en");
    ADLanguage::getLanguage();

    //Init facebook start

    //Init facebook end

    initInAppPurchases();
    initTapJoy();
    //initHighscoreServer();

    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();


    pDirector->setOpenGLView(pEGLView);

    CCSize frameSize = pEGLView->getFrameSize();

    CCSize designResolutionSize = designResolutionSize_;

    if(frameSize.width > frameSize.height)
    {
        //Mode for Samsung who launches in wrong mode
        ADAds::disableAds();
        pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionShowAll);
    }
    else
    {
        // Set the design resolution
        pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
    }
    CCSize vsize = pEGLView->getVisibleSize();



    float width_change = vsize.width / designResolutionSize.width;
    std::string resource_directory = "images-normal";
    float resource_scale = 1;

    if(frameSize.height < 500)
    {
        resource_directory = "images-small";
        resource_scale = 0.5;
    }

    std::vector<std::string> searchPath;
    searchPath.push_back(resource_directory);

    ADScreen::setDesignScale(resource_scale);
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);
    pDirector->setContentScaleFactor(
                MIN(
                    mediumResource.size.height*resource_scale/
                    designResolutionSize.height/
                    width_change,

                    mediumResource.size.width*resource_scale/
                    designResolutionSize.width/
                    width_change));

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    
    //std::ifstream is(CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile());
    // create a scene. it's an autorelease object
    CCScene *pScene = MainMenu::scene();

    // run
    pDirector->runWithScene(pScene);



    initAds();

    //Init ADMenuItem
    ADMenuItem::setAllClicksAction([](){
        ADSoundManager::playSoundEffect("music/choose.wav");
    });


    ADStorage::loadInitialData();
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    ADDeviceEvents::onPause();


}
//#include "Core/MusicSettings.h"
//#include "Core/DrawLayer.h"
// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    ADDeviceEvents::onResume();



}
