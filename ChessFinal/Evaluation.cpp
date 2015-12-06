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
	LReleatedList Top = (LReleatedList)malloc(sizeof(LReleatedNode));
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
				if (ySPos<9)		//��������
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
				if (ySPos<9)		//��������
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
				if (xSPos<9)		//��������
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
			if (xSPos<9)		//��������
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
int Evaluation(int currChessBoard[][9])
{
	int sum;
	int Flex[10][9] = { 0 };		//����Լ�¼
	int Guard[10][9] = { 0 };		//�ܱ����ļ�¼
	int ChessValue[10][9] = { 0 };	//���ӵĹ�ֵ
	int i, j;			//ѭ��ʹ��
	int xchess,echess;
	LReleatedList top,q;
	int xEPos;
	int yEPos;
	int SumRValue;		//��ɫ���ܵĹ�ֵ
	int SumBValue;		//��ɫ���ܵĹ�ֵ
	//for (i = 0; i < 10; i++)
	//{ 
	//	for (j = 0; j < 9; j++)
	//	{
	//		xchess = currChessBoard[i][j];
	//		if (xchess != NO_CHESS)
	//		{
	//			top = GetReleatedPiece(currChessBoard, i, j);
	//			while (top != NULL)
	//			{
	//				q = PopReleatedMove(&top);
	//				xEPos = q->xEPos;
	//				yEPos = q->yEPos;
	//				free(q);
	//				echess = currChessBoard[xEPos][yEPos];
	//				if (echess == NO_CHESS)
	//				{
	//					Flex[i][j]++;		//���������
	//				}
	//				else
	//				{
	//					if (IsSameCol(xchess, echess))		//�����ͬһ�ߵ����Ӿ��ܱ���
	//					{
	//						Guard[xEPos][yEPos]++;
	//					}
	//					else			//��ͬ�ߵ�����
	//					{
	//						Flex[i][j]++;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			xchess = currChessBoard[i][j];
			if (xchess != NO_CHESS)
			{
				//ChessValue[i][j]++;		//������Ӵ����������ֵ��Ϊ0
				ChessValue[i][j] += m_BaseValue[xchess];			//���ϻ�����ֵ
				if (Guard[i][j])				//����������Ļ�
				{
					ChessValue[i][j] += m_BaseValue[xchess] / 16;
				}
				//ChessValue[i][j] += Flex[i][j] * m_FlexValue[xchess];		//��������ԵĹ�ֵ
				ChessValue[i][j] += GetBingValue(currChessBoard,i,j);			//���ϱ��Ĺ�ֵ
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
	return SumRValue - SumBValue;		//���ع�ֵ
}