#include <iostream>

using namespace std;

int main(){
    while(true){
        string s;
        cin>>s;
        if(s=="0") return 0;
        int len=s.size()-1;
        bool right=true;
        for(int i=0;i<=len;i++){
            if(s[i]==s[len-i]) continue;
            else{
                right=false;
                break;
            }
        }
        if(right) cout<<"yes\n";
        else cout<<"no\n";
    }
}