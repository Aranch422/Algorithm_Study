#include <iostream>
#include <algorithm>

using namespace std;

int n;

int dp[3]={};
int res[3]={};
int num[3]={};
int dp2[3]={};
int res2[3]={};

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[0]>>num[1]>>num[2];
        res[0]=max(dp[0],dp[1]);
        res[0]+=num[0];

        res[1]=max(dp[0],dp[1]);
        res[1]=max(res[1],dp[2]);
        res[1]+=num[1];

        res[2]=max(dp[1],dp[2]);
        res[2]+=num[2];

        dp[0]=res[0];
        dp[1]=res[1];
        dp[2]=res[2];

        //min
        res2[0]=min(dp2[0],dp2[1]);
        res2[0]+=num[0];

        res2[1]=min(dp2[0],dp2[1]);
        res2[1]=min(res2[1],dp2[2]);
        res2[1]+=num[1];

        res2[2]=min(dp2[1],dp2[2]);
        res2[2]+=num[2];

        dp2[0]=res2[0];
        dp2[1]=res2[1];
        dp2[2]=res2[2];
    }
    int M=max(dp[0],dp[1]);
    M=max(M,dp[2]);
    int m=min(dp2[0],dp2[1]);
    m=min(m,dp2[2]);
    cout<<M<<" "<<m;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    return 0;
}