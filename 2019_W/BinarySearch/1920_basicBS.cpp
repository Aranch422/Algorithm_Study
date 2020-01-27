#include <iostream>
#include <algorithm>

using namespace std;
int num[100001];
int target[100001];
int n,m;

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

bool BS(int T,int left,int right){

    if(left==right){
        if(T==num[left]) return true;
        else return false;
    }

    int mid=(left+right)/2;
    if(num[mid]<T){
        return BS(T,mid+1,right);
    }
    else if(T<num[mid]){
        return BS(T,left,mid);
    }
    else{
        return true;
    }
}

void solve(){
    for(int i=0;i<m;i++){
        cout<<BS(target[i],0,n-1)<<"\n";
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