#include "MoveGenerator.h"

MoveLink MoveGenerator(int currChessBoard[][9], int redTurn)		//�߷�������,i=0�ú����ߣ�����ú�����
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
				case NO_CHESS:		//û������
					break;
				case R_Chariot:		//�쳵
					for (m = i - 1; m >= 0; m--)		//��x��С������ѭ��
					{
						if (!currChessBoard[m][j])			//��ǰλ��û������
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
						else							//��ǰλ��������
						{
							if (IsBlack(currChessBoard[m][j]))		//��ͬ��Ӫ��ʱ�����һ���ڵ�
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
					for (m = i + 1; m < 10; m++)	//��x������ѭ��
					{
						if (!currChessBoard[m][j])		//��ǰλ��û������
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
						else						//��ǰλ�ô�������
						{
							if (IsBlack(currChessBoard[m][j]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
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
					for (m = j - 1; m >= 0; m--)		//��j��С����ѭ��
					{
						if (!currChessBoard[i][m])		//��ǰλ��û������
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
						else						//��ǰλ�ô�������
						{
							if (IsBlack(currChessBoard[i][m]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
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
					for (m = j + 1; m<9; m++)		//��j������ѭ��
					{
						if (!currChessBoard[i][m])		//��ǰλ��û������
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
						else						//��ǰλ�ô�������
						{
							if (IsBlack(currChessBoard[i][m]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
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

				case R_Horse:		//����
					if (i<8)		//������
					{
						if (!currChessBoard[i + 1][j])		//����û�б���
						{
							if (j>0 && (!IsRed(currChessBoard[i + 2][j - 1])))		//��������
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
							if (j<9 && (!IsRed(currChessBoard[i + 2][j + 1])))		//��������
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
					if (i>1)		//������
					{
						if (!currChessBoard[i - 1][j])		//����û�б���
						{
							if (j>0 && (!IsRed(currChessBoard[i - 2][j - 1])))		//��������
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
							if (j<9 && (!IsRed(currChessBoard[i - 2][j + 1])))		//��������
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
					if (j<7)		//������
					{
						if (!currChessBoard[i][j + 1])		//����û�б���
						{
							if (i>0 && (!IsRed(currChessBoard[i - 1][j + 2])))		//��������
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
							if (i<9 && (!IsRed(currChessBoard[i + 1][j + 2])))		//��������
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
					if (j>1)		//������
					{
						if (!currChessBoard[i][j - 1])
							if (i>0 && (!IsRed(currChessBoard[i - 1][j - 2])))		//��������
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
						if (i<9 && (!IsRed(currChessBoard[i + 1][j - 2])))		//��������
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

				case R_Canon:		//����
					n = 0;
					for (m = i - 1; m >= 0; m--)			//��x��С����ѭ��
					{
						if ((!currChessBoard[m][j]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
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
						else		//������
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(currChessBoard[m][j]))		//�Ǻ�ɫ����
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
								break;		//������ǰѭ��
							}
						}
					}
					n = 0;
					for (m = i + 1; m <= 9; m++)		//��x������ѭ��
					{
						if ((!currChessBoard[m][j]) && (n == 0))	//�õ�û�����Ӳ��������յ�֮��û����������
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
						else		//�õ�������
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(currChessBoard[m][j]))		//�Ǻ�ɫ����
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
								break;	//����ѭ��
							}
						}
					}
					n = 0;
					for (m = j - 1; m >= 0; m--)			//��y��С�ķ���ѭ��
					{
						if ((!currChessBoard[i][m]) && (n == 0))		//���û�����Ӳ��������յ�֮��û������
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
								if (IsBlack(currChessBoard[i][m]))		//�Ǻ�ɫ����
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
					for (m = j + 1; m <= 8; m++)		//��y����ķ���ѭ��
					{
						if ((!currChessBoard[i][m]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
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
						else		//�õ�������
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

				case R_Elephant:		//����
					if (i == 5)		//�����ɫ��Ӫ���������
					{
						if (!currChessBoard[i + 1][j - 1])		//���Ϸ�����û�б���
						{
							if (!IsRed(currChessBoard[i + 2][j - 2]))		//���Ǻ���
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
						if (!currChessBoard[i + 1][j + 1])		//���Ϸ�����û�б���
						{
							if (!IsRed(currChessBoard[i + 2][j + 2]))		//���Ǻ���
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
					else if (i == 7)	//�ں�ɫ��Ӫ��������
					{
						if (j == 0 || j == 4)
						{
							if (!currChessBoard[i + 1][j + 1])		//���Ϸ�����û�б���
							{
								if (!IsRed(currChessBoard[i + 2][j + 2]))	//���Ǻ���
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
							if (!currChessBoard[i - 1][j + 1])		//���·�����û�б���
							{
								if (!IsRed(currChessBoard[i - 2][j + 2]))			//���Ǻ���
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
							if (!currChessBoard[i + 1][j - 1])		//���Ϸ�����û�б���
							{
								if (!IsRed(currChessBoard[i + 2][j - 2]))		//���Ǻ���
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
							if (!currChessBoard[i - 1][j - 1])		//���·�����û�б���
							{
								if (!IsRed(currChessBoard[i - 2][j - 2]))		//���Ǻ���
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
					else		//i=9,�ں�ɫ��Ӫ��������
					{
						if (!currChessBoard[i - 1][j - 1])	//��������û�б���
						{
							if (!IsRed(currChessBoard[i - 2][j - 2]))		//���Ǻ���
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
						if (!currChessBoard[i - 1][j + 1])	//���·�����û�б���
						{
							if (!IsRed(currChessBoard[j - 2][j + 2]))	//���Ǻ���
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

				case R_Adviser:		//��ʿ
					if ((i + 1) <= 9 && (j + 1) <= 5)		//������������
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
					if ((i + 1) <= 9 && (j - 1) >= 3)		//������������
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
					if ((i - 1) >= 7 && (j + 1) <= 5)		//������������
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
					if ((i - 1) >= 7 && (j - 1) >= 3)		//������������
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
					if (i<9)		//����������
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
					if (i>7)		//����������
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
					if (j>3)		//����������
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
					if (j<5)		//����������
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
				case R_Pawn:		//���
					if (i >= 5)
					{
						if (!IsRed(currChessBoard[i - 1][j]))	//��ǰ��,Ŀ�겻�Ǻ���
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
						if (!IsRed(currChessBoard[i - 1][j])&&(i>0)) //��ǰ�ߣ�Ŀ�겻�Ǻ���
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
						if (!IsRed(currChessBoard[i][j-1]) && (j>0))//�����ߣ�Ŀ�겻�Ǻ���
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
						if (!IsRed(currChessBoard[i][j + 1]) && (j<8))//���ң�Ŀ�겻�Ǻ���
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
				case NO_CHESS:		//û������
					break;
				case B_Chariot:		//�ڳ�
					for (m = i - 1; m >= 0; m--)		//��x��С������ѭ��
					{
						if (!currChessBoard[m][j])			//��ǰλ��û������
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
						else							//��ǰλ��������
						{
							if (IsRed(currChessBoard[m][j]))		//��ͬ��Ӫ��ʱ�����һ���ڵ�
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
					for (m = i + 1; m< 10; m++)	//��x������ѭ��
					{
						if (!currChessBoard[m][j])		//��ǰλ��û������
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
						else						//��ǰλ�ô�������
						{
							if (IsRed(currChessBoard[m][j]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
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
					for (m = j - 1; m >= 0; m--)		//��j��С����ѭ��
					{
						if (!currChessBoard[i][m])		//��ǰλ��û������
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
						else						//��ǰλ�ô�������
						{
							if (IsRed(currChessBoard[i][m]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
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
					for (m = j + 1; m<9; m++)		//��j������ѭ��
					{
						if (!currChessBoard[i][m])		//��ǰλ��û������
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
						else						//��ǰλ�ô�������
						{
							if (IsRed(currChessBoard[i][m]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
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

				case B_Horse:		//����
					if (i<8)		//������
					{
						if (!currChessBoard[i + 1][j])		//����û�б���
						{
							if (j>0 && (!IsBlack(currChessBoard[i + 2][j - 1])))		//��������
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
							if (j<9 && (!IsBlack(currChessBoard[i + 2][j + 1])))		//��������
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
					if (i>1)		//������
					{
						if (!currChessBoard[i - 1][j])		//����û�б���
						{
							if (j>0 && (!IsBlack(currChessBoard[i - 2][j - 1])))		//��������
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
							if (j<9 && (!IsBlack(currChessBoard[i - 2][j + 1])))		//��������
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
					if (j<7)		//������
					{
						if (!currChessBoard[i][j + 1])		//����û�б���
						{
							if (i>0 && (!IsBlack(currChessBoard[i - 1][j + 2])))		//��������
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
							if (i<9 && (!IsBlack(currChessBoard[i + 1][j + 2])))		//��������
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
					if (j>1)		//������
					{
						if (!currChessBoard[i][j - 1])
							if (i>0 && (!IsBlack(currChessBoard[i - 1][j - 2])))		//��������
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
						if (i<9 && (!IsBlack(currChessBoard[i + 1][j - 2])))		//��������
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

				case B_Canon:		//����
					n = 0;
					for (m = i - 1; m >= 0; m--)			//��x��С����ѭ��
					{
						if ((!currChessBoard[m][j]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
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
						else		//������
						{
							n++;
							if (n == 2)
							{
								if (IsRed(currChessBoard[m][j]))		//�Ǻ�ɫ����
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
								break;		//������ǰѭ��
							}
						}
					}
					n = 0;
					for (m = i + 1; m <= 9; m++)		//��x������ѭ��
					{
						if ((!currChessBoard[m][j]) && (n == 0))	//�õ�û�����Ӳ��������յ�֮��û����������
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
						else		//�õ�������
						{
							n++;
							if (n == 2)
							{
								if (IsRed(currChessBoard[m][j]))		//�Ǻ�ɫ����
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
								break;	//����ѭ��
							}
						}
					}
					n = 0;
					for (m = j - 1; m >= 0; m--)			//��y��С�ķ���ѭ��
					{
						if ((!currChessBoard[i][m]) && (n == 0))		//���û�����Ӳ��������յ�֮��û������
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
								if (IsRed(currChessBoard[i][m]))		//�Ǻ�ɫ����
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
					for (m = j + 1; m <= 8; m++)		//��y����ķ���ѭ��
					{
						if ((!currChessBoard[i][m]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
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
						else		//�õ�������
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

				case B_Elephant:		//����
					if (i == 0)		//���������
					{
						if (!currChessBoard[i + 1][j - 1])		//���Ϸ�����û�б���
						{
							if (!IsBlack(currChessBoard[i + 2][j - 2]))		//���Ǻ���
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
						if (!currChessBoard[i + 1][j + 1])		//���Ϸ�����û�б���
						{
							if (!IsBlack(currChessBoard[i + 2][j + 2]))	//���Ǻ���
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
					else if (i == 2)	//�ں�ɫ��Ӫ��������
					{
						if (j == 0 || j == 4)
						{
							if (!currChessBoard[i + 1][j + 1])		//���Ϸ�����û�б���
							{
								if (!IsBlack(currChessBoard[i + 2][j + 2]))	//���Ǻ���
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
							if (!currChessBoard[i - 1][j + 1])		//���·�����û�б���
							{
								if (!IsBlack(currChessBoard[i - 2][j + 2]))			//���Ǻ���
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
							if (!currChessBoard[i + 1][j - 1])		//���Ϸ�����û�б���
							{
								if (!IsBlack(currChessBoard[i + 2][j - 2]))		//���Ǻ���
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
							if (!currChessBoard[i - 1][j - 1])		//���·�����û�б���
							{
								if (!IsBlack(currChessBoard[i - 2][j - 2]))		//���Ǻ���
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
					else		//i=5,�ں�ɫ��Ӫ��������
					{
						if (!currChessBoard[i - 1][j - 1])	//��������û�б���
						{
							if (!IsBlack(currChessBoard[i - 2][j - 2]))		//���Ǻ���
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
						if (!currChessBoard[i - 1][j + 1])	//���·�����û�б���
						{
							if (!IsBlack(currChessBoard[j - 2][j + 2]))	//���Ǻ���
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

				case B_Adviser:		//��ʿ
					if ((i + 1) <= 2 && (j + 1) <= 5)		//������������
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
					if ((i + 1) <= 2 && (j - 1) >= 3)		//������������
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
					if ((i - 1) >= 0 && (j + 1) <= 5)		//������������
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
					if ((i - 1) >= 0 && (j - 1) >= 3)		//������������
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

				case B_King:		//�ڽ�
					if (i<2)		//����������
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
					if (i>0)		//����������
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
					if (j>3)		//����������
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
					if (j<5)		//����������
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
					if (i <= 4)		//��û�й���
					{
						if (!IsBlack(currChessBoard[i + 1][j]))		//��ǰ�ߣ�Ŀ�겻�Ǻ���
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
					else		//������
					{
						if (!IsBlack(currChessBoard[i + 1][j])&&(i<9))		//��ǰ�ߣ�Ŀ�겻�Ǻ���
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
						if (!IsBlack(currChessBoard[i][j-1]) && (j>0))		//�����ߣ�Ŀ�겻�Ǻ���
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
						if (!IsBlack(currChessBoard[i][j + 1]) && (j<8))		//�����ߣ�Ŀ�겻�Ǻ���
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