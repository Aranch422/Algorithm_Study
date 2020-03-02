#include <iostream>

using namespace std;

int n;

int dp[501][501];

int page[501];
int pageDP[501][501];

int subsum(int i,int j){
    int ret=0;
    if(pageDP[i][j]!=0) return pageDP[i][j];
    for(int idx=i;idx<=j;idx++){
        ret+=page[idx];
    }
    pageDP[i][j]=ret;
    return ret;
}

void init(){
    
    int k;
    cin>>k;
    
    //page, dp, pageDP initialize with 0
    for(int i=1;i<=k;i++){
        page[i]=0;
        for(int j=1;j<=k;j++){
            dp[i][j]=0;
            pageDP[i][j]=0;
        }
    }
    
    
    for(int i=1;i<=k;i++){
        cin>>page[i];
    }
    if(k==1){
        cout<<page[1]<<'\n';
        return;
    }
    //for j<i
    for(int i=1;i<=k;i++){
        for(int j=i-1;j>=1;j--){

            if(j==i-1){
                dp[i][j]=page[i]+page[j];
                continue;
            }
            int MIN=987654321;
            for(int mid=i;mid>j;mid--){
                if(dp[i][mid]+dp[mid-1][j]+subsum(j,i)<MIN)
                    MIN=dp[i][mid]+dp[mid-1][j]+subsum(j,i);
            }
            dp[i][j]=MIN;
        }
    }
    //for i<j
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i<j) dp[i][j]=dp[j][i];
        }
    }


    //for show
    /*
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    cout<<dp[1][k]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    while(n>0){
        n--;
        init();
    }
    return 0;
}