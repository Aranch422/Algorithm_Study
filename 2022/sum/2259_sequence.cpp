#include <iostream>

using namespace std;

const int MAX = 100000;

int num[MAX];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int tempSum=0;
	for(int i=0;i<k;i++){
		tempSum +=num[i];
	}
	int Sum = tempSum;
	for(int i = k; i<n;i++){
		tempSum = tempSum +num[i] - num[i-k];
		if(tempSum>Sum){
			Sum = tempSum;
		}
	}
	cout<<Sum;
	return 0;
}