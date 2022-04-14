#include <iostream>
#include <vector>

using namespace std;

struct node{
	int num;
	int level;
	node* parent;
	vector<node*> children;
};

node* Nodes[1000001];

int n;

void leveling(node* parent, node* me){
	if(parent!=NULL){
		me->parent = parent;
		me->level = parent->level+1;
		for(int i=0;i<me->children.size();i++){
			if(me->children[i] == parent) {
				me->children.erase(me->children.begin()+i);
				break;
			}
		}
	}
	for(int i=0;i<me->children.size();i++){
		leveling(me,me->children[i]);
	}
}

int dp[1000001][2];

int getMinEarly(node* root, bool isNecessary){
	if(isNecessary){
		if(dp[root->num][1]!=-1) return dp[root->num][1];
		int ans =0;
		for(int i=0;i<root->children.size();i++){
			ans += getMinEarly(root->children[i],false);
		}
		dp[root->num][1] = ans+1;
		return ans+1;
	}
	else{
		if(dp[root->num][0]!=-1) return dp[root->num][0];
		int ans = 0;
		int involved = 1;
		int notInvolved= 0;
		for(int i=0;i<root->children.size();i++){
			involved += getMinEarly(root->children[i],false);
			notInvolved += getMinEarly(root->children[i],true);
		}
		if(notInvolved>involved){
			dp[root->num][0] = involved;
			return involved;
		}
		else{
			dp[root->num][0] = notInvolved;
			return notInvolved;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		Nodes[i]= new node();
		Nodes[i]->num = i;
		dp[i][0]=-1;
		dp[i][1] = -1;
	}
	for(int i=1;i<n;i++){
		int s,e;
		cin>>s>>e;
		Nodes[s]->children.push_back(Nodes[e]);
		Nodes[e]->children.push_back(Nodes[s]);
	}
	Nodes[1]->level =1;
	leveling(NULL,Nodes[1]);
	int a = getMinEarly(Nodes[1],true);
	int b =getMinEarly(Nodes[1],false);
	int ans = (a<b)? a:b;
	cout<<ans;
	return 0;
}