#include <iostream>
#include <queue>

using namespace std;

// r,c,break?,cnt
queue<pair<pair<int,int>,pair<int,int>>> Q;

int board[1000][1000];
int dp[1000][1000][2];

int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};

int n,m;

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
    return (0<=r&&0<=c&&r<n&&c<m);
}

void BFS(){
    while(!Q.empty()){
        int r=Q.front().first.first;
        int c=Q.front().first.second;
        int isbreak = Q.front().second.first;
        int cnt=Q.front().second.second;
        //cout<<"BFS called\n";
        //cout<<r<<" "<<c<<" "<<isbreak<<" "<<cnt<<endl;
        Q.pop();
        if(isbreak==1){
            if(dp[r][c][1]!=0) continue;
            dp[r][c][1]=cnt+1;
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(isInside(newr,newc)){
                    if(board[newr][newc]==0&&dp[newr][newc][1]==0){
                        Q.push(make_pair(make_pair(newr,newc),make_pair(1,cnt+1)));
                    }
                }
            }
        }
        else{
            if(dp[r][c][0]!=0) continue;
            else{
                dp[r][c][0]=cnt+1;
                for(int i=0;i<4;i++){
                    int newr=r+dr[i];
                    int newc=c+dc[i];
                    if(isInside(newr,newc)){
                        if(board[newr][newc]==0&&dp[newr][newc][0]==0){
                            Q.push(make_pair(make_pair(newr,newc),make_pair(0,cnt+1)));
                        }
                        if(board[newr][newc]==1&&dp[newr][newc][1]==0){
                            Q.push(make_pair(make_pair(newr,newc),make_pair(1,cnt+1)));
                        }
                    }
                }
            }
        }
    }
    
}

void solve(){
    Q.push(make_pair(make_pair(0,0),make_pair(0,0)));
    BFS();
}

int main(){
    init();
    solve();
    if(dp[n-1][m-1][1]==0&&dp[n-1][m-1][0]==0) cout<<-1;
    else if(dp[n-1][m-1][0]==0) cout<<dp[n-1][m-1][1];
    else if(dp[n-1][m-1][1]==0) cout<<dp[n-1][m-1][0];
    else{
        if(dp[n-1][m-1][0]<dp[n-1][m-1][1]) cout<<dp[n-1][m-1][0];
        else cout<<dp[n-1][m-1][1];
    }
    /*
    cout<<"DP 0 called\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j][0]<<" ";
        }
        cout<<endl;
    }
    cout<<"DP 1 called\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j][1]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}