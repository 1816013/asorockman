#pragma once

enum class INPUT_ID
{
	LEFT,	// Å©
	RIGHT,	// Å®
	UP,		// Å™
	DOWN,	// Å´
	SHOT,	// Rshift
	A,		// A
	D,		// D
	W,		// W
	S,		// S
	SHIFT,	// LSHIFT
	SPACE,	// SPACE
	MAX
};

INPUT_ID begin(INPUT_ID);	// INPUT_IDÇÃç≈èâÇÃóvëf
INPUT_ID end(INPUT_ID);		// INPUT_IDÇÃç≈å„ÇÃóvëf
INPUT_ID operator*(INPUT_ID key);	
INPUT_ID operator++(INPUT_ID& key);