#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int num[1010];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",num+i);
        sort(num,num+n);
        for(int i=0;i<n;i++)
            printf("%d%c",num[i],i==n-1?'\n':' ');
    }
    return 0;
}
