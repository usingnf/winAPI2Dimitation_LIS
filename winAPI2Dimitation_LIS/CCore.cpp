#pragma once
#include "pch.h"
#include "CCore.h"
#include "CPlayer.h"

Vec2 angle(0,0);

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
	CSceneManager::getInstance()->update();
	//0x0000 : 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
	//0x0001 : 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
	//0x8000 : 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태
	//0x8001 : 이전에 누른 적이 있고 호출 시점에도 눌려있는 상태

	//ballp.x += angle.x * speed*2 * DT();
	//ballp.y += angle.y * speed*2 * DT();
	//
	//if (ballp.y > (double)WS_HEIGHT-50 || ballp.y < 0+50)
	//{
	//	angle.y = -angle.y;
	//}
	//if (distance(leftp, ballp) < _size)
	//{
	//	//충돌
	//	ballp.x += 30;
	//	angle.x = -angle.x;
	//	angle.x += rand() % 10;
	//	if(rand()%2 == 0)
	//		angle.y += rand() % 4;
	//	else
	//		angle.y += -rand() % 4;
	//}
	//if (distance(rightp, ballp) < _size)
	//{
	//	ballp.x += -30;
	//	angle.x = -angle.x;
	//	angle.x += -rand() % 10;
	//	if (rand() % 2 == 0)
	//		angle.y += rand() % 4;
	//	else
	//		angle.y += -rand() % 4;
	//}
	//normalize(angle);

	WCHAR strFPS[7];
	swprintf_s(strFPS, L"%d", CTimeManager::getInstance()->getFPS());
	TextOutW(m_hMemDC, WS_WIDTH - 100, 10, strFPS, 6);
	
}

void CCore::render()
{
	//배경
	Rectangle(m_hMemDC, -1, -1, WS_WIDTH + 1, WS_HEIGHT + 1);
	//scene의 오브젝트 출력
	CSceneManager::getInstance()->render(m_hMemDC);

	//MemDC로 그린 BMP를 복사하여 윈도우 창으로 옮기기
	BitBlt(m_hDC, 0, 0, WS_WIDTH, WS_HEIGHT, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	CTimeManager::getInstance()->init();
	CKeyManager::getInstance()->init();
	CSceneManager::getInstance()->init();
	
	/*srand(time(0));
	angle.x = (double)(rand() % 10) + 3;
	angle.y = (double)(rand() % 10);
	normalize(angle);*/
	
	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WS_WIDTH, WS_HEIGHT);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}
