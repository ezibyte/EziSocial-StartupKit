EziSocial-StarterKit
====================

This repository contains the starter kit of EziSocial Plugin. 

How to use this kit?
--------------------


iOS Platform
------------

1. Download the iOS kit from https://github.com/ezibyte/EziSocial-StartupKit/tree/master/iOS
2. Create the Facebook-iOS Application at Facebook-Developer. You can use the tutorial http://www.ezibyte.com/how-to-use-ezisocial-plugin-for-ios-games/ for creating the Facebook App for iOS over your Facebook account.
3. Open the iOS project from the downloaded kit.
4. Open info.plist file and change the following fields:-
- FacebookAppID (Replace value with your id)
- URL Types - (Replace the value with you id with prefix as fb).

Default values of both types already given.

That's it you project is ready to run. If you build and run the project then it will ask you login in Facebook and to give access to your Facebook App. Once you give the access a message will popup - login successful.

This startup kit is using cocos2d-2.1-x-2.1.2 as the base version. You can update the library files on your wish.

Note: The EziSocial Library for iOS is used for Simulator. If you want to run it on Device then download the new library from https://github.com/ezibyte/EziSocial-Plugin/tree/master/iOS/iphoneos and replace it with existing simulator library.

Android Platform
----------------

1. Download the Android kit from https://github.com/ezibyte/EziSocial-StartupKit/tree/master/Android
2. Create the Facebook-Android Application at Facebook-Developer. You can use the tutorial http://www.ezibyte.com/how-to-use-ezisocial-plugin-for-android-games/ for creating the Facebook App for Android over your Facebook account.
3. Open ./build_native.sh file stored under proj.android folder and change the values of following as per your folder structure:
- NDK_ROOT (mentioned at 2nd line)
- COCOS2DX_ROOT (mentioned at 41st line)

4. Open the Android project from the downloaded kit in Eclipse.
5. Open strings.xml file and change the following fields:-
- app_id (Replace value with your id)

6. Add Facebook Project to your Android Application as instructed over here: http://www.ezibyte.com/how-to-use-ezisocial-plugin-for-android-games/


That's it you project is ready to run. If you build and run the project then it will ask you login in Facebook and to give access to your Facebook App. Once you give the access a message will popup - login successful.

This startup kit is using cocos2d-2.1-x-2.1.2 as the base version. You can update the library files on your wish.


Advance Features
================

There are many features supported by EziSocial Plugin. All features are listed at http://www.ezibyte.com 

To know how to use this advance feature, read the tutorial: http://www.ezibyte.com/magic-of-ezisocial-plugin/

You can tweet us or post message on Facebook or post message on our site if you face any problem to use this kit.

Facebook Page: http://www.facebook.com/ezibyte
Twitter Handle: @ezibyte
