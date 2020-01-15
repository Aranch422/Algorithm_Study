#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

long long m, M;

int arr[1000001];

void init() {
	cin >> m >> M;
	memset(arr, 0, sizeof(arr));
}

int result = 0;

int main() {
	init();

	for (long long i = 2; i * i < M + 1; i++) {
		long long j = m / (i * i);
		if (j * i * i != m) j++;
		for (; j * i * i < M + 1; j++) {
			if (arr[j * i * i-m] == 0) {
				result++;
			}
			arr[j * i * i-m] = 1;
		}
	}


	cout << M-m-result+1;
	return 0;
}