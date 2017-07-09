#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct even{
    int s,e;
}num[110];
bool cmp(even a,even b){
    return a.e<b.e;
}
int main()
{
    int t;
    while(scanf("%d",&t)==1&&t){
        for(int i=0;i<t;i++){
            scanf("%d%d",&num[i].s,&num[i].e);
        }
        sort(num,num+t,cmp);
        int ct=0,temp=0;
        for(int i=0;i<t;i++){
            if(num[i].s>=temp){
                ct++;temp=num[i].e;
            }
        }
        printf("%d\n",ct);
    }
    return 0;
}
