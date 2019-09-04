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
	void Update(void);	// ϯ�߈ړ�
	void Draw(void);	// �`��
	VecInt GetMapChip(void);	// ϯ������ID���擾
	Vector2 GetM_pos(void);	// _m_pos���擾
	
private:
	VecInt _mapChip;	// ϯ������ID
	Vector2 _m_pos;	// ϯ�ߍ��W
};

