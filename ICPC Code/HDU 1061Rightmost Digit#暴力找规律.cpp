#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


int main()
{
    int t;
    int num[20]={1,4,7,6,5,6,3,6,9,0,1,6,3,6,5,6,7,4,9,0};
    scanf("%d",&t);
    while(t--){
//        for(int i=2;i<100;i++){
//            long long  ans=i;
//            for(int j=1;j<i;j++)
//                {ans*=i;ans%=10;}
//            cout<<ans;
//        }
        int n;
        scanf("%d",&n);
        printf("%d\n",num[(n-1)%20]);
    }
    return 0;
}
