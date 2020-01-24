#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> Q;

void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        Q.push(i);
    }
}

void solve(){
    while(Q.size()!=1){
        Q.pop();
        if(Q.size()==1) break;
        int temp=Q.front();
        Q.pop();
        Q.push(temp);
    }
    cout<<Q.front();
}


int main(){
    init();
    solve();
    return 0;
}