#pragma once
#include <memory>

enum class SCN_ID
{
	TITLE,
	GAME,
	GAMEOVER,
	MAX
};

class BaseScene;
using unique_base = std::unique_ptr<BaseScene>;


class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual unique_base Update(unique_base own) = 0;	// �Ԃ�l�͎������g��Ԃ�
	virtual SCN_ID GetScnID(void) = 0;					// ���݂̼�݂�ID���擾����
	virtual SCN_ID NextScnID(void) = 0;					// ���̼�݂�ID���擾����
	virtual void Draw(void) = 0;						// �`��
	SCN_ID _scnID;										// ���̼�݊i�[�p
};

