#include <iostream>

using namespace std;

int n;
int stair[301];

// 0 can jump 1,2 # 1 can jump only 2
//0 from 1, 1 from 0
int dp[301][2];

void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stair[i];
        for(int j=0;j<2;j++){
            dp[i][j]=0;
        }
    }
    dp[n][0]=stair[n];
    dp[n][1]=stair[n];
    dp[n-1][0]=-1; dp[n-1][1]=stair[n-1]+dp[n][0];

    for(int i=n-2;i>=0;i--){
        if(dp[i+2][0]>dp[i+2][1]) dp[i][0]=stair[i]+dp[i+2][0];
        else dp[i][0]=stair[i]+dp[i+2][1];
        
        if (dp[i+1][0]==-1) dp[i][1]=-1;
        else dp[i][1]=stair[i]+dp[i+1][0];
    }
}



int main(){
    init();
    if(dp[1][0]>dp[1][1]) {
        if(dp[1][0]>dp[2][1]) cout<<dp[1][0];
        else cout<<dp[2][1];
    }
    else{
        if(dp[1][1]>dp[2][1]) cout<<dp[1][1];
        else cout<<dp[2][1];
    }

    return 0;
}