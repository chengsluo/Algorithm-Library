#include<iostream>
#include<cstdio>
using namespace std;

const int M=101;
int n,m;
bool G[M][M];
int v[8][2]={1,0,0,1,-1,0,0,-1,1,-1,-1,1,1,1,-1,-1};

void dfs(int i,int j)
{
       if(i<0||j<0||i>n-1||j>m-1) return;
       if(G[i][j]){
              G[i][j]=0;
              for(int k=0;k<8;k++){
                     dfs(i+v[k][0],j+v[k][1]);
              }
       }
       return;
}
int main()
{
       while(scanf("%d%d",&n,&m)==2){
              getchar();
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            if(getchar()=='W'){
                                   G[i][j]=1;
                            }
                            else{
                                   G[i][j]=0;
                            }
                     }
                     getchar();
              }
//              for(int i=0;i<n;i++){
//                     for(int j=0;j<m;j++){
//                                   cout<<G[i][j];
//                     }
//                     cout<<endl;
//              }
              int ct=0;
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            if(G[i][j]){
                                   dfs(i,j);
                                   ct++;
                            }
                     }
              }
              printf("%d\n",ct);
       }
       return 0;
}
