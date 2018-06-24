#include "HelloWorldScene.h"
#include "Alone.h"
#include "cooperate.h"
#include "scorebank.h"
#include<iostream>
#include<fstream>
USING_NS_CC;
using std::string;

Scene* HelloWorld::createScene()
{
	Scene* scene = Scene::create();

	HelloWorld* layer = HelloWorld::create();

	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	Size visiblesize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("Tetris", "fonts/Marker Felt.ttf", 60);

	label->setColor(Color3B::WHITE);

	label->setPosition(Vec2(origin.x + visiblesize.width / 2,
		origin.y + visiblesize.height - label->getContentSize().height));

	this->addChild(label, 2);

	auto background = Sprite::create("background.png");
	background->setPosition(Vec2(visiblesize.width / 2, visiblesize.height / 2));//这句自己根据需要修改
	Size mywinsize = Director::getInstance()->getWinSize();
	float winw = mywinsize.width; //获取屏幕宽度
	float winh = mywinsize.height;//获取屏幕高度
	float spx = background->getTextureRect().getMaxX();
	float spy = background->getTextureRect().getMaxY();
	background->setScaleX(winw / spx); //设置精灵宽度缩放比例
	background->setScaleY(winh / spy);
	this->addChild(background,1);

	auto exitbutton = MenuItemImage::create("exitbutton.png","exitbuttonpressed.png",CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
	exitbutton->setPosition(Vec2(origin.x + visiblesize.width/2 ,origin.y +visiblesize.height/6));

	auto helpbutton = MenuItemImage::create("helpbutton.png","helpbuttonpressed.png",CC_CALLBACK_1(HelloWorld::menuhelpcallback,this));
	helpbutton->setPosition(Vec2(origin.x + visiblesize.width / 2, origin.y + visiblesize.height/2));

	auto startbutton = MenuItemImage::create("startbutton.png", "startbuttonpressed.png",
		CC_CALLBACK_1(HelloWorld::menunextcallback, this));
	startbutton->setPosition(Vec2(origin.x + visiblesize.width / 2 , origin.y+visiblesize.height / 6*5));

	auto startbutton1 = MenuItemImage::create("startbutton1.png", "startbutton1pressed.png",
		CC_CALLBACK_1(HelloWorld::menudouble, this));
	startbutton1->setPosition(Vec2(origin.x + visiblesize.width / 2, origin.y + visiblesize.height / 6 * 4));

	auto scorebutton = MenuItemImage::create("scorebutton.png", "scorebuttonpressed.png",
		CC_CALLBACK_1(HelloWorld::menuscore, this));
	scorebutton->setPosition(Vec2(origin.x + visiblesize.width / 2, origin.y + visiblesize.height / 3));

	auto menu = Menu::create(exitbutton, startbutton, helpbutton, startbutton1, scorebutton,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);

    return true;
}

void HelloWorld::menuCloseCallback(Ref *pSender)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT )
	MessageBox("You will close","Alert");
	return;
#endif

	Director::getInstance()->end();
}


void HelloWorld::menunextcallback(Ref* pSender)
{
	Size visiblesize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto easybutton = MenuItemImage::create("easybutton.png", "easybuttonpressed.png",
		CC_CALLBACK_1(HelloWorld::easymode, this));
	easybutton->setPosition(Vec2(origin.x + visiblesize.width / 2+100, origin.y + visiblesize.height / 6 * 5));

	auto normalbutton = MenuItemImage::create("normalbutton.png", "normalbuttonpressed.png",
		CC_CALLBACK_1(HelloWorld::normalmode, this));
	normalbutton->setPosition(Vec2(origin.x + visiblesize.width / 2+180, origin.y + visiblesize.height / 6 * 5));

	auto hardbutton = MenuItemImage::create("hardbutton.png", "hardbuttonpressed.png",
		CC_CALLBACK_1(HelloWorld::hardmode, this));
	hardbutton->setPosition(Vec2(origin.x + visiblesize.width / 2+260, origin.y + visiblesize.height / 6 * 5));

	auto menu = Menu::create(easybutton, normalbutton, hardbutton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);
}

void HelloWorld::menudouble(Ref* pSender)
{
	//新建MyScene实例
	auto scene = MainScene4::createScene();
	//用这MyScene实例替换当前scene
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::menuhelpcallback(Ref *pSender)
{
	Size visiblesize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto helppage = Sprite::create("helppage.png");
	helppage->setPosition(Vec2(visiblesize.width / 2, visiblesize.height / 2));//这句自己根据需要修改
	Size mywinsize = Director::getInstance()->getWinSize();
	float winw = mywinsize.width; //获取屏幕宽度
	float winh = mywinsize.height;//获取屏幕高度
	float spx = helppage->getTextureRect().getMaxX();
	float spy = helppage->getTextureRect().getMaxY();
	helppage->setScaleX(winw / spx/2); //设置精灵宽度缩放比例
	helppage->setScaleY(winh / spy);
	this->addChild(helppage, 2);
	helppage->setTag(12);

	auto backbutton = MenuItemImage::create("backbutton.png", "backbuttonpressed.png", CC_CALLBACK_1(HelloWorld::menuback, this));
	backbutton->setPosition(Vec2(origin.x + visiblesize.width - backbutton->getContentSize().width / 2,
		origin.y + backbutton->getContentSize().height / 2));
	auto menu = Menu::create( backbutton, NULL);
	menu->setPosition(Vec2::ZERO);
	menu->setTag(13);
	this->addChild(menu, 2);
}

void HelloWorld::menuback(Ref *pSender)
{
	removeChildByTag(12);
	removeChildByTag(13);
}

void HelloWorld::menuscore(cocos2d::Ref *pSender)
{
	//新建MyScene实例
	auto scene = scorebank::createScene();
	//用这MyScene实例替换当前scene
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::easymode(cocos2d::Ref *pSender)
{
	auto scene = MainScene1::createScene1();
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::normalmode(cocos2d::Ref *pSender)
{
	auto scene = MainScene1::createScene2();
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::hardmode(cocos2d::Ref *pSender)
{
	auto scene = MainScene1::createScene3();
	Director::getInstance()->replaceScene(scene);
}