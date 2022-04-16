#include <iostream>

using namespace std;

int n;
const int INF = 987654321;

int adj[20][20];

int dp[1<<20];

int getMinCost(int next, int Bits){
	if(next>=n) return 0;
	if(dp[Bits]!= INF){
		return dp[Bits];
	}
	for(int i=0;i<n;i++){
		if(Bits & 1<<i) {
			continue;
		}
		else{
			int newBits = Bits | 1<<i;
			if(dp[Bits] > getMinCost(next+1,newBits) + adj[next][i]){
				dp[Bits]=getMinCost(next+1,newBits) + adj[next][i];
			}
		}
	}
	return dp[Bits];
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>adj[i][j];
		}
	}
	for(int i=0;i<(1<<20);i++){
		dp[i] = INF;
	}
	cout<<getMinCost(0,0);

	return 0;
}