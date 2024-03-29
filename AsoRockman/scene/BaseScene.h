#pragma once
#include <memory>

enum class SCN_ID
{
	TITLE,
	GAME,
	GAMEOVER,
	MAX
};

class BaseScene;
using unique_base = std::unique_ptr<BaseScene>;


class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual unique_base Update(unique_base own) = 0;	// 返り値は自分自身を返す
	virtual SCN_ID GetScnID(void) = 0;					// 現在のｼｰﾝのIDを取得する
	virtual SCN_ID NextScnID(void) = 0;					// 次のｼｰﾝのIDを取得する
	virtual void Draw(void) = 0;						// 描画
	SCN_ID _scnID;										// 次のｼｰﾝ格納用
};

