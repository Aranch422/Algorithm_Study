#include <iostream>

using namespace std;

int n;

void init(){
    cin>>n;
}

void solve(){
    int num1,num7;
    num1=n/2;
    num7=n%2;
    //7111111
    if(num7==1){
        num1--;
        cout<<7;
        for(int i=0;i<num1;i++){
            cout<<1;
        }
    }
    else{
        for(int i=0;i<num1;i++){
            cout<<1;
        }
    }
}

int main(){
    init();
    solve();
    return 0;
}