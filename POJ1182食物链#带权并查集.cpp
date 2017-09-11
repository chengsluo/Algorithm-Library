#include <iostream>
#include <cstdio>
using namespace std;

int n;
int pa[50001],r[50001];
//r[i]为0代表i与pa[i]是同类；
//为1代表i被pa[i]吃;
//为2代表i吃pa[i];
void init_set()
{
    for(int i=0;i<n;i++){
        pa[i]=i;
        r[i]=0;
    }
}

int find_set(int x)
{
    if(pa[x]==x) return x;
    int tmp=pa[x]; //tmp应该可以不要
    pa[x]=find_set(pa[x]);
    r[x]=(r[x]+r[tmp])%3;
    //关系传递规律，通过列举所有9种情况得出。
    //这里有一个关系：如果 x 和y 为关系 r1, y 和 z 为关系 r2 
    //那么 x 和z的关系就是 （r1+r2）%3
    return pa[x];
}

void union_set(int a,int b,int p,int q,int d)
{
    //如果 d == 1则 a 和b 是同类 ，那么 b 对 a 的关系是 0
    //如果 d == 2 则 a 吃了 b,  那么 b 对 a 的关系是 1, a 对 b 的关系是 2.
    //综上所述 ,无论 d为1 或者是为 2,  b 对 a 的关系都是 d-1
    pa[q]=p;//将tree[b]合并到tree[a]上
    r[q]=(3-r[b]+d-1+r[a])%3;//更新其与父节点的关系

    //q 对 b 的关系为 3-r[b]
    //b  对 a 的关系为 d-1
    //a  对 p 的关系为 r[a]
}

int main()
{
    int k,a,b,d;
    scanf("%d%d", &n, &k);
    int ct = 0;
    init_set();
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &d, &a, &b);
        if (a > n || b > n)
        {
            ct++;
            continue;
        }
        if (d == 2 && a == b)
        {
            ct++;
            continue;
        }
        int p=find_set(a),q=find_set(b);
        if(p==q){
            if(d==1){
                if(r[a]!=r[b]) ct++;
            }else{
                //将各种情况列举后得出来的公式
                if((r[a]+1)%3!=r[b]) ct++;
            }
        }else{
            union_set(a,b,p,q,d);
        }
    }
    printf("%d\n",ct);
    return 0;
}