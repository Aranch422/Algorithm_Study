#include <iostream>
#include <algorithm>

using namespace std;

int n,k;

int num[101];

int temp[10001];
int res[10001];

void init(){
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    temp[0]=1;
    res[0]=1;
    sort(num,num+n+1);
}

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j-num[i]<0) res[j]=temp[j];
            else res[j]=temp[j]+res[j-num[i]];
        }
        
        /*
        cout<<"temp: ";
        for(int j=0;j<=k;j++){
            cout<<temp[j]<<" ";
        }
        
        cout<<"\nres: ";
        for(int j=0;j<=k;j++){
            cout<<res[j]<<" ";
        }
        cout<<endl;
        */        

        for(int j=1;j<=k;j++){
            temp[j]=res[j];
        }
    }
}

int main(){
    init();
    solve();
    cout<<res[k];
    return 0;
}