#include <iostream>
#include <queue>

using namespace std;

int r,c;

int board[1000][1000];
int num=0;
int res;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

queue<pair<pair<int,int>,int>> Q;

void init(){
    cin>>c>>r;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            if(board[i][j]==0){
                num++;
            }
            if(board[i][j]==1){
                Q.push(make_pair(make_pair(i,j),0));
            }
        }
    }
}

void solve(){
    while(!Q.empty()){
        pair<pair<int,int>,int> temp =Q.front();
        //cout<<temp.first.first<<" "<<temp.first.second<<"\n";
        int day=temp.second;
        res=day;
        for(int i=0;i<4;i++){
            int newR=temp.first.first+dx[i];
            int newC=temp.first.second+dy[i];
            //in range
            if(0<=newR&&newR<r&&0<=newC&&newC<c){
                //cout<<newR<<" "<<newC<<"\n";
                if(board[newR][newC]==0){
                    num--;
                    board[newR][newC]=1;
                    Q.push(make_pair(make_pair(newR,newC),day+1));
                }
            }
        }
        Q.pop();
    }
    if(num==0) cout<<res;
    else cout<<-1;
}

int main(){
    init();
    solve();
    /*
    cout<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<num;
    */
    return 0;
}