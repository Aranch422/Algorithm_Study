#include <iostream>

using namespace std;

long long n,m;
long long num[100001];
long long dp[100001];

void init(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>num[i];
        dp[i]=num[i]+dp[i-1];
    }
}

void solve(){
    while(m>0){
        m--;
        long long a,b;
        cin>>a>>b;
        cout<<dp[b]-dp[a-1]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    init();
    solve();

    return 0;

}