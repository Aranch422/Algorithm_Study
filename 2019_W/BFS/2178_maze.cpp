#include <iostream>
#include <queue>

using namespace std;

queue<pair<pair<int,int>,int>> Q;
int board[100][100];

int n,m;

int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            board[i][j]=s[j]-48;
        }
    }
}

bool isInside(int r,int c){
    return (0<=r&&r<n&&0<=c&&c<m);
}

void BFS(){
    if(Q.empty()) return;
    int r=Q.front().first.first;
    int c=Q.front().first.second;
    int cnt=Q.front().second;
    Q.pop();
    if(board[r][c]==0) BFS();
    else if(r==n-1&&c==m-1){
        cout<<cnt;
        while(!Q.empty()) Q.pop();
        return;
    }
    else{
        //cout<<r<<" "<<c<<" "<<cnt<<'\n';
        board[r][c]=0;
        for(int i=0;i<4;i++){
            int newr=r+dr[i];
            int newc=c+dc[i];
            if(isInside(newr,newc)){
                if(board[newr][newc]==1){
                    Q.push(make_pair(make_pair(newr,newc),cnt+1));
                }
            }
        }
        BFS();
    }
}

void solve(){
    Q.push(make_pair(make_pair(0,0),1));
    BFS();
}

int main(){
    init();
    solve();
    return 0;
}