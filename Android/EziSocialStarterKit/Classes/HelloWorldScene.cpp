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


//#warning You can remove this method if you don't want auto facbook login feature when scene is loaded.
void HelloWorld::onEnterTransitionDidFinish()
{
    CCLog("Enter Transition Finished; Attempting Facebook Login.");
    EziSocialObject::sharedObject()->performLoginUsingFacebook(false);
}

// ---------------------------------------------------------
#pragma mark - Facebook Delegate Methods
// ---------------------------------------------------------


void HelloWorld::fbSessionCallback(int responseCode, const char* responseMessage)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGIN_SUCCESSFUL:
        {
            CCMessageBox(responseMessage, "Facebook Session - Response");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGIN_FAILED:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGIN_PERMISSION_DENIED:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGIN_APP_NOT_ALLOWERD_TO_USE_FB:
        {
            CCMessageBox(responseMessage, "Facebook Session - Response");
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_LOGOUT_SUCCESSFUL:
        {
            CCMessageBox(responseMessage, "Facebook Session - Response");
            break;
        }
        default:
            break;
    }
    
}

void HelloWorld::fbUserDetailCallback(int responseCode, const char* responseMessage, EziFacebookUser* fbUser)
{
    CCMessageBox(responseMessage, "User Details - Response");
    
    if (fbUser)
    {
        CCLOG("User Name = %s", fbUser->getUserName());
    }
}

void HelloWorld::fbMessageCallback(int responseCode, const char* responseMessage)
{
    const char* title = "";
    
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_NORMAL_MESSAGE_PUBLISHED:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_NORMAL_MESSAGE_CANCELLED:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_NORMAL_MESSAGE_ERROR:
        {
            title = "Normal Post Response";
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_AUTO_MESSAGE_PUBLISHED:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_AUTO_MESSAGE_ERROR:
        {
            title = "Auto Post Response";
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_SCORE_POSTED:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_SCORE_POSTING_ERROR:
        {
            title = "Post Score API Response";
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::FB_SCORE_DELETED:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_SCORE_DELETE_ERROR:
        {
            title = "Delete Score API Response";
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::ERROR_PUBLISH_PERMISSION_ERROR:
        {
            title = "Publish Permission - Denied";
            break;
        }
        case EziSocialWrapperNS::RESPONSE_CODE::ERROR_INTERNET_NOT_AVAILABLE:
        {
            title = "Internet not available";
            break;
        }
            
        default:
            break;
    }
    
    CCMessageBox(responseMessage, title);
}

void HelloWorld::fbSendRequestCallback(int responseCode, const char* responseMessage, cocos2d::CCArray* friendsGotRequests)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_GIFT_SENDING_ERROR:
            CCMessageBox(responseMessage, "Gift Request Error");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::FB_GIFT_SENDING_CANCELLED:
            CCMessageBox(responseMessage, "Gift Request Cancelled");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::FB_GIFT_SENT:
            CCMessageBox(responseMessage, "Gift Request Success");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::FB_CHALLENGE_SENDING_ERROR:
            CCMessageBox(responseMessage, "Challenge Request Error");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::FB_CHALLEGE_CANCELLED:
            CCMessageBox(responseMessage, "Challenge Request Cancelled");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::FB_CHALLEGE_SENT:
            CCMessageBox(responseMessage, "Challenge Request Success");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::FB_INVITE_SENDING_ERROR:
            CCMessageBox(responseMessage, "Invite Request Error");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::FB_INVITE_CANCELLED:
            CCMessageBox(responseMessage, "Invite Request Cancelled");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::FB_INVITE_SENT:
            CCMessageBox(responseMessage, "Invite Request Success");
            break;
            
            
            
        default:
            break;
    }
}

void HelloWorld::fbIncomingRequestCallback(int responseCode, const char* responseMessage, int totalIncomingRequests)
{
    if (totalIncomingRequests > 0)
    {
        CCMessageBox(CCString::createWithFormat("Total Pending Requests = %d", totalIncomingRequests, NULL)->getCString(),
                     "Got New Incoming Request");

    }
    else if (responseCode == EziSocialWrapperNS::RESPONSE_CODE::ERROR_INTERNET_NOT_AVAILABLE ||
             responseCode == EziSocialWrapperNS::RESPONSE_CODE::FB_INCOMING_REQUEST_ERROR)
    {
        CCMessageBox(responseMessage, "Incoming Request Error");
    }
    else if (responseCode == EziSocialWrapperNS::RESPONSE_CODE::FB_NO_NEW_INCOMING_REQUEST)
    {
        CCLOG(responseMessage);
    }
}

void HelloWorld::fbPageLikeCallback(int responseCode, const char* responseMessage)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::FB_PAGELIKE_ERROR:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_PAGELIKE_NEGATIVE:
        case EziSocialWrapperNS::RESPONSE_CODE::FB_PAGELIKE_POSITIVE:
        case EziSocialWrapperNS::RESPONSE_CODE::ERROR_INTERNET_NOT_AVAILABLE:
        {
            CCMessageBox(responseMessage, "PageLike Response");
            break;
        }
        default:
            break;
    }
}

void HelloWorld::fbPostPhotoCallback(int responseCode, const char* responseMessage)
{
    CCMessageBox(responseMessage, CCString::createWithFormat("Response Code = %d", responseCode, NULL)->getCString());
}


// ---------------------------------------------------------
#pragma mark - EMail Delegate Methods
// ---------------------------------------------------------
void HelloWorld::mailCallback(int responseCode)
{
    switch (responseCode)
    {
        case EziSocialWrapperNS::RESPONSE_CODE::MAIL_SEND_SUCCESS:
            CCMessageBox("Email sent successfully", "Email Status");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::MAIL_SEND_STORED:
            CCMessageBox("User stored the email", "Email Status");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::MAIL_SEND_CANCLLED:
            CCMessageBox("User cancelled email.", "Email Status");
            break;
            
        case EziSocialWrapperNS::RESPONSE_CODE::MAIL_SEND_ERROR:
            CCMessageBox("Got error while sending email.", "Email Status");
            break;
            
            
        default:
            break;
    }
}

void HelloWorld::fbUserPhotoCallback(const char *userPhotoPath)
{
        CCSprite* userPhoto = EziSocialObject::sharedObject()->generateCCSprite(userPhotoPath);

        
        this->addChild(userPhoto);
        userPhoto->setAnchorPoint(ccp(0, 1));
        userPhoto->setPosition(ccp(this->getContentSize().width/2, this->getContentSize().height/2));

    
}

void HelloWorld::twitterCallback(int responseCode)
{
    if (responseCode == EziSocialWrapperNS::RESPONSE_CODE::TWIT_SEND)
    {
        CCMessageBox("Tweet Send", "Twitter");
    }
    else if (responseCode == EziSocialWrapperNS::RESPONSE_CODE::TWIT_CANCEL)
    {
        CCMessageBox("Tweet Cancelled", "Twitter");
    }
}
