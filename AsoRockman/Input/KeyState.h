#pragma once
#include <vector>
#include "InputState.h"
class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();
	void Update(void) override;		// �����ޯ̧�ɓo�^
private:
	char _buf[256];					// ���ޯ̧
	std::vector<int> _key;		// ���̔z�u	
};

