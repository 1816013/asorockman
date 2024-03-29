#pragma once
#include "BaseScene.h"
#include <memory>
#include <Input/InputState.h>
class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_base Update(unique_base own);	// 返り値は自分自身を返す
	SCN_ID GetScnID(void);					// 現在のｼｰﾝのIDを取得する
	SCN_ID NextScnID(void)override;			// 次のｼｰﾝIDを取得する
	void Draw(void)override;				// 描画
	int _ghTitleScreen;						// ﾀｲﾄﾙｼｰﾝ用ｽｸﾘｰﾝ
private:
	std::unique_ptr<InputState> _key;

};

