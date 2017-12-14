#include <stdio.h>
#include <malloc.h>
#define max 19999
int main (void){
	int *G,*P,*L;
	int size;
	int i,j,k,l,m;
	int Min[2];
	size = 6;
	G =(int *)malloc(size * size * sizeof(int));
	P =(int *)malloc(size  * sizeof(int));
	L =(int *)malloc(size  * sizeof(int));
	for(i = 0; i < size; i ++)
		for(j = 0;j < size; j ++)
		{
			scanf("%d",G + size * i + j);
		}
for(l = 0;l <size ;l++)
{

		k = l;
		for(i = 0; i < size; i ++)
			*(P + i) = 0;
		*(P + l) = 1;
		for(i = 0; i < size; i++)
			*(L + i) = *(G + size * l + i );//这里和下面都是没管临时的pj的
	//以上从k=l；那行开始都是初始化。
	for(i = 0; i < size -1; i ++)
	{	
		for(j = 0;j < size;j++)
		{
			if(!*(P + j))//临时标记
				if( *(G + size * k + j ) != -1)//如果存在通路，则判断Lj + Wkj与Lj的大小来改变Lj
					if((*(L + k) + *(G + size * k + j))  < *(L + j)||*(L + j) == -1 )//小或是无穷大
						*(L +j) = *(L + k) + *(G + size * k + j);
		}
		Min[0]= -1;//位置
		Min[1]= max;//值
		for(j = 0; j < size;j ++)
		{
			if(!*(P + j))//选择只比有临时标记的
			{
				if(*(L + j) == -1)
					continue;//并且跳过比较没有通路的
				if( *(L + j) < Min[1])
				{
					Min[0] = j;
					Min[1] = *(L +j);
				}
			}
			//找到lj中最小的那个；
		}
		if(Min[0] == -1)//不联通图，临时标记的所有的都会没比
		{
			break;
		}
		else
		{

			*(P + Min[0]) = 1;//最小的标记为永久
			k = Min[0];//改变k的值
		}
		for(j = 0; j < size;j ++)
		{
			printf("%d-%d ",*(P + j),*(L + j));
		}
		printf("%d\n",k);
	}
	printf("%d :",l);
	for(m = 0; m < size; m++)
		if(*(L +m)== -1)
			printf("* ");//表是无穷；
		else	
		printf("%d ",*(L + m));
	printf("\n");
}

	return 0;
}
