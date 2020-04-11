#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N,M;

int board[101][101];

void init(){
    cin>>N>>M;
    memset(board,0,sizeof(board));
    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        board[i][i]=1;
        board[a][b]=1;
        board[b][a]=1;
    }
}

void solve(){
    for(int i=1;i<=N;i++){
        for(int cnt=2;cnt<N;cnt++){
            vector<int> temp;
            for(int j=1;j<=N;j++){
                if(board[i][j]==0){
                    for(int k=1;k<=N;k++){
                        if(board[j][k]==1&&j!=k){
                            if(board[i][k]!=0&&i!=k){
                                temp.push_back(j);
                            }
                        }
                    }
                }
            }
            for(int j=0;j<temp.size();j++){
                board[i][temp[j]]=cnt;
            }
        }
    }
    int linesum[101]={};
    int KBmin=300000;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            linesum[i]+=board[i][j];
        }
    }
    int result=0;
    for(int i=1;i<=N;i++){
        if(KBmin>linesum[i]){
            KBmin=linesum[i];
            result=i;
        }
    }

    cout<<result;
    /*
    cout<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<< board[i][j]<<' ';
        }
        cout<<linesum[i]<<"\n";
    }
    */
}

int main(){
    init();
    solve();
    return 0;
}