#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    char temp;
    temp=a[0];
    a[0]=a[2];
    a[2]=temp;
    temp=b[0];
    b[0]=b[2];
    b[2]=temp;

    int aa=stoi(a);
    int bb=stoi(b);
    if(aa<bb) cout<< bb;
    else cout<<aa;

    return 0;
}