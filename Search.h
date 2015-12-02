
#include "MoveGenerator.h"
#include "Move.h"
void PushStep(MoveLink* top, MoveLink t);		//将步伐进栈
MoveLink PopStep(MoveLink* top);			//将步伐出栈
MoveLink Search(int currChessBoard[][9], int depth);		//向下搜索depth步，找出最优的步伐
bool IsEmptyStack(MoveLink top);		//是否栈空