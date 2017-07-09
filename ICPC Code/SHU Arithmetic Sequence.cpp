#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[5005];
int dp[5005][5005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)
            scanf("%d",a+i);
        memset(dp,0,sizeof(dp));
        sort(a,a+n);
        int ans=0;
        int i,j,k;
        for(i=1; i<n-1; i++)
        {
            j=i-1;
            k=i+1;
            while(j>=0 && k<n)
            {
                if(a[j]+a[k]>2*a[i])
                {
                    j--;
                }
                else if(a[j]+a[k]<2*a[i])
                {
                    k++;
                }
                else
                {
                    dp[i][k]=(dp[j][i]==0)?3:max(dp[j][i]+1,dp[i][k]+1);
                    if(dp[i][k]>ans){
                        ans=dp[i][k];
                    }
                    j--;
                    k++;
                }
            }
        }
        if(ans!=0)
              printf("%d\n",ans);
        else if(n==1){
              printf("%d\n",n);
        }
        else{
              printf("2\n");
        }
    }
    return 0;
}
