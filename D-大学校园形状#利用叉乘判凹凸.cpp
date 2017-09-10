#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
const int MAX = 10010;
typedef long long ll;
using namespace std;

struct xy
{
    int x;
    int y;
} d[100010];
//利用向量叉乘，判断相邻边的内角大小是否大于180.

int g(int a, int b, int c)
{
    int t;
    //公式:s=(x1-x3)*(y2-y3)-(x2-x3)*(y1-y3)
    //当s>0时,p1,p2,p3三个点呈逆时针
    //当s<0时,p1,p2,p3三个点呈顺时针
    t = (d[a].x - d[c].x) * (d[b].y - d[c].y) - (d[b].x - d[c].x) * (d[a].y - d[c].y);
    return t;
}

int main()
{
    int i, t, n;
    while (scanf("%d", &n) && n != 0)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &d[i].x, &d[i].y);
        }
        for (i = 0; i < n; i++)
        {
            //模n是因为当i=n-1的时候n+1,n+2会超出数据范围,所以从头开始为最后一个点和第一二个点判断直线的走向
            //所以要取模
            t = g(i % n, (i + 1) % n, (i + 2) % n);
            if (t < 0)
                break;
        }
        if (t >= 0)
        {
            printf("convex\n");
        }
        else
            printf("concave\n");
    }
    return 0;
}