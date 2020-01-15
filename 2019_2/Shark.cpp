
#include <iostream>
#include <vector>

using namespace std;

class Shark {
	
public:
	int x, y, speed, dir, size;
	static int row, col;


	Shark() {
		x = 0; y = 0; speed = 0; dir = 0; size = 0;
	}
	Shark(int xS, int yS, int speedS, int dirS, int sizeS) {
		x = xS; y = yS; speed = speedS; dir = dirS; size = sizeS;
	}

	void move() {
		if (speed == 0) return;
		switch (dir) {
		case 1:
			speed = speed % (2 * row - 2);
			if (speed <= y - 1) { y = y - speed; }
			else if (speed <= y - 1 + row - 1) { y = 1 + speed - (y - 1); }
			else { y = row - (speed - (y - 1 + row - 1)); }
			break;

		case 2:
			speed = speed % (2 * row - 2);
			if (speed <= row - y) { y = y + speed; }
			else if (speed <= row - y + row - 1) { y = row - (speed - (row - y)); }
			else { y = 1 + speed - (row - y + row - 1); }
			break;

		case 3:
			speed = speed % (2 * col - 2);
			if (speed <= col - x) { x = x + speed; }
			else if (speed <= col - x + col - 1) { x = col - (speed - (col - x)); }
			else {
				x = 1 + speed - (col - x + col - 1);
				break;

		case 4:
			speed = speed % (2 * col - 2);
			if (speed <= x - 1) { x = x - speed; }
			else if (speed <= x - 1 + col - 1) { x = 1 + speed - (x - 1); }
			else { x = col - (speed - (x - 1 + col - 1)); }
			}
		}
	}

	bool isExist() {
		if (x == 0) return false;
		else return true;
	}

	static void setStatic(int r, int c) {
		row = r; col = c;
	}
};

int Shark::row = 0;
int Shark::col = 0;

int main() {

	int row, col, numShark;
	cin >> row >> col >> numShark;
	Shark::setStatic(row, col);

	Shark* Slist =new Shark[numShark];

	Shark** Sea = new Shark * [row+1];
	for (int i = 0; i < row + 1; i++) {
		Sea[i] = new Shark[col + 1];
	}

	for (int i = 0; i < numShark; i++) {
		int rowS, colS, speedS, dirS, sizeS;
		cin >> rowS >> colS >> speedS >> dirS >> sizeS;

		Sea[rowS][colS]=Shark(rowS, colS, speedS, dirS, sizeS);
		Slist[i]=Shark(rowS, colS, speedS, dirS, sizeS);
	}

	int fisherX=1;
	int sumOfShark = 0;

	for (; fisherX < row + 1; fisherX++) {
		//ÇÑÄ­¾¿ ¿·À¸·Î °¡¸é¼­ ÇÏ³ª¾¿ ¸ÔÀ½
		for (int c = 1; c < col + 1; c++) {
			if (Sea[fisherX][c].isExist()) {
				sumOfShark += Sea[fisherX][c].size;
				Sea[fisherX][c] = Shark();
				break;
			}
		}
		for (int i = 0; i < numShark; i++) {
			Slist[i].move();
		}
		for (int i = 0; i < numShark; i++) {

		}
	}

	cout << sumOfShark;
	return 0;
}
