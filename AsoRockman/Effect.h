#pragma once
#include <vector>
#include <common/VECTOR2.h>
#include <memory>
#include <tuple>

enum class EF_STATE
{
	POS_X,	// X���W
	POS_Y,	// Y���W
	ANGLE,	// �p�x
	SPEED,	// ���x
	MAX
};
class Effect;
using shared_effect = std::shared_ptr<Effect>;
using ef_state = std::tuple<int, int, double, double>;

class Effect
{
public:
	Effect();
	Effect(ef_state);
	~Effect();
	void Update(void);	// �̪�Ă̈ړ�
	void Draw(void);	// �`��
private:
	Vector2_D _pos;		// �̪�Ă̍��W
	double _speed;		// �̪�Ă̽�߰��
	double _angle;		// �̪�Ă̔�Ԋp�x
	int _id;			// �̪�Ẳ摜��ID
	int waitC;			// �̪�Ă̱�Ұ��݂̑ҋ@����
};

