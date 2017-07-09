#include<iostream>
#include<cstdio>
using namespace std;

const int M=1010;
bool G[M][M];
int n,m;
int ct,max_room_size,temp;
int v[4][2]={0,1,1,0,-1,0,0,-1};

void dfs(int i,int j)
{
       if(i<0||j<0) return;
       if(i>n-1||j>m-1) return;
       if(G[i][j]) return;
       else{
              G[i][j]=1;
              temp++;
              for(int k=0;k<4;k++){
                     dfs(i+v[k][0],j+v[k][1]);
              }
       }
}

void find_room()
{
       for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                     if(G[i][j]==0){
                            temp=0;
                            dfs(i,j);
                            max_room_size=max(max_room_size,temp);
                            ct++;
                     }
              }
       }
}
int main()
{
       while(scanf("%d%d",&n,&m)==2){
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++)
                            scanf("%d",&G[i][j]);
              }
              ct=0;max_room_size=0;
              find_room();
              cout<<ct<<" "<<max_room_size<<endl;
       }
}

