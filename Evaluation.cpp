#include "Evalution.h"
int GetBingValue(int x, int y, int position[10][9])
{
	if (position[y][x] = B_Pawn)
		return BAO[y][x];
	if (position[y][x] = R_Pawn)
		return BA1[y][x];
	return 0;
}
LReleatedList GetReleatedPiece(int currChessBoard[][9], int xSPos, int ySPos)
{
	int m, n;
	LReleatedList Head = (LReleatedList)malloc(sizeof(LReleatedNode));
	LReleatedList p = Head;
	LReleatedList q;
	int chess = currChessBoard[xSPos][ySPos];
	if (chess == NO_CHESS)
	{
		return NULL;
	}
	switch (chess)
	{
	case B_Chariot:
	case R_Chariot:
		for (m = xSPos - 1; m >= 0; m--)		//��x��С������ѭ��
		{
			if (!currChessBoard[m][ySPos])			//��ǰλ��û������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = m;
				q->yEPos = ySPos;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			else							//��ǰλ��������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = m;
				q->yEPos = ySPos;
				q->next = NULL;
				p = q;
				break;
			}
		}
		for (m = xSPos + 1; m< 10; m++)	//��x������ѭ��
		{
			if (!currChessBoard[m][ySPos])		//��ǰλ��û������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = m;
				q->yEPos = ySPos;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			else						//��ǰλ�ô�������
			{

				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = m;
				q->yEPos = ySPos;
				q->next = NULL;
				p = q;
				break;
			}
		}
		for (m = ySPos - 1; m >= 0; m--)		//��ySPos��С����ѭ��
		{
			if (!currChessBoard[xSPos][m])		//��ǰλ��û������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos;
				q->yEPos = m;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			else						//��ǰλ�ô�������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos;
				q->yEPos = m;
				q->next = NULL;
				p = q;
				break;
			}
		}
		for (m = ySPos + 1; m<9; m++)		//��ySPos������ѭ��
		{
			if (!currChessBoard[xSPos][m])		//��ǰλ��û������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos;
				q->yEPos = m;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			else						//��ǰλ�ô�������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos;
				q->yEPos = m;
				q->next = NULL;
				p = q;
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
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos + 2;
					q->yEPos = ySPos - 1;
					q->next = NULL;
					p->next = q;
					p = q;
				}
				if (ySPos<9)		//��������
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos + 2;
					q->yEPos = ySPos + 1;
					q->next = NULL;
					p->next = q;
					p = q;
				}
			}
		}
		if (xSPos>1)		//������
		{
			if (!currChessBoard[xSPos - 1][ySPos])		//����û�б���
			{
				if (ySPos>0)		//��������
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos - 2;
					q->yEPos = ySPos - 1;
					q->next = NULL;
					p->next = q;
					p = q;
				}
				if (ySPos<9)		//��������
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos - 2;
					q->yEPos = ySPos + 1;
					q->next = NULL;
					p->next = q;
					p = q;
				}
			}
		}
		if (ySPos<7)		//������
		{
			if (!currChessBoard[xSPos][ySPos + 1])		//����û�б���
			{
				if (xSPos>0)		//��������
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos - 1;
					q->yEPos = ySPos + 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
				if (xSPos<9)		//��������
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos + 1;
					q->yEPos = ySPos + 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
			}
		}
		if (ySPos>1)		//������
		{
			if (!currChessBoard[xSPos][ySPos - 1])
				if (xSPos>0)		//��������
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos - 1;
					q->yEPos = ySPos - 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
			if (xSPos<9)		//��������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos + 1;
				q->yEPos = ySPos - 2;
				q->next = NULL;
				p->next = q;
				p = q;
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
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = m;
				q->yEPos = ySPos;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			else		//������
			{
				n++;
				if (n == 2)
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = m;
					q->yEPos = ySPos;
					q->next = NULL;
					p->next = q;
					p = q;
					break;		//������ǰѭ��
				}
			}
		}
		n = 0;
		for (m = xSPos + 1; m <= 9; m++)		//��x������ѭ��
		{
			if ((!currChessBoard[m][ySPos]) && (n == 0))	//�õ�û�����Ӳ��������յ�֮��û����������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = m;
				q->yEPos = ySPos;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			else		//�õ�������
			{
				n++;
				if (n == 2)
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = m;
					q->yEPos = ySPos;
					q->next = NULL;
					p->next = q;
					p = q;
					break;	//����ѭ��
				}
			}
		}
		n = 0;
		for (m = ySPos - 1; m >= 0; m--)			//��y��С�ķ���ѭ��
		{
			if ((!currChessBoard[xSPos][m]) && (n == 0))		//���û�����Ӳ��������յ�֮��û������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos;
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
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos;
					q->yEPos = m;
					q->next = NULL;
					p->next = q;
					p = q;
					break;
				}
			}
		}
		n = 0;
		for (m = ySPos + 1; m <= 8; m++)		//��y����ķ���ѭ��
		{
			if ((!currChessBoard[xSPos][m]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos;
				q->yEPos = m;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			else		//�õ�������
			{
				n++;
				if (n == 2)
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos;
					q->yEPos = m;
					q->next = NULL;
					p->next = q;
					p = q;
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
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos + 2;
				q->yEPos = ySPos - 2;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			if (!currChessBoard[xSPos + 1][ySPos + 1])		//���Ϸ�����û�б���
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos + 2;
				q->yEPos = ySPos + 2;
				q->next = NULL;
				p->next = q;
				p = q;
			}
		}
		else if (xSPos == 2)	//�ں�ɫ��Ӫ��������
		{
			if (ySPos == 0 || ySPos == 4)
			{
				if (!currChessBoard[xSPos + 1][ySPos + 1])		//���Ϸ�����û�б���
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos + 2;
					q->yEPos = ySPos + 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
				if (!currChessBoard[xSPos - 1][ySPos + 1])		//���·�����û�б���
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos - 2;
					q->yEPos = ySPos + 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
			}
			if (ySPos == 4 || ySPos == 8)
			{
				if (!currChessBoard[xSPos + 1][ySPos - 1])		//���Ϸ�����û�б���
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos + 2;
					q->yEPos = ySPos - 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
				if (!currChessBoard[xSPos - 1][ySPos - 1])		//���·�����û�б���
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos - 2;
					q->yEPos = ySPos - 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
			}

		}
		else		//xSPos=5,�ں�ɫ��Ӫ��������
		{
			if (!currChessBoard[xSPos - 1][ySPos - 1])	//��������û�б���
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos - 2;
				q->yEPos = ySPos - 2;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			if (!currChessBoard[xSPos - 1][ySPos + 1])	//���·�����û�б���
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos - 2;
				q->yEPos = ySPos + 2;
				q->next = NULL;
				p->next = q;
				p = q;
			}
		}
		break;
	case R_Elephant:		//����
		if (xSPos == 5)		//�����ɫ��Ӫ���������
		{
			if (!currChessBoard[xSPos + 1][ySPos - 1])		//���Ϸ�����û�б���
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos + 2;
				q->yEPos = ySPos - 2;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			if (!currChessBoard[xSPos + 1][ySPos + 1])		//���Ϸ�����û�б���
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos + 2;
				q->yEPos = ySPos + 2;
				q->next = NULL;
				p->next = q;
				p = q;
			}
		}
		else if (xSPos == 7)	//�ں�ɫ��Ӫ��������
		{
			if (ySPos == 0 || ySPos == 4)
			{
				if (!currChessBoard[xSPos + 1][ySPos + 1])		//���Ϸ�����û�б���
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos + 2;
					q->yEPos = ySPos + 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
				if (!currChessBoard[xSPos - 1][ySPos + 1])		//���·�����û�б���
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos - 2;
					q->yEPos = ySPos + 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
			}
			if (ySPos == 4 || ySPos == 8)
			{
				if (!currChessBoard[xSPos + 1][ySPos - 1])		//���Ϸ�����û�б���
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos + 2;
					q->yEPos = ySPos - 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
				if (!currChessBoard[xSPos - 1][ySPos - 1])		//���·�����û�б���
				{
					q = (LReleatedList)malloc(sizeof(LReleatedNode));
					q->xEPos = xSPos - 2;
					q->yEPos = ySPos - 2;
					q->next = NULL;
					p->next = q;
					p = q;
				}
			}

		}
		else		//xSPos=9,�ں�ɫ��Ӫ��������
		{
			if (!currChessBoard[xSPos - 1][ySPos - 1])	//��������û�б���
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos - 2;
				q->yEPos = ySPos - 2;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			if (!currChessBoard[xSPos - 1][ySPos + 1])	//���·�����û�б���
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));
				q->xEPos = xSPos - 2;
				q->yEPos = ySPos + 2;
				q->next = NULL;
				p->next = q;
				p = q;
			}
		}
		break;
	case B_Adviser:		//��ʿ
		if ((xSPos + 1) <= 2 && (ySPos + 1) <= 5)		//������������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos + 1;
			q->yEPos = ySPos + 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if ((xSPos + 1) <= 2 && (ySPos - 1) >= 3)		//������������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos + 1;
			q->yEPos = ySPos - 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if ((xSPos - 1) >= 0 && (ySPos + 1) <= 5)		//������������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos - 1;
			q->yEPos = ySPos + 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if ((xSPos - 1) >= 0 && (ySPos - 1) >= 3)		//������������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos - 1;
			q->yEPos = ySPos - 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		break;
	case R_Adviser:		//��ʿ
		if ((xSPos + 1) <= 9 && (ySPos + 1) <= 5)		//������������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos + 1;
			q->yEPos = ySPos + 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if ((xSPos + 1) <= 9 && (ySPos - 1) >= 3)		//������������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos + 1;
			q->yEPos = ySPos - 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if ((xSPos - 1) >= 7 && (ySPos + 1) <= 5)		//������������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos - 1;
			q->yEPos = ySPos + 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if ((xSPos - 1) >= 7 && (ySPos - 1) >= 3)		//������������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos - 1;
			q->yEPos = ySPos - 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		break;
	case B_King:		//�ڽ�
		if (xSPos<2)		//����������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos + 1;
			q->yEPos = ySPos;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if (xSPos>0)		//����������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos - 1;
			q->yEPos = ySPos;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if (ySPos>3)		//����������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos;
			q->yEPos = ySPos - 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if (ySPos<5)		//����������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos;
			q->yEPos = ySPos + 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		break;
	case R_King:
		if (xSPos<9)		//����������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos + 1;
			q->yEPos = ySPos;
			q->next = NULL;
			p->next = q;
			q = q;
		}
		if (xSPos>7)		//����������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos - 1;
			q->yEPos = ySPos;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if (ySPos>3)		//����������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos;
			q->yEPos = ySPos - 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		if (ySPos<5)		//����������
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));
			q->xEPos = xSPos;
			q->yEPos = ySPos + 1;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		break;
	}
	return Head;
}
int Evaluation(int currChessBoard[][9], bool IsRedTurn)
{
	int sum;
	int Flex[10][9] = { 0 };
	int Guard[10][9] = { 0 };
	int Attack[10][9] = { 0 };
	int i, j;
	int xchess,echess;
	LReleatedList p;
	int xEPos;
	int yEPos;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			xchess = currChessBoard[i][j];
			p = GetReleatedPiece(currChessBoard, i, j);
			if (p->next != NULL)
			{
				p = p->next;
				xEPos = p->xEPos;
				yEPos = p->yEPos;
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
			if (xchess != NULL)
			{
				currChessBoard[i][j]++;		//��ֵ
				currChessBoard[i][j] += Flex[i][j];
				currChessBoard[i][j] += Flex[i][j];
				
			}
		}
	}
}