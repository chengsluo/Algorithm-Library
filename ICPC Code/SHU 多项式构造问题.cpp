#include<iostream>
#include<cstdio>

using namespace std;
int a[10];
int main()
{
    while(cin>>a[8]>>a[7]>>a[6]>>a[5]>>a[4]>>a[3]>>a[2]>>a[1]>>a[0]){
        for(int i=1;i<9;i++){
            if(a[i]!=0) break;
        }
        int key=0;
        if(i<9){
            for(int j=8;j>1;j--){
                if(key){
                    if(a[j]==0);
                    else if(a[j]==1){
                        cout<<" + x^"<<j;
                    }
                    else if(a[j]>1) cout<<" + "<<a[j]<<"x^"<<j;
                    else cout<< cout<<" - "<<-a[j]<<"x^"<<j;
                }
                else{
                    key=1;
                    if(a[j]==0) key=0;
                    else if(a[j]==1){
                        cout<<"x^"<<j;
                    }
                    else if(a[j]>1) cout<<a[j]<<"x^"<<j;
                    else cout<< cout<<" - "<<-a[j]<<"x^"<<j;
                }
            }
            if(key){
                    if(a[1]==0);
                    else if(a[j]==1){
                        cout<<" + x";
                    }
                    else if(a[j]>1) cout<<" + "<<a[j]<<"x^"<<j;
                    else cout<< cout<<" - "<<-a[j]<<"x^"<<j;
                }
                else{
                    key=1;
                    if(a[j]==0) key=0;
                    else if(a[j]==1){
                        cout<<" + x^"<<j;
                    }
                    else if(a[j]>1) cout<<a[j]<<"x^"<<j;
                    else cout<< cout<<" - "<<-a[j]<<"x^"<<j;
                }
        }
        else{
                cout<<a[0]<<endl;
        }
    }
    return 0;
}

