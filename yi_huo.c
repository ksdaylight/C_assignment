#include <stdio.h>
#include <malloc.h>
int main(void){
int m,n,k;
int *x;
int i,j;
scanf("%d%d",&n,&m);
x=(int*)malloc(n*m*sizeof(int));

for(i=0;i<n;i++)
{
	for(j =0;j<m;j++)
	{
		scanf("%d",&k);
		*(x + i*m + j)=k;
	}
}
for(j=m-1;j>=0;j--)
{
	for(i=0;i<n;i++)
		printf("%d ",*(x+i*m+j));
	printf("\n");
}


	return	0;
}
