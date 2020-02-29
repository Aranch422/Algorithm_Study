#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

//addr, pw
vector<pair<string,string>> V;

bool check(pair<string,string> a,pair<string,string> b){
    return a.first<b.first;
}

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string addr,pw;
        cin>>addr>>pw;
        V.push_back(make_pair(addr,pw));
    }
    sort(V.begin(),V.end(),check);
}

void find(string s){
    int left=0; int right=n-1;
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(V[mid].first<s) left=mid+1;
        else right=mid;
    }
    mid=left;
    cout<<V[mid].second<<'\n';
}

void solve(){
    for(int i=0;i<m;i++){
        string target;
        cin>>target;
        find(target);
    }
}

int main(){
    init();
    solve();
    return 0;
}