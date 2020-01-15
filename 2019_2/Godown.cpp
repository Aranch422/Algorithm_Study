#include <iostream>
#include <stack>
#include <cstring>

using namespace std;


/* 시간초과 코드, 메모이제이션이 없어서 너무 많이 탐색함
int Answer = 0;

struct node {
public:
	int height=0;
	node* up=NULL;
	node* right=NULL;
	node* left=NULL;
	node* down=NULL;


};

void check(node* start, stack<node> myS) {

	// 마지막꺼면 리턴
	if (start->right == NULL && start->down == NULL) {
		/*
		stack<node> tempS;
		while (!myS.empty()) {
			int tempI;
			tempI = myS.top().height;
			tempS.push(myS.top());
			myS.pop();
			cout << tempI;
		}
		//
		Answer++;
		return;
	}


	myS.push(*start);
	if (start->right != NULL) {
		if (start->height > start->right->height) {
			check(start->right, myS);
		}
	}


	if (start->down != NULL) {
		if (start->height > start->down->height) {
			check(start->down, myS);
		}
	}
	if (start->left != NULL) {
		if (start->height > start->left->height) {
			check(start->left, myS);
		}
	}
	if (start->up != NULL) {
		if (start->height > start->up->height) {
			check(start->up, myS);
		}
	}
	myS.pop();
	return;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int row, col;
	cin >> row >> col;

	// node board
	node** Board = new node* [row];
	for (int i = 0; i < col; i++) {
		Board[i] = new node[col];
	}

	//board cin
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> Board[i][j].height;
		}
	}

	//구석

	//왼쪽위에
	Board[0][0].right = &Board[0][1];
	Board[0][0].down = &Board[1][0];
	

	//왼쪽 아래
	Board[row - 1][0].right = &Board[row - 1][1];
	Board[row - 1][0].up = &Board[row - 2][0];

	Board[row - 1][col - 1].left = &Board[row - 1][col - 2];
	Board[row - 1][col - 1].up = &Board[row - 2][col - 1];

	Board[0][col - 1].left = &Board[0][col - 2];
	Board[0][col - 1].down = &Board[1][col - 1];

	//줄
	for (int j = 1; j < col - 1; j++) {
		Board[0][j].right = &Board[0][j + 1];
		Board[0][j].left = &Board[0][j - 1];
		Board[0][j].down = &Board[1][j];

		Board[row-1][j].right = &Board[row-1][j + 1];
		Board[row - 1][j].left = &Board[row-1][j-1];
		Board[row - 1][j].up = &Board[row-2][j];
	}
	for (int i = 1; i < row - 1; i++) {
		Board[i][0].right = &Board[i][1];
		Board[i][0].up = &Board[i-1][0];
		Board[i][0].down = &Board[i+1][0];

		Board[i][col - 1].left = &Board[i][col - 2];
		Board[i][col - 1].up = &Board[i-1][col - 1];
		Board[i][col - 1].down = &Board[i+1][col - 1];
	}


	//중간
	for (int i = 1; i < row-1; i++) {
		for (int j = 1; j < col-1; j++) {
			Board[i][j].left = &Board[i][j - 1];
			Board[i][j].right = &Board[i][j + 1];
			Board[i][j].up = &Board[i-1][j];
			Board[i][j].down = &Board[i+1][j];
		}
	}
	
	
	

	stack<node> S;
	check(&Board[0][0], S);

	cout << Answer;

	return 0;
}
*/


int map[501][501];
int DP[501][501];

int M, N;

void start() {
	//input 초기화
	cin >> M >> N;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1;j++) {
			cin >> map[i][j];
		}
	}

	//DP 초기화 -1로
	memset(DP, -1, sizeof(DP));
}

bool isIn(int y,int x) {
	return y >= 1 && y <= M && x >= 1 && x <= N;
}

int isGoingDown(int y,int x, int newY,int newX) {
	if (map[y][x] > map[newY][newX]) return true;
	else return false;
}

int solve(int y, int  x) {
	// 핵심!!
	int &result = DP[y][x];
	if (x == N && y == M) return 1;
	if (result != -1) return result;
	result = 0;

	if (isIn(y - 1, x) && isGoingDown(y, x, y - 1, x)) {
		result += solve(y - 1, x);
	}
	if (isIn( y+1, x) && isGoingDown(y, x, y+1, x )) {
		result += solve(y+1,x);
	}
	if (isIn(y, x - 1) && isGoingDown(y, x, y, x - 1)) {
		result += solve(y, x - 1);
	}
	if (isIn( y, x + 1) && isGoingDown(y, x, y, x + 1)) {
		result += solve(y, x + 1);
	}
	return result;
}

int main() {
	start();

	cout << solve(1, 1)<<endl;

	return 0;
}