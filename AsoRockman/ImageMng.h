#pragma once
#include <map>
#include <vector>
#include "common/VECTOR2.h"

using VecInt = std::vector<int>;
#define IMAGE_ID(KEY) (ImageMng::GetInstance().GetID(KEY))
#define SET_IMAGE_ID(KEY, F_NAME) (ImageMng::GetInstance().GetID(KEY, F_NAME))
#define SET_IMAGE_DIV_ID(KEY, F_NAME, D_CNT, D_SIZE) (ImageMng::GetInstance().GetID(KEY, F_NAME, D_CNT, D_SIZE))

class ImageMng
{
public:
	static ImageMng& GetInstance()
	{
		if (s_instance == nullptr)
		{
			s_instance = new ImageMng();
		}
		return (*s_instance);
	}
	const VecInt& GetID(const std::string& key);	// key��̧�ق̖��O���ꏏ�̎��g���A�摜��ID��map�ɒǉ�����Ă���Ƃ����͕����������炵�����Ƃ��Ɏg��
	const VecInt& GetID(const std::string& key, const std::string& fileName);	// LoadGraph
	const VecInt& GetID(const std::string& key, const std::string& fileName, const Vector2& divCnt, const Vector2& divSize);	// LoadDivGraph

	~ImageMng();
private:
	ImageMng();
	std::map<std::string, VecInt> imgMap;	// ���� (ID, �ް�)

	static ImageMng* s_instance;
};

