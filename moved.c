#include"moved.h"
void init_moved_stack(made_move_stack* stack)
{
    stack->top=stack->base=(made_move*)malloc(sizeof(made_move)*STACK_SIZE);
    if(stack->top==NULL)
    {
        printf("moved_stack init fail\n");
        exit(0);
    }
    stack->len=STACK_SIZE;
}
void push(made_move_stack* stack,unsigned char form,unsigned char to,int to_chess)		
{
    if((stack->top)-(stack->bottom)==stack->len)
    {
        printf("stack is full\n");
    }
    (stack->top)->to_chess=to_chess;
    (stack->top)->from=from;
    (stack->top)->to=to;
    stack->top++;
}
void pop(made_move_stack* stack,made_move* pop_move)		
{
    if(stack->top==stack->base)
    {
        printf("stack is empty\n");
        exit(0);
    }
    pop_move->to_chess=(stack->top)->pop;
    pop_move->from=(stack->top)->from;
    pop_move->to=(stack->top)->to;
    (stack->top)--;
}
void make_move(made_move_stack* stack,unsigned char form,unsigned char to)	
{
	int to_chess = curr_chess_board[to];
    int from_chess=curr_chess_board[from];
	curr_chess_board[to] = curr_chess_board[from];
	curr_chess_board[from] = NO_CHESS;
    position_array[from_chess]=to;
    if(to_chess!=NO_CHESS)
    {
        position_array[to_chess]=0;
    }
	push(stack, from,to, to_chess);		
}
void un_make_move(unsigned char position_array,made_move_stack* stack)	//退回一步就并且出栈
{
	made_move move;
    pop(stack,&move);		
	unsigned char from=move->from;
    unsigned char to=move->to;
	int from_chess = curr_chess_board[to];		
	int to_chess = move->to_chess;				
	curr_chess_board[from] = from_chess;
	curr_chess_board[to] = to_chess;
    position_array[from_chess]=from;
    if(to_chess!=NO_CHESS)
    {
        position_array[to_chess]=to;
    }
}
