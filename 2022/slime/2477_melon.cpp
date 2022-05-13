#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	queue<int> Q;
	vector<int> V;
	int n;
	bool stopQ = false;
	cin>>n;
	for(int i=0;i<6;i++){
		int a,b;
		cin>>a>>b;
		if(a == 2 || a == 3){
			b = -b;
		}
		if(a == 1){
			stopQ = true;
		}
		if(stopQ == false){
			Q.push(b);
		}
		else{
			V.push_back(b);
		}
	}
	
	while(Q.empty() == false){
		int front = Q.front();
		Q.pop();
		
		V.push_back(front);
	}
	
	int width = 0;
	int area = 0;
	for(int i=0;i<V.size();i++){
		if(i%2==0){
			width += V[i];
		}
		else{
			area+=width*V[i];
		}
	}
	cout<<area*n;
	
	return 0;
}