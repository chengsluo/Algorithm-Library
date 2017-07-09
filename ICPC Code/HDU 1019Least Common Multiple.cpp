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
int num[MAX];

int GCD(int a,int b)
{
    return b==0?a:GCD(b,a%b);//辗转相除法，必须牢记，前提是a>b
}
int  LCM(int a,int b)
{
    return (ll)a*b/GCD(a,b);//必须得注意，虽然结果可能不会超过int，但是中间变量可能会超
}

int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",num+i);
        for(int i=n-1;i>=1;i--){
            if(num[i]>=num[i-1])
            num[i-1]=LCM(num[i],num[i-1]);
            else
            num[i-1]=LCM(num[i-1],num[i]);
        }
        cout<<num[0]<<endl;
    }
    return 0;
}
