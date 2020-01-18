#include <iostream>

using namespace std;

int M,N;

void init(){
    cin>>M>>N;
}

bool isPrime(int num){
    if(num ==1) return false;
    for(int i=2;i<=100;i++){
        if(num!=i&&num%i==0) return false;
    }
    return true;
}

int main(){
    int sum=0;
    int min=0;
    init();
    for(int i=M;i<=N;i++){
        if(isPrime(i)){
            if(sum==0) min=i;
            sum+=i;   
        }
    }
    if(sum==0) {
        cout<<-1;
        return 0;
    }
    cout<< sum<<endl;
    cout<< min;
    return 0;
}