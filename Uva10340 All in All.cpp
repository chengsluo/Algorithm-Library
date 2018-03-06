#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
using namespace std;
#define maxn 100005
char s[maxn],t[maxn];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while(scanf("%s%s",s,t)!=EOF){
        int lens=strlen(s);
        int lent=strlen(t);
        int j=0;
        int i=0;
        for(;i<lens&&j<lent;){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i==lens){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

#ifdef LOCAL
    printf("Time used=%.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}