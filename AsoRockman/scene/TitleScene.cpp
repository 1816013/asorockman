#include "TitleScene.h"
#include <DxLib.h>
#include <Input/KeyState.h>
#include "ImageMng.h"


TitleScene::TitleScene()
{
	_key = std::make_unique<KeyState>();
	_scnID = SCN_ID::TITLE;
}

TitleScene::~TitleScene()
{
}

unique_base TitleScene::Update(unique_base own)
{
	_key->Update();
	if (_key->state(INPUT_ID::SPACE).first &~_key->state(INPUT_ID::SPACE).second)
	{
		_scnID = SCN_ID::GAME;
	}
	Draw();
	return own;
}

SCN_ID TitleScene::GetScnID(void)
{
	return SCN_ID::TITLE;
}

SCN_ID TitleScene::NextScnID(void)
{
	return _scnID;
}

void TitleScene::Draw(void)
{
	int ghbefor;
	ghbefor = GetDrawScreen();
	SetDrawScreen(_ghTitleScreen);
	ClsDrawScreen();
	// ‚±‚±‚©‚çÀ²ÄÙ¼°Ý‚Ì•`‰æ
	DrawGraph(0, 0, IMAGE_ID("title")[0], false);
	DrawString(0, 0, "TITLE SCENE", 0xffffff);
	DrawGraph(220, 400, IMAGE_ID("Ã·½Ä")[0], true);
	SetDrawScreen(ghbefor);
}
