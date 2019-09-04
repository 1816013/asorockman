#pragma once
#include "BaseScene.h"
#include <memory>
#include <Input/InputState.h>
class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_base Update(unique_base own);	// �Ԃ�l�͎������g��Ԃ�
	SCN_ID GetScnID(void);					// ���݂̼�݂�ID���擾����
	SCN_ID NextScnID(void)override;			// ���̼��ID���擾����
	void Draw(void)override;
	int _ghTitleScreen;
private:
	std::unique_ptr<InputState> _key;

};

