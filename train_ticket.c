#include <stdio.h>
#include <stdlib.h>

int find_tickets(int every_number,int train_ticket[][5]){
	int i,j;
	int tempo_count;
	
	tempo_count = 0;	

   for(i = 0; i < 20 ; i++)
   {
       	tempo_count = 0;

	   for(j = 0; j < 5 ;j++)
		{
			if(train_ticket[i][j] != -1)
				tempo_count ++ ;
			else
				tempo_count = 0;

			if(  tempo_count == every_number)
				return (i * 5 + j);///the final seat
		}
   }	
   return -1;
}
int unusual(int every_number,int train_ticket[][5]){
	int i,j;
	int tempo_count;

	tempo_count = 0;

   for(i = 0; i < 20 ; i++)
        for(j = 0; j < 5 ;j++)
	    {
		if ( train_ticket[i][j] != -1)
		{	
			printf("%d ",train_ticket[i][j]);	
			train_ticket[i][j] == -1;
			tempo_count ++;
		}	
		if( tempo_count == every_number)
			{	printf("\n");
				return 0;
			}
	    }

}
int usual(int seat,int every_number,int train_ticket[][5]){
	int i,j;
	int tempo_count;
	
	seat = seat - every_number + 1;

	tempo_count = 0;
	
             for(i = 0 ;i < every_number; i++)
	     {	
		     printf("%d ",train_ticket[seat / 5][seat % 5 + i]);
		     train_ticket[seat / 5][seat % 5 + i] = -1;
	     }
	     printf("\n");

}
void test(int train_ticket[][5])///no use
{	
	int i,j;
   for(i = 0; i < 20 ; i++)
        for(j = 0; j < 5 ;j++)
	
        train_ticket[i][j] = 3;
	
}
int main (void){
    int order_times;
    int order[100];
    int train_ticket[20][5];
    int i,j,train_count;
    int seat;


   for(i = 0; i < 20 ; i++)
        for(j = 0; j < 5 ;j++)
  		train_ticket[i][j] = i * 5 + j + 1;
//test(train_ticket);

      scanf("%d",&order_times);
    for(i = 0; i < order_times; i++)
        scanf("%d",&order[i]);

  for(train_count = 0 ; train_count < order_times ;train_count ++ )
            {
                seat = find_tickets(order[train_count],train_ticket);
                  if(seat == -1)
                   unusual(order[train_count],train_ticket);///no found
                   else
                    usual(seat,order[train_count],train_ticket);/// found
            }



    return 0;
}
/**问题描述
　　请实现一个铁路购票系统的简单座位分配算法，来处理一节车厢的座位分配。
　　假设一节车厢有20排、每一排5个座位。为方便起见，我们用1到100来给所有的座位编号，第一排是1到5号，第二排是6到10号，依次类推，第20排是96到100号。
　　购票时，一个人可能购一张或多张票，最多不超过5张。如果这几张票可以安排在同一排编号相邻的座位，则应该安排在编号最小的相邻座位。否则应该安排在编号最小的几个空座位中（不考虑是否相邻）。
　　假设初始时车票全部未被购买，现在给了一些购票指令，请你处理这些指令。
输入格式
　　输入的第一行包含一个整数n，表示购票指令的数量。
　　第二行包含n个整数，每个整数p在1到5之间，表示要购入的票数，相邻的两个数之间使用一个空格分隔。
输出格式
　　输出n行，每行对应一条指令的处理结果。
　　对于购票指令p，输出p张车票的编号，按从小到大排序。
样例输入
4
2 5 4 2
样例输出
1 2
6 7 8 9 10
11 12 13 14
3 4
样例说明
　　1) 购2张票，得到座位1、2。
　　2) 购5张票，得到座位6至10。
　　3) 购4张票，得到座位11至14。
　　4) 购2张票，得到座位3、4。
评测用例规模与约定
　　对于所有评测用例，1 ≤ n ≤ 100，所有购票数量之和不超过100。*/
