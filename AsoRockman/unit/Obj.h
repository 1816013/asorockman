#pragma once
#include <common/VECTOR2.h>
#include <memory>
#include <vector>
#include <map>


class Obj;
using shared_Obj = std::shared_ptr<Obj>;
using VecInt = std::vector<int>;
using AnimVector = std::vector<std::pair<int, int>>;	// 中身は ｱﾆﾒｰｼｮﾝﾌﾚｰﾑと現在描画中のｱﾆﾒｰｼｮﾝｶｳﾝﾀ
 
enum class ANIM_ID
{ 
	STOP,	// 待機
	RUN,	// 移動
	SHOT,	// 弾
	S_SHOT,	// 待機射撃
	R_SHOT,	// 移動射撃
	J_SHOT,	// ｼﾞｬﾝﾌﾟ射撃
	JUMP,	// ｼﾞｬﾝﾌﾟ
	MAX
};

enum class UNIT
{
	PLAYER1,
	PLAYER2,
	SHOT,
	SHOT2,
	MAX
};

enum class DIR
{
	RIGHT,
	LEFT,
	MAX
};

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void Update(void) = 0;
	virtual void Draw(void);
	virtual bool Init(void) = 0;
	virtual UNIT GetUnit(void) = 0;

	void SetDrawPos(Vector2 pos);
	const ANIM_ID animKey(void) const;		// _animKeyの取得
	bool animKey(const ANIM_ID key);		// _animKeyの設定
	bool SetAnim(const ANIM_ID key, AnimVector& data);// ｱﾆﾒｰｼｮﾝの設定
	bool isShotF(void) { return _shotF; };		// 撃っているかいないかを取得する
	bool isDeath(void) { return _death; };		// 死んでいるか死んでいないかを取得する
	void Decreaselife(void) { _life--; };		// 体力を1減少させる
	Vector2 pos(void) { return _pos; };			// 座標を取得
	Vector2 size(void) { return _size; };		// 大きさを取得
	DIR dir(void) { return _dir; };				// 方向を取得
	bool pRunF(void){ return _pRunF; };			// 走っているかいないかを取得
	bool pJumpF(void){ return _pJumpF; };		// ジャンプしているかしていないかを取得

	bool isColF(void) { return _colF; };		// 当たったかを取得
	void SetColF(bool flag) { _colF = flag; };	// 当たったかを設定

private:
	std::map<ANIM_ID, AnimVector>_animMap;
	ANIM_ID _animKey;	// ｱﾆﾒｰｼｮﾝｷｰ（どのｱﾆﾒｰｼｮﾝか）
	int _animCnt;	// ｱﾆﾒｰｼｮﾝｶｳﾝﾀ
	int _animFrame;	// ｱﾆﾒｰｼｮﾝﾌﾚｰﾑ
protected:
	Vector2 _pos;	// ｵﾌﾞｼﾞｪｸﾄの座標 
	Vector2 d_pos;	// _m_pos分描画をずらす為の座標
	Vector2 _size;	// ｵﾌﾞｼﾞｪｸﾄの大きさ
	UNIT _unit;		// 自分自身
	VecInt _mapC;	// ﾏｯﾌﾟ情報
	DIR _dir;		// ｵﾌﾞｼﾞｪｸﾄの向き
	bool _shotF;	// 弾を打ったか打っていないか
	bool _death;	// 死んだか死んでないか
	bool _pRunF;	// ｷｬﾗが走っているかいないか
	bool _pJumpF;	// ｷｬﾗがｼﾞｬﾝﾌﾟ可能か不可能か
	int _life;		// ｷｬﾗの体力
	bool _colF;		// 当たったか
	
};

