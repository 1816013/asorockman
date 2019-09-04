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
	virtual unique_base Update(unique_base own) = 0;	// •Ô‚è’l‚Í©•ª©g‚ğ•Ô‚·
	virtual SCN_ID GetScnID(void) = 0;					// Œ»İ‚Ì¼°İ‚ÌID‚ğæ“¾‚·‚é
	virtual SCN_ID NextScnID(void) = 0;					// Ÿ‚Ì¼°İ‚ÌID‚ğæ“¾‚·‚é
	virtual void Draw(void) = 0;						// •`‰æ
	SCN_ID _scnID;										// Ÿ‚Ì¼°İŠi”[—p
};

