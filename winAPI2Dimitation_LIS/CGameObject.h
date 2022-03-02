#pragma once

class CCollider;
class CAnimator;
class CTexture;

class CGameObject
{
protected:
	CGameObject* parent;
	Vec2 pos;
	double angle;
	Vec2 scale;
	Vec2 velocity;
	double gravity;
	double drag;

	CTexture* texture;
	CCollider* collider;
	CAnimator* animator;


	double speed;
	double hp;
	bool isDead;

public:
	CGameObject();
	virtual ~CGameObject();

	virtual void update();
	virtual void finalupdate() final; // 오버라이딩 금지
	virtual void render(HDC& hDC);
	virtual void component_render(HDC& hDC);
	
	void setPos(Vec2 vec);
	Vec2 getPos();
	
	void setScale(Vec2 scale);
	Vec2 getScale();

	virtual void setAngle(double ang);
	virtual void setAngle(Vec2 vec);
	virtual double getAngle();

	void createCollider();
	CCollider* getCollider();

	void addForce(Vec2 vec);
};

