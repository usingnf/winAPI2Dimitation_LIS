#pragma once
#include "pch.h"

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

	for (int i = 0; i < (UINT)Group_Pen::Size; i++)
	{
		if(m_arrPen != 0)
			DeleteObject(m_arrPen[i]);
	}
}

void CCore::update()
{
	CEventManager::getInstance()->update();
	CTimeManager::getInstance()->update();
	CKeyManager::getInstance()->update();
	CSceneManager::getInstance()->update();
	CCollisionManager::getInstance()->update();
}

void CCore::render()
{
	//배경
	Rectangle(m_hMemDC, -1, -1, WS_WIDTH + 1, WS_HEIGHT + 1);
	//scene의 오브젝트 출력
	CSceneManager::getInstance()->render(m_hMemDC);

	//frame 출력
	WCHAR strFPS[7];
	swprintf_s(strFPS, L"%d", CTimeManager::getInstance()->getFPS());
	TextOutW(m_hMemDC, WS_WIDTH - 100, 10, strFPS, 6);

	//MemDC로 그린 BMP를 복사하여 윈도우 창으로 옮기기
	BitBlt(m_hDC, 0, 0, WS_WIDTH, WS_HEIGHT, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	CPathManager::getInstance()->init();
	//CResourceManager::getInstance()->init();
	CTimeManager::getInstance()->init();
	CKeyManager::getInstance()->init();
	CSceneManager::getInstance()->init();
	CCollisionManager::getInstance()->init();
	
	srand(time(0));

	
	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WS_WIDTH, WS_HEIGHT);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	createBrushPen();
}

HDC CCore::getMainDC()
{
	return m_hDC;
}

void CCore::createBrushPen()
{
	m_arrBrush[(UINT)Group_Brush::Hollow] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	m_arrPen[(UINT)Group_Pen::Red] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)Group_Pen::Blue] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	m_arrPen[(UINT)Group_Pen::Green] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)Group_Pen::White] = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	m_arrPen[(UINT)Group_Pen::Black] = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
}

HPEN CCore::getPen(Group_Pen pen)
{
	return m_arrPen[(UINT)pen];
}

HBRUSH CCore::getBrush(Group_Brush brush)
{
	return m_arrBrush[(UINT)brush];
}
