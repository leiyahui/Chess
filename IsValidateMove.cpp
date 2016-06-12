#include"IsValidateMove.h"
int IsValidateMove(int currChessBoard[][9], int xSPos, int ySPos, int xEPos, int yEPos)		//�Ƿ��ǺϷ����߷�
{
	int i;
	int j;
	int s_chess = currChessBoard[xSPos][ySPos];			//����λ�õ�����
	int e_chess = currChessBoard[xEPos][yEPos];			//�յ������
	if ((xSPos == xEPos) && (ySPos == yEPos))
	{
		return 0;		//�����յ�һ��
	}
	if (IsSameCol(s_chess, e_chess))
	{
		return 0;		//��������յ��������Ӫ��ͬ
	}
	switch (s_chess)
	{

	case B_Chariot:					//�ڳ�
	case R_Chariot:					//�쳵
		if ((xSPos != xEPos) && (ySPos != yEPos))	//û����ֱ��
		{
			return 0;
		}
		if (xSPos == xEPos)						//x������ͬ
		{
			if (ySPos < yEPos)
			{
				for (i = ySPos + 1; i < yEPos; i++)
				{
					if (currChessBoard[xSPos][i])		//�����յ�֮�����谭
					{
						return 0;
					}
				}
			}
			else
			{
				for (i = yEPos + 1; i < ySPos; i++)
				{
					if (currChessBoard[xSPos][i])		//�����յ�֮�����谭
					{
						return 0;
					}
				}
			}

		}
		else							//y������ͬ
		{
			if (xSPos < xEPos)
			{
				for (i = xSPos + 1; i < xEPos; i++)
				{
					if (currChessBoard[i][ySPos])		//�����յ�֮�����谭
					{
						return 0;
					}
				}
			}
			else
			{
				for (i = xEPos + 1; i < xSPos; i++)
				{
					if (currChessBoard[i][ySPos])
					{
						return 0;
					}
				}
			}
		}
		break;
	case B_Horse:				//����
	case R_Horse:				//����
		if (abs((xSPos - xEPos)*(ySPos - yEPos)) != 2)		//��û������
			return 0;
		if ((xSPos - xEPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos])
			{
				return 0;			//����
			}
		}
		else if ((xEPos - xSPos) == 2)
		{
			if (currChessBoard[xSPos + 1][ySPos])
			{
				return 0;			//����
			}
		}
		else if ((ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos][ySPos - 1])
			{
				return 0;
			}
		}
		else
		{
			if (currChessBoard[xSPos][ySPos + 1])
			{
				return 0;
			}
		}
		break;
	case B_Elephant:		//����
		if (abs(xSPos - xEPos) != 2 || abs(ySPos - yEPos) != 2 || xEPos > 4)		//�ߵĲ��ǡ���ӣ������յ㳬���ڷ���Ӫ
		{
			return 0;
		}
		if ((xSPos - xEPos) == 2 && (ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos - 1])
			{
				return 0;			//����
			}
		}
		else if ((xSPos - xEPos) == 2 && (yEPos - ySPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos + 1])
			{
				return 0;			//����
			}
		}
		else if ((xEPos - xSPos) == 2 && (ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos + 1][ySPos - 1])
			{
				return 0;			//����
			}
		}
		else
		{
			if (currChessBoard[xSPos + 1][ySPos + 1])
			{
				return 0;			//����
			}
		}
		break;

	case R_Elephant:		//����
		if (abs(xSPos - xEPos) != 2 || abs(ySPos - yEPos) != 2 || xEPos < 5)		//�ߵĲ��ǡ���ӣ������յ㳬���췽��Ӫ
		{
			return 0;
		}
		if ((xSPos - xEPos) == 2 && (ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos - 1])
			{
				return 0;			//����
			}
		}
		else if ((xSPos - xEPos) == 2 && (yEPos - ySPos) == 2)
		{
			if (currChessBoard[xSPos - 1][ySPos + 1])
			{
				return 0;			//����
			}
		}
		else if ((xEPos - xSPos) == 2 && (ySPos - yEPos) == 2)
		{
			if (currChessBoard[xSPos + 1][ySPos - 1])
			{
				return 0;			//����
			}
		}
		else
		{
			if (currChessBoard[xSPos + 1][ySPos + 1])
			{
				return 0;			//����
			}
		}
		break;
	case B_Adviser:		//��ʿ
		if (abs(xSPos - xEPos) != 1 || abs(ySPos - yEPos) != 1 || xEPos > 2 || yEPos < 3 || yEPos>5)	//û����'��'�ӣ������յ�û���ڷ�Χ��
		{
			return 0;
		}
		break;
	case R_Adviser:		//��ʿ
		if (abs(xSPos - xEPos) != 1 || abs(ySPos - yEPos) != 1 || xEPos < 7 || yEPos < 3 || yEPos>5)		//û���ߡ��ڡ��ӣ������յ�û���ڷ�Χ��
		{
			return 0;
		}
		break;
	case B_Canon:		//����
	case R_Canon:		//����
		if ((xSPos != xEPos) && (ySPos != yEPos))		//û����ֱ��
		{
			return 0;
		}
		j = 0;
		if (currChessBoard[xEPos][yEPos])			//�յ�������
		{
			if (xSPos == xEPos)
			{
				if (ySPos > yEPos)
				{
					for (i = yEPos + 1; i < ySPos; i++)
					{
						if (currChessBoard[xSPos][i])
						{
							j++;
						}
					}
					if (j != 1)		//�����յ�֮�䲻ֻ��һ������
					{
						return 0;
					}
				}
				else
				{
					for (i = ySPos + 1; i < yEPos; i++)
					{
						if (currChessBoard[xSPos][i])
						{
							j++;
						}
					}
					if (j != 1)	//�����յ�֮�䲻ֻ��һ������
					{
						return 0;
					}
				}
			}
			else
			{
				if (xSPos > xEPos)
				{
					for (i = xEPos + 1; i < xSPos; i++)
					{
						if (currChessBoard[i][ySPos])
						{
							j++;
						}
					}
					if (j != 1)		//�����յ�֮�䲻ֹ��һ������
					{
						return 0;
					}
				}
				else
				{
					for (i = xSPos + 1; i < xEPos; i++)
					{
						if (currChessBoard[i][ySPos])
						{
							j++;
						}
					}
					if (j != 1)	//�����յ�֮�䲻ֹ��һ������
					{
						return 0;
					}
				}
			}
		}
		else										//�յ�û������
		{
			if (xSPos == xEPos)						//x������ͬ
			{
				if (ySPos < yEPos)
				{
					for (i = ySPos + 1; i < yEPos; i++)
					{
						if (currChessBoard[xSPos][i])		//�����յ�֮�����谭
						{
							return 0;
						}
					}
				}
				else
				{
					for (i = yEPos + 1; i < ySPos; i++)
					{
						if (currChessBoard[xSPos][i])		//�����յ�֮�����谭
						{
							return 0;
						}
					}
				}

			}
			else							//y������ͬ
			{
				if (xSPos < xEPos)
				{
					for (i = xSPos + 1; i < xEPos; i++)
					{
						if (currChessBoard[i][ySPos])		//�����յ�֮�����谭
						{
							return 0;
						}
					}
				}
				else
				{
					for (i = xEPos + 1; i < xSPos; i++)
					{
						if (currChessBoard[i][ySPos])
						{
							return 0;
						}
					}
				}
			}
		}

		break;
	case B_Pawn:		//�ڱ�
		if (xSPos > xEPos)		//���������
		{
			return 0;
		}
		if (xSPos < 5)			//����֮ǰ
		{
			if ((xEPos - xSPos) != 1 || ySPos != yEPos)		//���������ǰ����һ��
			{
				return 0;
			}
		}
		else
		{
			if ((abs(xSPos - xEPos) + abs(ySPos - yEPos)) != 1)		//�����������һ��
			{
				return 0;
			}
		}
		break;
	case R_Pawn:	//���
		if (xSPos < xEPos)		//���������
		{
			return 0;
		}
		if (xSPos > 4)		//����֮ǰ
		{
			if ((xSPos - xEPos) != 1 || ySPos != yEPos)		//���������ǰ����һ��
			{
				return 0;
			}
		}
		else
		{
			if ((abs(xSPos - xEPos) + abs(ySPos - yEPos)) != 1)		//�����������һ��
			{
				return 0;
			}
		}
		break;
	case B_King:	//�ڽ�
		if (xEPos > 2 || yEPos < 3 || yEPos>5 || ((abs(xSPos - xEPos) + abs(ySPos - yEPos)) != 1))	//�����˽�Ӧ���ڵķ�Χ�����ߵĲ���һ��
		{
			return 0;
		}
		break;
	case R_King:	//�콫
		if (xEPos < 7 || yEPos < 3 || yEPos>5 || ((abs(xSPos - xEPos) + abs(ySPos - yEPos)) != 1))	//�����˽�Ӧ���ڵķ�Χ�����ߵĲ�ֹһ��
		{
			return 0;
		}
		break;
		return 1;
	}

}