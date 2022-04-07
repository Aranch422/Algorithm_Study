#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dp[101][10001];

int n,m,k;

int T;

struct edge{
	int start,end;
	int cost;
	int time;
};
vector<edge> adj[101];

struct node{
	int num;
	int cost;
	int time;
	node(int a,int b,int c) : num(a), cost(b), time(c){}
	bool operator<(const node n) const{
		return this->time > n.time;
	}
};

priority_queue<node> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T-->0){
		cin>>n>>m>>k;
		priority_queue<node>().swap(pq);
		for(int i=0;i<n;i++){
			/*
			for(int j=0;j<adj[i].size();j++){
				delete adj[i][j];
				adj[i][j]=0;
			}
			*/
			adj[i].clear();
			vector<edge>().swap(adj[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp[i][j]=2000000000;
			}
		}
		// get edges
		for(int i=0;i<k;i++){
			int start,end,cost,time;
			cin>>start>>end>>cost>>time;
			adj[start].push_back({start,end,cost,time});
			/*
			edge* E2 = new edge();
			E2.start =end;
			E2.end = start;
			E2.cost=cost;
			E2.time=time;
			adj[end].push_back(E2);
			*/
		}
		/*
		for(int i=1;i<=n;i++){
			for(int j=0;j<adj[i].size();j++){
				cout<<adj[i][j].end<<" ";
			}
			cout<<endl;
		}
		*/
		dp[1][0]=0;
		pq.push({1,0,0});
		while(!pq.empty()){
			//cout<<pq.size()<<" ";
			node now = pq.top();
			pq.pop();
			if(dp[now.num][now.cost]<now.time) continue;
			for(int i=0;i<adj[now.num].size();i++){
				int end = adj[now.num][i].end;
				int cost = adj[now.num][i].cost;
				int time = adj[now.num][i].time;
				
				int newCost = now.cost+ cost;
				int newTime = now.time+ time;
				
				if(newCost>m) continue;
				if(dp[end][newCost]<=newTime) continue;
				if(end!=n) pq.push({end,newCost,newTime});
				for(int j=newCost;j<=m;j++){
					if(dp[end][j]<newTime) break;
					dp[end][j] = newTime;
				}
			}
		}
		
		int minimum=2000000000;
		for(int i=0;i<=m;i++){
			if(minimum>dp[n][i]){
				minimum = dp[n][i];
			}
		}
		
		if(minimum!=2000000000) {cout<<minimum<<endl;}
		else cout<<"Poor KCM\n";
		/*
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		*/
	}
	return 0;
}