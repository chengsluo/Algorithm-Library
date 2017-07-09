#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int M=30;
vector<int>G[M];///G[i][j]��ʾ���Ϊi�Ľڵ�ģ���j������ָ��Ľڵ���
int deg[M];
int vis[M];
int ans[M];
int n;
void dfs(int t)
{
       if(t==n){
              for(int i=0;i<n;i++)
                     cout<<ans[i]+1<<" ";
              cout<<endl;
              return ;
       }
       for(int i=0;i<n;i++){
                     if(!vis[i]&&deg[i]==0){
                            for(int j=0;j<G[i].size();j++){///�ȼ�
                                   int to=G[i][j];
                                   deg[to]--;
                            }
                            ans[t]=i;
                            vis[i]=1;///��Ϊ�ѷ���
                            dfs(t+1);
                            vis[i]=0;
                            for(int j=0;j<G[i].size();j++){///���
                                   int to=G[i][j];
                                   deg[to]++;
                            }
                     }
       }
}
int main()
{
       int m;
       cin>>n>>m;
       memset(deg,0,sizeof(deg));
       memset(G,0,sizeof(G));
       memset(vis,0,sizeof(vis));
       for(int i=0;i<m;i++){
              int t1,t2;
              scanf("%d%d",&t1,&t2);
              t1--;t2--;
              G[t1].push_back(t2);
              deg[t2]++;
       }
       dfs(0);
       return 0;
}

//���ϲ�������֮һ��
//6 9
//
//2 1
//2 5
//5 1
//1 4
//1 3
//3 4
//6 3
//6 4
//6 5
