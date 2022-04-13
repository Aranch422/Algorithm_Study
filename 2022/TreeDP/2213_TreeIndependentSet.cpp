#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 2123456789;

struct node{
	int num;
	int val;
	int level;
	node* parent;
	vector<node*> children;
};

int n;

node* Nodes[10001];

void leveling(node* parent, node* me){
	if(parent!=NULL) {
		me->level = parent->level+1;
		me->parent = parent;
		for(int i=0;i<me->children.size();i++){
			if(me->children[i] == parent){
				me->children.erase(me->children.begin()+i);
				break;
			}
		}
	}
	for(int i=0;i<me->children.size();i++){
		leveling(me,me->children[i]);
	}
}

set<int> Log;

int dp[10001][2];

int getIndSet(node* root,bool isInvolved){
	if(isInvolved){
		if(dp[root->num][1]!=-1) return dp[root->num][1];
		int tempValSum=0;
		for(int i=0;i<root->children.size();i++){
			tempValSum+= getIndSet(root->children[i],false);
		}
		dp[root->num][1] = root->val+tempValSum;
		return root->val+tempValSum;
	}
	else{
		if(dp[root->num][0]!=-1) return dp[root->num][0];
		int tempValSum=0;
		for(int i=0;i<root->children.size();i++){
			int inVolved = getIndSet(root->children[i],true);
			int not_inVolved = getIndSet(root->children[i],false);
			int bigger;
			if(not_inVolved<inVolved){
				bigger = inVolved;
				Log.insert(root->children[i]->num);
			}
			else{
				bigger = not_inVolved;
			}
			tempValSum+=bigger;
		}
		dp[root->num][0] = tempValSum;
		return tempValSum;
	}
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int val;
		dp[i][0]=-1;
		dp[i][1]=-1;
		cin>>val;
		Nodes[i] = new node();
		Nodes[i]->val = val;
		Nodes[i]->num = i;
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		Nodes[a]->children.push_back(Nodes[b]);
		Nodes[b]->children.push_back(Nodes[a]);
	}
	Nodes[1]->level = 1;
	Nodes[1]->parent = NULL;
	leveling(NULL,Nodes[1]);
	
	int a = getIndSet(Nodes[1],true);
	set<int> LogA = Log;
	Log.clear();
	int b = getIndSet(Nodes[1],false);
	set<int> LogB = Log;
	int big;
	if(a>b){
		Log = LogA;
		big = dp[1][1];
		Log.insert(1);
	}
	else{
		Log = LogB;
		big = dp[1][0];
	}
	
	cout<<big<<endl;
	
	for(auto iter=Log.begin();iter!=Log.end();iter++){
		if(iter == Log.begin()){
			cout<<(*iter);
		}
		else{
			cout<<" "<<(*iter);
		}
	}
	
	return 0;
}
