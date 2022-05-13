#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int n,a,b;
	cin>>n>>a>>b;
	double dist = sqrt( pow(a,2)+ pow(b,2));
	
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		if(s<=dist){
			cout<<"DA\n";
		}
		else{
			cout<<"NE\n";
		}
	}
	return 0;
}