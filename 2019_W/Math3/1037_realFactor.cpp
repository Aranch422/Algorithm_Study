#include <iostream>
#include <algorithm>

using namespace std;

int factor[50];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>factor[i];
    }
    sort(factor,factor+n);
    cout<<factor[0]*factor[n-1];
}