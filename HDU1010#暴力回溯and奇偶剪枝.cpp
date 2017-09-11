#include <iostream>
#include <cstdio>
using namespace std; 
char map[7][7];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int n,m,t;
int sx,sy,ex,ey;
//奇偶剪枝

bool search(int x,int y,int rt)
{
    if(x==ex&&y==ey&&rt==0){
        return true;
    }else if((x==ex&&y==ey)||(rt==0)){
        return false;
    }else{
        char tmp=map[x][y];
        map[x][y]='X';        
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if((nx>=0&&nx<n)&&(ny>=0&&ny<m)&&(map[nx][ny]!='X')){
                int tx=ex-nx;
                int ty=ey-ny;
                int sum=0;
                if(tx<0){
                    sum-=tx;
                }else{
                    sum+=tx;
                }
                if(ty<0){
                    sum-=ty;
                }else{
                    sum+=ty;
                }
                if(sum>rt-1){
                    continue;
                }
                if((sum%2)!=(rt-1)%2){//奇偶剪枝
                    continue;
                }
                if(search(nx,ny,rt-1)){
                    return true;
                } 
            }
        }
        map[x][y]=tmp;        
        return false;        
    }
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&t),n+m+t){
        getchar();        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%c",&map[i][j]);
                if(map[i][j]=='S'){
                    sx=i,sy=j;
                }else if(map[i][j]=='D'){
                    ex=i,ey=j;
                }
            }
            getchar();
        }
        if(search(sx,sy,t)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}