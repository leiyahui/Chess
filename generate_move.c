#include "generate_move.h"
void generate_king_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count ,movement move_array[][128])
{
    int i;
    int to;
    for(i=0;i<4;i++)
    {
        to=from+king_dir[i];
        if(is_valid_pos(king_pos,to))
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,&count,from,to);
            }
        }
    }
}
void generate_adviser_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128])
{
    int i;
    int to;
    for(i=0;i<4;i++)
    {
        to=from+adviser_move[i];
        if(is_valid_pos(adviser_pos,to))
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,&count,from,to);
            }
        }
    }
}

void generate_elephant_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128])
{
    int i;
    int to;
    int check;
    for(i=0;i<8;i++)
    {
        to=from+elephant_move[i];
        check=from+elephant_check[i];
        if(is_valid_pos(elephant_pos,to)&&curr_chess_board[check]==0)
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,&count,from,to);
            }
        }
    }
}

void generate_horse_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128])
{
    int i;
    int to,check;
    for(i=0;i<8;i++)
    {
        to=from+horse_move[i];
        check=from+horse_check[i];
        if(is_valid_pos(horse_pos,to)&&curr_chess_board[check]==NO_CHESS)
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,&count,from,to);
            }
        }
    }
}

void generate_charoit_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128])
{
    int i,j;
    int to;
    for(i=0;i<4;i++)
    {
        j=1;
        to=from+charoit_dir[i]*j;
        while(to<256&&to>=0&&curr_chess_board[to]==NO_CHESS)        //position without chess
        {
            if(is_valid_pos(charoit_pos,to))
            {
                add_movement(move_array,depth,&count,from,to);
            }
            j++;
            to=from+charoit_dir[i]*j;
        }
        if(to>=0&&to<256)                   //the only one position with chess
        {
            if(is_valid_pos(charoit_pos,to))
            {
                if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
                {
                    add_movement(move_array,depth,&count,from,to);
                }
            }
        }
    }
}
void generate_canon_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128])
{
    int i,j;
    int to
    for(i=0;i<4;i++)
    {
        j=1;
        to=from+canon_dir[i]*j;
        while(to<256&&to>=0&&curr_chess_board[to]==NO_CHESS)        //position without chess
        {
            if(is_valid_pos(charoit_pos,to))
            {
                add_movement(move_array,depth,&count,from,to);
            }
            j++;
            to=from+charoit_dir[i]*j;
        }
        j++;
        to=from+charoit_move[i]*j;     
        /*clear postion without chess after one one position with chess */
        while(to>=0&&to<256&&curr_chess_board[to]==NO_CHESS)
        {
           j++;
           to=from+charoit_dir[i]*j;
        }
        if(to>=0&&to<256)
        {
            if(is_valid_pos(charoit_pos,to))
            {
                if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
                {
                    add_movement(move_array,depth,&count,from,to);
                }
            }
        }
    }
}
void generate_rpawn_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128])
{
    int i;
    int to;
    for(i=0;i<3;i++)
    {
        to=from+rpawn_dir[i];
        if(is_valid_pos(r_pawn_pos,to))
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_arrary,depth,&count,from,to);
            }
        }
    }
}
void generate_bpawn_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128])
{
    int i;
    int to;
    for(i=0;i<3;i++)
    {
        to=from+bpawn_dir[i];
        if(is_valid_pos(b_pawn_pos,to))
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_arrary,depth,&count,from,to);
            }
        }
    }
}

void add_movement(movement move_array[][128],int depth,int* count,unsigned char from,unsigned char to)
{
    move_array[depth][*count].from=from;
    move_array[depth][*count].to=to;
    *count++;
}
    
/*void generate_move(unsigned char curr_chess_board[], int depth,movement move_array[][128])		//走法产生器,i=0该黑子走，否则该红子走
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
				case NO_CHESS:		//没有棋子
					break;
				case R_Chariot:		//红车
					for (m = i - 1; m >= 0; m--)		//向x减小方向线循环
					{
						if (!curr_chess_board[m][j])			//当前位置没有棋子
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
						else							//当前位置有棋子
						{
							if (IsBlack(curr_chess_board[m][j]))		//不同阵营的时候添加一个节点
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
					for (m = i + 1; m < 10; m++)	//向x增大方向循环
					{
						if (!curr_chess_board[m][j])		//当前位置没有棋子
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
						else						//当前位置存在棋子
						{
							if (IsBlack(curr_chess_board[m][j]))	//不同阵营的时候添加一个节点	
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
					for (m = j - 1; m >= 0; m--)		//向j减小方向循环
					{
						if (!curr_chess_board[i][m])		//当前位置没有棋子
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
						else						//当前位置存在棋子
						{
							if (IsBlack(curr_chess_board[i][m]))	//不同阵营的时候添加一个节点	
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
					for (m = j + 1; m<9; m++)		//向j增大方向循环
					{
						if (!curr_chess_board[i][m])		//当前位置没有棋子
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
						else						//当前位置存在棋子
						{
							if (IsBlack(curr_chess_board[i][m]))	//不同阵营的时候添加一个节点	
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

				case R_Horse:		//红马
					if (i<8)		//向上走
					{
						if (!curr_chess_board[i + 1][j])		//马蹄没有被拌
						{
							if (j>0 && (!IsRed(curr_chess_board[i + 2][j - 1])))		//向左上走
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
							if (j<9 && (!IsRed(curr_chess_board[i + 2][j + 1])))		//向右上走
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
					if (i>1)		//向下走
					{
						if (!curr_chess_board[i - 1][j])		//马蹄没有被拌
						{
							if (j>0 && (!IsRed(curr_chess_board[i - 2][j - 1])))		//向左下走
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
							if (j<9 && (!IsRed(curr_chess_board[i - 2][j + 1])))		//向右下走
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
					if (j<7)		//向右走
					{
						if (!curr_chess_board[i][j + 1])		//马蹄没有被拌
						{
							if (i>0 && (!IsRed(curr_chess_board[i - 1][j + 2])))		//向右下走
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
							if (i<9 && (!IsRed(curr_chess_board[i + 1][j + 2])))		//向右上走
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
					if (j>1)		//向左走
					{
						if (!curr_chess_board[i][j - 1])
							if (i>0 && (!IsRed(curr_chess_board[i - 1][j - 2])))		//向左下走
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
						if (i<9 && (!IsRed(curr_chess_board[i + 1][j - 2])))		//向左上走
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

				case R_Canon:		//红炮
					n = 0;
					for (m = i - 1; m >= 0; m--)			//向x减小方向循环
					{
						if ((!curr_chess_board[m][j]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
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
						else		//有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(curr_chess_board[m][j]))		//是红色棋子
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
								break;		//跳出当前循环
							}
						}
					}
					n = 0;
					for (m = i + 1; m <= 9; m++)		//沿x增大方向循环
					{
						if ((!curr_chess_board[m][j]) && (n == 0))	//该点没有棋子并且起点和终点之间没有其他棋子
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
						else		//该点有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsBlack(curr_chess_board[m][j]))		//是红色棋子
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
								break;	//跳出循环
							}
						}
					}
					n = 0;
					for (m = j - 1; m >= 0; m--)			//向y减小的方向循环
					{
						if ((!curr_chess_board[i][m]) && (n == 0))		//这点没有棋子并且起点和终点之间没有棋子
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
								if (IsBlack(curr_chess_board[i][m]))		//是红色棋子
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
					for (m = j + 1; m <= 8; m++)		//向y增大的方向循环
					{
						if ((!curr_chess_board[i][m]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
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
						else		//该点有棋子
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

				case R_Elephant:		//红象
					if (i == 5)		//在最红色阵营的最底线上
					{
						if (!curr_chess_board[i + 1][j - 1])		//左上方象蹄没有被拌
						{
							if (!IsRed(curr_chess_board[i + 2][j - 2]))		//不是红子
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
						if (!curr_chess_board[i + 1][j + 1])		//右上方象蹄没有被拌
						{
							if (!IsRed(curr_chess_board[i + 2][j + 2]))		//不是红子
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
					else if (i == 7)	//在黑色阵营的中线上
					{
						if (j == 0 || j == 4)
						{
							if (!curr_chess_board[i + 1][j + 1])		//右上方象蹄没有被拌
							{
								if (!IsRed(curr_chess_board[i + 2][j + 2]))	//不是红子
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
							if (!curr_chess_board[i - 1][j + 1])		//右下方象蹄没有被拌
							{
								if (!IsRed(curr_chess_board[i - 2][j + 2]))			//不是红子
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
							if (!curr_chess_board[i + 1][j - 1])		//左上方象蹄没有被拌
							{
								if (!IsRed(curr_chess_board[i + 2][j - 2]))		//不是红子
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
							if (!curr_chess_board[i - 1][j - 1])		//左下方象蹄没有被拌
							{
								if (!IsRed(curr_chess_board[i - 2][j - 2]))		//不是红子
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
					else		//i=9,在黑色阵营的最上线
					{
						if (!curr_chess_board[i - 1][j - 1])	//左下象蹄没有被拌
						{
							if (!IsRed(curr_chess_board[i - 2][j - 2]))		//不是红子
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
						if (!curr_chess_board[i - 1][j + 1])	//右下方象蹄没有被拌
						{
							if (!IsRed(curr_chess_board[j - 2][j + 2]))	//不是红子
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

				case R_Adviser:		//红士
					if ((i + 1) <= 9 && (j + 1) <= 5)		//可以向右上走
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
					if ((i + 1) <= 9 && (j - 1) >= 3)		//可以向左上走
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
					if ((i - 1) >= 7 && (j + 1) <= 5)		//可以向右下走
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
					if ((i - 1) >= 7 && (j - 1) >= 3)		//可以向左下走
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
					if (i<9)		//可以向上走
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
					if (i>7)		//可以向下走
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
					if (j>3)		//可以向左走
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
					if (j<5)		//可以向右走
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
				case R_Pawn:		//红兵
					if (i >= 5)
					{
						if (!IsRed(curr_chess_board[i - 1][j]))	//向前走,目标不是红子
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
						if (!IsRed(curr_chess_board[i - 1][j])&&(i>0)) //向前走，目标不是红子
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
						if (!IsRed(curr_chess_board[i][j-1]) && (j>0))//向左走，目标不是红子
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
						if (!IsRed(curr_chess_board[i][j + 1]) && (j<8))//向右，目标不是红子
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
				case NO_CHESS:		//没有棋子
					break;
				case B_Chariot:		//黑车
					for (m = i - 1; m >= 0; m--)		//向x减小方向线循环
					{
						if (!curr_chess_board[m][j])			//当前位置没有棋子
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
						else							//当前位置有棋子
						{
							if (IsRed(curr_chess_board[m][j]))		//不同阵营的时候添加一个节点
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
					for (m = i + 1; m< 10; m++)	//向x增大方向循环
					{
						if (!curr_chess_board[m][j])		//当前位置没有棋子
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
						else						//当前位置存在棋子
						{
							if (IsRed(curr_chess_board[m][j]))	//不同阵营的时候添加一个节点	
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
					for (m = j - 1; m >= 0; m--)		//向j减小方向循环
					{
						if (!curr_chess_board[i][m])		//当前位置没有棋子
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
						else						//当前位置存在棋子
						{
							if (IsRed(curr_chess_board[i][m]))	//不同阵营的时候添加一个节点	
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
					for (m = j + 1; m<9; m++)		//向j增大方向循环
					{
						if (!curr_chess_board[i][m])		//当前位置没有棋子
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
						else						//当前位置存在棋子
						{
							if (IsRed(curr_chess_board[i][m]))	//不同阵营的时候添加一个节点	
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

				case B_Horse:		//黑马
					if (i<8)		//向上走
					{
						if (!curr_chess_board[i + 1][j])		//马蹄没有被拌
						{
							if (j>0 && (!IsBlack(curr_chess_board[i + 2][j - 1])))		//向左上走
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
							if (j<9 && (!IsBlack(curr_chess_board[i + 2][j + 1])))		//向右上走
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
					if (i>1)		//向下走
					{
						if (!curr_chess_board[i - 1][j])		//马蹄没有被拌
						{
							if (j>0 && (!IsBlack(curr_chess_board[i - 2][j - 1])))		//向左下走
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
							if (j<9 && (!IsBlack(curr_chess_board[i - 2][j + 1])))		//向右下走
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
					if (j<7)		//向右走
					{
						if (!curr_chess_board[i][j + 1])		//马蹄没有被拌
						{
							if (i>0 && (!IsBlack(curr_chess_board[i - 1][j + 2])))		//向右下走
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
							if (i<9 && (!IsBlack(curr_chess_board[i + 1][j + 2])))		//向右上走
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
					if (j>1)		//向左走
					{
						if (!curr_chess_board[i][j - 1])
							if (i>0 && (!IsBlack(curr_chess_board[i - 1][j - 2])))		//向左下走
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
						if (i<9 && (!IsBlack(curr_chess_board[i + 1][j - 2])))		//向左上走
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

				case B_Canon:		//黑炮
					n = 0;
					for (m = i - 1; m >= 0; m--)			//向x减小方向循环
					{
						if ((!curr_chess_board[m][j]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
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
						else		//有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsRed(curr_chess_board[m][j]))		//是红色棋子
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
								break;		//跳出当前循环
							}
						}
					}
					n = 0;
					for (m = i + 1; m <= 9; m++)		//沿x增大方向循环
					{
						if ((!curr_chess_board[m][j]) && (n == 0))	//该点没有棋子并且起点和终点之间没有其他棋子
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
						else		//该点有棋子
						{
							n++;
							if (n == 2)
							{
								if (IsRed(curr_chess_board[m][j]))		//是红色棋子
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
								break;	//跳出循环
							}
						}
					}
					n = 0;
					for (m = j - 1; m >= 0; m--)			//向y减小的方向循环
					{
						if ((!curr_chess_board[i][m]) && (n == 0))		//这点没有棋子并且起点和终点之间没有棋子
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
								if (IsRed(curr_chess_board[i][m]))		//是红色棋子
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
					for (m = j + 1; m <= 8; m++)		//向y增大的方向循环
					{
						if ((!curr_chess_board[i][m]) && (n == 0))		//该点没有棋子并且起点和终点之间没有其他棋子
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
						else		//该点有棋子
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

				case B_Elephant:		//黑象
					if (i == 0)		//在最低线上
					{
						if (!curr_chess_board[i + 1][j - 1])		//左上方象蹄没有被拌
						{
							if (!IsBlack(curr_chess_board[i + 2][j - 2]))		//不是黑子
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
						if (!curr_chess_board[i + 1][j + 1])		//右上方象蹄没有被拌
						{
							if (!IsBlack(curr_chess_board[i + 2][j + 2]))	//不是黑子
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
					else if (i == 2)	//在黑色阵营的中线上
					{
						if (j == 0 || j == 4)
						{
							if (!curr_chess_board[i + 1][j + 1])		//右上方象蹄没有被拌
							{
								if (!IsBlack(curr_chess_board[i + 2][j + 2]))	//不是黑子
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
							if (!curr_chess_board[i - 1][j + 1])		//右下方象蹄没有被拌
							{
								if (!IsBlack(curr_chess_board[i - 2][j + 2]))			//不是黑子
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
							if (!curr_chess_board[i + 1][j - 1])		//左上方象蹄没有被拌
							{
								if (!IsBlack(curr_chess_board[i + 2][j - 2]))		//不是黑子
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
							if (!curr_chess_board[i - 1][j - 1])		//左下方象蹄没有被拌
							{
								if (!IsBlack(curr_chess_board[i - 2][j - 2]))		//不是黑子
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
					else		//i=5,在黑色阵营的最上线
					{
						if (!curr_chess_board[i - 1][j - 1])	//左下象蹄没有被拌
						{
							if (!IsBlack(curr_chess_board[i - 2][j - 2]))		//不是黑子
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
						if (!curr_chess_board[i - 1][j + 1])	//右下方象蹄没有被拌
						{
							if (!IsBlack(curr_chess_board[j - 2][j + 2]))	//不是黑子
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

				case B_Adviser:		//黑士
					if ((i + 1) <= 2 && (j + 1) <= 5)		//可以向右上走
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
					if ((i + 1) <= 2 && (j - 1) >= 3)		//可以向左上走
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
					if ((i - 1) >= 0 && (j + 1) <= 5)		//可以向右下走
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
					if ((i - 1) >= 0 && (j - 1) >= 3)		//可以向左下走
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

				case B_King:		//黑将
					if (i<2)		//可以向上走
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
					if (i>0)		//可以向下走
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
					if (j>3)		//可以向左走
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
					if (j<5)		//可以向右走
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
					if (i <= 4)		//还没有过河
					{
						if (!IsBlack(curr_chess_board[i + 1][j]))		//向前走，目标不是黑子
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
					else		//过河了
					{
						if (!IsBlack(curr_chess_board[i + 1][j])&&(i<9))		//向前走，目标不是黑子
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
						if (!IsBlack(curr_chess_board[i][j-1]) && (j>0))		//向左走，目标不是黑子
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
						if (!IsBlack(curr_chess_board[i][j + 1]) && (j<8))		//向右走，目标不是黑子
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
}*/
