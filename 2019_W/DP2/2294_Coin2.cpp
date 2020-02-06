#include <iostream>
#include <algorithm>

using namespace std;

int n,k;

int num[101];
int res[10001];

void init(){
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        res[i]=999999;
    }
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]>k) continue;
        res[num[i]]=1;
    }
    sort(num,num+n+1);
}

void solve(){
    for(int i=1;i<=k;i++){
        if(res[i]==1) continue;
        for(int j=1;j<=n;j++){
            if(i-num[j]>=0){
                if(res[i-num[j]]<res[i]){
                    res[i]=res[i-num[j]];
                }
            }
        }
        res[i]++;
    }
    if(res[k]==1000000)  cout<<-1;
    else cout<<res[k];
}

int main(){
    init();
    solve();

    return 0;
}