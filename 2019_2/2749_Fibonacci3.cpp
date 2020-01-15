#include <iostream>
#include <stack>

using namespace std;

long long num;

class matrix {
public:
	int key[2][2];

	int pow = 1;

	void square() {
		int ret[2][2];
		ret[0][0] = key[0][0] * key[0][0]+key[0][1]*key[1][0];
		ret[0][1] = key[0][0] * key[0][1] + key[0][1] * key[1][1];
		ret[1][0] = key[1][0] * key[0][0] + key[1][1] * key[1][0];
		ret[1][1] = key[1][0] * key[0][1] + key[1][1] * key[1][1];
		
		key[0][0] = ret[0][0]%1000000;
		key[0][1] = ret[0][1] % 1000000;
		key[1][0] = ret[1][0] % 1000000;
		key[1][1] = ret[1][1] % 1000000;

		pow *= 2;
	}

	void prod() {
		key[0][0] = key[0][0] + key[0][1];
		key[0][1] = key[0][0];
		key[1][0] = key[0][0];
		key[1][1] = 0;
		pow++;
	}
};

void init() {
	cin >> num;
}

//0ÀÌ¸é Á¦°ö -1ÀÌ¸é Á¦°ö +1
stack<int> myS;

void solve(long long n) {
	if (n % 2 == 0) {
		myS.push(0);
		solve(n / 2);
	}
	else {
		myS.push(-1);
		solve((n - 1) / 2);
	}
}

matrix myM;

int main() {
	init();
	solve(num);
	myM.key[0][0] = 1;
	myM.key[0][1] = 1;
	myM.key[1][0] = 1;
	myM.key[1][1] = 0;
	for (int i = 0; !myS.empty(); myS.pop()) {
		i = myS.top();
		if (i == 0) {
			myM.square();
		}
		else {
			myM.square();
			myM.prod();
		}
	}
	cout<<myM.key[0][1];
	return 0;
}