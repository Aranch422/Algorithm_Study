#include <iostream>
#include <math.h>

using namespace std;

int target;

bool isPrime(int num){
    if(num==1) return false;
    for(int i=2;i<=sqrt(num);i++){
        if(num!=i&&num%i==0) return false;
    }
    return true;
}

void solve(){
    int a,b;
    a=target/2;
    b=a;
    while(b>1){
        if(isPrime(a)&&isPrime(b)) {
            cout<<b<<" "<<a<<endl;
            return;
        }
        a++;
        b--;
    }

}

int main(){
    int n;
    cin>>n;
    while(n>0){
        n--;
        cin>>target;
        solve();
    }

    return 0;
}