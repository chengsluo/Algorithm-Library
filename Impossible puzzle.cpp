#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int sh_ct=0;
    int sh[100]; //���100���ڵ�����;
    for(int i=2;i<100;i++){
        int j;
        for(j=2;j<i;j++){
            if((i/j)*j==i) break;
        }
        if(j>=i){ sh[sh_ct++]=i;}
    }
//    for (int i=0;i<sh_ct;i++){
//        cout<<sh[i]<<" ";
//    }
//    cout<<endl;
    int sum_ct=0;
    int sum[100];//��š������ܽ�֮�ֽ�����������ĺ͡�������
    //�Ա���������1:"���������Ҳ�֪�� x �� y �ֱ���ɶ��"����������֮��
    //�Ա���������2:"����������֪���㲻֪����"�����ܽ��ͷֽ�����������ĺ�
    for(int i=4;i<100;i++){//�������к�
        int j,k;
        for(j=0;j<sh_ct;j++){
            for(k=0;k<sh_ct;k++){
                if(sh[j]+sh[k]==i)break;
            }
            if(k<sh_ct) break;
        }
        if(j>=sh_ct) sum[sum_ct++]=i;
    }
//    for (int i=0;i<sum_ct;i++){
//        cout<<sum[i]<<" ";
//    }
//    cout<<endl;
    int possible_ans_ct=0;
    int possible_ans[10000][2];//������п��ܵĴ����
    int ct_sum[200]={0};//����ǰ3�������ĺ�i�Ķ�Ӧ����
    bool maybe_mul[10000]={0};//����ǰ2�������Ļ�num��Ӧ�ĸ���
    for(int num=4;num<=50*49;num++){//�������п��ܵĻ�
                int tmp_ct=0;
                int tmp_a,tmp_b;//a��b������ʱ����ֽ���������
                for(int k=2;k<=num/k;k++){
                        for(int h=0;h<sum_ct;h++)
                            if(num/k*k==num&&num/k+k==sum[h]){//�ܹ��������Һ�����Ժ͵���������
                                    int t1,t2;
                                    for(t1=0;t1<sh_ct;t1++){//����Ի�����������
                                        if(num/k==sh[t1]){
                                                for(t2=0;t2<sh_ct;t2++){
                                                    if(k==sh[t2]) break;
                                                }
                                                if(t2<sh_ct) break;
                                        }
                                    }
                                    if(t1<sh_ct) break;

                                    tmp_ct++;
                                    tmp_a=k;tmp_b=num/k;
                                    break;
                            }
                }
                if(tmp_ct==1){///��Ȼ����3����������˵���Ѿ�ȷ���ˡ�,��ô��Ȼĳ��������ֻ��һ����ϵĺ���������1��2
                    possible_ans[possible_ans_ct][0]=tmp_a;
                    possible_ans[possible_ans_ct][1]=tmp_b;
                    possible_ans_ct++;
                    //cout<<tmp_a<<" "<<tmp_b<<endl;
                    maybe_mul[num]=true;
                }
    }
    for(int i=0;i<10000;i++){
        if(maybe_mul[i]){
            for(int j=0;j<possible_ans_ct;j++){
                if(possible_ans[j][0]*possible_ans[j][1]==i){
                    ct_sum[ possible_ans[j][0]+possible_ans[j][1] ]++;
                     //cout<<possible_ans[j][0]<<" "<<possible_ans[j][1]<<endl;
                }
            }
        }
    }
    for(int i=0;i<200;i++){
        if(ct_sum[i]==1){//��Ȼ����4����������˵���Ѿ�ȷ���ˡ�,��ô��Ȼĳ���ͽ���ֻ��һ����ϵĺ���������1��2��3
            for(int j=0;j<possible_ans_ct;j++){
                if(possible_ans[j][0]+possible_ans[j][1]==i){
                    cout<<"�������Ϊ��"<<possible_ans[j][0]<<" "<<possible_ans[j][1]
                    <<";��Ϊ:"<<i<<"��Ϊ:"<<possible_ans[j][0]*possible_ans[j][1]<<endl;
                }
            }
        }
    }
    return 0;
}
