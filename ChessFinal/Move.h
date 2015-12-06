#include "chess.h"
typedef struct MakedMove		//记录已经走过的步伐
{
	int xSPos;
	int ySPos;
	int xEPos;
	int yEPos;
	int echess;			//被覆盖的棋子
	MakedMove* next;
}Moved,*MovedLink;
void Push(MovedLink* top, int xSPos, int ySPos, int xEPos, int yEPos, int eChess);		//将走过路进栈
MovedLink Pop(MovedLink* top);	//将走过的步伐出栈
int MovedStackLength(MovedLink top);		//走过步伐栈的长度
void MakeMove(int currChessBoard[][9],MovedLink* top, int xSPos, int ySPos, int xEPos, int yEPos);		//走一步并且把步伐记录进入栈中
void unMakeMove(int currChessBoar[][9],MovedLink* top);	//返回已经走过的步伐并且出栈
