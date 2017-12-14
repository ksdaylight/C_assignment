#include<stdio.h>

int main(void){
	int a[2000];
	int b[2000];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		b[a[i]]++;
		printf("%d ",b[a[i]]);
	}


	return	0;
}
