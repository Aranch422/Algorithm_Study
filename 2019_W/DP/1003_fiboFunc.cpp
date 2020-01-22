#include <iostream>

using namespace std;

int call0[41];
int call1[41];

void init(){
    call0[0]=1; call0[1]=0;
    call1[0]=0; call1[1]=1;
    for(int i=2;i<41;i++){
        call0[i]=call0[i-1]+call0[i-2];
        call1[i]=call1[i-1]+call1[i-2];
    }
}

int main(){
    init();
    int n;
    cin>>n;
    while(n>0){
        n--;
        int a;
        cin>>a;
        cout<<call0[a]<<" "<<call1[a]<<"\n";
    }
    return 0;
}