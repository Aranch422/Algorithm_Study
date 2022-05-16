#include <iostream>
#include <cmath>

using namespace std;

int dp[53][53];

int comb(int n,int r){
	if(dp[n][r] != -1){
		return dp[n][r];
	}
	if(r==0){
		dp[n][r] = 1;
		return dp[n][r];
	}
	if(r == 1){
		dp[n][r] = n;
		return dp[n][r];
	}
	if(n==r){
		dp[n][r] = 1;
		return dp[n][r];
	}
	dp[n][r] = comb(n-1,r-1)+comb(n-1,r);
	dp[n][r] %=10007;
	return dp[n][r];
}

int main(){
	
	for(int i=0;i<53;i++){
		for(int j=0;j<53;j++){
			dp[i][j]= -1;
		}
	}
	
	int N;
	cin>>N;
	int ans =0;
	for(int i=1;N-i*4>=0;i++){
		ans += comb(13,i)*comb(52-i*4,N-i*4)*pow(-1,i+1);
		ans %=10007;
	}
	if(ans<0){
		ans+=10007;
	}
	cout<<ans;

	return 0;
}