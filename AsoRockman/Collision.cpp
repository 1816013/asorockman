#include <algorithm>
#include "Collision.h"

Collision::Collision()
{
}


Collision::~Collision()
{
}

bool Collision::WallCol(Vector2 n_pos, std::vector<int> m_chip)
{
	int index = n_pos.x / 32 + n_pos.y / 32 * 48 ;
	if (m_chip[index] == 8 || m_chip[index] == 10)
	{
		return false;
	}
	return true;
}

bool Collision::Judgment(std::vector<shared_Obj>& list)
{
	bool colF = false;
	std::vector<shared_Obj> tmpList = list;
	for (auto itr : list)
	{
		itr->SetColF(false);
		auto _pos = itr->pos();
		auto _size = itr->size();
		auto _unit = itr->GetUnit();
		for (auto other_itr : list)
		{
			auto unit = other_itr->GetUnit();
			if (_unit != unit && !(_unit == UNIT::PLAYER1 && unit == UNIT::PLAYER2 || _unit == UNIT::PLAYER2 && unit == UNIT::PLAYER1))
			{
				auto pos = other_itr->pos();
				auto size = other_itr->size();
				if (!(_pos.x - _size.x / 2 > pos.x + size.x / 2
					|| _pos.x + _size.x / 2 < pos.x - size.x / 2
					|| _pos.y - _size.y / 2 > pos.y + size.y / 2
					|| _pos.y + _size.y / 2 < pos.y - size.y / 2)
					)
				{
					itr->SetColF(true);
					other_itr->SetColF(true);
					if (_unit == UNIT::SHOT && unit != UNIT::PLAYER1)
					{
						tmpList.erase(std::remove_if(tmpList.begin(),
										tmpList.end(),
							[](shared_Obj obj) { return (*obj).isColF() == false; }),
										tmpList.end());
					}
					if (_unit == UNIT::SHOT2 && unit != UNIT::PLAYER2)
					{
						tmpList.erase(std::remove_if(tmpList.begin(),
							tmpList.end(),
							[](shared_Obj obj) { return (*obj).isColF() == false; }),
							tmpList.end());
						
					}
					colF = true;
				}
			}
		}
	}

	if (colF)
	{
		for (auto itr : tmpList)
		{
			itr->Decreaselife();
		}
	}

	return true;
}
