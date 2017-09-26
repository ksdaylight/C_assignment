//pintia.cn 798360
#include <stdio.h>
#include <stdlib.h>

int *find_tickets(int every_number,int *train_ticket){

}
void unusual(int every_number,int *train_ticket){
}
void usual(int every_number,int *train_ticket){

}
int main (void){
    int order_times;
    int order[100];
    int train_ticket[20][5];
    int i,j,train_count;
    int seat[1][1];


   for(i = 0; i < 20 ; i++)
        for(j = 0; j < 5 ;j++)
        train_ticket[i][j] = 1;

    scanf("%d",&order_times);
    for(i = 0; i < order_times; i++)
        scanf("%d",&order[i]);
  for(train_count = 0 ; train_count < order_times ;train_count ++ )
            {
                seat = find_tickets(order[train_count],train_ticket);
                  if(seat == NULL)
                   unusual(order[train_count],train_ticket);///no found
                   else
                    usual(order[train_count],train_ticket);/// found
            }




    return 0;
}
