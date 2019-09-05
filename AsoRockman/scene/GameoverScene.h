#pragma once
#include "BaseScene.h"
#include <Input/InputState.h>
class GameoverScene :
	public BaseScene
{
public:
	GameoverScene();
	~GameoverScene();
	unique_base Update(unique_base own);	// 返り値は自分自身を返す
	SCN_ID GetScnID(void);					// 現在のｼｰﾝのIDを取得する
	void Draw(void)override;
	SCN_ID NextScnID(void)override;			// 次のｼｰﾝIDを取得する
private:
	int waitTime;							// ﾀｲﾄﾙｼｰﾝに移行するﾀｲﾐﾝｸﾞ用ｶｳﾝﾀ
	int _ghGameoverScreen;					// ｹﾞｰﾑｵｰﾊﾞｰ用ｽｸﾘｰﾝ
	std::unique_ptr<InputState> _key;
};

