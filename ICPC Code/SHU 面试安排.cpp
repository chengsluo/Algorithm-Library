#include<iostream>
#include <cstdlib>
using namespace std;

struct node{///链表结点定义
       node* pio;///前驱
       node* next;///后继
       int no;///当前结点的编号
};

class circle_list{///双向链表
public:
       circle_list(int n=0);///构造函数，默认参数为0
       void del(node* temp);///删除指针temp指向的那个结点
       void print_resume(int k,int m);///根据题目要求建立的函数
private:
       node* head;///主要是在进入链表的时候，方便定位
       int num;///当前环形链表有多少个顶点
};

circle_list::circle_list(int n)
{
       if(n<0)  {
              cout<<"链表中结点数不能为负"<<endl;
              exit(1);
       }
       else if(n==0){
              head=NULL;
       }
       else{
              head=new node;
              head->no=1;
              node * t1=head;
              for(int i=2;i<=n;i++){
                     t1->next=new node;
                     t1->next->pio=t1;
                     t1=t1->next;
                     t1->no=i;
              }
              t1->next=head;
              head->pio=t1;
       }
       num=n;
}

void circle_list::del(node* temp)
{
       temp->pio->next=temp->next;///将要被删的点前驱的后继置为，被删的点的后继
       temp->next->pio=temp->pio;///将要被删的点后继的前驱置为，被删的点的前驱
       delete temp;
       num--;
       return;
}

void circle_list::print_resume(int k,int m)///在删除之后，链表为空
{
       int t;
       node* pos1=head;
       node* pos2=head->pio;
       while(num!=0){
              t=k-1;
              while(t--){
                     pos1=pos1->next;
              }
              t=m-1;
              while(t--){
                     pos2=pos2->pio;
              }
              if(pos1==pos2){
                     cout<<pos2->no<<";"<<endl;
                     pos1=pos1->next;
                     pos2=pos2->pio;
                     del(pos1->pio);
              }
              else{
                     cout<<pos1->no<<",";
                     cout<<pos2->no<<";"<<endl;
                     if(pos1->next==pos2){
                            pos1=pos1->next->next;///先移动到后两个结点
                            pos2=pos2->pio->pio;
                            del(pos1->pio->pio);
                            del(pos2->next);///因为前一个删除操作，减少了相互之间的距离
                     }
                     else{
                            pos1=pos1->next;
                            pos2=pos2->pio;
                            del(pos1->pio);
                            del(pos2->next);
                     }
              }
//              node* temp=pos1;///查看环里剩余的值
//              for(;temp->next!=pos1;temp=temp->next){
//                     cout<<temp->no<<" ";
//              }
//              cout<<endl;
       }
       head=NULL;
       return;
}

int main()
{
       int n,k,m;
       while(cin>>n>>k>>m){
              circle_list LOOP(n);
              LOOP.print_resume(k,m);
       }
       return 0;
}
