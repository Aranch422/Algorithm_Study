#include <iostream>
#include <string>

using namespace std;

int num[26];

int main(){
    for(int i=0;i<26;i++){
        num[i]=-1;
    }
    string s;
    cin>>s;
    int size=s.size();
    for(int i=0;i<size;i++){
        if(num[int(s[i]-'a')]==-1){
            num[int(s[i]-'a')]=i;
        }
    }

    for(int i=0;i<26;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}