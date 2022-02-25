#pragma once
#include "CTexture.h"

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	std::map<std::wstring, CTexture*> textureData;
public:
	void init();
	CTexture* findTexture(const wstring& name);
	CTexture* loadTexture(const wstring& name, const wstring& path);
	
};

