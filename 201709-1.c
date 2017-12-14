#include<stdio.h>

int main(void){
	int i,j;
	scanf("%d",&i);
	j = 0;
	j += i/50 * 7;
	i =  i%50;
	j += i/30 * 4;
	i = i%30;
	j += i/10;
	printf("%d",j);
	return 0;	
}
