#include <iostream>

using namespace std;

int n;

int num5,num3;

void init(){
    cin>>n;
}

void solve(){
    if(n%5==0){
        cout<<n/5;
        return;
    }

    num5 = n/5+1;
    num3=0;
    if(num5%2!=n%2) num5++;

    while(5*num5+3*num3!=n&&num5>=0){
        num5--;
        num3++;
    }

    if(num5<0){
        cout << -1;
        return;
    }
    else{
        cout<< num5+num3;
        return;
    }

}


int main(){
    init();
    solve();
    return 0;
}