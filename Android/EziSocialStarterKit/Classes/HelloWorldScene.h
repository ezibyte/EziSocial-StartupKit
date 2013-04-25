#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "EziSocialDelegate.h"

class HelloWorld : public cocos2d::CCLayer, public EziFacebookDelegate
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
    virtual void fbSessionCallback(int responseCode);
    virtual void fbUserDetailCallback(cocos2d::CCDictionary* data);
    virtual void fbMessageCallback(int responseCode);
    virtual void fbChallengeCallback(int responseCode);
    virtual void fbGiftCallback(int responseCode);
    virtual void fbPageLikeCallback(int responseCode);
    virtual void fbFriendsCallback(cocos2d::CCArray* friends);
    virtual void fbHighScoresCallback(cocos2d::CCArray* highScores);
    
};

#endif // __HELLOWORLD_SCENE_H__
