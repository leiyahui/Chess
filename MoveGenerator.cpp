#include "MoveGenerator.h"

MoveLink MoveGenerator(int currChessBoard[][9], int redTurn)		//走法产生器,i=0该黑子走，否则该红子走
{
	int xSPos, ySPos, xEPos, yEPos;
	int chess;
	int i, j;
	int m, n;
	MoveLink Head = NULL;
	MoveLink p = (MoveLink)malloc(sizeof(Move));
	Head = p;
	MoveLink q;
	if (redTurn)
	{
		for (i = 0; i<10; i++)
		{
			for (j = 0; j<9; j++)
			{
				chess = currChessBoard[i][j];
				switch (chess)
				{
				case NO_CHESS:		//没有棋子
					break;
				case R_Chariot:		//红车
					for (m = i - 1; m >= 0; m--)		//向x减小方向线循环
					{
						if (!currChessBoard[m][j])			//当前位置没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = m;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else							//当前位置有棋子
						{
							if (IsBlack(currChessBoard[m][j]))		//不同阵营的时候添加一个节点
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = m;
								q->yEPos = j;
								q->next = NULL;
								p = q;
							}
							break;
						}
					}
					for (m = i + 1; m < 10; m++)	//向x增大方向循环
					{
						if (!currChessBoard[m][j])		//当前位置没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = m;
							q->ySPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//当前位置存在棋子
						{
							if (IsBlack(currChessBoard[m][j]))	//不同阵营的时候添加一个节点	
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = m;
								q->yEPos = j;
								q->next = NULL;
								p = q;
							}
							break;
						}
					}
					for (m = j - 1; m >= 0; m--)		//向j减小方向循环
					{
						if (!currChessBoard[i][m])		//当前位置没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->ySPos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//当前位置存在棋子
						{
							if (IsBlack(currChessBoard[i][m]))	//不同阵营的时候添加一个节点	
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i;
								q->yEPos = m;
								q->next = NULL;
								p = q;
							}
							break;
						}
					}
					for (m = j + 1; m<9; m++)		//向j增大方向循环
					{
						if (!currChessBoard[i][m])		//当前位置没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->ySPos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//当前位置存在棋子
						{
							if (IsBlack(currChessBoard[i][m]))	//不同阵营的时候添加一个节点	
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i;
								q->yEPos = m;
								q->next = NULL;
								p = q;
							}
							break;
						}
					}
					break;

				case R_Horse:		//红马
					if (i<8)		//向上走
					{
						if (!currChessBoard[i + 1][j])		//马蹄没有被拌
						{
							if (j>0 && (!IsRed(currChessBoard[i + 2][j - 1])))		//向左上走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 2;
								q->yEPos = j - 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (j<9 && (!IsRed(currChessBoard[i + 2][j + 1])))		//向右上走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 2;
								q->yEPos = j + 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (i>1)		//向下走
					{
						if (!currChessBoard[i - 1][j])		//马蹄没有被拌
						{
							if (j>0 && (!IsRed(currChessBoard[i - 2][j - 1])))		//向左下走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 2;
								q->yEPos = j - 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (j<9 && (!IsRed(currChessBoard[i - 2][j + 1])))		//向右下走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 2;
								q->yEPos = j + 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (j<7)		//向右走
					{
						if (!currChessBoard[i][j + 1])		//马蹄没有被拌
						{
							if (i>0 && (!IsRed(currChessBoard[i - 1][j + 2])))		//向右下走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 1;
								q->yEPos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (i<9 && (!IsRed(currChessBoard[i + 1][j + 2])))		//向右上走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 1;
								q->yEPos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (j>1)		//向左走
					{
						if (!currChessBoard[i][j - 1])
							if (i>0 && (!IsRed(currChessBoard[i - 1][j - 2])))		//向左下走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 1;
								q->yEPos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						if (i<9 && (!IsRed(currChessBoard[i + 1][j - 2])))		//向左上走
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j - 2;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;

				case R_Canon:		//红炮
					n = 0;
					for (m = i - 1; m >= 0; m--)			//向x减小方向循环
					{
						if ((!currChessBoard[m][j]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = m;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(currChessBoard[m][j]))		//是红色棋子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = m;
									q->yEPos = j;
									q->next = NULL;
									p->next = q;
									p = q;
								}
								break;		//跳出当前循环
							}
						}
					}
					n = 0;
					for (m = i + 1; m <= 9; m++)		//沿x增大方向循环
					{
						if ((!currChessBoard[m][j]) && (n == 0))	//该点没有棋子并且起点和终点之间没有其他棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = m;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//该点有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(currChessBoard[m][j]))		//是红色棋子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = m;
									q->yEPos = j;
									q->next = NULL;
									p->next = q;
									p = q;
								}
								break;	//跳出循环
							}
						}
					}
					n = 0;
					for (m = j - 1; m >= 0; m--)			//向y减小的方向循环
					{
						if ((!currChessBoard[i][m]) && (n == 0))		//这点没有棋子并且起点和终点之间没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(currChessBoard[i][m]))		//是红色棋子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i;
									q->yEPos = m;
									q->next = NULL;
									p->next = q;
									p = q;
								}
								break;
							}
						}
					}
					n = 0;
					for (m = j + 1; m <= 8; m++)		//向y增大的方向循环
					{
						if ((!currChessBoard[i][m]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//该点有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(currChessBoard[i][m]))
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i;
									q->yEPos = m;
									q->next = NULL;
									p->next = q;
									p = q;
								}
								break;
							}
						}
					}
					break;

				case R_Elephant:		//红象
					if (i == 5)		//在最红色阵营的最底线上
					{
						if (!currChessBoard[i + 1][j - 1])		//左上方象蹄没有被拌
						{
							if (!IsRed(currChessBoard[i + 2][j - 2]))		//不是红子
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 2;
								q->yEPos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
						if (!currChessBoard[i + 1][j + 1])		//右上方象蹄没有被拌
						{
							if (!IsRed(currChessBoard[i + 2][j + 2]))		//不是红子
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 2;
								q->yEPos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					else if (i == 7)	//在黑色阵营的中线上
					{
						if (j == 0 || j == 4)
						{
							if (!currChessBoard[i + 1][j + 1])		//右上方象蹄没有被拌
							{
								if (!IsRed(currChessBoard[i + 2][j + 2]))	//不是红子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i + 2;
									q->yEPos = j + 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
							if (!currChessBoard[i - 1][j + 1])		//右下方象蹄没有被拌
							{
								if (!IsRed(currChessBoard[i - 2][j + 2]))			//不是红子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i - 2;
									q->yEPos = j + 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
						}
						if (j == 4 || j == 8)
						{
							if (!currChessBoard[i + 1][j - 1])		//左上方象蹄没有被拌
							{
								if (!IsRed(currChessBoard[i + 2][j - 2]))		//不是红子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i + 2;
									q->yEPos = j - 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
							if (!currChessBoard[i - 1][j - 1])		//左下方象蹄没有被拌
							{
								if (!IsRed(currChessBoard[i - 2][j - 2]))		//不是红子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i - 2;
									q->yEPos = j - 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
						}

					}
					else		//i=9,在黑色阵营的最上线
					{
						if (!currChessBoard[i - 1][j - 1])	//左下象蹄没有被拌
						{
							if (!IsRed(currChessBoard[i - 2][j - 2]))		//不是红子
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 2;
								q->yEPos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
						if (!currChessBoard[i - 1][j + 1])	//右下方象蹄没有被拌
						{
							if (!IsRed(currChessBoard[j - 2][j + 2]))	//不是红子
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 2;
								q->yEPos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					break;

				case R_Adviser:		//红士
					if ((i + 1) <= 9 && (j + 1) <= 5)		//可以向右上走
					{
						if (!IsRed(currChessBoard[i + 1][j + 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i + 1) <= 9 && (j - 1) >= 3)		//可以向左上走
					{
						if (!IsRed(currChessBoard[i + 1][j - 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i - 1) >= 7 && (j + 1) <= 5)		//可以向右下走
					{
						if (!IsRed(currChessBoard[i - 1][j + 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i - 1;
							q->yEPos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i - 1) >= 7 && (j - 1) >= 3)		//可以向左下走
					{
						if (!IsRed(currChessBoard[i - 1][j - 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i - 1;
							q->yEPos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;

				case R_King:
					if (i<9)		//可以向上走
					{
						if (!IsRed(currChessBoard[i + 1][j]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							q = q;
						}
					}
					if (i>7)		//可以向下走
					{
						if (!IsRed(currChessBoard[i - 1][j]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i - 1;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (j>3)		//可以向左走
					{
						if (!IsRed(currChessBoard[i][j - 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (j<5)		//可以向右走
					{
						if (!IsRed(currChessBoard[i][j + 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;
				case R_Pawn:		//红兵
					if (i >= 5)
					{
						if (!IsRed(currChessBoard[i - 1][j]))	//向前走,目标不是红子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i - 1;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					else
					{
						if (!IsRed(currChessBoard[i - 1][j])&&(i>0)) //向前走，目标不是红子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i - 1;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						if (!IsRed(currChessBoard[i][j-1]) && (j>0))//向左走，目标不是红子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						if (!IsRed(currChessBoard[i][j + 1]) && (j<8))//向右，目标不是红子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;
				}
			}
		}
	}
	else
	{
		for (i = 0; i<10; i++)
		{
			for (j = 0; j<9; j++)
			{
				chess = currChessBoard[i][j];
				switch (chess)
				{
				case NO_CHESS:		//没有棋子
					break;
				case B_Chariot:		//黑车
					for (m = i - 1; m >= 0; m--)		//向x减小方向线循环
					{
						if (!currChessBoard[m][j])			//当前位置没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = m;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else							//当前位置有棋子
						{
							if (IsRed(currChessBoard[m][j]))		//不同阵营的时候添加一个节点
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = m;
								q->yEPos = j;
								q->next = NULL;
								p = q;
							}
							break;
						}
					}
					for (m = i + 1; m< 10; m++)	//向x增大方向循环
					{
						if (!currChessBoard[m][j])		//当前位置没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = m;
							q->ySPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//当前位置存在棋子
						{
							if (IsRed(currChessBoard[m][j]))	//不同阵营的时候添加一个节点	
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = m;
								q->yEPos = j;
								q->next = NULL;
								p = q;
							}
							break;
						}
					}
					for (m = j - 1; m >= 0; m--)		//向j减小方向循环
					{
						if (!currChessBoard[i][m])		//当前位置没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->ySPos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//当前位置存在棋子
						{
							if (IsRed(currChessBoard[i][m]))	//不同阵营的时候添加一个节点	
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i;
								q->yEPos = m;
								q->next = NULL;
								p = q;
							}
							break;
						}
					}
					for (m = j + 1; m<9; m++)		//向j增大方向循环
					{
						if (!currChessBoard[i][m])		//当前位置没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->ySPos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//当前位置存在棋子
						{
							if (IsRed(currChessBoard[i][m]))	//不同阵营的时候添加一个节点	
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i;
								q->yEPos = m;
								q->next = NULL;
								p = q;
							}
							break;
						}
					}
					break;

				case B_Horse:		//黑马
					if (i<8)		//向上走
					{
						if (!currChessBoard[i + 1][j])		//马蹄没有被拌
						{
							if (j>0 && (!IsBlack(currChessBoard[i + 2][j - 1])))		//向左上走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 2;
								q->yEPos = j - 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (j<9 && (!IsBlack(currChessBoard[i + 2][j + 1])))		//向右上走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 2;
								q->yEPos = j + 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (i>1)		//向下走
					{
						if (!currChessBoard[i - 1][j])		//马蹄没有被拌
						{
							if (j>0 && (!IsBlack(currChessBoard[i - 2][j - 1])))		//向左下走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 2;
								q->yEPos = j - 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (j<9 && (!IsBlack(currChessBoard[i - 2][j + 1])))		//向右下走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 2;
								q->yEPos = j + 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (j<7)		//向右走
					{
						if (!currChessBoard[i][j + 1])		//马蹄没有被拌
						{
							if (i>0 && (!IsBlack(currChessBoard[i - 1][j + 2])))		//向右下走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 1;
								q->yEPos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (i<9 && (!IsBlack(currChessBoard[i + 1][j + 2])))		//向右上走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 1;
								q->yEPos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (j>1)		//向左走
					{
						if (!currChessBoard[i][j - 1])
							if (i>0 && (!IsBlack(currChessBoard[i - 1][j - 2])))		//向左下走
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 1;
								q->yEPos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						if (i<9 && (!IsBlack(currChessBoard[i + 1][j - 2])))		//向左上走
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j - 2;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;

				case B_Canon:		//黑炮
					n = 0;
					for (m = i - 1; m >= 0; m--)			//向x减小方向循环
					{
						if ((!currChessBoard[m][j]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = m;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsRed(currChessBoard[m][j]))		//是红色棋子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = m;
									q->yEPos = j;
									q->next = NULL;
									p->next = q;
									p = q;
								}
								break;		//跳出当前循环
							}
						}
					}
					n = 0;
					for (m = i + 1; m <= 9; m++)		//沿x增大方向循环
					{
						if ((!currChessBoard[m][j]) && (n == 0))	//该点没有棋子并且起点和终点之间没有其他棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = m;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//该点有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsRed(currChessBoard[m][j]))		//是红色棋子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = m;
									q->yEPos = j;
									q->next = NULL;
									p->next = q;
									p = q;
								}
								break;	//跳出循环
							}
						}
					}
					n = 0;
					for (m = j - 1; m >= 0; m--)			//向y减小的方向循环
					{
						if ((!currChessBoard[i][m]) && (n == 0))		//这点没有棋子并且起点和终点之间没有棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else
						{
							n++;
							if (n == 2)
							{
								if (IsRed(currChessBoard[i][m]))		//是红色棋子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i;
									q->yEPos = m;
									q->next = NULL;
									p->next = q;
									p = q;
								}
								break;
							}
						}
					}
					n = 0;
					for (m = j + 1; m <= 8; m++)		//向y增大的方向循环
					{
						if ((!currChessBoard[i][m]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//该点有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsRed(currChessBoard[i][m]))
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i;
									q->yEPos = m;
									q->next = NULL;
									p->next = q;
									p = q;
								}
								break;
							}
						}
					}
					break;

				case B_Elephant:		//黑象
					if (i == 0)		//在最低线上
					{
						if (!currChessBoard[i + 1][j - 1])		//左上方象蹄没有被拌
						{
							if (!IsBlack(currChessBoard[i + 2][j - 2]))		//不是黑子
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 2;
								q->yEPos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
						if (!currChessBoard[i + 1][j + 1])		//右上方象蹄没有被拌
						{
							if (!IsBlack(currChessBoard[i + 2][j + 2]))	//不是黑子
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i + 2;
								q->yEPos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					else if (i == 2)	//在黑色阵营的中线上
					{
						if (j == 0 || j == 4)
						{
							if (!currChessBoard[i + 1][j + 1])		//右上方象蹄没有被拌
							{
								if (!IsBlack(currChessBoard[i + 2][j + 2]))	//不是黑子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i + 2;
									q->yEPos = j + 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
							if (!currChessBoard[i - 1][j + 1])		//右下方象蹄没有被拌
							{
								if (!IsBlack(currChessBoard[i - 2][j + 2]))			//不是黑子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i - 2;
									q->yEPos = j + 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
						}
						if (j == 4 || j == 8)
						{
							if (!currChessBoard[i + 1][j - 1])		//左上方象蹄没有被拌
							{
								if (!IsBlack(currChessBoard[i + 2][j - 2]))		//不是黑子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i + 2;
									q->yEPos = j - 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
							if (!currChessBoard[i - 1][j - 1])		//左下方象蹄没有被拌
							{
								if (!IsBlack(currChessBoard[i - 2][j - 2]))		//不是黑子
								{
									q = (MoveLink)malloc(sizeof(Move));
									q->xSPos = i;
									q->ySPos = j;
									q->xEPos = i - 2;
									q->yEPos = j - 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
						}

					}
					else		//i=5,在黑色阵营的最上线
					{
						if (!currChessBoard[i - 1][j - 1])	//左下象蹄没有被拌
						{
							if (!IsBlack(currChessBoard[i - 2][j - 2]))		//不是黑子
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 2;
								q->yEPos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
						if (!currChessBoard[i - 1][j + 1])	//右下方象蹄没有被拌
						{
							if (!IsBlack(currChessBoard[j - 2][j + 2]))	//不是黑子
							{
								q = (MoveLink)malloc(sizeof(Move));
								q->xSPos = i;
								q->ySPos = j;
								q->xEPos = i - 2;
								q->yEPos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					break;

				case B_Adviser:		//黑士
					if ((i + 1) <= 2 && (j + 1) <= 5)		//可以向右上走
					{
						if (!IsBlack(currChessBoard[i + 1][j + 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i + 1) <= 2 && (j - 1) >= 3)		//可以向左上走
					{
						if (!IsBlack(currChessBoard[i + 1][j - 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i - 1) >= 0 && (j + 1) <= 5)		//可以向右下走
					{
						if (!IsBlack(currChessBoard[i - 1][j + 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i - 1;
							q->yEPos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i - 1) >= 0 && (j - 1) >= 3)		//可以向左下走
					{
						if (!IsBlack(currChessBoard[i - 1][j - 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i - 1;
							q->yEPos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;

				case B_King:		//黑将
					if (i<2)		//可以向上走
					{
						if (!IsBlack(currChessBoard[i + 1][j]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (i>0)		//可以向下走
					{
						if (!IsBlack(currChessBoard[i - 1][j]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i - 1;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (j>3)		//可以向左走
					{
						if (!IsBlack(currChessBoard[i][j - 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (j<5)		//可以向右走
					{
						if (!IsBlack(currChessBoard[i][j + 1]))
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;
				case B_Pawn:
					if (i <= 4)		//还没有过河
					{
						if (!IsBlack(currChessBoard[i + 1][j]))		//向前走，目标不是黑子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					else		//过河了
					{
						if (!IsBlack(currChessBoard[i + 1][j])&&(i<9))		//向前走，目标不是黑子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i + 1;
							q->yEPos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						if (!IsBlack(currChessBoard[i][j-1]) && (j>0))		//向左走，目标不是黑子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = j-1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						if (!IsBlack(currChessBoard[i][j + 1]) && (j<8))		//向右走，目标不是黑子
						{
							q = (MoveLink)malloc(sizeof(Move));
							q->xSPos = i;
							q->ySPos = j;
							q->xEPos = i;
							q->yEPos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
				}
			}
		}
	}
	return Head;
}