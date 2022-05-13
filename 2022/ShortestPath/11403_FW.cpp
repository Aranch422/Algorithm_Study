#include <iostream>
#include <vector>

using namespace std;

const int MAX =101;

int adj[MAX][MAX];
int dist[MAX][MAX];

int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>adj[i][j];
			dist[i][j] = adj[i][j];
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k] == 1 && dist[k][j] == 1){
					dist[i][j] =1;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}