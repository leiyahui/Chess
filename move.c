#include"Move.h"
void init_moved_link(made_move_link* link)
{
    link->top=(made_move*)malloc(sizeof(made_move));
    link->top->next=NULL;
    link->len=0;
}
void push(made_move_link* link, int xspos, int yspos, int xepos, int yepos, int echess)		
{
	made_move* p = (made_move*)malloc(sizeof(made_move));
	p->xspos = xspos;
	p->yspos = yspos;
	p->xepos = xepos;
	p->yepos = yepos;
	p->echess = echess;
	p->next = link->top->next;
	link->top->next=p;
    link->len++;
}
void Pop(made_move_link* link,made_move* pop_move)		
{
	if (link->len == 0)		
	{
		printf("empty stack");
		return NULL;
	}
    made_move* del;
	del=link->top->next;
	link->top->next=del->next;
    strcpy(pop_move,del,sizeof(made_move));
    free(del);
	return q;
}
int moved_link_length(made_move_link* link)	
{
	return link->len;
}
void make_move(int curr_chess_board[][9],made_move_link* link,int xspos,int yspos,int xepos,int yepos)	
{
	int i = curr_chess_board[xepos][yepos];
	curr_chess_board[xepos][yepos] = curr_chess_board[xspos][yspos];		//更改棋盘
	curr_chess_board[xspos][yspos] = NO_CHESS;			//更改棋盘
	push(link, xspos, yspos, xepos, yepos, i);		//把已走过的步伐进栈，top为全局变量
}
void un_make_move(int curr_chess_board[][9], made_move_link* link)	//退回一步就并且出栈
{
	made_move move;
    pop(link,&move);		//出栈
	int xspos = move.xspos;
	int yspos = move.yspos;
	int xepos = move.xepos;
	int yepos = move.yepos; 
	int i = curr_chess_board[xepos][yepos];		//当时移动的棋子
	int j = move->echess;				//被覆盖的棋子
	curr_chess_board[xspos][yspos] = i;
	curr_chess_board[xepos][yepos] = j;
}
