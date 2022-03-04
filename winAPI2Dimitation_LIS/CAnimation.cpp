#include "pch.h"
#include "CAnimation.h"

CAnimation::CAnimation()
{
	name = L"Noname";
	animator = nullptr;
	texture = nullptr;
	curFrame = -1;
	accTime = 0;
	isLoop = true;
}

CAnimation::~CAnimation()
{
	
}

void CAnimation::setLoop(bool b)
{
	isLoop = b;
}

bool CAnimation::getLoop()
{
	return isLoop;
}

void CAnimation::setName(const wstring& name)
{
	this->name = name;
}

const wstring& CAnimation::getName()
{
	return name;
}

void CAnimation::update()
{
	accTime += DT();

	if (accTime > vecFrame[curFrame].duration)
	{
		//accTime = 0;
		accTime -= vecFrame[curFrame].duration;
		curFrame++;
		if (curFrame >= vecFrame.size())
		{
			if (isLoop == true)
			{
				curFrame %= vecFrame.size();
			}
			else
			{
				curFrame--;
			}
		}
		
	}
}

void CAnimation::render(HDC& hDC)
{
	CGameObject* obj = animator->getOwner();
	tAniFrame frm = vecFrame[curFrame];
	
	Vec2 pos = obj->getPos() + frm.fptOffset;
	pos = CCameraManager::getInstance()->getRenderPos(pos);

	TransparentBlt(hDC,
		(int)pos.x - frm.slice.x / 2, 
		(int)pos.y - frm.slice.y / 2, 
		(int)frm.slice.x,
		(int)frm.slice.y, 
		texture->getDC(), 
		frm.leftTop.x,
		frm.leftTop.y, 
		frm.slice.x,
		frm.slice.y, 
		RGB(255,0,255));
		
		
}

void CAnimation::create(CTexture* tex, Vec2 leftTop, Vec2 slice, Vec2 step, float duration, UINT frameCount)
{
	this->texture = tex;
	tAniFrame frm = {};
	for (UINT i = 0; i < frameCount; i++)
	{
		frm.duration = duration;
		frm.slice = slice;
		frm.leftTop = leftTop + step * i;
		frm.fptOffset = Vec2(0, 0);

		vecFrame.push_back(frm);
	}
}

void CAnimation::SetFrame(int frmIndex)
{
	curFrame = frmIndex;
}

tAniFrame& CAnimation::GetFrame(int frmIndex)
{
	return vecFrame[frmIndex];
}