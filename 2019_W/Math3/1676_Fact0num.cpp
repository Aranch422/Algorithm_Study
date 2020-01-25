#include <iostream>

using namespace std;

int zero[501];

void init(){
    zero[0]=0;
    for(int i=1;i<=500;i++){
        zero[i]=zero[i-1];
        if(i%5==0) zero[i]++;
        if(i%25==0) zero[i]++;
        if(i%125==0) zero[i]++;
        //cout<<i<<" "<<zero[i]<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    init();
    cout<<zero[n];
    return 0;
}