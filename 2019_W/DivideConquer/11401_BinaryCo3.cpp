#include <iostream>

using namespace std;

long long n,k;
long long R=1000000007;

void init(){
    cin>>n>>k;
}

long long nck(int a,int b){
    if(a==b) return 1;
    if(b==0) return 1;
    else{
        return nck(a-1,b-1)%R+nck(a-1,b)%R;
        
    }
}
