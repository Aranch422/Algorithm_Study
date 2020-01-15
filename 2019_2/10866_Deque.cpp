#include <iostream>
#include <string>

using namespace std;

class node {
public:
	int key;
	node* next;

	node() {
		key = 0;
		next = NULL;
	}
};

class Deque {
public:
	int size=0;

	node* begin;
	node* end;

	//push
	void push_front(int x) {
		node* newnode = new node();
		newnode->key = x;
		if (size != 0) {
			newnode->next = &(*begin);
			begin = newnode;
		}
		else {
			newnode->next = NULL;
			begin = newnode;
			end = newnode;
		}
		size++;
	}

	//pop 후 출력
	void pop_front() {
		if (size!=0) {
			cout << begin->key << "\n";
			node* temp = begin->next;
			delete(begin);
			begin = temp;
			size--;
		}
		else {
			cout << -1 << "\n";
		}
	}

	//push
	void push_back(int x) {

		node* newnode = new node();
		newnode->key = x;
		newnode->next = NULL;

		if (size!=0) {
			end->next = newnode;
			end = newnode;
		}
		else {
			end = newnode;
			begin = newnode;
		}
		size++;
	}

	//pop 후 출력
	void pop_back() {
		if (size!=0) {
			cout << end->key << "\n";
			node* temp = begin;
			for (int i = 1; i < size-1;i++) {
				temp = temp->next;
			}
			end = temp;
			temp->next = NULL;
			size--;
		}
		else {
			cout << -1 << "\n";
		}

	}

	//원소개수 출력
	void Size() {
		cout << size<<"\n";
	}

	//empty 비어있으면 1 아니면 0
	bool empty() {
		if (size == 0) {
			cout << 1 << "\n";
			return true;
		}
		else {
			cout << 0 << "\n";
			return false;
		}
	}

	//front
	void front() {
		if (size!=0) {
			cout << begin->key << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}

	//back
	void back() {
		if (size!=0) {
			cout << end->key << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
};

void solve(string s,Deque &myD) {
	int x;

	if (s == "push_back") {
		cin >> x;
		myD.push_back(x);
	}
	else if (s == "push_front") {
		cin >> x;
		myD.push_front(x);
	}
	else if (s == "pop_back") {
		myD.pop_back();
	}
	else if (s == "pop_front") {
		myD.pop_front();
	}
	else if (s == "empty") {
		myD.empty();
	}
	else if (s == "front"){
		myD.front();
	}
	else if (s == "back") {
		myD.back();
	}
	else if (s == "size") {
		myD.Size();
	}
}


int main() {
	int n;
	Deque myD;
	cin >> n;
	while (n>0) {
		string s;
		cin >> s;
		solve(s,myD);
		n--;
	}
	return 0;
}