#include <iostream>
#include <algorithm>


using namespace std;

bool isupright(pair<int,int> a, pair<int,int> b){
    if(a.second<b.second) return true;
    else if(a.second>b.second) return false;
    else{
        if(a.first<b.first) return true;
        else if(a.first>b.first) return false;
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
    sort(list,list+n,isupright);
    for(int i=0;i<n;i++){
        cout<<list[i].first<<" "<<list[i].second<<"\n";
    }
    return 0;
}