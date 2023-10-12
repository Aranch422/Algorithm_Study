#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<string> board;

struct Coord
{
	int r, c;
	string color;
};

struct State
{
	Coord red, blue;
	int dist;
};

Coord Red,Blue;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main()
{
	cin >> N >> M;
	board = vector<string>(N);
	for(int i=0;i<N;i++)
	{
		cin >> board[i];
		for(int j=0;j<M;j++)
		{
			if(board[i][j] == 'R')
			{
				Red.r = i;
				Red.c = j;
				Red.color = "red";
				board[i][j] = '.';
			}
			else if(board[i][j] == 'B')
			{
				Blue.r = i;
				Blue.c = j;
				Blue.color = "blue";
				board[i][j] = '.';
			}
		}
	}
	queue<State> myQ;
	myQ.push({ Red,Blue,0 });

	while(!myQ.empty())
	{
		State curState = myQ.front();
		myQ.pop();
		if(curState.dist >=10)
		{
			continue;
		}

		bool isTerminate = false;
		Coord red = curState.red;
		Coord blue = curState.blue;

		for(int i=0;i<4;i++)
		{
			Coord first, second;
			if(i==0)
			{
				if(red.r<blue.r)
				{
					first = red;
					second = blue;
				}
				else
				{
					first = blue;
					second = red;
				}
			}
			else if (i == 1)
			{
				if (red.c > blue.c)
				{
					first = red;
					second = blue;
				}
				else
				{
					first = blue;
					second = red;
				}
			}
			else if (i == 2)
			{
				if (red.r >blue.r)
				{
					first = red;
					second = blue;
				}
				else
				{
					first = blue;
					second = red;
				}
			}
			else if (i == 3)
			{
				if (red.c < blue.c)
				{
					first = red;
					second = blue;
				}
				else
				{
					first = blue;
					second = red;
				}
			}

			bool isRedIn = false;
			bool isBlueIn = false;
			while (board[first.r + dr[i]][first.c + dc[i]] == '.')
			{
				first.r += dr[i];
				first.c += dc[i];
			}

			if (board[first.r + dr[i]][first.c + dc[i]] == 'O')
			{
				if (first.color == "red")
				{
					isRedIn = true;
				}
				else
				{
					isBlueIn = true;
				}
			}
			else{
				board[first.r][first.c] = 'B';
			}

			while (board[second.r + dr[i]][second.c + dc[i]] == '.')
			{
				second.r += dr[i];
				second.c += dc[i];
			}

			if (board[second.r + dr[i]][second.c + dc[i]] == 'O')
			{
				if (second.color == "red")
				{
					isRedIn = true;
				}
				else
				{
					isBlueIn = true;
				}
			}

			if (isRedIn && !isBlueIn)
			{
				isTerminate = true;
				break;
			}
			else if(isBlueIn)
			{
				
			}
			else
			{
				if(first.color == "red")
				{
					myQ.push({ first,second,curState.dist + 1 });
				}
				else
				{
					myQ.push({ second,first,curState.dist + 1 });
				}
			}
			board[first.r][first.c]='.';
		}

		if(isTerminate)
		{
			cout << curState.dist + 1;
			return 0;
		}
	}
	cout << -1;

	return 0;
}