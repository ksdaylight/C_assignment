#include <stdio.h>
#include <stdlib.h>
///小图抽取出来，大图不抽（第14行全为1），小图的计算，找出4个中能下落次数最小的（每个人的起点不同），同等，取左边的。

int main (void){
        int big_map[16][10];
        int small_map[4][4];
        int i,j,k;
        int seat;
        /*for(i =0; i < 15; i ++ )
            scanf("%d%d%d%d%d%d%d%d%d%d",&big_map[i][0],
                  &big_map[i][1],&big_map[i][2],&big_map[i][3],&big_map[i][4]
                  ,&big_map[i][5],&big_map[i][6],&big_map[i][7],&big_map[i][8],
                  &big_map[i][9]);
        for(i =0; i < 10; i ++ )
            big_map[15][i] = 1;
        */
        for(i =0; i < 4; i ++ )
            scanf("%d%d%d%d",&small_map[i][0],&small_map[i][1],&small_map[i][2],&small_map[i][3]);
        stare_seat(,)  
   /*     for(i =0; i < 16; i ++ )
        {

         for(j = 0; j < 10 ; j++)
          printf("%d ",big_map[i][j]);
         printf("\n");
        }
    */
    return 0;
}
