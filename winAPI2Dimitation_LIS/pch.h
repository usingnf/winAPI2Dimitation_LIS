#pragma once

#include "framework.h"
// 기본 추가 기능
#include <string>
#include <vector>
#include <list>
#include <map>
#include <chrono>

#include "Vec2.h"
#include "logger.h"
#include "CCore.h"
#include "CSingleton.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CGameObject.h"


#define WS_MYSTYLE WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
#define WS_WIDTH 1280
#define WS_HEIGHT 720
#define WS_STARTX 100
#define WS_STARTY 100

#define DT() CTimeManager::getInstance()->getDeltaTime()
#define KEY(vk_key) CKeyManager::getInstance()->getButtonState(vk_key)


extern HINSTANCE hInst;
extern HWND hWnd;