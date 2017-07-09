#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=1010;
const double INF=1000000;
typedef long long ll;
using namespace std;
int num[MAX];
bool cmp(int a,int b){
return a<b;
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2){
        for(int i=0;i<n;i++){
            scanf("%d",num+i);
        }
        sort(num,num+n,cmp);
        double ans=INF;
        for(int i=0;i<=n-k;i++){
            double sum=0;
            for(int j=i;j<i+k;j++){
                sum+=num[j];
            }
            double avg=sum*1.0/k;
            double ct=0;
            for(int j=i;j<i+k;j++){
                ct+=(num[j]-avg)*(num[j]-avg);
            }
            ans=min(ans,ct/k);
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
