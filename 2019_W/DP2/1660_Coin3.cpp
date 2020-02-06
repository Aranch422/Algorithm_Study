#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[300000];
int res[300001];

int nsize=0;

void init(){
    cin>>n;
    int sum=0;
    int layer=0;

    for(int i=1;i<300001;i++){
        res[i]=999999;
    }

    for(int i=1;sum<=300000;i++){
        layer+=i;
        sum+=layer;
        num[i]=sum;
        res[num[i]]=1;
        nsize++;
    }

}

void solve(){
    for(int i=1;i<=n;i++){
        if(res[i]==1) continue;
        for(int j=1;j<=nsize;j++){
            if(i-num[j]<=0) break;
            if(res[i-num[j]]<res[i]) res[i]=res[i-num[j]];
        }
        res[i]++;
    }
    cout<<res[n];
}

int main(){
    init();
    solve();
    return 0;
}