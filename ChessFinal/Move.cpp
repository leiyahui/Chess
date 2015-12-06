#include"Move.h"
void Push(MovedLink* top, int xSPos, int ySPos, int xEPos, int yEPos, int echess)		//���߹��Ĳ�����ջ
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
MovedLink Pop(MovedLink* top)		//�������߹��Ĳ�����ջ
{
	if (*top == NULL)		//��ʱ�Ѿ�û���߹��Ĳ�����
	{
		printf("ջ��");
		return NULL;
	}
	MovedLink q = (*top);
	(*top) = q->next;
	return q;
}
int MovedStackLength(MovedLink top)		//����ջ�ĳ���
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
void MakeMove(int currChessBoard[][9],MovedLink* top,int xSPos,int ySPos,int xEPos,int yEPos)		//�߳�һ�������Ұ��߹��Ĳ������������߹��Ĳ�����ջ��
{
	int i = currChessBoard[xEPos][yEPos];
	currChessBoard[xEPos][yEPos] = currChessBoard[xSPos][ySPos];		//��������
	currChessBoard[xSPos][ySPos] = NO_CHESS;			//��������
	Push(top, xSPos, ySPos, xEPos, yEPos, i);		//�����߹��Ĳ�����ջ��topΪȫ�ֱ���
}
void unMakeMove(int currChessBoard[][9], MovedLink* top)	//�˻�һ���Ͳ��ҳ�ջ
{
	MovedLink move = Pop(top);		//��ջ
	int xSPos = move->xSPos;
	int ySPos = move->ySPos;
	int xEPos = move->xEPos;
	int yEPos = move->yEPos; 
	int i = currChessBoard[xEPos][yEPos];		//��ʱ�ƶ�������
	int j = move->echess;				//�����ǵ�����
	currChessBoard[xSPos][ySPos] = i;
	currChessBoard[xEPos][yEPos] = j;
	free(move);
}