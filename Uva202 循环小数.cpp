#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
using namespace std;
#define maxn 3005
int tmp[maxn];
int ans[55];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a, b, res;
    int n, begin, end, dec;
    while (scanf("%d%d", &a, &b) == 2)
    {
        for (int i = 0; i < maxn; i++)
        {
            tmp[i] = -1;
        }
        end = 0;
        n = a;
        dec = n / b;
        n = n % b;
        while (n != 0)
        {
            if (tmp[n] == -1)
            {
                tmp[n] = end;
            }
            else
            {
                begin = tmp[n];
                break;
            }
            if(end<50) ans[end] = (n*10) / b;
            end++;
            n = (n*10) % b;
        }
        if (n != 0)
        {
            printf("%d/%d = %d.", a, b,dec);
            for (int k = 0; k < end && k < 50; k++)
            {
                if (k == begin)
                {
                    printf("(");
                }
                printf("%d", ans[k]);
            }
            if (end >= 50)
            {
                printf("...");
            }
            printf(")\n   %d = number of digits in repeating cycle\n\n", end - begin);
        }
        else
        {
            printf("%d/%d = %d.", a, b,dec);
            for (int k = 0; k < end; k++)
            {
                printf("%d", ans[k]);
            }
            printf("(0)\n   %d = number of digits in repeating cycle\n\n", 1);
        }
    }

#ifdef LOCAL
    printf("Time used=%.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}