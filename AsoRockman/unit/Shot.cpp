#include "Shot.h"
#include "ImageMng.h"
#include "Collision.h"

Shot::Shot()
{
	
}

Shot::Shot(s_state & state, const VecInt& mapC)
{

	animKey(ANIM_ID::SHOT);
	_pos = std::get<static_cast<int>(ShotState::POS)>(state);
	_size = std::get<static_cast<int>(ShotState::SIZE)>(state);
	_dir = std::get<static_cast<int>(ShotState::DIR)>(state);
	_pRunF = std::get<static_cast<int>(ShotState::RUN_F)>(state);
	_pJumpF = std::get<static_cast<int>(ShotState::JUMP_F)>(state);
	_unit = std::get<static_cast<int>(ShotState::P_TYPE)>(state);
	if (_unit == UNIT::PLAYER1)
	{
		_unit = UNIT::SHOT;
	}
	if (_unit == UNIT::PLAYER2)
	{
		_unit = UNIT::SHOT2;
	}
	_pos = ShotOffset(_pos);
	_mapC = mapC;
	_life = 1;
	Init();
}

Shot::~Shot()
{
}

void Shot::Update(void)
{
	if (_dir == DIR::LEFT)
	{
		_pos.x -= 8;
	}
	else if (_dir == DIR::RIGHT)
	{
		_pos.x += 8;
	}
	if (!_col->WallCol(_pos, _mapC)|| _life <= 0)
	{
		_death = true;
	}
}

void Shot::Draw(void)
{
}

bool Shot::Init(void)
{
	AnimVector data;
	if (_unit == UNIT::SHOT)
	{
		data.emplace_back(IMAGE_ID("’e")[0], 0);
		SetAnim(ANIM_ID::SHOT, data);
	}
	if (_unit == UNIT::SHOT2)
	{
		data.emplace_back(IMAGE_ID("’e2")[0], 0);
		SetAnim(ANIM_ID::SHOT, data);
	}
	return true;
}

UNIT Shot::GetUnit(void)
{
	return _unit;
}

Vector2 Shot::ShotOffset(const Vector2 pos)
{
	Vector2 tmp = pos;
	
	if (_dir == DIR::LEFT)
	{
		tmp.x -= 40;
	}
	else if (_dir == DIR::RIGHT)
	{
		tmp.x += 40;
	}
	if (_pJumpF)
	{
		tmp.y += 7;
	}
	else
	{
		tmp.y -= 8;
	}


	return tmp;
}
