#include <iostream>

using namespace std;

int n,k;

int main(){
    cin>>n>>k;
    int temp1,temp2;
    temp1=1; temp2=1;
    for(int i=n;i>n-k;i--){
        temp1*=i;
    }
    for(int i=k;i>=1;i--){
        temp2*=i;
    }
    cout<<temp1/temp2;
    return 0;
}