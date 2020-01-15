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
	//ó���� �� push
	for (int i = 1; i <= Sequence[1]; i++) {
		check[i] = 1;
		result.push_back("+\n");
	}
	//ó���� pop
	result.push_back("-\n");
	check[Sequence[1]] = 0;

	for (int i = 2; i <= n; i++) {
		//�״����� ������ pop
		if (Sequence[i]< Sequence[i-1] ) {
			for (int j = Sequence[i-1] - 1; j > Sequence[i]; j--) {
				//pop �ȵ����� NO
				if (check[j] != 0) {
					cout << "NO";
					return;
				}

			}
			check[Sequence[i]] = 0;
			result.push_back("-\n");
		}

		//ũ�� push
		else if (Sequence[i] > Sequence[i-1]) {
			for (int j = Sequence[i-1] + 1; j <= Sequence[i]; j++) {
				if(check[j]==0) continue;
				check[j] == 1;
				result.push_back("+\n");
			}
			//������ pop
			result.push_back("-\n");
			check[Sequence[i]] = 0;
		}
		//�ƴϸ� NO
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