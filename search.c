#include "search.h"
#include "evalution.h"
int IsBlackFail(int currChessBoard[][9])		//判断黑棋有没有输，如果黑棋没有输返回0，否则返回1
{
	int i, j;
	for (i = 0; i <= 2; i++)
	{
		for (j = 3; j<= 5; j++)
		{
			if (currChessBoard[i][j] == B_King)
			{
				return 0;			//黑棋没有输
			}
		}
	}
	return 1;
}
int IsRedFail(int currChessBoard[][9])		//判断红棋有没有输，如果没有输返回0，否则返回1
{
	int i, j;
	for (i = 7; i <= 9; i++)
	{
		for (j = 3; j <= 5; j++)
		{
			if (currChessBoard[i][j] == R_King)
			{
				return 0;
			}
		}
	}
	return 1;
}
