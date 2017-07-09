#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=10010;
typedef long long ll;
using namespace std;

int num[25];
int main()
{
    int n;
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        int ans=0;
        int s=0,e=n-1;
        while(e-s>=3){
                ans+=min(num[s+1]+num[s]+num[e]+num[s+1],num[e]+num[s]+num[e-1]+num[s]);
                e-=2;
              // cout<<ans<<endl;
        }

        if(e-s==2)
            ans+=min(num[s+1]+num[s]+num[s+2],num[s+2]+num[s+1]+num[s+1]);
        if(e-s==1)
            ans+=num[s+1];
        printf("%d\n",ans);
    }
    return 0;
}

