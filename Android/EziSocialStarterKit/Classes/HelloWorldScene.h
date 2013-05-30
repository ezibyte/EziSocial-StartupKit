#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "EziSocialDelegate.h"

class HelloWorld : public cocos2d::CCLayer, public EziFacebookDelegate, public EziEmailDelegate, public EziTwitterDelegate
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
    
    virtual void onEnterTransitionDidFinish();
    
    // Facebook Delegate Methods
    virtual void fbSessionCallback(int responseCode, const char* responseMessage);
    virtual void fbUserDetailCallback(int responseCode, const char* responseMessage, EziFacebookUser *fbUser);
    virtual void fbMessageCallback(int responseCode, const char* responseMessage);
    virtual void fbPageLikeCallback(int responseCode, const char* responseMessage);
    
    virtual void fbUserPhotoCallback(const char *userPhotoPath);
    
    virtual void fbSendRequestCallback(int responseCode, const char* responseMessage, cocos2d::CCArray* friendsGotRequests);
    virtual void fbPostPhotoCallback(int responseCode, const char* responseMessage);
    
    virtual void fbIncomingRequestCallback(int responseCode, const char* responseMessage, int totalIncomingRequests);
    
    // EMail Delegate
    virtual void mailCallback(int responseCode);
    
    // Twitter Callback
    virtual void twitterCallback(int responseCode);
    
};

#endif // __HELLOWORLD_SCENE_H__
