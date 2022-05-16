#include <iostream>
#include <cmath>

using namespace std;

const long long MAX = 4000001;
long long MOD = 1000000007;

long long fact[MAX];

long long myPow(long long n, long long k){
	long long ret = 1;
	while(k){
		if(k&1){
			ret *=n;
			ret %=MOD;
		} 
		n = n*n%MOD;
		k = k>>1;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fact[0] = 1;
	for(long long i=1;i<MAX;i++){
		fact[i] = fact[i-1]*i%MOD;
	}
	int M;
	cin>>M;
	while(M--){
		long long n,k;
		cin>>n>>k;
		long long ans = fact[n]*myPow(fact[n-k]*fact[k]%MOD,MOD-2)%MOD;
		cout<< ans<<"\n";
	}
	return 0;
}
//https://modoocode.com/313