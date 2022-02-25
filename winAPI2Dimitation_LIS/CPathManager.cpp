#include "pch.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{
	//szContentPath[0] = L'1';
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

	Logger::debug(szContentPath);
	//C:\Users\chin_\source\repos\winAPI2Dimitation_LIS\winAPI2Dimitation_LIS
}

const WCHAR* CPathManager::getContentPath()
{
	return szContentPath;
}
