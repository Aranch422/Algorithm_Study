#include <iostream>
#include <algorithm>

using namespace std;

long long n,m;
long long num[10001];

void init(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num,num+n+1);
}

long long MAX=0;

void solve(){
    long long left=1;
    long long right=num[n];
    while(left!=right){
        //cout<<left<<" "<<right<<endl;
        long long mid=(left+right)/2;
        long long value=0;
        for(long long i=1;i<=n;i++){
            value+=num[i]/mid;
        }
        if(value>=m){
            MAX=mid;
            left=mid+1;
        }
        else if(value<m){
            right=mid;
        }

    }
    long long mid=(left+right)/2;
    long long value=0;
    for(long long i=1;i<=n;i++){
        value+=num[i]/mid;
    }
    if(value>=m){
        if(MAX<mid) MAX=mid;
        return;
    }
}

int main(){
    init();
    solve();
    cout<<MAX;
    return 0;
}