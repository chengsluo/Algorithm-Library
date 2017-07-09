#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int INF=0x3f3f3f3f;
int n,cnt;
int dist[201];

struct node{
    int u,v,w;
}edge[1010*2];//注意边数

void add_edge(int u,int v,int w)
{
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].w=w;
    cnt++;
    edge[cnt].v=u;edge[cnt].u=v;edge[cnt].w=w;
    cnt++;
    return;
}

void Bellman_Ford(int s,int t)
{
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[s]=0;
    bool flag;
    for(int i=0;i<n;i++){//每次过程都会得出比前一次更长度更大的最短距离
        flag=false;
        for(int j=0;j<cnt;j++){
            if(dist[edge[j].u]!=INF&&dist[edge[j].v]>dist[edge[j].u]+edge[j].w){
                dist[edge[j].v]=dist[edge[j].u]+edge[j].w;//将更新成更小的,
                flag=true;
            }
        }
        if(flag==false) break;
    }
    if(flag==true) cout<<"存在负环\n";
    return;
}

int main()
{
    int m;
    while(scanf("%d%d",&n,&m)==2)
    {
        cnt=0;
        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
        }
        int s,t;
        scanf("%d%d",&s,&t);
        Bellman_Ford(s,t);
        if(dist[t]==INF){
            cout<<-1<<endl;
        }else{
            cout<<dist[t]<<endl;
        }
    }
    return 0;
}
/*
#算法解释
    对每条边进行1遍松弛的时候，生成了从s出发，层次至多为1的那些树枝。也就是说，找到了与s至多有1条边相联的那些顶点的最短路径；对每条边进行第2遍松弛的时候，生成了第2层次的树枝，就是说找到了经过2条边相连的那些顶点的最短路径……。因为最短路径最多只包含|v|-1 条边，所以，只需要循环|v|-1 次。 每实施一次松弛操作，最短路径树上就会有一层顶点达到其最短距离，此后这层顶点的最短距离值就会一直保持不变，不再受后续松弛操作的影响。
*/

