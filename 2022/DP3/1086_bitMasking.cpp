#include <iostream>

using namespace std;

int dp[1<<15][100];
int num[15]
int n,k;

void getRemain(int state){
	for(int i=0;i<n;i++){
		if(state & 1<<i){
			continue;
		}
		else{
			for(int i=0;i<k;i++){
				if
			}
		}
	}
}

int main(){
	for(int i=n-1;i>=0;i--){
		cin>>num[i];
	}
	cin>>k;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<k;j++){
			dp[i][j] = 0;
		}
	}
	
	return 0;
}