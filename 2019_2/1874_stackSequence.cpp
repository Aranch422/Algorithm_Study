#include <iostream>
#include <cstring>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n;
//1 push, 0 pop, -1 not done
int check[100001];
int Sequence[100001];
vector<string> result;

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> Sequence[i];
	}
	memset(check, -1, sizeof(check));
}

void solve() {
	//처음은 다 push
	for (int i = 1; i <= Sequence[1]; i++) {
		check[i] = 1;
		result.push_back("+\n");
	}
	//처음꺼 pop
	result.push_back("-\n");
	check[Sequence[1]] = 0;

	for (int i = 2; i <= n; i++) {
		//그다음이 작으면 pop
		if (Sequence[i]< Sequence[i-1] ) {
			for (int j = Sequence[i-1] - 1; j > Sequence[i]; j--) {
				//pop 안됐으면 NO
				if (check[j] != 0) {
					cout << "NO";
					return;
				}

			}
			check[Sequence[i]] = 0;
			result.push_back("-\n");
		}

		//크면 push
		else if (Sequence[i] > Sequence[i-1]) {
			for (int j = Sequence[i-1] + 1; j <= Sequence[i]; j++) {
				if(check[j]==0) continue;
				check[j] == 1;
				result.push_back("+\n");
			}
			//마지막 pop
			result.push_back("-\n");
			check[Sequence[i]] = 0;
		}
		//아니면 NO
		else {
			cout << "NO";
			return;
		}
	}
	for (vector<string>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter;
	}

}

int main() {
	init();
	solve();
	return 0;
}