#include <iostream>
#include <string.h>

using namespace std;

long long dp[10001];

int N;

void init(){
    cin>>N;
    memset(dp,-1,sizeof(dp));
    dp[0]=0ll; dp[1]=1ll;
}

long long fib4(int n){
    if(dp[n]!=-1) return dp[n];
    else{
        dp[n]=fib4(n-1)+fib4(n-2);
        return dp[n];
    }
}

int main(){
    init();
    cout<<fib4(N);
    return 0;
}