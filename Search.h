#include "chess.h"
#include "MoveGenerator.h"
#include "Move.h"
void Push(MoveLink* top, MoveLink t);		//��������ջ
MoveLink Pop(MoveLink* top);			//��������ջ
MoveLink Search(int currChessBoard[][9], int depth);		//��������depth�����ҳ����ŵĲ���
bool IsEmptyStack(MoveLink top);		//�Ƿ�ջ��