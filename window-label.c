#include <windows.h>

#define ID_BUTTON1 1     // I could just put the number 1 or 2 in the create window instead of this
#define ID_BUTTON2 2

// didn't use a prototype foe WindowProc, WinMain is below
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch(msg)
	{
		case WM_CREATE:
		{
			CreateWindowW(L"static",L"Here is a label", WS_CHILD | WS_VISIBLE, 20,40,120,20,
			hwnd, (HMENU) NULL, NULL, NULL);

			break;
		}

		case WM_DESTROY:
		PostQuitMessage(0);
		break;

		default:
		return DefWindowProcW( hwnd,msg,wParam,lParam);
	}

	return 0;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR lpCmdLine, int nCmdShow)
{
   
	WNDCLASSW wc = {0};

	wc.lpfnWndProc   = WindowProc;
	wc.hInstance     = hInstance;
	wc.lpszClassName =  L"Sample Window Class";
	wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassW(&wc);

	HWND hwnd = CreateWindowW(L"Sample Window Class", L"Window With Label", WS_OVERLAPPEDWINDOW,   CW_USEDEFAULT, 
		CW_USEDEFAULT, 500,500,  NULL,  NULL, hInstance, NULL );

	if (hwnd == NULL)
	{
		 return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg = {0};

	while( GetMessage(&msg, NULL, 0, 0) )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

}
