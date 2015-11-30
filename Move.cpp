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
	MovedLink p = (MovedLink)malloc(sizeof(Moved));
	MovedLink q = (*top);
	p->xSPos = q->xSPos;
	p->ySPos = q->ySPos;
	p->xEPos = q->xEPos;
	p->yEPos = q->yEPos;
	p->echess = q->echess;
	(*top) = q->next;
	free(q);
	return p;
}
void MakeMove(int currChessBoard[][9],MovedLink* top,int xSPos,int ySPos,int xEPos,int yEPos)		//�߳�һ�������Ұ��߹��Ĳ������������߹��Ĳ�����ջ��
{
	int i = currChessBoard[yEPos][yEPos];
	currChessBoard[xSPos][ySPos] = NO_CHESS;			//��������
	Push(top, xSPos, ySPos, xEPos, yEPos, i);		//�����߹��Ĳ�����ջ��topΪȫ�ֱ���
}
void unMakeMove(int currChessBoard[][9], MovedLink* top)
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
}