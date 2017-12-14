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
int f_dsf(int va,int vb,float *Lin,int *P,int e,int size)
{
	int i,j,k;
	int *ins;
	int yes;
				ins = (int *)malloc(size * sizeof(int));
				for(i = 0; i< size;i ++)
				{
					*(ins + i) = 0;
				}
	*(ins + vb) = 1;//�˽ڵ��ѱ�����
	push(vb);
	k = vb;

	while(top!=-1)
	{
		yes = 0;
		for(i = 0;i < e;i ++ )
		{

		if(((int)*(Lin + i*3 +0)==k||(int)*(Lin + i*3 +1)==k)&&*(P + i)==1)
			{
				for(j =0;j<2;j++ )
				if((int)*(Lin + i*3 +j)!=k)//ָ���
				{
					if(*(ins + (int)*(Lin + i*3 +j) ) != 1)//δ������
					{
						push((int)*(Lin + i*3 +j));
						*(ins + (int)*(Lin + i*3 +j)) = 1;//���
						k =*(Lin + i*3 +j);
						yes = 1;
						break;
					}
						
				}

			}
		}
		if(yes != 1)///û�ҵ���һ�������
		{
			k = pop();
		}
		if(k == va)//����ҵ�����������ͬһ����
		{
			top = -1;//����
			free(ins);
			return 0;
		}

	}
	top = -1;//����
	free(ins);
	return 1;
}
void SelectionSort(float *Lin,int e)  
{  
 int i = 0;  
 int  min = 0;  
 int j = 0;  
 int tmp = 0;  
 for(i = 0;i < e-1;i++)  
 {  
    min = i;//ÿ��min�ó���������ʼλ��Ԫ���±�   
    for(j = i;j < e;j++)//���������飬�ҵ���СԪ�ء�   
    {  
      if(*(Lin + min*3 + 2)>*(Lin+j*3 + 2))  
      {  
       min = j;
      }  
    }  
    if(min != i)//�����СԪ�ز�����������ʼλ��Ԫ�أ�������ʼԪ�ؽ���λ��   
    {  
      tmp = *(Lin + min *3 + 0);  
       *(Lin + min *3 + 0) = *(Lin + i * 3 + 0);  
      *(Lin + i * 3 + 0) = tmp;  
      tmp = *(Lin + min *3 + 1);  
       *(Lin + min *3 + 1) = *(Lin + i * 3 + 1);  
      *(Lin + i * 3 + 1) = tmp;  
      tmp = *(Lin + min *3 + 2);  
       *(Lin + min *3 + 2) = *(Lin + i * 3 + 2);  
      *(Lin + i * 3 + 2) = tmp;  
    }  
 }  
}  
 void Kruskal(float *Lin,int *P,int size,int e) 
{
	int edge = 0;
	float weight = 0;
	int k = 0;
	char s[ ]={"ABCDEFGHIJKS"};
	while(edge != size - 1)
	{
	  if(f_dsf((int)*(Lin + k*3 +0),(int)*(Lin + k*3 +1),Lin,P,e,size))
	  {
		weight +=*(Lin + k*3 + 2);
		printf("�����%c��%c\n",s[(int)*(Lin + k*3 +0)],s[(int)*(Lin + k*3 +1)]);
		*(P + k) = 1;//�߷�������
		edge ++;
	  }
	  k ++;
	  if(k > e)
	  {
			printf("no tree \n");
			break;
	  }
	}
	if(k<=e)
	{
		printf("����Ȩ��Ϊ��%.1f\n",weight);
	}
}
int main(void)  
{ 
 float *Lin;
 int *P;
 float w;
 int size,e;
 int i,j,k;
 scanf("%d%d",&size,&e);
 Lin = (float *)malloc(e*3*sizeof(float));
 P = (int *)malloc(e*sizeof(int));
 for(i = 0;i < e;i++)
 {
*(P + i) = 0;//��ʼ��0
 }
 for(k = 0;k < e;k ++)
 {
	 scanf("%d%d%f",&i,&j,&w);
	 *(Lin + k*3 +0)= i;
	 *(Lin + k*3 +1) = j; 
	 *(Lin + k*3 +2) = w ;
 }

 SelectionSort(Lin,e);
 Kruskal(Lin,P,size,e);
 return 0;  
}  
