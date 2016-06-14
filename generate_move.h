/*generator move*/
#ifndef _MOVEGENERATOR_H
#define _MOVEGENERATOR_H
#include"chess.h"
#include"is_valid_pos.h"
typedef struct _movement     
{
    unsigned char from;
    unsigned char to;
}movement;
//Chess move direction
const unsigned char king_dir[4]={+1,-1,+16,-16};
const unsigned char adviser_dir[4]={+17,-17,+15,-15};
const unsigned char elephant_dir[4]={+34,-34,+30,-30};
const unsigned char horse_dir[8]={+18,-14,+33,-31,+31,-33,+14,-18};
const unsigned char chariot_dir[4]={+1,+16,-1,-16};
const unsigned char canon_dir[4]={+1,+16,-1,-16};
const unsigned char r_pawn_dir[4]={+1,-1,+16,0};
const unsigned char b_pawn_dir[4]={+1,-1,-16,0};

//Chess move check
const unsigned char elephant_check[4]={+17,-17,+15,-15};
const unsigned char horse_check[8]={+1,+1,+16,-16,+16,-16,-1,-1};
//generate move function of each kind of chess
static void generate_king_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128]);
static void generate_adviser_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128]);
static void generate_elephant_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128]);
static void generate_horse_move(unsigned char curr_chess_board[],unsigned char form,int depth,int* count,movement move_array[][128]);
static void generate_chariot_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128]);
static void generate_canon_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128]);
static void generate_r_pawn_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128]);
static void generate_b_pawn_move(unsigned char curr_chess_board[],unsigned char from,int depth,int* count,movement move_array[][128]);



static void add_movement(movement move_array[][128],int depth,int* count,unsigned char from,unsigned char to);
int generate_move(unsigned char curr_chess_board[],int depth,movement move_array[][128],unsigned chess_array[]); 
#endif
