 #include <stdio.h>
#include <malloc.h>
int *zi(int *n,int size){
    int i;
    for(i = 0; i < size; i ++)
        *(n + i * size + i) = 1;
    return n;
 /*           return 0;
    return 1;*/
}
int *dui(int *n,int size)
{
    int i,j;
     for(i = 0;i < size ; i ++ )
    {
        for(j = 0; j < size; j++)
        if(*(n + i * size + j) == 1)
           *(n + j * size + i) = 1;
    }
    return n;
}
int *chuan(int *n,int size){/// haiyou mei you wei 1?
    int i,j,k;
//    int l,m;
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
 /*       printf("%d\n",j);///////////
        for(l = 0;l < size ; l ++ )
        {
            for(m= 0; m< size; m++)
            printf("%d ",*(n + l * size + m));
            printf("\n");
        }
   */
    }
    return n;
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
   // n = zi(n,size);
    //n = dui(n,size);
    n = chuan(n,size);///改为每个函数自己建立
    for(i = 0;i < size ; i ++ )
        {
            for(j = 0; j < size; j++)
            printf("%d ",*(n + i * size + j));
            printf("\n");
        }
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
