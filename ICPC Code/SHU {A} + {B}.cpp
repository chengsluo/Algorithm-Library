#include<iostream>
#include<cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef int elem;

int main()
{
    int a,b,temp;
    set<elem>se;
    while(scanf("%d%d",&a,&b)==2){
        for(int i=0;i<a;i++) {scanf("%d",&temp);se.insert(temp);}
        for(int i=0;i<b;i++) {scanf("%d",&temp);se.insert(temp);}
        set<int>::iterator iter;
        iter=se.begin();
        printf("%d",*iter);
        for(iter++;iter!=se.end();iter++){
            printf(" %d",*iter);
        }
        printf("\n");
        se.clear();
    }
    return 0;
}
