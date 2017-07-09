#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int INF=0x3f3f3f3f;
int map[201][201];
int n;
void Floyd()
{
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){///mao[i][j]��map[j][i]���߶���Ҫ����
                map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
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
                map[i][j]=((i==j)?0:INF);//ע�⵽����ľ���Ϊ0;
            }
        }
        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(map[u][v]>w) ///���map[u][v]��ǰֵ���������ֵ��ʱ�Ÿ��£���Ϊ����һ�����رߵ�˫��ͼģ��
                map[u][v]=map[v][u]=w;
        }
        int s,t;
        scanf("%d%d",&s,&t);
        Floyd();
        if(map[s][t]==INF){
            cout<<-1<<endl;
        }else{
            cout<<map[s][t]<<endl;
        }
    }
    return 0;
}


