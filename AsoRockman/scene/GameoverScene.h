#pragma once
#include "BaseScene.h"
#include <Input/InputState.h>
class GameoverScene :
	public BaseScene
{
public:
	GameoverScene();
	~GameoverScene();
	unique_base Update(unique_base own);	// �Ԃ�l�͎������g��Ԃ�
	SCN_ID GetScnID(void);					// ���݂̼�݂�ID���擾����
	void Draw(void)override;
	SCN_ID NextScnID(void)override;			// ���̼��ID���擾����
private:
	int waitTime;
	int _ghGameoverScreen;
	std::unique_ptr<InputState> _key;
};

