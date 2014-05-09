TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += ../../../cocos2dx \
    ../../../cocos2dx/include \
    ../../../cocos2dx/kazmath/include \
    ../../../cocos2dx/platform/win32 \
    ../../../cocos2dx/platform/third_party/win32/ \
    ../../../cocos2dx/platform/third_party/win32/OGLES \
    ../Classes \
    ../../../CocosDenshion/include

include(../libraries/ADLib/ADLib.pri)

#DEFINES +=NDEBUG
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/../../../Debug.win32/ -lglew32
    LIBS += -L$$PWD/../../../Debug.win32/ -llibcocos2d
    LIBS += -L$$PWD/../../../Debug.win32/ -llibCocosDenshion
    LIBS += -L$$PWD/../../../Debug.win32/ -llibcurl_imp
    LIBS += -lopengl32
} else {
    #LIBS += -L../../../Release.win32/ -llibcocos2d
    #LIBS += -L../../../Release.win32/ -lglew32
    #LIBS += -L../../../Release.win32/ -llibCocosDenshion
    #LIBS += -lopengl32
    DEFINES +=NDEBUG
}
LIBS += -luser32
QMAKE_CXXFLAGS_DEBUG += -wd4267 -wd4251 -wd4244
QMAKE_CXXFLAGS_RELEASE += -wd4267 -wd4251 -wd4244

DEFINES += WIN32 \
            _DEBUG \
            _WINDOWS \
            COCOS2D_DEBUG="1" \
            _CRT_SECURE_NO_WARNINGS \
            _SCL_SECURE_NO_WARNINGS

SOURCES += main.cpp \
    ../Classes/AppDelegate.cpp \
    PurchaseEmulator.cpp \
    ../Classes/Scenes/MainMenu.cpp \
    ../Classes/Scenes/SceneStyle.cpp

HEADERS += \
    ../Classes/AppMacros.h \
    ../Classes/AppDelegate.h \
    main.h \
    ../Classes/Scenes/MainMenu.h \
    ../Classes/Scenes/SceneStyle.h


