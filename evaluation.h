#ifndef _EVALUATION_H
#define _EVALUATION_H
#include"chess.h"
#include"search.h"
#include"is_valid_pos.h"
#define BASEVALUE_PAWN 10
#define BASEVALUE_BISHOP 20
#define BASEVALUE_ELEPHANT 20
#define BASEVALUE_HORSE 40
#define BASEVALUE_CAR 90
#define BASEVALUE_CANON 45
#define BASEVALUE_KING 10000
#define FLEXIBILTY_PAWN 2
#define FLEXIBILTY_BISHOP 2
#define FLEXIBILTY_ELEPHANT 2
#define FLEXIBILTY_CAR 4
#define FLEXIBILTY_HORSE 5
#define FLEXIBILTY_CANON 3
#define FLEXIBILTY_KING 2
typedef struct ReleatedNode		
{
	int xEPos;
	int yEPos;
	ReleatedNode* next;
}LReleatedNode, *LReleatedList;
static int flex_pos_value();
int evaluation();		//给一个棋盘评价
#endif
