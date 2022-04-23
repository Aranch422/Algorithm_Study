#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct node{
	long long num;
	long long level;
	vector<pair<long long,long long>> destNCost;
	node(long long num) : num(num),level(0) {}
};

const long long NUM = 100001;
const long long MAXLOG = 17;

node* Nodes[NUM];
pair<long long,long long> dp[NUM][MAXLOG];

long long n;

void setLevel(node* now){
	long long lev = now->level+1;
	for(long long i=0;i<now->destNCost.size();i++){
		long long dest =now->destNCost[i].first;
		long long cost = now->destNCost[i].second;
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
	for(long long i=1;i<=n;i++){
		Nodes[i] = new node(i);
	}
	for(long long i=0;i<NUM;i++){
		for(long long j=0;j<MAXLOG;j++){
			dp[i][j] = {-1, -1};
		}
	}
	for(long long i=1;i<n;i++){
		long long a,b,cost;
		cin>>a>>b>>cost;
		Nodes[a]->destNCost.push_back( {b, cost} );
		Nodes[b]->destNCost.push_back( {a, cost} );
	}
	
	Nodes[1]->level = 1;
	setLevel(Nodes[1]);
	
	for(long long j=1;j<MAXLOG;j++){
		for(long long i=1;i<=n;i++){
			long long prev = dp[i][j-1].first;
			if(prev!=-1){
				dp[i][j].first = dp[prev][j-1].first;
				dp[i][j].second = dp[i][j-1].second + dp[prev][j-1].second;
			}
		}
	}
	long long q;
	cin>>q;
	while(q--){
		long long op,a,b,k;
		long long oriA,oriB;
		cin>>op;
		if(op == 1){
			cin>>a>>b;
		}
		else{
			cin>>a>>b>>k;
		}
		
		long long totalCost=0;
		
		long long levelA = Nodes[a]->level;
		long long levelB = Nodes[b]->level;
		bool isSwitched = false;
		if(levelA>levelB){
			swap(a,b);
			swap(levelA,levelB);
			isSwitched = true;
		}
		oriA=a;
		oriB=b;
		long long levelGap = levelB - levelA;
		long long ori = levelGap;
		long long len2 = 0;
		for(long long i=0;levelGap>0;i++){
			if(levelGap%2 == 1){
				len2+=powl(2,i);
				totalCost += dp[b][i].second;
				b = dp[b][i].first;
			}
			levelGap /=2;
		}
		if(a == b){
			if(op ==1) {
				cout<<totalCost<<'\n';
			}
			else{
				long long elevate;
				if(isSwitched){
					elevate = k-1;
				}
				else{
					elevate = len2-k+1;	
				}
				
				b = oriB;
				for(long long i=0;elevate>0;i++){
					if(elevate%2==1){
						b = dp[b][i].first;
					}
					elevate /=2;
				}
				cout<<b<<'\n';
			}
		}
		else{
			long long len = 0;
			for(long long i=MAXLOG-1;i>=0;i--){
				if(dp[a][i].first!=-1 && dp[a][i].first !=dp[b][i].first){
					len += powl(2,i);
					totalCost +=dp[a][i].second;
					totalCost +=dp[b][i].second;
					a = dp[a][i].first;
					b = dp[b][i].first;
				}
			}
			len +=1;
			totalCost +=dp[a][0].second;
			totalCost +=dp[b][0].second;
			
			a = dp[a][0].first;
			b = dp[b][0].first;
			
			if(op == 1){
				cout<<totalCost<<'\n';
			}
			else{
				if(isSwitched){
					k = 2*len+len2-k+2;
				}
				if(k<=len){
					a = oriA;
					long long elevate = k-1;
					for(long long i=0;elevate>0;i++){
						if(elevate%2==1){
							a = dp[a][i].first;
						}
						elevate /=2;
					}
					cout<<a<<"\n";
				}
				else if(k==len+1){
					cout<<a<<'\n';
				}
				else{
					long long elevate = 2*len + len2-k+1;
					b = oriB;
					for(long long i=0;elevate>0;i++){
						if(elevate%2==1){
							b = dp[b][i].first;
						}
						elevate /=2;
					}
					cout<<b<<'\n';
				}
			}
		}
	}
	return 0;
}