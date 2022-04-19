#include <iostream>

using namespace std;

int dp[1001][1001];

int n,k;

int setDP(int a,int b){
	if(a<0 || b<0) return 0;
	if(dp[a][b]!=-1) return dp[a][b];
	dp[a][b] =(setDP(a-2,b-1)+setDP(a-1,b))%1000000003;
	return dp[a][b];
}

int main(){
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0) dp[i][j]=1;
			else if(j==1) dp[i][j]=i;
			else {
				dp[i][j]=-1;
			}
		}
	}
	dp[0][1] =0;
	setDP(n,k);
	cout<<(dp[n-3][k-1]+dp[n-1][k])%1000000003<<endl;

	return 0;
}