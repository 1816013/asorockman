#pragma once
#include "BaseScene.h"
#include <memory>
#include <vector>
#include <unit/Obj.h>
#include "map.h"
#include <unit/Shot.h>
#include "Collision.h"
class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_base Update(unique_base own)override;	// 返り値は自分自身を返す
	SCN_ID GetScnID(void)override;					// 現在のｼｰﾝのIDを取得する
	SCN_ID NextScnID(void)override;					// 次のｼｰﾝIDを取得する
private:
	void Draw(void)override;	// 描画
	int _ghGameScreen;	// ｹﾞｰﾑ中のｽｸﾘｰﾝ
	std::unique_ptr<map>_map;	
	std::vector<shared_Obj>_objlist;	
	std::vector<s_state>_shotlist;
	std::shared_ptr<Collision>_col;
};

