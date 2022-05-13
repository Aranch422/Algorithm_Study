#include <iostream>
#include <cmath>

using namespace std;
int w,h,x,y,n;

bool isIn(int a,int b){
	if(a<x){
		return sqrt( pow(x-a,2) + pow(y+h/2-b,2)) <= h/2;
	}
	else if(x+w<a){
		return sqrt( pow(x+w-a,2) + pow(y+h/2-b,2)) <= h/2;
	}
	else{
		if(x<=a && a<=x+w && y<=b && b<= y+h){
			return true;
		}
	}
	return false;
}
int main(){
	cin>>w>>h>>x>>y>>n;
	int cnt =0;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(isIn(a,b)){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}