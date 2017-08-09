//
// Created by chengs on 17-8-9.
//
#include <iostream>
#include <algorithm>
using namespace std;
int min(int a,int b,int c,int d)
{
    if(b<a) a=b;
    if(c<a) a=c;
    if(d<a) a=d;
    return  a;
}
int main()
{
    int n;
    string str;
    int dp[5843];
    dp[1]=1;
    int x1,x2,x3,x4;
    int dp1,dp2,dp3,dp4;
    x1=x2=x3=x4=1;
    for(int i=2;i<=5842;i++){
        dp1=dp[x1]*2;     //后面的数必定是前面的一些数乘以着四个数，
        dp2=dp[x2]*3;     // 取其中最小的一个，即为下一个丑数。
        dp3=dp[x3]*5;
        dp4=dp[x4]*7;
        dp[i]=min(dp1,dp2,dp3,dp4);
        if(dp[i]==dp1)    x1++;     //注意不用加else , 因为有些会相等
        if(dp[i]==dp2)    x2++;
        if(dp[i]==dp3)    x3++;
        if(dp[i]==dp4)    x4++;
    }
    while(cin>>n&&n){
        if(n%10==1&&n%100!=11){
            str="st humble number is ";
        }else if(n%10==2&&n%100!=12){
            str="nd humble number is ";
        }else if(n%10==3&&n%100!=13) {
            str="rd humble number is ";
        }else{
            str="th humble number is ";
        }
        cout<<"The "<<n<< str <<dp[n]<<"."<<endl;
    }
    return 0;
}
