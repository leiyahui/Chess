#include "Evalution.h"
int GetBingValue(int x, int y, int position[][9])
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
	Head->next = NULL;
	LReleatedList p = Head;
	LReleatedList q;
	int chess = currChessBoard[xSPos][ySPos];
	if (chess == NO_CHESS)
	{
		return Head;
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
	case R_Pawn:
		if (xSPos >= 5)		//��û�й���
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));		//����������
			q->xEPos = xSPos - 1;
			q->yEPos = ySPos;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		else			//�Ѿ����˺�
		{
			if (xSPos > 0)		//����������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));		//����������
				q->xEPos = xSPos - 1;
				q->yEPos = ySPos;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			if (ySPos > 0)	//����������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));		//����������
				q->xEPos = xSPos;
				q->yEPos = ySPos - 1;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			if (ySPos < 8)
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));		//����������
				q->xEPos = xSPos;
				q->yEPos = ySPos + 1;
				q->next = NULL;
				p->next = q;
				p = q;
			}
		}
		break;
	case B_Pawn:
		if (xSPos <= 4)		//��û�й���
		{
			q = (LReleatedList)malloc(sizeof(LReleatedNode));		//����������
			q->xEPos = xSPos + 1;
			q->yEPos = ySPos;
			q->next = NULL;
			p->next = q;
			p = q;
		}
		else
		{
			if (xSPos < 9)		//������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));		//����������
				q->xEPos = xSPos + 1;
				q->yEPos = ySPos;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			if (ySPos > 0)			//����������
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));		//����������
				q->xEPos = xSPos;
				q->yEPos = ySPos-1;
				q->next = NULL;
				p->next = q;
				p = q;
			}
			if (ySPos < 8)
			{
				q = (LReleatedList)malloc(sizeof(LReleatedNode));		//����������
				q->xEPos = xSPos;
				q->yEPos = ySPos + 1;
				q->next = NULL;
				p->next = q;
				p = q;
			}
		}
		break;
	}
	return Head;
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
	int xchess,echess;
	LReleatedList p;
	int xEPos;
	int yEPos;
	int SumRValue;		//��ɫ���ܵĹ�ֵ
	int SumBValue;		//��ɫ���ܵĹ�ֵ
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
			if (xchess != NO_CHESS)
			{
				ChessValue[i][j]++;		//������Ӵ����������ֵ��Ϊ0
				ChessValue[i][j] += Flex[i][j] * m_FlexValue[xchess];		//��������ԵĹ�ֵ
				ChessValue[i][j] += GetBingValue(i, j, currChessBoard);			//���ϱ��Ĺ�ֵ
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
				nHalfValue = m_BaseValue[xchess]/16;
				ChessValue[i][j] += nHalfValue;
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
	SumBValue = SumRValue = 0;		//����ֵΪ0
	for (i = 0; i < 10;i++)
	{
		for (j = 0; j < 9; j++)
		{
			xchess = currChessBoard[i][j];
			if (xchess != NO_CHESS)
			{
				if (IsRed(xchess))
				{
					SumRValue += ChessValue[i][j];		//����ɫ���ӵ���ֵ���
				}
				else
				{
					SumBValue += ChessValue[i][j];		//����ɫ���ܵ���ֵ���
				}
			}
		}
	}
	if (IsRedTurn)
	{
		return SumRValue - SumBValue;			//�ֵ������߷��ع�ֵ
	}
	else
	{
		return SumBValue - SumRValue;		//�ֵ������߷��ع�ֵ���෴��
	}

}