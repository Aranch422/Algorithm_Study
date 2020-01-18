#include <iostream>

using namespace std;

int n;

void init(){
    cin>>n;
}

void solve(){
    int target = n-1;
    if(target==0){
        cout<<1;
        return;
    }
    else{
        for(int k=2;;k++){
            if(3*(k-1)*(k-2)<target && target<=3*k*(k-1)){
                cout<<k;
                return;
            }
        }
    }
}


int main(){
    init();
    solve();

    return 0;
}