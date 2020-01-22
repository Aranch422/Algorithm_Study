#include <iostream>

using namespace std;

int n;

long long dp[101][11];

void init(){
    cin>>n;
    //first row
    for(int i=1;i<10;i++){
        dp[1][i]=1;
    }
    dp[1][10]=9;

    dp[0][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][10]=0;
        for(int j=1;j<10;j++){
            if(j==1) dp[i][1]=(dp[i-1][2]+dp[i-2][1])%1000000000;
            else if(j==9) dp[i][9]=dp[i-1][8];
            else{
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
            }
            dp[i][10]=(dp[i][10]+dp[i][j])%1000000000;
        }
        dp[i][10]=dp[i][10]%1000000000;
    }
}

int main(){
    init();
    cout<<dp[n][10];
    return 0;
}