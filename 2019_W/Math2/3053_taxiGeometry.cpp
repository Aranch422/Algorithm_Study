#include <iostream>
#include <math.h>

const double pi = 3.14159265358979323846264;

using namespace std;

int main(){

    cout.setf(ios::fixed);
    cout.precision(6);
    int n;
    cin>> n;
    cout<<n*n*pi<<endl;
    cout<< 2*n*n;


}