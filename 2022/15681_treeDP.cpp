#include <iostream>
#include <vector>

using namespace std;

int n,r,q;

vector<int> adj[100001];
int dp[100001];

int numOfSubtree(int parent, int me){
	if(dp[me] !=-1) return dp[me];
	int ans = 1;
	for(int i=0;i<adj[me].size();i++){
		if(adj[me][i] == parent) continue;
		ans += numOfSubtree(me,adj[me][i]);
	}
	dp[me] = ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>r>>q;
	for(int i=0;i<=n;i++){
		dp[i] = -1;
	}
	for(int i=0;i<n-1;i++){
		int s,e;
		cin>>s>>e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	numOfSubtree(-1,r);
	for(int i=0;i<q;i++){
		int qq;
		cin>>qq;
		cout<<dp[qq]<<"\n";
	}
	return 0;
}