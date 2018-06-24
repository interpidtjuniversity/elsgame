#include "Alone.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include<iostream>
#include "gameover.h"
using namespace std;
float Position[1000][99999] = { 900 };
int score = 0;

Scene* MainScene1::createScene1()
{
	auto scene = Scene::createWithPhysics();
	Vect gravity(0, -10.0f);
	scene->getPhysicsWorld()->setGravity(gravity);
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); 
	auto layer = MainScene1::create();
	layer->setPhyWorld(scene->getPhysicsWorld());
	// add layer as a child to scene  
	scene->addChild(layer);
	// return the scene  
	return scene;
}

Scene* MainScene1::createScene2()
{
	auto scene = Scene::createWithPhysics();
	Vect gravity(0, -20.0f);
	scene->getPhysicsWorld()->setGravity(gravity);
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = MainScene1::create();
	layer->setPhyWorld(scene->getPhysicsWorld());
	// add layer as a child to scene  
	scene->addChild(layer);
	// return the scene  
	return scene;
}

Scene* MainScene1::createScene3()
{
	auto scene = Scene::createWithPhysics();
	Vect gravity(0, -30.0f);
	scene->getPhysicsWorld()->setGravity(gravity);
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = MainScene1::create();
	layer->setPhyWorld(scene->getPhysicsWorld());
	// add layer as a child to scene  
	scene->addChild(layer);
	// return the scene  
	return scene;
}

void MainScene1::update(float delta)
{
	Node::update(delta);
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW, rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
	auto upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW, downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
	auto qArrow = EventKeyboard::KeyCode::KEY_Q;
	if (isKeyPressed(leftArrow) && a == 0) {
		keyPressedDuration(leftArrow);
		a++;
	}
	else if (isKeyPressed(rightArrow) && b == 0) {
		keyPressedDuration(rightArrow);
		b++;
	}
	else if (isKeyPressed(upArrow) && c == 0) {
		keyPressedDuration(upArrow);
		c++;
	}
	else if (isKeyPressed(downArrow) && d == 0) {
		keyPressedDuration(downArrow);
		d++;
	}
	else if (isKeyPressed(qArrow) && e == 0){
		keyPressedDuration(qArrow);
		e++;
	}
	//
	else if (isKeyPressed(leftArrow) == 0 && a == 1) {
		a--;
	}
	else if (isKeyPressed(rightArrow) == 0 && b == 1) {
		b--;
	}
	else if (isKeyPressed(upArrow) == 0 && c == 1) {
		c--;
	}
	else if (isKeyPressed(downArrow) == 0 && d == 1) {
		d--;
	}
	else if (isKeyPressed(qArrow) == 0 && e == 1){
		e--;
	}
	for (int i = 0; i < 3; ++i)
	{
		getScene()->getPhysicsWorld()->step(1 / 180.0f);                      //
	}
}

bool MainScene1::isKeyPressed(EventKeyboard::KeyCode keyCode) {
	if (keys[keyCode]) {
		return true;
	}
	else {
		return false;
	}
}
void MainScene1::keyPressedDuration(EventKeyboard::KeyCode code)
{
	int offsetX = 0, offsetY = 0;
	Sprite *sss = Sprite::create("square.png");
	switch (code) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		offsetX = -sss->getContentSize().width / 2;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		offsetX = sss->getContentSize().width / 2;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		offsetY = sss->getContentSize().height;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		offsetY = -sss->getContentSize().height;
		break;
	case EventKeyboard::KeyCode::KEY_Q:
		sprites[i]->runAction(RotateTo::create(0.0f, rads)), rads = rads + 90;
		if (rads > 360)
			rads = 0;
	default:
		offsetY = offsetX = 0;
		break;
	}
	// 0.0s耗时
	auto moveTo = MoveTo::create(0.0, Vec2(sprites[i]->getPositionX() + offsetX, sprites[i]->getPositionY() + offsetY));
	sprites[i]->runAction(moveTo);
}

bool MainScene1::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	score = 0;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto edgeSp = Sprite::create();
	auto edgeSp1 = Sprite::create();
	auto body1 = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT);
	auto body5 = PhysicsBody::createEdgeBox(Size(602, 860));
	body1->getShape(0)->setRestitution(0);
	body5->getShape(0)->setRestitution(0);
	Vect force = Vect(0.0f, 0.0f);
	body1->applyImpulse(force);
	body5->applyImpulse(force);
	edgeSp->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	edgeSp1->setPosition(Point(301, 430));
	edgeSp->setPhysicsBody(body1);
	edgeSp1->setPhysicsBody(body5);
	this->addChild(edgeSp); edgeSp->setTag(0);
	this->addChild(edgeSp1); edgeSp->setTag(1);
	//
	auto label = Label::createWithTTF("SCORE", "fonts/Marker Felt.ttf", 40);

	label->setColor(Color3B::WHITE);

	label->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4,
		origin.y + visibleSize.height / 4));
	this->addChild(label, 2);

	auto nextblock1 = Label::createWithTTF("NEXT", "fonts/Marker Felt.ttf", 40);

	nextblock1->setColor(Color3B::WHITE);

	nextblock1->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4,
		origin.y + visibleSize.height / 4*3+60));
	this->addChild(nextblock1, 2);

	Node *n = this->getChildByTag(score);
	CCString *scores = CCString::createWithFormat("%d", score);

	auto lbscore = Label::createWithTTF(scores->getCString(), "fonts/arial.ttf", 30);
	lbscore->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4,
		origin.y + visibleSize.height / 4 - 50));
	this->addChild(lbscore, 20, score);


	//
	auto listener1 = EventListenerKeyboard::create();
	listener1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
		log("key pressed");
	};
	listener1->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
		log("key release");
		listener1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
			keys[keyCode] = true;
		};

		listener1->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
			keys[keyCode] = false;
		};
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	//
	evaluation();
	random();
	sprites[i] = addBlock(1, Point(300, 800));
	next[1] = nextblock(rands[1], Point(1010, 650));
	this->schedule(schedule_selector(MainScene1::updates));
	this->scheduleUpdate();
	return true;
}
void MainScene1::updates(float dt)
{
	Position[i][0] = 1000;
	sss = Sprite::create("square.png");
	float k = sss->getContentSize().height / 2;
	Position[i][j + 1] = sprites[i]->getPositionY();
	//
	//
	j++;
	if (abs(Position[i][j] - Position[i][j - 1]) == 0)
	{
		remove1();
		next[i + 2] = nextblock(rands[i + 2], Point(1010, 650));
		sprites[i]->getPhysicsBody()->getShape(0)->setFriction(0);
		sprites[i]->getPhysicsBody()->setDynamic(false);
		//
		// 按照刚体的旋转角度添加新的刚体
		int finalrads = sprites[i]->getRotation();
		int fx = sprites[i]->getPositionX();
		int fy = sprites[i]->getPositionY();
		if (i == 0)
		{
			addbaseblock(finalrads, fx, fy, 1);
			score = score + 4;
			removeChild(sprites[i], true);
		}
		else
		{
			addbaseblock(finalrads, fx, fy, rands[i]);
			score = score + 4;
			removeChild(sprites[i], true);
			clear();
		}
		//
		removeChild(next[i + 1], true);
		//
		i++;
		if (rands[i] == 1 || rands[i] == 4 || rands[i] == 6 || rands[i] == 8 || rands[i] == 10 || rands[i] == 12 || rands[i] == 14 || rands[i] == 15)
		{
			sprites[i] = addBlock(rands[i], Point(300, 800));
		}
		else
		{
			sprites[i] = addBlock(rands[i], Point(310, 800));
		}
		j = 0;
		rads = 0;
		display();
		gameover();
	}
}
Sprite* MainScene1::fun(vector<Vec2*>*shapeVecs, vector<int>* shapeVecAmount, int shapeAmount, int number, Point p)
{
	PhysicsBody* body = PhysicsBody::create();
	Vect force = Vect(0.0f, 0.0f);
	body->applyImpulse(force);
	body->addMoment(999999999999999.9f);
	body->setMoment(999999999999999.9f);
	//	body->getShape(0)->setFriction(1000.0f);
	for (int i = 0; i < shapeAmount; i++)
	{
		auto shape = PhysicsShapePolygon::create(shapeVecs->at(i), shapeVecAmount->at(i));
		shape->setRestitution(0);
		body->addShape(shape);
	}
	Sprite * nima;
	if (number == 1)
	{
		nima = Sprite::create("1.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 2)
	{
		nima = Sprite::create("2.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 3)
	{
		nima = Sprite::create("3.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 4)
	{
		nima = Sprite::create("4.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 5)
	{
		nima = Sprite::create("5.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 6)
	{
		nima = Sprite::create("6.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 7)
	{
		nima = Sprite::create("7.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 8)
	{
		nima = Sprite::create("8.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 9)
	{
		nima = Sprite::create("9.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 10)
	{
		nima = Sprite::create("10.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 11)
	{
		nima = Sprite::create("11.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 12)
	{
		nima = Sprite::create("12.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 13)
	{
		nima = Sprite::create("13.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else if (number == 14)
	{
		nima = Sprite::create("14.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	else
	{
		nima = Sprite::create("15.png");
		nima->setPosition(p);
		nima->setPhysicsBody(body);
		this->addChild(nima);
	}
	return nima;
}
Sprite* MainScene1::addBlock(int number, Point p)
{
	Sprite *square = Sprite::create("square.png");
	float k = square->getContentSize().width / 2;
	Vec2 *form1 = new Vec2[4];
	Vec2 *form2 = new Vec2[4];
	Vec2 *form3 = new Vec2[4];
	Vec2 *form4 = new Vec2[4];
	vector<Vec2*>* vec = new vector<Vec2*>[4];
	vector<int>*vecNumber = new vector<int>[4];
	if (number == 3)
	{
		form1[0].setPoint(-3 * k, 2 * k);
		form1[1].setPoint(-k, 2 * k);
		form1[2].setPoint(-k, 0);
		form1[3].setPoint(-3 * k, 0);
		form2[0].setPoint(-k, 0);
		form2[1].setPoint(-k, -2 * k);
		form2[2].setPoint(-3 * k, -2 * k);
		form2[3].setPoint(-3 * k, 0);
		form3[0].setPoint(-k, 0);
		form3[1].setPoint(k, 0);
		form3[2].setPoint(-k, -2 * k);
		form3[3].setPoint(k, -2 * k);
		form4[0].setPoint(k, 0);
		form4[1].setPoint(3 * k, 0);
		form4[2].setPoint(3 * k, -2 * k);
		form4[3].setPoint(k, -2 * k);
	}
	else if (number == 2)
	{
		form1[0].setPoint(-k, 4 * k);
		form1[1].setPoint(k, 4 * k);
		form1[2].setPoint(k, 2 * k);
		form1[3].setPoint(-k, 2 * k);
		form2[0].setPoint(k, 2 * k);
		form2[1].setPoint(-k, 2 * k);
		form2[2].setPoint(-k, 0);
		form2[3].setPoint(k, 0);
		form3[0].setPoint(-k, 0);
		form3[1].setPoint(k, 0);
		form3[2].setPoint(k, -2 * k);
		form3[3].setPoint(-k, -2 * k);
		form4[0].setPoint(k, -2 * k);
		form4[1].setPoint(-k, -2 * k);
		form4[2].setPoint(-k, -4 * k);
		form4[3].setPoint(k, -4 * k);
	}
	else if (number == 1)
	{
		form1[0].setPoint(-4 * k, k);
		form1[1].setPoint(-4 * k, -k);
		form1[2].setPoint(-2 * k, -k);
		form1[3].setPoint(-2 * k, k);
		form2[0].setPoint(-2 * k, k);
		form2[1].setPoint(-2 * k, -k);
		form2[2].setPoint(0, -k);
		form2[3].setPoint(0, k);
		form3[0].setPoint(0, -k);
		form3[1].setPoint(0, k);
		form3[2].setPoint(2 * k, k);
		form3[3].setPoint(2 * k, -k);
		form4[0].setPoint(2 * k, k);
		form4[1].setPoint(2 * k, -k);
		form4[2].setPoint(4 * k, -k);
		form4[3].setPoint(4 * k, k);
	}
	else if (number == 4)
	{
		form1[0].setPoint(-2 * k, 3 * k);
		form1[1].setPoint(0, 3 * k);
		form1[2].setPoint(0, k);
		form1[3].setPoint(-2 * k, k);
		form2[0].setPoint(0, 3 * k);
		form2[1].setPoint(2 * k, 3 * k);
		form2[2].setPoint(2 * k, k);
		form2[3].setPoint(0, k);
		form3[0].setPoint(0, -k);
		form3[1].setPoint(-2 * k, -k);
		form3[2].setPoint(-2 * k, k);
		form3[3].setPoint(0, k);
		form4[0].setPoint(0, -k);
		form4[1].setPoint(0, -3 * k);
		form4[2].setPoint(-2 * k, -3 * k);
		form4[3].setPoint(-2 * k, -k);
	}
	else if (number == 5)
	{
		form1[0].setPoint(-3 * k, 0);
		form1[1].setPoint(-3 * k, 2 * k);
		form1[2].setPoint(-k, 2 * k);
		form1[3].setPoint(-k, 0);
		form2[0].setPoint(-k, 2 * k);
		form2[1].setPoint(-k, 0);
		form2[2].setPoint(k, 0);
		form2[3].setPoint(k, 2 * k);
		form3[0].setPoint(k, 0);
		form3[1].setPoint(k, 2 * k);
		form3[2].setPoint(3 * k, 2 * k);
		form3[3].setPoint(3 * k, 0);
		form4[0].setPoint(k, 0);
		form4[1].setPoint(3 * k, 0);
		form4[2].setPoint(3 * k, -2 * k);
		form4[3].setPoint(k, -2 * k);
	}
	else if (number == 6)
	{
		form1[0].setPoint(0, 3 * k);
		form1[1].setPoint(2 * k, 3 * k);
		form1[2].setPoint(2 * k, k);
		form1[3].setPoint(0, k);
		form2[0].setPoint(0, k);
		form2[1].setPoint(2 * k, k);
		form2[2].setPoint(0, -k);
		form2[3].setPoint(2 * k, -k);
		form3[0].setPoint(0, -k);
		form3[1].setPoint(2 * k, -k);
		form3[2].setPoint(2 * k, -3 * k);
		form3[3].setPoint(0, -3 * k);
		form4[0].setPoint(0, -k);
		form4[1].setPoint(0, -3 * k);
		form4[2].setPoint(-2 * k, -3 * k);
		form4[3].setPoint(-2 * k, -k);
	}
	else if (number == 7)
	{
		form1[0].setPoint(-3 * k, 0);
		form1[1].setPoint(-3 * k, -2 * k);
		form1[2].setPoint(-k, -2 * k);
		form1[3].setPoint(-k, 0);
		form2[0].setPoint(-k, 0);
		form2[1].setPoint(-k, -2 * k);
		form2[2].setPoint(k, -2 * k);
		form2[3].setPoint(k, 0);
		form3[0].setPoint(k, 0);
		form3[1].setPoint(k, 2 * k);
		form3[2].setPoint(-k, 2 * k);
		form3[3].setPoint(-k, 0);
		form4[0].setPoint(k, 0);
		form4[1].setPoint(3 * k, 0);
		form4[2].setPoint(3 * k, 2 * k);
		form4[3].setPoint(k, 2 * k);
	}
	else if (number == 8)
	{
		form1[0].setPoint(-2 * k, 3 * k);
		form1[1].setPoint(0, 3 * k);
		form1[2].setPoint(0, k);
		form1[3].setPoint(-2 * k, k);
		form2[0].setPoint(-2 * k, k);
		form2[1].setPoint(-2 * k, -k);
		form2[2].setPoint(0, -k);
		form2[3].setPoint(0, k);
		form3[0].setPoint(0, -k);
		form3[1].setPoint(0, k);
		form3[2].setPoint(2 * k, k);
		form3[3].setPoint(2 * k, -k);
		form4[0].setPoint(0, -k);
		form4[1].setPoint(2 * k, -k);
		form4[2].setPoint(2 * k, -3 * k);
		form4[3].setPoint(0, -3 * k);
	}
	else if (number == 9)
	{
		form1[0].setPoint(-3 * k, 0);
		form1[1].setPoint(-3 * k, 2 * k);
		form1[2].setPoint(-k, 2 * k);
		form1[3].setPoint(-k, 0);
		form2[0].setPoint(-k, 0);
		form2[1].setPoint(-k, 2 * k);
		form2[2].setPoint(k, 2 * k);
		form2[3].setPoint(k, 0);
		form3[0].setPoint(-k, 0);
		form3[1].setPoint(k, 0);
		form3[2].setPoint(k, -2 * k);
		form3[3].setPoint(-k, -2 * k);
		form4[0].setPoint(k, 0);
		form4[1].setPoint(k, -2 * k);
		form4[2].setPoint(3 * k, -2 * k);
		form4[3].setPoint(3 * k, 0);
	}
	else if (number == 10)
	{
		form1[0].setPoint(0, 3 * k);
		form1[1].setPoint(2 * k, 3 * k);
		form1[2].setPoint(2 * k, k);
		form1[3].setPoint(0, k);
		form2[0].setPoint(0, k);
		form2[1].setPoint(2 * k, k);
		form2[2].setPoint(2 * k, -k);
		form2[3].setPoint(0, -k);
		form3[0].setPoint(0, -k);
		form3[1].setPoint(0, k);
		form3[2].setPoint(-2 * k, k);
		form3[3].setPoint(-2 * k, -k);
		form4[0].setPoint(-2 * k, -k);
		form4[1].setPoint(-2 * k, -3 * k);
		form4[2].setPoint(0, -3 * k);
		form4[3].setPoint(0, -k);
	}
	else if (number == 11)
	{
		form1[0].setPoint(-k, 0);
		form1[1].setPoint(k, 0);
		form1[2].setPoint(k, 2 * k);
		form1[3].setPoint(-k, 2 * k);
		form2[0].setPoint(-k, 0);
		form2[1].setPoint(k, 0);
		form2[2].setPoint(k, -2 * k);
		form2[3].setPoint(-k, -2 * k);
		form3[0].setPoint(-k, 0);
		form3[1].setPoint(-k, -2 * k);
		form3[2].setPoint(-3 * k, -2 * k);
		form3[3].setPoint(-3 * k, 0);
		form4[0].setPoint(k, 0);
		form4[1].setPoint(k, -2 * k);
		form4[2].setPoint(3 * k, -2 * k);
		form4[3].setPoint(3 * k, 0);
	}
	else if (number == 12)
	{
		form1[0].setPoint(0, k);
		form1[1].setPoint(0, -k);
		form1[2].setPoint(2 * k, -k);
		form1[3].setPoint(2 * k, k);
		form2[0].setPoint(0, 3 * k);
		form2[1].setPoint(-2 * k, 3 * k);
		form2[2].setPoint(-2 * k, k);
		form2[3].setPoint(0, k);
		form3[0].setPoint(-2 * k, k);
		form3[1].setPoint(0, k);
		form3[2].setPoint(0, -k);
		form3[3].setPoint(-2 * k, -k);
		form4[0].setPoint(-2 * k, -k);
		form4[1].setPoint(0, -k);
		form4[2].setPoint(0, -3 * k);
		form4[3].setPoint(-2 * k, -3 * k);
	}
	else if (number == 13)
	{
		form1[0].setPoint(k, 0);
		form1[1].setPoint(-k, 0);
		form1[2].setPoint(-k, -2 * k);
		form1[3].setPoint(k, -2 * k);
		form2[0].setPoint(-3 * k, 0);
		form2[1].setPoint(-3 * k, 2 * k);
		form2[2].setPoint(-k, 2 * k);
		form2[3].setPoint(-k, 0);
		form3[0].setPoint(-k, 2 * k);
		form3[1].setPoint(-k, 0);
		form3[2].setPoint(k, 0);
		form3[3].setPoint(k, 2 * k);
		form4[0].setPoint(k, 0);
		form4[1].setPoint(k, 2 * k);
		form4[2].setPoint(3 * k, 2 * k);
		form4[3].setPoint(3 * k, 0);
	}
	else if (number == 14)
	{
		form1[0].setPoint(-2 * k, k);
		form1[1].setPoint(0, k);
		form1[2].setPoint(0, -k);
		form1[3].setPoint(-2 * k, -k);
		form2[0].setPoint(0, 3 * k);
		form2[1].setPoint(2 * k, 3 * k);
		form2[2].setPoint(2 * k, k);
		form2[3].setPoint(0, k);
		form3[0].setPoint(2 * k, k);
		form3[1].setPoint(0, k);
		form3[2].setPoint(0, -k);
		form3[3].setPoint(2 * k, -k);
		form4[0].setPoint(2 * k, -k);
		form4[1].setPoint(0, -k);
		form4[2].setPoint(0, -3 * k);
		form4[3].setPoint(2 * k, -3 * k);
	}
	else if (number == 15)
	{
		form1[0].setPoint(-2 * k, 2 * k);
		form1[1].setPoint(0, 2 * k);
		form1[2].setPoint(0, 0);
		form1[3].setPoint(-2 * k, 0);
		form2[0].setPoint(2 * k, 2 * k);
		form2[1].setPoint(2 * k, 0);
		form2[2].setPoint(0, 0);
		form2[3].setPoint(0, 2 * k);
		form3[0].setPoint(0, -2 * k);
		form3[1].setPoint(-2 * k, -2 * k);
		form3[2].setPoint(-2 * k, 0);
		form3[3].setPoint(0, 0);
		form4[0].setPoint(2 * k, 0);
		form4[1].setPoint(2 * k, -2 * k);
		form4[2].setPoint(0, -2 * k);
		form4[3].setPoint(0, 0);
	}
	vec->push_back(form1);
	vec->push_back(form2);
	vec->push_back(form3);
	vec->push_back(form4);
	for (int i = 0; i < 4; i++)
		vecNumber->push_back(4);
	return fun(vec, vecNumber, 4, number, p);
}
void MainScene1::addbaseblock(int rotations, int X, int Y, int number)
{
	if (number == 1)
	{
		if (rotations == 0 || rotations == 360 || rotations == 180)
		{
			background[X / 20 - 2][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 2][43 - (Y - 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 2][43 - (Y - 10) / 20 - 1]->setPosition(X - 30, Y);
			backgroundnumber[X / 20 - 2][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 2][43 - (Y - 10) / 20 - 1]);
			//
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20 - 1]);
			//
			background[X / 20][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 1]);
			//
			background[X / 20 + 1][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 + 1][43 - (Y - 10) / 20 - 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 + 1][43 - (Y - 10) / 20 - 1]->setPosition(X + 30, Y), backgroundnumber[X / 20 + 1][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 + 1][43 - (Y - 10) / 20 - 1]);
		}
		else if (rotations == 90 || rotations == 270)
		{
			background[(X - 10) / 20][43 - Y / 20 - 2] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 2]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 2]->setPosition(X, Y + 30), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 2] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 2]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 + 1]->setPosition(X, Y - 30), backgroundnumber[(X - 10) / 20][43 - Y / 20 + 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 + 1]);
		}
	}
	else if (number == 2)
	{
		if (rotations == 0 || rotations == 360 || rotations == 180)
		{
			background[(X - 10) / 20][43 - Y / 20 - 2] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 2]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 2]->setPosition(X, Y + 30), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 2] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 2]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 + 1]->setPosition(X, Y - 30), backgroundnumber[(X - 10) / 20][43 - Y / 20 + 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 + 1]);
		}
		else if (rotations == 90 || rotations == 270)
		{
			background[X / 20 - 2][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 2][43 - (Y - 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 2][43 - (Y - 10) / 20 - 1]->setPosition(X - 30, Y), backgroundnumber[X / 20 - 2][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 2][43 - (Y - 10) / 20 - 1]);
			//
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20 - 1]);
			//
			background[X / 20][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 1]);
			//
			background[X / 20 + 1][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 + 1][43 - (Y - 10) / 20 - 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 + 1][43 - (Y - 10) / 20 - 1]->setPosition(X + 30, Y), backgroundnumber[X / 20 + 1][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 + 1][43 - (Y - 10) / 20 - 1]);
		}
	}
	else if (number == 3)
	{
		if (rotations == 0 || rotations == 360)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 90)
		{
			background[X / 20][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 + 1]);
		}
		else if (rotations == 180)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 270)
		{
			background[X / 20][43 - (Y - 10) / 20 - 2] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 2] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 2]);
			background[X / 20][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 1]);
			background[X / 20][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20]);
			background[X / 20 - 1][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20]);
		}
	}
	else if (number == 4)
	{
		if (rotations == 0 || rotations == 360)
		{
			background[X / 20][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 + 1]);
		}
		else if (rotations == 90)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 180)
		{
			background[X / 20][43 - (Y - 10) / 20 - 2] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 2] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 2]);
			background[X / 20][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 1]);
			background[X / 20][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20]);
			background[X / 20 - 1][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20]);
		}
		else if (rotations == 270)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
	}
	else if (number == 5)
	{
		if (rotations == 0 || rotations == 360)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 90)
		{
			background[X / 20][43 - (Y - 10) / 20 - 2] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 2] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 2]);
			background[X / 20][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 1]);
			background[X / 20][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20]);
			background[X / 20 - 1][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20]);
		}
		else if (rotations == 180)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 270)
		{
			background[X / 20][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 + 1]);
		}
	}
	else if (number == 6)
	{
		if (rotations == 0 || rotations == 360)
		{
			background[X / 20][43 - (Y - 10) / 20 - 2] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 2] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 2]);
			background[X / 20][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 1]);
			background[X / 20][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20]);
			background[X / 20 - 1][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20]);
		}
		else if (rotations == 90)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 180)
		{
			background[X / 20][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 + 1]);
		}
		else if (rotations == 270)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
	}
	else if (number == 7)
	{
		if (rotations == 0 || rotations == 360 || rotations == 180)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
		}
		else if (rotations == 90 || rotations == 270)
		{
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 + 1]);
		}
	}
	else if (number == 8)
	{
		if (rotations == 0 || rotations == 360 || rotations == 180)
		{
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 + 1]);
		}
		else if (rotations == 90 || rotations == 270)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
		}
	}
	else if (number == 9)
	{
		if (number == 0 || rotations == 360 || rotations == 180)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (number == 90 || number == 270)
		{
			background[X / 20 - 1][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20]);
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20 - 1]);
			background[X / 20][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 1]);
			background[X / 20][43 - (Y - 10) / 20 - 2] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 2] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 2]);
		}
	}
	else if (number == 10)
	{
		if (rotations == 0 || rotations == 180 || rotations == 360)
		{
			background[X / 20 - 1][43 - (Y - 10) / 20] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20]);
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y - 10) / 20 - 1]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y - 10) / 20 - 1]);
			background[X / 20][43 - (Y - 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 1]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 1]);
			background[X / 20][43 - (Y - 10) / 20 - 2] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20][43 - (Y - 10) / 20 - 2]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y - 10) / 20 - 2] = 1;
			this->addChild(background[X / 20][43 - (Y - 10) / 20 - 2]);
		}
		else if (rotations == 90 || rotations == 270)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
	}
	else if (number == 11)
	{
		if (rotations == 0 || rotations == 360)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 90)
		{
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 + 1]);
		}
		else if (rotations == 180)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
		}
		else if (rotations == 270)
		{
			background[X / 20][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 - 1]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 + 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
		}
	}
	else if (number == 12)
	{
		if (rotations == 0 || rotations == 360)
		{
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 + 1]);
		}
		else if (rotations == 90)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
		}
		else if (rotations == 180)
		{
			background[X / 20][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 - 1]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 + 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
		}
		else if (rotations == 270)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
	}
	else if (number == 13)
	{
		if (rotations == 0 || rotations == 360)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
		}
		else if (rotations == 90)
		{
			background[X / 20][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 - 1]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 + 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
		}
		else if (rotations == 180)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 270)
		{
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 + 1]);
		}
	}
	else if (number == 14)
	{
		if (rotations == 0 || rotations == 360)
		{
			background[X / 20][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 - 1]->setPosition(X + 10, Y + 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 - 1]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20 + 1]->setPosition(X + 10, Y - 20), backgroundnumber[X / 20][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20 + 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
		}
		else if (rotations == 90)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20]->setPosition(X - 20, Y - 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20]->setPosition(X + 20, Y - 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20]);
		}
		else if (rotations == 180)
		{
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 - 1]->setPosition(X - 10, Y + 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 - 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 - 1]);
			background[X / 20 - 1][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPhysicsBody(w);
			w->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20]->setPosition(X - 10, Y), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20]);
			background[X / 20][43 - (Y + 10) / 20] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[X / 20][43 - (Y + 10) / 20]->setPhysicsBody(e);
			e->setDynamic(false);
			background[X / 20][43 - (Y + 10) / 20]->setPosition(X + 10, Y), backgroundnumber[X / 20][43 - (Y + 10) / 20] = 1;
			this->addChild(background[X / 20][43 - (Y + 10) / 20]);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPhysicsBody(r);
			r->setDynamic(false);
			background[X / 20 - 1][43 - (Y + 10) / 20 + 1]->setPosition(X - 10, Y - 20), backgroundnumber[X / 20 - 1][43 - (Y + 10) / 20 + 1] = 1;
			this->addChild(background[X / 20 - 1][43 - (Y + 10) / 20 + 1]);
		}
		else if (rotations == 270)
		{
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
			q->setDynamic(false);
			background[(X - 10) / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 20, Y + 10), backgroundnumber[(X - 10) / 20 - 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 - 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
			w->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20 - 1]->setPosition(X, Y + 10), backgroundnumber[(X - 10) / 20][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20 - 1]);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1] = Sprite::create("square.png");
			PhysicsBody *e = PhysicsBody::createBox(Size(20, 21));
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPhysicsBody(e);
			e->setDynamic(false);
			background[(X - 10) / 20 + 1][43 - Y / 20 - 1]->setPosition(X + 20, Y + 10), backgroundnumber[(X - 10) / 20 + 1][43 - Y / 20 - 1] = 1;
			this->addChild(background[(X - 10) / 20 + 1][43 - Y / 20 - 1]);
			background[(X - 10) / 20][43 - Y / 20] = Sprite::create("square.png");
			PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
			background[(X - 10) / 20][43 - Y / 20]->setPhysicsBody(r);
			r->setDynamic(false);
			background[(X - 10) / 20][43 - Y / 20]->setPosition(X, Y - 10), backgroundnumber[(X - 10) / 20][43 - Y / 20] = 1;
			this->addChild(background[(X - 10) / 20][43 - Y / 20]);
		}
	}
	else if (number == 15)
	{
		background[X / 20 - 1][43 - Y / 20 - 1] = Sprite::create("square.png");
		PhysicsBody *q = PhysicsBody::createBox(Size(20, 21));
		background[X / 20 - 1][43 - Y / 20 - 1]->setPhysicsBody(q);
		q->setDynamic(false);
		background[X / 20 - 1][43 - Y / 20 - 1]->setPosition(X - 10, Y + 10), backgroundnumber[X / 20 - 1][43 - Y / 20 - 1] = 1;
		this->addChild(background[X / 20 - 1][43 - Y / 20 - 1]);
		background[X / 20][43 - Y / 20 - 1] = Sprite::create("square.png");
		PhysicsBody *w = PhysicsBody::createBox(Size(20, 21));
		background[X / 20][43 - Y / 20 - 1]->setPhysicsBody(w);
		w->setDynamic(false);
		background[X / 20][43 - Y / 20 - 1]->setPosition(X + 10, Y + 10), backgroundnumber[X / 20][43 - Y / 20 - 1] = 1;
		this->addChild(background[X / 20][43 - Y / 20 - 1]);
		background[X / 20][43 - Y / 20] = Sprite::create("square.png");
		PhysicsBody *e = PhysicsBody::createBox(Size(20, 20));
		background[X / 20][43 - Y / 20]->setPhysicsBody(e);
		e->setDynamic(false);
		background[X / 20][43 - Y / 20]->setPosition(X + 10, Y - 10), backgroundnumber[X / 20][43 - Y / 20] = 1;
		this->addChild(background[X / 20][43 - Y / 20]);
		background[X / 20 - 1][43 - Y / 20] = Sprite::create("square.png");
		PhysicsBody *r = PhysicsBody::createBox(Size(20, 20));
		background[X / 20 - 1][43 - Y / 20]->setPhysicsBody(r);
		r->setDynamic(false);
		background[X / 20 - 1][43 - Y / 20]->setPosition(X - 10, Y - 10), backgroundnumber[X / 20 - 1][43 - Y / 20] = 1;
		this->addChild(background[X / 20 - 1][43 - Y / 20]);
	}
}
void MainScene1::clear()
{
	int sum = 0;
	for (int a = 0; a < 2; a++)
	{
		for (int i = 0; i < 30; i++)
			if (backgroundnumber[i][42] == 1)
			{
				sum++;
			}
		if (sum == 30)
		{
			for (int j = 42; j >= 1; j--)
			{
				for (int i = 0; i < 30; i++)
				{
					if (backgroundnumber[i][j] == 1)
					{
						removeChild(background[i][j], true);
					}
					backgroundnumber[i][j] = backgroundnumber[i][j - 1];
					if (backgroundnumber[i][j - 1] == 1)
					{
						background[i][j] = Sprite::create("square.png");
						PhysicsBody *itsbody1 = PhysicsBody::createBox(Size(background[i][j]->getContentSize().width, background[i][j]->getContentSize().height));
						background[i][j]->setPhysicsBody(itsbody1);
						background[i][j]->getPhysicsBody()->setDynamic(false);
						background[i][j]->setPosition((i + 1) * 20 - 10, (42 - j) * 20 + 10);
						this->addChild(background[i][j]);
					}
				}
			}
			sum = 0;
			score = score + 60;
		}
		sum = 0;
	}
	sum = 0;
	for (int a = 0; a < 2; a++)
	{
		for (int i = 0; i < 30; i++)
			if (backgroundnumber[i][41] == 1)
			{
				sum++;
			}
		if (sum == 30)
		{
			for (int j = 41; j >= 1; j--)
			{
				for (int i = 0; i < 30; i++)
				{
					if (backgroundnumber[i][j] == 1)
					{
						removeChild(background[i][j], true);
					}
					backgroundnumber[i][j] = backgroundnumber[i][j - 1];
					if (backgroundnumber[i][j - 1] == 1)
					{
						background[i][j] = Sprite::create("square.png");
						PhysicsBody *itsbody1 = PhysicsBody::createBox(Size(background[i][j]->getContentSize().width, background[i][j]->getContentSize().height));
						background[i][j]->setPhysicsBody(itsbody1);
						background[i][j]->getPhysicsBody()->setDynamic(false);
						background[i][j]->setPosition((i + 1) * 20 - 10, (42 - j) * 20 + 10);
						this->addChild(background[i][j]);
					}
				}
			}
			sum = 0;
			score = score + 60;
		}
		sum = 0;
	}
	sum = 0;
	for (int i = 0; i < 30; i++)
		if (backgroundnumber[i][40] == 1)
		{
			sum++;
		}
	if (sum == 30)
	{
		for (int j = 40; j >= 1; j--)
		{
			for (int i = 0; i < 30; i++)
			{
				if (backgroundnumber[i][j] == 1)
				{
					removeChild(background[i][j], true);
				}
				backgroundnumber[i][j] = backgroundnumber[i][j - 1];
				if (backgroundnumber[i][j - 1] == 1)
				{
					background[i][j] = Sprite::create("square.png");
					PhysicsBody *itsbody1 = PhysicsBody::createBox(Size(background[i][j]->getContentSize().width, background[i][j]->getContentSize().height));
					background[i][j]->setPhysicsBody(itsbody1);
					background[i][j]->getPhysicsBody()->setDynamic(false);
					background[i][j]->setPosition((i + 1) * 20 - 10, (42 - j) * 20 + 10);
					this->addChild(background[i][j]);
				}
			}
		}
		sum = 0;
		score = score + 60;
	}
}
void MainScene1::evaluation()
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 43; j++)
		{
			backgroundnumber[i][j] = 0;
		}
	}
}
void MainScene1::display()
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size visize = Director::getInstance()->getVisibleSize();
	Node *n = this->getChildByTag(score);
	CCString *scores = CCString::createWithFormat("%d", score);

	auto lbscore = Label::createWithTTF(scores->getCString(), "fonts/arial.ttf", 30);
	lbscore->setPosition(Vec2(origin.x + visize.width * 3 / 4,
		origin.y + visize.height / 4-50));
	this->addChild(lbscore, 20, score);
}

void MainScene1::remove1()
{
	this->removeChildByTag(score);
}

void MainScene1::gameover()
{
	for (int a = 0; a < 30; a++)
	{
		if (backgroundnumber[a][2]==1)
	    {
			Vec2 origin = Director::getInstance()->getVisibleOrigin();
			Size visize = Director::getInstance()->getVisibleSize();
			auto gameoverscene = Gameover::createScene();
			Director::getInstance()->replaceScene(gameoverscene);

		}
	}
}

Sprite* MainScene1::nextblock(int x, Point p)
{
	Sprite * nima;
	if (x == 1)
	{
		nima = Sprite::create("1.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 2)
	{
		nima = Sprite::create("2.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 3)
	{
		nima = Sprite::create("3.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 4)
	{
		nima = Sprite::create("4.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 5)
	{
		nima = Sprite::create("5.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 6)
	{
		nima = Sprite::create("6.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 7)
	{
		nima = Sprite::create("7.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 8)
	{
		nima = Sprite::create("8.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 9)
	{
		nima = Sprite::create("9.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 10)
	{
		nima = Sprite::create("10.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 11)
	{
		nima = Sprite::create("11.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 12)
	{
		nima = Sprite::create("12.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 13)
	{
		nima = Sprite::create("13.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else if (x == 14)
	{
		nima = Sprite::create("14.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	else
	{
		nima = Sprite::create("15.png");
		nima->setPosition(p);
		this->addChild(nima);
	}
	return nima;
}
void MainScene1::random()
{
	for (int i = 1; i < 1000; i++)
		rands[i] = rand() % (15) + 1;
}
