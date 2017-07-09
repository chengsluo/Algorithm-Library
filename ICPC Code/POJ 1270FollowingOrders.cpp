#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int M=30;
vector<int>G[M];///G[i][j]表示编号为i的节点的，第j个出边指向的节点编号
int deg[M];
int dir[M];
char tag[M];///初始存储
int num[280];///num[i]=j代表的是ascii码为i的编号是j
int vis[M];
char ans[M];
int n;
void dfs(int t)
{
       if(t==n){
              ans[n]='\0';
              puts(ans);
              return ;
       }
       for(int i=0;i<n;i++){
                     if(!vis[i]&&deg[i]==0){
                            for(int j=0;j<G[i].size();j++){///先减
                                   int to=G[i][j];
                                   deg[to]--;
                            }
                            ans[t]=tag[i];///初始存储数组里的第i个，也是num[tag[i]]=i;
                            ///正常时，应该写成ans[t]=i;但在本题中,i与tag[i]建立了映射关系

                            vis[i]=1;///置为已访问
                            dfs(t+1);
                            vis[i]=0;
                            for(int j=0;j<G[i].size();j++){///后加
                                   int to=G[i][j];
                                   deg[to]++;
                            }
                     }
       }
}
int main()
{
       char a,b,c,d;
       bool key=0;
       while(scanf("%c%c",&a,&b)==2){
                     tag[n++]=a;
                     if(b=='\n'){
                            memset(deg,0,sizeof(deg));
                            memset(G,0,sizeof(G));
                            memset(vis,0,sizeof(vis));
                            sort(tag,tag+n);
                            for(int i=0;i<n;i++){
                                   num[tag[i]]=i;///因为i是不重复的字母，所以也可以将其化为数组索引,
                                   ///且某个字母的索引数组值与其在原始的存储数组里的编号相同
                                   ///即把num中各个字母序编号的值标记为它的序号，方便下一步存储进变长数组；
                            }
                            while(scanf("%c%c%c%c",&a,&b,&c,&d)==4){///下面就跟普通的方式几乎一模一样了！
                                   G[num[a]].push_back(num[c]);
                                   deg[num[c]]++;
                                   if(d=='\n') break;
                            }
                            if(key)    cout<<endl;
                            dfs(0);
                            n=0;
                            key=1;
                     }
       }
       return 0;
}
