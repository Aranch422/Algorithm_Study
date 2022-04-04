#include <iostream>

#define INF 2000000000000
#define UPPER 200000000000
using namespace std;


long long n,m;

long long dist[101][101];

void floid(){
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}

int main(){

	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			dist[i][j]=INF;
			if(i==j) dist[i][j]=0;
		}
	}
	for(long long i=0;i<m;i++){
		long long r,c,cost;
		cin>>r>>c>>cost;
		if(dist[r][c]>cost){
			dist[r][c] = cost;	
		}
	}
	floid();
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(dist[i][j]>=UPPER) cout<<0<<" ";
			else{
				cout<<dist[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}