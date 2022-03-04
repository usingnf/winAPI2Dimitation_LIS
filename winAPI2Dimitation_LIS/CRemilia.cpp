#include "pch.h"
#include "CRemilia.h"

/*
#include <gdiplus.h>

#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;
ULONG_PTR gdiplusToken;
GdiplusStartupInput gdiplusStartupInput;
*/


CRemilia::CRemilia()
{
	speed = pSpeed;
	scale = pScale;
	name = L"Remilia";

	createCollider();
	getCollider()->setColliderScale(Vec2(50, 50));

	texture = CResourceManager::getInstance()->loadTexture(L"Remilia", L"Remilia.bmp");

	createAnimator();
	getAnimator()->createAnimation(L"stay", texture, Vec2(0,48), Vec2(48,48), Vec2(48,0), 0.08, 4);
	getAnimator()->play(L"stay");

	CAnimation* ani;
	ani = getAnimator()->findAnimation(L"stay");
	ani->setLoop(true);
}

CRemilia* CRemilia::clone()
{
	return new CRemilia(*this);
}

CRemilia::~CRemilia()
{
}

void CRemilia::update()
{
	CAnimator* ani = getAnimator();
	if (ani != nullptr)
		ani->update();
}

void CRemilia::render(HDC& hDC)
{
	/*
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	Graphics g(hDC);
	wstring contentPath = CPathManager::getInstance()->getContentPath();
	contentPath += L"\\content\\texture\\";
	contentPath += L"Remilia.png";
	Image* image = Image::FromFile(contentPath.c_str());
	g.DrawImage(image, WS_WIDTH, WS_HEIGHT);
	*/
	component_render(hDC);
}
