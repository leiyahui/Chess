/*generator move*/
#ifndef _MOVEGENERATOR_H
#define _MOVEGENERATOR_H
#include"chess.h"
typedef struct _movement     
{
    unsigned char from;
    unsigned char to;
}movement;
//Chess move direction
const unsigned char king_dir[4]={+1,-1,+16,-16};
const unsigned char adviser_dir[4]={+17,-17,+15,-15};
const unsigned char elephant_dir[4]={+34,-34,+30,-30};
const unsigned char horse_dir[8]={+18,-
//Chess move check
const unsigned char elephant_check[4]={+17,-17,+15,-15};
// Chess position
const unsigned char king_pos{256}=
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0
};
//generate move function of each kind of chess
void generate_king_move(unsigned char curr_chess_board[],int depth,int* count,movement move_array[][128]);
bool is_valid_pos(unsigned char pos_array[],unsigned char pos);
void add_movement(movement move_array[][128],int depth,int count,unsigned char from,unsigned char to);
void generate_move(unsigned char curr_chess_board[],int depth,movement move_array[][128]); 
#endif
