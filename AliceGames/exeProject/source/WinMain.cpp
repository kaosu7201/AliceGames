/*
** WinMain
*/

//
// include ��
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
  VertexShader vs;
  PixelShader ps;
  InputLayout il;
  // ���_����ݒ�
    struct Vertex
  {
    XMFLOAT3 pos;
    XMFLOAT4 col;
    XMFLOAT2 uv;
  };

  //�e�N�X�`���̍쐬
  ComPtr<ID3D11ShaderResourceView> texture;
  texture.Attach(manager.CreateTextureFromFile(L"res/Texture/Player/reimu_Idle_L.png"));
  vs.Attach(manager.CreateVertexShader("res/Shaders/Sprite.fx", "vs_main"));
  ps.Attach(manager.CreatePixelShader("res/Shaders/Sprite.fx", "ps_main"));
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
