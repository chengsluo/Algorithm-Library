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
    long long x,n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&x,&n);
        if(x==1){
            if(n%2){
                cout<<2<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        else if(x==2){
            if(n%2){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
        else{
            if(n==0) cout<<3<<endl;
            else if(n%2) cout<<2<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}
