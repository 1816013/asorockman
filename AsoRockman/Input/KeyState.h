#pragma once
#include <vector>
#include "InputState.h"
class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();
	void Update(void) override;		// ·°‚ðÊÞ¯Ì§‚É“o˜^
private:
	char _buf[256];					// ·°ÊÞ¯Ì§
	std::vector<int> _key;		// ·°‚Ì”z’u	
};

