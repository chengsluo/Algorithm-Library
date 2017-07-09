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
int dir[M];
char tag[M];///��ʼ�洢
int num[280];///num[i]=j�������ascii��Ϊi�ı����j
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
                            for(int j=0;j<G[i].size();j++){///�ȼ�
                                   int to=G[i][j];
                                   deg[to]--;
                            }
                            ans[t]=tag[i];///��ʼ�洢������ĵ�i����Ҳ��num[tag[i]]=i;
                            ///����ʱ��Ӧ��д��ans[t]=i;���ڱ�����,i��tag[i]������ӳ���ϵ

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
                                   num[tag[i]]=i;///��Ϊi�ǲ��ظ�����ĸ������Ҳ���Խ��仯Ϊ��������,
                                   ///��ĳ����ĸ����������ֵ������ԭʼ�Ĵ洢������ı����ͬ
                                   ///����num�и�����ĸ���ŵ�ֵ���Ϊ������ţ�������һ���洢���䳤���飻
                            }
                            while(scanf("%c%c%c%c",&a,&b,&c,&d)==4){///����͸���ͨ�ķ�ʽ����һģһ���ˣ�
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
