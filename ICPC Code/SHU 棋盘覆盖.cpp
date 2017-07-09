#include<iostream>
#include <iomanip>
using namespace std;

int board[1025][1025];//2^10�����Լ���K=10; 
int CN;

void chessBoard(int tr, int tc, int dr, int dc, int size){
	if(size==1) return ;
	int  t=CN++;//CN��¼L�͹��ƺ� 
	size=size/2;//�ָ� 
	
	if(dr<tr+size&&dc<tc+size)//���ⷽ�������ϲ��� 
		chessBoard(tr,tc,dr,dc,size);//ֱ�Ӷ����������̼����ָ� 
	else{//���ⷽ��δ�����ϲ��� 
		board[tr+size-1][tc+size-1]=t;//�����������̵������·���һ���������Ϲ��� 
		chessBoard(tr,tc,tr+size-1,tc+size-1,size);//�ٶ����������̼����ָ�
	}
	
	
	if(dr<tr+size&&dc>=tc+size)//���ⷽ�������²���
		chessBoard(tr,tc+size,dr,dc,size);//ֱ�Ӷ����������̼����ָ� 
	else{//���ⷽ��δ�����²��� 
		board[tr+size-1][tc+size]=t;//�����������̵������Ϸ���һ���������Ϲ��� 
		chessBoard(tr,tc+size,tr+size-1,tc+size,size);//�ٶ����������̼����ָ�
	}
	 
	 
	if(dr>=tr+size&&dc<tc+size)//���ⷽ�������ϲ��� 
		chessBoard(tr+size,tc,dr,dc,size);//ֱ�Ӷ����������̼����ָ� 
	else{//���ⷽ��δ�����ϲ��� 
		board[tr+size][tc+size-1]=t;//�����������̵������·���һ���������Ϲ��� 
		chessBoard(tr+size,tc,tr+size,tc+size-1,size);//�ٶ����������̼����ָ�
	}
	
	
	if(dr>=tr+size&&dc>=tc+size)//���ⷽ�������²��� 
		chessBoard(tr+size,tc+size,dr,dc,size);//ֱ�Ӷ����������̼����ָ� 
	else{//���ⷽ��δ�����²��� 
		board[tr+size][tc+size]=t;//�����������̵������Ϸ���һ���������Ϲ��� 
		chessBoard(tr+size,tc+size,tr+size,tc+size,size);//�ٶ����������̼����ָ�
	}
	
}
int main(){
	int x,y,k,ct=1;
	while(cin>>k>>x>>y){
		int size=1<<k;
		CN=1;
		chessBoard(0,0,x-1,y-1,size);
		cout<<"Case "<<ct++<<": "<<"n="<<size<<endl;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(i==x-1&&j==y-1)
					cout<<setfill(' ')<<setw(4)<<'#';
				else
					cout<<setfill(' ')<<setw(4)<<board[i][j];				
			}
			cout<<endl;
		}
		cout<<endl;		
	}
	return 0;
}

