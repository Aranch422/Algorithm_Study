#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int input[1000001];
int result[1000001];
int n;
stack<int> myS;


void init() {
	cin >> n;
	memset(result, -1, sizeof(input));
	for(int i=1;i<=n;i++) {
		cin >> input[i];
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		//스택의 맨위가 다음꺼보다 작으면
		while (!myS.empty()&& input[myS.top()]<input[i]) {
			result[myS.top()] = input[i];
			myS.pop();
		}
		myS.push(i);
	}
}

int main() {
	init();
	solve();

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}
	return 0;
}