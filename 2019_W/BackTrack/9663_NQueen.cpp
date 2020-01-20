#include <iostream>

using namespace std;

int N;
int res=0;
bool row[15];
bool col[15];
bool board[15][15];

void init(){
    cin>>N;
    for(int i=0;i<N;i++){
        row[i]=true;
        col[i]=true;
        for(int j=0;j<N;j++){
            board[i][j]=true;
        }
    }
}

void update(int r,int c){
    for(int i=0;i<N;i++){
        board[r][i]=false;
        board[i][c]=false;
        if(r+i<N&&c+i<N) board[r+i][c+i]=false;
        if(r+i<N&&c-i>=0) board[r+i][c-i]=false;
        if(r-i>=0&&c+i<N) board[r-i][c+i]=false;
        if(r-i>=0&&c-i>=0)board[r-i][c-i]=false;
    }
}


void dfs(int r,int c,int cnt){
    if(cnt==1){
        res++;
        return;
    }
    bool temp[15][15];
    row[r]=false;
    col[c]=false;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            temp[i][j]=board[i][j];
        }
    }
    update(r,c);
    int newR=r+1;
    for(int i=0;i<N;i++){
        if(col[i]){
            if(board[newR][i]){
                dfs(newR,i,cnt-1);
            }
        }    
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=temp[i][j];
        }
    }
    row[r]=true;
    col[c]=true;

}

int main(){
    init();
    for(int c=0;c<N;c++){
        dfs(0,c,N);
    }
    cout<<res;
    return 0;
}