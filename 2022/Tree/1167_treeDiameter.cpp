#include <iostream>
#include <vector>

using namespace std;

int v;
int diameter[100001];
vector<pair<int,int>> adj[100001];

int search(int now, int parent){
	vector<int> children;
	for(int i=0;i<adj[now].size();i++){
		int end,cost;
		end = adj[now][i].first;
		if(end == parent) continue;
		cost = adj[now][i].second;
		int len = cost + search(end,now);
		children.push_back(len);
	}
	int first = 0;
	int second =0;
	for(int i=0;i<children.size();i++){
		if(first<children[i]){
			second = first;
			first = children[i];
		}
		else if(second < children[i]){
			second = children[i];
		}
	}
	diameter[now] = first+second;
	children.clear();
	vector<int>().swap(children);
	return first;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>v;
	int start;
	int end,cost;
	for(int i=1;i<=v;i++){
		cin>>start;
		while(true){
			cin>>end;
			if(end==-1) break;
			cin>>cost;
			adj[start].push_back( make_pair(end,cost) );
		}
	}
	
	search(1,-1);
	int maximum = 0;
	for(int i=1;i<=v;i++){
		if(maximum<diameter[i]) maximum = diameter[i];
	}
	cout<< maximum;

	return 0;
}