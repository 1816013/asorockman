#pragma once
#include "Obj.h"
#include <common/VECTOR2.h>
#include <tuple>
#include "Collision.h"

enum class ShotState
{
	POS,
	SIZE,
	DIR,
	RUN_F,
	JUMP_F,
	P_TYPE,
	M_CHIP
};

using s_state = std::tuple<Vector2, Vector2, DIR, bool, bool, UNIT>;

class Shot :
	public Obj
{
public:
	Shot();
	Shot(s_state& state, const VecInt& mapC);
	~Shot();
private:
	void Update(void)override;	// �e�̓����Ȃ�
	void Draw(void)override;	// �e�ŗL�̕`��
	bool Init(void)override;	// ������
	UNIT GetUnit(void)override; // �ƯĂ����ߎ擾
	Vector2 ShotOffset(const Vector2 pos);	// ��ڲ԰�̌��݂̏��ɂ���č��W��̾�Ă���
	std::shared_ptr<Collision>_col;

};

