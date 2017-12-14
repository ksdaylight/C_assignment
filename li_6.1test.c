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
///f_dfs用来判断是否是桥,原理是测试通过此边到达的结点(vb)能否做到在不走这条边就能深度遍历到原来的结点(va)
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
	*(ins + vb) = 1;//此节点已遍历过
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
			if(*(G + k*m +j) == 1)///找到一条起始边
			{
				for(i = 0;i < n;i ++)//找到这条边指向的结点
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
				if(*(ins + i) != 1)//如果指向点未被标记
				{
					push(i);
					*(ins + i) = 1;
					k = i;
					yes = 1;//找到了下一个边
//printf("%d k yes %d(yes)\n",k,yes);
					break;//不是则跳出找指向结点
				}
			}
			if(yes)
				break;//跳出找边
//printf("aero test%d\n",j);
		}
		if(j >= m)//没有可走结点
		{

		k = pop();
//printf("%d,%d,%d,%d\n",stack[0],stack[1],stack[2],stack[3]);
//printf("%d k no %d top = %d\n",k,j,top);
		}
		if(k == va)//如果找到了
		{
			top = -1;//清零
			free(ins);
			return 1;
		}
//printf("4st\n");
//printf("top =%d \n",top);
//if(k<0)
//exit(0);
	}
//遍历完毕，未有va，返回0.
	return 0;

}
void Fleury(int *G,int n,int m,int type,int s[2],int l){
	int i,j,k;
	int number;
	int yes;
	if(type)//找起始点	
	{
		if(l == -1)///有回路从任意点开始，此处取点v0
			k = 0;
		else
			k = s[0];//从奇度顶点开始

	}
	else
	{
		if(l == -1)///有回路从任意点开始，此处取点v0
			k = 0;
		else
			for(j = 0;j < 2; j ++)
			{
				if(s[j] > 0)
					k = s[j];
			}
	}
//printf("k=%d,l=%d,s[0]=%ds[1]=%d\n",k,l,s[0],s[1]);
	for(number = 0; number < m; number++)///最多到边删除完了就结束，k为每次在的结点位置
	{
		yes = 0;
		for(j = 0; j < m; j++)
		{
			if(*(G + k*m +j) == 1)///找到一条起始边
			{
				for(i = 0;i < n;i ++)//找到这条边指向的结点
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
					if(f_dfs(G,n,m,type,k,i,j))//如果检测到这条边是不是桥
					{
							printf("v%d-e%d-v%d yes\n",k,j,i);
							k = i;		//确认走这条边了
						for(i = 0;i < n;i ++)//删除这条边
							*(G + i*m + j) = 0;
						yes = 1;
							break;
					}
						//继续在这k结点上找不是桥的边
//printf("2st\n");

			}
			if(yes)
				break;//跳出找边
		}
		if(j >= m)//没有不是桥的边了
		{
			for(j = 0; j < m; j++)
			{
					yes = 0;
					
				if(*(G + k*m +j) == 1)///随便找到一条起始边
					for(i = 0;i < n;i ++)//找到这条边指向的结点
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
			k = i;		//确认走这条边了
			for(i = 0;i < n;i ++)//删除这条边
				*(G + i*m + j) = 0;

		}

	}
}
int main(void)
{
	int n,m;//n点数,m边数
	int *G;
	int i,j,k,l;
	int type;//无向图为1有向图为0
	int s[2];
	scanf("%d",&type);
	scanf("%d%d",&n,&m);///有向图不能有环
	G = (int*)malloc(n*m*sizeof(int));
	for(i = 0;i < n;i++ )
		for(j = 0;j < m; j++ )
			*(G + i*m + j) = 0;
	for(k = 0;k < m;k++)///依次输入边
	{
		scanf("%d%d",&i,&j);//i起点j终点
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
		for(i = 0;i < n;i++ )///每行度数求和
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
					if(k>0)///初始点的出度多设置为正的
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
	if(l == -1)//用l来判断他们的类型
		printf("欧拉图\n");
	else
		if(l == 1)
			printf("半欧拉图\n");
		else
			printf("不是欧拉图也不是半欧拉图\n");
	Fleury(G,n,m,type,s,l);
	return 0;
}
/**
  欧拉图
  无向
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
  有向
  0
  4 6
  0 1
  1 2
  2 3
  3 0
  0 2
  2 0
  半欧拉图
  无向
  1
  4 5
  0 1
  1 2
  2 3
  3 0
  0 2

  有向
  0
  4 5
  0 1
  1 2
  2 3
  3 0
  2 0
  双非
  无向
  1
  4 6
  0 1
  0 2
  0 3
  1 2
  1 3
  2 3
  有向
  0
  4 5
  0 1
  1 2
  3 2
  3 0
  2 0
  */
