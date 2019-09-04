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
	unique_base Update(unique_base own);	// •Ô‚è’l‚Í©•ª©g‚ğ•Ô‚·
	SCN_ID GetScnID(void);					// Œ»İ‚Ì¼°İ‚ÌID‚ğæ“¾‚·‚é
	SCN_ID NextScnID(void)override;			// Ÿ‚Ì¼°İID‚ğæ“¾‚·‚é
	void Draw(void)override;
	int _ghTitleScreen;
private:
	std::unique_ptr<InputState> _key;

};

