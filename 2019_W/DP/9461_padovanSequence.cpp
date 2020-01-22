#include <iostream>

using namespace std;

int n;
long long dp[101];

void init(){
    cin>>n;
    dp[1]=1; dp[2]=1; dp[3]=1; dp[4]=2; dp[5]=2;
    for(int i=6;i<101;i++){
        dp[i]=dp[i-1]+dp[i-5];
    }
}

int main(){
    init();
    while(n>0){
        n--;
        int a;
        cin>>a;
        cout<<dp[a]<<endl;
    }
    return 0;
}