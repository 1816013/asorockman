#pragma once
#include "Obj.h"
#include <common/VECTOR2.h>
#include <tuple>
#include "Collision.h"

enum class ShotState
{
	POS,
	SIZE,
	DIR,
	RUN_F,
	JUMP_F,
	P_TYPE,
	M_CHIP
};

using s_state = std::tuple<Vector2, Vector2, DIR, bool, bool, UNIT>;

class Shot :
	public Obj
{
public:
	Shot();
	Shot(s_state& state, const VecInt& mapC);
	~Shot();
private:
	void Update(void)override;	// ’e‚Ì“®‚«‚È‚Ç
	void Draw(void)override;	// ’eŒÅ—L‚Ì•`‰æ
	bool Init(void)override;	// ‰Šú‰»
	UNIT GetUnit(void)override; // ÕÆ¯Ä‚ÌÀ²Ìßæ“¾
	Vector2 ShotOffset(const Vector2 pos);	// ÌßÚ²Ô°‚ÌŒ»İ‚Ìî•ñ‚É‚æ‚Á‚ÄÀ•W‚ğµÌ¾¯Ä‚·‚é
	std::shared_ptr<Collision>_col;

};

