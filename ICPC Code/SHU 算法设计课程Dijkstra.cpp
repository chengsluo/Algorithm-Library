#include<iostream>
#include<cstring>
using namespace std;

const int INF = 0x7fffffff;//0x3f3f3f3f;
int G[55][55];
int dist[55];
int Prev[55];
int Pass[55];

void  Dijkstra(int s, int n)
{

    bool p[55];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = G[s][i];
        p[i] = false;
        if (dist[i] == 0)
        {
            Prev[i] = 0;
            dist[i] = INF;
        }
        else Prev[i] = s;
    }
    dist[s] = 0;
    p[s] = true;
    Prev[s] = s;
    for (int ct = 0; ct < n - 1; ct++) ///将n-1个元素加入集合
    {
        int temp = INF;
        int u = s;
        for (int j = 1; j <= n; j++) ///选择一个离源点最短的，未加入集合的元素加入
            if ((!p[j]) && (G[s][j]< temp))
            {
                u = j;
                temp = dist[j];
            }

        p[u] = true;///标志位，已加入
        for (int j = 1; j <= n; j++) ///更新集合到其他非集合点的最短距离
            if ((!p[j]) && (G[u][j] != 0))
            {
                int newdist = dist[u] + G[u][j];
                if (newdist<dist[j])
                {
                    dist[j] = newdist;
                    Prev[j] = u;///记录路径
                }
            }
    }
}
int main()
{
    int n,a,b,c;
    cin >> n;

    cout<<"请输入一系列三元组<a,b,c>;a,b<n;c>0:"<<endl<<"输入'0 0 0'代表结束"<<endl;

    memset(G,0,sizeof(G));

    while(cin>>a>>b>>c)
    {
        if(a==0&&b==0&&c==0) break;
        else if(a<n&&b<n&&a>=0&&b>=0)
        {
            G[a][b]=c;
        }
        else
        {
            cout<<"非法输入，无效，请继续！"<<endl;
        }
    }
    int s, e;
    while(cin >> s >> e)
    {
        Dijkstra(s, n);
        cout<<"The least distance from "<<s<<"->"<<e<<"is"<< dist[e] << endl;
        int k=0;
        while (e!= s)
        {
            Pass[k++] = e;
            e = Prev[e];
        }
        cout << "the path is "<<s;
        for (int i = k - 1; i >= 0; i--)
            cout << "->"<<Pass[i];
        cout << endl;
    }
    return 0;
}
