#pragma once
#include "BaseScene.h"
#include <Input/InputState.h>
class GameoverScene :
	public BaseScene
{
public:
	GameoverScene();
	~GameoverScene();
	unique_base Update(unique_base own);	// •Ô‚è’l‚Í©•ª©g‚ğ•Ô‚·
	SCN_ID GetScnID(void);					// Œ»İ‚Ì¼°İ‚ÌID‚ğæ“¾‚·‚é
	void Draw(void)override;
	SCN_ID NextScnID(void)override;			// Ÿ‚Ì¼°İID‚ğæ“¾‚·‚é
private:
	int waitTime;
	int _ghGameoverScreen;
	std::unique_ptr<InputState> _key;
};

