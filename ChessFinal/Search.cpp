#include "Search.h"
#include "Evalution.h"
bool IsEmptyStack(MoveLink top)	 //�Ƿ�ջ��
{
	if (top == NULL)
	{
		return true;
	}
	return false;
}
void PushStep(MoveLink* top, MoveLink t)		//��ջ
{
	t->next = *top;		//��ǰ�ڵ�ָ���²���Ľڵ�
	(*top) = t;				//����ǰ�ڵ��Ϊ����Ľڵ�
}
MoveLink PopStep(MoveLink* top)		//��ջ
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
int IsBlackFail(int currChessBoard[][9])		//�жϺ�����û���䣬�������û���䷵��0�����򷵻�1
{
	int i, j;
	for (i = 0; i <= 2; i++)
	{
		for (j = 3; j<= 5; j++)
		{
			if (currChessBoard[i][j] == B_King)
			{
				return 0;			//����û����
			}
		}
	}
	return 1;
}
int IsRedFail(int currChessBoard[][9])		//�жϺ�����û���䣬���û���䷵��0�����򷵻�1
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
	int length;		//����ջ�еĲ�������,�����õ�һ��Ҫɾ��
	int movedLength;		//�߹��Ĳ�����ջ�еĳ���,������һ��ɾ��
	int Max_depth;				//������
	int sore;				//��ǰ�÷�
	int Best_sore=0;		//���÷�
	MoveLink Head;			//ÿ�β���������ջ
	MoveLink top = NULL;		//�������в�����ջ��
	MoveLink p,q;
	MoveLink NowNode;			//��ǰ�����Ĳ���
	MoveLink BestFirstMove=(MoveLink)malloc(sizeof(Move));			//�������ŵ�ͷһ��
	MoveLink CurrFirstMove=(MoveLink)malloc(sizeof(Move));			//���浱ǰ��ͷһ��
	MovedLink MovedTop = NULL;
	long int xSPos, ySPos, xEPos, yEPos;
	long int depth5 = 0;     //�����õ�
	long int depth4 = 0;     //�����õ�
	long int depth3 = 0;     //�����õ�
	long int depth2 = 0;     //�����õ�
	long int depth1 = 0;     //�����õ�
	Max_depth = depth;
	int MaxMin[10] = { -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000 };		//���ÿһ�㵱ǰ�������Сֵ
	int Best_MaxMin[10] = { -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000 };	//��ŵ�ǰ�ĵ����Ž�
	Head = MoveGenerator(currChessBoard,(Max_depth-depth+1)%2);		//��һ�β�������һ��Ĳ���
	p = Head;		
	q = p;		//���淵�ص�ͷ���
	while (p->next != NULL)	
	{
		p = p->next;	//�ҵ����������һ��
	}
	top = q->next;		//ʹtopָ��ջ��ͷ���
	length = StackLength(top);
	//while (p->next != NULL)		//����������Ĳ�����ջ
	//{
	//	p = p->next;
	//	PushStep(&top, p);
	//}
	while(!IsEmptyStack(top))		//�������ջ��Ϊ��
	{
		NowNode = PopStep(&top);		//��ջ��ȡ����
		xSPos = NowNode->xSPos;			
		ySPos = NowNode->ySPos;
		xEPos = NowNode->xEPos;
		yEPos = NowNode->yEPos;
		free(NowNode);		//���ڵ��ͷ�
		if (depth % 2)		//��ͬһ�������о��߳����ֵ
		{
			if (MaxMin[depth - 1] > Best_MaxMin[depth - 1])
			{
				Best_MaxMin[depth - 1] = MaxMin[depth - 1];
			}
			
		}
		else		//��ͬһ�������о��߳���Сֵ
		{
			if (MaxMin[depth - 1] < Best_MaxMin[depth - 1])
			{
				Best_MaxMin[depth - 1] = MaxMin[depth - 1];
			}
		}
		while ((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL)&(yEPos == NULL))		//�����ص���һ����ʱ��
		{
			unMakeMove(currChessBoard,&MovedTop);	//��������
			depth++;
			NowNode = PopStep(&top);			//��Ϊ�ղ�ȡ���Ľڵ��ǿյ�����˵����ȡ���ڵ�
			xSPos = NowNode->xSPos;
			ySPos = NowNode->ySPos;
			xEPos = NowNode->xEPos;
			yEPos = NowNode->yEPos;
			free(NowNode);
			MaxMin[depth - 1] = Best_MaxMin[depth - 2];		//����һ������������Сֵ������һ��
			if (depth % 2)
			{
				Best_MaxMin[depth - 2] = -10000;			//���¸����ֵ��ֵ
				MaxMin[depth - 2] = -10000;
			}
			else
			{
				Best_MaxMin[depth - 2] = 10000;			//���¸���Сֵ��ֵ
				MaxMin[depth - 2] = 10000;
			}
			
			
		}
		if (depth == Max_depth )		//��ȡ��ǰ�����ĵ�һ���߷�
		{
			if (MaxMin[depth - 1] > Best_MaxMin[depth - 1])
			{
				Best_MaxMin[depth - 1] = MaxMin[depth - 1];
				BestFirstMove->xSPos = xSPos;
				BestFirstMove->ySPos = ySPos;
				BestFirstMove->xEPos = xEPos;
				BestFirstMove->yEPos = yEPos;
			}
			depth5++;
		}
		if (depth == (Max_depth - 1))		//�����õ�
		{
			depth4++;
		}
		if (depth == (Max_depth - 2))		//�����õ�
		{
			depth3++;
		}
		if (depth == (Max_depth - 3))		//�����õ�
		{
			depth2++;
		}
		
		length = StackLength(top);
		MakeMove(currChessBoard,&MovedTop,xSPos,ySPos,xEPos, yEPos);		//�߳�һ��
		if (IsBlackFail(currChessBoard))		//����ʧ��
		{
			return BestFirstMove;
		}
		if (IsRedFail(currChessBoard))		//����ʧ��
		{
			break;
		}
		movedLength = MovedStackLength(MovedTop);
		depth--;	//��ȼ�һ
			if (depth ==1)		//����ǵ��������˵����ڶ�������ջֱ�ӶԲ��������в������б���
			{
				Head = MoveGenerator(currChessBoard,depth%2);
				p = Head;
				Best_MaxMin[depth-1]=-10000;
				while (p->next != NULL)
				{
					q = p;
					p = p->next;
					free(q);
					xSPos = p->xSPos;
					ySPos = p->ySPos;
					xEPos = p->xEPos;
					yEPos = p->yEPos;
					MakeMove(currChessBoard,&MovedTop,xSPos,ySPos, xEPos, yEPos);		//�����һ��
					movedLength = MovedStackLength(MovedTop);
					MaxMin[depth-1] = Evaluation(currChessBoard);		//�����һ����������
					depth1++;		//�����õ�
					if (MaxMin[depth-1] >Best_MaxMin[depth-1])
					{
						Best_MaxMin[depth-1] = MaxMin[depth-1];
					}
					unMakeMove(currChessBoard,&MovedTop);
					movedLength = MovedStackLength(MovedTop);
				}
				unMakeMove(currChessBoard, &MovedTop);
				depth++;
				MaxMin[depth - 1] = Best_MaxMin[depth - 2];		//���²�����ֵ�����ϲ�
			}
			else		//�����������������ջ
			{
				Head = MoveGenerator(currChessBoard,depth%2);
				p = Head;
				q = p;		//���淵�ص�ͷ���
				while (p->next != NULL)
				{
					p = p->next;	//�ҵ����������һ��
				}
				p->next = (MoveLink)malloc(sizeof(Move));		//�½�һ���ڵ���Ϊ������һ���ı�ʶ�ڵ㣬����ڵ���ȫΪ��
				(p->next)->xSPos = NULL;
				(p->next)->ySPos = NULL;
				(p->next)->xEPos = NULL;
				(p->next)->yEPos = NULL;
				(p->next)->next = top;		//��ԭ����ջ���
				top = q->next;		//ʹtopָ��ջ��ͷ���
				//while (p->next != NULL)		//����������Ĳ�����ջ
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