#include <iostream>

using namespace std;

int n;
int num[100000];
int dp[100000];


void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    dp[0]=num[0];
    for(int i=1;i<n;i++){
        if(dp[i-1]>=0) dp[i]=dp[i-1]+num[i];
        else dp[i]=num[i];
    }
}

int main(){
    init();
    int max=-100000000;
    for(int i=0;i<n;i++){
        if(max<dp[i]) max=dp[i];
        //cout<<dp[i]<<" ";
    }
    cout<<max;
    return 0;
}