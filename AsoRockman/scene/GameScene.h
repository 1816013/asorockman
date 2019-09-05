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
	unique_base Update(unique_base own)override;	// �Ԃ�l�͎������g��Ԃ�
	SCN_ID GetScnID(void)override;					// ���݂̼�݂�ID���擾����
	SCN_ID NextScnID(void)override;					// ���̼��ID���擾����
private:
	void Draw(void)override;	// �`��
	void effectInstance(ef_state state);
	int _p_cnt;

	int _ghGameScreen;	// �ްђ��̽�ذ�
	std::unique_ptr<map>_map;	
	std::vector<shared_Obj>_objlist;	
	std::vector<s_state>_shotlist;
	std::shared_ptr<Collision>_col;
	std::vector<shared_effect> _effectList;
};

