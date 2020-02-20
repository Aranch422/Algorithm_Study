#include <iostream>
#include <math.h>

using namespace std;

long long n;
long long x[10000];
long long y[10000];

void init(){
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
}

long long tri(long long i,long long j){
    long long  x1,y1,x2,y2;
    x1=x[i]-x[0];
    x2=x[j]-x[0];
    y1=y[i]-y[0];
    y2=y[j]-y[0];
    
    long long ret=(x1*y2-x2*y1);
    return ret;
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(1);

    long long res=0;

    init();
    for(long long i=1;i<n-1;i++){
        res+=tri(i,i+1);
    }
    if(res<0) res= -res;
    cout<<res/2.0;
    return 0;
}