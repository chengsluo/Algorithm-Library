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
    for (int ct = 0; ct < n - 1; ct++) ///��n-1��Ԫ�ؼ��뼯��
    {
        int temp = INF;
        int u = s;
        for (int j = 1; j <= n; j++) ///ѡ��һ����Դ����̵ģ�δ���뼯�ϵ�Ԫ�ؼ���
            if ((!p[j]) && (G[s][j]< temp))
            {
                u = j;
                temp = dist[j];
            }

        p[u] = true;///��־λ���Ѽ���
        for (int j = 1; j <= n; j++) ///���¼��ϵ������Ǽ��ϵ����̾���
            if ((!p[j]) && (G[u][j] != 0))
            {
                int newdist = dist[u] + G[u][j];
                if (newdist<dist[j])
                {
                    dist[j] = newdist;
                    Prev[j] = u;///��¼·��
                }
            }
    }
}
int main()
{
    int n,a,b,c;
    cin >> n;

    cout<<"������һϵ����Ԫ��<a,b,c>;a,b<n;c>0:"<<endl<<"����'0 0 0'�������"<<endl;

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
            cout<<"�Ƿ����룬��Ч���������"<<endl;
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
