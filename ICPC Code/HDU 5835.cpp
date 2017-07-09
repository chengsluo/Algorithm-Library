#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct ps
{
    int flag;
    int num;
    bool operator < (ps tar) const
    {
        if(tar.num>num) return true;
        else return false;
    }
}pas[12];

int main()
{
    int t,key=0;
    cin>>t;
    int CS=0;
    while(t--)
    {
        CS++;

        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&pas[i].num);
            pas[i].flag=i;
            sum+=pas[i].num;
        }
        printf("Case #%d: ",CS);
        int ans=0;
        int fl=-1;
        sort(pas,pas+n);
        reverse(pas,pas+n);
        while(pas[0].num>0){
              key=0;
              for(int i=0;i<n;i++){
                      if(pas[i].flag==fl) continue;
                      else if(pas[i].num!=0){
                                   pas[i].num--;
                                   key=1;
                                   fl=pas[i].flag;
                                   break;
                     }
              }
              if(key==0) break;
              else {
                            ans++;
                            sort(pas,pas+n);
                            reverse(pas,pas+n);
              }
              if(ans>sum/2){
                     ans--;
                     break;
              }
        }
        cout<<ans<<endl;
    }
    return 0;
}
