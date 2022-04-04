#include <iostream>

#define INF 2000000000000
#define UPPER 200000000000
long long dist[501][501];

using namespace std;

long long n,m;

void floid(){
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
}

int main(){
	
	for(long long i=0;i<501;i++){
		for(long long j=0;j<501;j++){
			if(i==j){
				dist[i][j]=0;
			}
			else{
				dist[i][j]=INF;
			}
		}
	}
	
	cin>>n>>m;
	for(long long i=0;i<m;i++){
		long long r,c,cost;
		cin>>r>>c>>cost;
		if(dist[r][c]>cost){
			dist[r][c] = cost;	
		}
	}
	
	floid();
	
	bool isMinusLoop = false;
	
	if(dist[1][1]!=0) isMinusLoop=true;
	for(long long i=2;i<=n;i++){
		if(dist[i][i]!=0 && dist[1][i]<UPPER){
			isMinusLoop = true;
			break;
		}
	}
	
	if(isMinusLoop){
		cout<<-1;
	}
	else{
		for(long long i=2;i<=n;i++){
			dist[1][i]>=UPPER? cout<<-1<<endl:cout<<dist[1][i]<<endl;
		}
	}
	return 0;
}