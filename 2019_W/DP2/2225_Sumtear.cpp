#include <iostream>

using namespace std;

//dp k n
int dp[201][201];

int n,k;

void init(){
    cin>>n>>k;
    for(int j=0;j<=n;j++){
        dp[1][j]=1;
    }
    for(int i=2;i<=k;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]+=dp[i-1][k];
                dp[i][j]=dp[i][j]%1000000000;
            }
        }
    }
    cout<<dp[k][n];
}


int main(){
    init();
    /*
    cout<<endl;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}