#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> Q;

int board[50][50];

int m,n,k;

int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};

void init(){
    // 가로 세로 개수

    cin>>m>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j]=0;
        }
    }
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        board[y][x]=1;
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    */
}

pair<int,int> findOne(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

bool isInside(int x,int y){
    return (0<=x&&0<=y&&x<n&&y<m);
}

void BFS(){
    //cout<<"Running BFS";
    if(Q.empty()) return;
    int r = Q.front().first;
    int c = Q.front().second;
    Q.pop();
    if(board[r][c]==0) BFS();

    board[r][c]=0;
    for(int i=0;i<4;i++){
        int newr =r+dr[i];
        int newc =c+dc[i];
        if(isInside(newr,newc)){
            if(board[newr][newc]==1){
                Q.push(make_pair(newr,newc));
            }
        }
    }
    BFS();
}


void solve(){
    int cnt=0;
    while(findOne().first!=-1){
        cnt++;
        Q.push(findOne());
        BFS();
    }
    cout<<cnt<<"\n";
}

int N;

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        init();
        solve();
    }

    return 0;
}