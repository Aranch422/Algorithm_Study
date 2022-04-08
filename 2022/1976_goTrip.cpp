#include <iostream>

using namespace std;

int n,m;

int parent[201];

int Find(int a){
	if(parent[a] == -1) return a;
	else{
		int temp = a;
		
		while(parent[a]!=-1){
			a= parent[a];
		}
		int root = a;
		a = temp;
		while(parent[a]!=-1){
			temp = a;
			a=parent[temp];
			parent[temp] = root;
		}
		return root;
	}
}

void Union(int a, int b){
	a= Find(a);
	b = Find(b);
	if(a==b) return;
	else{
		parent[a] = b;
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		parent[i]=-1;
	}
	int adj;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>adj;
			if(adj == 1) Union(i,j);
		}
	}
	int road;
	cin>>road;
	int root = Find(road);
	for(int i=1;i<m;i++){
		cin>>road;
		if(root != Find(road)) {
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}