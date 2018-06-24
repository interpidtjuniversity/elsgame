#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCloseCallback(cocos2d::Ref *pSender);
	void menuhelpcallback(cocos2d::Ref *pSender);
	void menuback(cocos2d::Ref *pSender);
	void menudouble(cocos2d::Ref *pSender);
	void menuscore(cocos2d::Ref *pSender);
	void menunextcallback(cocos2d::Ref *pSender);
	void easymode(cocos2d::Ref *pSender);
	void normalmode(cocos2d::Ref *pSender);
	void hardmode(cocos2d::Ref *pSender);
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
