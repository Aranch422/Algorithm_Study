#include <iostream>

using namespace std;

int board[1025][1025];
int sumBoard[1025][1025];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		sumBoard[i][0] = 0;
		int rowSum =0;
		for(int j=1;j<=n;j++){
			cin>>board[i][j];
			rowSum+=board[i][j];
			sumBoard[i][j] = rowSum;
		}
	}
	
	while(m--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int ret=0;
		for(int i=x1;i<=x2;i++){
			ret += sumBoard[i][y2]-sumBoard[i][y1-1];
		}
		cout<<ret<<'\n';
	}
	return 0;
}