#include <iostream>

using namespace std;

int n;
int num[2001];
int dp[2001][2001];


void init(){
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>num[i];
        dp[i][i]=1;
    }
    for(int i=1;i<n;i++){
        if(num[i]==num[i+1])
            dp[i][i+1]=1;
    }
    for(int gap=2;gap<=n-1;gap++){
        for(int i=1;i<=n;i++){
            int j=i+gap;
            if(j>n) break;
            if(num[i]==num[j]){
                if(dp[i+1][j-1]==1){
                    dp[i][j]=1;
                }
            }
        }
    }
}

void solve(){
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        cout<<dp[a][b]<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();
    return 0;
}