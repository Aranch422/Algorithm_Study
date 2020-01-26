#include <iostream>

using namespace std;

int n;
int Minus=0;
int zero=0;
int one=0;

int board[2187][2187];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
}

void solve(int r,int c,int k){
    bool isone= true;
    bool iszero=true;
    bool isminus =true;

    for(int i=r;i<r+k;i++){
        for(int j=c;j<c+k;j++){
            if(board[i][j]!=1) isone=false;
            if(board[i][j]!=0) iszero=false;
            if(board[i][j]!=-1) isminus=false;
        }
    }
    if(isone){
        one++;
        return;
    }
    if(iszero){
        zero++;
        return ;
    }
    if(isminus){
        Minus++;
        return;
    }
    else{
        k=k/3;
        solve(r,c,k);
        solve(r,c+k,k);
        solve(r,c+k+k,k);
        solve(r+k,c,k);
        solve(r+k,c+k,k);
        solve(r+k,c+k+k,k);
        solve(r+k+k,c,k);
        solve(r+k+k,c+k,k);
        solve(r+k+k,c+k+k,k);
    }
}
int main(){
    init();
    solve(0,0,n);
    cout<<Minus<<endl;
    cout<<zero<<endl;
    cout<<one;
}