#include <iostream>


using namespace std;

int n;
const int INF = 987654321;

int adj[16][16];
int dp[16][1<<16];



int getLeastCost(int last, int maskedBits){
	if(maskedBits==(1<<n)-1){
		if(adj[last][0] == 0) return INF;
		return adj[last][0];
	}
	if(dp[last][maskedBits]!=INF){
		return dp[last][maskedBits];
	}

	for(int i=0;i<n;i++){
		if(maskedBits & (1<<i)){
			continue;
		}
		else if(adj[last][i] == 0){
			continue;
		}
		else{
			int nextMaskedBits = maskedBits | (1<<i);
			int val= getLeastCost(i, nextMaskedBits) + adj[last][i];	

			if(dp[last][maskedBits] > val){
				dp[last][maskedBits] = val;
			}
		}
	}
	return dp[last][maskedBits];
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>adj[i][j];
		}
	}
	
	for(int i=0;i<(1<<16);i++){
		for(int j=0;j<16;j++){
			dp[j][i] = INF;	
		}
	}
	cout<<getLeastCost(0,1);
	return 0;
}