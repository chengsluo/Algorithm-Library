#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int INF=0x3f3f3f3f;
int map[201][201];
int n;
bool vis[201];
int dist[201];

void Dijkstra(int s,int t)
{
    for(int i=0;i<n;i++){
        dist[i]=map[s][i];
        vis[i]=0;
    }
    vis[s]=1;dist[s]=0;
    for(int i=0;i<n-1;i++){
        int tmp=INF;
        int k;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dist[j]<tmp) {
                    tmp=dist[j];
                    k=j;
            }
        }
        if(tmp==INF) break;
        vis[k]=1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&map[k][j]+dist[k]<dist[j]) dist[j]=map[k][j]+dist[k];
        }
    }
    return;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[i][j]=INF;
            }
        }
        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(map[u][v]>w) ///如果map[u][v]当前值比新输入的值大时才更新，因为这是一个有重边的双向图模型
                map[u][v]=map[v][u]=w;
        }
        int s,t;
        scanf("%d%d",&s,&t);
        Dijkstra(s,t);
        if(dist[t]==INF){
            cout<<-1<<endl;
        }else{
            cout<<dist[t]<<endl;
        }
    }
    return 0;
}
