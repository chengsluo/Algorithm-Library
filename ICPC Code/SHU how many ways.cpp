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

int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        if(n<=4){
            printf("1\n");
        }
        else{
            printf("%d\n",(n-1)/2);
        }
    }
    return 0;
}
