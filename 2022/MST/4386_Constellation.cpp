#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n;

pair<double,double> coor[101];


bool isVisit[101];

struct edge{
	int start;
	int end;
	double cost;
	edge(int s,int e,double c) : start(s),end(e),cost(c) {}
};

struct cmp{
	bool operator()(edge a, edge b){
		return a.cost>b.cost;
	}
};

priority_queue<edge,vector<edge>,cmp> dist;

void addEdge(int i){

	for(int j=1;j<=n;j++){
		if(i==j) continue;
		if(isVisit[j]) continue;
		double x1 = coor[i].first;
		double y1 = coor[i].second;

		double x2 = coor[j].first;
		double y2 = coor[j].second;
		dist.push( edge(i,j,sqrt(pow(x2-x1,2)+pow(y2-y1,2)) ));
	}

}


int main(){
	cout<<fixed;
	cout.precision(5);
	cin>>n;
	for(int i=1;i<=n;i++){
		string sa,sb;
		cin>>sa>>sb;
		
		double a = stod(sa);
		double b= stod(sb);
		coor[i] = {a,b};
		isVisit[i] = false;
	}
	
	addEdge(1);
	isVisit[1] = true;
	
	int now =1;
	int visitCnt = 1;
	double answer = 0;
	while(visitCnt<n){
		int end = dist.top().end;
		double cost = dist.top().cost;
		
		while(isVisit[end]){
			end = dist.top().end;
			cost = dist.top().cost;
			dist.pop();
		}
		dist.pop();
		isVisit[end] = true;
		answer += cost;
		visitCnt++;
		addEdge(end);
	}
	cout<<answer;
	return 0;
}