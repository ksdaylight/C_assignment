#include<stdio.h>

int main(void){
	int n,m;
	int i,j;
	int a[1000][1000];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(j=m-1;j>=0;j--)
	{
		for(i=0;i<n;i++)
			printf("%d ",a[i][j]);
		printf("\n");
	}

	return 0;
}
