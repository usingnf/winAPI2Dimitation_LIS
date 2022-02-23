#pragma once

#include "framework.h"
// 기본 추가 기능
#include <string>
#include <vector>
#include <list>
#include <map>
#include <chrono>

using std::vector;
using std::wstring;

enum class Group_GameObj
{
	Default,
	Missile,
	Monster,
	Player,

	Size,
};

#include "Vec2.h"
#include "logger.h"
#include "CCore.h"
#include "CSingleton.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CGameObject.h"
#include "CSceneManager.h"

#define WS_MYSTYLE WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
#define WS_WIDTH 1280
#define WS_HEIGHT 720
#define WS_STARTX 100
#define WS_STARTY 100

#define DT() CTimeManager::getInstance()->getDeltaTime()
#define KEY(vk_key) CKeyManager::getInstance()->getButtonState(vk_key)

#define PI 3.141592
#define RADIAN (PI/180)

extern HINSTANCE hInst;
extern HWND hWnd;

class CPlayer;
class CPlayer_Right;
class CBall;
extern CPlayer* leftPlayer;
extern CPlayer_Right* rightPlayer;
extern CBall* ball;
//CPlayer* leftPlayer = new CPlayer();
//CPlayer_Right* rightPlayer = nullptr;
//CBall* ball = nullptr;