#include <iostream>

using namespace std;

int ans[12];

void init(){
    ans[1]=1;
    ans[2]=2;
    ans[3]=4;
    for(int i=4;i<=11;i++){
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
}

int main(){
    init();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        cout<<ans[a]<<"\n";
    }
    return 0;
}