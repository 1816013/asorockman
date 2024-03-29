#pragma once
#include <vector>
#include <memory>
#include <common/VECTOR2.h>

using VecInt = std::vector<int>;

class map
{
public:
	map();
	~map();
	void Update(void);	// ﾏｯﾌﾟ移動
	void Draw(void);	// 描画
	VecInt GetMapChip(void);	// ﾏｯﾌﾟﾁｯﾌﾟIDを取得
	Vector2 GetM_pos(void);	// _m_posを取得
	
private:
	VecInt _mapChip;	// ﾏｯﾌﾟﾁｯﾌﾟID
	Vector2 _m_pos;	// ﾏｯﾌﾟ座標
};

