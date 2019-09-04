#include <DxLib.h>
#include "scene/SceneMng.h"


int WINAPI WinMain(HINSTANCE hINSTANCE, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	lpSceneMng.Run();
	DxLib_End();
	return 0;
}