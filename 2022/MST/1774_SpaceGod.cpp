#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n,m;
pair<long long,long long> coor[1001];

long long parent[1001];


long long find(long long a){
	long long ori =a;
	while(parent[a]!=-1){
		a= parent[a];
	}
	long long root =a;
	a = ori;
	while(parent[a]!=-1){
		ori = a;
		a = parent[a];
		parent[ori] = root;
	}
	return root;
}

void Union(long long a, long long b){
	a = find(a);
	b = find(b);
	
	if(a!=b){
		parent[a] = b;
	}
}

bool isInSame(long long a, long long b){
	return find(a) == find(b);
}

struct edge{
	long long start;
	long long end;
	double cost;
	edge(long long s, long long e,double c) : start(s), end(e), cost(c) {}

	bool operator<(edge e){
		return this->cost<e.cost;
	}
};

vector<edge> E;

int main(){
	cout<<fixed;
	cout.precision(2);
	edge E1 = edge(1,1,2);
	edge E2 = edge(1,1,3);
	cout<<(E1<E2);
	return 0;
	cin>>n>>m;
	for(long long i=0;i<=n;i++){
		parent[i] = -1;
	}
	for(long long i=1;i<=n;i++){
		long long x,y;
		cin>>x>>y;
		coor[i] = {x,y};
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j) continue;
			double dist = sqrt(pow(coor[i].first-coor[j].first,2)+ pow(coor[i].second-coor[j].second,2));
			E.push_back(edge(i,j,dist));
		}
	}
	
	sort(E.begin(),E.end());
	
	for(long long i=0;i<m;i++){
		long long s,e;
		cin>>s>>e;
		Union(s,e);
	}
	
	double totalCost =0;
	for(long long i=0;i<E.size();i++){
		long long start = E[i].start;
		long long end = E[i].end;
		double cost = E[i].cost;

		if(!isInSame(start,end)){
			totalCost += cost;
			Union(start,end);
		}
	}
	cout<<totalCost;
	return 0;
}