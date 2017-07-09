#include<iostream>
#include <cstdlib>
using namespace std;

struct node{///�����㶨��
       node* pio;///ǰ��
       node* next;///���
       int no;///��ǰ���ı��
};

class circle_list{///˫������
public:
       circle_list(int n=0);///���캯����Ĭ�ϲ���Ϊ0
       void del(node* temp);///ɾ��ָ��tempָ����Ǹ����
       void print_resume(int k,int m);///������ĿҪ�����ĺ���
private:
       node* head;///��Ҫ���ڽ��������ʱ�򣬷��㶨λ
       int num;///��ǰ���������ж��ٸ�����
};

circle_list::circle_list(int n)
{
       if(n<0)  {
              cout<<"�����н��������Ϊ��"<<endl;
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
       temp->pio->next=temp->next;///��Ҫ��ɾ�ĵ�ǰ���ĺ����Ϊ����ɾ�ĵ�ĺ��
       temp->next->pio=temp->pio;///��Ҫ��ɾ�ĵ��̵�ǰ����Ϊ����ɾ�ĵ��ǰ��
       delete temp;
       num--;
       return;
}

void circle_list::print_resume(int k,int m)///��ɾ��֮������Ϊ��
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
                            pos1=pos1->next->next;///���ƶ������������
                            pos2=pos2->pio->pio;
                            del(pos1->pio->pio);
                            del(pos2->next);///��Ϊǰһ��ɾ���������������໥֮��ľ���
                     }
                     else{
                            pos1=pos1->next;
                            pos2=pos2->pio;
                            del(pos1->pio);
                            del(pos2->next);
                     }
              }
//              node* temp=pos1;///�鿴����ʣ���ֵ
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
