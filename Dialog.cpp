#include<windows.h>
#include"resource.h"
#include "IsValidateMove.h"
#include "chess.h"
int currChessBoard[10][9] =			//棋盘
{
	1, 2, 4, 5, 7, 5, 4, 2, 1,		//黑色,用户是黑色棋子
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 3, 0, 0, 0, 0, 0, 3, 0,
	6, 0, 6, 0, 6, 0, 6, 0, 6,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,		//红色,计算机是红色棋子
	13, 0, 13, 0, 13, 0, 13, 0, 13,
	0, 10, 0, 0, 0, 0, 0, 10, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	8, 9, 11, 12, 14, 12, 11, 9, 8
};								//定义棋盘的初始化格局
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL	CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("Chess");
	int currChessBoard[10][9];
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
	int i, j;
	int chess;
    char bitmapID[8]="CHESS";
	char out[3];
	static int cxWidth, cyWidth;		//一个的长度
	int xPos, yPos;
	static int xSPos, ySPos, xEPos, yEPos;
	static bool mark=false;		//标识上次是否选定一个棋子
	static HINSTANCE hInstance;
	switch (message)
	{
	case WM_CREATE:
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		
		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cxWidth = cxClient / 9;
		cyClient = HIWORD(lParam);
		cyWidth = cyClient / 10;
		return 0;
	case WM_PAINT:		//重绘
		hBitmap = LoadBitmap(hInstance, TEXT("CHESSBOARD"));
		GetObject(hBitmap, sizeof(BITMAP), &bitmap);
		cxSource = bitmap.bmWidth;
		cySource = bitmap.bmHeight;
		hdc = BeginPaint(hwnd, &ps);
		hdcMem = CreateCompatibleDC(hdc);
		SelectObject(hdcMem, hBitmap);
		StretchBlt(hdc, 0, 0, cxClient, cyClient,
			hdcMem, 0, 0, cxSource, cySource, MERGECOPY);
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 9; j++)
			{
				chess = currChessBoard[i][j];
				if (chess != NO_CHESS)
				{
					_itoa_s(chess, out, 10);
					bitmapID[5] = out[0];
					bitmapID[6] = out[1];
					hBitmap = LoadBitmapA(hInstance, bitmapID);
					GetObject(hBitmap, sizeof(BITMAP), &bitmap);
					cxSource = bitmap.bmWidth;
					cySource = bitmap.bmHeight;
					SelectObject(hdcMem, hBitmap);
					StretchBlt(hdc, j*cxWidth+10,cyClient- i*cyWidth-40, cxWidth / 2, cyWidth / 2,
						hdcMem, 0, 0, cxSource, cySource, MERGECOPY);
				}
				
			}
		}
		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_LBUTTONDOWN:
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (xPos >= ((j*cxWidth + 10) - cxWidth / 2) && xPos <= ((j*cxWidth + 10) + cxWidth / 2) && yPos >= ((cyClient - i*cyWidth - 40) - cyWidth / 2) && yPos <= ((cyClient - i*cyWidth - 40) + cyWidth / 2))
				{
					if (mark == false)
					{
						xSPos = i;
						ySPos = j;
						mark = true;
						return 0;
					}
					else
					{
						xEPos = i;
						yEPos = j;
						if (IsValidateMove(currChessBoard,xSPos, ySPos,xEPos,yEPos))
						{
							currChessBoard[xEPos][yEPos] = currChessBoard[xSPos][ySPos];
							currChessBoard[xSPos][ySPos] = NO_CHESS;
							InvalidateRect(hwnd,NULL,false);
						}
						else
						{
							MessageBox(hwnd, TEXT("不合法的走法"), TEXT("错误"), MB_OK);
						}
						mark = false;
						return 0;
					}
					
				}
			}
		}

		return 0;
	case WM_DESTROY:
		DeleteObject(hBitmap);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}