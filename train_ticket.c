//pintia.cn 798360
#include <stdio.h>
#include <stdlib.h>


int main (void){
    int order_times;
    int order[100];
    int train_ticket[20][5];
    int i,j,k;

    scanf("%d",&order_times);
    for(i = 0; i < order_times; i++)
        scanf("%d",&order[i]);
    
        
/*    for(i = 0; i < 20 ; i++)
        for(j = 0; j < 5 ;j++)
        train_ticket[i][j] = i * 5 + j + 1;
 */  
    return 0;
}
