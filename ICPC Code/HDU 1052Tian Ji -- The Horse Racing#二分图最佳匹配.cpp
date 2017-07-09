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
int num1[1010],num2[1010];///����Ҳ�����ö�̬�滮��⣬��Ϊ���������˽��в���
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
            if (num1[f1] > num2[f2]) { ///������������ȹ����죬�����ߵֵ�
                f1++;
                f2++;
                ans += 200;
            } else if (num1[f1] < num2[f2]) { ///������������ȹ����������������������ֵ�����������
                f2++;
                r1--;
                ans -= 200;
            } else {///��ǰ���˵���������ٶ����
                if (num1[r1] > num2[r2]) { ///�����ɵ�����������Ӯ�����������������ȱȽ���������
                    r1--;
                    r2--;
                    ans += 200;
                } else {///��ɵ�����������Ӯ���������������������������������������ȡ�
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
