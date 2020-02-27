#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int board[30][30];
vector<int> res;
queue<pair<int,int>> Q;

int BFScnt=0;

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            board[i][j]=s[j]-48;
        }
    }
}

pair<int,int> findOne(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

bool isInside(int x,int y){
    return (0<=x&&x<n&&0<=y&&y<n);
}

void BFS(){
    if(Q.empty()) return;

    int r,c;

    pair<int,int> start = Q.front();
    Q.pop();
    r= start.first, c=start.second;
    while(board[r][c]==0){
        if(Q.empty()) return;
        pair<int,int> start = Q.front();
        Q.pop();
        r= start.first, c=start.second;
    }



    BFScnt++;
    //cout<<r<<" "<<c<<" "<<BFScnt<<endl;
    board[r][c]=0;

    for(int i=0;i<4;i++){
        int newr=r+dr[i];
        int newc=c+dc[i];
        if(isInside(newr,newc)){
            if(board[newr][newc]==1){
                Q.push(make_pair(newr,newc));
            }
        }
    }
    BFS();
}

void solve(){
    Q.push(findOne());
    BFS();
    res.push_back(BFScnt);
    BFScnt=0;
}

int cnt=0;

int main(){
    init();

    while(findOne().first!=-1){
        cnt++;
        //cout<<cnt<<" "<<findOne().first<<" "<<findOne().second<<endl;
        solve();

    }
    cout<<cnt<<'\n';
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<'\n';
    }
    return 0;
}