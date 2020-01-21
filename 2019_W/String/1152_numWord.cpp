#include <iostream>
#include <string>

using namespace std;

string s;

int main(){
    int cnt=0;
    getline(cin,s);
    while(!s.empty()&&s.front()==' '){
        s.erase(s.begin());
    }
    while(!s.empty()&&s.back()==' '){
        s.pop_back();
    }
    int size= s.size();
    for(int i=0;i<size;i++){
        if(s[i]==' ') cnt++;
    }
    if(s.empty()) cout<<0;
    else cout<<cnt+1;
    return 0;
}