#include <iostream>

using namespace std;

int dp[1001];

int n;

void init(){
    cin>>n;
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]*2;
        dp[i]=dp[i]%10007;
    }
}

int main(){
    init();
    cout<<dp[n];
    return 0;
}