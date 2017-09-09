#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[4][4];
int d[3][2]={1,0,0,1,1,1};

//这种解法比较暴力，但是会超时，但是也是一种很好的思路实现。
void DFSandBFS(int a,int b)
{
    int key=0;
    for(int i=0;i<3;i++){
        int x=a+d[i][0];
        int y=b+d[i][1];
        if(x<4&&y<4){
            //关联点不等，并且还未被探索过，则继续BFS.
            if(num[x][y]!=0&&num[x][y]!=num[a][b]){
                DFSandBFS(x,y);
                //此点还需要重新检查
                i--;
            }else key++;
        }
    }
    //首先必定4个数字相等,对于这样的情况，直接将四个点置0即可;
    //对于其他情况，考虑已为0的情况，其他地方满足一致即可。
    if(key==3){
        for(int i=0;i<3;i++){
            int x=a+d[i][0];
            int y=b+d[i][1];
            num[x][y]=0;
        }
        num[a][b]=0;
    }
    //如果能这样一片一片，全部消除的话，则说明这个图案是可以构成的。
}

int main()
{
    char str[20];
    while(scanf("%s",str)!=EOF){
        getchar();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&num[i][j]);
            }
        }
        DFSandBFS(0,0);
        bool  k=1;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(num[i][j]!=0) k=0;
            }
        }
        if(k){
            printf("THESE WINDOWS ARE CLEAN\n" );
        }else{
            printf("THESE WINDOWS ARE BROKEN\n");
        }
        scanf("%s",str);
        getchar();
    }
    return 0;
}