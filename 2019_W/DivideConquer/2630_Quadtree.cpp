#include <iostream>

using namespace std;

int board[128][128];

int n;
int blue=0;
int white =0;

void init(){
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
}

void slice(int r,int c, int k){
    bool isblue=true;
    bool iswhite =true;
    for(int i=r;i<r+k;i++){
        for(int j=c;j<c+k;j++){
            if(board[i][j]==1) iswhite=false;
            if(board[i][j]==0) isblue=false;
        }
    }
    if(isblue) {
        blue++;
        return;
    }
    else if(iswhite){
        white++;
        return;
    }
    else{
        k=k/2;
        slice(r,c,k);
        slice(r+k,c,k);
        slice(r,c+k,k);
        slice(r+k,c+k,k);
    }
}

int main(){
    init();
    slice(0,0,n);
    cout<<white<<endl;
    cout<<blue;
    return 0;
}