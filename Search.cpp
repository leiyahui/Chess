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
	MoveLink p = (*top);
	(*top) = (*top)->next;
	return p;
}
MoveLink Search(int currChessBoard[][9], int depth)
{
	int Max_depth;				//������
	int sore;				//��ǰ�÷�
	int Best_sore=0;		//���÷�
	MoveLink Head;			//ÿ�β���������ջ
	MoveLink top = NULL;		//�������в�����ջ��
	MoveLink p,q;
	MoveLink NowNode;			//��ǰ�����Ĳ���
	MoveLink BestFirstMove=NULL;			//�������ŵ�ͷһ��
	MoveLink CurrFirstMove=NULL;			//���浱ǰ��ͷһ��
	MovedLink MovedTop = NULL;
	Max_depth = depth;
	Head = MoveGenerator(currChessBoard,(Max_depth-depth+1)%2);		//��һ�β�������һ��Ĳ���
	p = Head;		
	q = p;		//���淵�ص�ͷ���
	while (p->next != NULL)	
	{
		p = p->next;	//�ҵ����������һ��
	}
	p->next = (MoveLink)malloc(sizeof(Move));		//�½�һ���ڵ���Ϊ��ʶ�ڵ㣬�˽ڵ���ȫΪ��
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
	while(!IsEmptyStack(top))		//�������ջ��Ϊ��
	{
		NowNode = PopStep(&top);
		while ((NowNode->xSPos == NULL) && (NowNode->ySPos == NULL) && (NowNode->xEPos == NULL)&(NowNode->yEPos == NULL))
		{
			unMakeMove(currChessBoard,&MovedTop);
			depth++;
			NowNode = PopStep(&top);
		}
		if (depth == Max_depth)		//��ȡ��ǰ�����ĵ�һ���߷�
		{
			CurrFirstMove= NowNode;
		}
		MakeMove(currChessBoard,&MovedTop,NowNode->xSPos, NowNode->ySPos, NowNode->xEPos, NowNode->yEPos);		//�߳�һ��
		depth--;
			if (depth =1)		//����ǵ��������˵����ڶ�������ջֱ�ӶԲ��������в������б���
			{
				Head = MoveGenerator(currChessBoard,depth%2);
				p = Head;
				while (p->next != NULL)
				{
					p = p->next;
					MakeMove(currChessBoard,&MovedTop,p->xSPos, p->ySPos, p->xEPos, p->yEPos);		//�����һ��
					depth--;
					sore = Evaluation(currChessBoard, (Max_depth - depth) % 2);		//�����һ����������
					if ((Max_depth % 2) == 1)		//�������������
					{
						if (sore > Best_sore)
						{
							Best_sore = sore;				//���浱ǰ���������
							BestFirstMove = CurrFirstMove;		//����ͷ����һ������������ṹ��
						}
					}
					else
					{
						if (sore < Best_sore)
						{
							Best_sore = sore;			//����������С��
							BestFirstMove = CurrFirstMove;
						}
					}
					unMakeMove(currChessBoard,&MovedTop);
					depth++;
				}
				unMakeMove(currChessBoard, &MovedTop);
				depth++;
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
	return BestFirstMove;
}