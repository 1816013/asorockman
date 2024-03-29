#include <DxLib.h>
#include "main.h"
#include "InputState.h"

InputState::InputState()
{
	//new = 0;old = 1;
	for (auto id : INPUT_ID())
	{
		_state.try_emplace(id, KeyPair{ 0,1 });
	}
}


InputState::~InputState()
{
}

const KeyMap& InputState::state(void)const
{
	return _state;
}


const KeyPair InputState::state(INPUT_ID id) const
{
	try
	{
		return _state.at(id);
	}
	catch(...)
	{
		AST();
	}
	return { 0,0 };
}

bool InputState::state(INPUT_ID id, int input)
{
	if (_state.find(id) != _state.end())
	{
		_state[id].first = input;
		return true;
	}
	return false;
}

void InputState::SetOld(void)
{
	for (auto id : INPUT_ID())
	{
		try
		{
			_state[id].second = _state[id].first;
		}
		catch (...)
		{
			AST();
			_state.emplace(id, KeyPair{ 0,1 });
		}
	}
}
