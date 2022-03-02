#include "pch.h"
#include "CResourceManager.h"

CResourceManager::CResourceManager()
{
	textureData = { };
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
}


CTexture* CResourceManager::findTexture(const wstring& name)
{
	return nullptr;
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
