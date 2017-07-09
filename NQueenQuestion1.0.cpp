#include <iostream>
using namespace std;

int N;
int G[11];

bool canPlace(int a,int b){
    for(int i=1;i<a;i++){
        if(G[i]==b|a-i==b-G[i]|a-i==G[i]-b){
            return false;
        }
    }
    return true;
}

int main() {
    cin>>N;
    while(N!=0) {
        for (int i = 1; i <= N; i++) {
            G[i] = 0;
        }
        G[1] = 1;
        int sum = 0;
        int row = 1;
        int k = 1;
        while (row <= N && row >= 1) {
            if (k <= N) {
                if (canPlace(row, k)) {
                    G[row] = k;
                    k = 1;
                    row++;
                } else {
                    k++;
                }
            } else {
                row--;
                k = G[row] + 1;
            }
            if (row > N) {
                sum++;
                row--;
                k = G[row] + 1;
            }
        }
        cout<<sum<<endl;
        cin>>N;
    }
    return 0;
}