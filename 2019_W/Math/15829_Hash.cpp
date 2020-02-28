#include <iostream>

using namespace std;


int main(){
    long long n;
    cin>>n;
    string s;
    cin>>s;
    long long sum=0;
    long long r=1; long long M=1234567891;
    for(long long i=0;i<n;i++){
        sum+=((long long)(s[i]-96)*r);
        sum=sum%M;
        r=r*31;
        r=r%M;
    }
    cout<<sum;
    return 0;
}