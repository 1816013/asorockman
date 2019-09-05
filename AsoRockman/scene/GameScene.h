#pragma once
#include "BaseScene.h"
#include <memory>
#include <vector>
#include <unit/Obj.h>
#include "map.h"
#include <unit/Shot.h>
#include "Collision.h"
#include "Effect.h"



class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_base Update(unique_base own)override;	// •Ô‚è’l‚Í©•ª©g‚ğ•Ô‚·
	SCN_ID GetScnID(void)override;					// Œ»İ‚Ì¼°İ‚ÌID‚ğæ“¾‚·‚é
	SCN_ID NextScnID(void)override;					// Ÿ‚Ì¼°İID‚ğæ“¾‚·‚é
private:
	void Draw(void)override;	// •`‰æ
	void effectInstance(ef_state state);
	int _p_cnt;

	int _ghGameScreen;	// ¹Ş°Ñ’†‚Ì½¸Ø°İ
	std::unique_ptr<map>_map;	
	std::vector<shared_Obj>_objlist;	
	std::vector<s_state>_shotlist;
	std::shared_ptr<Collision>_col;
	std::vector<shared_effect> _effectList;
};

