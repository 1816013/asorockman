#pragma once

enum class INPUT_ID
{
	LEFT,	// ��
	RIGHT,	// ��
	UP,		// ��
	DOWN,	// ��
	SHOT,	// Rshift
	A,		// A
	D,		// D
	W,		// W
	S,		// S
	SHIFT,	// LSHIFT
	SPACE,	// SPACE
	MAX
};

INPUT_ID begin(INPUT_ID);	// INPUT_ID�̍ŏ��̗v�f
INPUT_ID end(INPUT_ID);		// INPUT_ID�̍Ō�̗v�f
INPUT_ID operator*(INPUT_ID key);	
INPUT_ID operator++(INPUT_ID& key);