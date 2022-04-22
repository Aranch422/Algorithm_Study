#include <iostream>
#include <cmath>
using namespace std;

const int MAXNUM = 200001;
const int MAXPOW = 20;
int dp[MAXNUM][MAXPOW];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<MAXNUM;i++){
		for(int j=0;j<MAXPOW;j++){
			dp[i][j] = -1;
		}
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>dp[i][0];
	}
	for(int j=1;j<MAXPOW;j++){
		for(int i=1;i<=m;i++){
			int prev = dp[i][j-1];
			if(prev!=-1){
				dp[i][j] = dp[prev][j-1];
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		for(int i=0;a>0;i++){
			if(a%2 == 1){
				b=dp[b][i];
			}
			a = a/2;
		}
		cout<<b<<"\n";
	}
	return 0;
}