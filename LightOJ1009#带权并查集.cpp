#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define maxn 20010

int num[maxn],father[maxn*2];
bool used[maxn],vis[maxn*2];
void init_set()
{
    for(int i=0;i<maxn*2;i++){//因为是以前一个为father,所以这里maxn*2
        father[i]=i;
    }
}
int find_set(int a)
{
    if(father[a]!=a){
         father[a]=find_set(father[a]);
    }
    return father[a];
}
void union_set(int a,int b)
{
    int x=find_set(a),y=find_set(b);
    if(x!=y){
        father[y]=x;
    }
}
int main()
{
    int t,n,u,v;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        memset(used,0,sizeof(used));
        memset(num,0,sizeof(num));
        memset(vis,0,sizeof(vis));
        init_set();
        for(int j=0;j<n;j++){
            scanf("%d%d",&u,&v);
            used[u]=used[v]=true;
            union_set(u,v+maxn);
            union_set(v,u+maxn);
        }       
        for(int j=0;j<maxn;j++){
            if(used[j]){
                int root=find_set(j);
                num[root]++;
            }
            //这里只需要0-maxn中的数目相加的原因是:
            //若某个数出现过，就将这个数所在集合中的元素个数加1。
        }
        int x,y,ans=0;
        for(int j=0;j<maxn;j++){
            if(used[j]){
                x=find_set(j);
                y=find_set(j+maxn);
                //探寻某两个相斥集合中的元素的个数大小.选择大的加入最后结果。
                //因为这个集合的个数已经加过，所以不能再加。
                //另一个集合与之相斥，也不能再加。
                //if(vis[x]||vis[y]) continue;
                //上一行代码可以写成如下：因为vis[x]==vis[y]衡成立
                if(vis[x]) continue;
                ans+=max(num[x],num[y]);
                vis[x]=vis[y]=true;
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}