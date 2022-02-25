#pragma once
#include "CResource.h"
class CTexture : public CResource
{
private:
	HDC hDC;
	HBITMAP hBitmap;
	BITMAP hBitmapInfo;

public:
	CTexture();
	virtual ~CTexture();

	void load(const wstring& path);
	HDC getDC();
	HBITMAP getBitmap();
	BITMAP getBitmapInfo();
	int getBitmapWidth();
	int getBitmapHeight();
};

