#pragma once
#include "Obj.h"
#include <Input/InputState.h>
#include <memory>
#include "Collision.h"

//enum class OFFSET
//{
//	LEFT_UP,
//	UP,
//	RIGHT_UP,
//	LEFT_MIDDLE,
//	RIGHT_MIDDLE,
//	LEFT_DOWN,
//	DOWN,
//	RIGHT_DOWN
//};


class Player :
	public Obj
{
public:
	Player();
	Player(Vector2 pos, Vector2 size, const VecInt mapC, UNIT unit, DIR dir);
	~Player();

private:
	void Update(void)override;	// 関数の統括
	void Draw(void)override;	// 描画
	bool Init(void)override;	// 初期化関数(主に画像設定)
	UNIT GetUnit(void)override;		// ﾕﾆｯﾄのﾀｲﾌﾟ取得
	// void SetOffset(Vector2 pos, Vector2 size);	// ｵﾌｾｯﾄ座標の取得
	void P_Input(void);		// ﾌﾟﾚｲﾔｰの移動ｷｰ入力
	void P_Move(void);		// ﾌﾟﾚｲﾔｰの動作(後で分割予定)
	void P_Jump(void);		// ﾌﾟﾚｲﾔｰのｼﾞｬﾝﾌﾟ
	void P_Shot(void);		// ﾌﾟﾚｲﾔｰのｼｮｯﾄ

	//----- 変数 ------
	Vector2_D _velocity;	// ﾌﾟﾚｲﾔｰの加速度

	
	float G = 0.5f;		// 重力
	bool shotAnim;		// 射撃のｱﾆﾒｰｼｮﾝがonかoffか
	int animStopCnt;	// 射撃ｱﾆﾒｰｼｮﾝ停止用ｶｳﾝﾀ
	int DamStopCnt;		// ﾀﾞﾒｰｼﾞｱﾆﾒｰｼｮﾝ停止用ｶｳﾝﾀ

	std::unique_ptr<InputState> _inputState;	// ｷｰ入力用
	//std::vector<Vector2> _offsetPos;	// ｵﾌｾｯﾄ用の座標
	std::shared_ptr<Collision>_col;
};

