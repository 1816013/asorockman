#pragma once
#include <vector>
#include <common/VECTOR2.h>
#include <memory>
#include <tuple>

enum class EF_STATE
{
	POS_X,	// X座標
	POS_Y,	// Y座標
	ANGLE,	// 角度
	SPEED,	// 速度
	MAX
};
class Effect;
using shared_effect = std::shared_ptr<Effect>;
using ef_state = std::tuple<int, int, double, double>;

class Effect
{
public:
	Effect();
	Effect(ef_state);
	~Effect();
	void Update(void);	// ｴﾌｪｸﾄの移動
	void Draw(void);	// 描画
private:
	Vector2_D _pos;		// ｴﾌｪｸﾄの座標
	double _speed;		// ｴﾌｪｸﾄのｽﾋﾟｰﾄﾞ
	double _angle;		// ｴﾌｪｸﾄの飛ぶ角度
	int _id;			// ｴﾌｪｸﾄの画像のID
	int waitC;			// ｴﾌｪｸﾄのｱﾆﾒｰｼｮﾝの待機ｶｳﾝﾀ
};

