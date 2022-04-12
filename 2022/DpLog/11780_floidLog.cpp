#include <iostream>
#include <vector>

using namespace std;


int dp[101][101];
const int INF =987654321;

vector<int> Log[101][101];

int n,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=INF;
			if(i==j) dp[i][j]=0;
		}
	}
	while(m-->0){
		int s,e,c;
		if(s==e) continue;
		cin>>s>>e>>c;
		if(dp[s][e]>c){
			dp[s][e]=c;
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
					Log[i][j] = Log[i][k];
					Log[i][j].insert(Log[i][j].end(),k);
					Log[i][j].insert(Log[i][j].end(),Log[k][j].begin(),Log[k][j].end());
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==INF) dp[i][j]=0;
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==0) {
				cout<<"0\n";
				continue;
			}
			cout<<Log[i][j].size()+2<<" ";
			cout<<i<<" ";
			
			for(int l=0;l<Log[i][j].size();l++){
				cout<<Log[i][j][l]<<" ";
			}
			
			cout<<j<<" \n";
		}
	}
	return 0;
}