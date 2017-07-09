#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;

int G[510][510];
int m,n;
int dir[510];
int deg[510];///每个点的入度
bool toposort()
{
       int k=0;
       queue<int>qu;
       ///如何找矩阵中第一个点
       for(int i=1;i<=n;i++){
              deg[i]=0;
              for(int j=1;j<=n;j++){
                     if(G[j][i]) deg[i]++;
              }
              if(deg[i]==0) qu.push(i);
       }
       while(!qu.empty()){
              int v=qu.front();qu.pop();
              dir[k++]=v;
              for(int i=1;i<=n;i++){
                     if(G[v][i]){
                            deg[i]--;
                             if(deg[i]==0) qu.push(i);
                     }
              }
       }
       if(k<n) return false;
       return true;
}

int main()
{
       int t1,t2;
       while(scanf("%d%d",&n,&m)==2){
              if(n==0&&m==0) break;
              memset(G,0,sizeof(G));
              for(int i=0;i<m;i++){
                     scanf("%d%d",&t1,&t2);
                     G[t1][t2]=1;
              }
              toposort();
              for(int i=0;i<n;i++){
                     printf("%d%c",dir[i],i==n-1?'\n':' ');
              }
       }
       return 0;
}
