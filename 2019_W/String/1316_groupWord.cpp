#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int cnt=0;
    cin>>n;
    while(n>0){
        n--;
        bool isGroup=true;
        string s;
        cin>>s;
        int size = s.size();
        for(int i=0;i<size;){

            if(i==size-1) {
                break;
            }
            else if(s.find(s[i],i+1)==string::npos||i+1==s.find(s[i],i+1)){
                i++;
            } 
            else {
                isGroup=false;
                break;
            }
        }

        if(isGroup) cnt++;
    }
    cout<<cnt;
    return 0;
}