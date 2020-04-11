#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int,int> num[1000000];

int result[1000000];

bool isnumbigger(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}

void init(){
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        num[i]=make_pair(a,i);
    }
    sort(num,num+N,isnumbigger);
}

void solve(){
    int write=0;
    result[0]=write;
    for(int i=1;i<N;i++){
        if(num[i].first>num[i-1].first){
            write+=1;
        }
        result[num[i].second]=write;
    }
    for(int i=0;i<N;i++){
        cout<<result[i]<<" ";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();
    return 0;
}