#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool check(pair<int,pair<int,string>> a,pair<int,pair<int,string>> b){
    if(a.second.first<b.second.first) return true;
    else if(a.second.first>b.second.first) return false;
    else{
        if(a.first<b.first) return true;
        else return false;
    }
}

pair<int,pair<int,string>> list[100000];


int main(){
    int n;
    int age;
    cin>>n;
    string name;
    for(int i=0;i<n;i++){
        cin>>age>>name;
        list[i]=make_pair(i,make_pair(age,name));
    }
    sort(list,list+n,check);
    for(int i=0;i<n;i++){
        cout<<list[i].second.first<<" "<<list[i].second.second<<"\n";
    }

    return 0;
}