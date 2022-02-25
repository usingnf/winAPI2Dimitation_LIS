#include "pch.h"
#include "CTexture.h"

CTexture::CTexture()
{
	hDC = 0;
	hBitmap = 0;
}

CTexture::~CTexture()
{
	if (hDC != nullptr)
		DeleteDC(hDC);
	if (hBitmap != nullptr)
		DeleteObject(hBitmap);
}

void CTexture::load(const std::wstring& path)
{
	hBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	if (hBitmap == nullptr)
	{
		// faile to load
	}

	hDC = CreateCompatibleDC(CCore::getInstance()->getMainDC());
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hDC, hBitmap);
	GetObject(hBitmap, sizeof(BITMAP), &hBitmapInfo);
}

HDC CTexture::getDC()
{
	return this->hDC;
}

HBITMAP CTexture::getBitmap()
{
	return this->hBitmap;
}

BITMAP CTexture::getBitmapInfo()
{
	return hBitmapInfo;
}

int CTexture::getBitmapWidth()
{
	return hBitmapInfo.bmWidth;
}

int CTexture::getBitmapHeight()
{
	return hBitmapInfo.bmHeight;
}
