#include "cocos2d.h"
USING_NS_CC;

class scorebank : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	char highscore[19][5] = { 0 };

	CREATE_FUNC(scorebank);
};