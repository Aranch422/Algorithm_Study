#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct node{
	int num;
	int level;
	vector<int> children;
	node(int num):num(num),level(0){}
};

int n;
const int NUM = 100001;
const int MAXLOG = 17;
int dp[NUM][MAXLOG];

node* Nodes[100001];

void setLevel(node* now){
	int lev = now->level+1;
	for(int i=0;i<now->children.size();i++){
		if(Nodes[now->children[i]]->level ==0){
			Nodes[now->children[i]]->level = lev;
			dp[Nodes[now->children[i]]->num][0] = now->num;
			setLevel(Nodes[now->children[i]]);	
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<MAXLOG;j++){
			dp[i][j] = -1;
		}
	}
	for(int i=1;i<=n;i++){
		Nodes[i] = new node(i);
	}
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		Nodes[a]->children.push_back(b);
		Nodes[b]->children.push_back(a);
	}
	Nodes[1]->level =1;
	setLevel(Nodes[1]);
	
	for(int j=1;j<MAXLOG;j++){
		for(int i=1;i<=n;i++){
			int prev = dp[i][j-1];
			if(prev != -1){
				dp[i][j] = dp[prev][j-1];
			}
		}
	}

	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int levelA = Nodes[a]->level;
		int levelB = Nodes[b]->level;
		//cout<<"level "<<levelA<<" "<<levelB<<endl;
		if(levelA>levelB){
			swap(a,b);
			swap(levelA,levelB);
		}
		int levelGap = levelB-levelA;
		for(int i=0;levelGap>0;i++){
			if(levelGap%2 == 1){
				b = dp[b][i];
			}
			levelGap = levelGap/2;;
		}
		//cout<<a<<" "<<b<<endl;
		if(a==b){
			cout<<a<<'\n';
		}
		else{
			for(int i = MAXLOG-1;i>=0;i--){
				if(dp[a][i]!=-1 && dp[a][i] !=dp[b][i]){
					a = dp[a][i];
					b = dp[b][i];
				}
			}
			cout<<dp[a][0]<<'\n';
		}
	}
	return 0;
}
/*
1
	2					3
	4     5  	6		7     	8
	9 10  11 12 		13 14
		  15
		  */