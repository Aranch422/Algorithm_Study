#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int n;
int Size=0;
int num[100],factor[1000];
int Max=0;
void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
}

int gcd(int a,int b){
    return a%b? gcd(b,a%b):b;
}

void solve(){
    int m=num[1]-num[0];
    //j%i
    for(int i=2;i<n;i++){
        m=gcd(num[i]-num[i-1],m);
    }

    for(int i=1;i*i<=m;i++){
        if(m%i==0) {
            if(m!=i*i) factor[Size++]=m/i;
            if(i!=1) factor[Size++]=i;
        }    
    }
    sort(factor,factor+Size);
    for(int i=0;i<Size;i++){
        cout<<factor[i]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}