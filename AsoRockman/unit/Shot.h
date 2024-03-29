#pragma once
#include "Obj.h"
#include <common/VECTOR2.h>
#include <tuple>
#include "Collision.h"

enum class ShotState
{
	POS,		// 座標
	SIZE,		// 大きさ
	DIR,		// 向き
	RUN_F,		// 走っているか
	JUMP_F,		// ｼﾞｬﾝﾌﾟしているか
	P_TYPE,		// どのﾌﾟﾚｲﾔｰが撃ったか
	M_CHIP		// ﾏｯﾌﾟ情報
};

using s_state = std::tuple<Vector2, Vector2, DIR, bool, bool, UNIT>;

class Shot :
	public Obj
{
public:
	Shot();
	Shot(s_state& state, const VecInt& mapC);
	~Shot();
private:
	void Update(void)override;	// 弾の動きなど
	void Draw(void)override;	// 弾固有の描画
	bool Init(void)override;	// 初期化
	UNIT GetUnit(void)override; // ﾕﾆｯﾄのﾀｲﾌﾟ取得
	Vector2 ShotOffset(const Vector2 pos);	// ﾌﾟﾚｲﾔｰの現在の情報によって座標をｵﾌｾｯﾄする
	std::shared_ptr<Collision>_col;

};

