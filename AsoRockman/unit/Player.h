#pragma once
#include "Obj.h"
#include <Input/InputState.h>
#include <memory>
#include "Collision.h"

//enum class OFFSET
//{
//	LEFT_UP,
//	UP,
//	RIGHT_UP,
//	LEFT_MIDDLE,
//	RIGHT_MIDDLE,
//	LEFT_DOWN,
//	DOWN,
//	RIGHT_DOWN
//};


class Player :
	public Obj
{
public:
	Player();
	Player(Vector2 pos, Vector2 size, const VecInt mapC, UNIT unit, DIR dir);
	~Player();

private:
	void Update(void)override;	// �֐��̓���
	void Draw(void)override;	// �`��
	bool Init(void)override;	// �������֐�(��ɉ摜�ݒ�)
	UNIT GetUnit(void)override;		// �ƯĂ����ߎ擾
	// void SetOffset(Vector2 pos, Vector2 size);	// �̾�č��W�̎擾
	void P_Input(void);		// ��ڲ԰�̈ړ�������
	void P_Move(void);		// ��ڲ԰�̓���(��ŕ����\��)
	void P_Jump(void);		// ��ڲ԰�̼ެ���
	void P_Shot(void);		// ��ڲ԰�̼���

	//----- �ϐ� ------
	Vector2_D _velocity;	// ��ڲ԰�̉����x

	
	float G = 0.5f;		// �d��
	bool shotAnim;		// �ˌ��̱�Ұ��݂�on��off��
	int animStopCnt;	// �ˌ���Ұ��ݒ�~�p����
	int DamStopCnt;		// ��Ұ�ޱ�Ұ��ݒ�~�p����

	std::unique_ptr<InputState> _inputState;	// �����͗p
	//std::vector<Vector2> _offsetPos;	// �̾�ėp�̍��W
	std::shared_ptr<Collision>_col;
};

