#include <iostream>

using namespace std;

int n;
int dp[1000001];

void init(){
    cin>>n;
    dp[1]=1; dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=-1;
    }
}

int cal(int k){
    if(dp[k]!=-1) return dp[k];
    dp[k-1]=cal(k-1);
    dp[k-2]=cal(k-2);
    dp[k]=dp[k-1]+dp[k-2];
    dp[k]=dp[k]%15746;
    return dp[k];
}

int main(){
    init();
    cout<<cal(n);
    return 0;
}