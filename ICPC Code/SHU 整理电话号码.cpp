#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    char ch;
    cin>>n;
    while(n--){
       getchar();
        for(int i=0;i<4;i++){
            ch=getchar();
            if(ch>='0'&&ch<='9') cout<<ch;
            if(ch=='A'||ch=='a'||ch=='B'||ch=='b'||ch=='C'||ch=='c')cout<<'2';
            if(ch=='D'||ch=='E'||ch=='F'||ch=='d'||ch=='e'||ch=='f')cout<<'3';
            if(ch=='J'||ch=='K'||ch=='L'||ch=='j'||ch=='k'||ch=='l')cout<<'5';
            if(ch=='G'||ch=='H'||ch=='I'||ch=='g'||ch=='h'||ch=='i')cout<<'4';
            if(ch=='M'||ch=='N'||ch=='O'||ch=='m'||ch=='n'||ch=='o')cout<<'6';
            if(ch=='P'||ch=='Q'||ch=='R'||ch=='S'||ch=='p'||ch=='q'||ch=='r'||ch=='s')cout<<'7';
            if(ch=='T'||ch=='U'||ch=='V'||ch=='t'||ch=='u'||ch=='v')cout<<'8';
            if(ch=='W'||ch=='X'||ch=='Y'||ch=='Z'||ch=='w'||ch=='x'||ch=='y'||ch=='z')cout<<'9';
        }
        cout<<'-';
        for(int i=0;i<4;i++){
            ch=getchar();
            if(ch>='0'&&ch<='9') cout<<ch;
            if(ch=='A'||ch=='a'||ch=='B'||ch=='b'||ch=='C'||ch=='c')cout<<'2';
            if(ch=='D'||ch=='E'||ch=='F'||ch=='d'||ch=='e'||ch=='f')cout<<'3';
            if(ch=='J'||ch=='K'||ch=='L'||ch=='j'||ch=='k'||ch=='l')cout<<'5';
            if(ch=='G'||ch=='H'||ch=='I'||ch=='g'||ch=='h'||ch=='i')cout<<'4';
            if(ch=='M'||ch=='N'||ch=='O'||ch=='m'||ch=='n'||ch=='o')cout<<'6';
            if(ch=='P'||ch=='Q'||ch=='R'||ch=='S'||ch=='p'||ch=='q'||ch=='r'||ch=='s')cout<<'7';
            if(ch=='T'||ch=='U'||ch=='V'||ch=='t'||ch=='u'||ch=='v')cout<<'8';
            if(ch=='W'||ch=='X'||ch=='Y'||ch=='Z'||ch=='w'||ch=='x'||ch=='y'||ch=='z')cout<<'9';
        }
        cout<<endl;
    }
    return 0;
}
