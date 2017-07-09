#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int sh_ct=0;
    int sh[100]; //存放100以内的素数;
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
    int sum[100];//存放“不可能将之分解成两个素数的和”的数；
    //以便满足条件1:"积先生：我不知道 x 和 y 分别是啥。"积非两素数之积
    //以便满足条件2:"和先生：我知道你不知道。"不可能将和分解成两个素数的和
    for(int i=4;i<100;i++){//便历所有和
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
    int possible_ans[10000][2];//存放所有可能的答案组合
    int ct_sum[200]={0};//满足前3个条件的和i的对应个数
    bool maybe_mul[10000]={0};//满足前2个条件的积num对应的个数
    for(int num=4;num<=50*49;num++){//遍历所有可能的积
                int tmp_ct=0;
                int tmp_a,tmp_b;//a和b用来临时保存分解后的两个数
                for(int k=2;k<=num/k;k++){
                        for(int h=0;h<sum_ct;h++)
                            if(num/k*k==num&&num/k+k==sum[h]){//能够整除并且和满足对和的限制条件
                                    int t1,t2;
                                    for(t1=0;t1<sh_ct;t1++){//满足对积的限制条件
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
                if(tmp_ct==1){///既然条件3：“积先生说他已经确定了”,那么必然某个积仅仅只有一个组合的和满足条件1和2
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
        if(ct_sum[i]==1){//既然条件4：“和先生说他已经确定了”,那么必然某个和仅仅只有一个组合的和满足条件1和2和3
            for(int j=0;j<possible_ans_ct;j++){
                if(possible_ans[j][0]+possible_ans[j][1]==i){
                    cout<<"两个组合为："<<possible_ans[j][0]<<" "<<possible_ans[j][1]
                    <<";和为:"<<i<<"积为:"<<possible_ans[j][0]*possible_ans[j][1]<<endl;
                }
            }
        }
    }
    return 0;
}
