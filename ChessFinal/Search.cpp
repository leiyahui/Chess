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
	MovedLink MovedTop = NULL;					//走过的步栈顶
	int xSPos, ySPos, xEPos, yEPos;				//当前坐标
	int FStepxSPos, FStepySPos, FStepxEPos, FStepyEPos;		//存储第一步走法
	Max_depth = depth;				//最大深度
	int depth0,depth1, depth2, depth3, depth4, depth5;		//测试使用
	int IsFirstdepth[10] = { 0 };		//记录是否是每层深度的第一步
	int MaxMin[10] = { 0 };		//存放每一层当前的最大最小值
	int Best_MaxMin[10] = { 0 };	//存放当前的的最优解
	Head = MoveGenerator(currChessBoard,(Max_depth-depth+1)%2);		//第一次产生向下一层的步伐
	p = Head;		
	q = p;		//保存返回的头结点
	while (p->next != NULL)	
	{
		p = p->next;	//找到搜索的最后一步
	}
	top = q->next;		//使top指向栈的头结点
	while(!IsEmptyStack(top))		//如果步伐栈不为空
	{
		NowNode = PopStep(&top);		//从栈中取步伐
		xSPos = NowNode->xSPos;			
		ySPos = NowNode->ySPos;
		xEPos = NowNode->xEPos;
		yEPos = NowNode->yEPos;
		free(NowNode);		//将节点释放
		if (depth == 5)
		{
			FStepxSPos = xSPos;					//记录下这一次搜所的第一步
			FStepySPos = ySPos;
			FStepxEPos = xEPos;
			FStepyEPos = yEPos;
		}
		while ((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL)&&(yEPos == NULL))		//当返回到上一级的时候
		{
			unMakeMove(currChessBoard,&MovedTop);	//步伐返回
			depth++;
			if (IsEmptyStack(top))
			{
				while (MovedTop != NULL)
				{
					unMakeMove(currChessBoard, &MovedTop);
				}
				return BestFirstMove;
			}
			NowNode = PopStep(&top);			//因为刚才取出的节点是空的所以说从新取出节点
			xSPos = NowNode->xSPos;
			ySPos = NowNode->ySPos;
			xEPos = NowNode->xEPos;
			yEPos = NowNode->yEPos;
			free(NowNode);
			MaxMin[depth - 1] = Best_MaxMin[depth - 2];		//将下一层的值赋给上一层
			if (IsFirstdepth[depth - 1] == 0)
			{
				Best_MaxMin[depth - 1] = MaxMin[depth - 1];
				IsFirstdepth[depth - 1]++;
				if (depth == Max_depth)
				{
					BestFirstMove->xSPos = FStepxSPos;
					BestFirstMove->ySPos = FStepySPos;
					BestFirstMove->xEPos = FStepxEPos;
					BestFirstMove->yEPos = FStepyEPos;
					FStepxSPos = xSPos;					//记录下这一次搜所的第一步
					FStepySPos = ySPos;
					FStepxEPos = xEPos;
					FStepyEPos = yEPos;
				}
				if (depth % 2)
				{
					if (depth != Max_depth)
					{
						if (IsFirstdepth[depth] != 0)
						{
							if (Best_MaxMin[depth - 1] > Best_MaxMin[depth])
							{
								do			//此时倒数第二层没有遍历下去的需要了
								{
									NowNode = PopStep(&top);
									xSPos = NowNode->xSPos;
									ySPos = NowNode->ySPos;
									xEPos = NowNode->xEPos;
									yEPos = NowNode->yEPos;
									free(NowNode);
								} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//循环直到倒数第二层遍历完
								unMakeMove(currChessBoard, &MovedTop);
								IsFirstdepth[depth - 1] = 0;
								depth++;
							}
						}
					}
				}
				else
				{
					if (IsFirstdepth[depth] != 0)
					{
						if (Best_MaxMin[depth - 1] < Best_MaxMin[depth])
						{
							do			//此时倒数第二层没有遍历下去的需要了
							{
								NowNode = PopStep(&top);
								xSPos = NowNode->xSPos;
								ySPos = NowNode->ySPos;
								xEPos = NowNode->xEPos;
								yEPos = NowNode->yEPos;
								free(NowNode);
							} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//循环直到倒数第二层遍历完
							unMakeMove(currChessBoard, &MovedTop);
							IsFirstdepth[depth - 1] = 0;
							depth++;
						}
					}
				}
			}
			else
			{
				if (depth % 2)				//这层是需要最大值的
				{
					IsFirstdepth[depth - 1]++;
					if (MaxMin[depth - 1] > Best_MaxMin[depth - 1])
					{
						Best_MaxMin[depth - 1] = MaxMin[depth - 1];
						if (depth == Max_depth)
						{
							BestFirstMove->xSPos = FStepxSPos;
							BestFirstMove->ySPos = FStepySPos;
							BestFirstMove->xEPos = FStepxEPos;
							BestFirstMove->yEPos = FStepyEPos;
							FStepxSPos = xSPos;					//记录下这一次搜所的第一步
							FStepySPos = ySPos;
							FStepxEPos = xEPos;
							FStepyEPos = yEPos;
						}
						if (depth != Max_depth)			//最高层不需要剪枝
						{
							if (IsFirstdepth[depth] != 0)
							{
								if (Best_MaxMin[depth - 1] > Best_MaxMin[depth])
								{
									do			//此时倒数第二层没有遍历下去的需要了
									{
										NowNode = PopStep(&top);
										xSPos = NowNode->xSPos;
										ySPos = NowNode->ySPos;
										xEPos = NowNode->xEPos;
										yEPos = NowNode->yEPos;
										free(NowNode);
									} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//循环直到倒数第二层遍历完
									unMakeMove(currChessBoard, &MovedTop);
									IsFirstdepth[depth - 1] = 0;
									depth++;
								}
							}
						}
					}
				}
				else
				{
					IsFirstdepth[depth - 1]++;
					if (MaxMin[depth - 1] < Best_MaxMin[depth - 1])
					{
						Best_MaxMin[depth - 1] = MaxMin[depth - 1];
						if (IsFirstdepth[depth] != 0)
						{
							if (Best_MaxMin[depth - 1] < Best_MaxMin[depth])		//进行剪枝
							{
								do			//此时倒数第二层没有遍历下去的需要了
								{
									NowNode = PopStep(&top);
									xSPos = NowNode->xSPos;
									ySPos = NowNode->ySPos;
									xEPos = NowNode->xEPos;
									yEPos = NowNode->yEPos;
									free(NowNode);
								} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//循环直到倒数第二层遍历完
								unMakeMove(currChessBoard, &MovedTop);
								IsFirstdepth[depth - 1] = 0;
								depth++;
							}
						}
					}
				}
			}
		}
		MakeMove(currChessBoard,&MovedTop,xSPos,ySPos,xEPos, yEPos);		//走出一步
		depth--;	//深度减一
		if (IsBlackFail(currChessBoard))		//黑棋失败
		{
			return BestFirstMove;
		}
		if (IsRedFail(currChessBoard))		//红棋失败
		{
			unMakeMove(currChessBoard, &MovedTop);
			continue;
		}
			if (depth ==1)		//还差最后一步没有访问
			{
				Head = MoveGenerator(currChessBoard,depth%2);
				IsFirstdepth[depth - 1] = 0;
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
					MaxMin[depth-1] = Evaluation(currChessBoard,1);		//对最后一步进行评价
					if (IsFirstdepth[depth-1] == 0)
					{
						Best_MaxMin[depth - 1] = MaxMin[depth - 1];
						if (IsFirstdepth[depth] != 0)
						{
							if (Best_MaxMin[depth - 1] > Best_MaxMin[depth])
							{
								break;
							}
						}
					}
					else
					{
						if (MaxMin[depth - 1] > Best_MaxMin[depth - 1])
						{
							Best_MaxMin[depth - 1] = MaxMin[depth - 1];
							if (IsFirstdepth[depth] != 0)
							{
								if (Best_MaxMin[depth - 1] > Best_MaxMin[depth])
								{
									break;
								}
							}
						}
					}
					IsFirstdepth[depth - 1]++;
					unMakeMove(currChessBoard,&MovedTop);
				}
				unMakeMove(currChessBoard, &MovedTop);			//倒数第二步返回
				depth++;
				MaxMin[depth - 1] = Best_MaxMin[depth - 2];		//将下层的最大值赋给上层
				if (IsFirstdepth[depth-1] == 0)
				{
					Best_MaxMin[depth - 1] = MaxMin[depth - 2];
					IsFirstdepth[depth - 1]++;
					if (IsFirstdepth[depth] != 0)
					{
						if (Best_MaxMin[depth - 1] > Best_MaxMin[depth])
						{
							do			//此时倒数第二层没有遍历下去的需要了
							{
								NowNode = PopStep(&top);			
								xSPos = NowNode->xSPos;
								ySPos = NowNode->ySPos;
								xEPos = NowNode->xEPos;
								yEPos = NowNode->yEPos;
								free(NowNode);
							} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//循环直到倒数第二层遍历完
							unMakeMove(currChessBoard, &MovedTop);
							IsFirstdepth[depth - 1] = 0;
							depth++;
						}
					}
				}
				else
				{
					IsFirstdepth[depth - 1]++;
					if (MaxMin[depth - 1] < Best_MaxMin[depth - 1])
					{
						Best_MaxMin[depth - 1] = MaxMin[depth - 1];
						if (IsFirstdepth[depth] != 0)
						{
							if (Best_MaxMin[depth - 1] < Best_MaxMin[depth])
							{
								do			//此时倒数第二层没有遍历下去的需要了
								{
									NowNode = PopStep(&top);
									xSPos = NowNode->xSPos;
									ySPos = NowNode->ySPos;
									xEPos = NowNode->xEPos;
									yEPos = NowNode->yEPos;
									free(NowNode);
								} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//循环直到倒数第二层遍历完
								unMakeMove(currChessBoard, &MovedTop);
								IsFirstdepth[depth - 1] = 0;
								depth++;
							}
						}
					}
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
				p->next = (MoveLink)malloc(sizeof(Move));		//新建一个节点作为返回上一级的标识节点，这个节点完全为空
				(p->next)->xSPos = NULL;
				(p->next)->ySPos = NULL;
				(p->next)->xEPos = NULL;
				(p->next)->yEPos = NULL;
				(p->next)->next = top;		//与原本的栈相接
				top = q->next;		//使top指向栈的头结点
			}
	}
	while (MovedTop != NULL)
	{
		unMakeMove(currChessBoard,&MovedTop);
	}
	return BestFirstMove;
}