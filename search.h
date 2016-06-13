
#include "MoveGenerator.h"
#include "Move.h"
void init_step(made_move_link* link);
void push_step(made_move_link* link, mode_move move);		//将步伐进栈
made_move_link pop_step(made_move_link* link);			//将步伐出栈
int stack_length(made_move_link* link);		//步伐栈的长度
made_move_link search(int curr_chess_board[][9], int depth);		//向下搜索depth步，找出最优的步伐
bool is_empty_stack(made_move_link* link);		//是否栈空
int is_black_fail(int curr_chess_board][9]);		//黑棋是否失败
int is_red_fail(int curr_chess_board[][9]);		//红旗是否失败
