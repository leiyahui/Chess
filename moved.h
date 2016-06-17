#ifndef _MOVED_H
#define _MOVED_H

#define STACK_SIZE 10
#include"chess.h"
#include"search.h"
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
void make_move(made_move_stack* stack,unsigned char from,unsigned char to);
void un_make_move(made_move_stack* stack);
#endif
