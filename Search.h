
#include "MoveGenerator.h"
#include "Move.h"
void PushStep(MoveLink* top, MoveLink t);		//��������ջ
MoveLink PopStep(MoveLink* top);			//��������ջ
MoveLink Search(int currChessBoard[][9], int depth);		//��������depth�����ҳ����ŵĲ���
bool IsEmptyStack(MoveLink top);		//�Ƿ�ջ��