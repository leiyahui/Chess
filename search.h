
#include "MoveGenerator.h"
#include "Move.h"
void init_step(made_move_link* link);
void push_step(made_move_link* link, mode_move move);		//��������ջ
made_move_link pop_step(made_move_link* link);			//��������ջ
int stack_length(made_move_link* link);		//����ջ�ĳ���
made_move_link search(int curr_chess_board[][9], int depth);		//��������depth�����ҳ����ŵĲ���
bool is_empty_stack(made_move_link* link);		//�Ƿ�ջ��
int is_black_fail(int curr_chess_board][9]);		//�����Ƿ�ʧ��
int is_red_fail(int curr_chess_board[][9]);		//�����Ƿ�ʧ��
