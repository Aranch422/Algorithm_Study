#include <iostream>

using namespace std;

long long n;

int main(){
    cin>>n;
    long long k=2;
    for(long long i=1;i<n;i++){
        k=k*2;
    }
    long long r,c;
    cin>>r>>c;
    long long mid=k;
    long long sum=0;
    while(mid!=1){
        mid=mid/2;
        //cout<<mid<<'\n';
        long long ret =0;
        if(r<mid&&c<mid) ret=0;
        else if(r<mid&&mid<=c) {
            ret=1;
            c=c-mid;
        }
        else if(mid<=r&&c<mid) {
            ret=2;
            r=r-mid;
        } 
        else {
            ret=3;
            r=r-mid;
            c=c-mid;
        }
        sum+=mid*mid*ret;
    }
    cout<<sum;
}