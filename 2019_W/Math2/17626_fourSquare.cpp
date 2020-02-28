#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> V;
int dp[50001];

int MAX=55;

int min(int a,int b){
    return (a<b)? a:b;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        dp[i*i]=1;
        V.push_back(i*i);
    }
    for(int i=2;i<=n;i++){
        int cnt=MAX;
        //cout<<i<<" ";
        for(int j=0;V[j]<=i&&j<V.size();j++){
            cnt=min(cnt,dp[i-V[j]]);
            //cout<<cnt<<" ";
        }
        dp[i]=cnt+1;
        //cout<<dp[i]<<"\n";
    }
    /*
    for(int i=0;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" "; 
    }
    cout<<endl;
    */
    cout<<dp[n];
    return 0;
}