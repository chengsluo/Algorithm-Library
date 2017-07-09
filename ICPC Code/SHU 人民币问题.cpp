#include<iostream>
using namespace std;

int main()
{
    int dp[100];
    dp[8]=1;
    dp[9]=1;
    for(int i=10;i<100;i++){
        dp[i]=dp[i-1]+(i%2);
        if(i%5==0) dp[i]++;
    }
    cout<<dp[50];
    return 0;
}
