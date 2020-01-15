#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Taxi {
public:
	int fuel;
	int fuelLimit;
	int money;
	Passenger* myP[4];
	int numOfP;

	int X, Y;

	Taxi() {
		fuelLimit = 0;
		fuel = 0;
		money = 0;
		numOfP = 0;
	}
	
	Taxi(int A) {
		fuelLimit = 0;
		fuel = A;
		money = 0;
		numOfP = 0;
	}

	//시작위치 초기화
	void move(int x, int y) {
		X = x; Y = y;
	}

	//탑승
	void takeOn(Passenger P) {
		myP[numOfP] = &P;
		numOfP++;
	}

	//하차,돈
	int takeOff() {
		money += myP[numOfP]->distance;
		delete myP[numOfP];
		numOfP--;
	}

	int oiling(int c) {
		//가득채울 돈이 있으면
		if (money >=(int) ((fuelLimit - fuel) * c)) {
			money -= (int)((fuelLimit - fuel) * c);
		}
		else {
			fuel += int(money / c);
			money -= int(money / c);
		}
	}
};

class Passenger {
public:
	Map start, end;
	int distance;
	Passenger() {
		distance = 0;
	}

	Passenger(Map S, Map E) {
		start = S; end = E;
		distance = abs(S.xcor - E.xcor) + abs(S.ycor - E.ycor);
	}
};

struct Map {
public:
	string name;
	int xcor, ycor;
	bool isOilStation = false;
};

int main() {

	int A, B, C;
	cin >> A >> B >> C;
	Taxi myT(A);
	int lines=0;
	cin >> lines;
	Map* myMap = new Map[lines];

	// 이름 x y 저장
	while (lines != 0) {
		lines--;
		string cont;
		string xcor,ycor;
		cont=cin.getline;
		for (int i = cont.length; ;i=cont.length) {
			if (cont.at(i) != ' ') {
				xcor.push_back(cont[i]);
				cont.pop_back();
			}
			else {
				cont.pop_back();
				break;
			}
		}

		for (int i = cont.length; ; i = cont.length) {
			if (cont.at(i) != ' ') {
				ycor.push_back(cont[i]);
				cont.pop_back();
			}
			else {
				cont.pop_back();
				break;
			}
		}
		
		xcor = reverse(xcor);
		ycor = reverse(ycor);

		Map mmap;
		mmap.name = cont;
		mmap.xcor = atoi(xcor.c_str()); mmap.ycor = atoi(ycor.c_str());
		myMap[lines] = mmap;
	}

	//주유소
	for (int i = 0; i < 3; i++) {

	}

	//void game() {
		string line = cin.getline;
		string dest;
		//go to라면
		if (line.find("Go to") != string::npos) {
			dest = line.substr(6, line.length - 6);
			for (int i = 0; i < lines; i++) {
				if (myMap[i].name.compare(dest)) {

				}
			}
		}

		//승객을 태운다면
		else if (line.find("Pickup a passenger going to") != string::npos) {
			dest = line.substr(28, line.length - 28);
		}
	//}

}

string reverse(string s) {
	for (int i = 0; i < s.length / 2; i++) {
		char temp = s[i];
		s[i] = s[s.length - 1 - i];
		s[s.length - 1 - i]=temp;
	}
	return s;
}
