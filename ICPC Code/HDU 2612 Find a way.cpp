#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define MP meke_pair ;

const int M=210;
const int INF=0x3FFFFFFF;
int n,m;
int G[M][M];///本题中不适合用回溯求解，因为要求遍历所有路径
int dis[2][M][M];///用数组保持，可以减少队列 的堆栈使用
int a,b,c,d;
int ans[M][M];
bool vis[M][M];


int v[4][2]={0,-1,-1,0,1,0,0,1};
void BFS(bool key)
{
       memset(vis,0,sizeof(vis));
       queue<int> qu;
       if(key){
               vis[c][d]=1;
              qu.push(c*m+d);
              dis[key][c][d]=0;
       }
       else{
               vis[a][b]=1;
              qu.push(a*m+b);
              dis[key][a][b]=0;
       }
       while(!qu.empty()){
              int p=qu.front();qu.pop();
              int x=p/m;
              int y=p%m;
              for(int i=0;i<4;i++){
                     int tx=x+v[i][0];
                     int ty=y+v[i][1];
                     if(!(tx<0||ty<0||tx>n-1||ty>m-1)&&G[tx][ty]!=1&&!vis[tx][ty]){
                                   vis[tx][ty]=1;
                                   dis[key][tx][ty]=dis[key][x][y]+1;
                                   qu.push(tx*m+ty);
                     }
              }
       }
}
int main()
{
       char ch;
       while(scanf("%d%d",&n,&m)==2){
              int k=0;
              getchar();
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            dis[0][i][j]=dis[1][i][j]=INF;
                            ch=getchar();
                            if(ch=='.') G[i][j]=0;
                            else if(ch=='#') G[i][j]=1;
                            else if(ch=='@'){
                                          G[i][j]=2;
                            }
                            else if(ch=='Y'){
                                   a=i;b=j;
                                   G[i][j]=0;
                            }
                            else if(ch=='M'){
                                   c=i;d=j;
                                   G[i][j]=0;
                            }
                     }
                     getchar();
              }
//              for(int i=0;i<n;i++){
//                     for(int j=0;j<m;j++){
//                            cout<<G[i][j];
//                     }
//                     cout<<endl;
//              }
              BFS(0);
              BFS(1);
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            ans[i][j]=dis[0][i][j]+dis[1][i][j];
                     }
              }
//              for(int i=0;i<n;i++){
//                     for(int j=0;j<m;j++){
//                            cout<<dis[0][i][j]<<" ";
//                     }
//                     cout<<endl;
//              }
//              cout<<endl;
//              for(int i=0;i<n;i++){
//                     for(int j=0;j<m;j++){
//                            cout<<dis[1][i][j]<<" ";
//                     }
//                     cout<<endl;
//              }
              int o=INF;
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            if(G[i][j]==2){
                                   o=min(o,ans[i][j]);
                            }
                     }
              }
              cout<<o*11<<endl;
       }
       return 0;
}
