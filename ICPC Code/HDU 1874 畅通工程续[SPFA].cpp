#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int INF=0x3f3f3f3f;
int map[201][201];
int n;
bool vis[201];
int dist[201];
queue<int> qu;
void SPFA(int s,int t)
{
    while(!qu.empty()) qu.pop();
    int i;
    for(i=0;i<n;i++){
        dist[i]=INF;
        vis[i]=0;
    }
    dist[s]=0;vis[s]=1;
    qu.push(s);
    while(!qu.empty()){
            int tmp=qu.front();
            qu.pop();
            vis[tmp]=0;
            for(i=0;i<n;i++){
                if(dist[i]>dist[tmp]+map[tmp][i]){
                    dist[i]=dist[tmp]+map[tmp][i];
                    if(!vis[i]){
                        vis[i]=1;
                        qu.push(i);
                    }
                }
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
        SPFA(s,t);
        if(dist[t]==INF){
            cout<<-1<<endl;
        }else{
            cout<<dist[t]<<endl;
        }
    }
    return 0;
}

