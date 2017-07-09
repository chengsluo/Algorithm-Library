#include<iostream>
#include <iomanip>
using namespace std;

int board[1025][1025];//2^10最多可以计算K=10; 
int CN;

void chessBoard(int tr, int tc, int dr, int dc, int size){
	if(size==1) return ;
	int  t=CN++;//CN记录L型骨牌号 
	size=size/2;//分割 
	
	if(dr<tr+size&&dc<tc+size)//特殊方格在左上部分 
		chessBoard(tr,tc,dr,dc,size);//直接对左上子棋盘继续分割 
	else{//特殊方格未在左上部分 
		board[tr+size-1][tc+size-1]=t;//将左上子棋盘的最右下方的一个方格填上骨牌 
		chessBoard(tr,tc,tr+size-1,tc+size-1,size);//再对左上子棋盘继续分割
	}
	
	
	if(dr<tr+size&&dc>=tc+size)//特殊方格在左下部分
		chessBoard(tr,tc+size,dr,dc,size);//直接对左下子棋盘继续分割 
	else{//特殊方格未在左下部分 
		board[tr+size-1][tc+size]=t;//将左下子棋盘的最右上方的一个方格填上骨牌 
		chessBoard(tr,tc+size,tr+size-1,tc+size,size);//再对左下子棋盘继续分割
	}
	 
	 
	if(dr>=tr+size&&dc<tc+size)//特殊方格在右上部分 
		chessBoard(tr+size,tc,dr,dc,size);//直接对右上子棋盘继续分割 
	else{//特殊方格未在右上部分 
		board[tr+size][tc+size-1]=t;//将右上子棋盘的最左下方的一个方格填上骨牌 
		chessBoard(tr+size,tc,tr+size,tc+size-1,size);//再对右上子棋盘继续分割
	}
	
	
	if(dr>=tr+size&&dc>=tc+size)//特殊方格在右下部分 
		chessBoard(tr+size,tc+size,dr,dc,size);//直接对右下子棋盘继续分割 
	else{//特殊方格未在右下部分 
		board[tr+size][tc+size]=t;//将右下子棋盘的最左上方的一个方格填上骨牌 
		chessBoard(tr+size,tc+size,tr+size,tc+size,size);//再对右下子棋盘继续分割
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

