#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int mod1=73;
const int mod2=137;
char str[10000010];
int main()
{
       int key=1;
       while(scanf("%s",str)==1){
                  int len=strlen(str);
                  int ans1=0;
                  int ans2=0;
                  for(int i=0;i<len;++i)
                  {
                      ans1=((ans1*10+str[i]-'0') % mod1);
                      ans2=((ans2*10+str[i]-'0') % mod2);
                  }
                  if(ans1==0&&ans2==0){
                     printf("Case #%d: YES\n",key++);
                  }else{
                     printf("Case #%d: NO\n",key++);
                  }
       }
       return 0;
}

