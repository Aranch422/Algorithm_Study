#include <iostream>
#include <cstring>

using namespace std;

int n;
int prime[10001];


void init() {
	cin >> n;
	memset(prime, 0, sizeof(prime));
	prime[2] = 1;

	for (int i=3; i < 10001;i++) {
		bool isprime = true;
		
		//이미 체크했으면
		if (prime[i] == -1) continue;


		for (int j=2; j < i;j++) {
			if (prime[j] == 1 && i % j == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) {
			prime[i] = 1;
			for (int k = 2; i * k < 10001; k++) {
				prime[i * k] = -1;
			}
		}
	}
}

int num;

int main() {
	init();

	while (n>0) {
		cin >> num;

		for (int i = int(num/2); i > 0; i--) {
			if (prime[i] == 1 && prime[num - i] == 1) {
				cout << i <<" "<< num-i<<endl;
				break;
			}
		}
		n--;
	}
	return 0;

}