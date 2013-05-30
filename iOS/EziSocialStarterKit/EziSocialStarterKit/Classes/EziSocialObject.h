//
//  EziSocialObject.h
//  EziSocial
//
//  Created by Paras Mendiratta on 11/04/13.
//  Copyright @EziByte 2013 (http://www.ezibyte.com)
//
//  Version 1.2 (Dt: 30-May-2013)
//
/***
 
 This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
 
 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
 
 3. This notice may not be removed or altered from any source distribution.
 
 */


#ifndef __FacebookGameDemo__EziSocialObject__
#define __FacebookGameDemo__EziSocialObject__

#include <iostream>
#include "EziSocialDelegate.h"
#include "EziSocialDefinition.h"
#include "cocos2d.h"

class EziSocialObject
{
    EziSocialObject();
    EziFacebookDelegate *mFacebookDelegate;
    EziTwitterDelegate *mTwitterDelegate;
    EziEmailDelegate *mEmailDelegate;
    
    bool mAllowIOS_5_Fallback;
    bool mNeedsPublishPermission;
    
    void downloadPhoto(const char *fbID, const char* filename, bool forceDownloadFromServer);
    void onHttpRequestCompleted(cocos2d::CCNode *sender, void *data);
    
public:
    
    ~EziSocialObject();
    
    static EziSocialObject* sharedObject();
    static std::vector<std::string> tokenizeStr( const std::string &s, const std::string &delim );
    
    bool isNeedsPublishPermission();
    
    void setFacebookDelegate(EziFacebookDelegate *facebookDelegate);
    void setTwitterDelegate(EziTwitterDelegate *twitterDelegate);
    void setEmailDelegate(EziEmailDelegate *emailDelegate);
    
    EziFacebookDelegate* getFacebookDelegate();
    EziTwitterDelegate* getTwitterDelegate();
    EziEmailDelegate* getEmailDelegate();
    
    void performLoginUsingFacebook(bool needsPublishPermission);
    void perfromLogoutFromFacebook();
    
    void fetchFBUserDetails(bool getEmailIDAlso);
    
    // Post Message On Wall
    void postMessageOnWall(const char* heading,
                           const char* caption,
                           const char* message,
                           const char* description,
                           const char* badgeIconURL,
                           const char* deepLinkURL);
    
    void autoPostMessageOnWall(const char* heading,
                               const char* caption,
                               const char* message,
                               const char* description,
                               const char* badgeIconURL,
                               const char* deepLinkURL);
    
    void postScore(unsigned long long score);
    void deleteScore();
    
    void hasUserLikedMyFBPage(const char* pageID);
    
    
    void getListOfFriendsUsingFBApp();
    void processIncomingRequest(std::string requestID);
    
    void getFriends(EziSocialWrapperNS::FB_FRIEND_SEARCH::TYPE searchType);
    void getFriends(EziSocialWrapperNS::FB_FRIEND_SEARCH::TYPE searchType, int startIndex, int limit);
    
    void getHighScores();
    void openFacebookPage(const char* pageID, bool checkPageLikeOnApplicationBecomesActive);
    
    void getProfilePicForID(const char* userFacebookID, bool forceDownload);
    void getProfilePicForID(const char* userFacebookID, EziSocialWrapperNS::FBUSER::PROFILE_PIC_TYPE picType, bool forceDownload);
    void getProfilePicForID(const char* userFacebookID, int width, int height, bool forceDownload);
    
    void sendRequestToFriends(EziSocialWrapperNS::FB_REQUEST::TYPE requestType,
                              const char* message,
                              cocos2d::CCArray *selectedFriendIDs,
                              cocos2d::CCDictionary *dataDictionary);
    
    void checkIncomingRequest();
    
    void postPhoto(const char* imageFileName, const char* message);
    
    // Twitter
    void tweet(const char* message, const char* imageURL);
    
    // Email
    void sendEmail(const char* subject, const char* htmlMessageBody, const char* semicolonSeperatedRecipents);
    
    // Network Status
    bool checkNetworkStatusForHost(const char* hostURL);
    
    bool isFacebookSessionActive();
    
    cocos2d::CCSprite* generateCCSprite(const char* userPhoto);
    
    void setAllowIos5Fallback(bool allowed);
    
    
};


#endif /* defined(__FacebookGameDemo__EziSocialObject__) */
