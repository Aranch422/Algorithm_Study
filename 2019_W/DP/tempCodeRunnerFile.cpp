#include <iostream>
#include <algorithm>

using namespace std;

int n;

int cost[1001];

// 
int dp[1001][1001]={};

void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int j=1;j<=n;j++){
        dp[1][j]=dp[1][j-1]+cost[1];
    }    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j-i<0) {
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-i]+cost[i]);
                dp[i][j]=max(dp[i][j],dp[i][j-i]+cost[i]);
            }
        }
    }
    cout<<dp[n][n]<<endl;
}

int main(){
    init();

    /*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}