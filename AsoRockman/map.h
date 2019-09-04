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
	void Update(void);	// 席踢堏摦
	void Draw(void);	// 昤夋
	VecInt GetMapChip(void);	// 席踢怜踢ID傪庢摼
	Vector2 GetM_pos(void);	// _m_pos傪庢摼
	
private:
	VecInt _mapChip;	// 席踢怜踢ID
	Vector2 _m_pos;	// 席踢嵗昗
};

