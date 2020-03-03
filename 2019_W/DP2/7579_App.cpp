#include <iostream>
#include <algorithm>

using namespace std;

int mem[101]={};
int cost[101]={};

int dp[101][10001]={};

void init(){
    int n;
    int target;
    cin>>n>>target;
    for(int i=1;i<=n;i++){
        cin>>mem[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }   

    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            if(j-cost[i]<0) {
                dp[i][j]=dp[i-1][j];
            }
            else dp[i][j]=max(dp[i-1][j-cost[i]]+mem[i],dp[i-1][j]);
        }
    }

    for(int j=0;j<=10000;j++){
        if(dp[n][j]>=target){
            cout<<j;
            return;
        }
    }

}


int main(){
    init();
    /*
    for(int i=0;i<=5;i++){
        for(int j=0;j<=15;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}