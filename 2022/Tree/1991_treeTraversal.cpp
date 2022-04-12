#include <iostream>

using namespace std;

struct node{
	char ch;
	node* left=NULL;
	node* right=NULL;
};

node* nodes[27];

int n;

void Pre(node* now){
	cout<<now->ch;
	if(now->left!=NULL) Pre(now->left);
	if(now->right!=NULL) Pre(now->right);
}

void In(node* now){
	if(now->left!=NULL) In(now->left);
	cout<<now->ch;
	if(now->right!=NULL) In(now->right);
}

void Post(node* now){
	if(now->left!=NULL) Post(now->left);
	if(now->right!=NULL) Post(now->right);
	cout<<now->ch;
}

int main(){
	
	for(int i=1;i<=26;i++){
		nodes[i] = new node();
		nodes[i]->ch = (char)(i+64);
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,l,r;
		cin>>a>>l>>r;
		if(l!='.'){
			nodes[int(a)-64]->left = nodes[int(l)-64];
		}
		if(r!='.'){
			nodes[int(a)-64]->right = nodes[int(r)-64];
		}
	}
	Pre(nodes[1]);
	cout<<endl;
	In(nodes[1]);
	cout<<endl;
	Post(nodes[1]);
	cout<<endl;
	return 0;
}