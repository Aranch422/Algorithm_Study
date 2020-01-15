#include <iostream>

using namespace std;

int smaller(int a, int b) {
	if (a >= b) return b;
	else return a;
}

int bigger(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int main() {

	//입력
	int numOfCase;
	cin >> numOfCase;

	while (numOfCase != 0) {
		numOfCase--;

		int p, q, a, b, c, d;
		cin >> p >> q >> a >> b >> c >> d;

		//초기화
		int Coin, Bit, Berry;
		Coin = 0; Bit = p; Berry = q;

		Coin = (Berry / c) * d;

		int result = -1;
		//비트가 더 많으면
		if (Bit >= Coin) {
			
			int OriBit = Bit;
			int OriCoin = Coin;
			Bit -= (OriBit - OriCoin) / (a + b) * a;
			Coin+= (OriBit - OriCoin) / (a + b) * b;

			int temp = smaller(Bit, Coin);
			result = bigger(temp, smaller(Bit - a, Coin + b));
		}
		else {

			int OriBit = Bit;
			int OriCoin = Coin;

			Bit += (OriCoin - OriBit) / (a + b) * a;
			Coin -= (OriCoin - OriBit) / (a + b) * b;
			int temp = smaller(Bit, Coin);
			result = bigger(temp, smaller(Bit + a, Coin - b));
		}
		cout << result << '\n';
	}
	return 0;
}