#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int num;
	int before;
	set<int> after;
	node(int num) : num(num), before(0) {}
};

node* Nodes[501];
node* Rank[501];

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			Nodes[i] = new node(i);
		}
		for(int i=1;i<=n;i++){
			int num;
			cin>>num;
			Rank[i] = Nodes[num];
		}
		for(int i=1;i<=n;i++){
			Rank[i]->before = i-1;
			for(int j=i+1;j<=n;j++){
				Rank[i]->after.insert(Rank[j]->num);
			}
		}
		
		
	
		
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			int s,e;
			cin>>s>>e;
			set<int>& afterS = Nodes[s]->after;
			set<int>::iterator iter = afterS.find(e);

			if(iter!=afterS.end()){
				Nodes[s]->before++;
				afterS.erase(iter);
			}
			else{
				Nodes[s]->before--;
				afterS.insert(e);
			}
			
			set<int>& afterE = Nodes[e]->after;
			iter = afterE.find(s);
			if(iter!=afterE.end()){
				Nodes[e]->before++;
				afterE.erase(iter);
			}
			else{
				Nodes[e]->before--;
				afterE.insert(s);
			}
		}
		
		/*
		for(int i=0;i<n;i++){
			cout<<i<<": ";
			for(auto iter = Nodes[i]->after.begin();iter!=Nodes[i]->after.end();iter++){
				cout<<*iter;
			}
			cout<<"  before: "<<Nodes[i]->before;
			cout<<endl;
		}
		*/
		
		
		
		queue<int> myQ;
		for(int i=1;i<=n;i++){
			//cout<<i<<" : "<<Nodes[i]->before<<endl; 
			if(Nodes[i]->before==0){
				myQ.push(i);
			}
		}
		vector<int> Log;
		int cnt = 0;
		while(myQ.size()==1){
			int now = myQ.front();
			myQ.pop();
			//cout<<now<<endl;
			Log.push_back(now);
			cnt++;
			// erase all and if size ==0 push and log
			for(auto iter = Nodes[now]->after.begin(); iter != Nodes[now]->after.end();iter++){
				Nodes[*iter]->before--;
				if(Nodes[*iter]->before ==0){
					myQ.push(*iter);
				}
			}
		}
		if(myQ.size()>1){
			//cout<<"size: "<<myQ.size();
			cout<<"?\n";
		}
		else if(myQ.empty()){
			if(cnt == n){
				for(int i=0;i<n;i++){
					cout<<Log[i]<<" ";
				}
				cout<<"\n";
			}
			else{
				cout<<"IMPOSSIBLE\n";
			}
		}
		
	}
	return 0;
}