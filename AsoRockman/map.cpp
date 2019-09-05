#include "map.h"
#include <DxLib.h>
#include "imageMng.h"
#include "main.h"

map::map()
{
	_m_pos = { 0, 0 };
	_mapChip.resize(48 * 15);
	FILE *fp;
	if (fopen_s(&fp, "mapData/stage.bin", "rb") != 0)
	{
		AST();
	}
	else
	{
		fread(_mapChip.data(), _mapChip.size() * sizeof(_mapChip[0]), 1, fp);
		fclose(fp);
	}
}


map::~map()
{
}

void map::Update(void)
{
	/*if (CheckHitKey(KEY_INPUT_W))
	{
		_m_pos.y -= 5;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		_m_pos.x += 5;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		_m_pos.y += 5;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		_m_pos.x -= 5;
	}*/
}

void map::Draw(void)
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 48; x++)
		{
			DrawRotaGraph(x * 32 - _m_pos.x + 16, y * 32 - _m_pos.y + 16,1.0, 0.0, IMAGE_ID("map")[_mapChip[y * 48 + x]], false);
		}
	}
}

VecInt map::GetMapChip(void)
{
	return _mapChip;
}

Vector2 map::GetM_pos(void)
{
	return _m_pos;
}

