#include <DxLib.h>
#include "Obj.h"
#include "ImageMng.h"
#include "main.h"

Obj::Obj()
{
	_dir = DIR::RIGHT;
	_death = false;
	_alive = true;
}

Obj::~Obj()
{
}

void Obj::Draw(void)
{
	if (_animMap.find(_animKey) == _animMap.end())
	{
		return;
	}
	if (_animMap[_animKey].size() <= _animFrame)
	{
		return;
	}
	if (!_alive)
	{
		return;
	}
	if (_animMap[_animKey][_animFrame].second <= _animCnt)
	{
		if (_animMap[_animKey][_animFrame].first != -1)
		{
			_animFrame++;
		}
		if (_animMap[_animKey].size() <= _animFrame)
		{
			_animFrame = 0;
			_animCnt = 0;
		}
	}
	if (_dir == DIR::RIGHT)
	{
		if ((DrawRotaGraph(_pos.x - d_pos.x, _pos.y - d_pos.y, 1.0f, 0.0f, _animMap[_animKey][_animFrame].first, true)) == -1)
		{
			AST();
		};
	}
	else if(_dir == DIR::LEFT)
	{
		DrawRotaGraph(_pos.x - d_pos.x, _pos.y - d_pos.y, 1.0f, 0.0f, _animMap[_animKey][_animFrame].first, true, true);
	}
	
	//_dbgDrawBox(_pos.x, _pos.y, _pos.x + _size.x, _pos.y + _size.y, 0x00ff00, true);
	_animCnt++;
}

void Obj::SetDrawPos(Vector2 pos)
{
	d_pos = pos;
}

const ANIM_ID Obj::animKey(void)const
{
	return _animKey;
}

bool Obj::animKey(const ANIM_ID key)
{
	if ((key < ANIM_ID::STOP) || (key > ANIM_ID::MAX))
	{
		return false;
	}
	if (_animKey != key)
	{
		_animCnt = 0;
		_animFrame = 0;
	}
	_animKey = key;
	return true;
}

bool Obj::SetAnim(const ANIM_ID key, AnimVector& data)
{
	return _animMap.try_emplace(key, std::move(data)).second;
}
