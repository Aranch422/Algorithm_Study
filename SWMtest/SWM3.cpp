#include <iostream>
#include <queue>

using namespace std;

int n,k;
int num[3001];

priority_queue<int> PQ;

void init(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<n;i++){
        PQ.push(num[i+1]-num[i]);
    }

}

void solve(){
    int ans;
    ans=num[n]-num[1];
    for(int i=0;i<k-1;i++){
        int temp=PQ.top();
        PQ.pop();
        ans-=temp;
    }
    cout<<ans;
}

int main(){
    init();
    solve();
    return 0;
}