#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 10001;

int v,e;
int cnt = 0;

int dfn[MAX];
bool finished[MAX];

stack<int> myS;

vector<int> adj[MAX];
vector<vector<int>> SCCs;

int dfs(int now){
	myS.push(now);
	cnt++;
	dfn[now] = cnt;
	int ret = dfn[now];
	for(int next : adj[now]){
		if(dfn[next] == MAX){
			//not visited yet
			ret = min(ret, dfs(next));
		}
		else if(finished[next] == false){
			ret = min(ret,dfn[next]);
		}
	}
	if(ret == dfn[now]){
		vector<int> tempSCC;
		while(true){
			int top = myS.top();
			myS.pop();
			
			finished[top] = true;
			tempSCC.push_back(top);
			
			if(top == now){
				break;
			}
		}
		sort(tempSCC.begin(),tempSCC.end());
		SCCs.push_back(tempSCC);
	}
	return ret;
}

bool cmp(vector<int> a, vector<int> b){
	return *a.begin() < * b.begin();
}

int main(){
	cin>>v>>e;
	for(int i=1;i<=v;i++){
		dfn[i] = MAX;
		finished[i] = false;
	}
	
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	for(int i=1;i<=v;i++){
		if(finished[i] == false){
			dfs(i);
		}
	}
	
	sort(SCCs.begin(),SCCs.end(),cmp);
	cout<<SCCs.size()<<"\n";
	for(vector<int> item : SCCs){
		for(int elem : item){
			cout<<elem<<" ";
		}
		cout<<-1<<"\n";
	}
	
	return 0;
}