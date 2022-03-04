#pragma once
#include "CAnimation.h"
//class CAnimation;

class CAnimator
{
	friend class CGameObject;
private:
	CGameObject* owner;
	map<wstring, CAnimation*> m_mapAni;
	CAnimation* curAnimation;
public:
	CAnimator();
	~CAnimator();

	void update();
	void render(HDC hDC);

	CGameObject* getOwner();

	void createAnimation(const wstring& name, CTexture* tex, Vec2 leftTop, Vec2 slice, Vec2 step, float duration, UINT frameCount);
	CAnimation* findAnimation(const wstring& name);
	void selectAnimator();
	void play(const wstring& name);
};

