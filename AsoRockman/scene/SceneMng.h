#pragma once
#include <memory>
#include "BaseScene.h"

#define lpSceneMng SceneMng::GetInstance()
class SceneMng
{
public:
	static SceneMng &GetInstance()
	{
		return (*s_instance);
	}
	void Run();	

private:
	struct SceneDeleter
	{
		void operator()(SceneMng* sceneMng)
		{
			delete sceneMng;
		}
	};
	SceneMng();
	~SceneMng();

	bool SysInit();	// dxlib������
	unique_base _activeScene;		// ���݂̼��


	static std::unique_ptr<SceneMng, SceneDeleter> s_instance;
};

