#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> Init[4][4];
int G[4][4];
bool path[9][9];
int du[9];
int dx[3]={0,1,1};
int dy[3]={1,0,1};
//相比之前的拓扑版本，path[a][a]==1将不会出现
bool checkTopo()
{
    queue<int> Q;
    for(int i=0;i<9;i++){
        if(du[i]==0) Q.push(i);
    }
    int sum=0;
    while(!Q.empty()){
        int word=Q.front();
        Q.pop();
        for(int i=0;i<9;i++){
            if(path[word][i]&&i!=word){
                du[i]--;
                if(du[i]==0){
                    Q.push(i);
                }
            }
        }
        sum++;
    }
    return sum==9;
}

int main()
{
    for(int i=0;i<9;i++){
        int row=i/3,col=i%3;
        Init[row][col].push_back(i);
        for(int j=0;j<3;j++){
            Init[row+dy[j]][col+dx[j]].push_back(i);
        }
    }
    char str[20];
    while(scanf("%s",str)&&str[0]!='E'){
        getchar();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&G[i][j]);
            }
        }
        memset(path,0,sizeof(path));
        memset(du,0,sizeof(du));

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int end=G[i][j]-1;
                for(int k=0;k<Init[i][j].size();k++){
                    int start=Init[i][j][k];
                    if(end!=start&&path[start][end]==0){
                        du[end]++;
                        path[start][end]=1;
                    }
                }
            }
        }
        if(checkTopo()){
            printf("THESE WINDOWS ARE CLEAN\n");
        }else{
            printf("THESE WINDOWS ARE BROKEN\n");
        }
        scanf("%s",str);
        getchar();
    }
    return 0;
}
