#include <iostream>

using namespace std;

int main(){
    string s="";
    for(int i=0;i<8;i++){
        string ss;
        cin>>ss;
        s+=ss;
    }

    if(s=="12345678") cout<<"ascending";
    else if(s=="87654321") cout<<"descending";
    else cout<<"mixed";

    return 0;
}