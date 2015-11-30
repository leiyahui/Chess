#include"chess.h"
//��ֵ�Ķ���
#define BASEVALUE_PAWN 100
#define BASEVALUE_BISHOP 250
#define BASEVALUE_ELEPHANT 250
#define BASEVALUE_HORSE 350
#define BASEVALUE_CAR 500
#define BASEVALUE_CANON 350
#define BASEVALUE_KING 1000
#define FLEXIBILTY_PAWN 15
#define FLEXIBILTY_BISHOP 1
#define FLEXIBILTY_ELEPHANT 1
#define FLEXIBILTY_CAR 6
#define FLEXIBILTY_HORSE 12
#define FLEXIBILTY_CANON 6
#define FLEXIBILTY_KING 0
const int BAO[10][9] =		//�ڱ��Ļ���ֵ�Ķ���
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	90, 90, 110, 120, 120, 120, 110, 90, 90,
	90, 90, 110, 120, 120, 120, 110, 90, 90,
	70, 90, 110, 110, 110, 110, 110, 90, 70,
	70, 70, 70, 70, 70, 70, 70, 70, 70,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
};
const int BA1[10][9] =		//����Ļ���֪ʶ�Ķ���
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	70, 70, 70, 70, 70, 70, 70, 70, 70,
	70, 90, 110, 110, 110, 110, 110, 90, 70,
	90, 90, 110, 120, 120, 120, 110, 90, 90,
	90, 90, 110, 120, 120, 120, 110, 90, 90,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
};
const int m_BaseValue[15] =
{
	0, BASEVALUE_CAR, BASEVALUE_HORSE, BASEVALUE_CANON, BASEVALUE_ELEPHANT, BASEVALUE_BISHOP, BASEVALUE_PAWN, BASEVALUE_KING,
	BASEVALUE_CAR, BASEVALUE_HORSE, BASEVALUE_CANON, BASEVALUE_ELEPHANT, BASEVALUE_BISHOP, BASEVALUE_PAWN, BASEVALUE_KING
};
const int m_FlexValue[15] =
{
	0, FLEXIBILTY_CAR, FLEXIBILTY_HORSE, FLEXIBILTY_CANON, FLEXIBILTY_ELEPHANT, FLEXIBILTY_BISHOP, FLEXIBILTY_PAWN, FLEXIBILTY_KING,
	FLEXIBILTY_CAR, FLEXIBILTY_HORSE, FLEXIBILTY_CANON, FLEXIBILTY_ELEPHANT, FLEXIBILTY_BISHOP, FLEXIBILTY_PAWN, FLEXIBILTY_KING
};
int GetBingValue(int x, int y, int position[10][9]); //��ȡ���ļ�ֵ
LReleatedList GetReleatedPiece(int currChessboard[][9], int xSPos, int ySPos);		//��ȡһ����������ص���������,����ͷ���ָ��
int Evaluation(int currChessBoard[][9], bool IsRedTurn);		//��һ����������