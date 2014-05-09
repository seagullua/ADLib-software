#Windows
Software to configure working environment on Windows

##1. Common
All steps from this section must be performed

###1.1 Install GitHub for Windows

- Download and install from https://windows.github.com/

###1.2 Clone cocos2d-x

- Open in browser https://github.com/seagullua/cocos2d-x
- Click "Clone In Desktop" at the right
- This will open repository in GitHub for Windows
- Switch to branch "master-4Enjoy"
- Click "Settings -> Open a shell here"
- In terminal type: ```git submodule init```
- And then ```git submodule update```

###1.3 Install PHP5

- Extract folder ```php5``` from this repository to your pc.

###1.4 Install ImageMagick

- Download and install http://www.imagemagick.org/download/binaries/ImageMagick-6.8.9-0-Q16-x86-dll.exe

###1.5 Install TexturePacker

- Download and install http://www.codeandweb.com/texturepacker/start-download?os=win&bits=32
- Launch TexturePacker
- When program will ask to select program mode select ```Lite - free```
- Close program

###1.6 Install Python3

- Download and install https://www.python.org/ftp/python/3.4.0/python-3.4.0.msi

###1.7 Install Visual C++ 2012 for Desktop Express

- Launch ```visual-studio-2012/wdexpress_full.exe``` and install Visual Studio
- Open Visual Studio 2012.
- When it will ask for activation:
   * follow link
   * fill the form
   * receive and enter the activation code
   
###1.8 Install Qt 

- Install Qt 32bit for Windows with Visual Studio 2012 support http://download.qt-project.org/official_releases/qt/5.2/5.2.1/qt-opensource-windows-x86-msvc2012-5.2.1.exe 

###1.9 Compile cocos2d-x

- Open folder with cocos2d-x from step ```1.2```
- Open ```cocos2d-win32.vc2012.sln``` with Visual Studio installed on step ```1.7```
- In the project list right click ```cocos2d-x``` and then select ```Build```
- In the project list right click ```CococsDension``` and then select ```Build```
- Close Visual Studio

###1.10 Create project

- Open folder with cocos2d-x installed
- Create folder ```projects```
- Open GitHub for Windows (step ```1.1```)
- Press ```create``` button in repositories list
- Set name of repository ```MyProject```
- Set location to ```projects``` folder which you have created
- Press ```Create``` button
- Copy files from ```MyProject-template``` to folder ```projects/MyProject```
- Create folder ```projects/MyProject/libraries```
- Open ```MyProject``` in GitHub for Windows
- Press ```Settings``` -> ```Open a shell here``` 
- Type into console ```cd libraries```
- Type into console ```git submodule add git@github.com:seagullua/ADLib.git```
- Close console
- Create folder ```projects/MyProject/Resources```

###1.11 Configure project
- Create copy of the file ```environment.example.py``` and name it ```environment.py```
- Open it with text editor and specify
	* ```env.php_bin``` - the location of ```php.exe``` from step ```1.3```
	* ```env.resource_compiler_dir``` - the location of Resource-Compiler. It is located inside cocos2d-x directory from step ```1.2``` in folder ```Resource-Compiler```
	* ```env.texture_packer_bin``` - the location of TexturePacker.exe from step ```1.5```
	* ```env.cocos2dx_dir``` - the location of cocos2d-x from step ```1.2```
- Open ```projects/MyProject/proj.qt/MyProject.pro``` with Qt Creator installed in step ```1.8```
- Select kit ```Desktop Qt 5.*.* MSVC2012 32bit``` and press ```Configure Project```
- In left panel click ```Projects``` then in top panel you find ```Desktop Qt 5.*.* MSVC2012 32bit``` and press ```Build``` button
	* Find ```Build Steps```
	* Press ```Add Build Step``` -> ```Custom Process Step```
	* Enter ```Command```: ```%PYTHON3_DIR%/python.exe``` instead of  ```%PYTHON3_DIR%``` enter dir where you have installed python on step ```1.6```
	* Enter ```Arguments```: ```%{sourceDir}\..\build.win32.py```
- In left panel click ```Projects``` then in top panel you find ```Desktop Qt 5.*.* MSVC2012 32bit``` and press ```Run``` button
- ```Run``` -> ```Working Directory``` select ```projects/MyProject/Resources``` folder created earlier. 
- Press ```F5``` and wait project to compile. After compilation you should see white windows with facebook logo in the middle.

###1.12 You are ready to go
No the project is configured you can start writing your code

##2. Build for Android
This optional section. It is required if you would like to build your program for Android.

###2.1 Install Android SDK
- You can use download it from https://github.com/seagullua/ADLib-software/releases/download/sdk/Android-SDK-installer_r22.6.2-windows.exe
- After installation open ```SDK Manager``` and install ```Android 4.3 (API 18)```

###2.2 Install Android NDK
- Download http://dl.google.com/android/ndk/android-ndk-r9d-windows-x86.zip
- Extract to your PC

###2.3 Install Apache Ant
- Download and extract http://apache.ip-connect.vn.ua//ant/binaries/apache-ant-1.9.4-bin.zip

###2.4 Configure build
- Open ```projects/MyProject/environment.py``` with text editor and specify:
	* ```env.android_sdk``` - Dir where you installed Android SDK from step 2.1
	* ```env.android_ndk``` - Dir where you extracted Android NDK from step 2.2
	* ```env.ant_dir``` - Dir to Apache Ant from step 2.3

###2.5 Configure Qt Creator
- Open project in Qt Creator
- In left panel click ```Projects``` then in top panel you find ```Desktop Qt 5.*.* MSVC2012 32bit``` and press ```Build``` button
	* In ```Build Settings``` section press Add -> Clone Selected
	* Enter name Android
	* Delete all from ```Build Steps``` section
	* Press ```Add Build Step``` -> ```Custom Process Step```
	* Enter ```Command```: ```%PYTHON3_DIR%/python.exe``` instead of  ```%PYTHON3_DIR%``` enter dir where you have installed python on step ```1.6```
	* Enter ```Arguments```: ```%{sourceDir}\..\build.android.py debug_release```
- Now in the left panel at the bottom you can switch between builds ```Debug``` - for windows and ```Android```
- Select ```Android``` mode.
- Attach you ```Android``` device to the pc
- Press ```Ctrl+B``` and wait until the application will be launched on your device
	

