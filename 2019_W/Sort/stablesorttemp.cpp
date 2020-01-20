//왜 주소쓰면 안되지?

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool check(pair<int,string> a,pair<int,string> b){
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else{
        if(&a<&b) return true;
        else return false;
    }
}

pair<int,string> list[100000];


int main(){
    int n;
    int age;
    cin>>n;
    string name;
    for(int i=0;i<n;i++){
        cin>>age>>name;
        list[i]=make_pair(age,name);
    }
    sort(list,list+n,check);
    for(int i=0;i<n;i++){
        cout<<list[i].first<<" "<<list[i].second<<"\n";
    }
    cout<<"====================================\n";
    for(int i=0;i<n;i++){
        cout<<&list[i]<<endl;
    }
    return 0;
}
