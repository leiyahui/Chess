
#include "MoveGenerator.h"
#include "Move.h"
void PushStep(MoveLink* top, MoveLink t);		//将步伐进栈
MoveLink PopStep(MoveLink* top);			//将步伐出栈
int StackLength(MoveLink top);		//步伐栈的长度
MoveLink Search(int currChessBoard[][9], int depth);		//向下搜索depth步，找出最优的步伐
bool IsEmptyStack(MoveLink top);		//是否栈空
int IsBlackFail(int currChessBoard[][9]);		//黑棋是否失败
int IsRedFail(int currChessBoard[][9]);		//红旗是否失败