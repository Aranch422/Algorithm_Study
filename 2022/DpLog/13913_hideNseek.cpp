#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isVisit[100001];
int before[100001];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=100000;i++){
		isVisit[i]=false;
		before[i]=-1;
	}
	queue<int> myQ;
	isVisit[n]=true;

	if(n == k) {
		cout<<0<<"\n"<<n;
		return 0;
	}
	
	myQ.push(n);
	while(!myQ.empty()){
		int now = myQ.front();


		myQ.pop();
		int back,front,jump;
		back = now-1;
		front = now+1;
		jump = now*2;
		
		if(back == k){
			before[back] = now;
			break;
		}
		if(front == k){
			before[front] = now;
			break;
		}
		if(jump == k){
			before[jump] = now;
			break;
		}
		
		if(back>=0 && !isVisit[back]) {
			isVisit[back]=true;
			before[back] = now;
			myQ.push(back);
		}
		if(front<=100000&&!isVisit[front]) {
			isVisit[front]=true;
			before[front] = now;
			myQ.push(front);
		}
		if(jump<=100000&&!isVisit[jump]) {
			isVisit[jump]=true;
			before[jump] = now;
			myQ.push(jump);
		}
	}
	vector<int> ans;
	int temp = k;
	while(before[temp]!=-1){
		ans.push_back(temp);
		temp = before[temp];
	}
	ans.push_back(temp);
	cout<<ans.size()-1<<"\n";
	for(int i=ans.size()-1;i>0;i--){
		cout<<ans[i]<<" ";
	}
	cout<<ans[0];
	return 0;
}