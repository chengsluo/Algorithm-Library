#include<iostream>
#include<cstdio>
using namespace std;

const int M=1010;
bool G[M][M];
bool vis[M][M];
int n=5,m=5;
int mct;
int v[4][2]={0,1,1,0,-1,0,0,-1};
int dir[25][2];

bool find_way(int i,int j,int t)///求最短长度时，多用一个参数记录访问次数
{
       if(i<0||j<0) return 0;
       if(i>n-1||j>m-1) return 0;
       if(G[i][j]) return 0;
       vis[i][j]=1;
       if(i==n-1&&j==m-1){
              vis[i][j]=0;
              if(t<mct){
                     mct=t;
                    // cout<<mct<<endl;
                     return 1;
              }
              return 0;
       }
       bool key=0;
       for(int k=0;k<4;k++){
              int x=i+v[k][0];
              int y=j+v[k][1];
              if(!vis[x][y]&&find_way(x,y,t+1)){
                     key=1;
                     dir[t+1][0]=x;
                     dir[t+1][1]=y;
              }
       }
       vis[i][j]=0;
       if(key) return 1;
       else return 0;
}
int main()
{
       int t;
       scanf("%d",&t);
       for(int a=1;a<=t;a++){
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++)
                            scanf("%d",&G[i][j]);
              }
              mct=30;
              find_way(0,0,0);
              cout<<"Case "<<a<<":"<<endl;
              for(int i=mct-1;i>=0;i--){
                     cout<<"("<<dir[i][0]<<","<<dir[i][1]<<")"<<endl;
              }
       }
}

