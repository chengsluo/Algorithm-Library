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

int num[1010];
int main()
{
    int n,i,j,ct,temp;
    while(scanf("%d",&n)==1){
            scanf("%d",&temp);
            num[0]=temp;
            ct=1;
            for(int i=1;i<n;i++){
                scanf("%d",&temp);
                for(j=0;j<ct;j++){
                    if(temp<=num[j]) {
                        num[j]=temp;
                        //cout<<temp;
                        break;
                    }
                }
                if(j>=ct){
                    num[j]=temp;
                    ct++;
                }
            }
            printf("%d\n",ct);
    }
    return 0;
}
