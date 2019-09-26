/*
** WinMain
*/

//
// include •”
//

#include "appframe.h"

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
  DirectX11Manager manager;
  if (FAILED(manager.Init(hInstance, nCmdShow)))
    return -1;
  MSG msg = { 0 };
  while (true)
  {
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    if (WM_QUIT == msg.message) return 0;
  }

  return 0;
}
