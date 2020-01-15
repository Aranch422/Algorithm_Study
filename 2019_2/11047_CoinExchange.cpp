#include <iostream>

using namespace std;

int N, K;
int coin[10];

int result = 0;

void init() {
	cin >> N >> K;

	//큰 순서대로
	for (int i = N-1; i >= 0; i--) {
		cin >> coin[i];
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		if (int(K / coin[i]) > 0) {
			result += int(K / coin[i]);
			K -= int(K / coin[i]) * coin[i];
			if (K == 0) break;
		}
	}
}

int main() {

	init();
	solve();

	cout << result;
	return 0;
}