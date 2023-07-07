#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string,string,greater<string>> log;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name,state;
        cin>>name>>state;
        auto data = log.find(name);
        if(data == log.end()){
            log.insert({name,state});
        }
        else{
            data->second = state;
        }
    }
    for(auto iter = log.begin(); iter!= log.end(); iter++){
        string name = iter->first;
        string state = iter->second;
        if(state=="enter"){
            cout<<name<<"\n";
        }
    }
    return 0;
}