#include "pch.h"
#include "CResourceManager.h"

CResourceManager::CResourceManager()
{
	textureData = { };
	soundData = {};
}

CResourceManager::~CResourceManager()
{
	for (map<wstring, CTexture*>::iterator iter = textureData.begin(); iter != textureData.end(); ++iter)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	textureData.clear();
	
	for (map<wstring, CSound*>::iterator iter = soundData.begin(); iter != soundData.end(); ++iter)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	soundData.clear();
	
}


CTexture* CResourceManager::findTexture(const wstring& name)
{
	map<wstring, CTexture*>::iterator iter = textureData.find(name);
	if (iter == textureData.end())
		return nullptr;
	return iter->second;
}


CTexture* CResourceManager::loadTexture(const wstring& name, const wstring& path)
{
	CTexture* texture = findTexture(name);
	if (texture != nullptr)
		return texture;

	
	wstring contentPath = CPathManager::getInstance()->getContentPath();
	contentPath += L"\\content\\texture\\";
	contentPath += path;

	texture = new CTexture();
	texture->load(contentPath);
	texture->setName(name);
	texture->setPath(path);


	textureData.insert(std::make_pair(name, texture));

	return texture;
}

CSound* CResourceManager::findSound(const wstring& name)
{
	map<wstring, CSound*>::iterator iter = soundData.find(name);
	if (iter == soundData.end())
		return nullptr;
	return iter->second;
}

CSound* CResourceManager::loadBGM(const wstring& name, const wstring& path)
{
	CSound* sound = findSound(name);
	if (sound != nullptr)
		return sound;

	wstring contentPath = CPathManager::getInstance()->getContentPath();
	contentPath += L"\\content\\sound\\";
	contentPath += path;

	sound = new CSound();
	sound->load(contentPath, true);
	sound->setName(name);
	sound->setPath(path);


	soundData.insert(std::make_pair(name, sound));

	return sound;
}

CSound* CResourceManager::loadSound(const wstring& name, const wstring& path)
{
	CSound* sound = findSound(name);
	if (sound != nullptr)
		return sound;

	wstring contentPath = CPathManager::getInstance()->getContentRelativePath();
	contentPath += L"\\sound\\";
	contentPath += path;

	sound = new CSound();
	sound->load(contentPath, false);
	sound->setName(name);
	sound->setPath(path);


	soundData.insert(std::make_pair(name, sound));

	return sound;
}
