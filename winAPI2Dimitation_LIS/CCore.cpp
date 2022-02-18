#pragma once
#include "pch.h"
#include "Vec2.h"
#include "CCore.h"

Vec2 leftp(0, WS_HEIGHT / 2);
Vec2 rightp(WS_WIDTH, WS_HEIGHT / 2);
Vec2 ballp(WS_WIDTH / 2, WS_HEIGHT / 2);
Vec2 angle(0,0);
float size = 50;

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
	//0x0000 : 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
	//0x0001 : 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
	//0x8000 : 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태
	//0x8001 : 이전에 누른 적이 있고 호출 시점에도 눌려있는 상태
	float speed = 300;
	if (GetAsyncKeyState('W') & 0x8000)
	{
		if(leftp.y > 0)
			leftp.y += -speed * CTimeManager::getInstance()->getDT();
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		if (leftp.y < WS_HEIGHT)
			leftp.y += speed * CTimeManager::getInstance()->getDT();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (rightp.y > 0)
			rightp.y += -speed * CTimeManager::getInstance()->getDT();
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{

	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (rightp.y < WS_HEIGHT)
			rightp.y += speed * CTimeManager::getInstance()->getDT();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{

	}
	ballp.x += angle.x * speed*2 * CTimeManager::getInstance()->getDT();
	ballp.y += angle.y * speed*2 * CTimeManager::getInstance()->getDT();
	
	if (ballp.y > WS_HEIGHT-50 || ballp.y < 0+50)
	{
		angle.y = -angle.y;
	}
	if (vdistance(leftp, ballp) < size)
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
	if (vdistance(rightp, ballp) < size)
	{
		ballp.x += -30;
		angle.x = -angle.x;
		angle.x += -rand() % 10;
		if (rand() % 2 == 0)
			angle.y += rand() % 4;
		else
			angle.y += -rand() % 4;
	}
	vnormalize(angle);

	WCHAR strFPS[7];
	swprintf_s(strFPS, L"%d", CTimeManager::getInstance()->getFPS());
	TextOutW(m_hDC, WS_WIDTH - 100, 10, strFPS, 6);
	
}

void CCore::render()
{
	//배경
	Rectangle(m_hMemDC, -1, -1, WS_WIDTH + 1, WS_HEIGHT + 1);
	//오브젝트
	
	//Rectangle(m_hMemDC, keyPos.x - (size / 2), keyPos.y - (size / 2), keyPos.x + (size / 2), keyPos.y + (size / 2));
	Rectangle(m_hMemDC, leftp.x - (size / 2), leftp.y - (size / 2), leftp.x + (size / 2), leftp.y + (size / 2));
	Rectangle(m_hMemDC, rightp.x - (size / 2), rightp.y - (size / 2), rightp.x + (size / 2), rightp.y + (size / 2));
	Ellipse(m_hMemDC, ballp.x - (size / 2), ballp.y - (size / 2), ballp.x + (size / 2), ballp.y + (size / 2));
	
	//MemDC로 그린 BMP를 복사하여 윈도우 창으로 옮기기
	BitBlt(m_hDC, 0, 0, WS_WIDTH, WS_HEIGHT, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	CTimeManager::getInstance()->init();
	srand(time(0));
	angle.x = rand() % 10 + 3;
	angle.y = rand() % 10;
	vnormalize(angle);
	
	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WS_WIDTH, WS_HEIGHT);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}
