#include "chess.h"
typedef struct MakedMove		//��¼�Ѿ��߹��Ĳ���
{
	int xSPos;
	int ySPos;
	int xEPos;
	int yEPos;
	int echess;			//�����ǵ�����
	MakedMove* next;
}Moved,*MovedLink;
void Push(MovedLink* top, int xSPos, int ySPos, int xEPos, int yEPos, int eChess);		//���߹�·��ջ
MovedLink Pop(MovedLink* top);	//���߹��Ĳ�����ջ
int MovedStackLength(MovedLink top);		//�߹�����ջ�ĳ���
void MakeMove(int currChessBoard[][9],MovedLink* top, int xSPos, int ySPos, int xEPos, int yEPos);		//��һ�����ҰѲ�����¼����ջ��
void unMakeMove(int currChessBoar[][9],MovedLink* top);	//�����Ѿ��߹��Ĳ������ҳ�ջ
