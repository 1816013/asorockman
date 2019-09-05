#pragma once
#include "Obj.h"
#include <common/VECTOR2.h>
#include <tuple>
#include "Collision.h"

enum class ShotState
{
	POS,		// ���W
	SIZE,		// �傫��
	DIR,		// ����
	RUN_F,		// �����Ă��邩
	JUMP_F,		// �ެ��߂��Ă��邩
	P_TYPE,		// �ǂ���ڲ԰����������
	M_CHIP		// ϯ�ߏ��
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

