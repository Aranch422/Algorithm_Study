#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;

int n,m,r;

vector<int> adj[MAX];

int cnt = 1;

int order[MAX];

void dfs(int now){
	if(order[now]!=0){
		return;
	}
	order[now] = cnt++;
	for(int next : adj[now]){
		dfs(next);
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m>>r;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++){
		sort(adj[i].begin(),adj[i].end());
		order[i] = 0;
	}
	
	dfs(r);
	
	for(int i=1;i<=n;i++){
		cout<<order[i]<<"\n";
	}
	
	return 0;
}