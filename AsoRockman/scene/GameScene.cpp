#include "GameScene.h"
#include <DxLib.h>
#include <tuple>
#include <algorithm>
#include "ImageMng.h"
#include "main.h"
#include <unit/Player.h>



GameScene::GameScene()
{
	_scnID = SCN_ID::GAME;
	_map = std::make_unique<map>();
	_col = std::make_shared<Collision>();
	_objlist.emplace_back(new Player({ 100, 50 }, { 32, 32 }, _map->GetMapChip(), UNIT::PLAYER1));
	_objlist.emplace_back(new Player({ 200, 50 }, { 32, 32 }, _map->GetMapChip(), UNIT::PLAYER2));
}

GameScene::~GameScene()
{
}

unique_base GameScene::Update(unique_base own)
{
	_map->Update();
	_col->Judgment(_objlist);
	for (auto itr : _objlist)
	{
		itr->Update();
		itr->SetDrawPos(_map->GetM_pos());
		if (itr->isShotF())
		{
			_shotlist.emplace_back(itr->pos(), Vector2(16, 16), itr->dir(),itr->pRunF(), itr->pJumpF(), itr->GetUnit());
		}
	}
	if (_shotlist.size() > 0)
	{
		for (auto itr : _shotlist)
		{
			_objlist.emplace_back(new Shot(itr, _map->GetMapChip()));
		}
		_shotlist.erase(_shotlist.begin(), _shotlist.end());
	}

	_objlist.erase(std::remove_if(_objlist.begin(),
								  _objlist.end(),
								  [](shared_Obj obj) { return (*obj).isDeath(); }),
								  _objlist.end());
	auto p_cnt = std::count_if(_objlist.begin(),
							   _objlist.end(),
							   [](shared_Obj obj) {return (*obj).GetUnit() == UNIT::PLAYER1 
													   || (*obj).GetUnit() == UNIT::PLAYER2; });
	if (p_cnt < 2)
	{
		_scnID = SCN_ID::GAMEOVER;
	}
	Draw();
	return own;
}

SCN_ID GameScene::GetScnID(void)
{
	return SCN_ID::GAME;
}

SCN_ID GameScene::NextScnID(void)
{
	return _scnID;
}

void GameScene::Draw(void)
{
	int ghbefor;
	ghbefor = GetDrawScreen();
	SetDrawScreen(_ghGameScreen);
	ClsDrawScreen();
	// ‚±‚±‚©‚ç¹Þ°Ñ¼°Ý‚Ì•`‰æ
	_map->Draw();
	for (auto itr : _objlist)
	{
		itr->Obj::Draw();
		itr->Draw();
	}
	DrawString(0, 50, "GAME SCENE", 0xffffff);
	SetDrawScreen(ghbefor);
}
