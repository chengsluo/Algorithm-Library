#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=220;
typedef long long ll;
using namespace std;

int num[MAX];
int main()
{
    int a,b,k;
    while(scanf("%d%d%d",&a,&b,&k)==3){
        int i;
        for(i=0;i<a;i++)  scanf("%d",num+i);
        for(int j=i;j<a+b;j++) scanf("%d",num+j);
        sort(num,num+a+b);
        printf("%d\n",num[k-1]);
    }
    return 0;
}
