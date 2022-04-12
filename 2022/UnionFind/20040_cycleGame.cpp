#include <iostream>

using namespace std;

int parent[500001];

int Find(int a){
	if(parent[a] == -1) return a;
	else{
		int oriA = a;
		while(parent[a]!=-1){
			a=parent[a];
		}
		int root = a;
		a= oriA;
		while(parent[a]!=-1){
			oriA=a;
			a=parent[oriA];
			parent[oriA] = root;
		}
		return root;
	}
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a==b) return true;
	else{
		parent[a] = b;
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		parent[i]=-1;
	}
	int i;
	for(i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		if(Union(a,b)){
			cout<<i;
			break;
		}
	}
	if(i>m) cout<<0;
	return 0;
}