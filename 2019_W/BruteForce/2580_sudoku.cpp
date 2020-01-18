#include <iostream>

using namespace std;


int board[9][9];

void init(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
}

//check condition
bool check(int r, int c,int num){
    //row
    for(int i=0;i<9;i++){
        if(board[r][i]==num) return false;
    }

    //column
    for(int i=0;i<9;i++){
        if(board[i][c]==num) return false;
    }

    for(int i=(r/3)*3;i<(r/3)*3+3;i++){
        for(int j=(c/3)*3;j<(c/3)*3+3;j++){
            if(board[i][j]==num) return false;
        }
    }

    return true;
}

//no next return -1,-1
pair<int,int> findnext(int r, int c){

    for(int j=c+1;j<9;j++){
        if(board[r][j]==0){
            return make_pair(r,j);
        }
    }
    
    for(int i=r+1;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                return make_pair(i,j);
            }
        }
    }

    return make_pair(-1,-1);
}


int dfs(int r, int c){
    if(r==-1&&c==-1) return 0;

    for(int k=1;k<10;k++){
        if(check(r,c,k)){
            board[r][c]=k;

            int nextR=findnext(r,c).first;
            int nextC=findnext(r,c).second;

            if(dfs(nextR,nextC)==0) return 0;
        }
    }
    board[r][c]=0;
    return -1;
}

void solve(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                dfs(i,j);
                return;
            }
        }
    }
}



int main(){

    init();
    solve();
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<< endl;
    }
    
    return 0;
}