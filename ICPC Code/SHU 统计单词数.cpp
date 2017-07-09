#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=66000;
typedef long long ll;
using namespace std;

char str[MAX];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        int ans=0;
        gets(str);
        for(int i=0;str[i]!='\0';i++){
            if(str[i]!=' '&&(str[i+1]==' '||str[i+1]=='\0')) ans++;
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
