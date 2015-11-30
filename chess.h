#include<stdio.h>
#include<stdlib.h>
//棋子的定义
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
#define IsBlack(chess)	(1<=(chess)<=7?1:0)
#define IsRed(chess)	(8<=(chess)<=14?1:0)
#define IsSameCol(chess1,chess2)	(IsBlack(chess1)&&IsBlack(chess2)||IsRed(chess1)&&IsRed(chess2))

typedef struct ReleatedNode		//跟一个棋子相关的节点
{
	int xEPos;
	int yEPos;
	ReleatedNode* next;
}LReleatedNode,*LReleatedList;
