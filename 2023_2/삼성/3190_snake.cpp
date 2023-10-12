#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> nextDir;

struct Coord
{
	int r, c;
};

queue<Coord> snake;
int N;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int r, c;
int dir = 1;

int dirIdx = 0;

int main()
{
	cin >> N;

	board = vector<vector<int>>(N+1, vector<int>(N+1,0));
	board[1][1] = 1;
	r = 1; c = 1;
	snake.push({ 1,1 });

	int numApp;
	cin >> numApp;
	for(int i=0;i<numApp;i++)
	{
		int rr, cc;
		cin >> rr >> cc;
		board[rr][cc] = 4;
	}
	int changeDir;
	cin >> changeDir;
	for(int i=0;i<changeDir;i++)
	{
		int time;
		char dir;
		int ddir;
		cin>>time>>dir;
		switch(dir)
		{
		case 'L':
			ddir = -1;
			break;
		case 'D':
			ddir = 1;
			break;
		default:
			ddir = 0;
		}
		nextDir.push_back({ time,ddir });
	}


	int time = 0;
	while(time++>=0)
	{
		r += dr[dir];
		c += dc[dir];
		//cout<<r<<' '<<c<<endl;
		if (r <= 0 || N < r || c <= 0 || N < c)
		{
			break;
		}
		if(board[r][c] == 1)
		{
			break;
		}

		snake.push({ r,c });
		if(board[r][c] == 4)
		{
			
		}
		else
		{
			Coord temp = snake.front();
			board[temp.r][temp.c] = 0;
			snake.pop();
		}
		board[r][c] = 1;

		if(time == nextDir[dirIdx].first)
		{
			dir += nextDir[dirIdx].second;
			if(dir<0)
			{
				dir += 4;
			}
			else if(4<=dir)
			{
				dir -= 4;
			}
			dirIdx++;
		}
	}
	cout << time;
	return 0;
}