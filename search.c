#include "search.h"
#include "evalution.h"
static movement best_move;
unsigned char curr_chess_board[256] =			//use one dimension array to represent chess board
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0,0,0,1, 2, 4, 5, 7, 5, 4, 2, 1,0,0,0,0,	
	0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,
	0,0,0,0, 3, 0, 0, 0, 0, 0, 3, 0,0,0,0,0,
	0,0,0,6, 0, 6, 0, 6, 0, 6, 0, 6,0,0,0,0,
	0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,	
	0,0,0,13, 0, 13, 0, 13, 0, 13, 0, 13,0,0,0,0,
	0,0,0,0, 10, 0, 0, 0, 0, 0, 10, 0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0,0,0,8, 9, 11, 12, 14, 12, 11, 9, 8,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0
};							
unsigned char chess_array=                  //save chess position
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    199,198,200,197,201,196,202,195,203,164,170,147,149,151,153,155,
    55,54,56,53,57,52,58,51,59,84,90,99,101,103,105,107
}
unsigned char move_array[10][128]={0};
int IsBlackFail(int currChessBoard[][9])		
{
	int i, j;
	for (i = 0; i <= 2; i++)
	{
		for (j = 3; j<= 5; j++)
		{
			if (currChessBoard[i][j] == B_King)
			{
				return 0;			
			}
		}
	}
	return 1;
}
int IsRedFail(int currChessBoard[][9])	
{
	int i, j;
	for (i = 7; i <= 9; i++)
	{
		for (j = 3; j <= 5; j++)
		{
			if (currChessBoard[i][j] == R_King)
			{
				return 0;
			}
		}
	}
	return 1;
}
int nega_search(int depth)
{
    int value;
    int max_value;
    int side,count;
    int i;
    unsigned char form,to;
    side=depth%2;
    max_vlaue=MIN_INT;
    if(depth==0)
    {
        return evaluation(side);
    }
    count=generate_move();
    for(i=0;i<count;i++)
    {
        from=move_array[depth][i].from;
        to=move_array[depth][i].to;
        make_move(from,to);
        value=-nega_search(depth-1);
        un_make_move();
        if(value>best_value)
        {
            best_value=value;
            best_move->from=from;
            best_move->to=to;
        }
    }
    return best;
}
