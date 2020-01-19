#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    while(1){
        int a,b;
        cin>>a>>b;
        if(cin.eof()==true) break;
        cout<<a+b<<"\n";
    }

    return 0;
}