/*#include "chess.h"
typedef struct MakedMove		//记录已经走过的步伐
{
	MakedMove* next;
	int xSPos;
	int ySPos;
	int xEPos;
	int yEPos;
	int echess;			//被覆盖的棋子
}Moved,*MovedLink;
typedef struct _made_move_link
{
    MovedLink front;
    MovedLink rear;
    int len;
}made_move_link;
void init_moved_stack(made_move_link* link);
void Push(made_move_link, int xSPos, int ySPos, int xEPos, int yEPos, int eChess);
MovedLink Pop(made_move_link* top);	
int MovedStackLength(MovedLink top);		//走过步伐栈的长度
void MakeMove(int currChessBoard[][9],MovedLink* top, int xSPos, int ySPos, int xEPos, int yEPos);		//走一步并且把步伐记录进入栈中
void unMakeMove(int currChessBoar[][9],MovedLink* top);	//返回已经走过的步伐并且出栈*/
#ifndef _MOVE_H
#define _MOVE_H
#include<string.h>
#include"chess.h"
typedef struct _made_move       //one move that have been made
{
    made_move* next;
    int xspos;
    int xypos;
    int xepos;
    int yepos;
    int echess;
}made_move;
typedef struct _made_move_link      //all move that have been made in one search
{
    made_move* top;
    int len;
}made_move_link;
void init_moved_link(made_move_link* link);
void push(made_move_link* link,int xspos,int yspos,int xepos,int yepos,int echess);
made_move pop(made_move_link* link);
int moved_link_length(made_move_link* link);
void make_move(int curr_chessboard[][9],made_move_link* link,int xspos,int yspos,int xepos,int yepos);
void un_make_move(int curr_chessboard[][9],made_move_link* link);
#endif
