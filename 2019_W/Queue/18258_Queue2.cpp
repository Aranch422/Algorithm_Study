#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    queue<int> myQ;
    cin>>n;
    while(n>0){
        n--;
        string s;
        cin>>s;
        if(s=="push"){
            int a;
            cin>>a;
            myQ.push(a);
        }
        else if(s=="pop"){
            if(myQ.empty()){
                cout<<-1<<"\n";
                continue;
            }
            cout<<myQ.front()<<"\n";
            myQ.pop();
        }
        else if(s=="size"){
            cout<<myQ.size()<<"\n";
        }
        else if(s=="empty"){
            cout<<myQ.empty()<<"\n";
        }
        else if(s=="front"){
            if(myQ.empty()) {
                cout<<-1<<"\n";
                continue;
            }
            cout<<myQ.front()<<"\n";
        }
        else if(s=="back"){
            if(myQ.empty()){
                cout<<-1<<"\n";
                continue;
            }
            cout<<myQ.back()<<"\n";
        }
    }

    return 0;
}