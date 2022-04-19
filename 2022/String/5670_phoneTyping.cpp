#include <iostream>
#include <string>

using namespace std;

int n;

int convertToIdx(char ch){
	return int(ch)-int('a');
}

struct node{
	node* children[26];
	bool isTerminal;
	int numOfChildren;
	node(){
		isTerminal = false;
		numOfChildren = 0;
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
	}
};

void insertTrie(node* now, string& str, int strIdx){
	if(str.size() == strIdx){
		now->isTerminal = true;
		now->numOfChildren++;
		return;
	}
	char ch = str[strIdx];
	int idx = convertToIdx(ch);
	if(now->children[idx] == NULL){
		now->children[idx] = new node();
		now->numOfChildren++;
		return insertTrie(now->children[idx],str,strIdx+1);
	}
	else{
		return insertTrie(now->children[idx],str,strIdx+1);
	}
}

node* root;

int cntTrie(node* now,int cnt){
	int ret=0;
	if(now == root){
		for(int i=0;i<26;i++){
			if(now->children[i]!=NULL){
				ret += cntTrie(now->children[i],cnt+1);
				
			}
		}
		return ret;
	}
	else if(now->numOfChildren == 1){
		if(now->isTerminal){
			return cnt;
		}
		else{
			for(int i=0;i<26;i++){
				if(now->children[i]!=NULL){
					return cntTrie(now->children[i],cnt);
				}
			}			
		}
	}
	else{
		if(now->isTerminal){
			ret += cnt;
		}
		for(int i=0;i<26;i++){
			if(now->children[i]!=NULL){
				ret += cntTrie(now->children[i],cnt+1);
			}
		}
		return ret;
	}
	return ret;
}

void delMem(node* now){
	for(int i=0;i<26;i++){
		if(now->children[i] == NULL) continue;
		delMem(now->children[i]);
		delete now->children[i];
		now->children[i] = NULL;
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed;
	cout.precision(2);
	while(cin>>n){
		root = new node();
		double ans;
		for(int i=0;i<n;i++){
			string str;
			cin>>str;
			insertTrie(root,str,0);
		}
		ans = double(cntTrie(root,0));
		cout<<ans/n<<"\n";
		delMem(root);
	}
	return 0;
}