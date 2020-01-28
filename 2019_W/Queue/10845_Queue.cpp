#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    while(n>0){
        n--;
        string s;
        cin>>s;
        if(s=="push"){
            int a;
            cin>>a;
            Q.push(a);
        }
        if(s=="pop"){
            if(Q.empty()) cout<<-1<<"\n";
            else {
                cout<<Q.front()<<"\n";
                Q.pop();
            }
        }
        if(s=="size") cout<<Q.size()<<"\n";
        if(s=="empty") cout<<Q.empty()<<"\n";
        if(s=="front"){
            if(Q.empty()) cout<<-1<<"\n";
            else cout<<Q.front()<<"\n";
        }
        if(s=="back"){
            if(Q.empty()) cout<<-1<<"\n";
            else cout<<Q.back()<<"\n";
        }
    }
    return 0;
}