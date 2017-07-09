#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int n,k,ct;
int num[20];
void prime(int a){
    if(a<=1) return;
    double sa=sqrt(a);
    int i;
    for(i=2;i<=sa;i++){
        if(a%i==0) return;
    }
    if(i>sa) ct++;

}
void next(int p,int r,int sum){
    if(r==0){
        prime(sum);
        return ;
    }
    if(n-p<r) return;
    next(p+1,r,sum);
    next(p+1,r-1,sum+num[p]);
}
int main()
{
    while(scanf("%d%d",&n,&k)==2){
        ct=0;
        for(int i=0;i<n;i++){
            scanf("%d",num+i);
        }
        next(0,k,0);
        printf("%d\n",ct);
    }
    return 0;
}
