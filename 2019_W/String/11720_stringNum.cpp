#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        sum+=int(c-'0');
    }
    cout<<sum;
}