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
void MakeMove(int currChessBoard[][9], int xSPos, int ySPos, int xEPos, int yEPos);		//��һ�����ҰѲ�����¼����ջ��
void unMakeNove(int currChessBoar[][9]);	//�����Ѿ��߹��Ĳ������ҳ�ջ
