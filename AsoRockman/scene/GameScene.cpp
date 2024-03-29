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
	_objlist.emplace_back(new Player({ 100, 440 }, { 32, 32 }, _map->GetMapChip(), UNIT::PLAYER1, DIR::RIGHT));
	_objlist.emplace_back(new Player({ 684, 440 }, { 32, 32 }, _map->GetMapChip(), UNIT::PLAYER2, DIR::LEFT));
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
	for (auto itr : _effectList)
	{
		itr->Update();
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

	_p_cnt = std::count_if(_objlist.begin(),
							   _objlist.end(),
							   [](shared_Obj obj) {return ((*obj).GetUnit() == UNIT::PLAYER1 
													   || (*obj).GetUnit() == UNIT::PLAYER2)
													   && (*obj).isAlive() == true; });

	if (_p_cnt < 2)
	{
		_clearwait++;
		for (auto itr : _objlist)
		{
			if ((itr->GetUnit() == UNIT::PLAYER1 || itr->GetUnit() == UNIT::PLAYER2) && itr->isAlive() == false)
			{
				Vector2 pos = itr->pos();
				if (_effectList.size() < 12 * (2 - _p_cnt))
				{
					effectInstance({ pos.x, pos.y , 0 , 1 });
					effectInstance({ pos.x, pos.y , 0, 0.5 });
					effectInstance({ pos.x, pos.y , 90, 1 });
					effectInstance({ pos.x, pos.y , 90, 0.5 });
					effectInstance({ pos.x, pos.y , 180, 1 });
					effectInstance({ pos.x, pos.y , 180, 0.5 });
					effectInstance({ pos.x, pos.y , 270, 1 });
					effectInstance({ pos.x, pos.y , 270, 0.5 });
					effectInstance({ pos.x, pos.y , 45, 1 });
					effectInstance({ pos.x, pos.y , 135, 1 });
					effectInstance({ pos.x, pos.y , 225, 1 });
					effectInstance({ pos.x, pos.y , 315, 1 });
				}
			}
		}
	}
	if (_clearwait > 200)
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
	// ここからｹﾞｰﾑｼｰﾝの描画
	_map->Draw();
	for (auto itr : _effectList)
	{
		itr->Draw();
	}
	for (auto itr : _objlist)
	{
		itr->Obj::Draw();
		itr->Draw();
		if (_p_cnt < 2)
		{
			if (itr->isAlive() == true)
			{
				if (itr->GetUnit() == UNIT::PLAYER1)
				{
					DrawGraph(180, 100, IMAGE_ID("player1_win")[0], true);
				}
				if (itr->GetUnit() == UNIT::PLAYER2)
				{
					DrawGraph(180, 100, IMAGE_ID("player2_win")[0], true);
				}
			}
			if (_p_cnt == 0)
			{
				DrawGraph(292, 100, IMAGE_ID("引き分け")[0], true);
			}
		}
	}
	//DrawString(0, 50, "GAME SCENE", 0xffffff);
	SetDrawScreen(ghbefor);
}

void GameScene::effectInstance(ef_state state)
{
	return _effectList.emplace_back(new Effect(state));
}

