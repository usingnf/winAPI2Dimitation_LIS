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
	//0x0000 : ������ ���� ���� ���� ȣ�� �������� �������� ���� ����
	//0x0001 : ������ ���� ���� �ְ� ȣ�� �������� �������� ���� ����
	//0x8000 : ������ ���� ���� ���� ȣ�� �������� �����ִ� ����
	//0x8001 : ������ ���� ���� �ְ� ȣ�� �������� �����ִ� ����

	//ballp.x += angle.x * speed*2 * DT();
	//ballp.y += angle.y * speed*2 * DT();
	//
	//if (ballp.y > (double)WS_HEIGHT-50 || ballp.y < 0+50)
	//{
	//	angle.y = -angle.y;
	//}
	//if (distance(leftp, ballp) < _size)
	//{
	//	//�浹
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
	//���
	Rectangle(m_hMemDC, -1, -1, WS_WIDTH + 1, WS_HEIGHT + 1);
	//scene�� ������Ʈ ���
	CSceneManager::getInstance()->render(m_hMemDC);

	//MemDC�� �׸� BMP�� �����Ͽ� ������ â���� �ű��
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
	
	// ���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WS_WIDTH, WS_HEIGHT);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}
