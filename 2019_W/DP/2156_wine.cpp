#include <iostream>

using namespace std;

int n;
int drink[10000];
int dp[10000][2];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>drink[i];
    }
    dp[0][0]=drink[0]; dp[0][1]=drink[0];
    if(n!=1) dp[1][0]=drink[1]; dp[1][1]=drink[0]+drink[1];

    int Max=0;
    for(int i=2;i<n;i++){
        if(dp[i-2][0]>dp[i-2][1]) {
            if(Max<dp[i-2][0]) Max=dp[i-2][0];
            dp[i][0]=drink[i]+Max;
        }
        else {
            if(Max<dp[i-2][1]) Max=dp[i-2][1];
            dp[i][0]=drink[i]+Max;
        }
        dp[i][1]=dp[i-1][0]+drink[i];
    }
}


int main(){
    init();
    if(n==1) {
        cout<<drink[0];
        return 0;
    }
    if(dp[n-1][0]>dp[n-1][1]){
        if(dp[n-1][0]>dp[n-2][1]) cout<<dp[n-1][0];
        else cout<<dp[n-2][1];
    }
    else{
        if(dp[n-1][1]>dp[n-2][1]) cout<<dp[n-1][1];
        else cout<<dp[n-2][1];
    }
    
    /*
    for(int i=0;i<n;i++){
        cout<<endl;
        cout<<drink[i] <<": "<<dp[i][0]<<" "<<dp[i][1];
    }
    */
    return 0;
}