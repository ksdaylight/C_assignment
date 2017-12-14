#include <stdio.h>
#include <malloc.h>
#define max 19999
int main (void){
	float *G,*P,*L,*Vj;
	int size,e;
	int  i,j,k;
	float w;
	int Min[2];
	char s[ ]={"ABCDEFGHIJKS"};
	printf("输入顶点数和变数：\n");
	scanf("%d%d",&size,&e);
	G =(float *)malloc(size * size * sizeof(float));
	P =(float *)malloc(size  * sizeof(float));
	L =(float *)malloc(size  * sizeof(float));
	Vj =(float *)malloc(size  * sizeof(float));
	for(i = 0; i < size; i ++)//带权值初始化
		for(j = 0;j < size; j ++)
			if(i == j)
				*(G + size * i + j) = 0;
			else
				*(G + size * i + j) = -1;
	for(i = 0; i < size; i ++)//Vj初始化
		*(Vj + i) = -1;
	for(k = 0; k < e; k ++)//此时k用于计数
	{
		scanf("%d%d%f",&i,&j,&w);
		*(G + size * i + j) = w;
		*(G + size * j + i) = w;

	}

/*	
	   for(i = 0; i < size; i ++)
	   {

	   for(j = 0;j < size; j ++)
	   prfloatf("%f ",*(G + size * i + j));
	   prfloatf("\n");
	   }	
	  */ 
		k = 0;
		for(i = 0; i < size; i ++)
			*(P + i) = 0;
		*(P + 0) = 1;
		for(i = 0; i < size; i++)
		{
			*(L + i) = *(G + size * 0 + i );
			if(*(G + size * 0 + i )  != -1 && i!=0)
				*(Vj + i) = 0;
		}/*
		   for(i = 0; i < size;i++)
		   {
		   prfloatf("%f ",*(P + i));
		   }prfloatf("\n");
		   for(i = 0; i < size;i++)
		   {
		   prfloatf("%f ",*(L + i));
		   }prfloatf("\n");
		   */
		//以上从k=0；那行开始都是初始化。
		for(i = 0; i < size -1; i ++)
		{	
			for(j = 0;j < size;j++)
			{
				if(!*(P + j))//临时标记
					if( *(G + size * k + j ) != -1)//如果存在通路，则判断Lj + Wkj与Lj的大小来改变Lj
						if((*(L + k) + *(G + size * k + j))  < *(L + j)||*(L + j) == -1 )//小或是没有通路
						{
							*(L +j) = *(L + k) + *(G + size * k + j);
							*(Vj + j) = k;//改变k 和l
						}
			}
			Min[0]= -1;
			Min[1]= max;
			for(j = 0; j < size;j ++)
			{
				if(!*(P + j))//选择只比有临时标记的来比较大小
				{
					if(*(L + j) == -1)
						continue;//并且跳过比较没有通路的
					if( *(L + j) < Min[1])
					{
						Min[0] = j;
						Min[1] = *(L +j);
					}
				}
				//找到Lj中最小的那个；
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
			  printf("%.1f-%.1f ",*(P + j),*(L + j));//标记状况和长度
			  }
			 printf("~%c %d \n",s[k],k);//每次的K
			 */
		}
for(i = 0;i < size;i++)
{

		printf("点%c的最短距离为%.1f,路径为 :",s[i],*(L + i));
		k = *(Vj + i);
		while(k != -1)	
		{
			printf("%c ",s[k]);
			k = *(Vj + k);
		}
		printf("\n");
}
	return 0;
}

