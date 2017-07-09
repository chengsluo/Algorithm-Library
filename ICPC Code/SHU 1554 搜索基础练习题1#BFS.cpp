#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

const int M=101;
bool G[M][M];
bool vis[M][M];
int m,n;
int v[4][2]={0,1,1,0,-1,0,0,-1};
///对于二维数组来说,其坐标可以保存为一个数
bool BFS_2()
{
       memset(vis,0,sizeof(0));
       queue<int> qu;
       qu.push(0);
       while(!qu.empty()){
              int pa=qu.front();qu.pop();
              int x=pa/m;
              int y=pa%m;
              if(x<0||y<0||x>n-1||y>m-1) continue;
              if(G[x][y]) continue;
              if(x==n-1&&y==m-1) return 1;
              if(vis[x][y]) continue;
              else vis[x][y]=1;
              for(int i=0;i<4;i++){
                     qu.push((x+v[i][0])*m+y+v[i][1]);
              }
       }
       return 0;

}
bool BFS()
{
       memset(vis,0,sizeof(0));
       queue<pair<int,int> > qu;
       qu.push(make_pair(0,0));
       while(!qu.empty()){
              pair<int,int> pa=qu.front();qu.pop();
              int x=pa.first;int y=pa.second;
              if(x<0||y<0||x>n-1||y>m-1) continue;
              if(G[x][y]) continue;
              if(x==n-1&&y==m-1) return 1;
              if(vis[x][y]) continue;
              else vis[x][y]=1;
              for(int i=0;i<4;i++){
                     qu.push(make_pair(x+v[i][0],y+v[i][1]));
              }
       }
       return 0;
}

int main()
{
       while(scanf("%d%d",&n,&m)==2){
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            scanf("%d",&G[i][j]);
                     }
              }
              if(BFS()) cout<<"Y"<<endl;
              else cout<<"N"<<endl;
       }
       return 0;
}
