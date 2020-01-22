#include <iostream>

using namespace std;

int n;
int board[500][500];
int dp[500][500];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>board[i][j];
            dp[i][j]=board[i][j];
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j==0) dp[i][0]+=dp[i-1][0];
            else if(j==i) dp[i][j]+=dp[i-1][j-1];
            else{
                if(dp[i-1][j-1]>dp[i-1][j]){
                    dp[i][j]+=dp[i-1][j-1];
                }
                else dp[i][j]+=dp[i-1][j];
            }
        }
    }
}


int main(){
    init();
    if(n==1) {
        cout<<board[0][0];
        return 0;
    }
    int max=dp[n-1][0];
    for(int j=1;j<n;j++){
        if(max<dp[n-1][j]) max=dp[n-1][j];
    }
    cout<<max;
    return 0;
}