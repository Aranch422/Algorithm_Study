#include <iostream>
#include <vector>

using namespace std;

int main(){
	long long n;
	cin>>n;
	long long ori =n;
	bool isPossible[1000001];
	for(long long i=1;i*i<=n;i++){
		isPossible[i] = true;
	}
	
	vector<long long> V;
	for(long long i=2;i*i<=ori;i++){
		if(isPossible[i]){
			if(n%i ==0){
				V.push_back(i);
				for(long long j=i;j*j<=ori;j+=i){
					isPossible[i] = false;
				}
				while(n%i==0){
					n=n/i;
				}
			}	
		}
	}
	if(n!=1){
		V.push_back(n);	
	}
	long long Len = V.size();
	long long ret = ori;
	for( auto item : V){
		//cout<<item<<" ";
		ret = ret/item*(item-1);
	}
	cout<<ret;
	return 0;
}