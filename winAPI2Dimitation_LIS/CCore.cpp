#pragma once
#include "pch.h"

CCore::CCore()
{
	m_hDC = 0;
	m_MemTexture = nullptr;
	//m_hMemDC = 0;
	//m_hBMP = 0;
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	//DeleteObject(m_hMemDC);
	//DeleteObject(m_hBMP);

	for (int i = 0; i < (UINT)Group_Pen::Size; i++)
	{
		if(m_arrPen != 0)
			DeleteObject(m_arrPen[i]);
	}
}

void CCore::update()
{
	CTimeManager::getInstance()->update();
	CKeyManager::getInstance()->update();
	CSceneManager::getInstance()->update();
	CCollisionManager::getInstance()->update();
	CCameraManager::getInstance()->update();
	CSoundManager::getInstance()->update();
	CUIManager::getInstance()->update();
	CEventManager::getInstance()->update();
}

void CCore::render()
{
	//���
	CRenderManager::getInstance()->GetRenderTarget()->BeginDraw();

	CRenderManager::getInstance()->RenderFillRectangle(-1, -1, WS_WIDTH + 1, WS_HEIGHT + 1, RGB(255, 255, 255));

	CSceneManager::getInstance()->render(m_hDC);

	//���
	//Rectangle(m_MemTexture->getDC(), -1, -1, WS_WIDTH + 1, WS_HEIGHT + 1);
	//Rectangle(m_hMemDC, -1, -1, WS_WIDTH + 1, WS_HEIGHT + 1);
	
	//scene�� ������Ʈ ���
	//CSceneManager::getInstance()->render(m_hMemDC);
	//CSceneManager::getInstance()->render(m_MemTexture->getDC());
	//CCameraManager::getInstance()->render(m_MemTexture->getDC());

	//frame ���
	//WCHAR strFPS[7];
	//swprintf_s(strFPS, L"%d", CTimeManager::getInstance()->getFPS());
	//CRenderManager::getInstance()->RenderText(strFPS, WS_WIDTH - 50, 10, WS_HEIGHT, 50, 12, RGB(0, 0, 0));
	//TextOutW(m_MemTexture->getDC(), WS_WIDTH - 100, 10, strFPS, 6);

	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInstance()->getFPS());
	CRenderManager::getInstance()->RenderText(strFPS, WS_WIDTH - 50, 10, WS_HEIGHT, 50, 12, RGB(0, 0, 0));

	CRenderManager::getInstance()->GetRenderTarget()->EndDraw();

	//MemDC�� �׸� BMP�� �����Ͽ� ������ â���� �ű��
	//BitBlt(m_hDC, 0, 0, WS_WIDTH, WS_HEIGHT, m_MemTexture->getDC(), 0, 0, SRCCOPY);
}

void CCore::init()
{
	m_hDC = GetDC(hWnd);

	CPathManager::getInstance()->init();
	CSoundManager::getInstance()->init();
	//CResourceManager::getInstance()->init();
	CTimeManager::getInstance()->init();
	CKeyManager::getInstance()->init();
	CSceneManager::getInstance()->init();
	CCameraManager::getInstance()->init();
	CCollisionManager::getInstance()->init();
	CRenderManager::getInstance()->init();
	
	srand(time(0));

	// ���� ���۸��� �޸� DC�� ��Ʈ�� ����
	
	//m_hMemDC = CreateCompatibleDC(m_hDC);
	//m_hBMP = CreateCompatibleBitmap(m_hDC, WS_WIDTH, WS_HEIGHT);
	//HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	//DeleteObject(hOldBitmap);

	createBrushPen();

	// ���� ���۸� �뵵�� �ؽ��� ������ ����
	m_MemTexture = CResourceManager::getInstance()->createTexture(L"BackBuffer", WS_WIDTH, WS_HEIGHT);
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
