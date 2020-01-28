#include <iostream>
#include <algorithm>

using namespace std;

long long n,m;

long long height[1000001];
long long sum[1000001];


//n
void init(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>height[i];
    }
    sort(height,height+n+1);
    for(long long i=1;i<=n;i++){
        sum[i]=sum[i-1]+height[i];
    }
}


//log n
long long BS(long long T,long long left,long long right){
    if(left==right) return left;
    long long mid=(left+right)/2;
    if(T<=height[mid]) return BS(T,left,mid);
    else return BS(T,mid+1,right);
}
long long MAX=0;

//logn log
void solve(){
    long long left=0;
    long long right=height[n];
    long long value=0;
    while(left!=right){
        //cout<<left<<" "<<right<<endl;
        long long midH=(left+right)/2;
        long long pos =BS(midH,1,n);
        value = sum[n]-sum[pos-1];
        value=value-midH*(n-pos+1);
        if(value>=m){
            MAX=midH;
            left=midH+1;
        }
        else{
            right=midH;
        }
    }
    long long midH=(left+right)/2;
    long long pos =BS(midH,1,n);
    value = sum[n]-sum[pos-1];
    value=value-midH*(n-pos+1);
    if(value>=m){
        MAX=midH;
    }
    cout<<MAX;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();
    return 0;
}