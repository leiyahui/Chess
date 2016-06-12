/*generator move*/
#ifndef _MOVEGENERATOR_H
#define _MOVEGENERATOR_H
#include"chess.h"
typedef struct _movement     
{
	int xspos;
	int yspos;
	int xepos;
	int yepos;
	Movement* next;
}movement;
movement* generate_move(int curr_chess_board[][9],int red_turn,int i,int j); 
#endif
