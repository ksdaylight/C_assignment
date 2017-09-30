#include <stdio.h>
#include <stdlib.h>

int main(void){
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int day;
	int year;
	int i,j,k;
	scanf("%d",&year);
		if(((year%4 == 0)&&(year%100 != 0))||(year%400 ==0))
			month[1] = 29;
	scanf("%d",&day);
	for(i = 0;i < 12;i++)
	{
		if((day - month[i]) <= 0 )
		{
		if( day % month[i] == 0)
			day = month[i];
		else
			day = day % month[i];
			break;
		}
		else
			day = day - month[i];
	}
	printf("%d\n%d",i+1,day);
return 0;
}
/**问题描述
　　给定一个年份y和一个整数d，问这一年的第d天是几月几日？
　　注意闰年的2月有29天。满足下面条件之一的是闰年：
　　1） 年份是4的整数倍，而且不是100的整数倍；
　　2） 年份是400的整数倍。
输入格式
　　输入的第一行包含一个整数y，表示年份，年份在1900到2015之间（包含1900和2015）。
　　输入的第二行包含一个整数d，d在1至365之间。
输出格式
　　输出两行，每行一个整数，分别表示答案的月份和日期。
样例输入
2015
80
样例输出
3
21
样例输入
2000
40
样例输出
2
9*/
