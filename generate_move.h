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
