#pragma once

#include "framework.h"
// 기본 추가 기능
#include <string>
#include <vector>
#include <list>
#include <map>
#include <chrono>

#include "CCore.h"
#include "CSingleton.h"
#include "CTimeManager.h"
#include "Vec2.h"
#include "logger.h"
#include "CScene.h"
#include "CGameObject.h"
#include "CKeyManager.h"

#define WS_MYSTYLE WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
#define WS_WIDTH 1280
#define WS_HEIGHT 720
#define WS_STARTX 100
#define WS_STARTY 100

using std::vector;
using std::string;
using std::wstring;

#define DT() CTimeManager::getInstance()->getDeltaTime()
#define KEY(vk_key) CKeyManager::getInstance()->getButtonState(vk_key)


extern HINSTANCE hInst;
extern HWND hWnd;