#include <iostream>
#include <string>

using namespace std;

string s; string bomb;
char answer[1000001];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> bomb;
	int ansIdx = 0;

	for (int i = 0; i < s.length();i++) {

		answer[ansIdx++] = s[i];
		
		if (answer[ansIdx - 1] == bomb[bomb.length() - 1]) {
			if (i -bomb.length()<0) { continue; }
			
			bool find = true;

			for (int j = 0; j < bomb.length(); j++) {
				if (answer[ansIdx - 1 - j] != bomb[bomb.length() - j - 1]) {
					find = false;
					break;
				}
			}
			if (find) { ansIdx -= bomb.length(); }
			
		}
		
	}
	if (!ansIdx) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < ansIdx; i++) {
			cout << answer[i];
		}
	}
	return 0;
}



