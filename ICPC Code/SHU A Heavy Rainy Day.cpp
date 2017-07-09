#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>

typedef long long ll;
using namespace std;

int num[1010];
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        int ans=0;
        int s=0,e=n-1;
        while(e-s>=3){
                ans+=min(num[s+1]+num[s]+num[e]+num[s+1],num[e]+num[s]+num[e-1]+num[s]);
                e-=2;
        }
        if(e-s==2)
            ans+=min(num[s+1]+num[s]+num[s+2],num[s+2]+num[s+1]+num[s+1]);
        if(e-s==1)
            ans+=num[s+1];
        if(e-s==0) ans+=num[0];
        printf("%d\n",ans);
    }
    return 0;
}


