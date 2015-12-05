#include"chess.h"
//价值的定义
#define BASEVALUE_PAWN 100
#define BASEVALUE_BISHOP 250
#define BASEVALUE_ELEPHANT 250
#define BASEVALUE_HORSE 400
#define BASEVALUE_CAR 1000
#define BASEVALUE_CANON 500
#define BASEVALUE_KING 10000
#define FLEXIBILTY_PAWN 15
#define FLEXIBILTY_BISHOP 1
#define FLEXIBILTY_ELEPHANT 1
#define FLEXIBILTY_CAR 12
#define FLEXIBILTY_HORSE 30
#define FLEXIBILTY_CANON 12
#define FLEXIBILTY_KING 20
typedef struct ReleatedNode		//跟一个棋子相关的节点
{
	int xEPos;
	int yEPos;
	ReleatedNode* next;
}LReleatedNode, *LReleatedList;

const int BAO[10][9] =		//黑兵的基础值的定义
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	90, 90, 110, 120, 120, 120, 110, 90, 90,
	90, 90, 110, 120, 120, 120, 110, 90, 90,
	70, 90, 110, 110, 110, 110, 110, 90, 70,
	70, 70, 70, 70, 70, 70, 70, 70, 70,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
};
const int BA1[10][9] =		//红兵的基础知识的定义
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	70, 70, 70, 70, 70, 70, 70, 70, 70,
	70, 90, 110, 110, 110, 110, 110, 90, 70,
	90, 90, 110, 120, 120, 120, 110, 90, 90,
	90, 90, 110, 120, 120, 120, 110, 90, 90,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
};
const int m_BaseValue[15] =
{
	0, BASEVALUE_CAR, BASEVALUE_HORSE, BASEVALUE_CANON, BASEVALUE_ELEPHANT, BASEVALUE_BISHOP, BASEVALUE_PAWN, BASEVALUE_KING,
	BASEVALUE_CAR, BASEVALUE_HORSE, BASEVALUE_CANON, BASEVALUE_ELEPHANT, BASEVALUE_BISHOP, BASEVALUE_PAWN, BASEVALUE_KING
};
const int m_FlexValue[15] =
{
	0, FLEXIBILTY_CAR, FLEXIBILTY_HORSE, FLEXIBILTY_CANON, FLEXIBILTY_ELEPHANT, FLEXIBILTY_BISHOP, FLEXIBILTY_PAWN, FLEXIBILTY_KING,
	FLEXIBILTY_CAR, FLEXIBILTY_HORSE, FLEXIBILTY_CANON, FLEXIBILTY_ELEPHANT, FLEXIBILTY_BISHOP, FLEXIBILTY_PAWN, FLEXIBILTY_KING
};
void PushReleatedMove(LReleatedList* top, int xEPos, int yEPos);		//将相关联的步伐进栈
LReleatedList PopReleatedMove(LReleatedList* top);	//将相关两的步伐出栈
int GetBingValue(int x, int y, int position[10][9]); //获取兵的价值
LReleatedList GetReleatedPiece(int currChessboard[][9], int xSPos, int ySPos);		//获取一个棋子所相关的棋子链表,返回头结点指针
int Evaluation(int currChessBoard[][9]);		//给一个棋盘评价