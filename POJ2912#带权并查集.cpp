#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

不过我们要枚举裁判；就是我们枚举出来的裁判参加的比赛我们都不管；
然后看看会不会出现错误；
如果游戏除掉裁判后，从头到尾都没出现错误，则这个人是裁判；
然后看看我们枚举其他人时，比如我们假设第一个人是裁判时，第二局出错了，那说明第二句就断定了第一个人不是裁判；
以此来算，我们找到裁判后，其他所有的出错局数最大的就是我们判断的步数；因为到了这一步，可以断定其他人都不是裁判了；
当然也有可能找不到裁判，或者找到多个裁判，这两种输出指定字符串；

*/

const int M = 2001;
const int N=501;
int r[N], root[N];

void init_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        root[i] = i;
        r[i] = 0;
    }
}
int find_set(int x)
{
    if (root[x] == x)
    {
        return x;
    }
    int temp = root[x];
    root[x] = find_set(root[x]);
    r[x] = (r[x] + r[temp]) % 3;
    //一共有三种状态,其中每种状态相互关联,A胜B,B胜C,C胜D,D胜A.构成循环
    //对于3个集合来讲:
    //0是同类,1是胜,2是负.
    //假如a对b是r[a]=0,b对c是r[b]=1,则a对c是1
    //1,1,则2(c胜a)
    //对于4个集合来讲:
    //0是同类,1是胜,2无关能胜于比他更强的人,3是负.
    //假如a对b是r[a]=0,b对c是r[b]=1,则a对c是1
    //假如a对b是r[a]=1,b对c是r[b]=1,则a对c是2
    //推演类似

    //这里是带权并查集的精髓
    return root[x];
}
bool union_set(int a, int b,int d)
{
    int x = find_set(a), y = find_set(b);
    if (x == y)
    {
        if (d == 0 && r[a] != r[b])
        {
            return false;
        }
        else if (d == 1)
        {
            if ((r[a] + 1) % 3 != r[b])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        root[y] = x;
        r[y] = (3- r[b]+d+r[a]) % 3;
        //b对a的关系是d;
        //y对b的关系是(3-r[b])%3;
        //a对x的关系是r[a];

        //合并时需要更改被合并负节点的关系值r[y].这个取决于a和b与根节点的关系
        //因为在find_set()过程中原本的关系就被整理成了与根节点的关系.


        //其实也可以推演出来,3*3*2=18种
        //假设a与x的关系r[a]是1,b与y的关系r[b]是2,a与b的关系是1,则y与x的关系是0
        //假设a与x的关系r[a]是1,b与y的关系b]是2,a与b的关系是0,则y与x的关系是2
        //0/1/2
        //其他推演效果一致...
        return true;
    }
}

int main()
{
    int m,n;
    int left[M], right[M],step[M];
    char ch[M];    
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d%c%d", left + i, ch + i, right + i);
        }
        memset(step, 0, sizeof(step));
        int cnt = 0;
        //矛盾的答案数
        int ans = -1;
        //枚举每一个参与者,排除他参与的场次.
        //如果他是裁判,则他被排除后,结果无矛盾.
        //如果他不是裁判,被排除后结果有矛盾,最开始出现矛盾的地方就是裁判出现的地方.
        for (int i = 0; i < n; i++)
        {
            init_set(n);
            bool flag = 0;
            for (int j = 0; j < m; j++)
            {
                if (left[j] == i || right[j] == i)
                {
                    continue;
                }
                else if ((ch[j] == '=' && !union_set(left[j], right[j], 0)) || (ch[j] == '>' && !union_set(left[j], right[j], 1)) || (ch[j] == '<' && !union_set(right[j],left[j],1)))
                {
                    flag = 1;
                    if(j>step[i]) step[i] = j + 1;
                    break;
                }
            }
            //如果去除此人后,没有发现错误,则此人是裁判.
            if (flag == 0)
            {
                ans = i;
                cnt++;
            }
        }
        if (cnt == 0)
        {
            printf("Impossible\n");
        }
        else if (cnt == 1)
        {
            int Max = 0;
            for (int i = 0; i < n; i++)
            {
                if (step[i] > Max)
                    Max = step[i];
            }
            printf("Player %d can be determined to be the judge after %d lines\n", ans, Max);
        }
        else{
            //多个裁判 
            printf("Can not determine\n");
        }
    }
    return 0;
}