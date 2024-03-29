#pragma once

enum class INPUT_ID
{
	LEFT,	// ©
	RIGHT,	// ¨
	UP,		// ª
	DOWN,	// «
	SHOT,	// Rshift
	A,		// A
	D,		// D
	W,		// W
	S,		// S
	SHIFT,	// LSHIFT
	SPACE,	// SPACE
	MAX
};

INPUT_ID begin(INPUT_ID);	// INPUT_IDÌÅÌvf
INPUT_ID end(INPUT_ID);		// INPUT_IDÌÅãÌvf
INPUT_ID operator*(INPUT_ID key);	
INPUT_ID operator++(INPUT_ID& key);