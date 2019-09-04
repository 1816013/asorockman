#include <DxLib.h>
#include "KeyState.h"

KeyState::KeyState()
{
	// ÃÞÌ«ÙÄ
	_key.reserve(static_cast<size_t>(end(INPUT_ID())));
	// emplace_back
	_key.emplace_back(KEY_INPUT_LEFT);
	_key.emplace_back(KEY_INPUT_RIGHT);
	_key.emplace_back(KEY_INPUT_UP);
	_key.emplace_back(KEY_INPUT_DOWN);	
	_key.emplace_back(KEY_INPUT_RSHIFT);
	_key.emplace_back(KEY_INPUT_A);
	_key.emplace_back(KEY_INPUT_D);
	_key.emplace_back(KEY_INPUT_W);
	_key.emplace_back(KEY_INPUT_S);
	_key.emplace_back(KEY_INPUT_LSHIFT);
	_key.emplace_back(KEY_INPUT_SPACE);
}

KeyState::~KeyState()
{
}

void KeyState::Update(void)
{
	SetOld();
	GetHitKeyStateAll(_buf);
	for (auto id : INPUT_ID())
	{
		state(id, _buf[_key[static_cast<int>(id)]]);
	}
}


