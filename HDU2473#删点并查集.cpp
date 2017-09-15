#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
int father[1100000];  
int flag[1000050];  
int id;
/*
source:leonharetd

题意：一些点M a,b代表a,b是一个集合,S a代表从集合中删除a点，最后输出有几类
思路：并查集，M代表合并，S代表删除，下面讲一下删除操作
大家都知道合并操作就是找到找到两个节点的父亲，修改父亲，如果删除就是将该点的父亲重新设置成自己，这样行不行呢？
这是不行的，比如1，2，3的父亲都是1，现在删除1，1的父亲还是1，2,3也是1，集合还是1个，正确的应该是2个。
那删除节点的父亲不设成自己给新申请一个节点当做父亲，比如1,2,3的父亲都是1，在一个集合，现在删除1，申请了4当做1的父亲，2,3父亲都是1，然后Find(2)找2的父亲
2的父亲是1，但是1的父亲是4，所以给2的父亲更新成了4,3同理，所以还不行。
正确的方法是每一个点都设立一个虚拟父亲比如1,2,3的父亲分别是4,5,6，现在合并1,2,3都在一个集合，那他们的父亲都是4，现在删除1，那就给1重新申请一个节点7
现在2,3的父亲是4,1的父亲是7，删除成功。

*/
void Make_set(int n,int m)  
{  
    int i;  
    for(i = 0; i < n; i++)  
    {  
        father[i] = i+n;
    }  
    for(i = n; i <= n+n+m; i++)  
    {  
        father[i] = i;  
    }
}  
  
int Find_set(int x)  
{  
    if(x != father[x])  
    {  
        father[x] = Find_set(father[x]);  
    }  
    return father[x];  
}  
  
void Union(int a,int b)  
{  
    int x = Find_set(a);  
    int y = Find_set(b);  
  
    if(x == y)  
        return ;  
    else  
    {  
        father[y] = x;  
    }  
}  
  
void Delet(int x)  
{  
    father[x] = id++;  
}  
int main()  
{  
    int n,m,cas = 1;  
    while(scanf("%d%d",&n,&m) != EOF)  
    {  
        int i;id = n+n; 
        char c[5];  
        int a,b;
        Make_set(n,m);
        if(n == 0 && m == 0)  
            break;  
        for(i = 0; i < m; i++)  
        {  
            scanf("%s",c);  
            if(c[0] == 'M')  
            {  
                scanf("%d%d",&a,&b);  
                Union(a,b);  
            }  
            else  
            {  
                scanf("%d",&a);  
                Delet(a);  
            }  
        }  
        memset(flag,0,sizeof(flag));  
        int ans = 0;  
        for(i = 0;i < n; i++)  
        {  
            int x = Find_set(i);
            if(!flag[x])  
            {  
                ans++;
                flag[x]=1;  
            }  
        }  
        printf("Case #%d: %d\n",cas++,ans);      
    }  
    return 0;  
}  