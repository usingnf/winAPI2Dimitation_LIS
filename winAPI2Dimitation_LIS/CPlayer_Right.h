#pragma once

class CPlayer_Right : public CGameObject
{
private:
	Vec2 pScale = Vec2(50, 50);
	double pSpeed = 300;
public:
	CPlayer_Right();
	virtual CPlayer_Right* clone();
	~CPlayer_Right();
	virtual void update();
	virtual void render(HDC& hDC);
	void CreateMissile();
};