#pragma once

class CCollider;
class CAnimator;
class Texture;

class CGameObject
{
protected:
	CGameObject* parent;
	Vec2 pos;
	double angle;
	Vec2 scale;
	Texture* texture;
	CCollider* collider;
	CAnimator* animator;

	double speed;
	double hp;
	bool isDead;

public:
	CGameObject();
	virtual ~CGameObject();

	virtual void update();
	virtual void render(HDC& hDC);

	void setPos(Vec2 vec);
	void setScale(Vec2 scale);

	Vec2 getPos();
	Vec2 getScale();
};

