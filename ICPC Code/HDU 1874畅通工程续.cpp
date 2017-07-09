#include<iostream>
#include<cstdio>
#include<cstring >
#include<algorithm>
using namespace std;

int dis[201][201];
int n;

const int INF =10000000;

void Floyd()
{
    for(int k=0;k<n;k++)//floyd算法实现的关键是k要是最外层循环
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j])
                dis[i][j]=dis[i][k]+dis[k][j];
}

int main()
{
    int m,a,b,t1,t2,t3;
    while(scanf("%d%d",&n,&m)==2){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dis[i][j]=(i==j?0:INF);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&t1,&t2,&t3);
            if(dis[t1][t2]>t3) dis[t1][t2]=dis[t2][t1]=t3;//因为有重复的情况出现
        }
        Floyd();
        scanf("%d%d",&a,&b);
        if(dis[a][b]!=INF)
        printf("%d\n",dis[a][b]);
        else printf("-1\n");
    }
    return 0;
}
