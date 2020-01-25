#include <iostream>
#include <deque>
#include <string>

using namespace std;

int n,k;
string s,num;
bool isFront =true;
deque<int> D;


void init(){
    cin>>s;
    cin>>k;
    cin>>num;
    int size=num.size();
    if(k==0) return;
    string temp;
    for(int i=0;i<size;i++){
        //is num
        if('0'<=num[i]&&num[i]<='9'){
            temp+=num[i];
        }
        else if(num[i]==','||num[i]==']'){
            D.push_back(stoi(temp));
            temp="";
        }
    }
}

void solve(){
    isFront=true;
    if(k==0){
        bool isD =false;
        int size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]=='D') {
                isD=true;
                break;
            }
        }
        if(isD){
            cout<<"error"<<endl;
        }
        else cout<<"[]"<<endl;
        return;
    }
    int size=s.size();
    for(int i=0;i<size;i++){
        if(s[i]=='R') isFront=!isFront;
        if(s[i]=='D'){
            if(D.empty()) {
                cout<<"error"<<endl;
                return;
            }
            else if(isFront) D.pop_front();
            else if(!isFront) D.pop_back();
        }
    }
    size=D.size();
    cout<<'[';
    for(int i=0;i<size;i++){
        if(isFront){
            int temp=D.front();
            D.pop_front();
            cout<<temp;
            if(i!=size-1) cout<<',';
        }
        else{
            cout<<D.back();
            if(i!=size-1) cout<<',';
            D.pop_back();
        }
    }
    cout<<']'<<endl;
}



int main(){
    cin>>n;
    while(n>0){
        n--;
        init();
        solve();
    }

    return 0;
}