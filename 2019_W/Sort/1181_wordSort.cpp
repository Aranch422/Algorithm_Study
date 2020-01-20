#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool wordcheck(string a,string b){
    if(a.size()<b.size()) return true;
    else if(a.size()>b.size()) return false;
    else{
        if(a<b) return true;
        else return false;
    }
}

string list[20000];

int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        list[i]=s;
    }
    sort(list,list+n,wordcheck);
    for(int i=0;i<n;i++){
        if(list[i]==list[i+1]) continue;
        cout<<list[i]<<"\n";
    }

    return 0;
}