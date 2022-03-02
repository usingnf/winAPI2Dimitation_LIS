#pragma once

class CBall : public CGameObject
{
private:
	Vec2 mScale = Vec2(50, 50);
	double mSpeed = 300;
	double maxSpeed = 1200;
public:
	CBall();
	~CBall();
	virtual void update();
	virtual void render(HDC& hDC);

	virtual void onCollisionEnter(CCollider* other);
};

