#pragma once
#include "pch.h"
#include "CSingleton.h"

class CTimeManager
{
	SINGLETON(CTimeManager);
private:
	CTimeManager();
	~CTimeManager();
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;
	unsigned int m_uiFPS;
	double m_dDT;
public:
	void update();
	void render();
	void init();
	unsigned int getFPS();
	double getDT();
};

