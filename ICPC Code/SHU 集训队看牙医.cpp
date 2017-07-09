#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>

typedef long long ll;
using namespace std;
int ans[4010];
ll num[4010][4];
int main()
{

    int n,ct,k;
    while(scanf("%d",&n)==1){
        ct=0;
        for(int i=0;i<n;i++){
            scanf("%lld%lld%lld",&num[i][0],&num[i][1],&num[i][2]);
            num[i][3]=0;
        }
        for(int i=0;i<n;i++){
            if(num[i][3]==0){
                ans[ct++]=i;
                ll p=num[i][0];
                ll q=0;
                for(int j=i+1;j<n;j++){
                    if(num[j][3]==0){
                         num[j][2]-=p;
                         num[j][2]-=q;
                         if(num[j][2]<0){
                            num[j][3]=1;
                            q+=num[j][1];
                        }
                        if(p!=0) p--;
                    }
                }
//                                            for(int k=0;k<n;k++)
//                    cout<<num[k][2]<<" ";
//               cout<<endl;
            }

        }
        printf("%d\n",ct);
        for(int i=0;i<ct;i++){
            printf("%d%c",ans[i]+1,i==ct-1?'\n':' ');
        }
    }
    return 0;
}
