#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
int num1[1010],num2[1010];///本题也可以用动态规划求解，因为总是在两端进行操作
int main()
{
    int t,ans1,ans2;
    while(scanf("%d",&t)&&t){
        ans1=0;ans2=0;
        for(int i=0;i<t;i++)
            scanf("%d",num1+i);
        for(int i=0;i<t;i++)
            scanf("%d",num2+i);
        sort(num1,num1+t,cmp);
        sort(num2,num2+t,cmp);
        int f1,f2,r1,r2;
        f1 = f2 = 0;
        r1 = r2 = t - 1;
        int ans = 0;
        while (f1 <= r1) {
            if (num1[f1] > num2[f2]) { ///如果田忌最快的马比国王快，则将两者抵掉
                f1++;
                f2++;
                ans += 200;
            } else if (num1[f1] < num2[f2]) { ///如果田忌最快的马比国王慢，则用田忌最慢的马抵掉国王最快的马
                f2++;
                r1--;
                ans -= 200;
            } else {///当前两人的最快的马的速度相等
                if (num1[r1] > num2[r2]) { ///如果田忌的最慢的马能赢国王的最慢的马，则先比较最慢的马。
                    r1--;
                    r2--;
                    ans += 200;
                } else {///田忌的最慢的马不能赢国王的最慢的马。则用最慢的马跟国王的最快的马比。
                    if (num1[r1] < num2[f2]) {
                        ans -= 200;
                    }
                    r1--;
                    f2++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
