#include <iostream>

using namespace std;

long long n,k;
long long R=1000000007;

void init(){
    cin>>n>>k;
}


long long power(long long a,long long b){
    //cout<<b<<endl;
    if(b==0) return 1;
    if(b==1) return a%R;
    else{
        if(b%2==0){
            long long half=power(a,b/2)%R;
            return (half*half)%R;
        }
        else{
            return (a*power(a,b-1))%R;
        }
    }
}


long long nck(){
    long long nFac=1;
    for(long long i=1;i<=n;i++){
        nFac*=i;
        nFac=nFac%R;
    }
    //cout<<"N\n";
    long long kFac=1;
    for(long long i=1;i<=n-k;i++){
        kFac*=i;
        kFac=kFac%R;
    }
    //cout<<"n-k\n";
    for(long long i=1;i<=k;i++){
        kFac*=i;
        kFac=kFac%R;
    }
    //cout<<"K\n";
    long long under=kFac%R;
    //cout<<"under\n";
    return ((nFac%R)*(power(under,R-2)%R))%R;
}

int main(){
    init();
    cout<<nck();
    //cout<<"end";
    return 0;
}