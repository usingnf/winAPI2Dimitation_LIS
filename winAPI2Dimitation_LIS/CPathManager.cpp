#include "pch.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{
	GetCurrentDirectory(MAXSIZE_PATH, szContentPath);
	int size = wcslen(szContentPath);
	for (int i = size - 1; i >= 0; i--)
	{
		if ('\\' == szContentPath[i])
		{
			szContentPath[i] = '\0';
			break;
		}
	}
	wcscat_s(szContentPath, MAXSIZE_PATH, L"\\release");
}

CPathManager::~CPathManager()
{

}

void CPathManager::init()
{

}

const WCHAR* CPathManager::getContentPath()
{
	return szContentPath;
}
