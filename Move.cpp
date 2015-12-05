#include"Move.h"
void Push(MovedLink* top, int xSPos, int ySPos, int xEPos, int yEPos, int echess)		//已走过的步伐进栈
{
	MovedLink p = (MovedLink)malloc(sizeof(Moved));
	p->xSPos = xSPos;
	p->ySPos = ySPos;
	p->xEPos = xEPos;
	p->yEPos = yEPos;
	p->echess = echess;
	p->next = *top;
	*top = p;
}
MovedLink Pop(MovedLink* top)		//所有已走过的步伐出栈
{
	if (*top == NULL)		//此时已经没有走过的步伐了
	{
		printf("栈空");
		return NULL;
	}
	MovedLink q = (*top);
	(*top) = q->next;
	return q;
}
int MovedStackLength(MovedLink top)		//步伐栈的长度
{
	int length = 0;
	MovedLink p;
	p = top;
	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	return length;
}
void MakeMove(int currChessBoard[][9],MovedLink* top,int xSPos,int ySPos,int xEPos,int yEPos)		//走出一步，并且把走过的步伐保存入已走过的步伐的栈中
{
	int i = currChessBoard[xEPos][yEPos];
	currChessBoard[xEPos][yEPos] = currChessBoard[xSPos][ySPos];		//更改棋盘
	currChessBoard[xSPos][ySPos] = NO_CHESS;			//更改棋盘
	Push(top, xSPos, ySPos, xEPos, yEPos, i);		//把已走过的步伐进栈，top为全局变量
}
void unMakeMove(int currChessBoard[][9], MovedLink* top)	//退回一步就并且出栈
{
	MovedLink move = Pop(top);		//出栈
	int xSPos = move->xSPos;
	int ySPos = move->ySPos;
	int xEPos = move->xEPos;
	int yEPos = move->yEPos; 
	int i = currChessBoard[xEPos][yEPos];		//当时移动的棋子
	int j = move->echess;				//被覆盖的棋子
	currChessBoard[xSPos][ySPos] = i;
	currChessBoard[xEPos][yEPos] = j;
	free(move);
}