#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[1001][3];
int dp[1001][3];

int n;
int ori;

int getShortestPath(int now, int c){
	if(dp[now][c]!=-1) return dp[now][c];
	if(now>n) return 0;
	vector<int> color;
	if(now != n-1 ){
		for(int i=0;i<=2;i++){
			if(i != c){
				color.push_back(i);	
			}
		}		
	}
	else{
		for(int i=0;i<=2;i++){
			if(i != c && i!=ori){
				color.push_back(i);	
			}
		}
	}

	int minimum = 99999999;
	for(int i=0;i<color.size();i++){
		int temp = getShortestPath(now+1,color[i])+cost[now][c];
		if(minimum>temp){
			minimum = temp;
		}
	}
	dp[now][c] = minimum;
	return dp[now][c];
	
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
		dp[i][0]=-1;
		dp[i][1]=-1;
		dp[i][2]=-1;
	}
	ori=0;
	int a = getShortestPath(1,0);
	
	for(int i=1;i<=n;i++){
		dp[i][0]=-1;
		dp[i][1]=-1;
		dp[i][2]=-1;
	}
	ori=1;
	int b = getShortestPath(1,1);
	
	for(int i=1;i<=n;i++){
		dp[i][0]=-1;
		dp[i][1]=-1;
		dp[i][2]=-1;
	}
	ori=2;
	int c = getShortestPath(1,2);
	int ans;
	if(a<b){
		if(a<c) ans = a;
		else ans =c;
	}
	else{
		if(b<c) ans =b;
		else ans =c;
	}
	cout<<ans;
	return 0;
}