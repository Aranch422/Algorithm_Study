#include <iostream>
#include <queue>
#include <string>

#define INF 1000000000

using namespace std;

int dp[1000001];
string myLog[1000001];
queue<int> myQ;
int main(){
	
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		dp[i] = INF;
	}
	dp[n]=0;
	myLog[n]=to_string(n);
	myQ.push(n);
	while(!myQ.empty()){
		int front = myQ.front();
		myQ.pop();
		if(front ==1){
			cout<<dp[1]<<endl;
			cout<<myLog[1];
			break;
		}
		int num = dp[front]+1;
		if(front-1>0 && dp[front-1]>num){
			dp[front-1]=num;
			myLog[front-1]=myLog[front]+" "+to_string(front-1);
			myQ.push(front-1);
		}
		if(front/2>0 && front%2==0){
			if(dp[front/2]>num){
				dp[front/2]=num;
				myLog[front/2]=myLog[front]+" "+to_string(front/2);
				myQ.push(front/2);
			}
		}
		if(front/3>0 && front%3==0){
			if(dp[front/3]>num){
				dp[front/3]=num;
				myLog[front/3]=myLog[front]+" "+to_string(front/3);
				myQ.push(front/3);
			}
		}
	}
	return 0;
}