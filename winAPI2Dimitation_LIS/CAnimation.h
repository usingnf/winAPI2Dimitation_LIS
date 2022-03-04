#pragma once

class CAnimator;
class CTexture;

struct tAniFrame
{
	Vec2 leftTop;
	Vec2 slice;
	Vec2 fptOffset;
	float duration;
};

class CAnimation
{
	friend class CAnimator;
private:
	wstring name;
	CAnimator* animator;
	CTexture* texture;
	vector<tAniFrame> vecFrame;
	
	int curFrame;
	double accTime;
	bool isLoop;
public:
	CAnimation();
	~CAnimation();

	void setLoop(bool b);
	bool getLoop();

	void setName(const wstring& name);
	const wstring& getName();

	void SetFrame(int frmIndex);
	tAniFrame& GetFrame(int frmIndex);

	void update();
	void render(HDC& hDC);

	void create(CTexture* tex, Vec2 leftTop, Vec2 slice, Vec2 step, float duration, UINT frameCount);
};

