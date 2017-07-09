#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int num1[101],num2[101];
int main()
{
    int t,ans1,ans2;
    while(scanf("%d",&t)&&t){
        ans1=0;ans2=0;
        for(int i=0;i<t;i++)
            scanf("%d",num1+i);
        for(int i=0;i<t;i++)
            scanf("%d",num2+i);
        sort(num1,num1+t);
        sort(num2,num2+t);
        for(int i=0;i<t;i++){
            if(num1[i]>num2[i]){
                ans1+=2;
            }
            else if(num1[i]==num2[i]){
                ans1++;ans2++;
            }
            else ans2+=2;
        }
        printf("%d vs %d\n",ans1,ans2);
    }
    return 0;
}
