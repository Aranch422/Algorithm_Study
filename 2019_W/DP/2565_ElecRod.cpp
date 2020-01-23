#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int ,int> rod[100];
int num[100];
int LIS[100];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        rod[i]=make_pair(a,b);
    }
}

bool check(pair<int,int> a,pair<int,int> b){
    if(a.first<b.first) return true;
    else return false;
}

void solve(){
    sort(rod,rod+n,check);
    for(int i=0;i<n;i++){
        num[i]=rod[i].second;
        LIS[i]=0;
    }
    for(int i=0;i<n;i++){
        int Max=0;
        for(int j=i-1;j>=0;j--){
            if(num[i]>num[j]){
                if(LIS[j]>Max) Max=LIS[j];
            }
        }
        LIS[i]=Max+1;
    }
    int M=0;
    for(int i=0;i<n;i++){
        if(M<LIS[i]) M=LIS[i]; 
    }
    cout<<n-M;
}

int main(){
    init();
    solve();
    return 0;
}