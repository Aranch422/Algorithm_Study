#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int x,y,d,t;
	cout<<fixed;
	cout.precision(12);
	cin>>x>>y>>d>>t;
	double dist = sqrt(pow(x,2)+pow(y,2));
	if(d<t){
		cout<<dist;
	}
	else{
		int times = dist/d;
		double r = dist-times*d;

		double line1 = r+t*times;
		double line2 = d-r+t*(times+1);
		double line  = (line1<line2)? line1:line2;
		double poly = t*(times+1);
		if(times == 0 ) poly = t*2;
		if(line<poly) cout<<line;
		else cout<<poly;
	}
	return 0;
}