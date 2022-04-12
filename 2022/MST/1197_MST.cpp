#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v,e;

bool isVisit[10001];
int visitCnt = 1;
int totalCost = 0;
struct edge{
	int start;
	int end;
	int cost;
	edge(int s,int e,int c) : start(s), end(e), cost(c) {}
	
	bool operator<(edge e){
		return this->cost<e.cost;
	}
};

vector<edge> E;

int parent[10001];

int find(int a){
	int ori = a;
	while(parent[a]!=-1){
		a= parent[a];
	}
	int root =a;
	a=ori;
	while(parent[a]!=-1){
		ori =a;
		a = parent[a];
		parent[ori]=root;
	}
	return root;
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		parent[a]=b;
		return true;
	}
	else{
		return false;
	}
}

int main(){
	cin>>v>>e;
	for(int i=0;i<e;i++){
		int s,e,c;
		cin>>s>>e>>c;
		E.push_back(edge(s,e,c));
	}
	sort(E.begin(),E.end());
	for(int i=1;i<=v;i++){
		parent[i] = -1;
	}
	int start = E[0].start;
	int end = E[0].end;
	int cost = E[0].cost;
	
	Union(start,end);
	totalCost += cost;
	visitCnt++;
	for(int i=1;i<e;i++){
		start = E[i].start;
		end = E[i].end;
		cost = E[i].cost;
		if(Union(start,end)){
			totalCost+=cost;
			visitCnt++;
			if(visitCnt>=v){
				break;
			}
		}
	}
	cout<<totalCost;
	return 0;
}