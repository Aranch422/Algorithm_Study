#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct node{
	string str;
	map<string,node*> children;
};

int n;

void printNode(node* now,int num){
	if(num!=-1){
		for(int i=0;i<num;i++){
			cout<<"--";
		}
		cout<<now->str<<"\n";		
	}
	for(auto iter = now->children.begin();iter!=now->children.end();iter++){
		printNode(iter->second,num+1);
	}
}

int main(){
	cin>>n;
	
	node* root = new node();
	root->str = "";
	
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		node* now = root;
		for(int i=0;i<k;i++){
			string str;
			cin>>str;
			//if find
			if(now->children.find(str) != now->children.end()){
				now = now->children.find(str)->second;
			}
			else{
				node* temp = new node();
				temp->str = str;
				now->children.insert({str,temp});
				now = temp;
			}
		}
	}
	printNode(root,-1);
	return 0;
}