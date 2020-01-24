#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int top=0;
int stack[10010];

void init(){
    cin>>n;
}

void solve(){
    cin>>s;
    if(s=="push"){
        int a;
        cin>>a;
        stack[top++]=a;
    }
    if(s=="pop"){
        if(top==0) {
            cout<<-1<<endl;
            return;
        }
        top--;
        cout<<stack[top]<<endl;
    }
    if(s=="size") cout<<top<<endl;
    if(s=="empty"){
        if(top==0) cout<<1<<endl;
        else cout<<0<<endl;
    }
    if(s=="top"){
        if(top==0) cout<<-1<<endl;
        else cout<<stack[top-1]<<endl;
    }

}

int main(){
    init();
    while(n>0){
        n--;
        solve();
    }

    return 0;
}