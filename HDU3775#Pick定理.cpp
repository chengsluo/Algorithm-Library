#include <iostream>
#include <cstdio>  
#include <cstring>
//用0-7表示八个坐标方向，输入一串0-7组成的序列，求总的点的个数（包括边界）

/*
pick 定理 ：s = n + e/2 -1 
多边形面积：area = cross(   ,  );
如果area不除2，那么area = 2s  = 2n + e -2     ==>   (area + 2) + e = 2(n + e)  ==>  (n+e) = (area + e )/2 +1
如果除以2，那么 area = s  ==>    n = s+1 - e/2;      ==>  n+e  = s+1+e/2;//但是要特断e=1的情况~~~~~！！！
*/
char str[1000005];  
int drow[8]={0,-1,-1,-1,0,1,1,1};  
int dcol[8]={1,1,0,-1,-1,-1,0,1};  
int main()  
{  
    long long  r1,c1,val,r,c,i,j,n;  
    long long  s,ans;  
    while(scanf("%s",str)!=EOF)  
    {  
        n=strlen(str);  
        r=c=s=0;  
        for (i=0;i<n;i++)  
        {  
            val=str[i]-'0';  
            r1=r+drow[val];  
            c1=c+dcol[val];  
            s=s+r*c1-c*r1;  
            r=r1;  
            c=c1;  
        }   
        if (s<0) s=-s;  
        printf("%lld\n",(n+s)/2+1);
        //加n是因为还要加上最外围的一圈，除2是因为
    }  
    return 0;  
}  