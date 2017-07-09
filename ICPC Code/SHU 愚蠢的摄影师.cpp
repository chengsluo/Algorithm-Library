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
int a[60];
int main()
{
    int n;
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for(int i=3;i<60;i++)
        a[i]=a[i-1]+a[i-3]+1;//找规律需要画图，需要思考
    cin>>n;
    cout<<a[n]<<endl;
    return 0;
}
/*

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
int n,ans;
int x[60];
void backtrack(int t){
    if(t==n) {
   //     for(int i=0;i<n;i++)
      //      cout<<x[i]<<" ";
        // cout<<endl;
            ans++;return;}
    int f1=1,f2=1,f3=1,f4=1;
    if(x[t-1]+1>n) f1=0;
    else
    for(int i=t-1;i>=0;i--){
        if(x[i]==x[t-1]+1) f1=0;
    }

    if(x[t-1]+2>n) f2=0;
    else
    for(int i=t-1;i>=0;i--){
        if(x[i]==x[t-1]+2) f2=0;
    }

    if(x[t-1]-1<1) f3=0;
    else
    for(int i=t-1;i>=0;i--){
        if(x[i]==x[t-1]-1) f3=0;
    }

    if(x[t-1]-2<1) f4=0;
    else
    for(int i=t-1;i>=0;i--){
        if(x[i]==x[t-1]-2) f4=0;
    }

    if(f1) {x[t]=x[t-1]+1;backtrack(t+1);}
    if(f2) {x[t]=x[t-1]+2;backtrack(t+1);}
    if(f3) {x[t]=x[t-1]-1;backtrack(t+1);}
    if(f4) {x[t]=x[t-1]-2;backtrack(t+1);}
}
int main()
{
    cin>>n;
    ans=0;
    x[0]=1;
    backtrack(1);
    cout<<ans<<endl;
    return 0;
}


*/
