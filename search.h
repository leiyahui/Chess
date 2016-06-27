#ifndef _SEARCH_H
#define _SEARCH_H
#include"chess.h"
#include "generate_move.h"
#include "limits.h"
#include "evaluation.h"
extern unsigned char curr_chess_board[256];			//use one dimension array to represent chess board
extern unsigned char chess_array[48];             //save chess position
extern unsigned char move_array[10][128];
void nega_search(int depth);
#endif
