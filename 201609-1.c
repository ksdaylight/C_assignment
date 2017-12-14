#include <stdio.h>
#include <math.h>
int main(void){
	int a[2000];
	int i,j,k;
	int ma=0;
	scanf("%d",&k);
	for(i=0;i<k;i++)	
		scanf("%d",&a[i]);
	for(i = 0;i<k-1;i++)
			if(ma<abs(a[i]-a[i+1]))
				ma=abs(a[i]-a[i+1]);
	printf("%d",ma);

	return 0;
}
