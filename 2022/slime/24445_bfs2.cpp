#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100001;

int n,m,r;

vector<int> adj[MAX];

int order[MAX];

int cnt = 1;

bool cmp(int a,int b){
	return a>b;
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
		sort(adj[i].begin(),adj[i].end(),cmp);
		order[i] = 0;
	}
	
	queue<int> myQ;
	myQ.push(r);
	while(!myQ.empty()){
		int now = myQ.front();
		myQ.pop();
		if(order[now]!=0){
			continue;
		}
		order[now] = cnt++;
		for(int next : adj[now]){
			if(order[next] == 0){
				myQ.push(next);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<order[i]<<"\n";
	}
	return 0;
}