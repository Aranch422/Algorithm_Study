#include <iostream>

using namespace std;

int N;

int n;

int* arr;

void init(){
    cin>>n;
    
    arr = new int[n+1];

    int i=1;
    while(i++<=n){
        cin>>arr[i];
    }
}

void solve(){
    
}

int main(){
    cin>>N;
    while(N-->0){
        init();
    }

    return 0;
}