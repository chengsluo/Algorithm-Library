#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=10010;
typedef long long ll;
using namespace std;

int a[210][210];
int num[210];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            scanf("%d",num+i);
            num[n+i]=num[i];
    }
    for(int r=0;r<n;r++){
        for(int i=1;i<2*n;i++){
                a[i][i]=0;
            for(int j=i;j<i+r;j++){
                a[i][i+r]=max(a[i][i+r],a[i][j]+a[j+1][i+r]+num[i]*num[j+1]*num[i+r+1]);
            }
        }
    }
//    for(int i=1;i<=2*n;i++){
//        for(int j=1;j<=2*n;j++) cout<<setw(5)<<a[i][j]<<" ";
//        cout<<endl;
//    }
    int ans=0;
    for(int i=1;i<2*n;i++)
        ans=max(ans,a[i][i+n-1]);
    cout<<ans<<endl;
    return 0;
}

/*
struct Node{
    int f;
    int  e;
    Node* next;
};
int main()
{
    int n,temp,ans=0;
    cin>>n;
    Node* head=new Node;
    Node* p=head;
    scanf("%d",&p->f);
    for(int i=1;i<n;i++){
        scanf("%d",&temp);
        p->e=temp;
        p->next=new Node;
        p=p->next;
        p->f=temp;
    }
    p->e=head->f;
    p->next=head;
    while(p!=p->next){
        if(p->f>=p->e&&(p->next->f<=p->next->e)){//错误思路：比如当100、2、3、2、10000的情况
            ans+=(p->f*p->e*p->next->e);
           // cout<<p->f<<" "<<p->e<<" "<<p->next->f<<" "<<p->next->e<<" "<<endl;
            p->e=p->next->e;
            Node* temp=p->next;
            p->next=p->next->next;
            delete temp;
        }
        p=p->next;
    }
    cout<<ans<<endl;
    return 0;
}*/
