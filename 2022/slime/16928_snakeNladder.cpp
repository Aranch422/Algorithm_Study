#include <iostream>
#include <queue>

using namespace std;

int n,m;

int board[101];
int dist[101];

int main(){
	cin>>n>>m;
	for(int i=0;i<101;i++){
		dist[i]=1000000;
		board[i] = i;
	}
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		board[a] = b;
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		board[a] = b;
	}
	int now = 1;
	dist[now] = 0;
	queue<int> myQ;
	myQ.push(now);
	bool endFlag = false;
	while(!myQ.empty()){
		now = myQ.front();
		myQ.pop();

		for(int i=1;i<=6;i++){
			int next = board[now+i];
			if(next>100){
				continue;
			}
			if(dist[next]>dist[now]+1){
				dist[next] = dist[now]+1;
				myQ.push(next);
				if(next == 100){
					cout<<dist[next];
					endFlag = true;
					break;
				}
			}
		}
		
		if(endFlag){
			break;
		}
	}
	return 0;
}