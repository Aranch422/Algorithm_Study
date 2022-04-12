#include <iostream>

using namespace std;

int n,m;

int parent[1000001];

// O(h)
int Find(int a){
	if(parent[a]==-1) return a;
	else{
		int ori = a;
		while(parent[a]!=-1){
			a=parent[a];
		}
		int root = a;
		a = ori;
		while(parent[a]!=-1){
			ori = a;	
			a = parent[ori];
			parent[ori] = root;
		}
		return root;
	}
}
//O(h)
void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a==b) return;
	parent[a]=b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		parent[i] = -1;
	}
	while(m-->0){
		int inst,op1,op2;
		cin>> inst>>op1>>op2;
		if(inst ==0){
			Union(op1,op2);
		}
		else{
			if(Find(op1)==Find(op2)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0 ;
}