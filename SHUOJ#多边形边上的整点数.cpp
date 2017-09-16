#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const int M=1000;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int n,ct=1;
    int x[M],y[M];
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            scanf("%d%d",x+i,y+i);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=gcd(fabs(x[i]-x[i-1]),fabs(y[i]-y[i-1]));
        }
        ans+=gcd(fabs(x[0]-x[n-1]),fabs(y[0]-y[n-1]));
        printf("Case %d:%d\n",ct++,ans);
    }
    return 0;
}