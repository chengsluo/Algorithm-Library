#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=110;
typedef long long ll;
using namespace std;

int num[MAX];
int main()
{
    int n;
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            scanf("%d",num+i);
        }
        sort(num,num+n);
        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",num[i]);
        }
        printf("\n");
    }
    return 0;
}
