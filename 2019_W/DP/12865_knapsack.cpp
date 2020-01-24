#include <iostream>
#include <algorithm>

using namespace std;

int n; int k;
pair<int,int> thing[101];
int dp[101][100001];

bool check(pair<int,int> a,pair<int ,int>b){
    if(a.first<b.first) return true;
    else return false;
}


void init(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        thing[i+1]=make_pair(a,b);
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }
}

void solve(){
    int Max=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(thing[i].first<=j){
                int before;
                if (j-thing[i].first<0) before=0;
                else before = j-thing[i].first;
                if(thing[i].second+dp[i-1][before]>dp[i-1][j]) dp[i][j]= thing[i].second+dp[i-1][before];
                else dp[i][j]=dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
            if(Max<dp[i][j]) Max=dp[i][j];
        }
    }
    cout<<Max;
}

int main(){
    init();
    solve();
    
    /*
    for(int i=1;i<=n;i++){
        cout<<endl;
        for(int j=1;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
    }
    */
    
    return 0;
}