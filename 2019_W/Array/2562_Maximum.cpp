#include <iostream>

using namespace std;

int num[10];
int Max=0;
int idx=0;

void init(){
    for(int i=1;i<=9;i++){
        cin>>num[i];
    }
}

void solve(){
    Max=num[1];
    idx=1;
    for(int i=2;i<=9;i++){
        if(Max<num[i]){
            Max=num[i];
            idx=i;
        }
    }
}

int main(){
    init();
    solve();
    cout<<Max<<"\n"<<idx;
    return 0;
}