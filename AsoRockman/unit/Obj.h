#pragma once
#include <common/VECTOR2.h>
#include <memory>
#include <vector>
#include <map>


class Obj;
using shared_Obj = std::shared_ptr<Obj>;
using VecInt = std::vector<int>;
using AnimVector = std::vector<std::pair<int, int>>;	// ���g�� ��Ұ����ڰтƌ��ݕ`�撆�̱�Ұ��ݶ���
 
enum class ANIM_ID
{ 
	STOP,	// �ҋ@
	RUN,	// �ړ�
	SHOT,	// �e
	S_SHOT,	// �ҋ@�ˌ�
	R_SHOT,	// �ړ��ˌ�
	J_SHOT,	// �ެ��ߎˌ�
	JUMP,	// �ެ���
	MAX
};

enum class UNIT
{
	PLAYER1,
	PLAYER2,
	SHOT,
	SHOT2,
	MAX
};

enum class DIR
{
	RIGHT,
	LEFT,
	MAX
};

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void Update(void) = 0;
	virtual void Draw(void);
	virtual bool Init(void) = 0;
	virtual UNIT GetUnit(void) = 0;

	void SetDrawPos(Vector2 pos);
	const ANIM_ID animKey(void) const;		// _animKey�̎擾
	bool animKey(const ANIM_ID key);		// _animKey�̐ݒ�
	bool SetAnim(const ANIM_ID key, AnimVector& data);// ��Ұ��݂̐ݒ�
	bool isShotF(void) { return _shotF; };		// �����Ă��邩���Ȃ������擾����
	bool isDeath(void) { return _death; };		// ����ł��邩����ł��Ȃ������擾����
	void Decreaselife(void) { _life--; };		// �̗͂�1����������
	Vector2 pos(void) { return _pos; };			// ���W���擾
	Vector2 size(void) { return _size; };		// �傫�����擾
	DIR dir(void) { return _dir; };				// �������擾
	bool pRunF(void){ return _pRunF; };			// �����Ă��邩���Ȃ������擾
	bool pJumpF(void){ return _pJumpF; };		// �W�����v���Ă��邩���Ă��Ȃ������擾

	bool isColF(void) { return _colF; };		// �������������擾
	void SetColF(bool flag) { _colF = flag; };	// ������������ݒ�

private:
	std::map<ANIM_ID, AnimVector>_animMap;
	ANIM_ID _animKey;	// ��Ұ��ݷ��i�ǂ̱�Ұ��݂��j
	int _animCnt;	// ��Ұ��ݶ���
	int _animFrame;	// ��Ұ����ڰ�
protected:
	Vector2 _pos;	// ��޼ު�Ă̍��W 
	Vector2 d_pos;	// _m_pos���`������炷�ׂ̍��W
	Vector2 _size;	// ��޼ު�Ă̑傫��
	UNIT _unit;		// �������g
	VecInt _mapC;	// ϯ�ߏ��
	DIR _dir;		// ��޼ު�Ă̌���
	bool _shotF;	// �e��ł������ł��Ă��Ȃ���
	bool _death;	// ���񂾂�����łȂ���
	bool _pRunF;	// ��ׂ������Ă��邩���Ȃ���
	bool _pJumpF;	// ��ׂ��ެ��߉\���s�\��
	int _life;		// ��ׂ̗̑�
	bool _colF;		// ����������
	
};

