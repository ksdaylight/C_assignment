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
	for(k = 0; k < e; k ++)//��ʱk���ڼ���
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
		//���ϴ�k=l�����п�ʼ���ǳ�ʼ����
		for(i = 0; i < size -1; i ++)
		{	
			for(j = 0;j < size;j++)
			{
				if(!*(P + j))//��ʱ���
					if( *(G + size * k + j ) != -1)//�������ͨ·�����ж�Lj + Wkj��Lj�Ĵ�С���ı�Lj
						if((*(L + k) + *(G + size * k + j))  < *(L + j)||*(L + j) == -1 )//С����û��ͨ·
							*(L +j) = *(L + k) + *(G + size * k + j);
			}
			Min[0]= -1;
			Min[1]= max;
			for(j = 0; j < size;j ++)
			{
				if(!*(P + j))//ѡ��ֻ������ʱ��ǵ�
				{
					if(*(L + j) == -1)
						continue;//���������Ƚ�û��ͨ·��
					if( *(L + j) < Min[1])
					{
						Min[0] = j;
						Min[1] = *(L +j);
					}
				}
				//�ҵ�lj����С���Ǹ���
			}
			if(Min[0]==-1)
				break;
			else
			{

				*(P + Min[0]) = 1;//���Ϊ����
				k = Min[0];//�ı�k��ֵ
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
			if(*(L + m) <= 6 && *(L + m) != -1)//�������
				number ++;
		}
//		printf("~");
	
		printf("%d: %.2f%%\n",l+1,number/size * 100);//1: 70.00%
	}

	return 0;
}

