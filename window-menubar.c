#include <windows.h>

HMENU hmenu;			// not 100% sure why he made this global

void addmenus(HWND hWnd)
{
	hmenu = CreateMenu();
	HMENU  hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();
	
// The Numbers after the parameter MF_STRING, the third parameter is used below in the WM_Command section

// File in menu bar with sub menus
	AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hFileMenu,"File");
	AppendMenu(hFileMenu,MF_STRING,2,"New");
	AppendMenu(hFileMenu,MF_STRING,3,"Open");
	AppendMenu(hFileMenu,MF_POPUP,(UINT_PTR)hSubMenu,"Open SubMenu");
	AppendMenu(hFileMenu,MF_SEPARATOR,0,0);		// Watch your spelling
	AppendMenu(hFileMenu,MF_STRING,4,"Quit");

	AppendMenu(hSubMenu,MF_STRING,31,"Submenu Item");

// Help on menu bar I idn't add any sub menus
	AppendMenu(hmenu,MF_STRING,1,"Help");

	SetMenu(hWnd,hmenu);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch(msg)
	{
		case WM_CREATE:
			addmenus(hwnd);
			break;

		case WM_COMMAND:
			switch(wParam)
			{
				case 1:
				MessageBox(hwnd,"HELP: on Menu Bar Was used","Hooray!",MB_OK);
				break;

				case 2:
				MessageBox(hwnd,"NEW: Under File on Menu Bar Was used","Hooray!",MB_OK);
				break;

				case 3:
				MessageBox(hwnd,"OPEN: Under File on Menu Bar Was used","Hooray!",MB_OK);
				break;

				case 31:
				MessageBox(hwnd,"Sub-SubMenu: Under File on Menu Bar Was used","Hooray!",MB_OK);
				break;

				case 4:
				DestroyWindow(hwnd);
				break;
			}
			break;

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
	wc.lpszClassName =L"Sample Window Class";    // CLASS_NAME;
	wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);

	RegisterClassW(&wc);

	CreateWindowW(L"Sample Window Class",L"Attempt Menubar", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,NULL,NULL);

	MSG msg = {0};

	while( GetMessage(&msg, NULL, 0, 0) )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

}
