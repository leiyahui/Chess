#include "evalution.h"
int flex_pos_value()
{
    int r_value[2];
    int pos,chess;
    int i,j,k;
    int check,n;
    int count;
    r_value[0]=r_vlaue[1]=0;
    for(i=0;i<=1;i++)
    {
        /*king*/
        chess=16+16*i;
        pos=chess_array[chess];
        if(pos!=0)
        {
          for(j=0;j<4;j++)
          {
              n=pos+king_dir[j];
              if(is_valid_pos(king_pos,n))
              {
                  if(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                  {
                      r_vlaue[i]+=flex_value[chess];
                  }
              }
          }
          r_value[i]+=king_pos_value[i][pos];
        }
        /*adviser*/
        for(k=0;k<=1;k++)
        {
          chess=17+k+16*i;
           pos=chess_array[chess];
           if(pos!=)
           {
              for(j=0;j<4;j++)
              {
                  n=pos+adviser_dir[j];
                  if(is_valid_pos(adviser_pos,n))
                  {
                      is(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                      {
                          r_value[i]+=flex_vlaue[chess];
                         r_value[i]+=adviser_pos_value[i][pos];
                      }
                  }
              }
          }
        }
          /*elephant*/
        for(k=0;k<=1;k++)
        {
            chess=19+k+16*i;
            pos=chess_array[i];
            if(pos!=0)
            {
              for(j=0;j<4;j++)
              {
                  n=pos+elephant_dir[j];
                  if(is_valid_pos(elephant_pos,n))
                  {
                      is(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                      {
                          r_value[i]+=flex_vlaue[chess];
                          r_value[i]+=elephant_pos_value[i][pos];
                      }
                  }
              }
            }
          }
          /*horse*/
        for(k=0;k<=1;k++)
        {
            chess=21+k+16*i;
            pos=chess_array[chess];
            if(pos!=0)
            {
               for(j=0;j<8;j++)
               {
                   n=pos+horse_dir[j];
                   check=pos+horse_check[j];
                   if(is_valid_pos(h_c_c_pos,n))
                   {
                       is(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                       {
                           if(curr_chess_board[check])
                           {
                               r_value[i]+=flex_vlaue[chess];
                               r_value[i]+=horse_pos_value[i][pos];
                           }
                       }
                   }
               }
            }
        }   
        /*charoit*/
        for(k=0;k<=1;k++)
        {
            chess=23+k+16*i;
            pos=chess_array[chess];
            if(pos!=0)
            {
               for(j=0;j<4;j++)
               {
                   count=1;
                   n=pos+charoit_dir[j];
                   while(n<256&&n>=0&&curr_chess_board[n]==NO_CHESS)        //position without chess
                   {
                       if(is_valid_pos(h_c_c_pos,n))
                       {
                           r_value[i]+=flex_value[chess];
                           r_value[i]+=charoit_pos_value[i][pos];
                       }
                       count++;
                       n=pos+chariot_dir[j]*count;
                   }
                   if(n>=0&&n<256)                   //the only one position with chess
                   {
                       if(is_valid_pos(h_c_c_pos,n))
                       {
                           if(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                           {
                               r_value[i]+=flex_value[chess];
                               r_value[i]+=charoit_pos_value[i][pos];
                           }
                       }
                   }
               }
            }
        }   
        /*canon*/
        for(k=0;k<=1;k++)
        {
            chess=25+k+16*i;
            pos=chess_array[chess];
            if(pos!=0)
            {
               for(j=0;j<4;j++)
               {
                  count=1;
                  n=pos+canon_dir[j]*count;
                  while(n<256&&n>=0&&curr_chess_board[n]==NO_CHESS)        //position without chess
                  {
                      if(is_valid_pos(h_c_c_pos,n))
                      {
                               r_value[i]+=flex_value[chess];
                               r_value[i]+=canon_pos_value[i][pos];
                      }
                      count++;
                      n=pos+chariot_dir[j]*count;
                  }
                  count++;
                  n=pos+chariot_dir[j]*count;     
                  /*clear postion without chess after one one position with chess */
                  while(n>=0&&n<256&&curr_chess_board[n]==NO_CHESS)
                  {
                     count++;
                     n=pos+chariot_dir[j]*count;
                  }
                  if(n>=0&&n<256)
                  {
                      if(is_valid_pos(h_c_c_pos,n))
                      {
                          if(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                          {
                               r_value[i]+=flex_value[chess];
                               r_value[i]+=canon_pos_value[i][pos];
                          }
                      }
                  }
               }
            }
        }   
    }    
    /*b_pawn*/
    for(k=0;k<5;k++)
    {
        chess=27+k;
        pos=chess_array[chess];
        is(pos!=0)
        {
           for(j=0;j<4;j++)
           {
               n=pos+b_pawn_dir[j];
               if(is_valid_pos(b_pawn_pos,n))
               {
                   if(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                   {
                       r_value[0]+=flex_value[chess];
                       r_value[0]+=canon_pos_value[0][pos];
                   }
               }
           }
        }
    }   
    for(k=0;k<5;k++)
    {
        chess=27+k;
        pos=chess_array[chess];
        if(pos!=0)
        {
           for(j=0;j<4;j++)
           {
               n=pos+r_pawn_dir[j];
               if(is_valid_pos(r_pawn_pos,n))
               {
                   if(!is_same_color(curr_chess_board[pos],curr_chess_board[n]))
                   {
                       r_value[1]+=flex_value[chess];
                       r_value[1]+=canon_pos_value[1][pos];
                   }
               }
           }
        }
    }   
    return r_value[0]-r_value[1];

}        

int evaluation()
{
   int b_value;
   int r_value;
   int value;
   int i;
   b_value=r_value=0;
   for(i=16;i<=31;i++)
   {
       if(chess_array[i]!=0)
       {
           b_value+=base_value[i];      //base_value;
       }
    }
   for(j=32;j<=47;j++)
   {
       if(chess_array[i]!=0)
       {
           r_value+=base_value[i];      //base_value;
       }
   }
   value=b_value-r_value;
   value+=flex_pos_value();
   
}



