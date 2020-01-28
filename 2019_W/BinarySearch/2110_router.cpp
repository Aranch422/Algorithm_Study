#include <iostream>
#include <algorithm>

using namespace std;

long long n,c;
long long num[200001];

long long MAX;

void init(){
    cin>>n>>c;
    for(long long i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num,num+n+1);
    MAX=(num[n]-num[1])/(c-1);
}

long long ret=0;

void solve(){
    long long left=1;
    long long right=MAX;
    while(left!=right){
        //cout<<left<<" "<<right<<endl;
        long long mid=(left+right)/2;
        long long cnt=c-1;
        for(long long i=1;i<n;){
            for(long long k=1;(i+k)<=n;k++){
                if(num[i+k]-num[i]>=mid){
                    cnt--;
                    i=i+k;
                    break;
                }
            }
            //cout<<i<<endl;
            if(num[n]-num[i]<mid){
                break;
            }
        }
        if(cnt<=0){
            ret=mid;
            left=mid+1;
        }
        else right=mid;
    }
    long long mid=(left+right)/2;
    long long cnt=c-1;
    for(long long i=1;i<n;){
        for(long long k=1;i+k<=n;k++){
            if(num[i+k]-num[i]>=mid){
                cnt--;
                i=i+k;
                break;
            }
        }
        if(num[n]-num[i]<mid){
            break;
        }
    }
    if(cnt<=0){
        if(ret<mid) ret=mid;
    }
}

int main(){
    init();
    solve();
    cout<<ret;

    return 0;
}