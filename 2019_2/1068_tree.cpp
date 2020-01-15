#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class node {
public:
	node* parent;
	vector<int> children;
};

int n;
int target;
int result = 0;
stack<int> myS;

node tree[50];

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p!=-1){
			tree[i].parent = &tree[p];
			tree[p].children.push_back(i);
		}
	}
	cin >> target;
}

void solve(node t) {
	if (t.children.empty()) {
		result--;
		if (myS.empty()) return;
		int temp = myS.top();
		myS.pop();
		solve(tree[temp]);
	}
	else {
		for (vector<int>::iterator iter = t.children.begin(); iter != t.children.end(); iter++) {
			myS.push(*iter);
		}
		if (myS.empty()) return;
		int temp = myS.top();
		myS.pop();
		solve(tree[temp]);
	}
}

int main() {
	init();
	for (int i = 0; i < n; i++) {
		if (tree[i].children.empty()) result++;
	}
	if (tree[target].parent != NULL) {
		if (tree[target].parent->children.size() == 1) result++;
	}
	solve(tree[target]);
	
	cout << result;
	return 0;
}