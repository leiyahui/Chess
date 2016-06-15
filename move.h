/*#include "chess.h"
typedef struct MakedMove		//记录已经走过的步伐
{
	MakedMove* next;
	int xSPos;
	int ySPos;
	int xEPos;
	int yEPos;
	int echess;			//被覆盖的棋子
}Moved,*Movedstack;
typedef struct _made_move_stack
{
    Movedstack front;
    Movedstack rear;
    int len;
}made_move_stack;
void init_moved_stack(made_move_stack* stack);
void Push(made_move_stack, int xSPos, int ySPos, int xEPos, int yEPos, int eChess);
Movedstack Pop(made_move_stack* top);	
int MovedStackLength(Movedstack top);		//走过步伐栈的长度
void MakeMove(int currChessBoard[][9],Movedstack* top, int xSPos, int ySPos, int xEPos, int yEPos);		//走一步并且把步伐记录进入栈中
void unMakeMove(int currChessBoar[][9],Movedstack* top);	//返回已经走过的步伐并且出栈*/
#ifndef _MOVE_H
#define _MOVE_H

#define STACK_SIZE 10
#include<string.h>
#include"chess.h"
typedef struct _made_move       //one move that have been made
{   
    int to_chess;      //save chess of to
    unsigned char from,
    unsigned char to;
}made_move;
typedef struct _made_move_stack      //all move that have been made in one search
{
    made_move* base;
    made_move* top;
    int len;
}made_move_stack;
void init_moved_stack(made_move_stack* stack);
void push(made_move_stack* stack,unsigned char from,unsigned char to,int to_chess);
void pop(made_move_stack* stack,made_move* pop_move);
void make_move(int curr_chess_board[],unsigned char postion_array[],made_move_stack* stack,unsigned char from,unsigned char to);
void un_make_move(int curr_chess_board[],unsigned char postion_array[],made_move_stack* stack);
#endif
