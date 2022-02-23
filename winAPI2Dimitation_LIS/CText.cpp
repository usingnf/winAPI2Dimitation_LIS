#include "pch.h"
#include "CText.h"


CText::CText()
{
	wcscpy_s(mtext, L"123");
}

CText::~CText()
{
}

void CText::update()
{
	
}

void CText::render(HDC& hDC)
{
	TextOutW(hDC, WS_WIDTH / 2, WS_HEIGHT / 2, mtext, sizeof(mtext) / sizeof(WCHAR));
	//TextOut(hDC, 5, 5, szText, lstrlen(szText));
}

void CText::setText(const WCHAR* text)
{
	wcscpy_s(mtext, text);
}
