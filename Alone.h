#ifndef MainScene1_hpp
#define MainScene1_hpp

#include <stdio.h>
#include "cocos2d.h"
#include<vector>
USING_NS_CC;
using namespace cocos2d;
using namespace std;
extern int score;

class MainScene1 : public cocos2d::Layer
{
public:
	PhysicsWorld* m_world;
	void setPhyWorld(PhysicsWorld* world) { m_world = world; };

	static cocos2d::Scene* createScene1();
	static cocos2d::Scene* createScene2();
	static cocos2d::Scene* createScene3();
	virtual bool init();
	//   void add();
	//	virtual void onEnter();
	//	virtual void onExit();

	CREATE_FUNC(MainScene1);
	//���̼���
	void update(float delta);
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	void keyPressedDuration(EventKeyboard::KeyCode code);
	//
	Sprite*fun(vector<Vec2*>*shapeVecs, vector<int>* shapeVecAmount, int shapeAmount, int number, Point p);
	Sprite*addBlock(int number, Point p);
	//
	void addbaseblock(int rotations, int X, int Y, int number);          //��������������Ȥ

	//
	Sprite* sp;
	//Sprite *sp1;
	Sprite* sss;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	void updates(float dt);
	Sprite* sprites[1000];
	Sprite* next[1000];
	int i = 0;
	int j = 0;
	int area = 0;
	int shapeAmount = 4;
	int rads = 90;
	int rands[1000];
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	//
	void evaluation();
	Sprite* background[60][43];
	int backgroundnumber[60][43];;//�ж�boolֵ
	void clear();//���һ��
	void display();
	void remove1();
	void gameover();

	Sprite* nextblock(int x, Point p);
	void random();//��������鸳ֵ

	//�ж�shijian
};


#endif // __HELLOWORLD_SCENE_H__  