#include "Evalution.h"
int GetBingValue(int currChessBoard[][9],int i, int j)
{
	if (currChessBoard[i][j] == B_Pawn)		//如果是黑兵的话返回黑兵的附加值
	{
		return BAO[i][j];
	}
	if (currChessBoard[i][j] == R_Pawn)		//如果是红兵的话返回红兵的附加值
	{
		return BA1[i][j];
	}
	return 0;
}
void PushReleatedMove(LReleatedList* top, int xEPos, int yEPos)		//将相关连的步伐进栈
{
	LReleatedList p = (LReleatedList)malloc(sizeof(LReleatedNode));
	p->xEPos = xEPos;
	p->yEPos = yEPos;
	p->next = (*top);
	(*top) = p;
}
LReleatedList PopReleatedMove(LReleatedList* top)			//将相关联的步伐出栈
{
	LReleatedList p;
	p = (*top);
	(*top) = (*top)->next;
	return p;
}
LReleatedList GetReleatedPiece(int currChessBoard[][9], int xSPos, int ySPos)
{
	int m, n;
	LReleatedList Top;
	Top = NULL;
	int chess = currChessBoard[xSPos][ySPos];
	if (chess == NO_CHESS)
	{
		return Top;
	}
	switch (chess)
	{
	case B_Chariot:
	case R_Chariot:
		for (m = xSPos - 1; m >= 0; m--)		//向x减小方向线循环
		{
			if (!currChessBoard[m][ySPos])			//当前位置没有棋子
			{
				PushReleatedMove(&Top, m, ySPos);
			}
			else							//当前位置有棋子
			{
				PushReleatedMove(&Top, m, ySPos);
				break;
			}
		}
		for (m = xSPos + 1; m< 10; m++)	//向x增大方向循环
		{
			if (!currChessBoard[m][ySPos])		//当前位置没有棋子
			{
				PushReleatedMove(&Top, m, ySPos);
			}
			else						//当前位置存在棋子
			{

				PushReleatedMove(&Top, m, ySPos);
				break;
			}
		}
		for (m = ySPos - 1; m >= 0; m--)		//向ySPos减小方向循环
		{
			if (!currChessBoard[xSPos][m])		//当前位置没有棋子
			{
				PushReleatedMove(&Top,xSPos, m);
			}
			else						//当前位置存在棋子
			{
				PushReleatedMove(&Top, xSPos, m);
				break;
			}
		}
		for (m = ySPos + 1; m<9; m++)		//向ySPos增大方向循环
		{
			if (!currChessBoard[xSPos][m])		//当前位置没有棋子
			{
				PushReleatedMove(&Top, xSPos, m);
			}
			else						//当前位置存在棋子
			{
				PushReleatedMove(&Top, xSPos, m);
				break;
			}
		}
		break;
	case B_Horse:
	case R_Horse:
		if (xSPos<8)		//向上走
		{
			if (!currChessBoard[xSPos + 1][ySPos])		//马蹄没有被拌
			{
				if (ySPos>0)		//向左上走
				{
					PushReleatedMove(&Top, xSPos+2, ySPos-1);
				}
				if (ySPos<8)		//向右上走
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos + 1);
				}
			}
		}
		if (xSPos>1)		//向下走
		{
			if (!currChessBoard[xSPos - 1][ySPos])		//马蹄没有被拌
			{
				if (ySPos>0)		//向左下走
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos - 1);
				}
				if (ySPos<8)		//向右下走
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos + 1);
				}
			}
		}
		if (ySPos<7)		//向右走
		{
			if (!currChessBoard[xSPos][ySPos + 1])		//马蹄没有被拌
			{
				if (xSPos>0)		//向右下走
				{
					PushReleatedMove(&Top, xSPos -1, ySPos +2 );
				}
				if (xSPos<8)		//向右上走
				{
					PushReleatedMove(&Top, xSPos + 1, ySPos + 2);
				}
			}
		}
		if (ySPos>1)		//向左走
		{
			if (!currChessBoard[xSPos][ySPos - 1])
				if (xSPos>0)		//向左下走
				{
					PushReleatedMove(&Top, xSPos - 1, ySPos - 2);
				}
			if (xSPos<8)		//向左上走
			{
				PushReleatedMove(&Top, xSPos + 1, ySPos - 2);
			}
		}
		break;
	case B_Canon:		//黑炮
	case R_Canon:
		n = 0;
		for (m = xSPos - 1; m >= 0; m--)			//向x减小方向循环
		{
			if ((!currChessBoard[m][ySPos]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
			{
				PushReleatedMove(&Top, m, ySPos);
			}
			else		//有棋子
			{
				n++;
				if (n == 2)
				{
					PushReleatedMove(&Top, m, ySPos);
					break;		//跳出当前循环
				}
			}
		}
		n = 0;
		for (m = xSPos + 1; m <= 9; m++)		//沿x增大方向循环
		{
			if ((!currChessBoard[m][ySPos]) && (n == 0))	//该点没有棋子并且起点和终点之间没有其他棋子
			{
				PushReleatedMove(&Top, m, ySPos);
			}
			else		//该点有棋子
			{
				n++;
				if (n == 2)
				{
					PushReleatedMove(&Top, m, ySPos);
					break;	//跳出循环
				}
			}
		}
		n = 0;
		for (m = ySPos - 1; m >= 0; m--)			//向y减小的方向循环
		{
			if ((!currChessBoard[xSPos][m]) && (n == 0))		//这点没有棋子并且起点和终点之间没有棋子
			{
				PushReleatedMove(&Top, xSPos, m);
			}
			else
			{
				n++;
				if (n == 2)
				{
					PushReleatedMove(&Top, xSPos, m);
					break;
				}
			}
		}
		n = 0;
		for (m = ySPos + 1; m <= 8; m++)		//向y增大的方向循环
		{
			if ((!currChessBoard[xSPos][m]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
			{
				PushReleatedMove(&Top, xSPos, m);
			}
			else		//该点有棋子
			{
				n++;
				if (n == 2)
				{
					PushReleatedMove(&Top, xSPos, m);
					break;
				}
			}
		}
		break;
	case B_Elephant:		//黑象
		if (xSPos == 0)		//在最低线上
		{
			if (!currChessBoard[xSPos + 1][ySPos - 1])		//左上方象蹄没有被拌
			{
				PushReleatedMove(&Top, xSPos+2, ySPos-2);
			}
			if (!currChessBoard[xSPos + 1][ySPos + 1])		//右上方象蹄没有被拌
			{
				PushReleatedMove(&Top, xSPos + 2, ySPos + 2);
			}
		}
		else if (xSPos == 2)	//在黑色阵营的中线上
		{
			if (ySPos == 0 || ySPos == 4)
			{
				if (!currChessBoard[xSPos + 1][ySPos + 1])		//右上方象蹄没有被拌
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos + 2);
				}
				if (!currChessBoard[xSPos - 1][ySPos + 1])		//右下方象蹄没有被拌
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos + 2);
				}
			}
			if (ySPos == 4 || ySPos == 8)
			{
				if (!currChessBoard[xSPos + 1][ySPos - 1])		//左上方象蹄没有被拌
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos - 2);
				}
				if (!currChessBoard[xSPos - 1][ySPos - 1])		//左下方象蹄没有被拌
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos - 2);
				}
			}

		}
		else		//xSPos=5,在黑色阵营的最上线
		{
			if (!currChessBoard[xSPos - 1][ySPos - 1])	//左下象蹄没有被拌
			{
				PushReleatedMove(&Top, xSPos - 2, ySPos - 2);
			}
			if (!currChessBoard[xSPos - 1][ySPos + 1])	//右下方象蹄没有被拌
			{
				PushReleatedMove(&Top, xSPos - 2, ySPos + 2);
			}
		}
		break;
	case R_Elephant:		//红象
		if (xSPos == 5)		//在最红色阵营的最底线上
		{
			if (!currChessBoard[xSPos + 1][ySPos - 1])		//左上方象蹄没有被拌
			{
				PushReleatedMove(&Top, xSPos + 2, ySPos - 2);
			}
			if (!currChessBoard[xSPos + 1][ySPos + 1])		//右上方象蹄没有被拌
			{
				PushReleatedMove(&Top, xSPos + 2, ySPos + 2);
			}
		}
		else if (xSPos == 7)	//在黑色阵营的中线上
		{
			if (ySPos == 0 || ySPos == 4)
			{
				if (!currChessBoard[xSPos + 1][ySPos + 1])		//右上方象蹄没有被拌
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos + 2);
				}
				if (!currChessBoard[xSPos - 1][ySPos + 1])		//右下方象蹄没有被拌
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos + 2);
				}
			}
			if (ySPos == 4 || ySPos == 8)
			{
				if (!currChessBoard[xSPos + 1][ySPos - 1])		//左上方象蹄没有被拌
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos - 2);
				}
				if (!currChessBoard[xSPos - 1][ySPos - 1])		//左下方象蹄没有被拌
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos - 2);
				}
			}

		}
		else		//xSPos=9,在黑色阵营的最上线
		{
			if (!currChessBoard[xSPos - 1][ySPos - 1])	//左下象蹄没有被拌
			{
				PushReleatedMove(&Top, xSPos - 2, ySPos - 2);
			}
			if (!currChessBoard[xSPos - 1][ySPos + 1])	//右下方象蹄没有被拌
			{
				PushReleatedMove(&Top, xSPos - 2, ySPos + 2);
			}
		}
		break;
	case B_Adviser:		//黑士
		if ((xSPos + 1) <= 2 && (ySPos + 1) <= 5)		//可以向右上走
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos + 1);
		}
		if ((xSPos + 1) <= 2 && (ySPos - 1) >= 3)		//可以向左上走
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos - 1);
		}
		if ((xSPos - 1) >= 0 && (ySPos + 1) <= 5)		//可以向右下走
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos + 1);
		}
		if ((xSPos - 1) >= 0 && (ySPos - 1) >= 3)		//可以向左下走
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos - 1);
		}
		break;
	case R_Adviser:		//红士
		if ((xSPos + 1) <= 9 && (ySPos + 1) <= 5)		//可以向右上走
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos + 1);
		}
		if ((xSPos + 1) <= 9 && (ySPos - 1) >= 3)		//可以向左上走
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos - 1);
		}
		if ((xSPos - 1) >= 7 && (ySPos + 1) <= 5)		//可以向右下走
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos + 1);
		}
		if ((xSPos - 1) >= 7 && (ySPos - 1) >= 3)		//可以向左下走
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos - 1);
		}
		break;
	case B_King:		//黑将
		if (xSPos<2)		//可以向上走
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos );
		}
		if (xSPos>0)		//可以向下走
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos);
		}
		if (ySPos>3)		//可以向左走
		{
			PushReleatedMove(&Top, xSPos, ySPos-1);
		}
		if (ySPos<5)		//可以向右走
		{
			PushReleatedMove(&Top, xSPos, ySPos + 1);
		}
		break;
	case R_King:
		if (xSPos<9)		//可以向上走
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos);
		}
		if (xSPos>7)		//可以向下走
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos);
		}
		if (ySPos>3)		//可以向左走
		{
			PushReleatedMove(&Top, xSPos, ySPos - 1);
		}
		if (ySPos<5)		//可以向右走
		{
			PushReleatedMove(&Top, xSPos, ySPos + 1);
		}
		break;
	case R_Pawn:
		if (xSPos >= 5)		//还没有过河
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos);
		}
		else			//已经过了河
		{
			if (xSPos > 0)		//可以向下走
			{
				PushReleatedMove(&Top, xSPos - 1, ySPos);
			}
			if (ySPos > 0)	//可以向左走
			{
				PushReleatedMove(&Top, xSPos, ySPos - 1);
			}
			if (ySPos < 8)
			{
				PushReleatedMove(&Top, xSPos, ySPos + 1);
			}
		}
		break;
	case B_Pawn:
		if (xSPos <= 4)		//还没有过河
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos);
		}
		else
		{
			if (xSPos < 9)		//向上走
			{
				PushReleatedMove(&Top, xSPos + 1, ySPos);
			}
			if (ySPos > 0)			//可以向左走
			{
				PushReleatedMove(&Top, xSPos, ySPos - 1);
			}
			if (ySPos < 8)
			{
				PushReleatedMove(&Top, xSPos, ySPos + 1);
			}
		}
		break;
	}
	return Top;
}
int Evaluation(int currChessBoard[][9], bool IsRedTurn)
{
	int sum;
	int Flex[10][9] = { 0 };		//灵活性记录
	int Guard[10][9] = { 0 };		//受保护的记录
	int Attack[10][9] = { 0 };		//受攻击的记录
	int ChessValue[10][9] = { 0 };	//棋子的估值
	int i, j;			//循环使用
	int nHalfValue;
	int xchess, echess;
	LReleatedList top, p;
	int xEPos;
	int yEPos;
	int SumRValue;		//红色的总的估值
	int SumBValue;		//黑色的总的估值
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			xchess = currChessBoard[i][j];
			top = GetReleatedPiece(currChessBoard, i, j);
			while (top != NULL)
			{
				p = PopReleatedMove(&top);
				xEPos = p->xEPos;
				yEPos = p->yEPos;
				free(p);
				echess = currChessBoard[xEPos][yEPos];
				if (echess == NO_CHESS)
				{
					Flex[i][j]++;		//灵活性增加
				}
				else
				{
					if (IsSameCol(xchess, echess))		//如果是同一边的棋子就受保护
					{
						Guard[xEPos][yEPos]++;
					}
					else			//不同边的棋子
					{
						Flex[i][j]++;
						Attack[xEPos][yEPos]++;
						switch (echess)
						{
						case B_King:		//是黑将
							if (IsRedTurn)		//该红子走了
							{
								return 18888;
							}
						case R_King:		//红将
							if (!IsRedTurn)		//该黑子走了
							{
								return 18888;
							}
						default:
							Attack[xEPos][yEPos] += (30 + (m_BaseValue[echess] - m_BaseValue[xchess]) / 10) / 10;		//根据威胁加上威胁的分值
						}
					}
				}

			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			xchess = currChessBoard[i][j];
			if (xchess != NO_CHESS)
			{
				ChessValue[i][j]++;		//如果棋子存在则基本价值不为0
				ChessValue[i][j] += Flex[i][j] * m_FlexValue[xchess];		//加上灵活性的估值
				ChessValue[i][j] += GetBingValue(currChessBoard,i, j);			//加上兵的估值
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			xchess = currChessBoard[i][j];
			if (xchess != NO_CHESS)
			{
				nHalfValue = m_BaseValue[xchess] / 16;
				ChessValue[i][j] += m_BaseValue[xchess];
				if (IsRed(xchess))		//如果是红色棋子的话
				{
					if (Attack[i][j])	//如果该棋子被威胁的话
					{
						if (IsRedTurn)		//改红色棋子走了
						{
							if (xchess == R_King)		//如果是红将的话
							{
								ChessValue[i][j] -= 20;;
							}
							else
							{
								ChessValue[i][j] -= nHalfValue * 2;
								if (Guard[i][j])
								{
									ChessValue[i][j] += nHalfValue;
								}
							}
						}
						else		//红色棋子被威胁该黑子走了
						{
							if (xchess == R_King)		//如果被威胁的棋子是红将的话，直接失败
							{
								return 18888;		//直接返回失败的最大值
							}
							else
							{
								ChessValue[i][j] -= nHalfValue * 10;		//表示受威胁程度非常高
								if (Guard[i][j])
								{
									ChessValue[i][j] += nHalfValue * 9;
								}
							}
						}
						ChessValue[i][j] -= Attack[i][j];		//防止一个兵威胁一个车而估值函数没有反应这个问题
					}
					else			//如果不收威胁的话
					{
						if (Guard[i][j])
						{
							ChessValue[i][j] += 5;
						}
					}
				}
				else		//如果是黑色棋子
				{
					if (Attack[i][j])
					{
						if (IsRedTurn)
						{
							if (xchess == B_King)		//如果是黑将的话
							{
								return 18888;		//返回失败的最大值
							}
							else
							{
								ChessValue[i][j] -= nHalfValue * 10;	//表示受威胁的程度很大
								if (Guard[i][j])
								{
									ChessValue[i][j] += nHalfValue * 9;
								}
							}
						}
						else		//如果不是该红色棋子走的话
						{
							if (xchess == B_King)		//如果是黑将的话
							{
								ChessValue[i][j] -= 20;
							}
							else
							{
								ChessValue[i][j] -= nHalfValue * 2;
								if (Guard[i][j])		//如果是受保护的话
								{
									ChessValue[i][j] += nHalfValue;
								}
							}
						}
						ChessValue[i][j] -= Attack[i][j];	//防止以个兵威胁一个车而估值函数没有反应出来
					}
					else
					{
						if (Guard[i][j])
						{
							ChessValue[i][j] += 5;
						}
					}
				}
			}
		}
	}
	SumBValue = SumRValue = 0;
	for (i = 0; i<10; i ++)
	{
		for (j = 0; j < 9; j++)
		{
			xchess = currChessBoard[i][j];
			if (xchess != NO_CHESS)
			{
				if (IsRed(xchess))
				{
					SumRValue += ChessValue[i][j];
				}
				else
				{
					SumBValue += ChessValue[i][j];
				}
			}
		}
	}
	if (IsRedTurn)
	{
		return SumRValue - SumBValue;
	}
	else
	{
		return SumBValue - SumRValue;
	}

}