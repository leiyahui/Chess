#include "Search.h"
#include "Evalution.h"
bool IsEmptyStack(MoveLink top)	 //是否栈空
{
	if (top == NULL)
	{
		return true;
	}
	return false;
}
void PushStep(MoveLink* top, MoveLink t)		//入栈
{
	t->next = *top;		//当前节点指向新插入的节点
	(*top) = t;				//将当前节点变为插入的节点
}
MoveLink PopStep(MoveLink* top)		//出栈
{
	MoveLink p;
	p = (*top);
	(*top) = p->next;
	return p;
}
int StackLength(MoveLink top)
{
	int length = 0;
	MoveLink p;
	p = top;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}
int IsBlackFail(int currChessBoard[][9])		//判断黑棋有没有输，如果黑棋没有输返回0，否则返回1
{
	int i, j;
	for (i = 0; i <= 2; i++)
	{
		for (j = 3; j<= 5; j++)
		{
			if (currChessBoard[i][j] == B_King)
			{
				return 0;			//黑棋没有输
			}
		}
	}
	return 1;
}
int IsRedFail(int currChessBoard[][9])		//判断红棋有没有输，如果没有输返回0，否则返回1
{
	int i, j;
	for (i = 7; i <= 9; i++)
	{
		for (j = 3; j <= 5; j++)
		{
			if (currChessBoard[i][j] == R_King)
			{
				return 0;
			}
		}
	}
	return 1;
}
MoveLink Search(int currChessBoard[][9], int depth)
{
	int length;		//步伐栈中的步伐数量,测试用的一会要删除
	int movedLength;		//走过的步伐的栈中的长度,测试用一会删除
	int Max_depth;				//最大深度
	int sore;				//当前得分
	int Best_sore=0;		//最大得分
	MoveLink Head;			//每次产生步伐的栈
	MoveLink top = NULL;		//保存所有步伐的栈顶
	MoveLink p,q;
	MoveLink NowNode;			//当前弹出的步伐
	MoveLink BestFirstMove=(MoveLink)malloc(sizeof(Move));			//保存最优的头一步
	MoveLink CurrFirstMove=(MoveLink)malloc(sizeof(Move));			//保存当前的头一步
	MovedLink MovedTop = NULL;
	int xSPos, ySPos, xEPos, yEPos;
	Max_depth = depth;
	Head = MoveGenerator(currChessBoard,(Max_depth-depth+1)%2);		//第一次产生向下一层的步伐
	p = Head;		
	q = p;		//保存返回的头结点
	while (p->next != NULL)	
	{
		p = p->next;	//找到搜索的最后一步
	}
	top = q->next;		//使top指向栈的头结点
	length = StackLength(top);
	//while (p->next != NULL)		//将这次搜索的步伐进栈
	//{
	//	p = p->next;
	//	PushStep(&top, p);
	//}
	while(!IsEmptyStack(top))		//如果步伐栈不为空
	{
		NowNode = PopStep(&top);
		xSPos = NowNode->xSPos;
		ySPos = NowNode->ySPos;
		xEPos = NowNode->xEPos;
		yEPos = NowNode->yEPos;
		free(NowNode);
		while ((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL)&(yEPos == NULL))
		{
			unMakeMove(currChessBoard,&MovedTop);
			depth++;
			NowNode = PopStep(&top);
			xSPos = NowNode->xSPos;
			ySPos = NowNode->ySPos;
			xEPos = NowNode->xEPos;
			yEPos = NowNode->yEPos;
			free(NowNode);
		}
		if (depth == Max_depth )		//获取当前搜索的第一步走法
		{
			CurrFirstMove->xSPos = xSPos;
			CurrFirstMove->ySPos = ySPos;
			CurrFirstMove->xEPos = xEPos;
			CurrFirstMove->yEPos = yEPos;
		}
		
		length = StackLength(top);
		MakeMove(currChessBoard,&MovedTop,xSPos,ySPos,xEPos, yEPos);		//走出一步
		if (IsBlackFail(currChessBoard))		//黑棋失败
		{
			return CurrFirstMove;
		}
		if (IsRedFail(currChessBoard))		//红棋失败
		{
			break;
		}
		movedLength = MovedStackLength(MovedTop);
		depth--;	//深度减一
			if (depth ==1)		//如果是倒数到达了倒数第二部则不入栈直接对产生的所有步伐进行遍历
			{
				Head = MoveGenerator(currChessBoard,depth%2);
				p = Head;
				while (p->next != NULL)
				{
					q = p;
					p = p->next;
					free(q);
					xSPos = p->xSPos;
					ySPos = p->ySPos;
					xEPos = p->xEPos;
					yEPos = p->yEPos;
					MakeMove(currChessBoard,&MovedTop,xSPos,ySPos, xEPos, yEPos);		//走最后一步
					movedLength = MovedStackLength(MovedTop);
					sore = Evaluation(currChessBoard);		//对最后一步进行评价
					if (sore > Best_sore)
					{
						Best_sore = sore;
						BestFirstMove = CurrFirstMove;
						BestFirstMove->xSPos = CurrFirstMove->xSPos;
						BestFirstMove->ySPos = CurrFirstMove->ySPos;
						BestFirstMove->xEPos = CurrFirstMove->xEPos;
						BestFirstMove->yEPos = CurrFirstMove->yEPos;
					}
					unMakeMove(currChessBoard,&MovedTop);
					movedLength = MovedStackLength(MovedTop);
				}
				unMakeMove(currChessBoard, &MovedTop);
				depth++;
			}
			else		//否则产生步伐并且入栈
			{
				Head = MoveGenerator(currChessBoard,depth%2);
				p = Head;
				q = p;		//保存返回的头结点
				while (p->next != NULL)
				{
					p = p->next;	//找到搜索的最后一步
				}
				p->next = (MoveLink)malloc(sizeof(Move));		//新建一个节点作为返回上一级的标识节点，这个节点完全为空
				(p->next)->xSPos = NULL;
				(p->next)->ySPos = NULL;
				(p->next)->xEPos = NULL;
				(p->next)->yEPos = NULL;
				(p->next)->next = top;		//与原本的栈相接
				top = q->next;		//使top指向栈的头结点
				//while (p->next != NULL)		//将这次搜索的步伐进栈
				//{
				//	p = p->next;
				//	PushStep(&top, p);
				//}
			}
	}
	while (MovedTop != NULL)
	{
		unMakeMove(currChessBoard,&MovedTop);
	}
	return BestFirstMove;
}