#include<iostream>
using namespace std;

int main()
{
    int a1,b1,c1,d1,a2,b2,c2,d2;
    int a3,b3,c3,d3;
    while(cin>>a1>>b1>>c1>>d1>>a2>>b2>>c2>>d2){
        if(d1+d2<60){
            d3=d1+d2;
        }else{
            c1++;
            d3=d1+d2-60;
        }
        if(c1+c2<60){
            c3=c1+c2;
        }else{
            b1++;
            c3=c1+c2-60;
        }
        if(b1+b2<24){
            b3=b1+b2;
        }else{
            a1++;
            b3=b1+b2-24;
        }
        cout<<a1+a2<<" "<<b3<<" "<<c3<<" "<<d3<<endl;
    }
    return 0;
}

