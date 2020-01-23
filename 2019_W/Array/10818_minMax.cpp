#include <iostream>

using namespace std;

int n;
int num[1000000];
int Max=-1000000;
int Min=1000000;
void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(Max<num[i]) Max=num[i];
        if(Min>num[i]) Min=num[i];
    }
}

int main() {
    init();
    cout<<Min<<" "<<Max;
    return 0;
}