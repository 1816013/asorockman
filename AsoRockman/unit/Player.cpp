#include "Player.h"
#include <DxLib.h>
#include "ImageMng.h"
#include <Input/KeyState.h>


Player::Player()
{
}

Player::Player(Vector2 pos, Vector2 size, const VecInt mapC, UNIT unit)
{
	animKey(ANIM_ID::STOP);
	_pos = pos;
	_size = size;
	_mapC = mapC;
	_unit = unit;
	_velocity = { 0 , 0 };
	_pJumpF = false;
	_inputState = std::make_unique<KeyState>();
	SetOffset(_pos, _size);
	Init();
	animStopCnt = 0;
	_life = 10;

}

Player::~Player()
{
}

void Player::Update(void)
{
	_inputState->Update();
	P_Move();
	P_Jump();
	P_Shot();
	
	if (_life <= 0)
	{
		_death = true;
	}
}

void Player::Draw(void)
{

	for (int i = 0; i < _life; i++)
	{
		if (_unit == UNIT::PLAYER1)
		{
			DrawGraph(100, 100 - (8 * i), IMAGE_ID("life")[0], false);
		}
		if (_unit == UNIT::PLAYER2)
		{
			DrawGraph(600, 100 - (8 * i), IMAGE_ID("life")[0], false);
		}
	}
	
}

bool Player::Init(void)
{
	
	AnimVector data;
	if (_unit == UNIT::PLAYER1)
	{
		data.emplace_back(IMAGE_ID("stop_player")[0], 0);
		SetAnim(ANIM_ID::STOP, data);

		for (int i = 0; i < 4; i++)
		{
			data.emplace_back(IMAGE_ID("run_player")[i], 10 * (i + 1));
			/*data.emplace_back(IMAGE_ID("run_player")[1], 20);
			data.emplace_back(IMAGE_ID("run_player")[2], 30);
			data.emplace_back(IMAGE_ID("run_player")[3], 40);*/
		}
		SetAnim(ANIM_ID::RUN, data);

		data.emplace_back(IMAGE_ID("jump_player")[0], 0);
		SetAnim(ANIM_ID::JUMP, data);

		data.emplace_back(IMAGE_ID("sShot_player")[0], 0);
		SetAnim(ANIM_ID::S_SHOT, data);

		for (int i = 0; i < 4; i++)
		{
			data.emplace_back(IMAGE_ID("rShot_player")[i], 10 * (i + 1));
			/*data.emplace_back(IMAGE_ID("rShot_player")[1], 20);
			data.emplace_back(IMAGE_ID("rShot_player")[2], 30);
			data.emplace_back(IMAGE_ID("rShot_player")[3], 40);*/
		}
		SetAnim(ANIM_ID::R_SHOT, data);

		data.emplace_back(IMAGE_ID("jShot_player")[0], 0);
		SetAnim(ANIM_ID::J_SHOT, data);
	}
	if (_unit == UNIT::PLAYER2)
	{
		data.emplace_back(IMAGE_ID("stop_player2")[0], 0);
		SetAnim(ANIM_ID::STOP, data);

		for (int i = 0; i < 4; i++)
		{
			data.emplace_back(IMAGE_ID("run_player2")[i], 10 * (i + 1));
			/*data.emplace_back(IMAGE_ID("run_player")[1], 20);
			data.emplace_back(IMAGE_ID("run_player")[2], 30);
			data.emplace_back(IMAGE_ID("run_player")[3], 40);*/
		}
		SetAnim(ANIM_ID::RUN, data);

		data.emplace_back(IMAGE_ID("jump_player2")[0], 0);
		SetAnim(ANIM_ID::JUMP, data);

		data.emplace_back(IMAGE_ID("sShot_player2")[0], 0);
		SetAnim(ANIM_ID::S_SHOT, data);

		for (int i = 0; i < 4; i++)
		{
			data.emplace_back(IMAGE_ID("rShot_player2")[i], 10 * (i + 1));
			/*data.emplace_back(IMAGE_ID("rShot_player")[1], 20);
			data.emplace_back(IMAGE_ID("rShot_player")[2], 30);
			data.emplace_back(IMAGE_ID("rShot_player")[3], 40);*/
		}
		SetAnim(ANIM_ID::R_SHOT, data);

		data.emplace_back(IMAGE_ID("jShot_player2")[0], 0);
		SetAnim(ANIM_ID::J_SHOT, data);
	}
	return true;
}

UNIT Player::GetUnit(void)
{
	return _unit;
}

void Player::SetOffset(Vector2 pos, Vector2 size)
{
	// 左上
	_offsetPos.emplace_back( Vector2(pos.x - size.x / 2, pos.y - size.y / 2 ));
	// 上
	_offsetPos.emplace_back(Vector2(pos.x, pos.y - size.y / 2));
	// 右上
	_offsetPos.emplace_back(Vector2(pos.x + size.x / 2, pos.y - size.y / 2));
	// 左
	_offsetPos.emplace_back(Vector2(pos.x - size.x / 2, pos.y ));
	// 右
	_offsetPos.emplace_back(Vector2(pos.x + size.x / 2, pos.y));
	// 左下
	_offsetPos.emplace_back(Vector2(pos.x - size.x / 2, pos.y + size.y / 2));
	// 下
	_offsetPos.emplace_back(Vector2(pos.x, pos.y + size.y / 2));
	// 右下
	_offsetPos.emplace_back(Vector2(pos.x + size.x / 2, pos.y + size.y / 2));
}

void Player::P_Move(void)
{
	Vector2 next_pos = _pos;

	Vector2 offsetPos = _pos;
	Vector2 offsetPos2 = offsetPos;
	Vector2 offsetPos3 = offsetPos;

	_pJumpF = false;
	_pRunF = false;
	// P1移動処理
	if (_unit == UNIT::PLAYER1)
	{
		if (_inputState->state(INPUT_ID::RIGHT).first && !_inputState->state(INPUT_ID::LEFT).first)
		{
			_velocity.x += 0.2;
			_pRunF = true;
			_dir = DIR::RIGHT;
		}
		if (_inputState->state(INPUT_ID::LEFT).first && !_inputState->state(INPUT_ID::RIGHT).first)
		{
			_pRunF = true;
			_velocity.x -= 0.2;
			_dir = DIR::LEFT;
		}
	}
	// P2移動処理
	if (_unit == UNIT::PLAYER2)
	{
		if (_inputState->state(INPUT_ID::D).first && !_inputState->state(INPUT_ID::A).first)
		{
			_velocity.x += 0.2;
			_pRunF = true;
			_dir = DIR::RIGHT;
		}
		if (_inputState->state(INPUT_ID::A).first && !_inputState->state(INPUT_ID::D).first)
		{
			_pRunF = true;
			_velocity.x -= 0.2;
			_dir = DIR::LEFT;
		}
	}

	// 制限速度
	if (_velocity.x > 6)
	{
		_velocity.x = 6.0f;
	}
	if (_velocity.x < -6)
	{
		_velocity.x = -6.0f;
	}
	// 減速処理
	if (_pRunF && !shotAnim)
	{
		animKey(ANIM_ID::RUN);
	}
	else if (!_pRunF)
	{
		animKey(ANIM_ID::STOP);
		if (_velocity.x > 0)
		{
			_velocity.x -= 0.2;
			if (_velocity.x < 0)
			{
				_velocity.x = 0;
			}
		}
		else
		{
			_velocity.x += 0.2;
			if (_velocity.x > 0)
			{
				_velocity.x = 0;
			}
		}
	}
	// xの変化
	next_pos.x += _velocity.x;
	// -------- 左右 ----------
	offsetPos = next_pos;
	if (_velocity.x < 0)// 左
	{
		offsetPos.x -= _size.x / 2;
	}
	else	// 右	
	{
		offsetPos.x += _size.x / 2;

	}
	// 頭
	offsetPos2 = offsetPos;
	offsetPos2.y -= _size.y / 2;
	// 足
	offsetPos3 = offsetPos;
	offsetPos3.y += _size.y / 2;

	if (_col->WallCol(offsetPos, _mapC) && _col->WallCol(offsetPos2, _mapC) && _col->WallCol(offsetPos3, _mapC))
	{
		_pos = next_pos;
	}
	else
	{
		int indexX = next_pos.x / 32;
		if (_velocity.x < 0)
		{
			indexX++;
			_pos.x = indexX * 32 - _size.x / 2 ;
		}
		else
		{
			_pos.x = indexX * 32 + _size.x / 2;
		}
		_velocity.x = 0;
	}
	next_pos = _pos;

	// ------- 重力 ---------
	_velocity.y += G;
	//yの変化
	next_pos.y += _velocity.y;

	// ------- 足元 ---------
	offsetPos = next_pos;
	offsetPos.y = next_pos.y + _size.y ;
	// 足元左
	offsetPos2 = offsetPos;
	offsetPos2.x = offsetPos.x - _size.x / 2;
	// 足元右
	offsetPos3 = offsetPos;
	offsetPos3.x = offsetPos.x + _size.x / 2 - 1;
	if (_col->WallCol(offsetPos, _mapC) && _col->WallCol(offsetPos2, _mapC) && _col->WallCol(offsetPos3, _mapC))
	{
		_pos = next_pos;
	}
	else
	{
		_pJumpF = true;
		int index = next_pos.y / 32;
		index--;
		_pos.y = index * 32 + _size.y;
		_velocity.y = 0;
	}
	next_pos = _pos;

	// -------- 頭上 ----------
	// 頭上
	offsetPos = next_pos;
	offsetPos.y -= _size.y / 2;
	// 頭上左
	offsetPos2 = offsetPos;
	offsetPos2.x -= _size.x / 2;
	// 頭上右
	offsetPos3 = offsetPos;
	offsetPos3.x += _size.x / 2 - 1;

	if (_col->WallCol(offsetPos, _mapC) && _col->WallCol(offsetPos2, _mapC) && _col->WallCol(offsetPos3, _mapC))
	{
		_pos = next_pos;
	}
	else
	{
		int index = next_pos.y / 32;
		index++;
		_pos.y = index * 32;
		_velocity.y *= -1;
	}
	next_pos = _pos;

	
}

void Player::P_Jump(void)
{
	// ｼﾞｬﾝﾌﾟ
	if (_unit == UNIT::PLAYER1)
	{
		if (_inputState->state(INPUT_ID::UP).first && _pJumpF)
		{
			_velocity.y = -10;
		}
		if (!_pJumpF || _inputState->state(INPUT_ID::UP).first && !shotAnim)
		{
			animKey(ANIM_ID::JUMP);
		}
	}
	if (_unit == UNIT::PLAYER2)
	{
		if (_inputState->state(INPUT_ID::W).first && _pJumpF)
		{
			_velocity.y = -10;
		}
		if (!_pJumpF || _inputState->state(INPUT_ID::W).first && !shotAnim)
		{
			animKey(ANIM_ID::JUMP);
		}
	}
}

void Player::P_Shot(void)
{
	// ｼｮｯﾄ
	if (_unit == UNIT::PLAYER1)
	{
		if (_inputState->state(INPUT_ID::SHOT).first &~_inputState->state(INPUT_ID::SHOT).second)
		{
			if (_pJumpF && !_pRunF)
			{
				animKey(ANIM_ID::S_SHOT);
			}
			animStopCnt = 0;
			_shotF = true;
			shotAnim = true;
		}
		else
		{
			_shotF = false;
		}
	}
	if (_unit == UNIT::PLAYER2)
	{
		if (_inputState->state(INPUT_ID::SHIFT).first &~_inputState->state(INPUT_ID::SHIFT).second)
		{
			if (_pJumpF && !_pRunF)
			{
				animKey(ANIM_ID::S_SHOT);
			}
			animStopCnt = 0;
			_shotF = true;
			shotAnim = true;
		}
		else
		{
			_shotF = false;
		}
	}

	// ｼｮｯﾄのｱﾆﾒｰｼｮﾝ
	if (shotAnim)
	{
		animStopCnt++;
		if (_pJumpF && !_pRunF)
		{
			animKey(ANIM_ID::S_SHOT);
		}
		if (_pRunF)
		{
			animKey(ANIM_ID::R_SHOT);
		}
		if (_unit == UNIT::PLAYER1)
		{
			if (!_pJumpF || _inputState->state(INPUT_ID::UP).first)
			{
				animKey(ANIM_ID::J_SHOT);
			}
		}
		if (_unit == UNIT::PLAYER2)
		{
			if (!_pJumpF || _inputState->state(INPUT_ID::W).first)
			{
				animKey(ANIM_ID::J_SHOT);
			}
		}
		if (animStopCnt > 40)
		{
			shotAnim = false;
		}
	}
}
