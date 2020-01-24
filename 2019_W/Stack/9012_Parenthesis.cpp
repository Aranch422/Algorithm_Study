#include <iostream>
#include <stack>

using namespace std;

int n;


void init(){
    cin>>n;
}

void solve(){
    while(n>0){
        stack<int> mys;
        bool isVPS =true;
        n--;
        string s;
        cin>>s;
        int size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]=='(') mys.push(1);
            else{
                if(mys.empty()){
                    isVPS=false;
                    break;
                }
                else{
                    mys.pop();
                }
            }
        }
        if(mys.size()!=0) isVPS =false;
        if(isVPS) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


int main(){
    init();
    solve();
    return 0;
}