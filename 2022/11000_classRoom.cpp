#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

int n;
vector<pair<int,int>> classes;
priority_queue<int,vector<int>,greater<int>> pq;

bool compare(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}

void init(){
	cin>>n;
	for(int i=0; i<n;i++){
		int a,b;
		cin>>a>>b;
		pair<int,int> p = make_pair(a,b);
		classes.push_back(p);
	}
	sort(classes.begin(),classes.end(),compare);
}

int main(){
	init();
	pq.push(classes[0].second);
	for( int i=1; i<classes.size(); i++){
		int top = pq.top();
		if(top <= classes[i].first){
			top = classes[i].second;
			pq.pop();
			pq.push(top);
		}
		else{
			pq.push(classes[i].second);
		}
	}
	cout<<pq.size();

	return 0;
}
