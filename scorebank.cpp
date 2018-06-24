#include<iostream>
#include<fstream>
#include "scorebank.h"
using namespace std;
USING_NS_CC;

Scene *scorebank::createScene()
{
	auto scene = Scene::create();

	scorebank* layer = scorebank::create();

	scene->addChild(layer);
	return scene;
}

bool scorebank::init()
{
	if (!Scene::init())
	{
		return false;
	}
	Size visiblesize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("SCORE RANK", "fonts/Marker Felt.ttf", 60);

	label->setColor(Color3B::WHITE);

	label->setPosition(Vec2(origin.x + visiblesize.width / 2,
		origin.y + visiblesize.height - label->getContentSize().height));

	this->addChild(label, 2);

	ifstream in("score.txt");
	for (int bb = 0; bb < 19; bb++)
	{
		in.getline(highscore[bb], 6);
	}

	for (int ac = 0; ac < 19; ac++)
	{
		if (highscore[ac][0] > 0)
		{
			CCString *scores = CCString::createWithFormat("%d", ac + 1);

			auto lbscore = Label::createWithTTF(scores->getCString(), "fonts/arial.ttf", 30);
			lbscore->setPosition(Vec2(origin.x + visiblesize.width / 2 - 100,
				origin.y + visiblesize.height - 140 - ac * 40));
			this->addChild(lbscore, 20, ac + 1);

			auto mh = Label::createWithTTF(":", "fonts/arial.ttf", 30);
			mh->setPosition(Vec2(origin.x + visiblesize.width / 2 - 90,
				origin.y + visiblesize.height - 140 - ac * 40));
			this->addChild(mh, 20);
		}
		for (int bc = 0; bc < 5; bc++)
		{
			//Node *n = this->getChildByTag(highscore[ac][bc]);
			CCString *scores = CCString::createWithFormat("%c", highscore[ac][bc]);

			auto lbscore = Label::createWithTTF(scores->getCString(), "fonts/arial.ttf", 30);
			lbscore->setPosition(Vec2(origin.x + visiblesize.width/2 -15+ 17*bc,
				origin.y + visiblesize.height-140-ac*40));
			this->addChild(lbscore, 20, highscore[ac][bc]);
		}
	}
	in.close();
}