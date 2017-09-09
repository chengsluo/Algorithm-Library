#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn=10;

vector<int> value[maxn][maxn];
int dr[]={0,1,0,1};
int dc[]={0,0,1,1};
int G[maxn][maxn];
int in[maxn];
    
//判断这些边关系是否有拓扑矛盾
bool topo()
{
    queue<int> Q;
    //将在此点之前点的个数为0的点入队
    for(int i=0;i<9;i++)
        if(in[i]==0) Q.push(i);
    int sum=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        //将其后的点找出来，并且将在此点之前点个数为0的点入队,可以通过此节点依次继续往下找
        for(int v=0;v<9;v++){
            if(G[u][v]){
                G[u][v]=0;
                if(--in[v]==0) Q.push(v);
            }
        }
        sum++;
    }
    return sum==9;
}

int main()
{
    //从1到9依次重叠的数据状态
    for(int i=0;i<9;i++){
        int r=i/3,c=i%3;
        for(int dir=0;dir<4;dir++){
            int nr=r+dr[dir];
            int nc=c+dc[dir];
            value[nr][nc].push_back(i);
        }
    }

    char str[100];
    while(scanf("%s",str)==1&&str[0]!='E'){
        //二维数组G存放路径先后关系
        memset(G,0,sizeof(G));
        //一维数组in存放入在此点之前点的个数
        memset(in,0,sizeof(in));
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int v;
                scanf("%d",&v);
                //为了方便表示，所有数据前移一位
                v--;
                for(int k=0;k<value[i][j].size();k++){
                    if((value[i][j])[k]!=v){
                        int x=(value[i][j])[k];
                        if(G[x][v]==0){
                            in[v]++;
                            G[x][v]=1;
                        }
                    }
                }
            }
        }
        if(topo()) printf("THESE WINDOWS ARE CLEAN\n");
        else printf("THESE WINDOWS ARE BROKEN\n");
        scanf("%s",str);
    }

    return 0;
}
