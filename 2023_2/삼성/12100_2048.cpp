#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> board;

int N;

int DFS(int curLevel)
{
	//cout<<curLevel;
	if (curLevel == 5)
	{
		int myMax = -1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (myMax < board[curLevel][i][j])
				{
					myMax = board[curLevel][i][j];
				}
			}
		}
		return myMax;
	}

	int nextLevel = curLevel + 1;

	vector<vector<int>>& curBoard = board[curLevel];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(curBoard[i][j] == -1){
				curBoard[i][j] =0;
			}
		}
	}


	vector<vector<int>>& nextBoard = board[nextLevel];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			nextBoard[i][j]=0;
		}
	}
	//UP
	for (int c = 0; c < N; c++)
	{
		nextBoard[0][c] = curBoard[0][c];
	}
	for (int r = 1; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (curBoard[r][c] == 0)
			{
				continue;
			}
			for (int k = r - 1; k >= 0; k--)
			{

				if (nextBoard[k][c] == curBoard[r][c])
				{
					nextBoard[k][c] *= 2;
					nextBoard[k + 1][c] = -1;
					break;
				}
				if (nextBoard[k][c] == -1)
				{
					nextBoard[k][c] = curBoard[r][c];
					break;
				}
				if (nextBoard[k][c] == 0)
				{
					if (k == 0)
					{
						nextBoard[k][c] = curBoard[r][c];
					}
					continue;
				}
				if (nextBoard[k][c] > 0)
				{
					nextBoard[k + 1][c] = curBoard[r][c];
					break;
				}
			}
		}
	}

	int up = DFS(nextLevel);

	//Down
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			nextBoard[i][j]=0;
		}
	}
	for (int c = 0; c < N; c++)
	{
		nextBoard[N - 1][c] = curBoard[N - 1][c];
	}
	for (int r = N - 2; r >= 0; r--)
	{
		for (int c = 0; c < N; c++)
		{
			if (curBoard[r][c] == 0)
			{
				continue;
			}
			for (int k = r + 1; k < N; k++)
			{

				if (nextBoard[k][c] == curBoard[r][c])
				{
					nextBoard[k][c] *= 2;
					nextBoard[k - 1][c] = -1;
					break;
				}
				if (nextBoard[k][c] == -1)
				{
					nextBoard[k][c] = curBoard[r][c];
					break;
				}
				if (nextBoard[k][c] == 0)
				{
					if (k == N-1)
					{
						nextBoard[k][c] = curBoard[r][c];
					}
					continue;
				}
				if (nextBoard[k][c] > 0)
				{
					nextBoard[k - 1][c] = curBoard[r][c];
					break;
				}
			}
		}
	}

	int down = DFS(nextLevel);

	//Left
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			nextBoard[i][j]=0;
		}
	}
	for (int r = 0; r < N; r++)
	{
		nextBoard[r][0] = curBoard[r][0];
	}
	for (int c = 1; c < N; c++)
	{
		for (int r = 0; r < N; r++)
		{
			if (curBoard[r][c] == 0)
			{
				continue;
			}
			for (int k = c - 1; k >= 0; k--)
			{

				if (nextBoard[r][k] == curBoard[r][c])
				{
					nextBoard[r][k] *= 2;
					nextBoard[r][k + 1] = -1;
					break;
				}
				if (nextBoard[r][k] == -1)
				{
					nextBoard[r][k] = curBoard[r][c];
					break;
				}
				if (nextBoard[r][k] == 0)
				{
					if (k == 0)
					{
						nextBoard[r][k] = curBoard[r][c];
					}
					continue;
				}
				if (nextBoard[r][k] > 0)
				{
					nextBoard[r][k + 1] = curBoard[r][c];
					break;
				}
			}
		}
	}

	int left = DFS(nextLevel);

	//Right
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			nextBoard[i][j]=0;
		}
	}
	for (int r = 0; r < N; r++)
	{
		nextBoard[r][N - 1] = curBoard[r][N - 1];
	}
	for (int c = N - 2; c >= 0; c--)
	{
		for (int r = 0; r < N; r++)
		{
			if (curBoard[r][c] == 0)
			{
				continue;
			}
			for (int k = c + 1; k < N; k++)
			{

				if (nextBoard[r][k] == curBoard[r][c])
				{
					nextBoard[r][k] *= 2;
					nextBoard[r][k - 1] = -1;
					break;
				}
				if (nextBoard[r][k] == -1)
				{
					nextBoard[r][k] = curBoard[r][c];
					break;
				}
				if (nextBoard[r][k] == 0)
				{
					if (k == N-1)
					{
						nextBoard[r][k] = curBoard[r][c];
					}
					continue;
				}
				if (nextBoard[r][k] > 0)
				{
					nextBoard[r][k - 1] = curBoard[r][c];
					break;
				}
			}
		}
	}

	int right = DFS(nextLevel);


	int myMax = up;
	if (myMax < down)
	{
		myMax = down;
	}
	if (myMax < left)
	{
		myMax = left;
	}
	if (myMax < right)
	{
		myMax = right;
	}
	return myMax;
}


int main()
{
	board = vector<vector<vector<int>>>(6);
	cin >> N;
	board[0] = vector<vector<int>>(N);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int x;
			cin >> x;
			board[0][i].push_back(x);
		}
	}

	for(int i=1;i<6;i++)
	{
		board[i] = vector<vector<int>>(N, vector<int>(N, 0));
	}
	cout << DFS(0);
	return 0;
 }