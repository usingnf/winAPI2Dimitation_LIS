#pragma once
class CText : public CGameObject
{
private:
	WCHAR mtext[11] = L"";
public:
	CText();
	~CText();
	virtual void update();
	virtual void render(HDC& hDC);
	void setText(const WCHAR* text);
};

