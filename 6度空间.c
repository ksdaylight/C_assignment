#include <stdio.h>
#include <malloc.h>
#define max 19999
int main (void){
	int *G,*P,*L;
	int size,e;
	int i,j,k,l,m;
	float number;
	int Min[2];
	scanf("%d%d",&size,&e);
	G =(int *)malloc(size * size * sizeof(int));
	P =(int *)malloc(size  * sizeof(int));
	L =(int *)malloc(size  * sizeof(int));
	for(i = 0; i < size; i ++)
		for(j = 0;j < size; j ++)
			if(i == j)
				*(G + size * i + j) = 0;
			else
				*(G + size * i + j) = -1;
	for(k = 0; k < e; k ++)//此时k用于计数
	{
		scanf("%d%d",&i,&j);
		i--;
		j--;
		*(G + size * i + j) = 1;
		*(G + size * j + i) = 1;

	}

/*	
	   for(i = 0; i < size; i ++)
	   {

	   for(j = 0;j < size; j ++)
	   printf("%d ",*(G + size * i + j));
	   printf("\n");
	   }	
	  */ 
	for(l = 0; l < size; l ++)
	{
		k = l;
		for(i = 0; i < size; i ++)
			*(P + i) = 0;
		*(P + l) = 1;
		for(i = 0; i < size; i++)
			*(L + i) = *(G + size * l + i );
		/*
		   for(i = 0; i < size;i++)
		   {
		   printf("%d ",*(P + i));
		   }printf("\n");
		   for(i = 0; i < size;i++)
		   {
		   printf("%d ",*(L + i));
		   }printf("\n");
		   */
		//以上从k=l；那行开始都是初始化。
		for(i = 0; i < size -1; i ++)
		{	
			for(j = 0;j < size;j++)
			{
				if(!*(P + j))//临时标记
					if( *(G + size * k + j ) != -1)//如果存在通路，则判断Lj + Wkj与Lj的大小来改变Lj
						if((*(L + k) + *(G + size * k + j))  < *(L + j)||*(L + j) == -1 )//小或是没有通路
							*(L +j) = *(L + k) + *(G + size * k + j);
			}
			Min[0]= -1;
			Min[1]= max;
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
			if(Min[0]==-1)
				break;
			else
			{

				*(P + Min[0]) = 1;//标记为永久
				k = Min[0];//改变k的值
			}
			/*for(j = 0; j < size;j ++)
			  {
			  printf("%d-%d ",*(P + j),*(L + j));
			  }
			  printf("%d\n",k);*/
		}
		number = 0;
		for(m = 0; m < size; m++)
		{
		//	printf("%d ",*(L +m));
			if(*(L + m) <= 6 && *(L + m) != -1)//无穷大不算
				number ++;
		}
//		printf("~");
	
		printf("%d: %.2f%%\n",l+1,number/size * 100);//1: 70.00%
	}

	return 0;
}

