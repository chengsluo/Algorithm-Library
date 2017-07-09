#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=1010;
typedef long long ll;
using namespace std;
struct A{
int p;
int a;
}s[MAX];

bool cmp(A s1,A s2){
    return s1.p>s2.p;
}
int main()
{
    int n,t,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
         for(int i=0;i<n;i++){
            scanf("%d%d",&(s[i].p),&(s[i].a));
        }
        sort(s,s+n,cmp);
        ll ans=0;
        for(int i=0;i<n;){
            ans+=(2*s[i].p);
            if(s[i].a>k){s[i].a=s[i].a-k;}
            else{
                int ct=0;
                while(i<n){
                   ct+=s[i].a;
                    if(ct>k){
                        s[i].a=ct-k;
                        break;
                    }
                    i++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
