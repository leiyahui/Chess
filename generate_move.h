/*generator move*/
#ifndef _GENERATE_MOVE_H
#define _GENERATE_MOVE_H
#include"chess.h"
#include"search.h"
#include"is_valid_pos.h"
typedef struct _movement     
{
    unsigned char from;
    unsigned char to;
}movement;
//generate move function of each kind of chess
static void generate_king_move(unsigned char from,int depth,int* count);
static void generate_adviser_move(unsigned char from,int depth,int* count);
static void generate_elephant_move(unsigned char from,int depth,int* count);
static void generate_horse_move(unsigned char form,int depth,int* count);
static void generate_chariot_move(unsigned char from,int depth,int* count);
static void generate_canon_move(unsigned char from,int depth,int* count);
static void generate_r_pawn_move(unsigned char from,int depth,int* count);
static void generate_b_pawn_move(unsigned char from,int depth,int* count);



static void add_movement(int depth,int* count,unsigned char from,unsigned char to);
int generate_move(int depth); 
#endif
