//못품

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int n;

pair<int, pair<int, int>> mass[10];

void init() {
	cin >> n;
	for (int i = 0; i < 10; i++) {
		mass[i] = make_pair(0, make_pair(1, 1));
	}
}

int a, b, p, q;

int main() {
	init();

	while (n--) {
		cin >> a >> b >> p >> q;

		//작은걸 할당
		if (p >= q) {
			mass[a].first = mass[b].first;
			mass[a].second.first = p;
			mass[a].second.second=q;
			
		}
	}

	return 0;
}