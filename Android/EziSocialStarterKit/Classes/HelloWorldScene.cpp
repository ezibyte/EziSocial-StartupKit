#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "EziSocialDefinition.h"

#include "EziSocialObject.h"

using namespace cocos2d;
using namespace CocosDenshion;




CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    // Set the Facebook Delegate
    EziSocialObject::sharedObject()->setFacebookDelegate(this);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


#warning You can remove this method if you don't want auto facbook login feature when scene is loaded.
void HelloWorld::onEnterTransitionDidFinish()
{
    CCLog("Enter Transition Finished; Attempting Facebook Login.");
    EziSocialObject::sharedObject()->performLoginUsingFacebook();
}

// ---------------------------------------------------------
    #pragma mark - Facebook Delegate Methods
// ---------------------------------------------------------


void HelloWorld::fbSessionCallback(int responseCode)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGIN_NO_TOKEN:
        {
            CCMessageBox("Token Not available", "fbSessionCallback");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGIN_SUCCESSFUL:
        {
            CCMessageBox("Login Successful", "fbSessionCallback");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGIN_FAILED:
        {
            CCLOG("FB_LOGIN_FAILED or User cancelled Login.");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGOUT_SUCCESSFUL:
        {
            CCMessageBox("Logout Successful", "fbSessionCallback");
            break;
        }
        default:
            break;
    }
    
}

void HelloWorld::fbUserDetailCallback(CCDictionary* data)
{
    if (data)
    {
        CCMessageBox("Got user data", "fbUserDetailCallback");
    }
    else
    {
        CCMessageBox("Sorry, user details not available", "fbUserDetailCallback");
    }
}

void HelloWorld::fbMessageCallback(int responseCode)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_MESSAGE_PUBLISHED:
        {
            CCMessageBox("Message posted on user wall successfully.", "Post Messgae on Wall");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_MESSAGE_CANCELLLED:
        {
            CCMessageBox("User cancelled the message.", "Post Messgae on Wall");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_MESSAGE_PUBLISHING_ERROR:
        {
            CCMessageBox("Got error while publishing the message.", "Post Messgae on Wall");
            break;
        }
        default:
            break;
    }
}

void HelloWorld::fbChallengeCallback(int responseCode)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_CHALLEGE_CANCELLED:
        {
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_CHALLEGE_PUBLISHED:
        {
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_CHALLENGE_SENDING_ERROR:
        {
            break;
        }
        default:
            break;
    }
}

void HelloWorld::fbGiftCallback(int responseCode)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_GIFT_SENDING_CANCELLED:
        {
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_GIFT_SENDING_ERROR:
        {
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_GIFT_SENT:
        {
            break;
        }
        default:
            break;
    }
}

void HelloWorld::fbPageLikeCallback(int responseCode)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_PAGELIKE_ERROR:
        {
            CCMessageBox("Got error while checking page like.", "Error - Page Like");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_PAGELIKE_NEGATIVE:
        {
            CCMessageBox("Ah! He don't like my page", "PageLike - Negative");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_PAGELIKE_POSITIVE:
        {
            CCMessageBox("Hurray! he like my page", "PageLike - Positive");
            break;
        }
        default:
            break;
    }
}

void HelloWorld::fbFriendsCallback(cocos2d::CCArray* friends)
{
    if (friends && friends->count() > 0)
    {
        CCLOG("Total Friends playing this game = %d", friends->count());
        for (int i=0; i<friends->count(); i++)
        {
            CCDictionary *friendDetails = (CCDictionary *)friends->objectAtIndex(i);
            CCString* friendID = (CCString*)friendDetails->objectForKey("id");
            CCString* friendName = (CCString*)friendDetails->objectForKey("name");
            CCLOG("%d. ID = %s, Name = %s", (i+1), friendID->getCString() ,friendName->getCString());
        }
        CCMessageBox((CCString::createWithFormat("Total friends playing this game = %d", friends->count()))->getCString(),
                     "Friends Playing This Game");
    }
    else
    {
        CCMessageBox("None of your friend playing this game.", "Friends Playing this game.");
        
        //CCUserDefault::sharedUserDefault()->setBoolForKey("", true);
        
    }
}

void HelloWorld::fbHighScoresCallback(cocos2d::CCArray* highScores)
{
    if (highScores && highScores->count() > 0)
    {
        CCLOG("Total High Scores available = %d", highScores->count());
    }
    else
    {
        CCMessageBox("High Scores are not available.", "Game High Scores.");
    }
}
