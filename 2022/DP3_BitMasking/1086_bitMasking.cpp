#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long long dp[1<<15][100];
string numStr[15];
long long sizeOfNum[15];
long long numR[15];
long long remainOfTenPower[51];
bool isVisited[1<<15];
long long n,k;


long long convertToInt(string str){
	long long ret = 0;
	long long len = str.size();
	long long front = len;
	long long i=0;
	for(i=0;i<len/8;i++){
		front -= 8;
		long long temp =  stoi(str.substr(front,8))%k;
		if(i !=0){
			temp = temp * remainOfTenPower[8*i];	
		}
		temp = temp%k;
		ret+= temp;
		ret %=k;
	}
	if(front != 0 && i!=0){
		long long temp =  stoi(str.substr(0,front))%k;	
		temp = temp * remainOfTenPower[8*i];
		temp = temp%k;
		ret+= temp;	
	}
	else if( i==0){
		long long temp =  stoi(str.substr(0,front))%k;	
		temp = temp%k;
		ret+= temp;	
	}
	return ret%k;
}

void getRemain(){
	for(long long state =0;state<(1<<n);state++){
		for(long long i=0;i<n;i++){
			if(state & 1<<i){
				continue;
			}
			else{
				long long newState = state | 1<<i;
				long long digit = sizeOfNum[i]; 
				for(long long r=0;r<k;r++){
					long long newRemain = (r*remainOfTenPower[digit] + numR[i])%k;
					dp[newState][newRemain] += dp[state][r];
					//cout<<dp[newState][newRemain]<<endl;
				}
			}
		}	
	}
}

int main(){
	cin>>n;
	for(long long i=n-1;i>=0;i--){
		cin>>numStr[i];
		sizeOfNum[i] = numStr[i].size();
	}
	cin>>k;
	
	long long temp = 1;
	remainOfTenPower[0] = 0;
	for(long long i=1;i<=50;i++){
		temp = temp*10;
		temp = temp%k;
		remainOfTenPower[i] = temp; 
	}
	
	for(long long i=n-1;i>=0;i--){
		numR[i]= convertToInt(numStr[i]);
	}
	
	for(long long i=0;i<(1<<n);i++){
		for(long long j=0;j<k;j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0]=1;
	getRemain();
	long long ans=dp[(1<<n)-1][0];
	long long cut=1;
	for(long long i=1;i<=n;i++){
		cut *=i;
	}
	long long a = cut;
	long long b= ans;
	long long r = -1;
	while(r!=0 && b!=0){
		r = a%b;
		a= b;
		b = r;
	}
	
	cout<<ans/a<<"/"<<cut/a;
	return 0;
}