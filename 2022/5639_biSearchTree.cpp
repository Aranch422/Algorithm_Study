#include <iostream>

using namespace std;

struct node{
	int num;
	node* parent;
	node* left;
	node* right;
	node(int n,node* p,node* l,node* r) : num(n),parent(p),left(l),right(r) {}
};

void Post(node* root){
	if(root ==NULL) return;
	Post(root->left);
	Post(root->right);
	cout<<root->num<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	cin>>num;
	node* root = new node(num,NULL,NULL,NULL);
	node* parent = root;
	node* me;
	while(cin>>num){
		//if(num==-1) break;
		//cout<<num;
		me = new node(num,parent,NULL,NULL);
		if(parent->num>num){
			parent->left = me;
			parent = me;
		}
		else{
			node* grand = parent->parent;
			if(grand == NULL){
				while(true){
					if( parent->num < me->num ){
						if(parent->right == NULL){
							parent->right = me;
							me->parent = parent;
							parent = me;
							break;
						}
						else{
							parent = parent->right;
						}
					}
					else{
						if(parent->left ==NULL){
							parent->left = me;
							me->parent =parent;
							parent = me;
							break;
						}
						else{
							parent= parent->left;
						}
					}
				}
			}
			else{
				while(true){
					if(me->num<grand->num){
						while(true){
							if( parent->num < me->num ){
								if(parent->right == NULL){
									parent->right = me;
									me->parent = parent;
									parent = me;
									break;
								}
								else{
									parent = parent->right;
								}
							}
							else{
								if(parent->left ==NULL){
									parent->left = me;
									me->parent =parent;
									parent = me;
									break;
								}
								else{
									parent= parent->left;
								}
							}
						}
						break;
					}
					else if(grand->parent ==NULL){
						parent= grand;
						while(true){
							if( parent->num < me->num ){
								if(parent->right == NULL){
									parent->right = me;
									me->parent = parent;
									parent = me;
									break;
								}
								else{
									parent = parent->right;
								}
							}
							else{
								if(parent->left ==NULL){
									parent->left = me;
									me->parent =parent;
									parent = me;
									break;
								}
								else{
									parent= parent->left;
								}
							}
						}
						break;
					}
					else{
						parent = grand;
						grand = grand->parent;
					}				
				}
			}

		}
		//cout<<"end"<<endl;
	}
	Post(root);
	return 0;
}
