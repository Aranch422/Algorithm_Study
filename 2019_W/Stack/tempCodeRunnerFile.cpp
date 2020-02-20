#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> myS;

int main(){
    string s;
    cin>>s;
    string ans;
    for(int i=0;i<s.size();i++){
        //cout<<"loop1\n";
        if(s[i]=='('||s[i]=='*'||s[i]=='/'){
            myS.push(s[i]);
        }
        else if(s[i]==')'){
            while(myS.top()!='('){
                ans+=myS.top();
                myS.pop();
            }
            myS.pop();
        }
        else if(s[i]=='+'||s[i]=='-'){
            while(!myS.empty()){
                if(myS.top()=='(') break;
                else{
                    ans+=myS.top();
                    myS.pop();
                }
            }
            myS.push(s[i]);
        }
        else{
            ans=ans+s[i];
        }
    }
    while(!myS.empty()){
        //cout<<"loop2\n";
        ans+=myS.top();
        myS.pop();
    }
    cout<<ans;
    return 0;
}