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
			*(L + i) = *(G + size * l + i );//��������涼��û����ʱ��pj��
	//���ϴ�k=l�����п�ʼ���ǳ�ʼ����
	for(i = 0; i < size -1; i ++)
	{	
		for(j = 0;j < size;j++)
		{
			if(!*(P + j))//��ʱ���
				if( *(G + size * k + j ) != -1)//�������ͨ·�����ж�Lj + Wkj��Lj�Ĵ�С���ı�Lj
					if((*(L + k) + *(G + size * k + j))  < *(L + j)||*(L + j) == -1 )//С���������
						*(L +j) = *(L + k) + *(G + size * k + j);
		}
		Min[0]= -1;//λ��
		Min[1]= max;//ֵ
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
		if(Min[0] == -1)//����ͨͼ����ʱ��ǵ����еĶ���û��
		{
			break;
		}
		else
		{

			*(P + Min[0]) = 1;//��С�ı��Ϊ����
			k = Min[0];//�ı�k��ֵ
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
			printf("* ");//�������
		else	
		printf("%d ",*(L + m));
	printf("\n");
}

	return 0;
}
