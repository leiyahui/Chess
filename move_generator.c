#include "movementGenerator.h"
void generate_king_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count ,int movement move_array[][128])
{
    int i;
    int to;
    for(i=0;i<4;i++)
    {
        to=from+king_dir[i];
        if(
        
        
    
void generate_move(unsigned char curr_chess_board[], int depth,movement move_array[][128])		//�߷�������,i=0�ú����ߣ�����ú�����
{
	int fromt,to;
	int pos,chess;
	int m, n;
    int i,j;
    int is_red_turn;
    is_red_turn%=2;
	if (red_turn)
	{
        for(i=3;i++;i<=11)
        {
            for(j=3;j++;j<=12)
            {
                pos=i<<4+j;    
				chess = curr_chess_board[pos];
				switch (chess)
				{
				case NO_CHESS:		//û������
					break;
				case R_Chariot:		//�쳵
					for (m = i - 1; m >= 0; m--)		//��x��С������ѭ��
					{
						if (!curr_chess_board[m][j])			//��ǰλ��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = m;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else							//��ǰλ��������
						{
							if (IsBlack(curr_chess_board[m][j]))		//��ͬ��Ӫ��ʱ�����һ���ڵ�
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = m;
								q->yepos = j;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							break;
						}
					}
					for (m = i + 1; m < 10; m++)	//��x������ѭ��
					{
						if (!curr_chess_board[m][j])		//��ǰλ��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = m;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//��ǰλ�ô�������
						{
							if (IsBlack(curr_chess_board[m][j]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = m;
								q->yepos = j;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							break;
						}
					}
					for (m = j - 1; m >= 0; m--)		//��j��С����ѭ��
					{
						if (!curr_chess_board[i][m])		//��ǰλ��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//��ǰλ�ô�������
						{
							if (IsBlack(curr_chess_board[i][m]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i;
								q->yepos = m;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							break;
						}
					}
					for (m = j + 1; m<9; m++)		//��j������ѭ��
					{
						if (!curr_chess_board[i][m])		//��ǰλ��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//��ǰλ�ô�������
						{
							if (IsBlack(curr_chess_board[i][m]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i;
								q->yepos = m;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							break;
						}
					}
					break;

				case R_Horse:		//����
					if (i<8)		//������
					{
						if (!curr_chess_board[i + 1][j])		//����û�б���
						{
							if (j>0 && (!IsRed(curr_chess_board[i + 2][j - 1])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 2;
								q->yepos = j - 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (j<9 && (!IsRed(curr_chess_board[i + 2][j + 1])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 2;
								q->yepos = j + 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (i>1)		//������
					{
						if (!curr_chess_board[i - 1][j])		//����û�б���
						{
							if (j>0 && (!IsRed(curr_chess_board[i - 2][j - 1])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 2;
								q->yepos = j - 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (j<9 && (!IsRed(curr_chess_board[i - 2][j + 1])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 2;
								q->yepos = j + 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (j<7)		//������
					{
						if (!curr_chess_board[i][j + 1])		//����û�б���
						{
							if (i>0 && (!IsRed(curr_chess_board[i - 1][j + 2])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 1;
								q->yepos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (i<9 && (!IsRed(curr_chess_board[i + 1][j + 2])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 1;
								q->yepos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (j>1)		//������
					{
						if (!curr_chess_board[i][j - 1])
							if (i>0 && (!IsRed(curr_chess_board[i - 1][j - 2])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 1;
								q->yepos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						if (i<9 && (!IsRed(curr_chess_board[i + 1][j - 2])))		//��������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j - 2;
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
						if ((!curr_chess_board[m][j]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = m;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//������
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(curr_chess_board[m][j]))		//�Ǻ�ɫ����
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = m;
									q->yepos = j;
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
						if ((!curr_chess_board[m][j]) && (n == 0))	//�õ�û�����Ӳ��������յ�֮��û����������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = m;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//�õ�������
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(curr_chess_board[m][j]))		//�Ǻ�ɫ����
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = m;
									q->yepos = j;
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
						if ((!curr_chess_board[i][m]) && (n == 0))		//���û�����Ӳ��������յ�֮��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(curr_chess_board[i][m]))		//�Ǻ�ɫ����
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i;
									q->yepos = m;
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
						if ((!curr_chess_board[i][m]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//�õ�������
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(curr_chess_board[i][m]))
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i;
									q->yepos = m;
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
						if (!curr_chess_board[i + 1][j - 1])		//���Ϸ�����û�б���
						{
							if (!IsRed(curr_chess_board[i + 2][j - 2]))		//���Ǻ���
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 2;
								q->yepos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
						if (!curr_chess_board[i + 1][j + 1])		//���Ϸ�����û�б���
						{
							if (!IsRed(curr_chess_board[i + 2][j + 2]))		//���Ǻ���
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 2;
								q->yepos = j + 2;
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
							if (!curr_chess_board[i + 1][j + 1])		//���Ϸ�����û�б���
							{
								if (!IsRed(curr_chess_board[i + 2][j + 2]))	//���Ǻ���
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i + 2;
									q->yepos = j + 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
							if (!curr_chess_board[i - 1][j + 1])		//���·�����û�б���
							{
								if (!IsRed(curr_chess_board[i - 2][j + 2]))			//���Ǻ���
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i - 2;
									q->yepos = j + 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
						}
						if (j == 4 || j == 8)
						{
							if (!curr_chess_board[i + 1][j - 1])		//���Ϸ�����û�б���
							{
								if (!IsRed(curr_chess_board[i + 2][j - 2]))		//���Ǻ���
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i + 2;
									q->yepos = j - 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
							if (!curr_chess_board[i - 1][j - 1])		//���·�����û�б���
							{
								if (!IsRed(curr_chess_board[i - 2][j - 2]))		//���Ǻ���
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i - 2;
									q->yepos = j - 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
						}

					}
					else		//i=9,�ں�ɫ��Ӫ��������
					{
						if (!curr_chess_board[i - 1][j - 1])	//��������û�б���
						{
							if (!IsRed(curr_chess_board[i - 2][j - 2]))		//���Ǻ���
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 2;
								q->yepos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
						if (!curr_chess_board[i - 1][j + 1])	//���·�����û�б���
						{
							if (!IsRed(curr_chess_board[j - 2][j + 2]))	//���Ǻ���
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 2;
								q->yepos = j + 2;
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
						if (!IsRed(curr_chess_board[i + 1][j + 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i + 1) <= 9 && (j - 1) >= 3)		//������������
					{
						if (!IsRed(curr_chess_board[i + 1][j - 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i - 1) >= 7 && (j + 1) <= 5)		//������������
					{
						if (!IsRed(curr_chess_board[i - 1][j + 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i - 1;
							q->yepos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i - 1) >= 7 && (j - 1) >= 3)		//������������
					{
						if (!IsRed(curr_chess_board[i - 1][j - 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i - 1;
							q->yepos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;

				case R_King:
					if (i<9)		//����������
					{
						if (!IsRed(curr_chess_board[i + 1][j]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							q = q;
						}
					}
					if (i>7)		//����������
					{
						if (!IsRed(curr_chess_board[i - 1][j]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i - 1;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (j>3)		//����������
					{
						if (!IsRed(curr_chess_board[i][j - 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (j<5)		//����������
					{
						if (!IsRed(curr_chess_board[i][j + 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;
				case R_Pawn:		//���
					if (i >= 5)
					{
						if (!IsRed(curr_chess_board[i - 1][j]))	//��ǰ��,Ŀ�겻�Ǻ���
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i - 1;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					else
					{
						if (!IsRed(curr_chess_board[i - 1][j])&&(i>0)) //��ǰ�ߣ�Ŀ�겻�Ǻ���
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i - 1;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						if (!IsRed(curr_chess_board[i][j-1]) && (j>0))//�����ߣ�Ŀ�겻�Ǻ���
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						if (!IsRed(curr_chess_board[i][j + 1]) && (j<8))//���ң�Ŀ�겻�Ǻ���
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = j + 1;
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
				chess = curr_chess_board[i][j];
				switch (chess)
				{
				case NO_CHESS:		//û������
					break;
				case B_Chariot:		//�ڳ�
					for (m = i - 1; m >= 0; m--)		//��x��С������ѭ��
					{
						if (!curr_chess_board[m][j])			//��ǰλ��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = m;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else							//��ǰλ��������
						{
							if (IsRed(curr_chess_board[m][j]))		//��ͬ��Ӫ��ʱ�����һ���ڵ�
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = m;
								q->yepos = j;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							break;
						}
					}
					for (m = i + 1; m< 10; m++)	//��x������ѭ��
					{
						if (!curr_chess_board[m][j])		//��ǰλ��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = m;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//��ǰλ�ô�������
						{
							if (IsRed(curr_chess_board[m][j]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = m;
								q->yepos = j;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							break;
						}
					}
					for (m = j - 1; m >= 0; m--)		//��j��С����ѭ��
					{
						if (!curr_chess_board[i][m])		//��ǰλ��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//��ǰλ�ô�������
						{
							if (IsRed(curr_chess_board[i][m]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i;
								q->yepos = m;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							break;
						}
					}
					for (m = j + 1; m<9; m++)		//��j������ѭ��
					{
						if (!curr_chess_board[i][m])		//��ǰλ��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else						//��ǰλ�ô�������
						{
							if (IsRed(curr_chess_board[i][m]))	//��ͬ��Ӫ��ʱ�����һ���ڵ�	
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i;
								q->yepos = m;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							break;
						}
					}
					break;

				case B_Horse:		//����
					if (i<8)		//������
					{
						if (!curr_chess_board[i + 1][j])		//����û�б���
						{
							if (j>0 && (!IsBlack(curr_chess_board[i + 2][j - 1])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 2;
								q->yepos = j - 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (j<9 && (!IsBlack(curr_chess_board[i + 2][j + 1])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 2;
								q->yepos = j + 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (i>1)		//������
					{
						if (!curr_chess_board[i - 1][j])		//����û�б���
						{
							if (j>0 && (!IsBlack(curr_chess_board[i - 2][j - 1])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 2;
								q->yepos = j - 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (j<9 && (!IsBlack(curr_chess_board[i - 2][j + 1])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 2;
								q->yepos = j + 1;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (j<7)		//������
					{
						if (!curr_chess_board[i][j + 1])		//����û�б���
						{
							if (i>0 && (!IsBlack(curr_chess_board[i - 1][j + 2])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 1;
								q->yepos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
							if (i<9 && (!IsBlack(curr_chess_board[i + 1][j + 2])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 1;
								q->yepos = j + 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
					}
					if (j>1)		//������
					{
						if (!curr_chess_board[i][j - 1])
							if (i>0 && (!IsBlack(curr_chess_board[i - 1][j - 2])))		//��������
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 1;
								q->yepos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						if (i<9 && (!IsBlack(curr_chess_board[i + 1][j - 2])))		//��������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j - 2;
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
						if ((!curr_chess_board[m][j]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = m;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//������
						{
							n++;
							if (n == 2)
							{
								if (IsRed(curr_chess_board[m][j]))		//�Ǻ�ɫ����
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = m;
									q->yepos = j;
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
						if ((!curr_chess_board[m][j]) && (n == 0))	//�õ�û�����Ӳ��������յ�֮��û����������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = m;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//�õ�������
						{
							n++;
							if (n == 2)
							{
								if (IsRed(curr_chess_board[m][j]))		//�Ǻ�ɫ����
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = m;
									q->yepos = j;
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
						if ((!curr_chess_board[i][m]) && (n == 0))		//���û�����Ӳ��������յ�֮��û������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else
						{
							n++;
							if (n == 2)
							{
								if (IsRed(curr_chess_board[i][m]))		//�Ǻ�ɫ����
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i;
									q->yepos = m;
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
						if ((!curr_chess_board[i][m]) && (n == 0))		//�õ�û�����Ӳ��������յ�֮��û����������
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = m;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						else		//�õ�������
						{
							n++;
							if (n == 2)
							{
								if (IsRed(curr_chess_board[i][m]))
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i;
									q->yepos = m;
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
						if (!curr_chess_board[i + 1][j - 1])		//���Ϸ�����û�б���
						{
							if (!IsBlack(curr_chess_board[i + 2][j - 2]))		//���Ǻ���
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 2;
								q->yepos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
						if (!curr_chess_board[i + 1][j + 1])		//���Ϸ�����û�б���
						{
							if (!IsBlack(curr_chess_board[i + 2][j + 2]))	//���Ǻ���
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i + 2;
								q->yepos = j + 2;
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
							if (!curr_chess_board[i + 1][j + 1])		//���Ϸ�����û�б���
							{
								if (!IsBlack(curr_chess_board[i + 2][j + 2]))	//���Ǻ���
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i + 2;
									q->yepos = j + 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
							if (!curr_chess_board[i - 1][j + 1])		//���·�����û�б���
							{
								if (!IsBlack(curr_chess_board[i - 2][j + 2]))			//���Ǻ���
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i - 2;
									q->yepos = j + 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
						}
						if (j == 4 || j == 8)
						{
							if (!curr_chess_board[i + 1][j - 1])		//���Ϸ�����û�б���
							{
								if (!IsBlack(curr_chess_board[i + 2][j - 2]))		//���Ǻ���
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i + 2;
									q->yepos = j - 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
							if (!curr_chess_board[i - 1][j - 1])		//���·�����û�б���
							{
								if (!IsBlack(curr_chess_board[i - 2][j - 2]))		//���Ǻ���
								{
									q = (movement*)malloc(sizeof(movement));
									q->xspos = i;
									q->yspos = j;
									q->xepos = i - 2;
									q->yepos = j - 2;
									q->next = NULL;
									p->next = q;
									p = q;
								}
							}
						}

					}
					else		//i=5,�ں�ɫ��Ӫ��������
					{
						if (!curr_chess_board[i - 1][j - 1])	//��������û�б���
						{
							if (!IsBlack(curr_chess_board[i - 2][j - 2]))		//���Ǻ���
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 2;
								q->yepos = j - 2;
								q->next = NULL;
								p->next = q;
								p = q;
							}
						}
						if (!curr_chess_board[i - 1][j + 1])	//���·�����û�б���
						{
							if (!IsBlack(curr_chess_board[j - 2][j + 2]))	//���Ǻ���
							{
								q = (movement*)malloc(sizeof(movement));
								q->xspos = i;
								q->yspos = j;
								q->xepos = i - 2;
								q->yepos = j + 2;
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
						if (!IsBlack(curr_chess_board[i + 1][j + 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i + 1) <= 2 && (j - 1) >= 3)		//������������
					{
						if (!IsBlack(curr_chess_board[i + 1][j - 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i - 1) >= 0 && (j + 1) <= 5)		//������������
					{
						if (!IsBlack(curr_chess_board[i - 1][j + 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i - 1;
							q->yepos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if ((i - 1) >= 0 && (j - 1) >= 3)		//������������
					{
						if (!IsBlack(curr_chess_board[i - 1][j - 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i - 1;
							q->yepos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;

				case B_King:		//�ڽ�
					if (i<2)		//����������
					{
						if (!IsBlack(curr_chess_board[i + 1][j]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (i>0)		//����������
					{
						if (!IsBlack(curr_chess_board[i - 1][j]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i - 1;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (j>3)		//����������
					{
						if (!IsBlack(curr_chess_board[i][j - 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = j - 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					if (j<5)		//����������
					{
						if (!IsBlack(curr_chess_board[i][j + 1]))
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = j + 1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					break;
				case B_Pawn:
					if (i <= 4)		//��û�й���
					{
						if (!IsBlack(curr_chess_board[i + 1][j]))		//��ǰ�ߣ�Ŀ�겻�Ǻ���
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
					}
					else		//������
					{
						if (!IsBlack(curr_chess_board[i + 1][j])&&(i<9))		//��ǰ�ߣ�Ŀ�겻�Ǻ���
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i + 1;
							q->yepos = j;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						if (!IsBlack(curr_chess_board[i][j-1]) && (j>0))		//�����ߣ�Ŀ�겻�Ǻ���
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = j-1;
							q->next = NULL;
							p->next = q;
							p = q;
						}
						if (!IsBlack(curr_chess_board[i][j + 1]) && (j<8))		//�����ߣ�Ŀ�겻�Ǻ���
						{
							q = (movement*)malloc(sizeof(movement));
							q->xspos = i;
							q->yspos = j;
							q->xepos = i;
							q->yepos = j + 1;
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
