#pragma once
#include <unit/Obj.h>
#include <common/VECTOR2.h>

class Collision
{
public:
	Collision();
	~Collision();
	bool WallCol(Vector2 n_pos, std::vector<int> m_chip);	// 壁とｵﾌﾞｼﾞｪｸﾄの当たり判定
	bool Judgment(std::vector<shared_Obj>& list);	// ｷｬﾗと弾の当たり判定

};

