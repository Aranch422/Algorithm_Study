#include <iostream>
#include <vector>
#include <algorithm>

int board[10][10];

int n,m;

using namespace std;

int islandCnt = 2;
int visitCnt = 1;

void rename(int i,int j){
	if(board[i][j] != 1) return;
	board[i][j] = islandCnt;
	//up
	if(i-1>=0){
		rename(i-1,j);
	}
	//left
	if(j-1>=0){
		rename(i,j-1);
	}
	//down
	if(i+1<n){
		rename(i+1,j);
	}
	if(j+1<m){
		rename(i,j+1);
	}
}

struct edge{
	int start,end,cost;
	edge(int s, int e, int c): start(s),end(e),cost(c){}
	
	bool operator<(edge e) const{
		return this->cost<e.cost;
	}
};

vector<edge> Edges;

bool isVisit[8];

int parent[8];

int find(int a){
	int ori=a;
	while(parent[a]!=-1){
		a=parent[a];
	}
	int root = a;
	a = ori;
	while(parent[a]!=-1){
		ori = a;
		a = parent[a];
		parent[ori] = root;
	}
	return root;
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		parent[a] = b;
	}
}

bool isInSame(int a,int b){
	return find(a) == find(b);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<8;i++){
		isVisit[i]=false;
		parent[i]=-1;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>board[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j] == 1){
				rename(i,j);
				islandCnt++;
			}
		}
	}
	
	//left
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			if(board[i][j]>=2 && board[i][j-1]==0){
				for(int k=j-1;k>=0;k--){
					if(board[i][k]!=0){
						if(j-k-1<=1) break;
						Edges.push_back(edge(board[i][j],board[i][k],j-k-1));
						break;
					}
				}
				continue;
			}
		}
	}
	
	//right
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(board[i][j]>=2 && board[i][j+1]==0){
				for(int k=j+1;k<m;k++){
					if(board[i][k]!=0){
						if(k-j-1<=1) break;
						Edges.push_back(edge(board[i][j],board[i][k],k-j-1));
						break;
					}
				}
				continue;
			}
		}
	}
	
	//up
	for(int j=0;j<m;j++){
		for(int i=1;i<n;i++){
			if(board[i][j]>=2 && board[i-1][j]==0){
				for(int k=i-1;k>=0;k--){
					if(board[k][j]!=0){
						if(i-k-1<=1) break;
						Edges.push_back(edge(board[i][j],board[k][j],i-k-1));
						break;
					}
				}
				continue;
			}
		}
	}
	
	//down
	for(int j=0;j<m;j++){
		for(int i=0;i<n-1;i++){
			if(board[i][j]>=2 && board[i+1][j]==0){
				for(int k=i+1;k<n;k++){
					if(board[k][j]!=0){
						if(k-i-1<=1) break;
						Edges.push_back(edge(board[i][j],board[k][j],k-i-1));
						break;
					}
				}
				continue;
			}
		}
	}
	
	sort(Edges.begin(),Edges.end());
	
	int totalCost = 0;
	for(int i=0;i<Edges.size();i++){
		int start = Edges[i].start;
		int end = Edges[i].end;
		int cost = Edges[i].cost;
		if(!isInSame(start, end)){
			//cout<<start<<" "<<end<<" "<<cost<<endl;
			Union(start, end);
			visitCnt++;
			if(!isVisit[start]){
				isVisit[start] = true;
			}
			if(!isVisit[end]){
				isVisit[end]=true;
			}
			totalCost +=cost;
		}
		if(visitCnt+2 == islandCnt) break;
	}
	if(visitCnt+2<islandCnt){
		cout<<-1;
	}
	else{
		cout<<totalCost;
	}

	return 0;
}