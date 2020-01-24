#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;

void init(){
    getline(cin,s);
}

int main(){
    while(1){
        stack<char> mys;
        bool isVPS=true;
        init();
        if(s==".") return 0;
        else{
            int size= s.size();
            for(int i=0;i<size;i++){
                if(s[i]=='(') mys.push(s[i]);
                else if(s[i]=='[') mys.push(s[i]);
                else if(s[i]==')'){
                    if(mys.size()==0) isVPS=false;
                    else if(mys.top()=='(') mys.pop();
                    else{
                        isVPS=false;
                    }
                }
                else if(s[i]==']'){
                    if(mys.size()==0) isVPS=false;
                    else if(mys.top()=='[') mys.pop();
                    else {
                        isVPS=false;
                    }
                }
            }
            if(mys.size()!=0) isVPS =false;
            if(isVPS) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }

    return 0;
}