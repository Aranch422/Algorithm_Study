#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int map[501][501];
int DP[501][501];

int maxDay = 0;

void init() {
	cin >> N;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> map[i][j];
		}
	}
	memset(DP, -1, sizeof(DP));
}

bool isIn(int y, int x) {
	return x >= 1 && x <= N && y > 0 &&y < N + 1;
}

bool isLarger(int y1, int x1, int y2, int x2) {
	return map[y1][x1] < map[y2][x2];
}

int solve(int y, int x) {
	
	int& result0 = DP[y][x];
	int result1, result2, result3, result4;
	
	if (DP[y][x] != -1) return DP[y][x];
	DP[y][x] = 0;

	if (isIn(y - 1, x) && isLarger(y, x, y - 1, x)) {
		result1 = solve(y - 1, x);
		result0 = max(result0, result1);
	}

	if (isIn(y + 1, x) && isLarger(y, x, y + 1, x)) {
		result2=solve(y + 1, x);
		result0 = max(result0, result2);
	}

	if (isIn(y , x-1) && isLarger(y, x, y , x-1)) {
		result3=solve(y, x - 1);
		result0 = max(result0, result3);
	}

	if (isIn(y, x+1) && isLarger(y, x, y, x+1)) {
		result4=solve(y, x + 1);
		result0 = max(result0, result4);
	}

	//max
	result0++;

	if (result0 > maxDay) maxDay = result0;

	return result0;
}

int main() {
	init();
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (DP[i][j] == -1) {
				solve(i, j);
			}
		}
	}
	/*Ãâ·Â
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cout << DP[i][j];
		}
		cout << endl;
	}
	*/
	cout << maxDay;
}