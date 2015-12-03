#include"chess.h"
typedef struct Movement
{
	int xSPos;
	int ySPos;
	int xEPos;
	int yEPos;
	Movement* next;
}Move,*MoveLink;
MoveLink MoveGenerator(int currChessBoard[][9],int redTurn);  //走法产生器