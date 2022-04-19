#include <iostream>

using namespace std;

long long N,K;

long long dp[1001][1001][2];

long long find(long long n, long long k, long long choose){
	if(k<0 || n<0) return 0;
	//cout<<n<<" "<<k<<" "<<choose<<" ";
	if(dp[n][k][choose]!= -1) {
		//cout<<dp[n][k][choose]<<endl;
		return dp[n][k][choose];
	}
	long long ans;
	if(choose == 1){
		ans = find(n-2,k-1,0);
		dp[n][k][choose] = ans;
		//cout<<ans<<endl;
		return ans;
	}
	else{
		ans = find(n-2,k-1,1)+2*find(n-3,k-1,0)+find(n-2,k,0);
		dp[n][k][choose] = ans;
		//cout<<ans<<endl;
		return ans;
 	}
}

int main(){
	cin>>N>>K;
	for(long long i=0;i<=N;i++){
		for(long long j=0;j<=N;j++){
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
	for(long long i=0;i<=N;i++){
		for(long long j=0;j<=N;j++){
			if(j==1){
				dp[i][j][0] = i-1;
				dp[i][j][1] = 1;
			}
			else if(j==0) dp[i][j][0]=0;
			else if(i==2*j){
				dp[i][j][0]=0;
				dp[i][j][1]=2;
			}
			else if(i<2*j){
				dp[i][j][0]=0;
				dp[i][j][1]=0;
			}
		}
	}
	cout<<(find(N,K,0)+find(N,K,1))%1000000003;
	return 0;
}