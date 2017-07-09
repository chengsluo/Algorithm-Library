#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int power(int a, int n){//快速幂的非递归实现
    int ans;
    if(n==0) ans=1;
    else
    {  ans=power(a*a, n/2);
       if(n%2==1) ans*=a;
     }
     return ans;
}
int powerf(int a,int n){//非递归实现
    int ans=1;
    while(n){
        if(n&1) ans*=a;//n%2==1;
        a*=a;
        n=n/2;//n>>=1;
    }
    return ans;
}

int pow(int a,int n){
    //cout<<a<<" "<<n<<endl;
    int ans=1;
    while(n){
        if(n%2) {ans*=a;ans=ans%1000;}//!!!!注意此处一定小心
        a*=a;//!!!!注意此处一定小心
        a%=1000;
        n=n/2;
    }
    return ans;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2&&(m!=0||n!=0)){
        printf("%d\n",pow(m,n));
    }
    return 0;
}
