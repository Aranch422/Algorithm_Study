#include <iostream>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	set<int> A,B;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		A.insert(num);
	}
	for(int i=0;i<m;i++){
		int num;
		cin>>num;
		B.insert(num);
	}
	
	int ret = n+m;
	
	for(int a : A){
		if(B.find(a) != B.end()){
			ret -=2;
		}
	}
	cout<<ret;
	return 0;
}