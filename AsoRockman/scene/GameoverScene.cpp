#include "GameoverScene.h"
#include <DxLib.h>
#include "ImageMng.h"
#include<Input/KeyState.h>

GameoverScene::GameoverScene()
{
	_key = std::make_unique<KeyState>();
	_scnID = SCN_ID::GAMEOVER;
	waitTime = 0;
}

GameoverScene::~GameoverScene()
{
}

unique_base GameoverScene::Update(unique_base own)
{
	_key->Update();
	waitTime++;
	if (waitTime > 120)
	{
		_scnID = SCN_ID::TITLE;
	}


	Draw();
	
	return own;
}

SCN_ID GameoverScene::GetScnID(void)
{
	return SCN_ID::GAMEOVER;
}

void GameoverScene::Draw(void)
{
	int ghbefor;
	ghbefor = GetDrawScreen();
	SetDrawScreen(_ghGameoverScreen);
	ClsDrawScreen();
	// ‚±‚±‚©‚ç¹Þ°Ñµ°ÊÞ°¼°Ý‚Ì•`‰æ
	DrawString(0, 0, "GAMEOVER SCENE", 0xffffff);
	SetDrawScreen(ghbefor);
}

SCN_ID GameoverScene::NextScnID(void)
{
	return _scnID;
}
