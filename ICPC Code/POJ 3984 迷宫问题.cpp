#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int M=5;
bool G[M][M];
int  vis[M][M];
int dir[M*M][2];
int v[4][2]={1,0,0,1,-1,0,0,-1};

void output(int x,int y)
{
       int k=0;
       while(vis[x][y]!=-2){
             // cout<<vis[x][y]<<endl;
              dir[k][0]=x;
              dir[k][1]=y;
              int t=vis[x][y];
              x=t/M;y=t%M;
              k++;
       }

       cout<<"("<<0<<", "<<0<<")\n";
       for(int i=k-1;i>=0;i--){
              cout<<"("<<dir[i][0]<<", "<<dir[i][1]<<")\n";
       }
}
bool dfs()
{
       for(int i=0;i<M;i++){///此处用0表示未访问与其前驱的功能相矛盾
              for(int j=0;j<M;j++){
                     vis[i][j]=-1;
              }
       }
       queue<int> qu;
       if(G[0][0]==0) qu.push(0);
       vis[0][0]=-2;///特殊访问标记
       while(!qu.empty()){
              int t=qu.front();qu.pop();
              int x=t/M;
              int y=t%M;
              if(x==M-1&&y==M-1){
                     output(x,y);
                     return 1;
              }
              for(int i=0;i<4;i++){
                     int tx=x+v[i][0];
                     int ty=y+v[i][1];
                     if(!(tx<0||tx>M-1||ty<0||ty>M-1)&&vis[tx][ty]==-1&&G[tx][ty]==0){
                            qu.push(tx*M+ty);vis[tx][ty]=t;
                            //cout<<"vis"<<tx<<ty<<"t"<<t<<endl;
                     }
              }
       }
       return 0;
}

int main()
{
       for(int i=0;i<M;i++){
              for(int j=0;j<M;j++){
                     scanf("%d",&G[i][j]);
              }
       }
       dfs();
       return 0;
}
