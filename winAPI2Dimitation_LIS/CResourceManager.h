#pragma once
#include "CTexture.h"
#include "CSound.h"

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	map<wstring, CTexture*> textureData;
	map<wstring, CSound*> soundData;

public:
	//void init();
	CTexture* findTexture(const wstring& name);
	CTexture* loadTexture(const wstring& name, const wstring& path);
	
	CSound* findSound(const wstring& name);
	CSound* loadBGM(const wstring& name, const wstring& path);
	CSound* loadSound(const wstring& name, const wstring& path);
};

