#include "Search.h"
#include "Evalution.h"
bool IsEmptyStack(MoveLink top)	 //�Ƿ�ջ��
{
	if (top == NULL)
	{
		return true;
	}
	return false;
}
void PushStep(MoveLink* top, MoveLink t)		//��ջ
{
	t->next = *top;		//��ǰ�ڵ�ָ���²���Ľڵ�
	(*top) = t;				//����ǰ�ڵ��Ϊ����Ľڵ�
}
MoveLink PopStep(MoveLink* top)		//��ջ
{
	MoveLink p;
	p = (*top);
	(*top) = p->next;
	return p;
}
int StackLength(MoveLink top)
{
	int length = 0;
	MoveLink p;
	p = top;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}
int IsBlackFail(int currChessBoard[][9])		//�жϺ�����û���䣬�������û���䷵��0�����򷵻�1
{
	int i, j;
	for (i = 0; i <= 2; i++)
	{
		for (j = 3; j<= 5; j++)
		{
			if (currChessBoard[i][j] == B_King)
			{
				return 0;			//����û����
			}
		}
	}
	return 1;
}
int IsRedFail(int currChessBoard[][9])		//�жϺ�����û���䣬���û���䷵��0�����򷵻�1
{
	int i, j;
	for (i = 7; i <= 9; i++)
	{
		for (j = 3; j <= 5; j++)
		{
			if (currChessBoard[i][j] == R_King)
			{
				return 0;
			}
		}
	}
	return 1;
}
MoveLink Search(int currChessBoard[][9], int depth)		//��������Ǻ��������㷨�������趨���������Ĳ�����ÿһ������Ĳ�������һ������Ĳ�����һ��NULL���������
{
	int length;		//����ջ�еĲ�������,�����õ�һ��Ҫɾ��
	int movedLength;		//�߹��Ĳ�����ջ�еĳ���,������һ��ɾ��
	int Max_depth;				//������
	MoveLink Head;			//ÿ�β���������ջ
	MoveLink top = NULL;		//�������в�����ջ��
	MoveLink p,q;
	MoveLink NowNode;			//��ǰ�����Ĳ���
	MoveLink BestFirstMove=(MoveLink)malloc(sizeof(Move));			//�������ŵ�ͷһ��
	MoveLink CurrFirstMove=(MoveLink)malloc(sizeof(Move));			//���浱ǰ��ͷһ��
	MovedLink MovedTop = NULL;					//�߹��Ĳ�ջ��
	int xSPos, ySPos, xEPos, yEPos;				//��ǰ����
	int FStepxSPos, FStepySPos, FStepxEPos, FStepyEPos;		//�洢�����ĵ�һ����߷�
	Max_depth = depth;				//������
	int depth0,depth1, depth2, depth3, depth4, depth5;		//�����õģ�������¼ÿһ��Ľڵ����
	depth2 = depth3 = depth4 = 0;
	int IsFirstdepth[10] = { 0 };		//��¼�Ƿ��ǵ�ǰ�ò������ĵ�һ��
	int MaxMin[10] = { 0 };		//���ÿһ�㵱ǰ�������Сֵ
	int Best_MaxMin[10] = { 0 };	//��ŵ�ǰ�ĵ����Ž�
	Head = MoveGenerator(currChessBoard,(Max_depth-depth+1)%2);		//��һ�β�������һ��Ĳ���
	p = Head;		
	q = p;		//���淵�ص�ͷ���
	while (p->next != NULL)	
	{
		p = p->next;	//�ҵ����������һ��
	}
	top = q->next;		//ʹtopָ��ջ��ͷ���
	while(!IsEmptyStack(top))		//�������ջ��Ϊ��
	{
		length = StackLength(top);		//����
		NowNode = PopStep(&top);		//��ջ��ȡ����
		xSPos = NowNode->xSPos;			
		ySPos = NowNode->ySPos;
		xEPos = NowNode->xEPos;
		yEPos = NowNode->yEPos;
		free(NowNode);		//���ڵ��ͷ�
		if (depth == 5)		//��һ��ĵ�һ�������if�����ִֻ��һ��
		{
			FStepxSPos = xSPos;					//��¼����һ�������ĵ�һ��
			FStepySPos = ySPos;
			FStepxEPos = xEPos;
			FStepyEPos = yEPos;
		}
		if (depth == 2)						   //����
		{									   //����
			depth2++;						   //����
		}									   //����
		if (depth == 3)						   //����
		{									   //����
			depth3++;						   //����
		}									   //����
		if (depth == 4)						   //����
		{									   //����
			depth4++;						   //����
		}
		while ((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL)&&(yEPos == NULL))		//�����ص���һ��������ʱ��
		{
			unMakeMove(currChessBoard,&MovedTop);	//��������
			depth++;
			if (depth == 5)			//����
			{
				depth++;
				depth--;
			}
			length = StackLength(top);		//����
			if (IsEmptyStack(top))			//�����������׶�ʱ������ջ�л�ʣ�¼���NULL��һ����򶼻��������˳�
			{
				while (MovedTop != NULL)
				{
					unMakeMove(currChessBoard, &MovedTop);		//��ʱ����һЩ�Ѿ��߹��Ĳ�����Ҫȫ������
				}
				return BestFirstMove;
			}
			NowNode = PopStep(&top);			//��Ϊ�ղ�ȡ���Ľڵ��ǿյ�����˵����ȡ���ڵ�
			xSPos = NowNode->xSPos;
			ySPos = NowNode->ySPos;
			xEPos = NowNode->xEPos;
			yEPos = NowNode->yEPos;
			if (xSPos == 0 && ySPos == 0 && xEPos == 2 && yEPos == 0)
			{
				depth++;
				depth--;
			}
			free(NowNode);
			MaxMin[depth - 1] = Best_MaxMin[depth - 2];		//����һ�������ֵ������һ�㣬���ڼ�֦
			Best_MaxMin[depth - 2] = MaxMin[depth - 2] = 0;		//��ʱ��һ�ֵ���һ�������Ѿ���ɣ�����˵Ҫ���¸�λ
			IsFirstdepth[depth - 2] = 0;			//Ҳ�Ǹ�λ
			if (IsFirstdepth[depth - 1] == 0)		//��һ�ֵ���һ�������Ƿ��ǵ�һ�ν���
			{
				Best_MaxMin[depth - 1] = MaxMin[depth - 1];		//����һ�������õ��Ľ��������һ������Ž⣬
				IsFirstdepth[depth - 1]++;				//��һ�������Ĵ�����1
				if (depth == Max_depth)		//���������ˣ���ô�ͽ���һ���߷��������Ž�
				{
					BestFirstMove->xSPos = FStepxSPos;
					BestFirstMove->ySPos = FStepySPos;
					BestFirstMove->xEPos = FStepxEPos;
					BestFirstMove->yEPos = FStepyEPos;
					FStepxSPos = xSPos;					//��¼����һ�������ĵ�һ��
					FStepySPos = ySPos;
					FStepxEPos = xEPos;
					FStepyEPos = yEPos;
				}
				if (depth % 2)		//������
				{
					if (depth != Max_depth)		//��������㣬��Ϊ����Ѿ�û����һ���ˣ�����Ҫ��֦
					{
						if (IsFirstdepth[depth] != 0)		//�����������һ���Ƿ��Ѿ���ֵ��
						{
							if (Best_MaxMin[depth - 1] >= Best_MaxMin[depth])		//��ǰ��һ�����������Ž������һ������Ž⣬����˵û�б�����ȥ�ı�Ҫ�ˣ��϶�������
							{
								do			
								{
									NowNode = PopStep(&top);
									xSPos = NowNode->xSPos;
									ySPos = NowNode->ySPos;
									xEPos = NowNode->xEPos;
									yEPos = NowNode->yEPos;
									free(NowNode);
								} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//ѭ��ֱ���ò������ĵ�ǰ�����
								IsFirstdepth[depth - 1] = 0;
							}
						}
					}
				}
				else
				{
					if (IsFirstdepth[depth] != 0)
					{
						if (Best_MaxMin[depth - 1] <= Best_MaxMin[depth])
						{
							do			//��ʱ�����ڶ���û�б�����ȥ����Ҫ��
							{
								NowNode = PopStep(&top);
								xSPos = NowNode->xSPos;
								ySPos = NowNode->ySPos;
								xEPos = NowNode->xEPos;
								yEPos = NowNode->yEPos;
								free(NowNode);
							} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//ѭ��ֱ�������ڶ��������
							IsFirstdepth[depth - 1] = 0;
						}
					}
				}
			}
			else			//���������һ�������ĵ�һ������
			{
				if (depth % 2)				//�������Ҫ���ֵ��
				{
					IsFirstdepth[depth - 1]++;
					if (MaxMin[depth - 1] >= Best_MaxMin[depth - 1])			//�����������ֵ������ǰ������������ֵʱ
					{
						Best_MaxMin[depth - 1] = MaxMin[depth - 1];
						if (depth == Max_depth)			//����ǵ�һ��Ļ����ͰѲ�����������
						{
							BestFirstMove->xSPos = FStepxSPos;
							BestFirstMove->ySPos = FStepySPos;
							BestFirstMove->xEPos = FStepxEPos;
							BestFirstMove->yEPos = FStepyEPos;
							FStepxSPos = xSPos;					//��¼����һ�������ĵ�һ��
							FStepySPos = ySPos;
							FStepxEPos = xEPos;
							FStepyEPos = yEPos;
						}
						if (depth != Max_depth)			//��߲㲻��Ҫ��֦
						{
							if (IsFirstdepth[depth] != 0)
							{
								if (Best_MaxMin[depth - 1] >= Best_MaxMin[depth])
								{
									do			//��ʱ�����ڶ���û�б�����ȥ����Ҫ��
									{
										NowNode = PopStep(&top);
										xSPos = NowNode->xSPos;
										ySPos = NowNode->ySPos;
										xEPos = NowNode->xEPos;
										yEPos = NowNode->yEPos;
										free(NowNode);
									} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//ѭ��ֱ�������ڶ��������
									IsFirstdepth[depth - 1] = 0;
								}
							}
						}
					}
				}
				else		//�����Ҫ���ֵ
				{
					IsFirstdepth[depth - 1]++;
					if (MaxMin[depth - 1] <= Best_MaxMin[depth - 1])
					{
						Best_MaxMin[depth - 1] = MaxMin[depth - 1];
						if (IsFirstdepth[depth] != 0)
						{
							if (Best_MaxMin[depth - 1] <= Best_MaxMin[depth])		//���м�֦
							{
								do			//��ʱ�����ڶ���û�б�����ȥ����Ҫ��
								{
									NowNode = PopStep(&top);
									xSPos = NowNode->xSPos;
									ySPos = NowNode->ySPos;
									xEPos = NowNode->xEPos;
									yEPos = NowNode->yEPos;
									free(NowNode);
								} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//ѭ��ֱ�������ڶ��������
								IsFirstdepth[depth - 1] = 0;
							}
						}
					}
				}
			}
		}
		MakeMove(currChessBoard,&MovedTop,xSPos,ySPos,xEPos, yEPos);		//�߳�һ��
		movedLength = MovedStackLength(MovedTop);
		depth--;	//��ȼ�һ
		if (IsBlackFail(currChessBoard))		//����ʧ��
		{
			return BestFirstMove;
		}
		if (IsRedFail(currChessBoard))		//����ʧ��
		{
			unMakeMove(currChessBoard, &MovedTop);
			continue;
		}
			if (depth ==1)		//�������һ��û�з���,��������Ҫ��������,
			{
				Head = MoveGenerator(currChessBoard,depth%2);  //��β����Ĳ�������Ҫ��ջ,
				IsFirstdepth[depth - 1] = 0;
				Best_MaxMin[depth - 1] = MaxMin[depth - 1] = 0;
				p = Head;
				while (p->next != NULL)
				{
					q = p;
					p = p->next;
					free(q);
					xSPos = p->xSPos;
					ySPos = p->ySPos;
					xEPos = p->xEPos;
					yEPos = p->yEPos;
					MakeMove(currChessBoard,&MovedTop,xSPos,ySPos, xEPos, yEPos);		//�����һ��
					movedLength = MovedStackLength(MovedTop);
					MaxMin[depth-1] = Evaluation(currChessBoard,1);		//�����һ����������
					if (MaxMin[depth - 1] != 0)				//���Դ���
					{
						MaxMin[depth - 1]++;
						MaxMin[depth - 1]--;
					}
					if (IsFirstdepth[depth-1] == 0)
					{
						Best_MaxMin[depth - 1] = MaxMin[depth - 1];
						if (IsFirstdepth[depth] != 0)
						{
							if (Best_MaxMin[depth - 1] >= Best_MaxMin[depth])		//�Ѿ�û�б�Ҫ������ȥ��
							{
								while (p->next != NULL)
								{
									q = p;
									p = p->next;
									free(q);
								}
								unMakeMove(currChessBoard, &MovedTop);	
								IsFirstdepth[depth - 1] = 0;
								break;
							}
						}
					}
					else
					{
						if (MaxMin[depth - 1] > Best_MaxMin[depth - 1])
						{
							Best_MaxMin[depth - 1] = MaxMin[depth - 1];
							if (IsFirstdepth[depth] != 0)
							{
								if (Best_MaxMin[depth - 1] >= Best_MaxMin[depth])
								{
									while (p->next != NULL)
									{
										q = p;
										p = p->next;
										free(q);
									}
									unMakeMove(currChessBoard, &MovedTop);
									IsFirstdepth[depth - 1] = 0;
									break;
								}
							}
						}
					}
					IsFirstdepth[depth - 1]++;
					unMakeMove(currChessBoard,&MovedTop);
				}
				unMakeMove(currChessBoard, &MovedTop);			//�����ڶ�������
				depth++;
				MaxMin[depth - 1] = Best_MaxMin[depth - 2];		//���²�����ֵ�����ϲ�
				if (IsFirstdepth[depth-1] == 0)		//���������ĵ����ڶ������ǵ�һ�εó����
				{
					Best_MaxMin[depth - 1] = MaxMin[depth - 1];
					IsFirstdepth[depth - 1]++;
					if (IsFirstdepth[depth] != 0)
					{
						if (Best_MaxMin[depth - 1] <= Best_MaxMin[depth])
						{
							do			//��ʱ�����ڶ���û�б�����ȥ����Ҫ��
							{
								NowNode = PopStep(&top);			
								xSPos = NowNode->xSPos;
								ySPos = NowNode->ySPos;
								xEPos = NowNode->xEPos;
								yEPos = NowNode->yEPos;
								free(NowNode);
							} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//ѭ��ֱ�������ڶ��������
							unMakeMove(currChessBoard, &MovedTop);
							IsFirstdepth[depth - 1] = 0;
							depth++;
						}
					}
				}
				else		//���ǵ�һ�εĵ����
				{
					IsFirstdepth[depth - 1]++;
					if (MaxMin[depth - 1] < Best_MaxMin[depth - 1])
					{
						Best_MaxMin[depth - 1] = MaxMin[depth - 1];
						if (IsFirstdepth[depth] != 0)
						{
							if (Best_MaxMin[depth - 1] <= Best_MaxMin[depth])
							{
								do			//��ʱ�����ڶ���û�б�����ȥ����Ҫ��
								{
									NowNode = PopStep(&top);
									xSPos = NowNode->xSPos;
									ySPos = NowNode->ySPos;
									xEPos = NowNode->xEPos;
									yEPos = NowNode->yEPos;
									free(NowNode);
								} while (!((xSPos == NULL) && (ySPos == NULL) && (xEPos == NULL) && (yEPos == NULL)));		//ѭ��ֱ�������ڶ��������
								unMakeMove(currChessBoard, &MovedTop);
								IsFirstdepth[depth - 1] = 0;
								depth++;
							}
						}
					}
				}
			}
			else		//�����������������ջ
			{
				Head = MoveGenerator(currChessBoard,depth%2);
				p = Head;
				q = p;		//���淵�ص�ͷ���
				while (p->next != NULL)
				{
					p = p->next;	//�ҵ����������һ��
				}
				p->next = (MoveLink)malloc(sizeof(Move));		//�½�һ���ڵ���Ϊ������һ���ı�ʶ�ڵ㣬����ڵ���ȫΪ��
				(p->next)->xSPos = NULL;
				(p->next)->ySPos = NULL;
				(p->next)->xEPos = NULL;
				(p->next)->yEPos = NULL;
				(p->next)->next = top;		//��ԭ����ջ���
				top = q->next;		//ʹtopָ��ջ��ͷ���
			}
	}
	while (MovedTop != NULL)
	{
		unMakeMove(currChessBoard,&MovedTop);
	}
	return BestFirstMove;
}