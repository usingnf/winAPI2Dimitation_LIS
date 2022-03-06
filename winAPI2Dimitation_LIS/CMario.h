#pragma once
class CMario : public CGameObject
{
private:
	Vec2 pScale = Vec2(36, 64);
	double pSpeed = 300;
	int wallCount = 0;
	bool isJump = false;
	double maxJump = 0;
	double jumpPower = 0;
	double jumpHeight = 0;
	double lrWall = 0;
public:
	CMario();
	virtual CMario* clone();
	~CMario();
	virtual void update();
	virtual void render(HDC& hDC);
	void CreateMissile();

	void onCollisionEnter(CCollider* other);
	void onCollisionStay(CCollider* other);
	void onCollisionExit(CCollider* other);
};

