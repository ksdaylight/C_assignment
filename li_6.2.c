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
	printf("���붥�����ͱ�����\n");
	scanf("%d%d",&size,&e);
	G =(float *)malloc(size * size * sizeof(float));
	P =(float *)malloc(size  * sizeof(float));
	L =(float *)malloc(size  * sizeof(float));
	Vj =(float *)malloc(size  * sizeof(float));
	for(i = 0; i < size; i ++)//��Ȩֵ��ʼ��
		for(j = 0;j < size; j ++)
			if(i == j)
				*(G + size * i + j) = 0;
			else
				*(G + size * i + j) = -1;
	for(i = 0; i < size; i ++)//Vj��ʼ��
		*(Vj + i) = -1;
	for(k = 0; k < e; k ++)//��ʱk���ڼ���
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
		//���ϴ�k=0�����п�ʼ���ǳ�ʼ����
		for(i = 0; i < size -1; i ++)
		{	
			for(j = 0;j < size;j++)
			{
				if(!*(P + j))//��ʱ���
					if( *(G + size * k + j ) != -1)//�������ͨ·�����ж�Lj + Wkj��Lj�Ĵ�С���ı�Lj
						if((*(L + k) + *(G + size * k + j))  < *(L + j)||*(L + j) == -1 )//С����û��ͨ·
						{
							*(L +j) = *(L + k) + *(G + size * k + j);
							*(Vj + j) = k;//�ı�k ��l
						}
			}
			Min[0]= -1;
			Min[1]= max;
			for(j = 0; j < size;j ++)
			{
				if(!*(P + j))//ѡ��ֻ������ʱ��ǵ����Ƚϴ�С
				{
					if(*(L + j) == -1)
						continue;//���������Ƚ�û��ͨ·��
					if( *(L + j) < Min[1])
					{
						Min[0] = j;
						Min[1] = *(L +j);
					}
				}
				//�ҵ�Lj����С���Ǹ���
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
			  printf("%.1f-%.1f ",*(P + j),*(L + j));//���״���ͳ���
			  }
			 printf("~%c %d \n",s[k],k);//ÿ�ε�K
			 */
		}
for(i = 0;i < size;i++)
{

		printf("��%c����̾���Ϊ%.1f,·��Ϊ :",s[i],*(L + i));
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

