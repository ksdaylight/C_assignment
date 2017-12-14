#include<stdio.h>

int main(void){
	int i,j;
	int number =0;
	int d;
	int a[2000];
	scanf("%d",&d);
	for(i=0;i<d;i++)
		scanf("%d",&a[i]);
	for(i=1;i<d-1;i++)
	{
		if(((a[i]<a[i-1])&&(a[i]<a[i+1]))||((a[i]>a[i-1])&&(a[i]>a[i+1])))
		{
		number ++;
		}
	}
	printf("%d",number);

	return 0;
}
