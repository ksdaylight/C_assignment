 #include <stdio.h>
#include <malloc.h>
int *zi(int *p,int size){
    int i;
    int l,m;
    int *n;
    n = (int *)malloc(size * size * sizeof(int));
    for(l = 0;l < size ; l ++ )
        {
            for(m= 0; m< size; m++)
            *(n + l * size + m) = *(p+ l * size + m);
        }
    for(i = 0; i < size; i ++)
        *(n + i * size + i) = 1;
    for(l = 0;l < size ; l ++ )
        {
            for(m= 0; m< size; m++)
            printf("%d ",*(n + l * size + m));
            printf("\n");
        }
    return p;

}
int *dui(int *p,int size)
{
    int i,j;
    int l,m;
    int *n;
    n = (int *)malloc(size * size * sizeof(int));
    for(l = 0;l < size ; l ++ )
        {
            for(m= 0; m< size; m++)
            *(n + l * size + m) = *(p+ l * size + m);
        }
     for(i = 0;i < size ; i ++ )
    {
        for(j = 0; j < size; j++)
        if(*(n + i * size + j) == 1)
           *(n + j * size + i) = 1;
    }
    for(l = 0;l < size ; l ++ )
        {
            for(m= 0; m< size; m++)
            printf("%d ",*(n + l * size + m));
            printf("\n");
        }
    return p;
}
int *chuan(int *p,int size){/// haiyou mei you wei 1?
    int i,j,k;
    int l,m;
    int *n;
    n = (int *)malloc(size * size * sizeof(int));
    for(l = 0;l < size ; l ++ )
        {
            for(m= 0; m< size; m++)
            *(n + l * size + m) = *(p+ l * size + m);
        }
    for(j = 0;j < size ; j ++ )
    {
        for(i= 0; i< size; i++)
        {
            if(*(n + i * size + j) == 1)
            {
                for(k = 0; k < size;k ++)
                {
                      if(*(n + i* size + k)||*(n + j* size + k))
                        *(n + i* size + k) = 1;

                }
            }
        }


    }
     for(l = 0;l < size ; l ++ )
        {
            for(m= 0; m< size; m++)
            printf("%d ",*(n + l * size + m));
            printf("\n");
        }
    return p;
}

int main(void)
{
    int size;
    int *n;
    int i,j,k;
    printf("请输入集合A的元素个数:\n");
    scanf("%d",&size);
    n = (int *)malloc(size * size * sizeof(int));
    printf("请输入关系R对应的矩阵:\n");
    for(i = 0;i < size ; i ++ )
    {
        for(j = 0; j < size; j++)
        scanf("%d",n + i * size + j);

    }
    printf("自反闭包:\n");
    n = zi(n,size);
    printf("对称闭包:\n");
    n = dui(n,size);
    printf("传递闭包:\n");
    n = chuan(n,size);

    return 0;
}

/*实验五 关系闭包运算	

【实验目的】掌握求关系闭包的方法。
【实验内容】编程求一个关系的闭包，要求传递闭包用warshall方法。
【实验原理和方法】
设N元关元系用r[N][N]表示，c[N][N]表示各个闭包，函数initc(r)表示将c[N][N]初始化为r[N][N]。
（1）自反闭包： 。
 
（2）对称闭包： 
 
（3）传递闭包： 。  （选作）

（4）课后练习P116练习4.14为测试例子

91，3

5
1 0 0 0 0
0 0 1 0 1
0 0 0 1 0
0 0 1 0 0
0 0 0 0 7
4
0 1 0 0
0 0 1 1
1 1 0 1
1 0 0 0
*/
