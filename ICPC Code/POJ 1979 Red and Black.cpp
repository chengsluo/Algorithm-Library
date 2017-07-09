#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;

int v[4][2]={0,1,0,-1,1,0,-1,0};
char maps[22][22];
bool g[22][22];
int main()
{
       int m,n,ans;
       queue<pair<int,int> > qu;
       while(scanf("%d%d",&m,&n)==2){
               getchar();
              ans=0;
              memset(g,0,sizeof(g));
              if(n==0&&m==0) break;
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            scanf("%c",&maps[i][j]);
                            if(maps[i][j]=='@'){
                                   qu.push(make_pair(i,j));
                                   g[i][j]=1;
                                   ans++;
                            }
                     }
                     getchar();
              }
              while(!qu.empty()){
                     pair<int,int> pa=qu.front();
                     qu.pop();
                     for(int i=0;i<4;i++){
                            int x=pa.first+v[i][0];
                            int y=pa.second+v[i][1];
                            if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0&&maps[x][y]=='.'){
                                   qu.push(make_pair(x,y));
                                   g[x][y]=1;
                                   ans++;
                            }
                     }
              }
              printf("%d\n",ans);
       }
       return 0;
}
