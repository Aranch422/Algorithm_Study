#include <iostream>

using namespace std;

int n;
int num[100];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
}

bool isPrime(int num){
    if(num ==1) return false;
    for(int i=2;i<32;i++){
        if(num!=i&&num%i==0) return false;
    }
    return true;
}


int main(){
    int cnt=0;
    init();
    for(int i=0;i<n;i++){
        if(isPrime(num[i])) cnt++;
    }
    cout<<cnt;
    return 0;
}