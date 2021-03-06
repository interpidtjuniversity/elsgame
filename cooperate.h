#ifndef MainScene4_hpp
#define MainScene4_hpp

#include <stdio.h>
#include "cocos2d.h"
#include<vector>
USING_NS_CC;
using namespace cocos2d;
using namespace std;
extern int score1;

class MainScene4 : public cocos2d::Layer
{
public:
	PhysicsWorld* m_world;
	void setPhyWorld(PhysicsWorld* world) { m_world = world; };

	static cocos2d::Scene* createScene();
	virtual bool init();
	//   void add();
	//	virtual void onEnter();
	//	virtual void onExit();

	CREATE_FUNC(MainScene4);
	//键盘监听
	void update(float delta);
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	void keyPressedDuration(EventKeyboard::KeyCode code);
	//
	Sprite*fun(vector<Vec2*>*shapeVecs, vector<int>* shapeVecAmount, int shapeAmount, int number, Point p);
	Sprite*addBlock(int number, Point p);
	//
	void addbaseblock(int rotations, int X, int Y, int number);          //等量代换超级有趣

	//
	Sprite* sp;
	Sprite* sss;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	void updates(float dt);
	Sprite* sprites[1000];
	Sprite* spritess[1000];
	Sprite* next[1000];
	Sprite* next1[1000];
	int i = 0;
	int j = 0;
	int i1 = 0;
	int j1 = 0;
	int area = 0;
	int shapeAmount = 4;
	int rads1 = 90;
	int rads2 = 90;
	int rands[1000];
	int rands1[1000];
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int g = 0, h = 0, m = 0, n = 0, k = 0;
	//
	void evaluation();
	Sprite* background[60][43];
	int backgroundnumber[60][43];;//判断bool值
	void clear();
	void display();
	void remove1();
	void gameover();

	Sprite* nextblock(int x, Point p);
	void random();
	void random1();
	//给随机数组赋值
	//判断shijian
};


#endif // __HELLOWORLD_SCENE_H__  
