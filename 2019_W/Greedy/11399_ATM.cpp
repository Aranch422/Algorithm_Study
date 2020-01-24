#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[1001];

void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num,num+1+n);
}

void solve(){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=num[i]*(n+1-i);
    }
    cout<<sum;
}


int main(){
    init();
    solve();
    return 0;
}