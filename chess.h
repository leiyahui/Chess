/*Chess defination*/
#ifndef _CHESS_H
#define _CHESS_H
#include<stdio.h>
#include<stdlib.h>
#define NO_CHESS	0
#define B_Chariot   1
#define B_Horse		2
#define B_Canon		3
#define B_Elephant	4
#define	B_Adviser	5
#define B_Pawn		6
#define	B_King		7
#define R_Chariot   8
#define R_Horse		9
#define R_Canon		10
#define R_Elephant	11
#define	R_Adviser	12
#define R_Pawn		13
#define	R_King		14
#define is_black(chess)	(1<=(chess)&&(chess)<=7?1:0)
#define is_red(chess)	(8<=(chess)&&(chess)<=14?1:0)
#define is_same_color(chess1,chess2)	((is_black(chess1)&&is_black(chess2))||(is_red(chess1)&&is_red(chess2)))
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
#endif
