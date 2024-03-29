#pragma once
#include <map>
#include "INPUT_ID.h"

using KeyPair = std::pair<int, int>;		// <現在のｷｰの状態, 1ﾌﾚｰﾑ前のｷｰ情報>
using KeyMap = std::map<INPUT_ID, KeyPair>;	// ｷｰのﾘｽﾄ, ｷｰの状態 

class InputState
{
public:
	InputState();
	virtual void Update(void) = 0;
	virtual ~InputState();

	const KeyMap& state(void)const;				// state取得
	const KeyPair state(INPUT_ID id)const;		// KeyPairの中身の取得
	bool state(INPUT_ID id, int input);			// 入力ﾃﾞｰﾀのｾｯﾄ
	void SetOld(void);							// 1ﾌﾚｰﾑ前の入力ﾃﾞｰﾀのｾｯﾄ

private:
	KeyMap _state;

};

