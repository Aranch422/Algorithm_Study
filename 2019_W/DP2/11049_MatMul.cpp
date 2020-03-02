#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    pair<int,int> Mat[501];
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        Mat[i]=make_pair(a,b);
    }

    int dp[501][501]={};

    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            int MIN=987654321;
            for(int mid=i;mid>j;mid--){
                int cost=dp[i][mid]+dp[mid-1][j]+Mat[j].first*Mat[mid].first*Mat[i].second;
                if(cost<MIN) MIN=cost;
            }
            dp[i][j]=MIN;
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    cout<<dp[n][1];
    return 0;
}