#include <iostream>
#include <algorithm>


using namespace std;

bool isleftup(pair<int,int> a, pair<int,int> b){
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else{
        if(a.second<b.second) return true;
        else if(a.second>b.second) return false;
    }
}

pair<int,int> list[100000];

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        list[i]=make_pair(a,b);
    }
    sort(list,list+n,isleftup);
    for(int i=0;i<n;i++){
        cout<<list[i].first<<" "<<list[i].second<<"\n";
    }
    return 0;
}