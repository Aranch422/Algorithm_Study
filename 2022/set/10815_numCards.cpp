#include <iostream>
#include <set>

using namespace std;

int n,m;

set<int> mySet;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		mySet.insert(num);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int num;
		cin>>num;
		cout<< (mySet.find(num) != mySet.end())<<" ";
	}
	return 0;
}