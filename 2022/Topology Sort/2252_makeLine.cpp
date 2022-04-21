#include <iostream>
#include <queue>

using namespace std;

struct node{
	int num;
	int before;
	vector<int> after;
	node(int num): num(num), before(0) {}
};

priority_queue<int, vector<int>, greater<int>> myQ;
node* Nodes[32001];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		Nodes[i] = new node(i);
	}
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		Nodes[a]->after.push_back(b);
		Nodes[b]-> before++;
	}
	for(int i=1;i<=n;i++){
		if(Nodes[i]->before ==0){
			myQ.push(i);
		}
	}
	priority_queue<int, vector<int>, greater<int>> temp;
	while(!myQ.empty()){
		node* now = Nodes[myQ.top()];
		myQ.pop();
		cout<<now->num<<" ";
		for(int j=0;j<now->after.size();j++){
			Nodes[now->after[j]]->before--;
			if(Nodes[now->after[j]]->before == 0){
				myQ.push(Nodes[now->after[j]]->num);
			}
		}

	}
	return 0;
}