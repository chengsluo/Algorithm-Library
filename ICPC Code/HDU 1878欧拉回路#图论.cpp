#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int M=1010;
bool G[M][M];
int deg[M];
int vis[M];
int n,m;
dfs(int i)
{

}
int main()
{
       while(scanf("%d%d",&n,&m)&&n!=0){
              memset(deg,0,sizeof(deg));
              memset(G,0,sizeof(G));
              for(int i=0;i<m;i++){
                     int t1,t2;
                     scanf("%d%d",&t1,&t2);
                     t1--;t2--;
                     if(t1==t2) continue;
                     if(G[t1][t2]==0) {
                                   deg[t1]++;
                                   deg[t2]++;
                     }
                     G[t1][t2]=G[t2][t1]=1;
              }
              int i;
              for(i=0;i<n;i++){
                     if(deg[i]==0||deg[i]%2){
                            break;
                     }
              }
              if(i<n){
                     printf("0\n");
              }
              else{
                     printf("1\n");
              }
       }
       return 0;
}
