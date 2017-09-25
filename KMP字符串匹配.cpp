#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int pMaxn=1e4;
const int sMaxn=7e4;
int Next[pMaxn];//不能用next，可能会与系统关键词矛盾
char p[pMaxn];//模式串 
char s[sMaxn];//主串 

void getNext(){
	int pLen=strlen(p);
	Next[0]=-1;
	int k=-1;//相同前缀下标
	int j=0;//相同后缀下标
	while(j<pLen-1){
		if(k==-1||p[k]==p[j]){
			k++;j++;
			if(p[j]!=p[k])
				Next[j]=k;
			else //为了进一步优化Next数组 
				Next[j]=Next[k];
		}
		else
			k=Next[k];
	}
}

int KMP(){
	getNext();
	int i=0,j=0;//i为s上的下标，j为p上的下标
	int ct=0; //ct为模式串出现的次数 
	int pLen=strlen(p),sLen=strlen(s);
	while(i<sLen&&j<pLen){
		if(j==-1||s[i]==p[j]){//不要把s错敲成p
			i++;j++;
		}else{
			j=Next[j];
		}
		if(j==pLen){
			//return i-j+1;//只返回首个匹配位置 
			ct++;
			i=i-j+1;//abab形式在abababac中情况，不能用i++； 
			j=0;
		} 
	}
	return ct;
}

int main(){
	int t=1;
	while(gets(p)!=NULL&&gets(s)!=NULL){
		cout<<"Case "<<t++<<": "<<KMP()<<endl;
	}
	return 0;
}


