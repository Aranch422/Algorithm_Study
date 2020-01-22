#include <iostream>

using namespace std;

int n;
int num[1000][3];
int dp[1000][3];


void init(){
    cin>>n;

    //num dp init
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>num[i][j];
            dp[i][j]=num[i][j];
        }
    }

    //make dp
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                // i-1 row compare
                if(dp[i-1][1]>dp[i-1][2]){
                    dp[i][j]+=dp[i-1][2];
                }
                else{
                    dp[i][j]+=dp[i-1][1];
                }
            }

            else if(j==1){
                // i-1 row compare
                if(dp[i-1][0]>dp[i-1][2]){
                    dp[i][j]+=dp[i-1][2];
                }
                else{
                    dp[i][j]+=dp[i-1][0];
                }
            }

            else if(j==2){
                // i-1 row compare
                if(dp[i-1][0]>dp[i-1][1]){
                    dp[i][j]+=dp[i-1][1];
                }
                else{
                    dp[i][j]+=dp[i-1][0];
                }
            }
        }
    }
}

int min(int a, int b, int c){
    if(a<b){
        if(a<c) return a;
        else return c;
    }
    else{
        if(b<c) return b;
        else return c;
    }
}

int main(){
    init();
    cout<<min(dp[n-1][0],dp[n-1][1],dp[n-1][2]);
    return 0;
}