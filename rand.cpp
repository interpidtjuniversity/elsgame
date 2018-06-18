#include "rand.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "Box2d.h"
#include<iostream>
using namespace std;
float Position1[1000][99999] = { 900 };
float Position2[1000][99999] = { 900 };

Scene* MainScene4::createScene()
{
	auto scene = Scene::createWithPhysics();
	Vect gravity(0, -10.0f);
	scene->getPhysicsWorld()->setGravity(gravity);
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//	scene->getPhysicsWorld()->setAutoStep(false);          //
	//	scene->getPhysicsWorld()->setFixedUpdateRate(500);
	// 'layer' is an autorelease object  
	auto layer = MainScene4::create();
	layer->setPhyWorld(scene->getPhysicsWorld());
	// add layer as a child to scene  
	scene->addChild(layer);
	// return the scene  
	return scene;
}
/*
void MainScene4::onEnter()
{
Layer::onEnter();
auto listener = EventListenerPhysicsContact::create();
listener->onContactBegin = [](PhysicsContact& contact)
{
auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();                //ballBody->setDynamic(false);  ballBodyOne->getShape(0)->setRestitution(1.0f);
auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();

if (spriteA && spriteA->getTag() == 1&& spriteB && spriteB->getTag() == 1)
{
contact.getShapeA()->setRestitution(0);
contact.getShapeB()->setRestitution(0);
contact.getShapeA()->getBody()->setDynamic(false);
contact.getShapeB()->getBody()->setDynamic(false);
spriteA->setColor(Color3B::YELLOW);
spriteB->setColor(Color3B::YELLOW);
spriteA->getPhysicsBody()->setDynamic(false);
spriteB->getPhysicsBody()->setDynamic(false);
}

log("onContactBegin");
return true;
};


listener->onContactPreSolve = [](PhysicsContact& contact,PhysicsContactPreSolve& solve)
{


log("onContactPreSolve");
return true;
};


listener->onContactPostSolve = [](PhysicsContact& contact,const PhysicsContactPostSolve& solve)
{


log("onContactPostSolve");
};
listener->onContactSeparate = [](PhysicsContact& contact)
{
auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();

if (spriteA && spriteA->getTag() == 1&& spriteB && spriteB->getTag() == 1)
{
spriteA->setColor(Color3B::WHITE);
spriteB->setColor(Color3B::WHITE);
}
log("onContactSeperate");
};


Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);


}


void MainScene1::onExit()
{
Layer::onExit();
log("HelloWorld onExit");
Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}
*/


void MainScene4::onKeyPressed(EventKeyboard::KeyCode keycode, Event *event) {
	if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		CCLOG("按下了：上方向键");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		CCLOG("按下了：左方向键");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		CCLOG("按下了：右方向键");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		CCLOG("按下了：下方向键");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_0){
		CCLOG("按下了：数字0键");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_W){
		CCLOG("按下了:字母键W");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_A){
		CCLOG("按下了:字母键A");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_S){
		CCLOG("按下了:字母键S");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_D){
		CCLOG("按下了:字母键D");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_Q){
		CCLOG("按下了:字母键Q");
	}
}
void MainScene4::update(float delta)
{
	Node::update(delta);
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW, rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
	auto upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW, downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
	auto Arrow0 = EventKeyboard::KeyCode::KEY_0;
	//
	auto qArrow = EventKeyboard::KeyCode::KEY_Q;
	auto wArrow = EventKeyboard::KeyCode::KEY_W;
	auto aArrow = EventKeyboard::KeyCode::KEY_A;
	auto sArrow = EventKeyboard::KeyCode::KEY_S;
	auto dArrow = EventKeyboard::KeyCode::KEY_D;
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
	else if (isKeyPressed(Arrow0) && e == 0){
		keyPressedDuration(Arrow0);
		e++;
	}
	//
	else if (isKeyPressed(wArrow) && g == 0) {
		keyPressedDuration(wArrow);
		g++;
	}
	else if (isKeyPressed(aArrow) && h == 0) {
		keyPressedDuration(aArrow);
		h++;
	}
	else if (isKeyPressed(sArrow) && m == 0) {
		keyPressedDuration(sArrow);
		m++;
	}
	else if (isKeyPressed(dArrow) && n == 0) {
		keyPressedDuration(dArrow);
		n++;
	}
	else if (isKeyPressed(qArrow) && k == 0){
		keyPressedDuration(qArrow);
		k++;
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
	else if (isKeyPressed(Arrow0) == 0 && e == 1){
		e--;
	}
	//
	else if (isKeyPressed(wArrow) == 0 && g == 1) {
		g--;
	}
	else if (isKeyPressed(aArrow) == 0 && h == 1) {
		h--;
	}
	else if (isKeyPressed(sArrow) == 0 && m == 1) {
		m--;
	}
	else if (isKeyPressed(dArrow) == 0 && n == 1) {
		n--;
	}
	else if (isKeyPressed(qArrow) == 0 && k == 1){
		k--;
	}
	for (int i = 0; i < 3; ++i)
	{
		getScene()->getPhysicsWorld()->step(1 / 180.0f);                      //
	}
}

bool MainScene4::isKeyPressed(EventKeyboard::KeyCode keyCode) {
	if (keys[keyCode]) {
		return true;
	}
	else {
		return false;
	}
}
void MainScene4::keyPressedDuration(EventKeyboard::KeyCode code)
{
	int offsetX1 = 0, offsetY1 = 0;
	int offsetX2 = 0, offsetY2 = 0;
	Sprite *sss = Sprite::create("square.png");
	switch (code) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		offsetX1 = -sss->getContentSize().width / 2;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		offsetX1 = sss->getContentSize().width / 2;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		offsetY1 = sss->getContentSize().height;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		offsetY1 = -sss->getContentSize().height;
		break;
	case EventKeyboard::KeyCode::KEY_0:
		sprites[i]->runAction(RotateTo::create(0.0f, rads1)), rads1 = rads1 + 90;
		if (rads1 > 360)
			rads1 = 0;
		break;
		//
	case EventKeyboard::KeyCode::KEY_A:
		offsetX2 = -sss->getContentSize().width / 2;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		offsetX2 = sss->getContentSize().width / 2;
		break;
	case EventKeyboard::KeyCode::KEY_W:
		offsetY2 = sss->getContentSize().height;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		offsetY2 = -sss->getContentSize().height;
		break;
	case EventKeyboard::KeyCode::KEY_Q:
		spritess[i1]->runAction(RotateTo::create(0.0f, rads2)), rads2 = rads2 + 90;
		if (rads2 > 360)
			rads2 = 0;
		break;
	default:
		offsetY1 = offsetX1 = 0;
		offsetY2 = offsetX2 = 0;
		break;
	}
	// 0.0s耗时
	auto moveTo1 = MoveTo::create(0.0, Vec2(sprites[i]->getPositionX() + offsetX1, sprites[i]->getPositionY() + offsetY1));
	sprites[i]->runAction(moveTo1);

	auto moveTo2 = MoveTo::create(0.0, Vec2(spritess[i1]->getPositionX() + offsetX2, spritess[i1]->getPositionY() + offsetY2));
	spritess[i1]->runAction(moveTo2);
}

bool MainScene4::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto edgeSp = Sprite::create();
	auto edgeSp1 = Sprite::create();
	auto body1 = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT);
	auto body5 = PhysicsBody::createEdgeBox(Size(1202, 860));
	body1->getShape(0)->setRestitution(0);
	body5->getShape(0)->setRestitution(0);
	Vect force = Vect(0.0f, 0.0f);
	body1->applyImpulse(force);
	body5->applyImpulse(force);
	edgeSp->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	edgeSp1->setPosition(Point(601, 430));
	edgeSp->setPhysicsBody(body1);
	edgeSp1->setPhysicsBody(body5);
	this->addChild(edgeSp); edgeSp->setTag(0);
	this->addChild(edgeSp1); edgeSp->setTag(1);
	//
	//
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
	sprites[i] = addBlock(1, Point(400, 800));
	spritess[i1] = addBlock(1, Point(800, 800));
	this->schedule(schedule_selector(MainScene4::updates));
	this->scheduleUpdate();
	return true;
}
void MainScene4::updates(float dt)
{
	Position1[i][0] = 1000, Position2[i1][0] = 1000;
	sss = Sprite::create("square.png");
	float k = sss->getContentSize().height / 2;
	Position1[i][j + 1] = sprites[i]->getPositionY();
	Position2[i1][j1 + 1] = spritess[i1]->getPositionY();
	//
	//
	j++;
	j1++;
	//
	if (abs(Position1[i][j] - Position1[i][j - 1]) == 0)
	{
		rands[i + 1] = rand() % (15) + 1;
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
		//
		i++;
		if (rands[i] == 1 || rands[i] == 4 || rands[i] == 6 || rands[i] == 8 || rands[i] == 10 || rands[i] == 12 || rands[i] == 14 || rands[i] == 15)
		{
			sprites[i] = addBlock(rands[i], Point(400, 800));
		}
		else
		{
			sprites[i] = addBlock(rands[i], Point(400, 800));
		}
		j = 0;
		rads1 = 0;
	}
	//
	if (abs(Position2[i1][j1] - Position2[i1][j1 - 1]) == 0)
	{
		rands1[i + 1] = rand() % (15) + 1;
		spritess[i1]->getPhysicsBody()->getShape(0)->setFriction(0);
		spritess[i1]->getPhysicsBody()->setDynamic(false);
		//
		// 按照刚体的旋转角度添加新的刚体
		int finalrads = spritess[i1]->getRotation();
		int fx = spritess[i1]->getPositionX();
		int fy = spritess[i1]->getPositionY();
		if (i1 == 0)
		{
			addbaseblock(finalrads, fx, fy, 1);
			score = score + 4;
			removeChild(spritess[i1], true);
		}
		else
		{
			addbaseblock(finalrads, fx, fy, rands1[i1]);
			score = score + 4;
			removeChild(spritess[i1], true);
			clear();
		}
		//
		//
		i1++;
		if (rands1[i1] == 1 || rands1[i1] == 4 || rands1[i1] == 6 || rands1[i1] == 8 || rands1[i1] == 10 || rands1[i1] == 12 || rands1[i1] == 14 || rands1[i1] == 15)
		{
			spritess[i1] = addBlock(rands1[i1], Point(800, 800));
		}
		else
		{
			spritess[i1] = addBlock(rands1[i1], Point(800, 800));
		}
		j1 = 0;
		rads2 = 0;
	}
}
Sprite* MainScene4::fun(vector<Vec2*>*shapeVecs, vector<int>* shapeVecAmount, int shapeAmount, int number, Point p)
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
Sprite* MainScene4::addBlock(int number, Point p)
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
void MainScene4::addbaseblock(int rotations, int X, int Y, int number)
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
void MainScene4::clear()
{
	int sum = 0;
	for (int i = 0; i < 60; i++)
		if (backgroundnumber[i][42] == 1)
		{
		sum++;
		}
	if (sum == 60)
	{
		for (int j = 42; j >= 1; j--)
		{
			for (int i = 0; i < 60; i++)
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
void MainScene4::evaluation()
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 43; j++)
		{
			backgroundnumber[i][j] = 0;
			//	background[i][j] = Sprite::create("square.png");
			//	PhysicsBody *itsbody = PhysicsBody::createBox(Size(background[i][j]->getContentSize().width, background[i][j]->getContentSize().height));
			//	background[i][j]->setPhysicsBody(itsbody);
			//	background[i][j]->getPhysicsBody()->setDynamic(false);
		}
	}
}
