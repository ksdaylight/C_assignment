#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define Max 1000
//#define Max 10
int stack[Max];
int top = -1;

void push(int v)
{
	if(top >= Max)
	{

	printf("%d stack full\n",stack[Max-1]);
	exit(0);

	}
	else
	{
		top ++;
		stack[top] = v;
	}
}
int pop(void){
	int temp;
	if(top < 0)
	{

	printf("stack empty\n");
	return -1;
	}
	temp = stack[top];
	top --;
	return temp;
}
///f_dfs�����ж��Ƿ�����,ԭ���ǲ���ͨ���˱ߵ���Ľ��(vb)�ܷ������ڲ��������߾�����ȱ�����ԭ���Ľ��(va)
int f_dfs(int *G,int n,int m,int type,int va,int vb,int e){
	int i,j,k;
	int *ins;
	int yes;
				ins = (int *)malloc(n * sizeof(int));
				for(i = 0; i< n;i ++)
				{
					*(ins + i) = 0;
				}
/*
for(i = 0;i < n;i++ )
{for(j = 0;j < m; j++ )
	printf("%d ",*(G + i*m + j));
	printf("\n");
}*/
	*(ins + vb) = 1;//�˽ڵ��ѱ�����
	push(vb);
	k = vb;
/*for(i = 0; i< n;i ++)
	{
printf("%d ",*(ins + i));
}
printf("\n");
*/
	while(top != -1)
	{
//printf("k =%d 3st\n",k);
		yes = 0;
		for(j = 0; j < m; j++)
		{	
			
			if(j == e)
				continue;
			if(*(G + k*m +j) == 1)///�ҵ�һ����ʼ��
			{
				for(i = 0;i < n;i ++)//�ҵ�������ָ��Ľ��
				{
					if(i == k)
						continue;
					if(type)
					{
						if(*(G + i*m +j) == 1)
							break;
					}
						else
							if(*(G + i*m +j) == -1)
								break;
				}
//printf("i =%d,ins-I =%d j = %d\n",i,*(ins + i),j);
				if(*(ins + i) != 1)//���ָ���δ�����
				{
					push(i);
					*(ins + i) = 1;
					k = i;
					yes = 1;//�ҵ�����һ����
//printf("%d k yes %d(yes)\n",k,yes);
					break;//������������ָ����
				}
			}
			if(yes)
				break;//�����ұ�
//printf("aero test%d\n",j);
		}
		if(j >= m)//û�п��߽��
		{

		k = pop();
//printf("%d,%d,%d,%d\n",stack[0],stack[1],stack[2],stack[3]);
//printf("%d k no %d top = %d\n",k,j,top);
		}
		if(k == va)//����ҵ���
		{
			top = -1;//����
			free(ins);
			return 1;
		}
//printf("4st\n");
//printf("top =%d \n",top);
//if(k<0)
//exit(0);
	}
//������ϣ�δ��va������0.
	return 0;

}
void Fleury(int *G,int n,int m,int type,int s[2],int l){
	int i,j,k;
	int number;
	int yes;
	if(type)//����ʼ��	
	{
		if(l == -1)///�л�·������㿪ʼ���˴�ȡ��v0
			k = 0;
		else
			k = s[0];//����ȶ��㿪ʼ

	}
	else
	{
		if(l == -1)///�л�·������㿪ʼ���˴�ȡ��v0
			k = 0;
		else
			for(j = 0;j < 2; j ++)
			{
				if(s[j] > 0)
					k = s[j];
			}
	}
//printf("k=%d,l=%d,s[0]=%ds[1]=%d\n",k,l,s[0],s[1]);
	for(number = 0; number < m; number++)///��ൽ��ɾ�����˾ͽ�����kΪÿ���ڵĽ��λ��
	{
		yes = 0;
		for(j = 0; j < m; j++)
		{
			if(*(G + k*m +j) == 1)///�ҵ�һ����ʼ��
			{
				for(i = 0;i < n;i ++)//�ҵ�������ָ��Ľ��
				{
					if(i == k)
						continue;
					if(type)
					{

						if(*(G + i*m +j) == 1)
							break;
					}
						else
							if(*(G + i*m +j) == -1)
								break;
					
				}
//printf("1st va =%d vb =%d e=%d \n",k,i,j);
					if(f_dfs(G,n,m,type,k,i,j))//�����⵽�������ǲ�����
					{
							printf("v%d-e%d-v%d yes\n",k,j,i);
							k = i;		//ȷ������������
						for(i = 0;i < n;i ++)//ɾ��������
							*(G + i*m + j) = 0;
						yes = 1;
							break;
					}
						//��������k������Ҳ����ŵı�
//printf("2st\n");

			}
			if(yes)
				break;//�����ұ�
		}
		if(j >= m)//û�в����ŵı���
		{
			for(j = 0; j < m; j++)
			{
					yes = 0;
					
				if(*(G + k*m +j) == 1)///����ҵ�һ����ʼ��
					for(i = 0;i < n;i ++)//�ҵ�������ָ��Ľ��
					{
						if(i == k)
							continue;
						if(type)
						{
						if(*(G + i*m +j) == 1)
						{
							yes = 1;
							break;
							
						}
						}
							else
								if(*(G + i*m +j) == -1)
								{
									yes = 1;
									break;

								}
					}
					if(yes)
						break;
			}
			printf("v%d-e%d-v%d  no\n",k,j,i);
			k = i;		//ȷ������������
			for(i = 0;i < n;i ++)//ɾ��������
				*(G + i*m + j) = 0;

		}

	}
}
int main(void)
{
	int n,m;//n����,m����
	int *G;
	int i,j,k,l;
	int type;//����ͼΪ1����ͼΪ0
	int s[2];
	scanf("%d",&type);
	scanf("%d%d",&n,&m);///����ͼ�����л�
	G = (int*)malloc(n*m*sizeof(int));
	for(i = 0;i < n;i++ )
		for(j = 0;j < m; j++ )
			*(G + i*m + j) = 0;
	for(k = 0;k < m;k++)///���������
	{
		scanf("%d%d",&i,&j);//i���j�յ�
		if(type)
		{

			*(G + i * m + k) = *(G + i * m + k) + 1;
			*(G + j * m + k) = *(G + j * m + k) + 1;
		}
		else
		{
			*(G + i*m + k) = 1;
			*(G + j*m + k) = -1;
		}

	}
	l = -1;
	if(type)
	{
		for(i = 0;i < n;i++ )///ÿ�ж������
		{
			k = 0;
			for(j = 0;j < m; j++ )
				k += *(G + i*m + j);
			printf("%d\n",k);///================================
			if(k % 2 != 0)
			{

				l++;
				if(l>2)
					break;
				else
					s[l] = i;

			}
		}
	}
	else{

		for(i = 0;i < n;i++ )
		{
			k = 0 ;
			for(j = 0;j < m; j++ )
				k += *(G + i*m + j) ;
			if(k!= 0)
			{
				l++;
				if(l>2)
					break;
				else
					if(k>0)///��ʼ��ĳ��ȶ�����Ϊ����
						s[l] = i;
					else
						s[l] = -i;

			}
		}
	}
	for(i = 0;i < n;i++ )
	{for(j = 0;j < m; j++ )
		printf("%d ",*(G + i*m + j));
		printf("\n");
	}
	printf("%d\n",l);
	if(l == -1)//��l���ж����ǵ�����
		printf("ŷ��ͼ\n");
	else
		if(l == 1)
			printf("��ŷ��ͼ\n");
		else
			printf("����ŷ��ͼҲ���ǰ�ŷ��ͼ\n");
	Fleury(G,n,m,type,s,l);
	return 0;
}
/**
  ŷ��ͼ
  ����
  1
  9 14
  0 1
  1 2
  2 3
  3 4
  4 5
  5 6
  6 7
  7 0
  7 1
  1 8
  7 8
  8 3
  3 5
  5 8
  ����
  0
  4 6
  0 1
  1 2
  2 3
  3 0
  0 2
  2 0
  ��ŷ��ͼ
  ����
  1
  4 5
  0 1
  1 2
  2 3
  3 0
  0 2

  ����
  0
  4 5
  0 1
  1 2
  2 3
  3 0
  2 0
  ˫��
  ����
  1
  4 6
  0 1
  0 2
  0 3
  1 2
  1 3
  2 3
  ����
  0
  4 5
  0 1
  1 2
  3 2
  3 0
  2 0
  */
