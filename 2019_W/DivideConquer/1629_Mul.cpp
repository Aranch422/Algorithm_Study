#include <iostream>
#include <math.h>

using namespace std;

long long a,b,c;
long long Size=0;

void init(){
    cin>>a>>b>>c;
}

long long power(long long n,long long m){
    if(m==0) return 1;
    else if(m==1) return n%c;
    else{
        if(m%2==0){
            return (power(n,m/2)%c)*(power(n,m/2)%c)%c;
        }
        else{
            return (power(n,m/2)%c)*(power(n,m/2+1)%c)%c;
        }
    }
}


int main(){
    init();
    cout<<power(a,b);

    return 0;

}