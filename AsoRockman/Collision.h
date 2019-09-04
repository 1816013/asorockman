#pragma once
#include <unit/Obj.h>
#include <common/VECTOR2.h>

class Collision
{
public:
	Collision();
	~Collision();
	bool WallCol(Vector2 n_pos, std::vector<int> m_chip);	// •Ç‚ÆµÌÞ¼Þª¸Ä‚Ì“–‚½‚è”»’è
	bool Judgment(std::vector<shared_Obj>& list);	// ·¬×‚Æ’e‚Ì“–‚½‚è”»’è

};

