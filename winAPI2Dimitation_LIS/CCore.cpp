#pragma once
#include "pch.h"
#include "CCore.h"
#include "CPlayer.h"


CScene scene;

Vec2 leftp(0, WS_HEIGHT / 2);
Vec2 rightp(WS_WIDTH, WS_HEIGHT / 2);
Vec2 ballp(WS_WIDTH / 2, WS_HEIGHT / 2);
Vec2 angle(0,0);
double _size = 50;

CCore::CCore()
{
	m_hDC = 0;
	m_hMemDC = 0;
	m_hBMP = 0;
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

void CCore::update()
{
	CTimeManager::getInstance()->update();
	CKeyManager::getInstance()->update();
	scene.update();
	//0x0000 : 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
	//0x0001 : 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
	//0x8000 : 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태
	//0x8001 : 이전에 누른 적이 있고 호출 시점에도 눌려있는 상태
	double speed = 300;
	
	if (KEY(VK_UP) == (UINT)KEY_STATE::HOLD)
	{
		if (rightp.y > 0)
			rightp.y += -speed * DT();
	}
	if (KEY(VK_DOWN) == (UINT)KEY_STATE::HOLD)
	{
		if (rightp.y < WS_HEIGHT)
			rightp.y += speed * DT();
	}

	ballp.x += angle.x * speed*2 * DT();
	ballp.y += angle.y * speed*2 * DT();
	
	if (ballp.y > (double)WS_HEIGHT-50 || ballp.y < 0+50)
	{
		angle.y = -angle.y;
	}
	if (distance(leftp, ballp) < _size)
	{
		//충돌
		ballp.x += 30;
		angle.x = -angle.x;
		angle.x += rand() % 10;
		if(rand()%2 == 0)
			angle.y += rand() % 4;
		else
			angle.y += -rand() % 4;
	}
	if (distance(rightp, ballp) < _size)
	{
		ballp.x += -30;
		angle.x = -angle.x;
		angle.x += -rand() % 10;
		if (rand() % 2 == 0)
			angle.y += rand() % 4;
		else
			angle.y += -rand() % 4;
	}
	normalize(angle);

	WCHAR strFPS[7];
	swprintf_s(strFPS, L"%d", CTimeManager::getInstance()->getFPS());
	TextOutW(m_hMemDC, WS_WIDTH - 100, 10, strFPS, 6);
	
}

void CCore::render()
{
	//배경
	Rectangle(m_hMemDC, -1, -1, WS_WIDTH + 1, WS_HEIGHT + 1);
	//scene의 오브젝트 출력
	scene.render(m_hMemDC);

	//오브젝트
	//Rectangle(m_hMemDC, keyPos.x - (_size / 2), keyPos.y - (_size / 2), keyPos.x + (_size / 2), keyPos.y + (_size / 2));
	//Rectangle(m_hMemDC, leftp.x - (_size / 2), leftp.y - (_size / 2), leftp.x + (_size / 2), leftp.y + (_size / 2));
	//Rectangle(m_hMemDC, rightp.x - (_size / 2), rightp.y - (_size / 2), rightp.x + (_size / 2), rightp.y + (_size / 2));
	//Ellipse(m_hMemDC, ballp.x - (_size / 2), ballp.y - (_size / 2), ballp.x + (_size / 2), ballp.y + (_size / 2));
	
	//MemDC로 그린 BMP를 복사하여 윈도우 창으로 옮기기
	BitBlt(m_hDC, 0, 0, WS_WIDTH, WS_HEIGHT, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	CTimeManager::getInstance()->init();
	CKeyManager::getInstance()->init();
	
	srand(time(0));
	angle.x = (double)(rand() % 10) + 3;
	angle.y = (double)(rand() % 10);
	normalize(angle);

	
	CPlayer* leftP = new CPlayer();
	leftP->setPos(Vec2(0, WS_HEIGHT / 2));
	leftP->setScale(50);
	scene.AddObject(leftP, GROUP_GAMEOBJ::NONE);
	CPlayer* rightP = new CPlayer();
	rightP->setPos(Vec2(WS_WIDTH, WS_HEIGHT / 2));
	rightP->setScale(50);
	scene.AddObject(rightP, GROUP_GAMEOBJ::NONE);
	CGameObject* ballP = new CGameObject();
	ballP->setPos(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));
	ballP->setScale(50);
	scene.AddObject(ballP, GROUP_GAMEOBJ::NONE);
	
	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WS_WIDTH, WS_HEIGHT);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}
