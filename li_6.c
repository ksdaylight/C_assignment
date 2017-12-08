#include <stdio.h>
#include <malloc.h>
int main(void)
{
    int n,m;
    int *G;
    int i,j,k,l;
    int type,type1;//无向图为1有向图为0
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
        for(i = 0;i < n;i++ )///每行
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
                                if(k>0)///初始点的出度多
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
        if(l == 0||l == -1)
            printf("欧拉图\n");
        else
            if(l == 2)
                printf("半欧拉图\n");
            else
                printf("不是欧拉图也不是半欧拉图\n");
        return 0;
}
/**
欧拉图
无向


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
有向
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



*/
