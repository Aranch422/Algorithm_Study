#include <iostream>

#define INF 9000000000000
#define UPPER 8000000000000
using namespace std;

long long n,m;

long long dist[401][401];

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
		}
	}
	
	for(long long i=0;i<m;i++){
		long long r,c,cost;
		cin>>r>>c>>cost;
		if(dist[r][c]>cost){
			dist[r][c]=cost;
		}
	}
	floid();
	long long minimum = INF;
	for(long long i=1;i<=n;i++){
		if(dist[i][i]!=INF){
			if(minimum>dist[i][i]){
				minimum = dist[i][i];
			}
		}
	}
	
	minimum==INF? cout<<-1:cout<<minimum;

	return 0;
}