#include <iostream>
#include <algorithm>

using namespace std;

long long n;
const long long MOD = 1000000007;
const long long MAX = 300000;
long long num[MAX];

long long gap0[MAX];

long long fastPow2(long long k){
	long long a=2;
	long long ret=1;
	while(k){
		if(k&1){
			ret *= a;
			ret%=MOD;
		}
		a = a*a%MOD;
		k=k>>1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		num[i] = a;
	}
	sort(num,num+n);
	
	for(long long i=0;i<n;i++){
		gap0[i] = (num[i]-num[0]);
		gap0[i] %=MOD;
	}
	long long G =0;
	for(long long i=1;i<n;i++){
		G+= gap0[i]*fastPow2(i-1)%MOD;
		G%=MOD;
	}
	
	long long ans = G;
	for(long long i=1;i<n-1;i++){
		G = ((G-(gap0[i]-gap0[i-1])%MOD)/2)%MOD - (gap0[i]-gap0[i-1])%MOD * (fastPow2(n-1-i)-1+MOD)%MOD;
		G%=MOD;
		if(G<0){
			G+=MOD;
		}
		ans +=G;
		ans %=MOD;
		if(ans<0){
			ans+=MOD;
		}
	}
	cout<<ans;
	return 0;
}