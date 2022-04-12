#include <iostream>
#include <vector>
using namespace std;

int n;
int diameter[10001];
vector<pair<int,int>> adj[10001];

int search(int now){
	vector<int> children;
	for(int i=0;i<adj[now].size();i++){
		int end,cost;
		end = adj[now][i].first;
		cost = adj[now][i].second;
		children.push_back( cost+search(end) );
	}
	int first =0;
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
	return first;
}


int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int start,end,cost;
		cin>>start>>end>>cost;
		adj[start].push_back( make_pair(end,cost) );
	}
	search(1);
	
	int maximum =0;
	for(int i=1;i<=n;i++){
		if(maximum < diameter[i]){
			maximum = diameter[i];
		}
	}
	cout<<maximum;
	return 0;
}