#include"IsValidateMove.h"
int IsValidateMove(int currChessBoard[][9], int xSPos, int ySPos, int xEPos, int yEPos)		//是否是合法的走法
{
	int i;
	int j;
	int s_chess = currChessBoard[xSPos][ySPos];			//出发位置的棋子
	int e_chess = currChessBoard[xEPos][yEPos];			//终点的棋子
	if ((xSPos == xEPos) && (ySPos == yEPos))
	{
		return 0;		//起点和终点一样
	}
	if (IsSameCol(s_chess, e_chess))
	{
		return 0;		//出发点和终点的棋子阵营相同
	}
	switch (s_chess)
	{

	case B_Chariot:					//黑车
	case R_Chariot:					//红车
		if ((xSPos != xEPos) && (ySPos != yEPos))	//没有走直线
		{
			return 0;
		}
		if (xSPos == xEPos)						//x坐标相同
		{
			if (ySPos < yEPos)
			{
				for (i = ySPos + 1; i < yEPos; i++)
				{
					if (currChessBoard[xSPos][i])		//起点和终点之间有阻碍
					{
						return 0;
					}
				}
			}
			else
			{
				for (i = yEPos + 1; i < ySPos; i++)
				{
					if (currChessBoard[xSPos][i])		//起点和终点之间有阻碍
					{
						return 0;
					}
				}
			}

		}
		else							//y坐标相同
		{
			if (xSPos < xEPos)
			{
				for (i = xSPos + 1; i < xEPos; i++)
				{
					if (currChessBoard[i][ySPos])		//起点和终点之间有阻碍
					{
						return 0;
					}
				}
			}
			else
			{
				for (i = xEPos + 1; i < xSPos; i++)
				{
					if (currChessBoard[i][ySPos])
					{
						return 0;
					}
				}
			}
		}
		break;
	case B_Horse:				//黑马
	case R_Horse:				//红马
		if (abs((xSPos - xEPos)*(ySPos - yEPos)) != 2)		//马没有走日
			return 0;
		if ((xSPos - xEPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos])
			{
				return 0;			//马蹄
			}
		}
		else if ((xEPos - xSPos) == 2)
		{
			if (currChessBoard[xSPos + 1][ySPos])
			{
				return 0;			//马蹄
			}
		}
		else if ((ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos][ySPos - 1])
			{
				return 0;
			}
		}
		else
		{
			if (currChessBoard[xSPos][ySPos + 1])
			{
				return 0;
			}
		}
		break;
	case B_Elephant:		//黑象
		if (abs(xSPos - xEPos) != 2 || abs(ySPos - yEPos) != 2 || xEPos > 4)		//走的不是‘田’子，或者终点超过黑方阵营
		{
			return 0;
		}
		if ((xSPos - xEPos) == 2 && (ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos - 1])
			{
				return 0;			//象蹄
			}
		}
		else if ((xSPos - xEPos) == 2 && (yEPos - ySPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos + 1])
			{
				return 0;			//象蹄
			}
		}
		else if ((xEPos - xSPos) == 2 && (ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos + 1][ySPos - 1])
			{
				return 0;			//象蹄
			}
		}
		else
		{
			if (currChessBoard[xSPos + 1][ySPos + 1])
			{
				return 0;			//象蹄
			}
		}
		break;

	case R_Elephant:		//红象
		if (abs(xSPos - xEPos) != 2 || abs(ySPos - yEPos) != 2 || xEPos < 5)		//走的不是‘田’子，或者终点超过红方阵营
		{
			return 0;
		}
		if ((xSPos - xEPos) == 2 && (ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos - 1])
			{
				return 0;			//象蹄
			}
		}
		else if ((xSPos - xEPos) == 2 && (yEPos - ySPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos + 1])
			{
				return 0;			//象蹄
			}
		}
		else if ((xEPos - xSPos) == 2 && (ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos + 1][ySPos - 1])
			{
				return 0;			//象蹄
			}
		}
		else
		{
			if (currChessBoard[xSPos + 1][ySPos + 1])
			{
				return 0;			//象蹄
			}
		}
		break;
	case B_Adviser:		//黑士
		if (abs(xSPos - xEPos) != 1 || abs(ySPos - yEPos) != 1 || xEPos > 2 || yEPos < 3 || yEPos>5)	//没有走'口'子，或者终点没有在范围内
		{
			return 0;
		}
		break;
	case R_Adviser:		//红士
		if (abs(xSPos - xEPos) != 1 || abs(ySPos - yEPos) != 1 || xEPos < 7 || yEPos < 3 || yEPos>5)		//没有走‘口’子，或者终点没有在范围内
		{
			return 0;
		}
		break;
	case B_Canon:		//黑炮
	case R_Canon:		//红炮
		if ((xSPos != xEPos) && (ySPos != yEPos))		//没有走直线
		{
			return 0;
		}
		j = 0;
		if (currChessBoard[xEPos][yEPos])			//终点有棋子
		{
			if (xSPos == xEPos)
			{
				if (ySPos > yEPos)
				{
					for (i = yEPos + 1; i < ySPos; i++)
					{
						if (currChessBoard[xSPos][i])
						{
							j++;
						}
					}
					if (j != 1)		//起点和终点之间不只有一个棋子
					{
						return 0;
					}
				}
				else
				{
					for (i = ySPos + 1; i < yEPos; i++)
					{
						if (currChessBoard[xSPos][i])
						{
							j++;
						}
					}
					if (j != 1)	//起点和终点之间不只有一个棋子
					{
						return 0;
					}
				}
			}
			else
			{
				if (xSPos > xEPos)
				{
					for (i = xEPos + 1; i < xSPos; i++)
					{
						if (currChessBoard[i][ySPos])
						{
							j++;
						}
					}
					if (j != 1)		//起点和终点之间不止有一个棋子
					{
						return 0;
					}
				}
				else
				{
					for (i = xSPos + 1; i < xEPos; i++)
					{
						if (currChessBoard[i][ySPos])
						{
							j++;
						}
					}
					if (j != 1)	//起点和终点之间不止有一个棋子
					{
						return 0;
					}
				}
			}
		}
		else										//终点没有棋子
		{
			if (xSPos == xEPos)						//x坐标相同
			{
				if (ySPos < yEPos)
				{
					for (i = ySPos + 1; i < yEPos; i++)
					{
						if (currChessBoard[xSPos][i])		//起点和终点之间有阻碍
						{
							return 0;
						}
					}
				}
				else
				{
					for (i = yEPos + 1; i < ySPos; i++)
					{
						if (currChessBoard[xSPos][i])		//起点和终点之间有阻碍
						{
							return 0;
						}
					}
				}

			}
			else							//y坐标相同
			{
				if (xSPos < xEPos)
				{
					for (i = xSPos + 1; i < xEPos; i++)
					{
						if (currChessBoard[i][ySPos])		//起点和终点之间有阻碍
						{
							return 0;
						}
					}
				}
				else
				{
					for (i = xEPos + 1; i < xSPos; i++)
					{
						if (currChessBoard[i][ySPos])
						{
							return 0;
						}
					}
				}
			}
		}

		break;
	case B_Pawn:		//黑兵
		if (xSPos > xEPos)		//不能向后走
		{
			return 0;
		}
		if (xSPos < 5)			//过河之前
		{
			if ((xEPos - xSPos) != 1 || ySPos != yEPos)		//如果不是先前走了一格
			{
				return 0;
			}
		}
		else
		{
			if ((abs(xSPos - xEPos) + abs(ySPos - yEPos)) != 1)		//如果不是走了一格
			{
				return 0;
			}
		}
		break;
	case R_Pawn:	//红兵
		if (xSPos < xEPos)		//不能向后走
		{
			return 0;
		}
		if (xSPos > 4)		//过河之前
		{
			if ((xSPos - xEPos) != 1 || ySPos != yEPos)		//如果不是向前走了一格
			{
				return 0;
			}
		}
		else
		{
			if ((abs(xSPos - xEPos) + abs(ySPos - yEPos)) != 1)		//如果不是走了一格
			{
				return 0;
			}
		}
		break;
	case B_King:	//黑将
		if (xEPos > 2 || yEPos < 3 || yEPos>5 || ((abs(xSPos - xEPos) + abs(ySPos - yEPos)) != 1))	//超出了将应该在的范围或者走的不是一格
		{
			return 0;
		}
		break;
	case R_King:	//红将
		if (xEPos < 7 || yEPos < 3 || yEPos>5 || ((abs(xSPos - xEPos) + abs(ySPos - yEPos)) != 1))	//超出了将应该在的范围或者走的不止一个
		{
			return 0;
		}
		break;
		return 1;
	}

}