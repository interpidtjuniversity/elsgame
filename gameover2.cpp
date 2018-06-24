#include "gameover2.h"
#include "cooperate.h"
#include<iostream>
#include<fstream>
USING_NS_CC;

Scene *Gameover2::createScene()
{
	auto scene = Scene::create();

	Gameover2* layer = Gameover2::create();

	scene->addChild(layer);
	return scene;
}

bool Gameover2::init()
{
	if (!Scene::init())
	{
		return false;
	}
	Size visiblesize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto helppage = Sprite::create("gameover.png");
	helppage->setPosition(Vec2(visiblesize.width / 2, visiblesize.height / 2));//����Լ�������Ҫ�޸�
	Size mywinsize = Director::getInstance()->getWinSize();
	float winw = mywinsize.width; //��ȡ��Ļ���
	float winh = mywinsize.height;//��ȡ��Ļ�߶�
	float spx = helppage->getTextureRect().getMaxX();
	float spy = helppage->getTextureRect().getMaxY();
	helppage->setScaleX(winw / spx); //���þ��������ű���
	helppage->setScaleY(winh / spy);
	this->addChild(helppage, 2);
	auto label = Label::createWithTTF("Your Score:", "fonts/Marker Felt.ttf", 40);

	label->setColor(Color3B::WHITE);

	label->setPosition(Vec2(origin.x + visiblesize.width / 3,
		origin.y + visiblesize.height / 2));

	this->addChild(label, 2);

	Node *n = this->getChildByTag(score1);
	CCString *scores = CCString::createWithFormat("%d", score1);

	auto lbscore = Label::createWithTTF(scores->getCString(), "fonts/arial.ttf", 40);
	lbscore->setPosition(Vec2(origin.x + visiblesize.width / 2 - 20,
		origin.y + visiblesize.height / 2));
	this->addChild(lbscore, 20, score1);

	auto restartbutton = MenuItemImage::create("restartbutton.png", "restartbuttonpressed.png",
		CC_CALLBACK_1(Gameover2::restart, this));
	restartbutton->setPosition(Vec2(origin.x + visiblesize.width - 380, origin.y + visiblesize.height / 3 * 2));
	auto menu = Menu::create(restartbutton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);

	ofstream fp;
	fp.open("score1.txt", ios::out | ios::app);
	fp << score1 << endl;
	fp.close();
}

void Gameover2::restart(cocos2d::Ref *pSender)
{
	auto scene = MainScene4::createScene();
	Director::getInstance()->replaceScene(scene);
}