#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,k;

int cost[200001];

const int INF = 987654321;
const int LIM = 100000;
struct cmp{
	bool operator()(int a, int b){
		if(cost[a]>cost[b]){
			return true;
		}
		else if (cost[a]<cost[b]){
			return false;
		}
		else{
			return a>b;
		}
	}
};


priority_queue<int, vector<int>, cmp > myQ;

int main(){
	cin>>n>>k;
	for(int i=0;i<=LIM;i++){
		cost[i] = INF;
	}
	cost[n]=0;
	myQ.push(n);
	while(!myQ.empty()){
		int now = myQ.top();
		
		if( now == k ){
			cout<< cost[now];
			return 0 ;
		}
		myQ.pop();
		if(now*2<=LIM && cost[now*2]==INF){
			cost[now*2] = cost[now];
			if(now*2 == k){
				cout<<cost[now*2];
				return 0;
			}
			else{
				myQ.push(now*2);
			}
		}
		if(now+1<=LIM && cost[now+1]==INF){
			cost[now+1] = cost[now]+1;
			if(now+1 == k){
				cout<<cost[now+1];
				return 0;
			}
			else{
				myQ.push(now+1);
			}
		}
		if(now-1>=0 && cost[now-1]==INF){
			cost[now-1] = cost[now]+1;
			if(now-1 == k){
				cout<<cost[now-1];
				return 0;
			}
			else{
				myQ.push(now-1);
			}
		}
	}
	return 0;
}