#include "search.h"
#include "evalution.h"
int IsBlackFail(int currChessBoard[][9])		//�жϺ�����û���䣬�������û���䷵��0�����򷵻�1
{
	int i, j;
	for (i = 0; i <= 2; i++)
	{
		for (j = 3; j<= 5; j++)
		{
			if (currChessBoard[i][j] == B_King)
			{
				return 0;			//����û����
			}
		}
	}
	return 1;
}
int IsRedFail(int currChessBoard[][9])		//�жϺ�����û���䣬���û���䷵��0�����򷵻�1
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
