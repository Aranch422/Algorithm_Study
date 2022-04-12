#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> myQ;
vector<int> adj[1000001];
int root[1000001];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		root[i]=-1;
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	myQ.push(1);
	while(!myQ.empty()){
		int front = myQ.front();
		myQ.pop();
		for(int i=0;i<adj[front].size();i++){
			if(root[adj[front][i]]==-1){
				root[adj[front][i]]=front;
				myQ.push(adj[front][i]);
			}
		}
	}
	for(int i=2;i<=n;i++){
		cout<<root[i]<<"\n";
	}
	return 0;
}