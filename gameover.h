#include "cocos2d.h"
USING_NS_CC;

class Gameover : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void restart(cocos2d::Ref *pSender);

	CREATE_FUNC(Gameover);
private:
	CCLabelTTF* pLabel;
};