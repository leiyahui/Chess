
#include "MoveGenerator.h"
#include "Move.h"
void PushStep(MoveLink* top, MoveLink t);		//��������ջ
MoveLink PopStep(MoveLink* top);			//��������ջ
int StackLength(MoveLink top);		//����ջ�ĳ���
MoveLink Search(int currChessBoard[][9], int depth);		//��������depth�����ҳ����ŵĲ���
bool IsEmptyStack(MoveLink top);		//�Ƿ�ջ��
int IsBlackFail(int currChessBoard[][9]);		//�����Ƿ�ʧ��
int IsRedFail(int currChessBoard[][9]);		//�����Ƿ�ʧ��