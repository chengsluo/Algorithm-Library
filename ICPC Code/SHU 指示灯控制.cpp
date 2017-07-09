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

bool num[1010];
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2){
        for(int i=1;i<=m;i++){
            num[i]=0;
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<=m;j+=i){
                if(num[j]) num[j]=0;
                else num[j]=1;
            }
        }
        int ct=0;
        for(int i=1;i<=m;i++){
            if(num[i]==0) ct++;
        }
        printf("%d\n",ct);
    }
    return 0;
}

