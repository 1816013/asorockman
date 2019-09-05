#include "Effect.h"
#include <DxLib.h>
#include "ImageMng.h"
#include <cmath>


Effect::Effect()
{
}

Effect::Effect(ef_state state)
{
	_pos.x = std::get<static_cast<int>(EF_STATE::POS_X)>(state);
	_pos.y = std::get<static_cast<int>(EF_STATE::POS_Y)>(state);
	_angle = std::get<static_cast<int>(EF_STATE::ANGLE)>(state) - 90;
	_speed = std::get<static_cast<int>(EF_STATE::SPEED)>(state);
	_id = 0;
}



Effect::~Effect()
{
}

void Effect::Update(void)
{
	_pos.x += cos(_angle * DX_PI / 180) * _speed * 2;
	_pos.y += sin(_angle * DX_PI / 180) * _speed * 2;

	_id++;
	if (_id / 3 > 5)
	{
		_id = 0;
	}
}

void Effect::Draw(void)
{
	DrawRotaGraph(_pos.x, _pos.y,2.5, 0.0, IMAGE_ID("effect")[_id / 3], true);
	
}
