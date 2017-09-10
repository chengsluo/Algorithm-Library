#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
//转化后即变成求 gcd（m,n）==1的数量，也就是两个数互质的数量
//可以用容斥原理
//也可以用莫比乌斯反演

int prime[8];

//小于等于t的数中，与m互质的个数
int getNum(int t, int m)
{
    //求出t中的所有质因数
    int pn = 0;
    for (int i = 2; i*i <= t; i++)
    {
        if (t % i)
            continue;
        while (t % i == 0)
            t /= i;
        prime[pn++] = i;
    }
    if (t != 1)
    {
        prime[pn++] = t;
    }

    int res = 0;
    int allFactor = 1 << pn;
    for (int i = 1; i < allFactor; i++)
    {
        int cnt = 0, tmp = 1;
        for (int j = 0; j < pn; j++)
        {
            if ((i >> j) & 1 == 1)
            {
                cnt++;
                tmp *= prime[j];
            }
        }
        if (cnt&1)
        {
            res += m / tmp;
        }
        else
        {
            res -= m / tmp;
        }
    }
    return m - res;
}
int main()
{
    int t, m, n;
    long long res;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);
        res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += getNum(i, m);
        }
        printf("%lld\n",res);
    }
    return 0;
}