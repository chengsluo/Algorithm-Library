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
    ll a,b,n;
    ll t1,t2,t3;
    while(scanf("%lld%lld%lld",&a,&b,&n)==3&&n!=0){
        //具有循环性质的,一定要记得找规律
        t1=t2=1;int temp=0;
        /*while(++temp){
            t3=(a*t2+b*t1)%7;//注意看题目的表示，不想想当然的认为
            t1=t2;
            t2=t3;
            if(t1==t2&&t1==1) break;
            //cout<<t1<<endl;
        }*/
        n=n%49;n--;//temp<=49?这个原理很简单
        // 因为这是一个递归，结果%7之后余数只有0,1,2,3,4,5,6七种情况，
        //由于后一项是由前两项推出来的所以最终的结果最多只有7*7=49中可能
        //用矩阵快速幂也可以做出来的！但我还不会
        while(n--){
            t3=(a*t2+b*t1)%7;
            t1=t2;
            t2=t3;
        }
        cout<<t1<<endl;
    }
    return 0;
}
