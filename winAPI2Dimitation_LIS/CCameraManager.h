#pragma once
class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	Vec2 pos;
	Vec2 destPos;
	Vec2 diffPos;
	CGameObject* targetObj;

	double time;
	double speed;
	double maxSpeed;
public:

	void setLookAt(Vec2 vec);
	void setTargetObj(CGameObject* obj);
	
	void calDiff();

	Vec2 getPos();
	Vec2 getCurPos();
	Vec2 getRenderPos(Vec2 vec);
	Vec2 getRealPos(Vec2 vec);

	void update();

	void timeMove(Vec2 dest, double t);
	void move(Vec2 vec);
};

