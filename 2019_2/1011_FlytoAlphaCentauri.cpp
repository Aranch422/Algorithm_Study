#include <iostream>
#include <math.h>

using namespace std;

int n;


int main() {
	int n;
	cin >> n;
	int from, to;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		int dist = to - from;
		int num = int(sqrt(dist));
		if (num * num == dist) {
			cout << 2*num-1;
		}
		else {
			int plus = int((dist - (num * num)) / num);
			if (plus * num + num * num == dist) {
				cout << 2*num-1 + plus;
			}
			else {
				cout << 2*num + plus;
			}
		}
		cout << endl;
	}
	return 0;
}