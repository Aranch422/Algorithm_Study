#include <iostream>

using namespace std;

long long fib[91];

void init(){
    for(int i=0;i<91;i++){
        fib[i]=-1;
    }
    fib[0]=0;
    fib[1]=1;
}

long long fibo(int n){
    if(fib[n]!=-1) return fib[n];
    if(fib[n]==-1) {
        fib[n]=fibo(n-1)+fibo(n-2);
        return fib[n];
    }

}

int main(){
    init();

    int n;
    cin>>n;
    cout<<fibo(n)<<endl;

    return 0;
}