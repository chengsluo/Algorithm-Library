#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct node{
    int w,p;
}num[1010];

bool cmp(node a,node b)
{
    return a.p<b.p;
}
int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&num[i].p,&num[i].w);
        }
        sort(num,num+n,cmp);
        double ans=0,cost=0;
        int i;
        for(i=0;i<n&&cost+num[i].w*num[i].p<=m;i++){
            cost+=num[i].p*num[i].w;
            ans+=num[i].w;
        }
        if(i<n&&cost<m){
            ans=ans+(m-cost)/num[i].p;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
