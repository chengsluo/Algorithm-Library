#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


int main()
{
    int t,n,ma,tmp;
    long long sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d",&ma);
        sum=ma;
        for(int i=1;i<n;i++){
            scanf("%d",&tmp);
            sum+=tmp;
            if(tmp>ma) ma=tmp;
        }
        if(sum-ma>=ma-1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
