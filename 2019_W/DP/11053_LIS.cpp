#include <iostream>

using namespace std;

int n;
int arr[1000];
int dp[1000];
int dpMax;
int Max;

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=1;i<n;i++){
        Max=0;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]) {
                if(dp[j]>Max) Max=dp[j];
            }
        }
        dp[i]=Max+1;
        if(dp[i]>dpMax) dpMax=dp[i]; 
    }
    if(dpMax==0) dpMax=1;
}

int main() {
    init();
    cout<<dpMax;
    /*
    for(int i=0;i<n;i++){
        cout<<endl;
        cout<<arr[i]<<" "<<dp[i];
    }
    */
    return 0;
}