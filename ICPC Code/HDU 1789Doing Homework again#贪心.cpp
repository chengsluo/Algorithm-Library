#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct node{
    int d,r;
}num[1010];

bool pos[1010];
bool cmp(node a,node b)
{
    return a.r>b.r;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i].d);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i].r);///ÿ��ѡ��ʱ����������а��ţ����Ҿ����ܵİ��������������ǰ����Ŀ�λ�á�
        sort(num,num+n,cmp);
        memset(pos,0,sizeof(pos));
        int ans=0;
        for(int i=0;i<n;i++){
            int j;
            for(j=num[i].d;j>=1;j--){
                if(pos[j]==0){
                    pos[j]=1;break;
                }
            }
            if(j<1){
                ans+=num[i].r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
