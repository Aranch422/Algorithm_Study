//long long
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long long n,k;

void init(){
    cin>>n>>k;
}

long long count(long long num){
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        cnt+=min(n,num/i);
    }
    return cnt;
}

void solve(){
    long long left=1;
    long long right=n*n;
    while(left!=right){
        long long mid=(left+right)/2;
        if(count(mid)<k){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    cout<<left<<endl;
}

int main(){
    init();
    solve();

    return 0;
}