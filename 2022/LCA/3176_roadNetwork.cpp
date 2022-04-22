#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct node{
	int num;
	int level;
	vector<pair<int,int>> destNcost;
	node(int num): num(num), level(0){}
};

const int NUM =100001;
const int MAXLOG = 17;
pair<int,int> dp[NUM][MAXLOG];
node* Nodes[NUM];

int n;

void setLevel(node* now){
	int lev = now->level;
	for(int i=0;i<now->destNcost.size();i++){
		int dest = now->destNcost[i].first;
		int cost = now->destNcost[i].second;
		if(Nodes[dest]->level == 0){
			Nodes[dest]->level = lev;
			dp[dest][0] = {now->num,cost};
			setLevel(Nodes[dest]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<NUM;i++){
		for(int j=0;j<MAXLOG;j++){
			dp[i][j] = {-1,0};
		}
	}
	for(int i=1;i<=n;i++){
		Nodes[i] = new node(i);
	}
	
	for(int i=0;i<n-1;i++){
		int a,b,cost;
		cin>>a>>b>>cost;
		Nodes[a]->destNcost.push_back( {b,cost} );
		Nodes[b]->destNcost.push_back( {a,cost} );
	}
	Nodes[1]->level = 1;
	setLevel(Nodes[1]);
	
	for(int j=1;j<MAXLOG;j++){
		for(int i=1;i<=n;i++){
			int prev = dp[i][j-1].first;
			int cost = dp[i][j-1].second;
			if(prev !=-1){
				dp[i][j].first = dp[prev][j-1].first;
				dp[i][j].second = dp[prev][j-1].second + cost;
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
		if(levelA>levelB){
			swap(a,b);
			swap(levelA,levelB);
		}
		int levelGap = levelB- levelA;
		int totalCost = 0;
		for(int i=MAXLOG-1;levelGap>0;i++){
			if(levelGap%2==1){
				totalCost += dp[b][i].second;
				b = dp[b][i].first;
			}
		}
		if(a==b){
			cout<<totalCost<<'\n';
		}
		else{
			for(int i=MAXLOG-1;i>=0;i--){
				if(dp[a][i].first !=1 && dp[a][i].first !=dp[b][i].first){
					totalCost += dp[a][i].second;
					totalCost +=dp[b][i].second;
					
					a = dp[a][i].first;
					b = dp[b][i].first;
				}
			}
			cout<<totalCost<<'\n';
		}
		
	}
	return 0;
}