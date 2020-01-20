#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int num[10];

int main(){

    string s;
    cin>>s;
    int size=s.size();
    for(int i=0;i<size;i++){
        num[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<num[i];j++){
            cout<<i;
        }
    }
    return 0;
}