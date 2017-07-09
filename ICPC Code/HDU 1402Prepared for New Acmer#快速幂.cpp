#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
ll  power(ll a,ll n,ll mod)
{
        ll ans=1;///
        while(n){
            if(n&1) {ans*=a;ans%=mod;}///
            a*=a;
            a%=mod;
            n>>=1;
        }
        return ans;
}

int main()
{
    ll t,a,b,c;///要用ll,因为1000 000*1000 000会超int
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",power(a,b,c));
    }
    return 0;
}
