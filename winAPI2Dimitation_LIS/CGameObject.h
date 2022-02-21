#pragma once

class CCollider;
class CAnimator;
class Texture;

class CGameObject
{
protected:
	Vec2 pos;
	Vec2 angle;
	double scale;
	Texture* texture;
	CCollider* collider;
	CAnimator* animator;

	double speed;
	double hp;
	bool isDead;

public:
	CGameObject();
	~CGameObject();

	virtual void update();
	virtual void render(HDC& hDC);

	void setPos(Vec2 vec);
	void setScale(double scale);

	Vec2 getPos();
	double getScale();
};

