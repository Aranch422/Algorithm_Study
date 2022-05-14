#include <iostream>

using namespace std;

const long long MAX = 1000000;

long long n,m;

long long arr[MAX];
long long remain[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	long long tempSum = 0;
	
	for(long long i=0;i<m;i++){
		remain[i] =0;
	}
	
	for(long long i=0;i<n;i++){
		cin>>arr[i];
		tempSum += arr[i];
		tempSum = tempSum%m;
		remain[tempSum]++;
	}
	long long ans = remain[0];
	for(long long i=0;i<m;i++){
		ans += remain[i]*(remain[i]-1)/2;
	}
	cout<<ans;
	return 0;
}