/*#include "chess.h"
typedef struct MakedMove		//��¼�Ѿ��߹��Ĳ���
{
	MakedMove* next;
	int xSPos;
	int ySPos;
	int xEPos;
	int yEPos;
	int echess;			//�����ǵ�����
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
int MovedStackLength(MovedLink top);		//�߹�����ջ�ĳ���
void MakeMove(int currChessBoard[][9],MovedLink* top, int xSPos, int ySPos, int xEPos, int yEPos);		//��һ�����ҰѲ�����¼����ջ��
void unMakeMove(int currChessBoar[][9],MovedLink* top);	//�����Ѿ��߹��Ĳ������ҳ�ջ*/
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
