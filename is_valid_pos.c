#include"is_valid_pos.h"
static const unsigned char king_pos[256]=
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0
};
static const unsigned char adviser_pos[256]=
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 0, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 0, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 0, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 1, 0, 1,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0
};
static const unsigned char elephant_pos[256]=
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 1, 0, 0, 0,1,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 1, 0, 0, 0, 1, 0,0,0,1,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 1, 0, 0, 0,1,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 1, 0, 0, 0,1,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 1, 0, 0, 0, 1, 0,0,0,1,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 1, 0, 0, 0,1,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0
};
static const unsigned char h_c_c_pos[256]=
{

	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0
};
static const unsigned char r_pawn_pos[256]=
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 1, 0, 1, 0, 1, 0,1,0,1,0,0,0,0,
	0, 0, 0, 1, 0, 1, 0, 1, 0,1,0,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0
};
static const unsigned char b_pawn_pos[256]=
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 1, 1, 1, 1, 1,1,1,1,0,0,0,0,
	0, 0, 0, 1, 0, 1, 0, 1, 0,1,0,1,0,0,0,0,
	0, 0, 0, 1, 0, 1, 0, 1, 0,1,0,1,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0
};
bool is_valid_pos(unsigned char pos)
{
    return chess_pos[pos];
}
