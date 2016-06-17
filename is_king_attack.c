#include"is_king_attack.h"
int is_king_attack(unsigned char curr_chess_board[],unsigned char chess_array,int side)//black 0, red 1
{
    int r;      //return value;
    int i,j;
    int count;
    unsigned char king_pos,attacker_pos,check_pos,b_king_pos,r_king_pos;
    int side_tag;
    b_king_pos=chess_array[16];
    r_king_pos=chess_array[32];
    side_tag=32-16*i;       //mark the king's subscript of chess_array 
    r=1;
    /*king attack*/
    if(b_king_pos^16==r_king_pos^16)
    {
        for(i=b_king_pos>>4+16;i<r_king_pos>>4;i++)
        {
            if(curr_chess_board[i<<4+b_king_pos^16]!=NO_CHESS)
            {
                r=0;
            }
        }
        if(r)
        {
            return r;       //king face to face
        }
    }
    king_pos==chess_array[side*16};
    /*horse attack*/
    for(i=0;i<8;i++)
    {
        attacker_pos=king_pos+horse_dir[i];
        if(curr_chess_board[attacker_pos]==side_tag+5||curr_chess_board[attacker_pos]==side_tag+6)
        {
            check_pos=attacker_pos+horse_check[i];
            if(curr_chess_board[check_pos]==NO_CHESS)
            {
                return r;
            }
        }
    }    
    /*charoit attack*/
    for(i=0;i<4;i++)
    {
        j=0;
        attacker_pos=king_pos+charoit_dir[i];
        while(attacker_pos>=0&&attacker_pos<256)
        {
            if(curr_chess_board[attacker_pos]!=NO_CHESS)
            {
                 if(curr_chess_board[attacker_pos]==side_tag+7||curr_chess_board[attacker_pos]==side_tag+8)
                 {
                     return r;
                 }
                break;
            }
            j++;
            attacker_pos=king_pos+charoit_dir[i]*j;
        }
    }
    /*canon attack*/
   for(i=0;i<4;i++)
   {
       j=0;
       count=0;
       attacker_pos=king_pos+canon_dir[i];
       while(attacker_pos<=0&&attacker_pos<256)
       {
           if(curr_chess_board[attacker_pos]!=NO_CHESS)
           {
               if(count==0)
               {
                 count=1;
               }
               else
               {
                   if(curr_chess_board[attacker_pos]==side_tag+9||curr_chess_board[attacker_pos]==side_tag+10)
                   {
                       return r;
                   }
                   break;
               }
           }
       }
   }
   /*pawn attack*/
   for(i=0;i<3;i++)
   {
       if(!side)
       {
           attacker_pos=king_pos+r_pawn_dir[i];
           if(curr_chess_board[attacker_pos]>=43&&curr_chess_board[attacker_pos]<=47)
           {
                return r;
           }
       }
       else
       {
           attacker_pos=king_pos+b_pawn_dir[i];
           if(curr_chess_board[attacker_pos]>=27&&curr_chess_board[attacker_pos]<=31)
           {
               return r;
           }
       }
   }
   return 0;
}
