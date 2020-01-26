#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int n;
int board[64][64];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            board[i][j]=s[j]-'0';
        }
    }
    /*
    cout<<"##########\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    */
}

void QT(int r,int c,int k){
    bool isZero=true;
    bool isOne=true;
    for(int i=r;i<r+k;i++){
        for(int j=c;j<c+k;j++){
            if(board[i][j]==1){
                isZero=false;
            }
            if(board[i][j]==0){
                isOne=false;
            }
        }
    }
    if(isZero) {
        cout<<0;
        return;
    }
    else if(isOne){
        cout<<1;
        return;
    } 
    else{
        k=k/2;
        cout<<"(";
        QT(r,c,k);
        QT(r,c+k,k);
        QT(r+k,c,k);
        QT(r+k,c+k,k);
        cout<<")";
    }
}

int main(){
    init();
    QT(0,0,n);
    return 0;
}