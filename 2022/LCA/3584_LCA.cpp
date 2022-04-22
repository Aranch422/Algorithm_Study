#include <iostream>
#include <cmath>

using namespace std;

int dp[10001][15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			for(int j=0;j<15;j++){
				dp[i][j] = -1;
			}
		}
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			dp[b][0] = a;
		}
		for(int j=1;j<15;j++){
			for(int i=1;i<=n;i++){
				int prev = dp[i][j-1];
				if(prev !=-1){
					dp[i][j] = dp[prev][j-1];
				}
			}
		}
		
		int root;
		for(int i=1;i<=n;i++){
			if(dp[i][0]== -1){
				root = i;
				break;
			}
 		}
		int a,b;
		cin>>a>>b;
		int tempA= a;
		int tempB= b;
		int levelA = 0;
		for(int i=14;i>=0;i--){
			if(dp[tempA][i]!= -1){
				tempA = dp[tempA][i];
				levelA += pow(2,i);
			}
			if(tempA == root) break;
		}
		
		int levelB = 0;
		for(int i=14;i>=0;i--){
			if(dp[tempB][i]!= -1){
				tempB = dp[tempB][i];
				levelB += pow(2,i);
			}
			if(tempB == root) break;
		}
		
		if(levelA>levelB){
			swap(a,b);
			swap(levelA,levelB);
		}
		int levelGap = levelB-levelA;
		for(int i=0;levelGap>0;i++){
			if(levelGap%2 == 1){
				b = dp[b][i];
			}
			levelGap = levelGap/2;
		}

		if(a==b){
			cout<<a<<'\n';
		}
		else{
			for(int i=14;i>=0;i--){
				if(dp[a][i] != -1 && dp[a][i] != dp[b][i]){
					a = dp[a][i];
					b = dp[b][i];
				}
			}
			cout<<dp[a][0]<<'\n';
		}
		
	}
	return 0;
}