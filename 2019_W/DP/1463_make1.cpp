#include <iostream>

using namespace std;

int n;
int dp[1000001];

void init(){
    cin>>n;
    dp[1]=0; dp[2]=1; dp[3]=1;
    for(int i=4;i<=n;i++){
        int temp1=1000000;
        int temp2=1000000;
        int temp3=1000000;
        if(i%3==0) temp1=dp[i/3]+1;
        if(i%2==0) temp2=dp[i/2]+1;
        temp3 =dp[i-1]+1;
        if(temp1>temp2){
            if(temp2>temp3) dp[i]=temp3;
            else dp[i]=temp2;
        }
        else{
            if(temp1>temp3) dp[i]=temp3;
            else dp[i]=temp1;
        }
    }
}

int main(){
    init();
    cout<<dp[n]<<endl;
    return 0;
}