#include "Evalution.h"
int GetBingValue(int currChessBoard[][9],int i, int j)
{
	if (currChessBoard[i][j] == B_Pawn)		//����Ǻڱ��Ļ����غڱ��ĸ���ֵ
	{
		return BAO[i][j];
	}
	if (currChessBoard[i][j] == R_Pawn)		//����Ǻ���Ļ����غ���ĸ���ֵ
	{
		return BA1[i][j];
	}
	return 0;
}
void PushReleatedMove(LReleatedList* top, int xEPos, int yEPos)		//��������Ĳ�����ջ
{
	LReleatedList p = (LReleatedList)malloc(sizeof(LReleatedNode));
	p->xEPos = xEPos;
	p->yEPos = yEPos;
	p->next = (*top);
	(*top) = p;
}
LReleatedList PopReleatedMove(LReleatedList* top)			//��������Ĳ�����ջ
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
		for (m = xSPos - 1; m >= 0; m--)		//��x��С������ѭ��
		{
			if (!currChessBoard[m][ySPos])			//��ǰλ��û������
			{
				PushReleatedMove(&Top, m, ySPos);
			}
			else							//��ǰλ��������
			{
				PushReleatedMove(&Top, m, ySPos);
				break;
			}
		}
		for (m = xSPos + 1; m< 10; m++)	//��x������ѭ��
		{
			if (!currChessBoard[m][ySPos])		//��ǰλ��û������
			{
				PushReleatedMove(&Top, m, ySPos);
			}
			else						//��ǰλ�ô�������
			{

				PushReleatedMove(&Top, m, ySPos);
				break;
			}
		}
		for (m = ySPos - 1; m >= 0; m--)		//��ySPos��С����ѭ��
		{
			if (!currChessBoard[xSPos][m])		//��ǰλ��û������
			{
				PushReleatedMove(&Top,xSPos, m);
			}
			else						//��ǰλ�ô�������
			{
				PushReleatedMove(&Top, xSPos, m);
				break;
			}
		}
		for (m = ySPos + 1; m<9; m++)		//��ySPos������ѭ��
		{
			if (!currChessBoard[xSPos][m])		//��ǰλ��û������
			{
				PushReleatedMove(&Top, xSPos, m);
			}
			else						//��ǰλ�ô�������
			{
				PushReleatedMove(&Top, xSPos, m);
				break;
			}
		}
		break;
	case B_Horse:
	case R_Horse:
		if (xSPos<8)		//������
		{
			if (!currChessBoard[xSPos + 1][ySPos])		//����û�б���
			{
				if (ySPos>0)		//��������
				{
					PushReleatedMove(&Top, xSPos+2, ySPos-1);
				}
				if (ySPos<8)		//��������
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos + 1);
				}
			}
		}
		if (xSPos>1)		//������
		{
			if (!currChessBoard[xSPos - 1][ySPos])		//����û�б���
			{
				if (ySPos>0)		//��������
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos - 1);
				}
				if (ySPos<8)		//��������
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos + 1);
				}
			}
		}
		if (ySPos<7)		//������
		{
			if (!currChessBoard[xSPos][ySPos + 1])		//����û�б���
			{
				if (xSPos>0)		//��������
				{
					PushReleatedMove(&Top, xSPos -1, ySPos +2 );
				}
				if (xSPos<8)		//��������
				{
					PushReleatedMove(&Top, xSPos + 1, ySPos + 2);
				}
			}
		}
		if (ySPos>1)		//������
		{
			if (!currChessBoard[xSPos][ySPos - 1])
				if (xSPos>0)		//��������
				{
					PushReleatedMove(&Top, xSPos - 1, ySPos - 2);
				}
			if (xSPos<8)		//��������
			{
				PushReleatedMove(&Top, xSPos + 1, ySPos - 2);
			}
		}
		break;
	case B_Canon:		//����
	case R_Canon:
		n = 0;
		for (m = xSPos - 1; m >= 0; m--)			//��x��С����ѭ��
		{
			if ((!currChessBoard[m][ySPos]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
			{
				PushReleatedMove(&Top, m, ySPos);
			}
			else		//������
			{
				n++;
				if (n == 2)
				{
					PushReleatedMove(&Top, m, ySPos);
					break;		//������ǰѭ��
				}
			}
		}
		n = 0;
		for (m = xSPos + 1; m <= 9; m++)		//��x������ѭ��
		{
			if ((!currChessBoard[m][ySPos]) && (n == 0))	//�õ�û�����Ӳ��������յ�֮��û����������
			{
				PushReleatedMove(&Top, m, ySPos);
			}
			else		//�õ�������
			{
				n++;
				if (n == 2)
				{
					PushReleatedMove(&Top, m, ySPos);
					break;	//����ѭ��
				}
			}
		}
		n = 0;
		for (m = ySPos - 1; m >= 0; m--)			//��y��С�ķ���ѭ��
		{
			if ((!currChessBoard[xSPos][m]) && (n == 0))		//���û�����Ӳ��������յ�֮��û������
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
		for (m = ySPos + 1; m <= 8; m++)		//��y����ķ���ѭ��
		{
			if ((!currChessBoard[xSPos][m]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
			{
				PushReleatedMove(&Top, xSPos, m);
			}
			else		//�õ�������
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
	case B_Elephant:		//����
		if (xSPos == 0)		//���������
		{
			if (!currChessBoard[xSPos + 1][ySPos - 1])		//���Ϸ�����û�б���
			{
				PushReleatedMove(&Top, xSPos+2, ySPos-2);
			}
			if (!currChessBoard[xSPos + 1][ySPos + 1])		//���Ϸ�����û�б���
			{
				PushReleatedMove(&Top, xSPos + 2, ySPos + 2);
			}
		}
		else if (xSPos == 2)	//�ں�ɫ��Ӫ��������
		{
			if (ySPos == 0 || ySPos == 4)
			{
				if (!currChessBoard[xSPos + 1][ySPos + 1])		//���Ϸ�����û�б���
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos + 2);
				}
				if (!currChessBoard[xSPos - 1][ySPos + 1])		//���·�����û�б���
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos + 2);
				}
			}
			if (ySPos == 4 || ySPos == 8)
			{
				if (!currChessBoard[xSPos + 1][ySPos - 1])		//���Ϸ�����û�б���
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos - 2);
				}
				if (!currChessBoard[xSPos - 1][ySPos - 1])		//���·�����û�б���
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos - 2);
				}
			}

		}
		else		//xSPos=5,�ں�ɫ��Ӫ��������
		{
			if (!currChessBoard[xSPos - 1][ySPos - 1])	//��������û�б���
			{
				PushReleatedMove(&Top, xSPos - 2, ySPos - 2);
			}
			if (!currChessBoard[xSPos - 1][ySPos + 1])	//���·�����û�б���
			{
				PushReleatedMove(&Top, xSPos - 2, ySPos + 2);
			}
		}
		break;
	case R_Elephant:		//����
		if (xSPos == 5)		//�����ɫ��Ӫ���������
		{
			if (!currChessBoard[xSPos + 1][ySPos - 1])		//���Ϸ�����û�б���
			{
				PushReleatedMove(&Top, xSPos + 2, ySPos - 2);
			}
			if (!currChessBoard[xSPos + 1][ySPos + 1])		//���Ϸ�����û�б���
			{
				PushReleatedMove(&Top, xSPos + 2, ySPos + 2);
			}
		}
		else if (xSPos == 7)	//�ں�ɫ��Ӫ��������
		{
			if (ySPos == 0 || ySPos == 4)
			{
				if (!currChessBoard[xSPos + 1][ySPos + 1])		//���Ϸ�����û�б���
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos + 2);
				}
				if (!currChessBoard[xSPos - 1][ySPos + 1])		//���·�����û�б���
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos + 2);
				}
			}
			if (ySPos == 4 || ySPos == 8)
			{
				if (!currChessBoard[xSPos + 1][ySPos - 1])		//���Ϸ�����û�б���
				{
					PushReleatedMove(&Top, xSPos + 2, ySPos - 2);
				}
				if (!currChessBoard[xSPos - 1][ySPos - 1])		//���·�����û�б���
				{
					PushReleatedMove(&Top, xSPos - 2, ySPos - 2);
				}
			}

		}
		else		//xSPos=9,�ں�ɫ��Ӫ��������
		{
			if (!currChessBoard[xSPos - 1][ySPos - 1])	//��������û�б���
			{
				PushReleatedMove(&Top, xSPos - 2, ySPos - 2);
			}
			if (!currChessBoard[xSPos - 1][ySPos + 1])	//���·�����û�б���
			{
				PushReleatedMove(&Top, xSPos - 2, ySPos + 2);
			}
		}
		break;
	case B_Adviser:		//��ʿ
		if ((xSPos + 1) <= 2 && (ySPos + 1) <= 5)		//������������
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos + 1);
		}
		if ((xSPos + 1) <= 2 && (ySPos - 1) >= 3)		//������������
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos - 1);
		}
		if ((xSPos - 1) >= 0 && (ySPos + 1) <= 5)		//������������
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos + 1);
		}
		if ((xSPos - 1) >= 0 && (ySPos - 1) >= 3)		//������������
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos - 1);
		}
		break;
	case R_Adviser:		//��ʿ
		if ((xSPos + 1) <= 9 && (ySPos + 1) <= 5)		//������������
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos + 1);
		}
		if ((xSPos + 1) <= 9 && (ySPos - 1) >= 3)		//������������
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos - 1);
		}
		if ((xSPos - 1) >= 7 && (ySPos + 1) <= 5)		//������������
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos + 1);
		}
		if ((xSPos - 1) >= 7 && (ySPos - 1) >= 3)		//������������
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos - 1);
		}
		break;
	case B_King:		//�ڽ�
		if (xSPos<2)		//����������
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos );
		}
		if (xSPos>0)		//����������
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos);
		}
		if (ySPos>3)		//����������
		{
			PushReleatedMove(&Top, xSPos, ySPos-1);
		}
		if (ySPos<5)		//����������
		{
			PushReleatedMove(&Top, xSPos, ySPos + 1);
		}
		break;
	case R_King:
		if (xSPos<9)		//����������
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos);
		}
		if (xSPos>7)		//����������
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos);
		}
		if (ySPos>3)		//����������
		{
			PushReleatedMove(&Top, xSPos, ySPos - 1);
		}
		if (ySPos<5)		//����������
		{
			PushReleatedMove(&Top, xSPos, ySPos + 1);
		}
		break;
	case R_Pawn:
		if (xSPos >= 5)		//��û�й���
		{
			PushReleatedMove(&Top, xSPos - 1, ySPos);
		}
		else			//�Ѿ����˺�
		{
			if (xSPos > 0)		//����������
			{
				PushReleatedMove(&Top, xSPos - 1, ySPos);
			}
			if (ySPos > 0)	//����������
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
		if (xSPos <= 4)		//��û�й���
		{
			PushReleatedMove(&Top, xSPos + 1, ySPos);
		}
		else
		{
			if (xSPos < 9)		//������
			{
				PushReleatedMove(&Top, xSPos + 1, ySPos);
			}
			if (ySPos > 0)			//����������
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
	int Flex[10][9] = { 0 };		//����Լ�¼
	int Guard[10][9] = { 0 };		//�ܱ����ļ�¼
	int Attack[10][9] = { 0 };		//�ܹ����ļ�¼
	int ChessValue[10][9] = { 0 };	//���ӵĹ�ֵ
	int i, j;			//ѭ��ʹ��
	int nHalfValue;
	int xchess, echess;
	LReleatedList top, p;
	int xEPos;
	int yEPos;
	int SumRValue;		//��ɫ���ܵĹ�ֵ
	int SumBValue;		//��ɫ���ܵĹ�ֵ
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
					Flex[i][j]++;		//���������
				}
				else
				{
					if (IsSameCol(xchess, echess))		//�����ͬһ�ߵ����Ӿ��ܱ���
					{
						Guard[xEPos][yEPos]++;
					}
					else			//��ͬ�ߵ�����
					{
						Flex[i][j]++;
						Attack[xEPos][yEPos]++;
						switch (echess)
						{
						case B_King:		//�Ǻڽ�
							if (IsRedTurn)		//�ú�������
							{
								return 18888;
							}
						case R_King:		//�콫
							if (!IsRedTurn)		//�ú�������
							{
								return 18888;
							}
						default:
							Attack[xEPos][yEPos] += (30 + (m_BaseValue[echess] - m_BaseValue[xchess]) / 10) / 10;		//������в������в�ķ�ֵ
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
				ChessValue[i][j]++;		//������Ӵ����������ֵ��Ϊ0
				ChessValue[i][j] += Flex[i][j] * m_FlexValue[xchess];		//��������ԵĹ�ֵ
				ChessValue[i][j] += GetBingValue(currChessBoard,i, j);			//���ϱ��Ĺ�ֵ
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
				if (IsRed(xchess))		//����Ǻ�ɫ���ӵĻ�
				{
					if (Attack[i][j])	//��������ӱ���в�Ļ�
					{
						if (IsRedTurn)		//�ĺ�ɫ��������
						{
							if (xchess == R_King)		//����Ǻ콫�Ļ�
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
						else		//��ɫ���ӱ���в�ú�������
						{
							if (xchess == R_King)		//�������в�������Ǻ콫�Ļ���ֱ��ʧ��
							{
								return 18888;		//ֱ�ӷ���ʧ�ܵ����ֵ
							}
							else
							{
								ChessValue[i][j] -= nHalfValue * 10;		//��ʾ����в�̶ȷǳ���
								if (Guard[i][j])
								{
									ChessValue[i][j] += nHalfValue * 9;
								}
							}
						}
						ChessValue[i][j] -= Attack[i][j];		//��ֹһ������вһ��������ֵ����û�з�Ӧ�������
					}
					else			//���������в�Ļ�
					{
						if (Guard[i][j])
						{
							ChessValue[i][j] += 5;
						}
					}
				}
				else		//����Ǻ�ɫ����
				{
					if (Attack[i][j])
					{
						if (IsRedTurn)
						{
							if (xchess == B_King)		//����Ǻڽ��Ļ�
							{
								return 18888;		//����ʧ�ܵ����ֵ
							}
							else
							{
								ChessValue[i][j] -= nHalfValue * 10;	//��ʾ����в�ĳ̶Ⱥܴ�
								if (Guard[i][j])
								{
									ChessValue[i][j] += nHalfValue * 9;
								}
							}
						}
						else		//������Ǹú�ɫ�����ߵĻ�
						{
							if (xchess == B_King)		//����Ǻڽ��Ļ�
							{
								ChessValue[i][j] -= 20;
							}
							else
							{
								ChessValue[i][j] -= nHalfValue * 2;
								if (Guard[i][j])		//������ܱ����Ļ�
								{
									ChessValue[i][j] += nHalfValue;
								}
							}
						}
						ChessValue[i][j] -= Attack[i][j];	//��ֹ�Ը�����вһ��������ֵ����û�з�Ӧ����
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