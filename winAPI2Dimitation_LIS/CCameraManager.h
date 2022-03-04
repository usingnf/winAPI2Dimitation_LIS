#pragma once
class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	Vec2 pos;
	Vec2 diffPos;
	CGameObject* targetObj;
public:

	void setLookAt(Vec2 vec);
	void setTargetObj(CGameObject* obj);
	
	void calDiff();

	Vec2 getRenderPos(Vec2 vec);

	void update();
};

