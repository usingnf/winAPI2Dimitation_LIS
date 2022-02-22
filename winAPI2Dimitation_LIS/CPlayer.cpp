#include "pch.h"
#include "CPlayer.h"

void CPlayer::update()
{
	if (KEY('W') == (UINT)KEY_STATE::HOLD)
	{
		if (this->pos.y > 0)
			this->pos.y += -100 * DT();
	}
	if (KEY('S') == (UINT)KEY_STATE::HOLD)
	{
		if (this->pos.y < WS_HEIGHT)
			this->pos.y += 100 * DT();
	}
}

void CPlayer::render(HDC& hDC)
{
	Ellipse(hDC,
		pos.x - (scale.x / 2),
		pos.y - (scale.y / 2),
		pos.x + (scale.x / 2),
		pos.y + (scale.y / 2));
}
