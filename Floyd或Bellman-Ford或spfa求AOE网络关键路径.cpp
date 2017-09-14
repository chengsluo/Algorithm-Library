#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int M=50;
int G[M][M];
int deg[M];///入度
int dis[M][M];
int Prev[M];///前驱
int Pass[M];
int n,m;

void MaxDijkstra(int s)
{
       for(int k=0;k<n;k++){
              for(int i=0;i<n;i++){
                     for(int j=0;j<n;j++){
                            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                     }
              }
       }
       int longest=0;
       for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                     longest=min(longest,dis[i][j]);
                     cout<<dis[i][j]<<" ";
              }
              cout<<endl;
       }
       cout<<-longest<<endl;
}
int main()///AOE网络只有一个入度为0的点,无环,边的权值为正数
{
       int u,v,w;
       scanf("%d%d",&n,&m);
       memset(G,0,sizeof(G));
       memset(deg,0,sizeof(deg));
              for(int i=0;i<M;i++){
                     for(int j=0;j<M;j++){
                            if(i==j) dis[i][j]
                            dis[i][j]=10000;
                     }
              }
       for(int i=0;i<m;i++){
              scanf("%d%d%d",&u,&v,&w);
              G[u][v]=w;
              dis[u][v]=w;
              deg[v]++;
       }
       MaxDijkstra(0);
       for(int i=0;i<n;i++){
              if(deg[i]==0){

                     break;
              }
       }
       return 0;
}
