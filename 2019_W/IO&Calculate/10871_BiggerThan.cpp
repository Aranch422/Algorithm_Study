#include <iostream>

using namespace std;

int n,m;
int num[10000];

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
}

void solve(){

    for(int i=0;i<n;i++){
        if(num[i]<m) cout<<num[i]<<" ";
    }

}

int main(){
    init();
    solve();

    return 0;
}