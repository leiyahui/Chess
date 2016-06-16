#include "Evalution.h"
const short m_BaseValue[48] =
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 BASEVALUE_KING,BSEVALUE_BISHOP,BSEVALUE_BISHOP, BASEVALUE_ELEPHANT, BASEVALUE_ELEPHANT, BASEVALUE_HORSE,BASEVALUE_HORSE,
 BASEVALUE_CAR, BASEVALUE_CAR, BASEVALUE_CANON, BASEVALUE_CANON, BASEVALUE_PAWN, BASEVALUE_PAWN, BASEVALUE_PAWN, BASEVALUE_PAWN, BASEVALUE_PAWN,
 BASEVALUE_KING,BSEVALUE_BISHOP,BSEVALUE_BISHOP, BASEVALUE_ELEPHANT, BASEVALUE_ELEPHANT, BASEVALUE_HORSE, BASEVALUE_HORSE,
 BASEVALUE_CAR, BASEVALUE_CAR, BASEVALUE_CANON, BASEVALUE_CANON, BASEVALUE_PAWN, BASEVALUE_PAWN, BASEVALUE_PAWN, BASEVALUE_PAWN, BASEVALUE_PAWN
};
/*
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
}*/
int flex_value(unsigned char curr_chess_board,int unsigned char chess_array[],bool is_red_turn)
{
    int r_value[2];
    int pos,chess;
    int i,j,k;
    int check,n;
    r_value[0]=r_vlaue[1]=0;
    for(i=0;i<=1;i++)
    {
        /*king*/
        chess=16+16*i;
        pos=chess_array[chess];
        for(j=0;j<4;j++)
        {
            n=pos+king_dir[j];
            if(is_valid_pos(king_pos,n))
            {
                if(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                {
                    r_vlaue[i]+=flex_value[chess];
                }
            }
        }
        /*adviser*/
        for(k=0;k<=1;k++)
        {
            chess=17+k+16*i;
            for(j=0;j<4;j++)
            {
                n=pos+adviser_dir[j];
                if(is_valid_pos(adviser_pos,n))
                {
                    is(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                    {
                        r_value[i]+=flex_vlaue[chess];
                    }
                }
            }
        }
        /*elephant*/
        for(k=0;k<=1;k++)
        {
            chess=19+k+16*i;
            for(j=0;j<4;j++)
            {
                n=pos+elephant_dir[j];
                if(is_valid_pos(elephant_pos,n))
                {
                    is(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                    {
                        r_value[i]+=flex_vlaue[chess];
                    }
                }
            }
        }
        /*horse*/
        for(k=0;k<=1;k++)
        {
            chess=21+k+16*i;
            for(j=0;j<8;j++)
            {
                n=pos+horse_dir[j];
                check=pos+horse_check[j];
                if(is_valid_pos(h_c_c_pos,n))
                {
                    is(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                    {
                        if(curr_chess_board[check])
                        {
                            r_value[i]+=flex_vlaue[chess];
                        }
                    }
                }
            }
        }
        /*charoit*/
        for(k=0;k<=1;k++)
        {
            chess=23+k+16*i;
            for(j=0;j<4;j++)
            {
                n=pos+charoit_dir[j];
                while(n<256&&n>=0&&curr_chess_board[n]==NO_CHESS)        //position without chess
                {
                    if(is_valid_pos(h_c_c_pos,n))
                    {
                        r_value[i]+=flex_value[chess];
                    }
                    j++;
                    n=pos+chariot_dir[i]*j;
                }
                if(n>=0&&n<256)                   //the only one position with chess
                {
                    if(is_valid_pos(h_c_c_pos,n))
                    {
                        if(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                        {
                            r_value[i]+=flex_value[chess];
                        }
                    }
                }
            }
        }
        for(k=0;k<=1;k++)
        {
            chess=25+k+16*i;
            for(j=0;j<4;j++)
            {

    
    }



int evaluation(unsigned char curr_chess_board,unsigned char chess_array[], bool is_red_turn)
{
   int b_value;
   int r_value;
   int i;
   b_value=r_value=0;
   for(i=16;i<=31;i++)
   {
       if(chess_array[i]!=0)
       {
           b_value+=base_value[i];      //base_value;
       }
    }
   for(j=32;j<=47;j++)
   {
       if(chess_array[i]!=0)
       {
           r_value+=base_value[i];      //base_value;
       }
   }
   return b_value-r_value;
}



