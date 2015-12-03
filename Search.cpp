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
	MoveLink p = (*top);
	(*top) = (*top)->next;
	return p;
}
MoveLink Search(int currChessBoard[][9], int depth)
{
	int Max_depth;				//最大深度
	int sore;				//当前得分
	int Max_sore;		//最大得分
	MoveLink Head;			//每次产生步伐的栈
	MoveLink top = NULL;		//保存所有步伐的栈顶
	MoveLink p,q;
	MoveLink NowNode;			//当前弹出的步伐
	MoveLink BestFirstMove=NULL;			//保存最优的头一步
	MoveLink CurrFirstMove=NULL;			//保存当前的头一步
	MovedLink MovedTop = NULL;
	Max_depth = depth;
	Head = MoveGenerator(currChessBoard,(Max_depth-depth+1)%2);		//第一次产生向下一层的步伐
	p = Head;		
	q = p;		//保存返回的头结点
	while (p->next != NULL)	
	{
		p = p->next;	//找到搜索的最后一步
	}
	p->next = top;		//与原本的栈相接
	top = q->next;		//使top指向栈的头结点
	//while (p->next != NULL)		//将这次搜索的步伐进栈
	//{
	//	p = p->next;
	//	PushStep(&top, p);
	//}
	while(!IsEmptyStack(top))		//如果步伐栈不为空
	{
		NowNode = PopStep(&top);
		if (depth == Max_depth)		//获取当前搜索的第一步走法
		{
			CurrFirstMove= NowNode;
		}
		MakeMove(currChessBoard,&MovedTop,NowNode->xSPos, NowNode->ySPos, NowNode->xEPos, NowNode->yEPos);		//走出一步
		depth--;
		while (depth >= 1)
		{
			if (depth =1)		//如果是倒数到达了倒数第二部则不入栈直接对产生的所有步伐进行遍历
			{
				Head = MoveGenerator(currChessBoard,depth%2);
				p = Head;
				while (p->next != NULL)
				{
					p = p->next;
					MakeMove(currChessBoard,&MovedTop,p->xSPos, p->ySPos, p->xEPos, p->yEPos);		//走最后一步
					sore = Evaluation(currChessBoard, (Max_depth - depth) % 2);		//对最后一步进行评价
					if (sore > Max_depth)
					{
						Max_depth = sore;				//保存当前的最大评分
						BestFirstMove = CurrFirstMove;		//将最头部的一个步伐保存入结构中
					}
					unMakeMove(currChessBoard,&MovedTop);
				}
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
				p->next = top;		//与原本的栈相接
				top = q;		//使top指向栈的头结点
				//while (p->next != NULL)		//将这次搜索的步伐进栈
				//{
				//	p = p->next;
				//	PushStep(&top, p);
				//}
			}
			
		}
	}
	return BestFirstMove;
}