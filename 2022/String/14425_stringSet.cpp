#include <iostream>

using namespace std;

int n,m;

struct node{
	bool isTerminal;
	node* children[26];
	node() : isTerminal(false) {
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
	}
};

int convertToIdx(char ch){
	return int(ch)-97;
}

void insertTrie(node* now, string& str, int strIdx){
	char ch = str[strIdx];
	int idx = convertToIdx(ch);
	bool isTerminal = (strIdx == str.size());
	if(isTerminal){
		now->isTerminal = true;
		return;
	}
	if(now->children[idx]==NULL){
		now->children[idx] = new node();
		return insertTrie(now->children[idx], str,strIdx+1);
	}
	else{
		return insertTrie(now->children[idx], str,strIdx+1);
	}
}

bool findTrie(node* now, string& str, int strIdx){
	char ch = str[strIdx];
	int idx = convertToIdx(ch);
	bool isTerminal = (strIdx == str.size());
	if(isTerminal){
		if(now->isTerminal){
			return true;
		}
		else{
			return false;
		}
	}
	if(now->children[idx]==NULL){
		return false;
	}
	else{
		return findTrie(now->children[idx], str,strIdx+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	node* root = new node();
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		insertTrie(root,s,0);
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		bool isIn = findTrie(root,s,0);
		if(isIn){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}