#pragma once
class CMissile : public CGameObject
{
private:
	double mSpeed = 200;
	Vec2 mScale = Vec2(30,30);
public:
	CMissile();
	~CMissile();
	virtual void update();
	virtual void render(HDC& hDC);
};

