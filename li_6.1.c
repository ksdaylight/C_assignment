#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define Max 1000
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
int f_dfs(int *G,int n,int m,int type,int va,int vb,int e){
	int i,j,k;
	int *ins;
	int yes;
				ins = (int *)malloc(n * sizeof(int));
				for(i = 0; i< n;i ++)
				{
					*(ins + i) = 0;
				}
	*(ins + vb) = 1;//�˽ڵ��ѱ�����
	push(vb);
	k = vb;
	while(top != -1)
	{
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
				if(*(ins + i) != 1)//���ָ���δ�����
				{
					push(i);
					*(ins + i) = 1;
					k = i;
					yes = 1;//�ҵ�����һ����
					break;//������������ָ����
				}
			}
			if(yes)
				break;//�����ұ�
		}
		if(j >= m)//û�п��߽��
		{

		k = pop();
		}
		if(k == va)//����ҵ���
		{
			top = -1;//����
			free(ins);
			return 1;
		}
	}
//������ϣ�δ��va������0.
	top = -1;//����
	free(ins);//?
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
					if(f_dfs(G,n,m,type,k,i,j))//�����⵽�������ǲ�����
					{
							printf("v%d-e%d-v%d \n",k,j,i);
							k = i;		//ȷ������������
						for(i = 0;i < n;i ++)//ɾ��������
							*(G + i*m + j) = 0;
						yes = 1;
							break;
					}
						//��������k������Ҳ����ŵı�

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
			printf("v%d-e%d-v%d  \n",k,j,i);
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
	printf("��Ҫ��������ͼ����1������ͼ����0\n");
	scanf("%d",&type);
	printf("���붨�����ͱ���:\n");
	scanf("%d%d",&n,&m);///����ͼ�����л�
	printf("����˳������ߵ����˵�:\n");
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
	if(l == -1)//��l���ж����ǵ�����
		printf("ŷ��ͼ\n");
	else
		if(l == 1)
			printf("��ŷ��ͼ\n");
		else
			printf("����ŷ��ͼҲ���ǰ�ŷ��ͼ\n");
	
	if(l == -1 || l == 1)
	{
	printf("��ŷ��·Ϊ:\n");
	Fleury(G,n,m,type,s,l);
	}
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
