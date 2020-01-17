#include <iostream>

using namespace std;

int main(){
    long double a,b;

    cout.setf(ios::fixed);
    cout.precision(10);

    cin >>a>>b;
    cout<<a/b;

    return 0;
}