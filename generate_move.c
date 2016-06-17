#include "generate_move.h"
//Chess move direction
static const unsigned char king_dir[4]={+1,-1,+16,-16};
static const unsigned char adviser_dir[4]={+17,-17,+15,-15};
static const unsigned char elephant_dir[4]={+34,-34,+30,-30};
static const unsigned char horse_dir[8]={+18,-14,+33,-31,+31,-33,+14,-18};
static const unsigned char chariot_dir[4]={+1,+16,-1,-16};
static const unsigned char canon_dir[4]={+1,+16,-1,-16};
static const unsigned char r_pawn_dir[4]={+1,-1,+16,0};
static const unsigned char b_pawn_dir[4]={+1,-1,-16,0};

//Chess move check
static const unsigned char elephant_check[4]={+17,-17,+15,-15};
static const unsigned char horse_check[8]={+1,+1,+16,-16,+16,-16,-1,-1};
static void generate_king_move(unsigned char from,int depth,int* count)
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
                add_movement(move_array,depth,count,from,to);
            }
        }
    }
}
static void generate_adviser_move(unsigned char from,int depth,int* count)
{
    int i;
    int to;
    for(i=0;i<4;i++)
    {
        to=from+adviser_dir[i];
        if(is_valid_pos(adviser_pos,to))
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,count,from,to);
            }
        }
    }
}

static void generate_elephant_move(unsigned char from,int depth,int* count)
{
    int i;
    int to;
    int check;
    for(i=0;i<8;i++)
    {
        to=from+elephant_dir[i];
        check=from+elephant_check[i];
        if(is_valid_pos(elephant_pos,to)&&curr_chess_board[check]==0)
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,count,from,to);
            }
        }
    }
}

static void generate_horse_move(unsigned char form,int depth,int* count)
{
    int i;
    int to,check;
    for(i=0;i<8;i++)
    {
        to=from+horse_dir[i];
        check=from+horse_check[i];
        if(is_valid_pos(h_c_c_pos,to)&&curr_chess_board[check]==NO_CHESS)
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,count,from,to);
            }
        }
    }
}

static void generate_chariot_move(unsigned char from,int depth,int* count)
{
    int i,j;
    int to;
    for(i=0;i<4;i++)
    {
        j=1;
        to=from+chariot_dir[i]*j;
        while(to<256&&to>=0&&curr_chess_board[to]==NO_CHESS)        //position without chess
        {
            if(is_valid_pos(h_c_c_pos,to))
            {
                add_movement(move_array,depth,count,from,to);
            }
            j++;
            to=from+chariot_dir[i]*j;
        }
        if(to>=0&&to<256)                   //the only one position with chess
        {
            if(is_valid_pos(h_c_c_pos,to))
            {
                if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
                {
                    add_movement(move_array,depth,count,from,to);
                }
            }
        }
    }
}
static void generate_canon_move(unsigned char from,int depth,int* count)
{
    int i,j;
    int to;
    for(i=0;i<4;i++)
    {
        j=1;
        to=from+canon_dir[i]*j;
        while(to<256&&to>=0&&curr_chess_board[to]==NO_CHESS)        //position without chess
        {
            if(is_valid_pos(h_c_c_pos,to))
            {
                add_movement(move_array,depth,count,from,to);
            }
            j++;
            to=from+chariot_dir[i]*j;
        }
        j++;
        to=from+chariot_dir[i]*j;     
        /*clear postion without chess after one one position with chess */
        while(to>=0&&to<256&&curr_chess_board[to]==NO_CHESS)
        {
           j++;
           to=from+chariot_dir[i]*j;
        }
        if(to>=0&&to<256)
        {
            if(is_valid_pos(h_c_c_pos,to))
            {
                if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
                {
                    add_movement(move_array,depth,count,from,to);
                }
            }
        }
    }
}
static void generate_r_pawn_move(unsigned char from,int depth,int* count)
{
    int i;
    int to;
    for(i=0;i<3;i++)
    {
        to=from+r_pawn_dir[i];
        if(is_valid_pos(r_pawn_pos,to))
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,count,from,to);
            }
        }
    }
}
static void generate_b_pawn_move(unsigned char from,int depth,int* count)
{
    int i;
    int to;
    for(i=0;i<3;i++)
    {
        to=from+b_pawn_dir[i];
        if(is_valid_pos(b_pawn_pos,to))
        {
            if(!is_same_color(curr_chess_board[from],curr_chess_board[to]))
            {
                add_movement(move_array,depth,count,from,to);
            }
        }
    }
}
int generate_move(int depth)
{
    int i,count;
    unsigned char pos;
    count=0;
    if(depth%2)     //red turn
    {
        for(i=32;i<=47;i++)
        {
            if(chess_array[i]!=0)
            {
                 switch(i)
                {
                     case 32:
                         generate_king_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                    case 33:
                    case 34:
                         generate_adviser_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                    case 35:
                    case 36:
                         generate_elephant_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                    case 37:
                    case 38:
                         generate_horse_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                   case 39:
                   case 40:
                        generate_chariot_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                   case 41:
                   case 42:
                        generate_canon_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                        break;
                   case 43:
                   case 44:
                   case 45:
                   case 46:
                   case 47:
                        generate_rpawn_move(curr_chess_board,depth,chess_array[i],&count,move_array);
                        break;
                }
            }
        }
    }
    else
    {
        for(i=16;i<=31;i++)
        {
            if(chess_array[i]!=0)
            {
                 switch(i)
                {
                    case 16:
                         generate_king_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                    case 17:
                    case 18:
                         generate_adviser_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                    case 19:
                    case 20:
                         generate_elephant_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                    case 21:
                    case 22:
                         generate_horse_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                   case 23:
                   case 24:
                        generate_chariot_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                         break;
                   case 25:
                   case 26:
                        generate_canon_move(curr_chess_board,chess_array[i],depth,&count,move_array);
                        break;
                   case 27:
                   case 28:
                   case 29:
                   case 30:
                   case 31:
                        generate_bpawn_move(curr_chess_board,depth,chess_array[i],&count,move_array);
                        break;
                }
            }
        }
    }
    return count;
}


                
                
                



static void add_movement(int depth,int* count,unsigned char from,unsigned char to)
{
    move_array[depth][*count].from=from;
    move_array[depth][*count].to=to;
    *count++;
}
    
