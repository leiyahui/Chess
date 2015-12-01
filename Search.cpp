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
void Push(MoveLink* top, MoveLink t)		//��ջ
{
	t->next = *top;		//��ǰ�ڵ�ָ���²���Ľڵ�
	(*top) = t;				//����ǰ�ڵ��Ϊ����Ľڵ�
}
MoveLink Pop(MoveLink* top)		//��ջ
{
	MoveLink p = (*top);
	(*top) = (*top)->next;
	return p;
}
MoveLink Search(int currChessBoard[][9], int depth)
{
	int Max_depth;				//������
	int sore;				//��ǰ�÷�
	int Max_sore;		//���÷�
	MoveLink Head;			//ÿ�β���������ջ
	MoveLink top = NULL;		//�������в�����ջ��
	MoveLink p;
	MoveLink NowNode;			//��ǰ�����Ĳ���
	MoveLink BestFirstMove;			//�������ŵ�ͷһ��
	MoveLink CurrFirstMove;			//���浱ǰ��ͷһ��
	Max_depth = depth;
	Head = MoveGenerator(currChessBoard);		//��һ�β�������һ��Ĳ���
	depth--;			//�������--
	p = Head;			
	while (p->next != NULL)		//����������Ĳ�����ջ
	{
		p = p->next;
		Push(&top, p);
	}
	while(!IsEmptyStack(top))		//�������ջ��Ϊ��
	{
		NowNode = Pop(&top);
		if (depth == Max_depth - 1)
		{
			CurrFirstMove= NowNode;
		}
		
		MakeMove(currChessBoard, NowNode->xSPos, NowNode->ySPos, NowNode->xEPos, NowNode->yEPos);		//�߳�һ��
		depth--;
		while (depth >= 1)
		{
			if (depth =1)		//����ǵ��������˵����ڶ�������ջֱ�ӶԲ��������в������б���
			{
				Head = MoveGenerator(currChessBoard);
				p = Head;
				while (p->next != NULL)
				{
					p = p->next;
					MakeMove(currChessBoard, p->xSPos, p->ySPos, p->xEPos, p->yEPos);		//�����һ��
					sore = Evaluation(currChessBoard, (Max_depth - depth) % 2);		//�����һ����������
					if (sore > Max_depth)
					{
						Max_depth = sore;				//���浱ǰ���������
						BestFirstMove = CurrFirstMove;		//����ͷ����һ������������ṹ��
					}
					unMakeNove(currChessBoard);
				}
			}
			else		//�����������������ջ
			{
				Head = MoveGenerator(currChessBoard);
				p = Head;
				while (p->next != NULL)		//����������Ĳ�����ջ
				{
					p = p->next;
					Push(&top, p);
				}
			}
			
		}
	}
	return BestFirstMove;
}