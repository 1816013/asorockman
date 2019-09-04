#include <DxLib.h>
#include "ImageMng.h"
#include "main.h"

ImageMng *ImageMng::s_instance = nullptr;

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}
const VecInt& ImageMng::GetID(const std::string& key)
{
	return GetID(key, key);
}

const VecInt& ImageMng::GetID(const std::string& key, const std::string& fileName)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(1);
		imgMap[key]/* Å©map*/[0]/*Å©vector*/ = LoadGraph(fileName.c_str());
		if (imgMap[key][0] == -1)
		{
			AST();
		}
	}
	return imgMap[key];
}

const VecInt& ImageMng::GetID(const std::string& key, const std::string& fileName, const Vector2& divCnt, const Vector2& divSize)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(divCnt.x * divCnt.y);
		if ((LoadDivGraph(fileName.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &imgMap[key][0], false)) == -1)
		{
			AST()
		};
	}
	return imgMap[key];
}