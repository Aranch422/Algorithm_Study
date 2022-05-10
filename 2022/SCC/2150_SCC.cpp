#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int v,e;

struct node{
	int num;
	int sccNum;
	vector<int> edge;
	node(int num): num(num), sccNum(0) {}
};

node* Nodes[10001];

int cnt =0;

stack<int> myS;

void findSCC(node* now){
	int sccNum = now->sccNum;
	for(int i=0;i<now->edge.size();i++){
		node* next = Nodes[now->edge[i]];
		if(next->sccNum == 0){
			next->sccNum = ++sccNum;
			findSCC(now->edge[i]);	
		}
		else{
			
		}
		
	}
}

int main(){
	cin>>v>>e;
	for(int i=1;i<=v;i++){
		Nodes[i] = new node(i);
	}
	for(int i=1;i<=e;i++){
		int a,b;
		cin>>a>>b;
		Nodes[a]->edge.push_back(b);
	}
	Nodes[1]->sccNum = ++cnt;
	return 0;
}