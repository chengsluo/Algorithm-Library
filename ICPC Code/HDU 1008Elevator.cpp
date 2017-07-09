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
    int n;
    int curl,ans;
    while(cin>>n&&n){
        int temp=0;
        curl=0;ans=0;
        while(n--){
            scanf("%d",&temp);
            if(temp<curl){
                ans+=(curl-temp)*4+5;//注意看题，当前层也要耗时！
                curl=temp;
            }
            else if(temp>curl){
                ans+=(temp-curl)*6+5;//注意看题，当前层也要耗时！
                curl=temp;
            }
            else{
                ans+=5;//注意看题，当前层也要耗时！
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
