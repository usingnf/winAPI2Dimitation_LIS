#pragma once
class CMonster : public CGameObject
{
private:
	Vec2 mScale = Vec2(50,50);
	double mSpeed = 300;
	Vec2 center = Vec2(WS_WIDTH / 2, WS_HEIGHT / 2);
	bool isUp = true;
	double maxMove = 300;
public:
	CMonster();
	~CMonster();
	void setCenter(Vec2 vec);
	virtual void update();
	virtual void render(HDC& hDC);
};

