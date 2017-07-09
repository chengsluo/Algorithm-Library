#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int M=10010;
vector<int>G[M];
int deg[M];
int m,n;
int ans[M];

bool toposort()
{
       int k=0;
       queue<int>qu;
       for(int i=0;i<n;i++){
              if(deg[i]==0) {
                     ans[i]=888;
                     qu.push(i);
              }
       }
       while(!qu.empty()){
              k++;
              int v=qu.front();qu.pop();
              for(int i=0;i<G[v].size();i++){
                     int temp=G[v][i];
                     deg[temp]--;
                     if(deg[temp]==0){
                            qu.push(temp);///注意加入和更新的都应是temp
                            ans[temp]=ans[v]+1;
                     }
              }
       }
       if(k<n) return false;
       else return true;
}
int main()
{
       while(scanf("%d%d",&n,&m)==2){
                     memset(G,0,sizeof(G));
                     memset(deg,0,sizeof(deg));
                     memset(ans,0,sizeof(ans));
                     int t1,t2;
                     while(m--){
                            scanf("%d%d",&t1,&t2);
                            t2--;t1--;
                            G[t2].push_back(t1);///注意题目要求顺序
                            deg[t1]++;
                     }
                     if(toposort()){
                            int sum=0;
                           for(int i=0;i<n;i++)
                                   sum+=ans[i];
                           printf("%d\n",sum);
                     }
                     else{
                            printf("-1\n");
                     }
       }
       return 0;
}


//
/////本题中不能用邻接矩阵存储，空间可能会超，要用邻接表
//const int M=10010;
//int n,m;
//bool G[M][M];
//int deg[M];
//int a[M];
//bool toposort()
//{
//       int k=0;
//       queue<int> qu;
//       for(int i=0;i<n;i++){
//              deg[i]=0;
//              for(int j=0;j<n;j++){
//                     if(G[j][i]) deg[i]++;///注意是入度，所以是j,i;
//              }
//              if(deg[i]==0) { a[i]=888;qu.push(i);}
//       }
//       while(!qu.empty()){
//              int v=qu.front();qu.pop();
//              for(int i=0;i<n;i++){
//                     if(G[v][i]){
//                            deg[i]--;
//                            if(deg[i]==0) {a[i]=a[v]+1;qu.push(i);}
//                     }
//              }
//              k++;
//       }
//       if(k<n) return false;
//       else return true;
//}
//int main()
//{
//       while(scanf("%d%d",&n,&m)==2){
//                     memset(G,0,sizeof(0));
//                     int t1,t2;
//                     while(m--){
//                            scanf("%d%d",&t1,&t2);
//                            t1--;t2--;
//                            G[t2][t1]=1;
//                     }
//                     if(toposort()){
//                            int ans=0;
//                            for(int i=0;i<n;i++)
//                                   ans+=a[i];
//                            printf("%d\n",ans);
//                     }
//                     else{
//                            printf("-1\n");
//                     }
//       }
//       return 0;
//}
