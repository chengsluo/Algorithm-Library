#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int N = 40;
const int INF = 0x3f3f3f3f;

int G[N][N], maps[N][N];
int n;
// (3 <=N <= 30, 3 <= M <= 1000)用floyd是完全可以的


//图矩阵默认各点距离无穷大
void Init()
{
    int i, j;
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= n ; j++)
        {
            if(i == j)
                G[i][j] = 0;
            else
                G[i][j] = G[j][i] = INF;
        }
    }
}

int Floyd(int m)
{
    int i, j, k;
    //重新构图
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= n; j++)
        {
            if(i == m || j == m)
                maps[i][j] = maps[j][i] = INF;//让编号为m的人不帮，来破坏该条关系链
            else
                maps[i][j] = maps[j][i] = G[i][j];
        }
    }
    //Floyd,将每个点松弛一下。O(n^3)
    for(k = 1 ; k <= n ; k++)
    {
        for(i = 1 ; i <= n ; i++)
        {
            for(j = 1 ; j <= n ; j++)
            {
                if(maps[i][j] > maps[i][k] + maps[k][j])
                    maps[i][j] = maps[i][k] + maps[k][j];
            }
        }
    }
    //最小距离
    return maps[1][n];
}

int main()
{
    int m, i, a, b, c;
    while(scanf("%d%d", &n, &m), m + n)
    {
        Init();
        while(m--)
        {
            scanf("%d%d%d", &a, &b, &c);
            G[b][a] = G[a][b] = c;
        }
        int ans = 0;
        //纯暴力删点。
        for(i = 2 ; i <= n - 1 ; i++)
            ans = max(ans, Floyd(i));
        if(ans == INF)
            printf("Inf\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
