#include <iostream>
#include <algorithm>

using namespace std;


int num[1000000];

int n;

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
}

int main(){
    init();
    sort(num,num+n);
    for(int i=0;i<n;i++){
        cout<<num[i]<<"\n";
    }
}