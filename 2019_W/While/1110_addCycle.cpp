#include <iostream>

using namespace std;

int cycle(int n){
    int a,b,s;
    b=n%10;
    n=n/10;
    a=n%10;
    s=(a+b)%10;
    return 10*b+s;
}


int main(){
    int n;
    cin>>n;
    int ori=n;
    int cnt=0;
    while(1){
        cnt++;
        int cyc=cycle(n);
        if(ori==cyc) break;
        n=cyc;

    }
    cout<<cnt;
    return 0;
}