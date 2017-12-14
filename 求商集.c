#include <stdio.h>
#include <malloc.h>
int zi(int *n,int size){
    int i;
    for(i = 0; i < size; i ++)
    {
        if( *(n + i * size + i) != 1)
            return 0;
    }

    return 1;
}
int dui(int *n,int size)
{
    int i,j;
     for(i = 0;i < size ; i ++ )
    {
        for(j = 0; j < size; j++)
        if(*(n + i * size + j) == 1)
            if(*(n + i * size + j) != *(n + j * size + i))
                return 0;
    }
    return 1;
}
int chuan(int *n,int size){/// haiyou mei you wei 1?
    int i,j,k;
    for(i = 0;i < size ; i ++ )
    {
        if (i == j)
        continue;///?
        for(j = 0; j < size; j++)
        {
            if(*(n + i * size + j) == 1)
            {
                for(k = 0; k < size;k ++)
                {
                    if(*(n + j* size + k) == 1)
                        if(*(n + i* size + k) != 1)
                        return 0;
                }
            }
        }
    }
    return 1;
}
void deng(int *n,int size){
	int *s,*t;
	int i,j,k,l,m,o;
    s = (int *)malloc(size * size * sizeof(int));//放等价类
    t = (int *)malloc(size * sizeof(int));//检验相交
	l = 0;
	for(i = 0 ; i < size; i ++)
		*(t + i) = -1;
	for(i = 0 ; i < size; i ++)
		for(j = 0 ; j < size; j ++)
            *(s + i* size + j) = -1;
			
    for(i = 0;i < size ; i ++ )
    {
		k = 0;//从s的每行开始插入
        for(j = 0; j < size; j++)
            if(*(n + i* size + j) == 1)
				{
						o = 1;
					for(m = 0;m < l; m++)//检验相交
					{
						if(*(t + m) == j)
						{
							o = 0;
							break;
						}
					}
					if(o == 1)//可以插入
					{
						*(s + i * size + k) = j;
						k ++;
						*(t + l) = j;
					    l ++;	
					}
					else
					{
						for(m = 0;m < size;m ++)//为相交等价类，清除前面的已经加进去的。
						{
							if(*(s + i * size + m) != -1)
							{
								l --;
								*(t + l) = -1;
								*(s + i * size + m) = -1;

							}
						}
						break;//跳出这一行
					}
				}


	}
//	printf("\n -%d\n",l);
//	for(i = 0 ; i < l;i ++)
//		printf("%d ",*(t + i));
	printf("商集：\n{");
	for(i = 0 ; i < size; i ++)
	{
		if(*(s + i * size + 0) == -1)
			break;
		else
			{
			printf("{");
			for(j = size - 1; j > 0; j --)
				if(*(s + i * size + j) != -1)
				{
					printf("%d,",-*(s + i * size + j));
				
				}
			for(j = 0 ; j < size; j ++)
				if(*(s + i * size + j) != -1)
				{
				if(*(s + i * size + j + 1) != -1)
					printf("%d,",*(s + i * size + j));
				else
					{
						printf("%d",*(s + i * size + j));
						break;
					}
				}
			if(*(s + (i + 1) * size + 0) != -1)
			printf("},");
			else
				printf("}");

			}
	}
	printf("}");
	
}
int main(void) {
    int size;
    int *n,x;
    int i,j,k;
    size = 101;//0到100的整数。
    n = (int *)malloc(size * size * sizeof(int));
    printf("请输入模n\n");
	scanf("%d",&x);	
    for(i = 0;i < size ; i ++ )
    {
        for(j = 0; j < size; j++)
			if(i % x == j % x)
					*(n + i * size + j) = 1;

    }
	if(zi(n,size)&&dui(n,size)&&chuan(n,size))
	{
		printf("二元关系为等价关系\n");
		deng(n,size);
	}
	else
		printf("二元关系不为等价关系\n");
    return 0;
}
