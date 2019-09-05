#include "SceneMng.h"
#include <DxLib.h>
#include <scene/GameScene.h>
#include <scene/TitleScene.h>
#include <scene/GameoverScene.h>
#include <common/VECTOR2.h>
#include "ImageMng.h"

std::unique_ptr<SceneMng, SceneMng::SceneDeleter>SceneMng::s_instance(new SceneMng);

void SceneMng::Run()
{
	SysInit();

	SET_IMAGE_ID("title", "image/title.png");
	SET_IMAGE_DIV_ID("map", "image/bg.png", Vector2(13, 1), Vector2(32, 32));
	SET_IMAGE_ID("stop_player", "image/stop.png");
	SET_IMAGE_ID("stop_player2", "image/stop2.png");
	SET_IMAGE_DIV_ID("run_player", "image/run.png", Vector2(4, 1), Vector2(96, 64));
	SET_IMAGE_DIV_ID("run_player2", "image/run2.png", Vector2(4, 1), Vector2(96, 64));
	SET_IMAGE_ID("jump_player", "image/jump.png");
	SET_IMAGE_ID("jump_player2", "image/jump2.png");
	SET_IMAGE_ID("sShot_player", "image/stop_shot.png");
	SET_IMAGE_ID("sShot_player2", "image/stop_shot2.png");
	SET_IMAGE_DIV_ID("rShot_player", "image/run_shot.png", Vector2(4, 1), Vector2(96, 64));
	SET_IMAGE_DIV_ID("rShot_player2", "image/run_shot2.png", Vector2(4, 1), Vector2(96, 64));
	SET_IMAGE_ID("jShot_player", "image/jump_shot.png");
	SET_IMAGE_ID("jShot_player2", "image/jump_shot2.png");
	SET_IMAGE_ID("damage_player", "image/damage.png");
	SET_IMAGE_ID("damage_player2", "image/damage2.png");

	SET_IMAGE_ID("player1_win", "image/player1win.png");
	SET_IMAGE_ID("player2_win", "image/player2win.png");
	SET_IMAGE_ID("à¯Ç´ï™ÇØ", "image/Draw.png");

	SET_IMAGE_DIV_ID("effect", "image/tobichiri2.png", Vector2(6, 1), Vector2(16, 16));

	SET_IMAGE_ID("íe", "image/shot1.png");
	SET_IMAGE_ID("íe2", "image/shot2.png");
	SET_IMAGE_ID("life", "image/life2.png");

	SET_IMAGE_ID("πﬁ∞—µ∞ ﬁ∞", "image/gameover.png");
	SET_IMAGE_ID("√∑Ωƒ", "image/hitstartkey.png");
	

	_activeScene = std::make_unique<TitleScene>();
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		auto nextScnID = _activeScene->NextScnID();
		auto nowScnID = _activeScene->GetScnID();
		if (nowScnID != nextScnID)
		{
			if (nextScnID == SCN_ID::GAME)
			{
				_activeScene = std::make_unique<GameScene>();
			}
			if (nextScnID == SCN_ID::GAMEOVER)
			{
				_activeScene = std::make_unique<GameoverScene>();
			}
			if (nextScnID == SCN_ID::TITLE)
			{
				_activeScene = std::make_unique<TitleScene>();
			}
		}
		ClsDrawScreen();
		_activeScene = _activeScene->Update(std::move(_activeScene));
		ScreenFlip();
	}
}

SceneMng::SceneMng()
{
}

SceneMng::~SceneMng()
{
}

bool SceneMng::SysInit()
{
	// ÉVÉXÉeÉÄèàóù
	SetWindowText("AsoRockMan");
	// ºΩ√—èàóù
	SetGraphMode(768, 480, 16);	// 768Å~480ƒﬁØƒ65536êF”∞ƒﬁÇ…ê›íË
	ChangeWindowMode(true);							// true:windowÅ@false:ÃŸΩ∏ÿ∞›
	if (DxLib_Init() == -1)return false;				// DX◊≤Ãﬁ◊ÿèâä˙âªèàóù
	SetDrawScreen(DX_SCREEN_BACK);					// Ç–Ç∆Ç‹Ç∏ ﬁØ∏ ﬁØÃßÇ…ï`âÊ
	return true;
}