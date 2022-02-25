#pragma once
#include "CSingleton.h"
#include "CTimeManager.h"

class CCore
{
	SINGLETON(CCore);
private:
	HDC m_hDC;
	HDC m_hMemDC;
	HBITMAP m_hBMP;
public:
	void update();
	void render();
	void init();
	HDC getMainDC();
};

