#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int n,m;
int dp[1001];
bool isVisit[1001];
int	before[1001];
vector<pair<int,int>> adj[1001];
struct compare{
	bool operator()(int a, int b){
		return dp[a]>dp[b];
	}
};

priority_queue<int,vector<int>,compare> myQ;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		dp[i]=INF;
		isVisit[i]=false;
	}
	while(m-->0){
		int s,e,c;
		cin>>s>>e>>c;
		if(s==e) continue;
		adj[s].push_back( {e,c} );
		//adj[e].push_back( {s,c} );
	}
	int start,end;
	cin>>start>>end;
	dp[start]=0;
	before[start]=-1;
	myQ.push( start );
	while(!myQ.empty()){
		int now = myQ.top();
		int cost = dp[now];
		myQ.pop();
		if(isVisit[now]) continue;
		isVisit[now]=true;
		if(now == end) break;
		for(int i=0;i<adj[now].size();i++){
			int next = adj[now][i].first;
			if(isVisit[next]) continue;
			int tempCost = adj[now][i].second;
			if(cost+tempCost<dp[next]){
				dp[next]=cost+tempCost;
				before[next]=now;
				myQ.push(next);
			}
		}
	}
	cout<<dp[end]<<"\n";
	vector<int> ans;
	while(before[end]!=-1){
		ans.push_back(end);
		end = before[end];
	}
	ans.push_back(end);
	cout<<ans.size()<<"\n";
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<" ";
	}
	return 0;
}