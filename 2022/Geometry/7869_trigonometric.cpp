#include <iostream>
#include <cmath>

using namespace std;

double x1,y_1,r1,x2,y2,r2;

double PI = 3.14159265358979;

int main(){
	
	cout<<fixed;
	cout.precision(3);
	cin>>x1>>y_1>>r1>>x2>>y2>>r2;
	if(r2>r1){
		double tempX = x1;
		double tempY = y_1;
		double tempR = r1;
		x1=x2;
		y_1=y2;
		r1=r2;
		
		x2=tempX;
		y2=tempY;
		r2=tempR;
		
	}
	double d = sqrt(pow(x2-x1,2)+pow(y2-y_1,2));
	
	if(r1-r2>=d){
		cout<< PI*r2*r2;
	}
	else if(r1+r2>d){
		double cosTheta1 = (pow(r1,2)+pow(d,2)-pow(r2,2))/(2*r1*d);
		double theta1 = acos(cosTheta1);

		double cosTheta2 = (pow(r2,2)+pow(d,2)-pow(r1,2))/(2*r2*d);
		double theta2 = acos(cosTheta2);

		double area1 = 0.5*pow(r1,2)*(2*theta1-sin(2*theta1));
		double area2 = 0.5*pow(r2,2)*(2*theta2-sin(2*theta2));


		cout<<(area1+area2);	
	}
	else if(r1+r2<=d){
		cout<<0.000000;
	}

	return 0;
}