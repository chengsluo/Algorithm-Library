#include<iostream>
#include<cstdio>
using namespace std;

const int M=1010;
bool G[M][M];
int n,m;

bool find_way(int i,int j)
{
       if(i>n-1||j>m-1) return 0;
       if(G[i][j]) return 0;
       if(i==n-1&&j==m-1) return 1;
       if(find_way(i+1,j)||find_way(i,j+1)){
              return 1;
       }
}
int main()
{
       while(scanf("%d%d",&n,&m)){
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++)
                            scanf("%d",&G[i][j]);
              }
              if(find_way(0,0)){
                     cout<<"Y"<<endl;
              }
              else{
                     cout<<"N"<<endl;
              }
       }
}
