#include<windows.h>
#include"resource.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL	CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("Chess");
	MSG msg;
	HWND hwnd;
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = DLGWINDOWEXTRA;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, TEXT("ABOUT1"));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = TEXT("ABOUT1");
	wndclass.lpszClassName = szAppName;
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT"), szAppName, MB_ICONERROR);
		return 0;
	}
	hwnd = CreateDialog(hInstance,szAppName,0,NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int cxClient, cyClient, cxSource, cySource;
	BITMAP bitmap;
	static HBITMAP hBitmap;
	HDC hdc, hdcMem;
	PAINTSTRUCT ps;
	int x, y;
	int cxWidth, cyWidth;		//一个的长度
	static HINSTANCE hInstance;
	switch (message)
	{
	case WM_CREATE:
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hBitmap = LoadBitmap(hInstance, TEXT("CHESSBOARD"));
		GetObject(hBitmap, sizeof(BITMAP), &bitmap);
		cxSource = bitmap.bmWidth;
		cySource = bitmap.bmHeight;
		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		hdcMem = CreateCompatibleDC(hdc);
		SelectObject(hdcMem, hBitmap);
		StretchBlt(hdc, 0, 0, cxClient, cyClient,
			hdcMem, 0, 0, cxSource, cySource, MERGECOPY);
		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		DeleteObject(hBitmap);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}