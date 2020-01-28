#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[500001];
int target[500001];
void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>target[i];
    }
}

int BS(int idx,int left,int right){
    if(target[idx]<num[left]||num[right]<target[idx]) return 0;
    if(target[idx]==num[left]&&target[idx]==num[right]) return right-left+1;

    int mid=(left+right)/2;
    return BS(idx,left,mid)+BS(idx,mid+1,right);
}

void solve(){
    for(int i=0;i<m;i++){
        cout<<BS(i,0,n-1)<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();

    return 0;
}