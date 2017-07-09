#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct node{
    int v,id;
}num[11];

int n;
bool mp[11][11];

bool cmp(node a,node b)
{
    return a.v>b.v;
}
bool havel()
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=num[i].v;
    if(sum&1) return 0;
    int ct=0;
    int flag=2;
    for(int i=0;i<n;i++){
        sort(num+ct,num+n,cmp);
        if(num[ct].v==0){
            flag=0;break;
        }
        if(ct+num[ct].v+1>n){
            flag=1;break;
        }
        for(int j=ct+1;j<ct+1+num[ct].v&&j<n;j++){
            if(--num[j].v<0){
                flag=1;break;
            }
            mp[num[ct].id][num[j].id]=mp[num[j].id][num[ct].id]=1;///当前点与其他点建立了联系
        }
        ct++;
        if(flag==1) break;
    }
    if(flag==1) return 0;
    else return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<11;i++)
            num[i].id=i;
        memset(mp,0,sizeof(mp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i].v);
        if(havel()){
            printf("YES\n");
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    printf("%d%c",mp[i][j],j==n-1?'\n':' ');///奇妙的换行方式
        }
        else printf("NO\n");
        printf("\n");///空行
    }
    return 0;
}
