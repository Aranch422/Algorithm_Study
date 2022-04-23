#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct node{
	long long num;
	long long level;
	vector<pair<long long,pair<long long,long long>>> destNcost;
	node(long long num): num(num), level(0){}
};

const long long NUM =100001;
const long long MAXLOG = 17;
pair<long long,pair<long long,long long>> dp[NUM][MAXLOG];
node* Nodes[NUM];

long long n;

void setLevel(node* now){
	long long lev = now->level+1;
	for(long long i=0;i<now->destNcost.size();i++){
		long long dest = now->destNcost[i].first;
		long long shortest = now->destNcost[i].second.first;
		long long longest = now->destNcost[i].second.second;
		if(Nodes[dest]->level == 0){
			Nodes[dest]->level = lev;
			dp[dest][0] = {now->num,{shortest,longest}};
			setLevel(Nodes[dest]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(long long i=0;i<NUM;i++){
		for(long long j=0;j<MAXLOG;j++){
			dp[i][j] = {-1,{999999999999,-1}};
		}
	}
	for(long long i=1;i<=n;i++){
		Nodes[i] = new node(i);
	}
	
	for(long long i=0;i<n-1;i++){
		long long a,b,cost;
		cin>>a>>b>>cost;
		Nodes[a]->destNcost.push_back( {b,{cost,cost}} );
		Nodes[b]->destNcost.push_back( {a,{cost,cost}} );
	}
	Nodes[1]->level = 1;
	setLevel(Nodes[1]);
	
	for(long long j=1;j<MAXLOG;j++){
		for(long long i=1;i<=n;i++){
			long long prev = dp[i][j-1].first;
			long long shortest = dp[i][j-1].second.first;
			long long longest = dp[i][j-1].second.second;
			if(prev !=-1){
				dp[i][j].first = dp[prev][j-1].first;
				long long tempS = dp[prev][j-1].second.first;
				long long tempL = dp[prev][j-1].second.second;
				long long newS,newL;
				if(tempS < shortest){
					newS = tempS;
				}
				else{
					newS = shortest;
				}
				if(longest<tempL){
					newL = tempL;
				}
				else{
					newL = longest;
				}
				dp[i][j].second = {newS,newL};
			}
		}
	}
	
	long long q;
	cin>>q;
	while(q--){
		long long a,b;
		cin>>a>>b;
		long long levelA = Nodes[a]->level;
		long long levelB = Nodes[b]->level;

		if(levelA>levelB){
			swap(a,b);
			swap(levelA,levelB);
		}
		long long levelGap = levelB- levelA;
		long long shortest=999999999999;
		long long longest = -1;
		for(long long i=0;levelGap>0;i++){
			if(levelGap%2==1){
				if( dp[b][i].second.first < shortest ){
					shortest = dp[b][i].second.first;
				}
				if( longest < dp[b][i].second.second ){
					longest = dp[b][i].second.second;
				}
				b = dp[b][i].first;
			}
			levelGap/=2;
		}
		if(a==b){
			cout<<shortest<<" "<<longest<<'\n';
		}
		else{
			for(long long i=MAXLOG-1;i>=0;i--){
				if(dp[a][i].first !=-1 && dp[a][i].first !=dp[b][i].first){
					if( dp[b][i].second.first < shortest ){
						shortest = dp[b][i].second.first;
					}
					if( longest < dp[b][i].second.second ){
						longest = dp[b][i].second.second;
					}
					
					if( dp[a][i].second.first < shortest ){
						shortest = dp[a][i].second.first;
					}
					if( longest < dp[a][i].second.second ){
						longest = dp[a][i].second.second;
					}
					a = dp[a][i].first;
					b = dp[b][i].first;
				}
			}
			if( dp[b][0].second.first < shortest ){
				shortest = dp[b][0].second.first;
			}
			if( longest < dp[b][0].second.second ){
				longest = dp[b][0].second.second;
			}

			if( dp[a][0].second.first < shortest ){
				shortest = dp[a][0].second.first;
			}
			if( longest < dp[a][0].second.second ){
				longest = dp[a][0].second.second;
			}
			cout<<shortest<<" "<<longest<<"\n";
		}
		
	}
	return 0;
}