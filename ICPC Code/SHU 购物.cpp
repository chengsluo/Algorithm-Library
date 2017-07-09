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

int main()
{
    int t;
    ll a,b,m0,m;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld",&a,&b,&m0);
        m=m0;
        while(m%a!=0&&m>0){
            m-=b;
        }
        if(m%a==0){
            printf("%lld %lld\n",m/a,(m0-m)/b);
        }
        else{
            printf("Impossible\n");
        }
    }
    return 0;
}
