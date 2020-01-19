#include <iostream>

using namespace std;

int fib[21];

void init(){
    for(int i=0;i<21;i++){
        fib[i]=-1;
    }
    fib[0]=0;
    fib[1]=1;
}

int fibo(int n){
    if(fib[n]!=-1) return fib[n];
    if(fib[n]==-1) fib[n]=fibo(n-1)+fibo(n-2);
    return fibo(n-1)+fibo(n-2);
}

int main(){
    init();
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
    /*
    for(int i=0;i<21;i++){
        cout<<fib[i]<<" ";
    }
    */
    return 0;
}