#include <iostream>
#include <vector>

using namespace std;

long long n;
vector<long long> prime;
vector<long long> primeSum;

bool isPrime[4000001];

long long biSearch(long long left, long long right, long long target){
	long long mid = (left + right)/2;
	if(left == right){
		if(primeSum[mid]==target){
			return mid;
		}
		else return -1;
	}
	else{
		if(primeSum[mid]==target) return mid;
		else if(primeSum[mid]<target) return biSearch(mid+1,right,target);
		else return biSearch(left,mid,target);
	}
	
}

int main(){
	cin>>n;
	long long sum = 0;
	for(long long i=0;i<=n;i++){
		isPrime[i]=true;
	}
	isPrime[0]=false;
	isPrime[1]=false;
	
	for(long long i=2;i<=n;i++){
		if(isPrime[i] == false) continue;
		for(long long j=i*2;j<=n;j+=i){
			isPrime[j]=false;
		}
	}
	for(long long i=0;i<=n;i++){
		if(isPrime[i]){
			prime.push_back(i);
			sum = sum +i;
			primeSum.push_back(sum);
		}
	}
	long long answer = 0;
	
	long long len = prime.size();
	if(n == 1){
		cout<<0;
		return 0;
	}
	else if(n==2){
		cout<<1;
		return 0;
	}
	
	long long target,loc;
	target =n;
	loc = biSearch(0,len-1,target);
	if(loc!=-1) answer++;
	
	for(long long i=1;i<len;i++){
		target = primeSum[i-1]+n;
		loc = biSearch(i,len-1,target);
		if(loc!=-1) answer++;
	}
	cout<<answer;
	return 0;
}