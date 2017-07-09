#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int INF=0x3f3f3f3f;
int n,cnt;
int dist[201];

struct node{
    int u,v,w;
}edge[1010*2];//ע�����

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
    for(int i=0;i<n;i++){//ÿ�ι��̶���ó���ǰһ�θ����ȸ������̾���
        flag=false;
        for(int j=0;j<cnt;j++){
            if(dist[edge[j].u]!=INF&&dist[edge[j].v]>dist[edge[j].u]+edge[j].w){
                dist[edge[j].v]=dist[edge[j].u]+edge[j].w;//�����³ɸ�С��,
                flag=true;
            }
        }
        if(flag==false) break;
    }
    if(flag==true) cout<<"���ڸ���\n";
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
#�㷨����
    ��ÿ���߽���1���ɳڵ�ʱ�������˴�s�������������Ϊ1����Щ��֦��Ҳ����˵���ҵ�����s������1������������Щ��������·������ÿ���߽��е�2���ɳڵ�ʱ�������˵�2��ε���֦������˵�ҵ��˾���2������������Щ��������·����������Ϊ���·�����ֻ����|v|-1 ���ߣ����ԣ�ֻ��Ҫѭ��|v|-1 �Ρ� ÿʵʩһ���ɳڲ��������·�����Ͼͻ���һ�㶥��ﵽ����̾��룬�˺���㶥�����̾���ֵ�ͻ�һֱ���ֲ��䣬�����ܺ����ɳڲ�����Ӱ�졣
*/

