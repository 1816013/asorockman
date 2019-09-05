#pragma once
#include <vector>
#include <common/VECTOR2.h>
#include <memory>
#include <tuple>

enum class EF_STATE
{
	POS_X,
	POS_Y,
	ANGLE,
	SPEED,
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
	void Update(void);
	void Draw(void);
private:
	Vector2_D _pos;
	double _speed;
	double _angle;
	int _id;
	int waitC;
};

