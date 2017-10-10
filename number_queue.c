#include <stdio.h>

int main(void){
    int key[1001];
    int number[1001];
    int answer[1001][2];
    int time;
    int i,j,k;

    scanf("%d",&time);
for(i = 0;i < 1001; i++ )
    {
        number[i] = 0;
        answer[i][0] = 0;
        answer[i][1] = 0;
    }
for(i = 0; i < time ;i ++)
      scanf("%d",&key[i]);

for(i = 0; i < time ;i ++)
    number[key[i]] ++ ;

i = 0;
j = 0;

for(i = 0; i < 1001 ;i ++)
    if(number[i] != 0)
    {
        answer[j][0] = i;
        answer[j][1] = number[i];
        j ++;
    }

time = j ;

for( i = 0 ; i < time; i++)
{
    answer[time][1] = answer[i][1];
    answer[time][0] = i;
    for (j = i +1; j < time ; j ++)
    {
        if(answer[j][1] > answer[time][1] )
        {
            answer[time][1] = answer[j][1];
            answer[time][0] = j;
        }
    }
   number[0] = answer[time][0];
   number[1] = answer[time][1];
   answer[time][0] = answer[answer[time][0]][0];
   answer[time][1] = answer[time][1];
   answer[answer[time][0]][0] = number[0];
   answer[time][1] = number[1];

}


for (i = 0 ; i < time ; i++ )
    printf("%d %d\n",answer[i][0],answer[i][1]);


return 0;
}


/*
	
问题描述
　　给定n个整数，请统计出每个整数出现的次数，按出现次数从多到少的顺序输出。
输入格式
　　输入的第一行包含一个整数n，表示给定数字的个数。
　　第二行包含n个整数，相邻的整数之间用一个空格分隔，表示所给定的整数。
输出格式
　　输出多行，每行包含两个整数，分别表示一个给定的整数和它出现的次数。按出现次数递减的顺序输出。如果两个整数出现的次数一样多，则先输出值较小的，然后输出值较大的。
样例输入
12
5 2 3 3 1 3 4 2 5 2 3 5
样例输出
3 4
2 3
5 3
1 1
4 1
评测用例规模与约定
　　1 ≤ n ≤ 1000，给出的数都是不超过1000的非负整数。*/
