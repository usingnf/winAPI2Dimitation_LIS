#pragma once

class CPlayer : public CGameObject
{
private:

public:
	virtual void update();
	virtual void render(HDC& hDC);

};

